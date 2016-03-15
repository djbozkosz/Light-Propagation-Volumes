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
void CShader::compile()
{
  if(shader.type == NShader::TYPE_UNDEFINED)
    return;

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
    context->log(CStr(NShader::STR_ERROR_COMPILE_SKIP, shader.file.c_str()));
    return;
  }

  CFile *f = context->getFilesystem()->open(SFile(std::string(NFile::STR_DATA_SHADERS)+shader.file));

  if(!f)
    return;

  std::string data(f->size(), ' ');
  f->read(&data[0], data.length());

  if(context->engineGetEngine()->gpuPlatform == NEngine::GPU_PLATFORM_GL0200_ES)
    data = setES2compatible(data);

  const char *d = data.c_str();

  //qDebug(d);
  shader.shader = gl->createShader(shaderType);
  gl->shaderSource(shader.shader, 1, &d, NULL);
  gl->compileShader(shader.shader);
  gl->getShaderiv(shader.shader, NOpenGL::COMPILE_STATUS, &status);
  gl->getShaderiv(shader.shader, NOpenGL::INFO_LOG_LENGTH, &infoLength);

  log.resize(infoLength);
  if(infoLength)
    gl->getShaderInfoLog(shader.shader, infoLength, &infoLength, &log[0]);
  if((&log[0]) && (status == NOpenGL::TRUE) && (log.find("warning") != std::string::npos))
    context->log(log);

  if(status == NOpenGL::FALSE)
    context->engineShowMessage(CStr(NShader::STR_ERROR_COMPILE, shader.file.c_str()), log.c_str(), false);

  f->close();
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
  auto index = d.find("in ");
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
void CShaderProgram::link()
{
  COpenGL *gl = context->getOpenGL();
  GLint status = 0;
  GLint infoLength = 0;
  std::string log;
  const NEngine::EGPUPlatform platform = context->engineGetEngine()->gpuPlatform;

  program.program = gl->createProgram();

  if(((program.geometryShader) && (platform < NEngine::GPU_PLATFORM_GL0302)) ||
     ((program.tesselationControlShader) && (platform < NEngine::GPU_PLATFORM_GL0400)) ||
     ((program.tesselationEvaluationShader) && (platform < NEngine::GPU_PLATFORM_GL0400)) ||
     ((program.computeShader) && (platform < NEngine::GPU_PLATFORM_GL0403)))
  {
    context->log(CStr(NShader::STR_ERROR_LINK_SKIP, NShader::STR_PROGRAM_LIST[program.name]));
    return;
  }

  if(program.vertexShader)
    gl->attachShader(program.program, program.vertexShader->getShader()->shader);
  if(program.geometryShader)
    gl->attachShader(program.program, program.geometryShader->getShader()->shader);
  if(program.tesselationControlShader)
    gl->attachShader(program.program, program.tesselationControlShader->getShader()->shader);
  if(program.tesselationEvaluationShader)
    gl->attachShader(program.program, program.tesselationEvaluationShader->getShader()->shader);
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
  if((&log[0]) && (status == NOpenGL::TRUE) && (log.find("warning") != std::string::npos))
    context->log(log);
#endif

  if(status == NOpenGL::FALSE)
    context->engineShowMessage(CStr(NShader::STR_ERROR_LINK, NShader::STR_PROGRAM_LIST[program.name]), log.c_str(), false);
}
//------------------------------------------------------------------------------
void CShaderProgram::initUniforms()
{
  COpenGL *gl = context->getOpenGL();
  SShaderUniforms *u = &program.uniforms;

  u->vertexPosition = gl->getAttribLocation(program.program, NShader::STR_ATTRIB_VERTEX_POSITION);
  u->vertexNormal = gl->getAttribLocation(program.program, NShader::STR_ATTRIB_VERTEX_NORMAL);
  u->vertexNormalTangent = gl->getAttribLocation(program.program, NShader::STR_ATTRIB_VERTEX_NORMAL_TANGENT);
  //u->vertexNormalBitangent = gl->getAttribLocation(program.program, NShader::STR_ATTRIB_VERTEX_NORMAL_BITANGENT);
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

  u->geomColorTex = gl->getUniformLocation(program.program, NShader::STR_UNIFORM_GEOM_COLOR_TEX);
  u->geomPosTex = gl->getUniformLocation(program.program, NShader::STR_UNIFORM_GEOM_POS_TEX);
  u->geomNormalTex = gl->getUniformLocation(program.program, NShader::STR_UNIFORM_GEOM_NORMAL_TEX);
  //u->geomDepthTex = gl->getUniformLocation(program.program, NShader::STR_UNIFORM_GEOM_DEPTH_TEX);

  u->lpvTexR = gl->getUniformLocation(program.program, NShader::STR_UNIFORM_LPV_TEX_R);
  u->lpvTexG = gl->getUniformLocation(program.program, NShader::STR_UNIFORM_LPV_TEX_G);
  u->lpvTexB = gl->getUniformLocation(program.program, NShader::STR_UNIFORM_LPV_TEX_B);
  u->gvTex = gl->getUniformLocation(program.program, NShader::STR_UNIFORM_GV_TEX);
  u->lpv0TexR = gl->getUniformLocation(program.program, NShader::STR_UNIFORM_LPV0_TEX_R);
  u->lpv0TexG = gl->getUniformLocation(program.program, NShader::STR_UNIFORM_LPV0_TEX_G);
  u->lpv0TexB = gl->getUniformLocation(program.program, NShader::STR_UNIFORM_LPV0_TEX_B);
  u->lpv1TexR = gl->getUniformLocation(program.program, NShader::STR_UNIFORM_LPV1_TEX_R);
  u->lpv1TexG = gl->getUniformLocation(program.program, NShader::STR_UNIFORM_LPV1_TEX_G);
  u->lpv1TexB = gl->getUniformLocation(program.program, NShader::STR_UNIFORM_LPV1_TEX_B);

  u->type = gl->getUniformLocation(program.program, NShader::STR_UNIFORM_TYPE);
  u->opacity = gl->getUniformLocation(program.program, NShader::STR_UNIFORM_OPACITY);
  u->shadowTexSize = gl->getUniformLocation(program.program, NShader::STR_UNIFORM_SHADOW_TEX_SIZE);
  u->lightAmb = gl->getUniformLocation(program.program, NShader::STR_UNIFORM_LIGHT_AMB);
  u->lightPos = gl->getUniformLocation(program.program, NShader::STR_UNIFORM_LIGHT_POS);
  u->lightRange = gl->getUniformLocation(program.program, NShader::STR_UNIFORM_LIGHT_RANGE);
  u->lightColor = gl->getUniformLocation(program.program, NShader::STR_UNIFORM_LIGHT_COLOR);
  u->lightSpeColor = gl->getUniformLocation(program.program, NShader::STR_UNIFORM_LIGHT_SPEC_COLOR);
  u->fogRange = gl->getUniformLocation(program.program, NShader::STR_UNIFORM_FOG_RANGE);
  u->fogColor = gl->getUniformLocation(program.program, NShader::STR_UNIFORM_FOG_COLOR);

  u->geomTexSize = gl->getUniformLocation(program.program, NShader::STR_UNIFORM_GEOM_TEX_SIZE);
  u->lpvPos = gl->getUniformLocation(program.program, NShader::STR_UNIFORM_LPV_POS);
  u->lpvSize = gl->getUniformLocation(program.program, NShader::STR_UNIFORM_LPV_SIZE);
  u->lpvCellSize = gl->getUniformLocation(program.program, NShader::STR_UNIFORM_LPV_CELL_SIZE);
  u->lpvParams = gl->getUniformLocation(program.program, NShader::STR_UNIFORM_LPV_PARAMS);
}
//------------------------------------------------------------------------------
void CShaderProgram::bind() const
{
  context->getOpenGL()->useProgram(program.program);
}
//------------------------------------------------------------------------------
void CShaderProgram::begin(const SShaderTechnique *technique, NRenderer::EMode mode) const
{
  COpenGL *gl = context->getOpenGL();
  const SShaderUniforms *u = &program.uniforms;

  if(program.name <= NShader::PROGRAM_DEPTH_CASCADE_COLOR_KEY)
  { // vbo attribs pack:   pos, tex
    const GLsizei stride = sizeof(float) * NModel::VERTEX_PT_SIZE;

    if(program.name >= NShader::PROGRAM_COLOR)
    {
      gl->enableVertexAttribArray(u->vertexPosition);
      gl->vertexAttribPointer(u->vertexPosition, NModel::VERTEX_SIZE_POSITION, NOpenGL::FLOAT, NOpenGL::FALSE, stride, reinterpret_cast<float *>(sizeof(float) * NModel::VERTEX_PT_OFFSET_POSITION));
    }
    if((program.name == NShader::PROGRAM_DEPTH_COLOR_KEY) || (program.name == NShader::PROGRAM_DEPTH_CASCADE_COLOR_KEY))
    {
      gl->enableVertexAttribArray(u->vertexTexCoord);
      gl->vertexAttribPointer(u->vertexTexCoord, NModel::VERTEX_SIZE_TEX_COORD, NOpenGL::FLOAT, NOpenGL::FALSE, stride, reinterpret_cast<float *>(sizeof(float) * NModel::VERTEX_PT_OFFSET_TEX_COORD));
    }
  }
  else if(program.name <= NShader::PROGRAM_GEOMETRY_CASCADE)
  { // vbo attribs pack:   pos, nor, tan, tex, col
    const GLsizei stride = sizeof(float) * NModel::VERTEX_PNTTC_SIZE;

    if(program.name >= NShader::PROGRAM_BASIC)
    {
      gl->enableVertexAttribArray(u->vertexPosition);
      gl->enableVertexAttribArray(u->vertexTexCoord);
      gl->enableVertexAttribArray(u->vertexColor);
      gl->vertexAttribPointer(u->vertexPosition, NModel::VERTEX_SIZE_POSITION, NOpenGL::FLOAT, NOpenGL::FALSE, stride, reinterpret_cast<float *>(sizeof(float) * NModel::VERTEX_PNTTC_OFFSET_POSITION));
      gl->vertexAttribPointer(u->vertexTexCoord, NModel::VERTEX_SIZE_TEX_COORD, NOpenGL::FLOAT, NOpenGL::FALSE, stride, reinterpret_cast<float *>(sizeof(float) * NModel::VERTEX_PNTTC_OFFSET_TEX_COORD));
      gl->vertexAttribPointer(u->vertexColor, NModel::VERTEX_SIZE_COLOR, NOpenGL::FLOAT, NOpenGL::FALSE, stride, reinterpret_cast<float *>(sizeof(float) * NModel::VERTEX_PNTTC_OFFSET_COLOR));
    }
    if(program.name >= NShader::PROGRAM_PER_FRAGMENT)
    {
      gl->enableVertexAttribArray(u->vertexNormal);
      gl->vertexAttribPointer(u->vertexNormal, NModel::VERTEX_SIZE_NORMAL, NOpenGL::FLOAT, NOpenGL::FALSE, stride, reinterpret_cast<float *>(sizeof(float) * NModel::VERTEX_PNTTC_OFFSET_NORMAL));
    }
    if(program.name >= NShader::PROGRAM_PER_FRAGMENT_NORMAL)
    {
      gl->enableVertexAttribArray(u->vertexNormalTangent);
      //gl->enableVertexAttribArray(u->vertexNormalBitangent);
      gl->vertexAttribPointer(u->vertexNormalTangent, NModel::VERTEX_SIZE_NORMAL_TANGENT, NOpenGL::FLOAT, NOpenGL::FALSE, stride, reinterpret_cast<float *>(sizeof(float) * NModel::VERTEX_PNTTC_OFFSET_NORMAL_TANGENT));
      //gl->vertexAttribPointer(u->vertexNormalBitangent, NModel::VERTEX_SIZE_NORMAL_BITANGENT, NOpenGL::FLOAT, NOpenGL::FALSE, stride, reinterpret_cast<float *>(sizeof(float) * NModel::VERTEX_PNTTC_OFFSET_NORMAL_BITANGENT));
    }
  }
  else if((program.name >= NShader::PROGRAM_LPV_INJECTION_GEOMETRY) && (program.name <= NShader::PROGRAM_LPV_PROPAGATION_GEOMETRY_SCATTERING))
  { // vbo attribs pack:   reserved float
    gl->enableVertexAttribArray(u->vertexPosition);
    gl->vertexAttribPointer(u->vertexPosition, NModel::VERTEX_SIZE_F, NOpenGL::FLOAT, NOpenGL::FALSE, sizeof(float) * NModel::VERTEX_F_SIZE, reinterpret_cast<float *>(sizeof(float) * NModel::VERTEX_F_OFFSET));
  }

  const SEngine *e = context->engineGetEngine();

  if(technique)
  {
    gl->uniformMatrix4fv(u->mw, 1, NOpenGL::FALSE, glm::value_ptr(technique->mw));
    gl->uniformMatrix3fv(u->mwnit, 1, NOpenGL::FALSE, glm::value_ptr(technique->mwnit));

    // mvp cascade variants
    if((program.name >= NShader::PROGRAM_DEPTH_CASCADE) || (program.name <= NShader::PROGRAM_DEPTH_CASCADE_COLOR_KEY))
      gl->uniformMatrix4fv(u->mvp, NEngine::SHADOW_CASCADES_COUNT, NOpenGL::FALSE, technique->mvps);
    else if(program.name == NShader::PROGRAM_GEOMETRY_CASCADE)
      gl->uniformMatrix4fv(u->mvp, NEngine::LPV_CASCADES_COUNT * NEngine::LPV_SUN_SKY_DIRS_COUNT, NOpenGL::FALSE, technique->mvpg);
    else
      gl->uniformMatrix4fv(u->mvp, 1, NOpenGL::FALSE, glm::value_ptr(technique->mvp));
    if(u->mvpsb != NShader::UNIFORM_UNDEFINED)
      gl->uniformMatrix4fv(u->mvpsb, NEngine::SHADOW_CASCADES_COUNT, NOpenGL::FALSE, technique->mvpsb);

    gl->uniform3f(u->cam, technique->cam.x, technique->cam.y, technique->cam.z);

    if(technique->material)
    {
      const SMaterial *m = technique->material;
      const bool lpvSwapIndex = (e->lpvPropagationSteps % 2) ? true : false;

      if((program.name == NShader::PROGRAM_BASIC_ALPHA) ||
         (program.name == NShader::PROGRAM_PER_FRAGMENT_ALPHA) ||
         (program.name == NShader::PROGRAM_PER_FRAGMENT_NORMAL_ALPHA))
        glEnable(NOpenGL::BLEND);

      // texture samplers
      if((program.name == NShader::PROGRAM_DEPTH_COLOR_KEY) || (program.name == NShader::PROGRAM_DEPTH_CASCADE_COLOR_KEY))
      {
        setSampler(m->diffuseMap, u->difTex, NShader::SAMPLER_DEPTH_COLOR_KEY_DIF, NMap::FORMAT_LINEAR);
      }
      else if(program.name == NShader::PROGRAM_BASIC)
      {
        setSampler(m->diffuseMap, u->difTex, NShader::SAMPLER_BASIC_DIF, ((m->type & NModel::MATERIAL_MIP_MAPPING) ? NMap::FORMAT_MIPMAP : NMap::FORMAT_LINEAR) | (mode == NRenderer::MODE_BACKDROP ? NMap::FORMAT_EDGE : NMap::FORMAT));
      }
      else if((program.name == NShader::PROGRAM_BASIC_ALPHA))
      {
        setSampler(m->diffuseMap, u->difTex, NShader::SAMPLER_BASIC_APLHA_DIF, m->type & NModel::MATERIAL_MIP_MAPPING ? NMap::FORMAT_MIPMAP : NMap::FORMAT_LINEAR);
        setSampler(m->alphaMap, u->alpTex, NShader::SAMPLER_BASIC_APLHA_ALP, m->type & NModel::MATERIAL_MIP_MAPPING ? NMap::FORMAT_MIPMAP : NMap::FORMAT_LINEAR);
      }
      else if((program.name >= NShader::PROGRAM_PER_FRAGMENT) && (program.name <= NShader::PROGRAM_PER_FRAGMENT_SHADOW_JITTER))
      {
        setSampler(m->diffuseMap, u->difTex, NShader::SAMPLER_PER_FRAGMENT_DIF, m->type & NModel::MATERIAL_MIP_MAPPING ? NMap::FORMAT_MIPMAP : NMap::FORMAT_LINEAR);
        setSampler(m->specularMap, u->speTex, NShader::SAMPLER_PER_FRAGMENT_SPE, m->type & NModel::MATERIAL_MIP_MAPPING ? NMap::FORMAT_MIPMAP : NMap::FORMAT_LINEAR);
        if(program.name != NShader::PROGRAM_PER_FRAGMENT)
          beginLPV(NShader::SAMPLER_PER_FRAGMENT_DEPTH, lpvSwapIndex);
      }
      else if((program.name >= NShader::PROGRAM_PER_FRAGMENT_ALPHA) && (program.name <= NShader::PROGRAM_PER_FRAGMENT_ALPHA_SHADOW_JITTER))
      {
        setSampler(m->diffuseMap, u->difTex, NShader::SAMPLER_PER_FRAGMENT_ALPHA_DIF, m->type & NModel::MATERIAL_MIP_MAPPING ? NMap::FORMAT_MIPMAP : NMap::FORMAT_LINEAR);
        setSampler(m->alphaMap, u->alpTex, NShader::SAMPLER_PER_FRAGMENT_ALPHA_ALP, m->type & NModel::MATERIAL_MIP_MAPPING ? NMap::FORMAT_MIPMAP : NMap::FORMAT_LINEAR);
        setSampler(m->specularMap, u->speTex, NShader::SAMPLER_PER_FRAGMENT_ALPHA_SPE, m->type & NModel::MATERIAL_MIP_MAPPING ? NMap::FORMAT_MIPMAP : NMap::FORMAT_LINEAR);
        if(program.name != NShader::PROGRAM_PER_FRAGMENT_ALPHA)
          beginLPV(NShader::SAMPLER_PER_FRAGMENT_ALPHA_DEPTH, lpvSwapIndex);
      }
      else if((program.name >= NShader::PROGRAM_PER_FRAGMENT_NORMAL) && (program.name <= NShader::PROGRAM_PER_FRAGMENT_NORMAL_SHADOW_JITTER))
      {
        setSampler(m->diffuseMap, u->difTex, NShader::SAMPLER_PER_FRAGMENT_NORMAL_DIF, m->type & NModel::MATERIAL_MIP_MAPPING ? NMap::FORMAT_MIPMAP : NMap::FORMAT_LINEAR);
        setSampler(m->specularMap, u->speTex, NShader::SAMPLER_PER_FRAGMENT_NORMAL_SPE, m->type & NModel::MATERIAL_MIP_MAPPING ? NMap::FORMAT_MIPMAP : NMap::FORMAT_LINEAR);
        setSampler(m->normalMap, u->norTex, NShader::SAMPLER_PER_FRAGMENT_NORMAL_NOR, m->type & NModel::MATERIAL_MIP_MAPPING ? NMap::FORMAT_MIPMAP : NMap::FORMAT_LINEAR);
        if(program.name != NShader::PROGRAM_PER_FRAGMENT_NORMAL)
          beginLPV(NShader::SAMPLER_PER_FRAGMENT_NORMAL_DEPTH, lpvSwapIndex);
      }
      else if((program.name >= NShader::PROGRAM_PER_FRAGMENT_NORMAL_ALPHA) && (program.name <= NShader::PROGRAM_PER_FRAGMENT_NORMAL_ALPHA_SHADOW_JITTER))
      {
        setSampler(m->diffuseMap, u->difTex, NShader::SAMPLER_PER_FRAGMENT_NORMAL_ALPHA_DIF, m->type & NModel::MATERIAL_MIP_MAPPING ? NMap::FORMAT_MIPMAP : NMap::FORMAT_LINEAR);
        setSampler(m->alphaMap, u->alpTex, NShader::SAMPLER_PER_FRAGMENT_NORMAL_ALPHA_ALP, m->type & NModel::MATERIAL_MIP_MAPPING ? NMap::FORMAT_MIPMAP : NMap::FORMAT_LINEAR);
        setSampler(m->specularMap, u->speTex, NShader::SAMPLER_PER_FRAGMENT_NORMAL_ALPHA_SPE, m->type & NModel::MATERIAL_MIP_MAPPING ? NMap::FORMAT_MIPMAP : NMap::FORMAT_LINEAR);
        setSampler(m->normalMap, u->norTex, NShader::SAMPLER_PER_FRAGMENT_NORMAL_ALPHA_NOR, m->type & NModel::MATERIAL_MIP_MAPPING ? NMap::FORMAT_MIPMAP : NMap::FORMAT_LINEAR);
        if(program.name != NShader::PROGRAM_PER_FRAGMENT_NORMAL_ALPHA)
          beginLPV(NShader::SAMPLER_PER_FRAGMENT_NORMAL_ALPHA_DEPTH, lpvSwapIndex);
      }
      else if((program.name >= NShader::PROGRAM_GEOMETRY) || (program.name <= NShader::PROGRAM_GEOMETRY_CASCADE))
      {
        setSampler(m->diffuseMap, u->difTex, NShader::SAMPLER_GEOMETRY_DIF, m->type & NModel::MATERIAL_MIP_MAPPING ? NMap::FORMAT_MIPMAP : NMap::FORMAT_LINEAR);
        setSampler(m->normalMap, u->norTex, NShader::SAMPLER_GEOMETRY_NOR, m->type & NModel::MATERIAL_MIP_MAPPING ? NMap::FORMAT_MIPMAP : NMap::FORMAT_LINEAR);
      }

      // other material params
      gl->uniform1i(u->type, m->type);
      gl->uniform1f(u->opacity, m->opacity);

      context->getMaps()->finishBind();
    }

    // picking color
    if(program.name == NShader::PROGRAM_COLOR)
      gl->uniform3f(u->lightAmb, technique->pickColor.x, technique->pickColor.y, technique->pickColor.z);

    if((program.name >= NShader::PROGRAM_PER_FRAGMENT) && (program.name <= NShader::PROGRAM_PER_FRAGMENT_NORMAL_ALPHA_SHADOW_JITTER))
    {
      const SCamera *cam = context->getCamera()->getCamera();

      gl->uniform3f(u->shadowTexSize, 0.5f / static_cast<float>(e->shadowTextureSize), 0.5f / static_cast<float>(e->shadowTextureSize), context->engineGetEngine()->shadowJittering);

      if((program.name >= NShader::PROGRAM_GEOMETRY) || (program.name <= NShader::PROGRAM_GEOMETRY_CASCADE))
      {
        // global illumination colors - sun + sky
        gl->uniform3fv(u->lightAmb, NEngine::LPV_SUN_SKY_DIRS_COUNT, e->sunSkyColors);
        gl->uniform3fv(u->lightPos, NEngine::LPV_SUN_SKY_DIRS_COUNT, e->sunSkyPoses);
      }
      else
      {
        gl->uniform3f(u->lightAmb, technique->lightAmb.x, technique->lightAmb.y, technique->lightAmb.z);
        gl->uniform3f(u->lightPos, technique->lights[0].pos.x, technique->lights[0].pos.y, technique->lights[0].pos.z);
      }
      gl->uniform2f(u->lightRange, technique->lights[0].range.x, technique->lights[0].range.y);
      gl->uniform3f(u->lightColor, technique->lights[0].color.x, technique->lights[0].color.y, technique->lights[0].color.z);
      gl->uniform4f(u->lightSpeColor, technique->lights[0].speColor.x, technique->lights[0].speColor.y, technique->lights[0].speColor.z, technique->lights[0].speColor.w);
      gl->uniform2f(u->fogRange, technique->fogRange.x * cam->clipFar, technique->fogRange.y * cam->clipFar);
      gl->uniform3f(u->fogColor, technique->fogColor.x, technique->fogColor.y, technique->fogColor.z);
    }
  }

  if((program.name >= NShader::PROGRAM_PER_FRAGMENT) && (program.name != NShader::PROGRAM_GEOMETRY) && (program.name != NShader::PROGRAM_GEOMETRY_CASCADE))
  {
    const glm::vec3 lpvCellSize(1.0f / e->lpvCellSize / e->lpvTextureSize);
    const glm::vec3 lpvPos(e->lpvCellSize * e->lpvTextureSize * 0.5f - e->lpvPos);

    gl->uniform4f(u->geomTexSize, e->geometryTextureSize, e->geometryTextureSize, 1.0f / static_cast<float>(e->geometryTextureSize), 1.0f / static_cast<float>(e->geometryTextureSize));
    gl->uniform4f(u->lpvPos, lpvPos.x, lpvPos.y, lpvPos.z, e->lpvIntensity * e->showLPV);
    gl->uniform3f(u->lpvSize, e->lpvTextureSize.x, e->lpvTextureSize.y, e->lpvTextureSize.z);
    gl->uniform3f(u->lpvCellSize, lpvCellSize.x, lpvCellSize.y, lpvCellSize.z);
  }

  if((program.name == NShader::PROGRAM_LPV_INJECTION) || (program.name == NShader::PROGRAM_LPV_INJECTION_COMPUTE))
  {
    fragColor = context->getMaps()->getMap(NWindow::STR_ORTHO_GEOMETRY_FBO_AMB_MAP);
    fragPos = context->getMaps()->getMap(NWindow::STR_ORTHO_GEOMETRY_FBO_POS_MAP);
    fragNormal = context->getMaps()->getMap(NWindow::STR_ORTHO_GEOMETRY_FBO_NORMAL_MAP);
    //fragDepth = context->getMaps()->getMap(NWindow::STR_ORTHO_GEOMETRY_FBO_DEPTH_MAP);
    fboGeoCam = context->getFramebuffers()->getFramebuffer(NWindow::STR_ORTHO_GEOMETRY_FBO)->getFrameBuffer()->camera.position;

    gl->uniform3f(u->lightPos, fboGeoCam.x, fboGeoCam.y, fboGeoCam.z);
  }
  if((program.name == NShader::PROGRAM_LPV_CLEAR_COMPUTE) || (program.name == NShader::PROGRAM_LPV_INJECTION_COMPUTE) || (program.name == NShader::PROGRAM_LPV_PROPAGATION_COMPUTE))
  {
    lpv0MapR = context->getMaps()->getMap(NWindow::STR_LPV0_MAP_R);
    lpv0MapG = context->getMaps()->getMap(NWindow::STR_LPV0_MAP_G);
    lpv0MapB = context->getMaps()->getMap(NWindow::STR_LPV0_MAP_B);
    lpv1MapR = context->getMaps()->getMap(NWindow::STR_LPV1_MAP_R);
    lpv1MapG = context->getMaps()->getMap(NWindow::STR_LPV1_MAP_G);
    lpv1MapB = context->getMaps()->getMap(NWindow::STR_LPV1_MAP_B);
    gvMap = context->getMaps()->getMap(NWindow::STR_GV0_MAP);
  }

  if(program.name == NShader::PROGRAM_LPV_INJECTION)
  {
    setSampler(fragColor, u->fragColorImg, NShader::SAMPLER_LPV_INJECTION_FRAG_COLOR, NMap::FORMAT_BORDER);
    setSampler(fragPos, u->fragPosImg, NShader::SAMPLER_LPV_INJECTION_FRAG_POS, NMap::FORMAT_BORDER);
    setSampler(fragNormal, u->fragNormalImg, NShader::SAMPLER_LPV_INJECTION_FRAG_NORMAL, NMap::FORMAT_BORDER);
    //setSampler(fragDepth, u->fragDepthImg, NShader::SAMPLER_LPV_INJECTION_FRAG_DEPTH, NMap::FORMAT_BORDER);
  }
  else if(program.name == NShader::PROGRAM_LPV_PROPAGATION)
  {
    //
  }
  else if(program.name == NShader::PROGRAM_LPV_CLEAR_COMPUTE)
  {
    setSampler(lpv0MapR, u->lpv0ImgR, NShader::IMAGE_LPV_CLEAR_COMPUTE_LPV0_R, NMap::FORMAT_IMAGE_W);
    setSampler(lpv0MapG, u->lpv0ImgG, NShader::IMAGE_LPV_CLEAR_COMPUTE_LPV0_G, NMap::FORMAT_IMAGE_W);
    setSampler(lpv0MapB, u->lpv0ImgB, NShader::IMAGE_LPV_CLEAR_COMPUTE_LPV0_B, NMap::FORMAT_IMAGE_W);
    setSampler(lpv1MapR, u->lpv1ImgR, NShader::IMAGE_LPV_CLEAR_COMPUTE_LPV1_R, NMap::FORMAT_IMAGE_W);
    setSampler(lpv1MapG, u->lpv1ImgG, NShader::IMAGE_LPV_CLEAR_COMPUTE_LPV1_G, NMap::FORMAT_IMAGE_W);
    setSampler(lpv1MapB, u->lpv1ImgB, NShader::IMAGE_LPV_CLEAR_COMPUTE_LPV1_B, NMap::FORMAT_IMAGE_W);
    setSampler(gvMap, u->gvImg, NShader::IMAGE_LPV_CLEAR_COMPUTE_GV, NMap::FORMAT_IMAGE_W);
  }
  else if(program.name == NShader::PROGRAM_LPV_INJECTION_COMPUTE)
  {
    setSampler(fragColor, u->fragColorImg, NShader::IMAGE_LPV_INJECTION_COMPUTE_FRAG_COLOR, NMap::FORMAT_IMAGE_R);
    setSampler(fragPos, u->fragPosImg, NShader::IMAGE_LPV_INJECTION_COMPUTE_FRAG_POS, NMap::FORMAT_IMAGE_R);
    setSampler(fragNormal, u->fragNormalImg, NShader::IMAGE_LPV_INJECTION_COMPUTE_FRAG_NORMAL, NMap::FORMAT_IMAGE_R);
    //setSampler(fragDepth, u->fragDepthImg, NShader::IMAGE_LPV_INJECTION_COMPUTE_FRAG_DEPTH, NMap::FORMAT_IMAGE_R);
    setSampler(lpv0MapR, u->lpv0ImgR, NShader::IMAGE_LPV_INJECTION_COMPUTE_LPV0_R, NMap::FORMAT_IMAGE_RW);
    setSampler(lpv0MapG, u->lpv0ImgG, NShader::IMAGE_LPV_INJECTION_COMPUTE_LPV0_G, NMap::FORMAT_IMAGE_RW);
    setSampler(lpv0MapB, u->lpv0ImgB, NShader::IMAGE_LPV_INJECTION_COMPUTE_LPV0_B, NMap::FORMAT_IMAGE_RW);
    setSampler(gvMap, u->gvImg, NShader::IMAGE_LPV_INJECTION_COMPUTE_GV, NMap::FORMAT_IMAGE_RW);
  }
  else if(program.name == NShader::PROGRAM_LPV_PROPAGATION_COMPUTE)
  {
    setSampler(lpv0MapR, u->lpv0ImgR, NShader::IMAGE_LPV_PROPAGATION_COMPUTE_LPV0_R, NMap::FORMAT_IMAGE_RW);
    setSampler(lpv0MapG, u->lpv0ImgG, NShader::IMAGE_LPV_PROPAGATION_COMPUTE_LPV0_G, NMap::FORMAT_IMAGE_RW);
    setSampler(lpv0MapB, u->lpv0ImgB, NShader::IMAGE_LPV_PROPAGATION_COMPUTE_LPV0_B, NMap::FORMAT_IMAGE_RW);
    setSampler(lpv1MapR, u->lpv1ImgR, NShader::IMAGE_LPV_PROPAGATION_COMPUTE_LPV1_R, NMap::FORMAT_IMAGE_RW);
    setSampler(lpv1MapG, u->lpv1ImgG, NShader::IMAGE_LPV_PROPAGATION_COMPUTE_LPV1_G, NMap::FORMAT_IMAGE_RW);
    setSampler(lpv1MapB, u->lpv1ImgB, NShader::IMAGE_LPV_PROPAGATION_COMPUTE_LPV1_B, NMap::FORMAT_IMAGE_RW);
    setSampler(gvMap, u->gvImg, NShader::IMAGE_LPV_PROPAGATION_COMPUTE_GV, NMap::FORMAT_IMAGE_RW);
    setSampler(lpvMapR, u->lpvOutImgR, NShader::IMAGE_LPV_INJECTION_COMPUTE_LPV_OUT_R, NMap::FORMAT_IMAGE_W);
    setSampler(lpvMapG, u->lpvOutImgG, NShader::IMAGE_LPV_INJECTION_COMPUTE_LPV_OUT_G, NMap::FORMAT_IMAGE_W);
    setSampler(lpvMapB, u->lpvOutImgB, NShader::IMAGE_LPV_INJECTION_COMPUTE_LPV_OUT_B, NMap::FORMAT_IMAGE_W);
  }
}
//------------------------------------------------------------------------------
void CShaderProgram::end(const SShaderTechnique *technique) const
{
  COpenGL *gl = context->getOpenGL();
  const SShaderUniforms *u = &program.uniforms;

  if((technique) && (technique->material))
  {
    if((program.name == NShader::PROGRAM_BASIC_ALPHA) ||
       (program.name == NShader::PROGRAM_PER_FRAGMENT_ALPHA) ||
       (program.name == NShader::PROGRAM_PER_FRAGMENT_NORMAL_ALPHA))
      glDisable(NOpenGL::BLEND);
  }

  if(program.name <= NShader::PROGRAM_DEPTH_CASCADE_COLOR_KEY)
  { // vbo attribs pack:   pos, tex
    if(program.name >= NShader::PROGRAM_COLOR)
      gl->disableVertexAttribArray(u->vertexPosition);
    if((program.name == NShader::PROGRAM_DEPTH_COLOR_KEY) || (program.name == NShader::PROGRAM_DEPTH_CASCADE_COLOR_KEY))
      gl->disableVertexAttribArray(u->vertexTexCoord);
  }
  else if(program.name <= NShader::PROGRAM_GEOMETRY_CASCADE)
  { // vbo attribs pack:   pos, nor, tan, tex, col
    if(program.name >= NShader::PROGRAM_BASIC)
    {
      gl->disableVertexAttribArray(u->vertexPosition);
      gl->disableVertexAttribArray(u->vertexTexCoord);
      gl->disableVertexAttribArray(u->vertexColor);
    }
    if(program.name >= NShader::PROGRAM_PER_FRAGMENT)
      gl->disableVertexAttribArray(u->vertexNormal);
    if(program.name >= NShader::PROGRAM_PER_FRAGMENT_NORMAL)
    {
      gl->disableVertexAttribArray(u->vertexNormalTangent);
      //gl->disableVertexAttribArray(u->vertexNormalBitangent);
    }
  }
  else if((program.name >= NShader::PROGRAM_LPV_INJECTION_GEOMETRY) && (program.name <= NShader::PROGRAM_LPV_PROPAGATION_GEOMETRY_SCATTERING))
  { // vbo attribs pack:   reserved float
    gl->disableVertexAttribArray(u->vertexPosition);
  }

  if(program.name == NShader::PROGRAM_LPV_CLEAR_COMPUTE)
  {
    setSampler(NULL, u->lpv0ImgR, NShader::IMAGE_LPV_CLEAR_COMPUTE_LPV0_R, NMap::FORMAT_IMAGE_W);
    setSampler(NULL, u->lpv0ImgG, NShader::IMAGE_LPV_CLEAR_COMPUTE_LPV0_G, NMap::FORMAT_IMAGE_W);
    setSampler(NULL, u->lpv0ImgB, NShader::IMAGE_LPV_CLEAR_COMPUTE_LPV0_B, NMap::FORMAT_IMAGE_W);
    setSampler(NULL, u->lpv1ImgR, NShader::IMAGE_LPV_CLEAR_COMPUTE_LPV1_R, NMap::FORMAT_IMAGE_W);
    setSampler(NULL, u->lpv1ImgG, NShader::IMAGE_LPV_CLEAR_COMPUTE_LPV1_G, NMap::FORMAT_IMAGE_W);
    setSampler(NULL, u->lpv1ImgB, NShader::IMAGE_LPV_CLEAR_COMPUTE_LPV1_B, NMap::FORMAT_IMAGE_W);
    setSampler(NULL, u->gvImg, NShader::IMAGE_LPV_CLEAR_COMPUTE_GV, NMap::FORMAT_IMAGE_W);
  }
  else if(program.name == NShader::PROGRAM_LPV_INJECTION_COMPUTE)
  {
    setSampler(NULL, u->fragColorImg, NShader::IMAGE_LPV_INJECTION_COMPUTE_FRAG_COLOR, NMap::FORMAT_IMAGE_R);
    setSampler(NULL, u->fragPosImg, NShader::IMAGE_LPV_INJECTION_COMPUTE_FRAG_POS, NMap::FORMAT_IMAGE_R);
    setSampler(NULL, u->fragNormalImg, NShader::IMAGE_LPV_INJECTION_COMPUTE_FRAG_NORMAL, NMap::FORMAT_IMAGE_R);
    //setSampler(NULL, u->fragDepthImg, NShader::IMAGE_LPV_INJECTION_COMPUTE_FRAG_DEPTH, NMap::FORMAT_IMAGE_R);
    setSampler(NULL, u->lpv0ImgR, NShader::IMAGE_LPV_INJECTION_COMPUTE_LPV0_R, NMap::FORMAT_IMAGE_RW);
    setSampler(NULL, u->lpv0ImgG, NShader::IMAGE_LPV_INJECTION_COMPUTE_LPV0_G, NMap::FORMAT_IMAGE_RW);
    setSampler(NULL, u->lpv0ImgB, NShader::IMAGE_LPV_INJECTION_COMPUTE_LPV0_B, NMap::FORMAT_IMAGE_RW);
    setSampler(NULL, u->gvImg, NShader::IMAGE_LPV_INJECTION_COMPUTE_GV, NMap::FORMAT_IMAGE_RW);
  }
  else if(program.name == NShader::PROGRAM_LPV_PROPAGATION_COMPUTE)
  {
    setSampler(NULL, u->lpv0ImgR, NShader::IMAGE_LPV_PROPAGATION_COMPUTE_LPV0_R, NMap::FORMAT_IMAGE_RW);
    setSampler(NULL, u->lpv0ImgG, NShader::IMAGE_LPV_PROPAGATION_COMPUTE_LPV0_G, NMap::FORMAT_IMAGE_RW);
    setSampler(NULL, u->lpv0ImgB, NShader::IMAGE_LPV_PROPAGATION_COMPUTE_LPV0_B, NMap::FORMAT_IMAGE_RW);
    setSampler(NULL, u->lpv1ImgR, NShader::IMAGE_LPV_PROPAGATION_COMPUTE_LPV1_R, NMap::FORMAT_IMAGE_RW);
    setSampler(NULL, u->lpv1ImgG, NShader::IMAGE_LPV_PROPAGATION_COMPUTE_LPV1_G, NMap::FORMAT_IMAGE_RW);
    setSampler(NULL, u->lpv1ImgB, NShader::IMAGE_LPV_PROPAGATION_COMPUTE_LPV1_B, NMap::FORMAT_IMAGE_RW);
    setSampler(NULL, u->gvImg, NShader::IMAGE_LPV_PROPAGATION_COMPUTE_GV, NMap::FORMAT_IMAGE_RW);
    setSampler(NULL, u->lpvOutImgR, NShader::IMAGE_LPV_INJECTION_COMPUTE_LPV_OUT_R, NMap::FORMAT_IMAGE_W);
    setSampler(NULL, u->lpvOutImgG, NShader::IMAGE_LPV_INJECTION_COMPUTE_LPV_OUT_G, NMap::FORMAT_IMAGE_W);
    setSampler(NULL, u->lpvOutImgB, NShader::IMAGE_LPV_INJECTION_COMPUTE_LPV_OUT_B, NMap::FORMAT_IMAGE_W);
  }
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
