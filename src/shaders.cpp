//------------------------------------------------------------------------------
#include "shaders.h"

//------------------------------------------------------------------------------
CShader::CShader() : CEngineBase()
{
}
//------------------------------------------------------------------------------
CShader::CShader(CContext *context, const SShader &shader) : CEngineBase(context), shader(shader)
{
  compile();
}
//------------------------------------------------------------------------------
CShader::~CShader()
{
}
//------------------------------------------------------------------------------
void CShader::compile()
{
  //COpenGL *gl = context->getOpenGL();
  GLenum shaderType = (shader.type == NShader::TYPE_VERTEX) ? GL_VERTEX_SHADER : GL_FRAGMENT_SHADER;
  GLint status = 0;
  GLint infoLength = 0;
  std::string log;
  CFile *f = context->getFilesystem()->open(SFile(shader.file));

  if(!f)
    return;

  std::string data(f->size(), ' ');
  f->read(&data[0], data.length());

#ifdef QT_OPENGL_ES_2
  data = setES2compatible(data);
#endif

  const char *d = data.c_str();

  //qDebug(d);
  shader.shader = glCreateShader(shaderType);
  glShaderSource(shader.shader, 1, &d, NULL);
  glCompileShader(shader.shader);
  glGetShaderiv(shader.shader, GL_COMPILE_STATUS, &status);
  glGetShaderiv(shader.shader, GL_INFO_LOG_LENGTH, &infoLength);

  log.resize(infoLength);
  if(infoLength)
    glGetShaderInfoLog(shader.shader, infoLength, &infoLength, &log[0]);
  if(&log[0])
    context->log(log);

  if(status == GL_FALSE)
    context->engineShowMessage(CStr(NShader::STR_ERROR_COMPILE, shader.file.c_str()), &log[0], false);

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
    d = CStr::replaceAll(d, "glFragColor", "gl_FragColor");
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
  link();
  initUniforms();
}
//------------------------------------------------------------------------------
CShaderProgram::~CShaderProgram()
{
}
//------------------------------------------------------------------------------
void CShaderProgram::link()
{
  //COpenGL *gl = context->getOpenGL();
  GLint status = 0;
  GLint infoLength = 0;
  std::string log;

  program.program = glCreateProgram();
  glAttachShader(program.program, program.vertexShader->getShader()->shader);
  glAttachShader(program.program, program.fragmentShader->getShader()->shader);
  glLinkProgram(program.program);

  glGetProgramiv(program.program, GL_LINK_STATUS, &status);
  glGetProgramiv(program.program, GL_INFO_LOG_LENGTH, &infoLength);
  log.resize(infoLength);
  if(infoLength)
    glGetProgramInfoLog(program.program, infoLength, &infoLength, &log[0]);
#ifndef Q_OS_SYMBIAN
  if(&log[0])
    context->log(log);
#endif
  if(status == GL_FALSE)
  {
#ifdef Q_OS_SYMBIAN
    if(&log[0])
      qDebug(&log[0]);
#endif
    context->engineShowMessage(CStr(NShader::STR_ERROR_LINK, NShader::STR_SHADERS_LIST[program.name]), &log[0], false);
  }
}
//------------------------------------------------------------------------------
void CShaderProgram::initUniforms()
{
  //COpenGL *gl = context->getOpenGL();

  program.uniforms.vertexPosition = glGetAttribLocation(program.program, NShader::STR_SHADER_UNIFORM_VERTEX_POSITION);
  program.uniforms.vertexNormal = glGetAttribLocation(program.program, NShader::STR_SHADER_UNIFORM_VERTEX_NORMAL);
  program.uniforms.vertexNormalTangent = glGetAttribLocation(program.program, NShader::STR_SHADER_UNIFORM_VERTEX_NORMAL_TANGENT);
  program.uniforms.vertexNormalBitangent = glGetAttribLocation(program.program, NShader::STR_SHADER_UNIFORM_VERTEX_NORMAL_BITANGENT);
  program.uniforms.vertexTexCoord = glGetAttribLocation(program.program, NShader::STR_SHADER_UNIFORM_VERTEX_TEX_COORD);
  program.uniforms.vertexColor = glGetAttribLocation(program.program, NShader::STR_SHADER_UNIFORM_VERTEX_COLOR);
  program.uniforms.mw = glGetUniformLocation(program.program, NShader::STR_SHADER_UNIFORM_MW);
  program.uniforms.mwnit = glGetUniformLocation(program.program, NShader::STR_SHADER_UNIFORM_MWNIT);
  program.uniforms.mvp = glGetUniformLocation(program.program, NShader::STR_SHADER_UNIFORM_MVP);
  program.uniforms.cam = glGetUniformLocation(program.program, NShader::STR_SHADER_UNIFORM_CAM);
  program.uniforms.difTex = glGetUniformLocation(program.program, NShader::STR_SHADER_UNIFORM_DIF_TEX);
  program.uniforms.alpTex = glGetUniformLocation(program.program, NShader::STR_SHADER_UNIFORM_ALP_TEX);
  program.uniforms.speTex = glGetUniformLocation(program.program, NShader::STR_SHADER_UNIFORM_SPE_TEX);
  program.uniforms.norTex = glGetUniformLocation(program.program, NShader::STR_SHADER_UNIFORM_NOR_TEX);
  program.uniforms.bumTex = glGetUniformLocation(program.program, NShader::STR_SHADER_UNIFORM_BUM_TEX);
  program.uniforms.envTex = glGetUniformLocation(program.program, NShader::STR_SHADER_UNIFORM_ENV_TEX);
  program.uniforms.opacity = glGetUniformLocation(program.program, NShader::STR_SHADER_UNIFORM_OPACITY);
  program.uniforms.lightAmb = glGetUniformLocation(program.program, NShader::STR_SHADER_UNIFORM_LIGHT_AMB);
  program.uniforms.lightPos = glGetUniformLocation(program.program, NShader::STR_SHADER_UNIFORM_LIGHT_POS);
  program.uniforms.lightRange = glGetUniformLocation(program.program, NShader::STR_SHADER_UNIFORM_LIGHT_RANGE);
  program.uniforms.lightColor = glGetUniformLocation(program.program, NShader::STR_SHADER_UNIFORM_LIGHT_COLOR);
  program.uniforms.lightSpeColor = glGetUniformLocation(program.program, NShader::STR_SHADER_UNIFORM_LIGHT_SPEC_COLOR);
  program.uniforms.fogRange = glGetUniformLocation(program.program, NShader::STR_SHADER_UNIFORM_FOG_RANGE);
  program.uniforms.fogColor = glGetUniformLocation(program.program, NShader::STR_SHADER_UNIFORM_FOG_COLOR);
}
//------------------------------------------------------------------------------
void CShaderProgram::bind() const
{
  /*context->getOpenGL()->*/glUseProgram(program.program);
}
//------------------------------------------------------------------------------
void CShaderProgram::begin(const SShaderTechnique *technique) const
{
  //COpenGL *gl = context->getOpenGL();

  glEnableVertexAttribArray(program.uniforms.vertexPosition);
  glEnableVertexAttribArray(program.uniforms.vertexNormal);
  glEnableVertexAttribArray(program.uniforms.vertexNormalTangent);
  glEnableVertexAttribArray(program.uniforms.vertexNormalBitangent);
  glEnableVertexAttribArray(program.uniforms.vertexTexCoord);
  glEnableVertexAttribArray(program.uniforms.vertexColor);
  glVertexAttribPointer(program.uniforms.vertexPosition, 3, GL_FLOAT, GL_FALSE, sizeof(float) * NModel::VERTEX_PNTBTC_SIZE, reinterpret_cast<float *>(sizeof(float) * NModel::VBO_OFFSET_POSITION));
  glVertexAttribPointer(program.uniforms.vertexNormal, 3, GL_FLOAT, GL_FALSE, sizeof(float) * NModel::VERTEX_PNTBTC_SIZE, reinterpret_cast<float *>(sizeof(float) * NModel::VBO_OFFSET_NORMAL));
  glVertexAttribPointer(program.uniforms.vertexNormalTangent, 3, GL_FLOAT, GL_FALSE, sizeof(float) * NModel::VERTEX_PNTBTC_SIZE, reinterpret_cast<float *>(sizeof(float) * NModel::VBO_OFFSET_NORMAL_TANGENT));
  glVertexAttribPointer(program.uniforms.vertexNormalBitangent, 3, GL_FLOAT, GL_FALSE, sizeof(float) * NModel::VERTEX_PNTBTC_SIZE, reinterpret_cast<float *>(sizeof(float) * NModel::VBO_OFFSET_NORMAL_BITANGENT));
  glVertexAttribPointer(program.uniforms.vertexTexCoord, 2, GL_FLOAT, GL_FALSE, sizeof(float) * NModel::VERTEX_PNTBTC_SIZE, reinterpret_cast<float *>(sizeof(float) * NModel::VBO_OFFSET_TEX_COORD));
  glVertexAttribPointer(program.uniforms.vertexColor, 3, GL_FLOAT, GL_FALSE, sizeof(float) * NModel::VERTEX_PNTBTC_SIZE, reinterpret_cast<float *>(sizeof(float) * NModel::VBO_OFFSET_COLOR));

  if(!technique)
    return;

  glUniformMatrix4fv(program.uniforms.mw, 1, GL_FALSE, glm::value_ptr(technique->mw));
  glUniformMatrix4fv(program.uniforms.mwnit, 1, GL_FALSE, glm::value_ptr(technique->mwnit));
  glUniformMatrix4fv(program.uniforms.mvp, 1, GL_FALSE, glm::value_ptr(technique->mvp));
  glUniform3f(program.uniforms.cam, technique->cam.x, technique->cam.y, technique->cam.z);

  if(technique->material)
  {
    const SMaterial *m = technique->material;

    if((program.name == NShader::PROGRAM_BASIC_ALPHA) ||
       (program.name == NShader::PROGRAM_PER_FRAGMENT_ALPHA) ||
       (program.name == NShader::PROGRAM_PER_FRAGMENT_NORMAL_ALPHA))
      glEnable(GL_BLEND);

    if(program.name == NShader::PROGRAM_BASIC)
    {
      setSampler(m->diffuseMap, program.uniforms.difTex, NShader::SAMPLER_BASIC_DIF, m->type & NModel::MATERIAL_MIP_MAPPING);
    }
    else if((program.name == NShader::PROGRAM_BASIC_ALPHA))
    {
      setSampler(m->diffuseMap, program.uniforms.difTex, NShader::SAMPLER_BASIC_APLHA_DIF, m->type & NModel::MATERIAL_MIP_MAPPING);
      setSampler(m->alphaMap, program.uniforms.alpTex, NShader::SAMPLER_BASIC_APLHA_ALP, m->type & NModel::MATERIAL_MIP_MAPPING);
    }
    else if(program.name == NShader::PROGRAM_PER_FRAGMENT)
    {
      setSampler(m->diffuseMap, program.uniforms.difTex, NShader::SAMPLER_PER_FRAGMENT_DIF, m->type & NModel::MATERIAL_MIP_MAPPING);
      setSampler(m->specularMap, program.uniforms.speTex, NShader::SAMPLER_PER_FRAGMENT_SPE, m->type & NModel::MATERIAL_MIP_MAPPING);
    }
    else if(program.name == NShader::PROGRAM_PER_FRAGMENT_ALPHA)
    {
      setSampler(m->diffuseMap, program.uniforms.difTex, NShader::SAMPLER_PER_FRAGMENT_ALPHA_DIF, m->type & NModel::MATERIAL_MIP_MAPPING);
      setSampler(m->alphaMap, program.uniforms.alpTex, NShader::SAMPLER_PER_FRAGMENT_ALPHA_ALP, m->type & NModel::MATERIAL_MIP_MAPPING);
      setSampler(m->specularMap, program.uniforms.speTex, NShader::SAMPLER_PER_FRAGMENT_ALPHA_SPE, m->type & NModel::MATERIAL_MIP_MAPPING);
    }
    else if(program.name == NShader::PROGRAM_PER_FRAGMENT_NORMAL)
    {
      setSampler(m->diffuseMap, program.uniforms.difTex, NShader::SAMPLER_PER_FRAGMENT_NORMAL_DIF, m->type & NModel::MATERIAL_MIP_MAPPING);
      setSampler(m->specularMap, program.uniforms.speTex, NShader::SAMPLER_PER_FRAGMENT_NORMAL_SPE, m->type & NModel::MATERIAL_MIP_MAPPING);
      setSampler(m->normalMap, program.uniforms.norTex, NShader::SAMPLER_PER_FRAGMENT_NORMAL_NOR, m->type & NModel::MATERIAL_MIP_MAPPING);
    }
    else if(program.name == NShader::PROGRAM_PER_FRAGMENT_NORMAL_ALPHA)
    {
      setSampler(m->diffuseMap, program.uniforms.difTex, NShader::SAMPLER_PER_FRAGMENT_NORMAL_ALPHA_DIF, m->type & NModel::MATERIAL_MIP_MAPPING);
      setSampler(m->alphaMap, program.uniforms.alpTex, NShader::SAMPLER_PER_FRAGMENT_NORMAL_ALPHA_ALP, m->type & NModel::MATERIAL_MIP_MAPPING);
      setSampler(m->specularMap, program.uniforms.speTex, NShader::SAMPLER_PER_FRAGMENT_NORMAL_ALPHA_SPE, m->type & NModel::MATERIAL_MIP_MAPPING);
      setSampler(m->normalMap, program.uniforms.norTex, NShader::SAMPLER_PER_FRAGMENT_NORMAL_ALPHA_NOR, m->type & NModel::MATERIAL_MIP_MAPPING);
    }

    glUniform1f(program.uniforms.opacity, m->opacity);
    context->getMaps()->finishBind();
  }

  const SCamera *cam = context->getCamera()->getCamera();
  if(program.name == NShader::PROGRAM_COLOR)
    glUniform3f(program.uniforms.lightAmb, technique->pickColor.x, technique->pickColor.y, technique->pickColor.z);
  else
    glUniform3f(program.uniforms.lightAmb, technique->lightAmb.x, technique->lightAmb.y, technique->lightAmb.z);
  glUniform3f(program.uniforms.lightPos, technique->lightPos.x, technique->lightPos.y, technique->lightPos.z);
  glUniform2f(program.uniforms.lightRange, technique->lightRange.x, technique->lightRange.y);
  glUniform3f(program.uniforms.lightColor, technique->lightColor.x, technique->lightColor.y, technique->lightColor.z);
  glUniform4f(program.uniforms.lightSpeColor, technique->lightSpeColor.x, technique->lightSpeColor.y, technique->lightSpeColor.z, technique->lightSpeColor.w);
  glUniform2f(program.uniforms.fogRange, technique->fogRange.x * cam->clipFar, technique->fogRange.y * cam->clipFar);
  glUniform3f(program.uniforms.fogColor, technique->fogColor.x, technique->fogColor.y, technique->fogColor.z);
}
//------------------------------------------------------------------------------
void CShaderProgram::end(const SShaderTechnique *technique) const
{
  //COpenGL *gl = context->getOpenGL();

  if((technique) && (technique->material))
  {
    if((program.name == NShader::PROGRAM_BASIC_ALPHA) ||
       (program.name == NShader::PROGRAM_PER_FRAGMENT_ALPHA) ||
       (program.name == NShader::PROGRAM_PER_FRAGMENT_NORMAL_ALPHA))
      glDisable(GL_BLEND);
  }

  glDisableVertexAttribArray(program.uniforms.vertexPosition);
  glDisableVertexAttribArray(program.uniforms.vertexNormal);
  glDisableVertexAttribArray(program.uniforms.vertexNormalTangent);
  glDisableVertexAttribArray(program.uniforms.vertexNormalBitangent);
  glDisableVertexAttribArray(program.uniforms.vertexTexCoord);
  glDisableVertexAttribArray(program.uniforms.vertexColor);
}
//------------------------------------------------------------------------------
void CShaderProgram::unbind() const
{
  /*context->getOpenGL()->*/glUseProgram(0);
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
