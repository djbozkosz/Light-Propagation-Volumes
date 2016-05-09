//------------------------------------------------------------------------------
#include "shaders.h"

//------------------------------------------------------------------------------
CShader::CShader() : CEngineBase()
{
}
//------------------------------------------------------------------------------
CShader::CShader(CContext *context, const SShader &shader) : CEngineBase(context), shader(shader)
{
}
//------------------------------------------------------------------------------
CShader::~CShader()
{
}
//------------------------------------------------------------------------------
bool CShader::compile()
{
  if(shader.type == NShader::TYPE_UNDEFINED)
    return false;

  COpenGL *gl = context->getOpenGL();
  const GLenum shaderType = NShader::TYPE_SHADERS[shader.type];
  const NEngine::EGPUPlatform platform = context->engineGetEngine()->gpuPlatform;
  GLint status = 0;
  GLint infoLength = 0;
  std::string log;

  if(((shader.type == NShader::TYPE_GEOMETRY) && (platform < NEngine::GPU_PLATFORM_GL0302)) ||
     ((shader.type == NShader::TYPE_TESSELATION_CONTROL) && (platform < NEngine::GPU_PLATFORM_GL0400)) ||
     ((shader.type == NShader::TYPE_TESSELATION_EVALUATION) && (platform < NEngine::GPU_PLATFORM_GL0400)) ||
     ((shader.type == NShader::TYPE_COMPUTE) && (platform < NEngine::GPU_PLATFORM_GL0403)))
  {
    context->log(CStr(NShader::STR_ERROR_COMPILE_SKIP, shader.name.c_str()));
    return false;
  }

  CFile *f = context->getFilesystem()->open(SFile(std::string(NFile::STR_DATA_SHADERS)+shader.file));

  if(!f)
    return false;

  std::string data(f->size(), ' ');
  f->read(&data[0], data.length());
  f->close();

  if(context->engineGetEngine()->gpuPlatform == NEngine::GPU_PLATFORM_GL0200_ES)
    data = setES2compatible(data);
  data = setDefines(data);
  const char *d = data.c_str();
  //context->log(shader.name);
  //context->log(data);

  shader.shader = gl->createShader(shaderType);
  gl->shaderSource(shader.shader, 1, &d, NULL);
  gl->compileShader(shader.shader);
  gl->getShaderiv(shader.shader, NOpenGL::COMPILE_STATUS, &status);
  gl->getShaderiv(shader.shader, NOpenGL::INFO_LOG_LENGTH, &infoLength);

  log.resize(infoLength);
  if(infoLength)
    gl->getShaderInfoLog(shader.shader, infoLength, &infoLength, &log[0]);
  if((&log[0]) && (status == NOpenGL::TRUE) && (log.find("no error") != std::string::npos))
    log = CStr::replaceAll(log, "no error", "");
  if((&log[0]) && (status == NOpenGL::TRUE) &&
     ((log.find("warning") != std::string::npos) ||
      (log.find("WARNING") != std::string::npos) ||
      (log.find("error") != std::string::npos) ||
      (log.find("ERROR") != std::string::npos)))
    context->log(CStr(NShader::STR_WARNING_COMPILE, shader.name.c_str(), log.c_str()));

  if(status == NOpenGL::FALSE)
  {
    context->engineShowMessage(CStr(NShader::STR_ERROR_COMPILE, shader.name.c_str()), log.c_str(), false);
    return false;
  }

  return true;
}
//------------------------------------------------------------------------------
std::string CShader::setES2compatible(const std::string &data)
{
  std::string d = data;
#ifndef Q_OS_ANDROID
  std::string precision("lowp");
#else
  std::string precision("highp");
#endif

  // replace any version and precision by #version 100 - ES 2.0
  auto index = d.find("layout ");
  if(index == std::string::npos)
    index = d.find("in ");
  if(index == std::string::npos)
    index = d.find("uniform ");
  if(index == std::string::npos)
    index = d.find("out ");
  d.erase(0, index);
  d.insert(0, "#version 100\r\n\r\n");

  if(shader.type == NShader::TYPE_VERTEX)
  {
    d = CStr::replaceAll(d, "in ", "attribute ");
    d = CStr::replaceAll(d, "out ", "varying ");
  }
  else if(shader.type == NShader::TYPE_FRAGMENT)
  {
    d = CStr::replaceAll(d, "in ", "varying ");
    d = CStr::replaceAll(d, "out vec4 glFragColor;", "");
    d = CStr::replaceAll(d, "glFragColor", "NOpenGL::FragColor");
    d = CStr::replaceAll(d, "texture(", "texture2D(");
  }

  d = CStr::replaceAll(d, "float ", precision+" float ");
  d = CStr::replaceAll(d, "vec2 ", precision+" vec2 ");
  d = CStr::replaceAll(d, "vec3 ", precision+" vec3 ");
  d = CStr::replaceAll(d, "vec4 ", precision+" vec4 ");
  d = CStr::replaceAll(d, "mat2 ", precision+" mat2 ");
  d = CStr::replaceAll(d, "mat3 ", precision+" mat3 ");
  d = CStr::replaceAll(d, "mat4 ", precision+" mat4 ");
  d = CStr::replaceAll(d, "sampler2D ", precision+" sampler2D ");

  return d;
}
//------------------------------------------------------------------------------
std::string CShader::setDefines(const std::string &data)
{
  const SEngine *e = context->engineGetEngine();
  const uint32 tokensCount = 9;
  const char *const startTokens[] = { "//", "/*", "#if", "#ifdef", "#ifndef", "#define", "layout", "in", "uniform", "out", "void" };
  uint32 tokenIndex[tokensCount];
  std::string d = data;
  uint32 index = std::string::npos;

  for(uint32 i = 0; i < tokensCount; tokenIndex[i] = d.find(startTokens[i]), i++);
  for(uint32 i = 0; i < tokensCount; i++)
  {
    if((index > tokenIndex[i]) && (tokenIndex[i] != std::string::npos))
      index = tokenIndex[i];
  }

  std::string defines;
  std::stringstream ss(shader.defines);
  for(std::string d; std::getline(ss, d, ' '); defines += "#define "+d+"\r\n");
  if(defines.length())
    defines += "\r\n";

  d.insert(index, defines);

  d = CStr::replaceAll(d, "#define SHADOW_CASCADES_COUNT", CStr("#define SHADOW_CASCADES_COUNT %d", e->shadowCascadesCount));
  d = CStr::replaceAll(d, "#define LPV_CASCADES_COUNT", CStr("#define LPV_CASCADES_COUNT %d", e->lpvCascadesCount));
  d = CStr::replaceAll(d, "#define LPV_SUN_SKY_SPEC_CASCADES_COUNT", CStr("#define LPV_SUN_SKY_SPEC_CASCADES_COUNT %d", e->lpvCascadesCount * e->lpvSunSkySpecDirsCount));
  d = CStr::replaceAll(d, "#define LPV_SUN_SKY_DIRS_COUNT", CStr("#define LPV_SUN_SKY_DIRS_COUNT %d", e->lpvSunSkyDirsCount));
  d = CStr::replaceAll(d, "#define LPV_SUN_SKY_SPEC_DIRS_COUNT", CStr("#define LPV_SUN_SKY_SPEC_DIRS_COUNT %d", e->lpvSunSkySpecDirsCount));

  return d;
}
//------------------------------------------------------------------------------
CShaderProgram::CShaderProgram() : CEngineBase()
{
}
//------------------------------------------------------------------------------
CShaderProgram::CShaderProgram(CContext *context, const SShaderProgram &shaderProgram) : CEngineBase(context), program(shaderProgram)
{
}
//------------------------------------------------------------------------------
CShaderProgram::~CShaderProgram()
{
}
//------------------------------------------------------------------------------
bool CShaderProgram::link()
{
  /*context->log(CStr("%s\n  %s\n  %s\n  %s\n  %s\n  %s\n  %s\n", NShader::STR_PROGRAM_LIST[program.name],
    (program.vertexShader) ? program.vertexShader->getShader()->name.c_str() : "NULL",
    (program.tesselationControlShader) ? program.tesselationControlShader->getShader()->name.c_str() : "NULL",
    (program.tesselationEvaluationShader) ? program.tesselationEvaluationShader->getShader()->name.c_str() : "NULL",
    (program.geometryShader) ? program.geometryShader->getShader()->name.c_str() : "NULL",
    (program.fragmentShader) ? program.fragmentShader->getShader()->name.c_str() : "NULL",
    (program.computeShader) ? program.computeShader->getShader()->name.c_str() : "NULL"));*/

  COpenGL *gl = context->getOpenGL();
  GLint status = 0;
  GLint infoLength = 0;
  std::string log;
  const NEngine::EGPUPlatform platform = context->engineGetEngine()->gpuPlatform;

  if(((program.tesselationControlShader) && (platform < NEngine::GPU_PLATFORM_GL0400)) ||
     ((program.tesselationEvaluationShader) && (platform < NEngine::GPU_PLATFORM_GL0400)) ||
     ((program.geometryShader) && (platform < NEngine::GPU_PLATFORM_GL0302)) ||
     ((program.computeShader) && (platform < NEngine::GPU_PLATFORM_GL0403)))
  {
    context->log(CStr(NShader::STR_ERROR_LINK_SKIP, NShader::STR_PROGRAM_LIST[program.name]));
    return false;
  }

  program.program = gl->createProgram();
  if(program.vertexShader)
    gl->attachShader(program.program, program.vertexShader->getShader()->shader);
  if(program.tesselationControlShader)
    gl->attachShader(program.program, program.tesselationControlShader->getShader()->shader);
  if(program.tesselationEvaluationShader)
    gl->attachShader(program.program, program.tesselationEvaluationShader->getShader()->shader);
  if(program.geometryShader)
    gl->attachShader(program.program, program.geometryShader->getShader()->shader);
  if(program.fragmentShader)
    gl->attachShader(program.program, program.fragmentShader->getShader()->shader);
  if(program.computeShader)
    gl->attachShader(program.program, program.computeShader->getShader()->shader);

  gl->linkProgram(program.program);

  gl->getProgramiv(program.program, NOpenGL::LINK_STATUS, &status);
  gl->getProgramiv(program.program, NOpenGL::INFO_LOG_LENGTH, &infoLength);
  log.resize(infoLength);
  if(infoLength)
    gl->getProgramInfoLog(program.program, infoLength, &infoLength, &log[0]);

#ifndef Q_OS_SYMBIAN
  if((&log[0]) && (status == NOpenGL::TRUE) && (log.find("no error") != std::string::npos))
    log = CStr::replaceAll(log, "no error", "");
  if((&log[0]) && (status == NOpenGL::TRUE) &&
     ((log.find("warning") != std::string::npos) ||
      (log.find("WARNING") != std::string::npos) ||
      (log.find("error") != std::string::npos) ||
      (log.find("ERROR") != std::string::npos)))
    context->log(CStr(NShader::STR_WARNING_LINK, NShader::STR_PROGRAM_LIST[program.name], log.c_str()));
#endif

  if(status == NOpenGL::FALSE)
  {
    context->engineShowMessage(CStr(NShader::STR_ERROR_LINK, NShader::STR_PROGRAM_LIST[program.name]), log.c_str(), false);
    return false;
  }

  return true;
}
//------------------------------------------------------------------------------
void CShaderProgram::initUniforms()
{
  COpenGL *gl = context->getOpenGL();
  CMaps *maps = context->getMaps();
  SShaderUniforms *u = &program.uniforms;

  u->vertexPosition = gl->getAttribLocation(program.program, NShader::STR_ATTRIB_VERTEX_POSITION);
  u->vertexNormal = gl->getAttribLocation(program.program, NShader::STR_ATTRIB_VERTEX_NORMAL);
  u->vertexNormalTangent = gl->getAttribLocation(program.program, NShader::STR_ATTRIB_VERTEX_NORMAL_TANGENT);
  u->vertexNormalBitangent = gl->getAttribLocation(program.program, NShader::STR_ATTRIB_VERTEX_NORMAL_BITANGENT);
  u->vertexTexCoord = gl->getAttribLocation(program.program, NShader::STR_ATTRIB_VERTEX_TEX_COORD);
  u->vertexColor = gl->getAttribLocation(program.program, NShader::STR_ATTRIB_VERTEX_COLOR);

  u->mw = gl->getUniformLocation(program.program, NShader::STR_UNIFORM_MW);
  u->mwnit = gl->getUniformLocation(program.program, NShader::STR_UNIFORM_MWNIT);
  u->mvp = gl->getUniformLocation(program.program, NShader::STR_UNIFORM_MVP);
  u->mvpsb = gl->getUniformLocation(program.program, NShader::STR_UNIFORM_MVPSB);
  u->cam = gl->getUniformLocation(program.program, NShader::STR_UNIFORM_CAM);

  u->difTex = gl->getUniformLocation(program.program, NShader::STR_UNIFORM_DIF_TEX);
  u->alpTex = gl->getUniformLocation(program.program, NShader::STR_UNIFORM_ALP_TEX);
  u->speTex = gl->getUniformLocation(program.program, NShader::STR_UNIFORM_SPE_TEX);
  u->norTex = gl->getUniformLocation(program.program, NShader::STR_UNIFORM_NOR_TEX);
  //u->envTex = gl->getUniformLocation(program.program, NShader::STR_UNIFORM_ENV_TEX);
  u->shadTex = gl->getUniformLocation(program.program, NShader::STR_UNIFORM_SHAD_TEX);
  u->shadDepthTex = gl->getUniformLocation(program.program, NShader::STR_UNIFORM_SHAD_DEPTH_TEX);

  u->geomColorTex = gl->getUniformLocation(program.program, NShader::STR_UNIFORM_GEOM_COLOR_TEX);
  u->geomPosTex = gl->getUniformLocation(program.program, NShader::STR_UNIFORM_GEOM_POS_TEX);
  u->geomNormalTex = gl->getUniformLocation(program.program, NShader::STR_UNIFORM_GEOM_NORMAL_TEX);
  //u->geomDepthTex = gl->getUniformLocation(program.program, NShader::STR_UNIFORM_GEOM_DEPTH_TEX);

  u->lpvTexR = gl->getUniformLocation(program.program, NShader::STR_UNIFORM_LPV_TEX_R);
  u->lpvTexG = gl->getUniformLocation(program.program, NShader::STR_UNIFORM_LPV_TEX_G);
  u->lpvTexB = gl->getUniformLocation(program.program, NShader::STR_UNIFORM_LPV_TEX_B);
  u->lpvAccumTexR = gl->getUniformLocation(program.program, NShader::STR_UNIFORM_LPV_ACCUM_TEX_R);
  u->lpvAccumTexG = gl->getUniformLocation(program.program, NShader::STR_UNIFORM_LPV_ACCUM_TEX_G);
  u->lpvAccumTexB = gl->getUniformLocation(program.program, NShader::STR_UNIFORM_LPV_ACCUM_TEX_B);
  u->sslpvAccumTexR = gl->getUniformLocation(program.program, NShader::STR_UNIFORM_SSLPV_ACCUM_TEX_R);
  u->sslpvAccumTexG = gl->getUniformLocation(program.program, NShader::STR_UNIFORM_SSLPV_ACCUM_TEX_G);
  u->sslpvAccumTexB = gl->getUniformLocation(program.program, NShader::STR_UNIFORM_SSLPV_ACCUM_TEX_B);
  u->lpvNormalTex = gl->getUniformLocation(program.program, NShader::STR_UNIFORM_LPV_NORMAL_TEX);
  u->lpv0Tex = gl->getUniformLocation(program.program, NShader::STR_UNIFORM_LPV0_TEX);
  u->lpv1Tex = gl->getUniformLocation(program.program, NShader::STR_UNIFORM_LPV1_TEX);
  u->lpvAccumTex = gl->getUniformLocation(program.program, NShader::STR_UNIFORM_LPV_ACCUM_TEX);
  u->lpvNormalAccumTex = gl->getUniformLocation(program.program, NShader::STR_UNIFORM_LPV_NORMAL_ACCUM_TEX);
  u->gvTex = gl->getUniformLocation(program.program, NShader::STR_UNIFORM_GV_TEX);

  u->type = gl->getUniformLocation(program.program, NShader::STR_UNIFORM_TYPE);
  u->opacity = gl->getUniformLocation(program.program, NShader::STR_UNIFORM_OPACITY);
  u->tiles = gl->getUniformLocation(program.program, NShader::STR_UNIFORM_TILES);
  u->tileInstances = gl->getUniformLocation(program.program, NShader::STR_UNIFORM_TILE_INSTANCES);
  u->shadowTexSize = gl->getUniformLocation(program.program, NShader::STR_UNIFORM_SHADOW_TEX_SIZE);
  u->shadowClips = gl->getUniformLocation(program.program, NShader::STR_UNIFORM_SHADOW_CLIPS);
  u->lightAmb = gl->getUniformLocation(program.program, NShader::STR_UNIFORM_LIGHT_AMB);
  u->lightPos = gl->getUniformLocation(program.program, NShader::STR_UNIFORM_LIGHT_POS);
  u->lightRange = gl->getUniformLocation(program.program, NShader::STR_UNIFORM_LIGHT_RANGE);
  u->lightColor = gl->getUniformLocation(program.program, NShader::STR_UNIFORM_LIGHT_COLOR);
  u->lightSpeColor = gl->getUniformLocation(program.program, NShader::STR_UNIFORM_LIGHT_SPEC_COLOR);
  u->fogRange = gl->getUniformLocation(program.program, NShader::STR_UNIFORM_FOG_RANGE);
  u->fogColor = gl->getUniformLocation(program.program, NShader::STR_UNIFORM_FOG_COLOR);

  u->geomTexSize = gl->getUniformLocation(program.program, NShader::STR_UNIFORM_GEOM_TEX_SIZE);
  u->geomPos = gl->getUniformLocation(program.program, NShader::STR_UNIFORM_GEOM_POS);
  u->lpvPos = gl->getUniformLocation(program.program, NShader::STR_UNIFORM_LPV_POS);
  u->lpvTexSize = gl->getUniformLocation(program.program, NShader::STR_UNIFORM_LPV_TEX_SIZE);
  u->lpvCellSize = gl->getUniformLocation(program.program, NShader::STR_UNIFORM_LPV_CELL_SIZE);
  u->lpvParams = gl->getUniformLocation(program.program, NShader::STR_UNIFORM_LPV_PARAMS);

  u->shadowMap = maps->getMap(NEngine::STR_SUN_SHADOW_FBO_MAP);
  u->shadowDepthMap = maps->getMap(NEngine::STR_SUN_SHADOW_FBO_DEPTH_MAP);
  u->geomColorMap = maps->getMap(NEngine::STR_GEOMETRY_FBO_AMB_MAP);
  u->geomPosMap = maps->getMap(NEngine::STR_GEOMETRY_FBO_POS_MAP);
  u->geomNormalMap = maps->getMap(NEngine::STR_GEOMETRY_FBO_NORMAL_MAP);
  //u->geomDepthMap = maps->getMap(NEngine::STR_GEOMETRY_FBO_DEPTH_MAP);

  u->lpvGs0MapR = maps->getMap(NEngine::STR_LPV0_GS_MAP_R);
  u->lpvGs0MapG = maps->getMap(NEngine::STR_LPV0_GS_MAP_G);
  u->lpvGs0MapB = maps->getMap(NEngine::STR_LPV0_GS_MAP_B);
  u->lpvAccumGs0MapR = maps->getMap(NEngine::STR_LPV0_ACCUM_GS_MAP_R);
  u->lpvAccumGs0MapG = maps->getMap(NEngine::STR_LPV0_ACCUM_GS_MAP_G);
  u->lpvAccumGs0MapB = maps->getMap(NEngine::STR_LPV0_ACCUM_GS_MAP_B);
  u->lpvNormalGs0Map = maps->getMap(NEngine::STR_LPV0_NORMAL_GS_MAP);
  u->lpvGs1MapR = maps->getMap(NEngine::STR_LPV1_GS_MAP_R);
  u->lpvGs1MapG = maps->getMap(NEngine::STR_LPV1_GS_MAP_G);
  u->lpvGs1MapB = maps->getMap(NEngine::STR_LPV1_GS_MAP_B);
  u->lpvAccumGs1MapR = maps->getMap(NEngine::STR_LPV1_ACCUM_GS_MAP_R);
  u->lpvAccumGs1MapG = maps->getMap(NEngine::STR_LPV1_ACCUM_GS_MAP_G);
  u->lpvAccumGs1MapB = maps->getMap(NEngine::STR_LPV1_ACCUM_GS_MAP_B);
  u->lpvNormalGs1Map = maps->getMap(NEngine::STR_LPV1_NORMAL_GS_MAP);
  u->lpvLobeGs0Map = maps->getMap(NEngine::STR_LPV0_LOBE_GS_MAP);
  u->lpvLobeGs1Map = maps->getMap(NEngine::STR_LPV1_LOBE_GS_MAP);
  u->gvGsMap = maps->getMap(NEngine::STR_GV_GS_MAP);

  u->sslpvGs0MapR = maps->getMap(NEngine::STR_SSLPV0_GS_MAP_R);
  u->sslpvGs0MapG = maps->getMap(NEngine::STR_SSLPV0_GS_MAP_G);
  u->sslpvGs0MapB = maps->getMap(NEngine::STR_SSLPV0_GS_MAP_B);
  u->sslpvAccumGs0MapR = maps->getMap(NEngine::STR_SSLPV0_ACCUM_GS_MAP_R);
  u->sslpvAccumGs0MapG = maps->getMap(NEngine::STR_SSLPV0_ACCUM_GS_MAP_G);
  u->sslpvAccumGs0MapB = maps->getMap(NEngine::STR_SSLPV0_ACCUM_GS_MAP_B);
  u->sslpvNormalGs0Map = maps->getMap(NEngine::STR_SSLPV0_NORMAL_GS_MAP);
  u->sslpvGs1MapR = maps->getMap(NEngine::STR_SSLPV1_GS_MAP_R);
  u->sslpvGs1MapG = maps->getMap(NEngine::STR_SSLPV1_GS_MAP_G);
  u->sslpvGs1MapB = maps->getMap(NEngine::STR_SSLPV1_GS_MAP_B);
  u->sslpvAccumGs1MapR = maps->getMap(NEngine::STR_SSLPV1_ACCUM_GS_MAP_R);
  u->sslpvAccumGs1MapG = maps->getMap(NEngine::STR_SSLPV1_ACCUM_GS_MAP_G);
  u->sslpvAccumGs1MapB = maps->getMap(NEngine::STR_SSLPV1_ACCUM_GS_MAP_B);
  u->sslpvNormalGs1Map = maps->getMap(NEngine::STR_SSLPV1_NORMAL_GS_MAP);
  u->sslpvLobeGs0Map = maps->getMap(NEngine::STR_SSLPV0_LOBE_GS_MAP);
  u->sslpvLobeGs1Map = maps->getMap(NEngine::STR_SSLPV1_LOBE_GS_MAP);

  u->lpv0CsMap = maps->getMap(NEngine::STR_LPV0_CS_IMG);
  u->lpv1CsMap = maps->getMap(NEngine::STR_LPV1_CS_IMG);
  u->lpvAccumCsMap = maps->getMap(NEngine::STR_LPV_ACCUM_CS_IMG);
  u->lpvNormalAccumCsMap = maps->getMap(NEngine::STR_LPV_NORMAL_ACCUM_CS_IMG);
  u->gvCsMap = maps->getMap(NEngine::STR_GV_CS_IMG);

  u->sslpv0CsMap = maps->getMap(NEngine::STR_SSLPV0_CS_IMG);
  u->sslpv1CsMap = maps->getMap(NEngine::STR_SSLPV1_CS_IMG);
  u->sslpvAccumCsMap = maps->getMap(NEngine::STR_SSLPV_ACCUM_CS_IMG);
  u->sslpvNormalAccumCsMap = maps->getMap(NEngine::STR_SSLPV_NORMAL_ACCUM_CS_IMG);
}
//------------------------------------------------------------------------------
void CShaderProgram::bind() const
{
  context->getOpenGL()->useProgram(program.program);
}
//------------------------------------------------------------------------------
void CShaderProgram::begin(const SShaderState *technique, NRenderer::EMode mode) const
{
  COpenGL *gl = context->getOpenGL();
  const SEngine *e = context->engineGetEngine();
  const SShaderUniforms *u = &program.uniforms;

  if(program.fAttribs & NShader::ATTRIB_PT_POSITION)
  { gl->enableVertexAttribArray(u->vertexPosition);
    gl->vertexAttribPointer(u->vertexPosition, NModel::VERTEX_SIZE_POSITION, NOpenGL::FLOAT, NOpenGL::FALSE, NModel::VERTEX_PT_SIZE_F, reinterpret_cast<float *>(sizeof(float) * NModel::VERTEX_PT_OFFSET_POSITION)); }
  if(program.fAttribs & NShader::ATTRIB_PT_TEX_COORD)
  { gl->enableVertexAttribArray(u->vertexTexCoord);
    gl->vertexAttribPointer(u->vertexTexCoord, NModel::VERTEX_SIZE_TEX_COORD, NOpenGL::FLOAT, NOpenGL::FALSE, NModel::VERTEX_PT_SIZE_F, reinterpret_cast<float *>(sizeof(float) * NModel::VERTEX_PT_OFFSET_TEX_COORD)); }
  if(program.fAttribs & NShader::ATTRIB_PNTBTC_POSITION)
  { gl->enableVertexAttribArray(u->vertexPosition);
    gl->vertexAttribPointer(u->vertexPosition, NModel::VERTEX_SIZE_POSITION, NOpenGL::FLOAT, NOpenGL::FALSE, NModel::VERTEX_PNTBTC_SIZE_F, reinterpret_cast<float *>(sizeof(float) * NModel::VERTEX_PNTBTC_OFFSET_POSITION)); }
  if(program.fAttribs & NShader::ATTRIB_PNTBTC_NORMAL)
  { gl->enableVertexAttribArray(u->vertexNormal);
    gl->vertexAttribPointer(u->vertexNormal, NModel::VERTEX_SIZE_NORMAL, NOpenGL::FLOAT, NOpenGL::FALSE, NModel::VERTEX_PNTBTC_SIZE_F, reinterpret_cast<float *>(sizeof(float) * NModel::VERTEX_PNTBTC_OFFSET_NORMAL)); }
  if(program.fAttribs & NShader::ATTRIB_PNTBTC_NORMAL_TANGENT)
  { gl->enableVertexAttribArray(u->vertexNormalTangent);
    gl->vertexAttribPointer(u->vertexNormalTangent, NModel::VERTEX_SIZE_NORMAL_TANGENT, NOpenGL::FLOAT, NOpenGL::FALSE, NModel::VERTEX_PNTBTC_SIZE_F, reinterpret_cast<float *>(sizeof(float) * NModel::VERTEX_PNTBTC_OFFSET_NORMAL_TANGENT)); }
  if(program.fAttribs & NShader::ATTRIB_PNTBTC_NORMAL_BITANGENT)
  { gl->enableVertexAttribArray(u->vertexNormalBitangent);
    gl->vertexAttribPointer(u->vertexNormalBitangent, NModel::VERTEX_SIZE_NORMAL_BITANGENT, NOpenGL::FLOAT, NOpenGL::FALSE, NModel::VERTEX_PNTBTC_SIZE_F, reinterpret_cast<float *>(sizeof(float) * NModel::VERTEX_PNTBTC_OFFSET_NORMAL_BITANGENT)); }
  if(program.fAttribs & NShader::ATTRIB_PNTBTC_TEX_COORD)
  { gl->enableVertexAttribArray(u->vertexTexCoord);
    gl->vertexAttribPointer(u->vertexTexCoord, NModel::VERTEX_SIZE_TEX_COORD, NOpenGL::FLOAT, NOpenGL::FALSE, NModel::VERTEX_PNTBTC_SIZE_F, reinterpret_cast<float *>(sizeof(float) * NModel::VERTEX_PNTBTC_OFFSET_TEX_COORD)); }
  if(program.fAttribs & NShader::ATTRIB_PNTBTC_COLOR)
  { gl->enableVertexAttribArray(u->vertexColor);
    gl->vertexAttribPointer(u->vertexColor, NModel::VERTEX_SIZE_COLOR, NOpenGL::FLOAT, NOpenGL::FALSE, NModel::VERTEX_PNTBTC_SIZE_F, reinterpret_cast<float *>(sizeof(float) * NModel::VERTEX_PNTBTC_OFFSET_COLOR)); }
  if(program.fAttribs & NShader::ATTRIB_F)
  { gl->enableVertexAttribArray(u->vertexPosition);
    gl->vertexAttribPointer(u->vertexPosition, NModel::VERTEX_SIZE_F, NOpenGL::FLOAT, NOpenGL::FALSE, NModel::VERTEX_F_SIZE_F, reinterpret_cast<float *>(sizeof(float) * NModel::VERTEX_F_OFFSET)); }

  if(technique)
  {
    if(program.fUniforms & NShader::UNIFORM_MW)
      gl->uniformMatrix4fv(u->mw, 1, NOpenGL::FALSE, glm::value_ptr(technique->mw));
    if(program.fUniforms & NShader::UNIFORM_MWNIT)
      gl->uniformMatrix3fv(u->mwnit, 1, NOpenGL::FALSE, glm::value_ptr(technique->mwnit));

    // mvp cascade variants
    if(program.fUniforms & NShader::UNIFORM_MVP)
      gl->uniformMatrix4fv(u->mvp, 1, NOpenGL::FALSE, glm::value_ptr(technique->mvp));
    else if(program.fUniforms & NShader::UNIFORM_MVP_SHAD)
      gl->uniformMatrix4fv(u->mvp, 1, NOpenGL::FALSE, &technique->mvps[0]);
    else if(program.fUniforms & NShader::UNIFORM_MVP_SHAD_CASCADE)
      gl->uniformMatrix4fv(u->mvp, e->shadowCascadesCount, NOpenGL::FALSE, &technique->mvps[0]);
    else if(program.fUniforms & NShader::UNIFORM_MVP_GEOM)
      gl->uniformMatrix4fv(u->mvp, 1, NOpenGL::FALSE, &technique->mvpg[0]);
    else if(program.fUniforms & NShader::UNIFORM_MVP_GEOM_CASCADE)
      gl->uniformMatrix4fv(u->mvp, e->lpvCascadesCount * e->lpvSunSkySpecDirsCount, NOpenGL::FALSE, &technique->mvpg[0]);
    if(program.fUniforms & NShader::UNIFORM_MVPSB)
      gl->uniformMatrix4fv(u->mvpsb, e->shadowCascadesCount, NOpenGL::FALSE, &technique->mvpsb[0]);

    if(program.fUniforms & NShader::UNIFORM_CAM)
      gl->uniform3f(u->cam, technique->cam.x, technique->cam.y, technique->cam.z);

    if(technique->material)
    {
      const SMaterial *m = technique->material;
      
      // texture samplers
      if(program.fSamplers & NShader::SAMPLER_DEPTH_COLOR_KEY)
        setSampler(m->diffuseMap, u->difTex, NShader::SAMPLER_TEX_DEPTH_COLOR_KEY_DIF, NMap::FORMAT_LINEAR);
      else if(program.fSamplers & NShader::SAMPLER_BASIC)
        setSampler(m->diffuseMap, u->difTex, NShader::SAMPLER_TEX_BASIC_DIF, ((m->type & NModel::MATERIAL_MIP_MAPPING) ? NMap::FORMAT_MIPMAP : NMap::FORMAT_LINEAR) | (((mode == NRenderer::MODE_SUN_RAYS_BACKDROP) || (mode == NRenderer::MODE_BACKDROP)) ? NMap::FORMAT_EDGE : NMap::FORMAT));
      else if(program.fSamplers & NShader::SAMPLER_BASIC_APLHA)
      { setSampler(m->diffuseMap, u->difTex, NShader::SAMPLER_TEX_BASIC_APLHA_DIF, m->type & NModel::MATERIAL_MIP_MAPPING ? NMap::FORMAT_MIPMAP : NMap::FORMAT_LINEAR);
        setSampler(m->alphaMap, u->alpTex, NShader::SAMPLER_TEX_BASIC_APLHA_ALP, m->type & NModel::MATERIAL_MIP_MAPPING ? NMap::FORMAT_MIPMAP : NMap::FORMAT_LINEAR); }
      else if(program.fSamplers & (NShader::SAMPLER_ILLUMINATION | NShader::SAMPLER_ILLUMINATION_SHADOW))
      { setSampler(m->diffuseMap, u->difTex, NShader::SAMPLER_TEX_ILLUMINATION_DIF, m->type & NModel::MATERIAL_MIP_MAPPING ? NMap::FORMAT_MIPMAP : NMap::FORMAT_LINEAR);
        setSampler(m->specularMap, u->speTex, NShader::SAMPLER_TEX_ILLUMINATION_SPE, m->type & NModel::MATERIAL_MIP_MAPPING ? NMap::FORMAT_MIPMAP : NMap::FORMAT_LINEAR);
        if(program.fSamplers & NShader::SAMPLER_ILLUMINATION_SHADOW)
          beginLPV(NShader::SAMPLER_TEX_ILLUMINATION_SHAD); }
      else if(program.fSamplers & (NShader::SAMPLER_ILLUMINATION_ALPHA | NShader::SAMPLER_ILLUMINATION_ALPHA_SHADOW))
      { setSampler(m->diffuseMap, u->difTex, NShader::SAMPLER_TEX_ILLUMINATION_ALPHA_DIF, m->type & NModel::MATERIAL_MIP_MAPPING ? NMap::FORMAT_MIPMAP : NMap::FORMAT_LINEAR);
        setSampler(m->alphaMap, u->alpTex, NShader::SAMPLER_TEX_ILLUMINATION_ALPHA_ALP, m->type & NModel::MATERIAL_MIP_MAPPING ? NMap::FORMAT_MIPMAP : NMap::FORMAT_LINEAR);
        setSampler(m->specularMap, u->speTex, NShader::SAMPLER_TEX_ILLUMINATION_ALPHA_SPE, m->type & NModel::MATERIAL_MIP_MAPPING ? NMap::FORMAT_MIPMAP : NMap::FORMAT_LINEAR);
        if(program.fSamplers & NShader::SAMPLER_ILLUMINATION_ALPHA_SHADOW)
          beginLPV(NShader::SAMPLER_TEX_ILLUMINATION_ALPHA_SHAD); }
      else if(program.fSamplers & (NShader::SAMPLER_ILLUMINATION_NORMAL | NShader::SAMPLER_ILLUMINATION_NORMAL_SHADOW))
      { setSampler(m->diffuseMap, u->difTex, NShader::SAMPLER_TEX_ILLUMINATION_NORMAL_DIF, m->type & NModel::MATERIAL_MIP_MAPPING ? NMap::FORMAT_MIPMAP : NMap::FORMAT_LINEAR);
        setSampler(m->specularMap, u->speTex, NShader::SAMPLER_TEX_ILLUMINATION_NORMAL_SPE, m->type & NModel::MATERIAL_MIP_MAPPING ? NMap::FORMAT_MIPMAP : NMap::FORMAT_LINEAR);
        setSampler(m->normalMap, u->norTex, NShader::SAMPLER_TEX_ILLUMINATION_NORMAL_NOR, m->type & NModel::MATERIAL_MIP_MAPPING ? NMap::FORMAT_MIPMAP : NMap::FORMAT_LINEAR);
        if(program.fSamplers & NShader::SAMPLER_ILLUMINATION_NORMAL_SHADOW)
          beginLPV(NShader::SAMPLER_TEX_ILLUMINATION_NORMAL_SHAD); }
      else if(program.fSamplers & (NShader::SAMPLER_ILLUMINATION_NORMAL_ALPHA | NShader::SAMPLER_ILLUMINATION_NORMAL_ALPHA_SHADOW))
      { setSampler(m->diffuseMap, u->difTex, NShader::SAMPLER_TEX_ILLUMINATION_NORMAL_ALPHA_DIF, m->type & NModel::MATERIAL_MIP_MAPPING ? NMap::FORMAT_MIPMAP : NMap::FORMAT_LINEAR);
        setSampler(m->alphaMap, u->alpTex, NShader::SAMPLER_TEX_ILLUMINATION_NORMAL_ALPHA_ALP, m->type & NModel::MATERIAL_MIP_MAPPING ? NMap::FORMAT_MIPMAP : NMap::FORMAT_LINEAR);
        setSampler(m->specularMap, u->speTex, NShader::SAMPLER_TEX_ILLUMINATION_NORMAL_ALPHA_SPE, m->type & NModel::MATERIAL_MIP_MAPPING ? NMap::FORMAT_MIPMAP : NMap::FORMAT_LINEAR);
        setSampler(m->normalMap, u->norTex, NShader::SAMPLER_TEX_ILLUMINATION_NORMAL_ALPHA_NOR, m->type & NModel::MATERIAL_MIP_MAPPING ? NMap::FORMAT_MIPMAP : NMap::FORMAT_LINEAR);
        if(program.fSamplers & NShader::SAMPLER_ILLUMINATION_NORMAL_ALPHA_SHADOW)
          beginLPV(NShader::SAMPLER_TEX_ILLUMINATION_NORMAL_ALPHA_SHAD); }
      else if(program.fSamplers & NShader::SAMPLER_GEOMETRY)
      { setSampler(m->diffuseMap, u->difTex, NShader::SAMPLER_TEX_GEOMETRY_DIF, m->type & NModel::MATERIAL_MIP_MAPPING ? NMap::FORMAT_MIPMAP : NMap::FORMAT_LINEAR);
        setSampler(m->normalMap, u->norTex, NShader::SAMPLER_TEX_GEOMETRY_NOR, m->type & NModel::MATERIAL_MIP_MAPPING ? NMap::FORMAT_MIPMAP : NMap::FORMAT_LINEAR); }

      // other material params
      if(program.fUniforms & NShader::UNIFORM_TYPE)
        gl->uniform1i(u->type, m->type);
      if(program.fUniforms & NShader::UNIFORM_OPACITY)
        gl->uniform1f(u->opacity, m->opacity);

      context->getMaps()->finishBind();
    } // end material

    // pick
    if(program.fUniforms & NShader::UNIFORM_LAMB_PICK)
      gl->uniform3f(u->lightAmb, technique->pickColor.x, technique->pickColor.y, technique->pickColor.z);
    else if((mode == NRenderer::MODE_SUN_RAYS) || (mode == NRenderer::MODE_SUN_RAYS_BACKDROP))
      gl->uniform3f(u->lightAmb, technique->sunRaysColor.x, technique->sunRaysColor.y, technique->sunRaysColor.z);

    // lights
    if(program.fUniforms & NShader::UNIFORM_TILE_SHAD)
    {
      gl->uniform4f(u->tiles, e->shadowTiles.x, e->shadowTiles.y, 1.0f / e->shadowTiles.x, 1.0f / e->shadowTiles.y);
      gl->uniform1iv(u->tileInstances, e->shadowCascadesCount, &technique->tileShadowInstances[0]);
    }
    else if(program.fUniforms & NShader::UNIFORM_TILE_GEOM)
    {
      gl->uniform4f(u->tiles, e->geometryTiles.x, e->geometryTiles.y, 1.0f / e->geometryTiles.x, 1.0f / e->geometryTiles.y);
      gl->uniform1iv(u->tileInstances, e->lpvCascadesCount * e->lpvSunSkySpecDirsCount, &technique->tileGeometryInstances[0]);
    }
    if(program.fUniforms & NShader::UNIFORM_SHAD_TEX_SIZE)
      gl->uniform3f(u->shadowTexSize, 1.0f / static_cast<float>(e->shadowTextureSize * e->shadowTiles.x), 1.0f / static_cast<float>(e->shadowTextureSize * e->shadowTiles.y), context->engineGetEngine()->shadowJittering);
    if(program.fUniforms & NShader::UNIFORM_SHAD_CLIPS)
      gl->uniform2fv(u->shadowClips, e->shadowCascadesCount, &e->shadowCascadesClips[0]);
    if(program.fUniforms & NShader::UNIFORM_LAMB_LPOS)
    { gl->uniform3f(u->lightAmb, technique->lightAmb.x, technique->lightAmb.y, technique->lightAmb.z);
      gl->uniform3f(u->lightPos, technique->lights[0].pos.x, technique->lights[0].pos.y, technique->lights[0].pos.z);  }
    if(program.fUniforms & NShader::UNIFORM_LRAN_LCOL_LSPEC_FRAN_FCOL)
    { const SCamera *cam = context->getCamera()->getCamera();
      gl->uniform2f(u->lightRange, technique->lights[0].range.x, technique->lights[0].range.y);
      gl->uniform3f(u->lightColor, technique->lights[0].color.x, technique->lights[0].color.y, technique->lights[0].color.z);
      gl->uniform4f(u->lightSpeColor, technique->lights[0].speColor.x, technique->lights[0].speColor.y, technique->lights[0].speColor.z, technique->lights[0].speColor.w);
      gl->uniform2f(u->fogRange, technique->fogRange.x * cam->clipFar, technique->fogRange.y * cam->clipFar);
      gl->uniform3f(u->fogColor, technique->fogColor.x, technique->fogColor.y, technique->fogColor.z); }
  } // end technique

  // lpv params
  if(program.fUniforms & NShader::UNIFORM_LAMB_LPOS_INJECT)
  { gl->uniform3fv(u->lightAmb, e->lpvSunSkyDirsCount, &e->sunSkyColors[0]);
    gl->uniform3fv(u->lightPos, e->lpvSunSkyDirsCount, &e->sunSkyPoses[0]); }
  if(program.fUniforms & NShader::UNIFORM_GEOM_POS)
    gl->uniform3fv(u->geomPos, e->lpvCascadesCount, &e->geometryPos[0]);
  if(program.fUniforms & NShader::UNIFORM_GEOM_TEX_SIZE)
  { gl->uniform4f(u->tiles,
      e->geometryTiles.x,
      e->geometryTiles.y,
      1.0f / (e->geometryTiles.x - static_cast<float>(
        ((mode >= NRenderer::MODE_LPV_CLEAR_COMPUTE) && (mode <= NRenderer::MODE_SSLPV_PROPAGATION_SCATTERING_COMPUTE)) ?
          (e->lpvDirsReservedCount + ((e->lpvGV) ? 0 : e->lpvSpecialDirsCount)) : // cs inject: tile: 1, else gv: 3
          ((program.fUniforms & NShader::UNIFORM_GEOM_GV_TEX_SIZE) ? e->lpvDirsReservedCount : (e->lpvSpecialDirsCount + e->lpvSkyDirsCount)) // normal inject: 1 tile column, gv inject: 3 cols
        )),
      1.0f / e->geometryTiles.y);
    gl->uniform4f(u->geomTexSize,
      e->geometryTextureSize * (e->geometryTiles.x - static_cast<float>(
        ((mode >= NRenderer::MODE_LPV_CLEAR_COMPUTE) && (mode <= NRenderer::MODE_SSLPV_PROPAGATION_SCATTERING_COMPUTE)) ?
          (e->lpvDirsReservedCount + ((e->lpvGV) ? 0 : e->lpvSpecialDirsCount)) : // cs inject: points for 1 col, else gv: 3 cols
          ((program.fUniforms & NShader::UNIFORM_GEOM_GV_TEX_SIZE) ? e->lpvDirsReservedCount : (e->lpvSpecialDirsCount + e->lpvSkyDirsCount)) // gs inject: points for 1 column (= g-buf width), gv inject: 3 cols
        )),
      e->geometryTextureSize * e->geometryTiles.y,
      1.0f / static_cast<float>(e->geometryTextureSize * e->geometryTiles.x), // texture size x, y
      1.0f / static_cast<float>(e->geometryTextureSize * e->geometryTiles.y)); }
  if(program.fUniforms & NShader::UNIFORM_LPV_POS_TEXS_CELLS_PARAMS)
  { gl->uniform3fv(u->lpvPos, e->lpvCascadesCount, &e->lpvPoses[0]);
    gl->uniform3f(u->lpvTexSize, e->lpvTextureSize.x * e->lpvCascadesCount, e->lpvTextureSize.y, e->lpvTextureSize.z);
    gl->uniform3fv(u->lpvCellSize, e->lpvCascadesCount, &e->lpvCellSizes[0]);
    gl->uniform4f(u->lpvParams, e->lpvPropagationSteps, e->lpvIntensity, e->lpvReflIntensity,
      (((mode >= NRenderer::MODE_SSLPV_CLEAR_GEOMETRY) && (mode <= NRenderer::MODE_SSLPV_PROPAGATION_SCATTERING_GEOMETRY)) ||
       ((mode >= NRenderer::MODE_SSLPV_CLEAR_COMPUTE) && (mode <= NRenderer::MODE_SSLPV_PROPAGATION_SCATTERING_COMPUTE))) ? -1.0 : 1.0); }

  // lpv samplers, images
  if(program.fSamplers & NShader::SAMPLER_LPV_INJECTION_GEOMETRY)
  { setSampler(u->geomColorMap, u->geomColorTex, NShader::SAMPLER_TEX_LPV_INJECTION_GEOMETRY_GEOM_COLOR, NMap::FORMAT_BORDER);
    setSampler(u->geomPosMap, u->geomPosTex, NShader::SAMPLER_TEX_LPV_INJECTION_GEOMETRY_GEOM_POS, NMap::FORMAT_BORDER);
    setSampler(u->geomNormalMap, u->geomNormalTex, NShader::SAMPLER_TEX_LPV_INJECTION_GEOMETRY_GEOM_NORMAL, NMap::FORMAT_BORDER);
    /*setSampler(u->geomDepthMap, u->geomDepthTex, NShader::SAMPLER_TEX_LPV_INJECTION_GEOMETRY_GEOM_DEPTH, NMap::FORMAT_BORDER);*/ }
  else if(program.fSamplers & NShader::SAMPLER_LPV_LOBE_INJECTION_GEOMETRY)
  { const CMap *const lpvMaps[] = { u->lpvNormalGs0Map, u->sslpvNormalGs0Map };
    const uint32 i = (mode == NRenderer::MODE_LPV_INJECTION_GEOMETRY) ? 0 : 1;
    setSampler(lpvMaps[i], u->lpvNormalTex, NShader::SAMPLER_TEX_LPV_LOBE_INJECTION_GEOMETRY_NORMAL, NMap::FORMAT_BORDER); }
  else if(program.fSamplers & NShader::SAMPLER_LPV_PROPAGATION_GEOMETRY)
  { const CMap *const lpvMaps[] = {
      u->lpvGs0MapR, u->lpvGs0MapG, u->lpvGs0MapB, u->lpvAccumGs0MapR, u->lpvAccumGs0MapG, u->lpvAccumGs0MapB, u->lpvLobeGs1Map,
      u->lpvGs1MapR, u->lpvGs1MapG, u->lpvGs1MapB, u->lpvAccumGs1MapR, u->lpvAccumGs1MapG, u->lpvAccumGs1MapB, u->lpvLobeGs0Map,
      u->sslpvGs0MapR, u->sslpvGs0MapG, u->sslpvGs0MapB, u->sslpvAccumGs0MapR, u->sslpvAccumGs0MapG, u->sslpvAccumGs0MapB, u->sslpvLobeGs1Map,
      u->sslpvGs1MapR, u->sslpvGs1MapG, u->sslpvGs1MapB, u->sslpvAccumGs1MapR, u->sslpvAccumGs1MapG, u->sslpvAccumGs1MapB, u->sslpvLobeGs0Map };
    const uint32 i = (((mode == NRenderer::MODE_LPV_PROPAGATION_GATHERING_GEOMETRY) || (mode == NRenderer::MODE_LPV_PROPAGATION_SCATTERING_GEOMETRY)) ? 0 : 14) + 
      ((!context->engineGetEngine()->lpvPropagationSwap) ? 0 : 7);
    setSampler(lpvMaps[i + 0], u->lpvTexR, NShader::SAMPLER_TEX_LPV_PROPAGATION_GEOMETRY_LPV_R, NMap::FORMAT_BORDER);
    setSampler(lpvMaps[i + 1], u->lpvTexG, NShader::SAMPLER_TEX_LPV_PROPAGATION_GEOMETRY_LPV_G, NMap::FORMAT_BORDER);
    setSampler(lpvMaps[i + 2], u->lpvTexB, NShader::SAMPLER_TEX_LPV_PROPAGATION_GEOMETRY_LPV_B, NMap::FORMAT_BORDER);
    setSampler(lpvMaps[i + 3], u->lpvAccumTexR, NShader::SAMPLER_TEX_LPV_PROPAGATION_GEOMETRY_LPV_ACCUM_R, NMap::FORMAT_BORDER);
    setSampler(lpvMaps[i + 4], u->lpvAccumTexG, NShader::SAMPLER_TEX_LPV_PROPAGATION_GEOMETRY_LPV_ACCUM_G, NMap::FORMAT_BORDER);
    setSampler(lpvMaps[i + 5], u->lpvAccumTexB, NShader::SAMPLER_TEX_LPV_PROPAGATION_GEOMETRY_LPV_ACCUM_B, NMap::FORMAT_BORDER);
    setSampler(lpvMaps[i + 6], u->lpvNormalTex, NShader::SAMPLER_TEX_LPV_PROPAGATION_GEOMETRY_NORMAL, NMap::FORMAT_BORDER);
    setSampler(u->gvGsMap, u->gvTex, NShader::SAMPLER_TEX_LPV_PROPAGATION_GEOMETRY_GV, NMap::FORMAT_BORDER); }
  else if(program.fSamplers & NShader::SAMPLER_LPV_LOBE_PROPAGATION_GEOMETRY)
  { const CMap *const lpvMaps[] = {
      u->lpvLobeGs0Map, u->lpvLobeGs1Map, u->sslpvLobeGs0Map, u->sslpvLobeGs1Map };
    const uint32 i = (((mode == NRenderer::MODE_LPV_PROPAGATION_GATHERING_GEOMETRY) || (mode == NRenderer::MODE_LPV_PROPAGATION_SCATTERING_GEOMETRY)) ? 0 : 2) +
      ((!context->engineGetEngine()->lpvPropagationSwap) ? 0 : 1);
    setSampler(lpvMaps[i + 0], u->lpvNormalTex, NShader::SAMPLER_TEX_LPV_LOBE_PROPAGATION_GEOMETRY_NORMAL, NMap::FORMAT_BORDER); }
  else if(program.fSamplers & NShader::IMAGE_LPV_CLEAR_COMPUTE)
  { if(mode == NRenderer::MODE_LPV_CLEAR_COMPUTE)
    { setSampler(u->lpvAccumGs0MapR, u->lpvAccumTexR, NShader::IMAGE_TEX_LPV_PROPAGATION_COMPUTE_LPV_R, NMap::FORMAT_IMAGE_W);
      setSampler(u->lpvAccumGs0MapG, u->lpvAccumTexG, NShader::IMAGE_TEX_LPV_PROPAGATION_COMPUTE_LPV_G, NMap::FORMAT_IMAGE_W);
      setSampler(u->lpvAccumGs0MapB, u->lpvAccumTexB, NShader::IMAGE_TEX_LPV_PROPAGATION_COMPUTE_LPV_B, NMap::FORMAT_IMAGE_W);
      setSampler(u->lpv0CsMap, u->lpv0Tex, NShader::IMAGE_TEX_LPV_CLEAR_COMPUTE_LPV0, NMap::FORMAT_IMAGE_W);
      setSampler(u->lpv1CsMap, u->lpv1Tex, NShader::IMAGE_TEX_LPV_CLEAR_COMPUTE_LPV1, NMap::FORMAT_IMAGE_W);
      setSampler(u->lpvAccumCsMap, u->lpvAccumTex, NShader::IMAGE_TEX_LPV_CLEAR_COMPUTE_LPV_ACCUM, NMap::FORMAT_IMAGE_W);
      setSampler(u->lpvNormalAccumCsMap, u->lpvNormalAccumTex, NShader::IMAGE_TEX_LPV_CLEAR_COMPUTE_LPV_NORMAL_ACCUM, NMap::FORMAT_IMAGE_W);
      setSampler(u->gvCsMap, u->gvTex, NShader::IMAGE_TEX_LPV_CLEAR_COMPUTE_GV, NMap::FORMAT_IMAGE_W); }
    else
    { setSampler(u->sslpvAccumGs0MapR, u->lpvAccumTexR, NShader::IMAGE_TEX_LPV_PROPAGATION_COMPUTE_LPV_R, NMap::FORMAT_IMAGE_W);
      setSampler(u->sslpvAccumGs0MapG, u->lpvAccumTexG, NShader::IMAGE_TEX_LPV_PROPAGATION_COMPUTE_LPV_G, NMap::FORMAT_IMAGE_W);
      setSampler(u->sslpvAccumGs0MapB, u->lpvAccumTexB, NShader::IMAGE_TEX_LPV_PROPAGATION_COMPUTE_LPV_B, NMap::FORMAT_IMAGE_W);
      setSampler(u->sslpv0CsMap, u->lpv0Tex, NShader::IMAGE_TEX_LPV_CLEAR_COMPUTE_LPV0, NMap::FORMAT_IMAGE_W);
      setSampler(u->sslpv1CsMap, u->lpv1Tex, NShader::IMAGE_TEX_LPV_CLEAR_COMPUTE_LPV1, NMap::FORMAT_IMAGE_W);
      setSampler(u->sslpvAccumCsMap, u->lpvAccumTex, NShader::IMAGE_TEX_LPV_CLEAR_COMPUTE_LPV_ACCUM, NMap::FORMAT_IMAGE_W);
      setSampler(u->sslpvNormalAccumCsMap, u->lpvNormalAccumTex, NShader::IMAGE_TEX_LPV_CLEAR_COMPUTE_LPV_NORMAL_ACCUM, NMap::FORMAT_IMAGE_W); } }
  else if(program.fSamplers & NShader::IMAGE_LPV_INJECTION_COMPUTE)
  { setSampler(u->geomColorMap, u->geomColorTex, NShader::IMAGE_TEX_LPV_INJECTION_COMPUTE_GEOM_COLOR, NMap::FORMAT_IMAGE_R);
    setSampler(u->geomPosMap, u->geomPosTex, NShader::IMAGE_TEX_LPV_INJECTION_COMPUTE_GEOM_POS, NMap::FORMAT_IMAGE_R);
    setSampler(u->geomNormalMap, u->geomNormalTex, NShader::IMAGE_TEX_LPV_INJECTION_COMPUTE_GEOM_NORMAL, NMap::FORMAT_IMAGE_R);
    //setSampler(u->geomDepthMap, u->geomDepthTex, NShader::IMAGE_TEX_LPV_INJECTION_COMPUTE_GEOM_DEPTH, NMap::FORMAT_IMAGE_R);
    if(mode == NRenderer::MODE_LPV_INJECTION_COMPUTE)
    { setSampler(u->lpv0CsMap, u->lpv0Tex, NShader::IMAGE_TEX_LPV_INJECTION_COMPUTE_LPV, NMap::FORMAT_IMAGE_RW);
      setSampler(u->lpvAccumCsMap, u->lpvAccumTex, NShader::IMAGE_TEX_LPV_INJECTION_COMPUTE_LPV_ACCUM, NMap::FORMAT_IMAGE_RW);
      setSampler(u->lpvNormalAccumCsMap, u->lpvNormalAccumTex, NShader::IMAGE_TEX_LPV_INJECTION_COMPUTE_LPV_NORMAL_ACCUM, NMap::FORMAT_IMAGE_RW);
      setSampler(u->gvCsMap, u->gvTex, NShader::IMAGE_TEX_LPV_INJECTION_COMPUTE_GV, NMap::FORMAT_IMAGE_RW); }
    else
    { setSampler(u->sslpv0CsMap, u->lpv0Tex, NShader::IMAGE_TEX_LPV_INJECTION_COMPUTE_LPV, NMap::FORMAT_IMAGE_RW);
      setSampler(u->sslpvAccumCsMap, u->lpvAccumTex, NShader::IMAGE_TEX_LPV_INJECTION_COMPUTE_LPV_ACCUM, NMap::FORMAT_IMAGE_RW);
      setSampler(u->sslpvNormalAccumCsMap, u->lpvNormalAccumTex, NShader::IMAGE_TEX_LPV_INJECTION_COMPUTE_LPV_NORMAL_ACCUM, NMap::FORMAT_IMAGE_RW); } }
  else if(program.fSamplers & NShader::IMAGE_LPV_PROPAGATION_COMPUTE)
  { if((mode == NRenderer::MODE_LPV_PROPAGATION_GATHERING_COMPUTE) || (mode == NRenderer::MODE_LPV_PROPAGATION_SCATTERING_COMPUTE))
    { setSampler(u->lpvAccumGs0MapR, u->lpvAccumTexR, NShader::IMAGE_TEX_LPV_PROPAGATION_COMPUTE_LPV_R, NMap::FORMAT_IMAGE_W);
      setSampler(u->lpvAccumGs0MapG, u->lpvAccumTexG, NShader::IMAGE_TEX_LPV_PROPAGATION_COMPUTE_LPV_G, NMap::FORMAT_IMAGE_W);
      setSampler(u->lpvAccumGs0MapB, u->lpvAccumTexB, NShader::IMAGE_TEX_LPV_PROPAGATION_COMPUTE_LPV_B, NMap::FORMAT_IMAGE_W);
      setSampler(u->lpv0CsMap, u->lpv0Tex, NShader::IMAGE_TEX_LPV_PROPAGATION_COMPUTE_LPV0, NMap::FORMAT_IMAGE_RW);
      setSampler(u->lpv1CsMap, u->lpv1Tex, NShader::IMAGE_TEX_LPV_PROPAGATION_COMPUTE_LPV1, NMap::FORMAT_IMAGE_RW);
      setSampler(u->lpvAccumCsMap, u->lpvAccumTex, NShader::IMAGE_TEX_LPV_PROPAGATION_COMPUTE_LPV_ACCUM, NMap::FORMAT_IMAGE_RW);
      setSampler(u->lpvNormalAccumCsMap, u->lpvNormalAccumTex, NShader::IMAGE_TEX_LPV_PROPAGATION_COMPUTE_LPV_NORMAL_ACCUM, NMap::FORMAT_IMAGE_RW);
      setSampler(u->gvCsMap, u->gvTex, NShader::IMAGE_TEX_LPV_PROPAGATION_COMPUTE_GV, NMap::FORMAT_IMAGE_R); }
    else
    { setSampler(u->sslpvAccumGs0MapR, u->lpvAccumTexR, NShader::IMAGE_TEX_LPV_PROPAGATION_COMPUTE_LPV_R, NMap::FORMAT_IMAGE_W);
      setSampler(u->sslpvAccumGs0MapG, u->lpvAccumTexG, NShader::IMAGE_TEX_LPV_PROPAGATION_COMPUTE_LPV_G, NMap::FORMAT_IMAGE_W);
      setSampler(u->sslpvAccumGs0MapB, u->lpvAccumTexB, NShader::IMAGE_TEX_LPV_PROPAGATION_COMPUTE_LPV_B, NMap::FORMAT_IMAGE_W);
      setSampler(u->sslpv0CsMap, u->lpv0Tex, NShader::IMAGE_TEX_LPV_PROPAGATION_COMPUTE_LPV0, NMap::FORMAT_IMAGE_RW);
      setSampler(u->sslpv1CsMap, u->lpv1Tex, NShader::IMAGE_TEX_LPV_PROPAGATION_COMPUTE_LPV1, NMap::FORMAT_IMAGE_RW);
      setSampler(u->sslpvAccumCsMap, u->lpvAccumTex, NShader::IMAGE_TEX_LPV_PROPAGATION_COMPUTE_LPV_ACCUM, NMap::FORMAT_IMAGE_RW);
      setSampler(u->sslpvNormalAccumCsMap, u->lpvNormalAccumTex, NShader::IMAGE_TEX_LPV_PROPAGATION_COMPUTE_LPV_NORMAL_ACCUM, NMap::FORMAT_IMAGE_RW); } }
}
//------------------------------------------------------------------------------
void CShaderProgram::end(const SShaderState *technique) const
{
  UNUSED(technique);
  COpenGL *gl = context->getOpenGL();
  const SShaderUniforms *u = &program.uniforms;

  if(program.fAttribs & NShader::ATTRIB_PT_POSITION)
    gl->disableVertexAttribArray(u->vertexPosition);
  if(program.fAttribs & NShader::ATTRIB_PT_TEX_COORD)
    gl->disableVertexAttribArray(u->vertexTexCoord);
  if(program.fAttribs & NShader::ATTRIB_PNTBTC_POSITION)
    gl->disableVertexAttribArray(u->vertexPosition);
  if(program.fAttribs & NShader::ATTRIB_PNTBTC_NORMAL)
    gl->disableVertexAttribArray(u->vertexNormal);
  if(program.fAttribs & NShader::ATTRIB_PNTBTC_NORMAL_TANGENT)
    gl->disableVertexAttribArray(u->vertexNormalTangent);
  if(program.fAttribs & NShader::ATTRIB_PNTBTC_NORMAL_BITANGENT)
    gl->disableVertexAttribArray(u->vertexNormalBitangent);
  if(program.fAttribs & NShader::ATTRIB_PNTBTC_TEX_COORD)
    gl->disableVertexAttribArray(u->vertexTexCoord);
  if(program.fAttribs & NShader::ATTRIB_PNTBTC_COLOR)
    gl->disableVertexAttribArray(u->vertexColor);
  if(program.fAttribs & NShader::ATTRIB_F)
    gl->disableVertexAttribArray(u->vertexPosition);

  if(program.fSamplers & NShader::IMAGE_LPV_CLEAR_COMPUTE)
  { setSampler(NULL, u->lpv0Tex, NShader::IMAGE_TEX_LPV_CLEAR_COMPUTE_LPV0, NMap::FORMAT_IMAGE_W);
    setSampler(NULL, u->lpv1Tex, NShader::IMAGE_TEX_LPV_CLEAR_COMPUTE_LPV1, NMap::FORMAT_IMAGE_W);
    setSampler(NULL, u->lpvAccumTex, NShader::IMAGE_TEX_LPV_CLEAR_COMPUTE_LPV_ACCUM, NMap::FORMAT_IMAGE_W);
    setSampler(NULL, u->lpvNormalAccumTex, NShader::IMAGE_TEX_LPV_CLEAR_COMPUTE_LPV_NORMAL_ACCUM, NMap::FORMAT_IMAGE_W);
    setSampler(NULL, u->gvTex, NShader::IMAGE_TEX_LPV_CLEAR_COMPUTE_GV, NMap::FORMAT_IMAGE_W); }
  else if(program.fSamplers & NShader::IMAGE_LPV_INJECTION_COMPUTE)
  { setSampler(NULL, u->geomColorTex, NShader::IMAGE_TEX_LPV_INJECTION_COMPUTE_GEOM_COLOR, NMap::FORMAT_IMAGE_R);
    setSampler(NULL, u->geomPosTex, NShader::IMAGE_TEX_LPV_INJECTION_COMPUTE_GEOM_POS, NMap::FORMAT_IMAGE_R);
    setSampler(NULL, u->geomNormalTex, NShader::IMAGE_TEX_LPV_INJECTION_COMPUTE_GEOM_NORMAL, NMap::FORMAT_IMAGE_R);
    //setSampler(NULL, u->geomDepthTex, NShader::IMAGE_TEX_LPV_INJECTION_COMPUTE_GEOM_DEPTH, NMap::FORMAT_IMAGE_R);
    setSampler(NULL, u->lpv0Tex, NShader::IMAGE_TEX_LPV_INJECTION_COMPUTE_LPV, NMap::FORMAT_IMAGE_W);
    setSampler(NULL, u->lpvAccumTex, NShader::IMAGE_TEX_LPV_INJECTION_COMPUTE_LPV_ACCUM, NMap::FORMAT_IMAGE_W);
    setSampler(NULL, u->lpvNormalAccumTex, NShader::IMAGE_TEX_LPV_INJECTION_COMPUTE_LPV_NORMAL_ACCUM, NMap::FORMAT_IMAGE_W);
    setSampler(NULL, u->gvTex, NShader::IMAGE_TEX_LPV_INJECTION_COMPUTE_GV, NMap::FORMAT_IMAGE_W); }
  else if(program.fSamplers & NShader::IMAGE_LPV_PROPAGATION_COMPUTE)
  { setSampler(NULL, u->lpvTexR, NShader::IMAGE_TEX_LPV_PROPAGATION_COMPUTE_LPV_R, NMap::FORMAT_IMAGE_W);
    setSampler(NULL, u->lpvTexG, NShader::IMAGE_TEX_LPV_PROPAGATION_COMPUTE_LPV_G, NMap::FORMAT_IMAGE_W);
    setSampler(NULL, u->lpvTexB, NShader::IMAGE_TEX_LPV_PROPAGATION_COMPUTE_LPV_B, NMap::FORMAT_IMAGE_W);
    setSampler(NULL, u->lpv0Tex, NShader::IMAGE_TEX_LPV_PROPAGATION_COMPUTE_LPV0, NMap::FORMAT_IMAGE_RW);
    setSampler(NULL, u->lpv1Tex, NShader::IMAGE_TEX_LPV_PROPAGATION_COMPUTE_LPV1, NMap::FORMAT_IMAGE_RW);
    setSampler(NULL, u->lpvAccumTex, NShader::IMAGE_TEX_LPV_PROPAGATION_COMPUTE_LPV_ACCUM, NMap::FORMAT_IMAGE_W);
    setSampler(NULL, u->lpvNormalAccumTex, NShader::IMAGE_TEX_LPV_PROPAGATION_COMPUTE_LPV_NORMAL_ACCUM, NMap::FORMAT_IMAGE_W);
    setSampler(NULL, u->gvTex, NShader::IMAGE_TEX_LPV_PROPAGATION_COMPUTE_GV, NMap::FORMAT_IMAGE_R); }
}
//------------------------------------------------------------------------------
void CShaderProgram::unbind() const
{
  context->getOpenGL()->useProgram(0);
}
//------------------------------------------------------------------------------
void CShaderProgram::dispatch(uint32 x, uint32 y, uint32 z, NRenderer::EMode mode, GLbitfield preSync, GLbitfield postSync) const
{
  COpenGL *gl = context->getOpenGL();

  if(preSync)
    gl->memoryBarrier(NOpenGL::ALL_BARRIER_BITS);

  bind();
  begin(NULL, mode);
  gl->dispatchCompute(x, y, z);
  end(NULL);
  unbind();

  if(postSync)
    gl->memoryBarrier(NOpenGL::ALL_BARRIER_BITS);
}
//------------------------------------------------------------------------------
CShaders::CShaders() : CEngineBase()
{
}
//------------------------------------------------------------------------------
CShaders::CShaders(CContext *context) : CEngineBase(context)
{
}
//------------------------------------------------------------------------------
CShaders::~CShaders()
{
}
//------------------------------------------------------------------------------
