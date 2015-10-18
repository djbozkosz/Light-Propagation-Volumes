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
  COpenGL *gl = context->getOpenGL();
  GLenum shaderType = (shader.type == NShader::TYPE_VERTEX) ? GL_VERTEX_SHADER : GL_FRAGMENT_SHADER;
  GLint status = 0;
  GLint infoLength = 0;
  std::string log;
  QFile f(shader.file);

  if(!f.open(QIODevice::ReadOnly))
    return;

  QString data = f.readAll().constData();
#ifdef QT_OPENGL_ES_2
  data = setES2compatible(data);
#endif

  QByteArray ba = data.toLatin1();
  const char *d = ba.data();

  //qDebug(d);
  shader.shader = gl->glCreateShader(shaderType);
  gl->glShaderSource(shader.shader, 1, &d, NULL);
  gl->glCompileShader(shader.shader);
  gl->glGetShaderiv(shader.shader, GL_COMPILE_STATUS, &status);
  gl->glGetShaderiv(shader.shader, GL_INFO_LOG_LENGTH, &infoLength);
  log.resize(infoLength);
  if(infoLength)
    gl->glGetShaderInfoLog(shader.shader, infoLength, &infoLength, &log[0]);
  if(&log[0])
    qDebug(&log[0]);
  if(status == GL_FALSE)
  {
    QMessageBox *msg = new QMessageBox();
    msg->setWindowTitle("Shader Compilation Error: "+shader.file);
    msg->setText(&log[0]);
    msg->setStandardButtons(QMessageBox::Ok);
    msg->setDefaultButton(QMessageBox::Ok);
    msg->setModal(false);
    msg->show();
  }

  /*QMessageBox *msg = new QMessageBox();
  msg->setWindowTitle("Shader");
  msg->setText(data);
  msg->setStandardButtons(QMessageBox::Ok);
  msg->setDefaultButton(QMessageBox::Ok);
  msg->setModal(false);
  msg->show();*/

  f.close();
}
//------------------------------------------------------------------------------
QString CShader::setES2compatible(const QString &data)
{
  QString d = data;
#ifndef Q_OS_ANDROID
  QString precision("lowp");
#else
  QString precision("highp");
#endif

  // replace any version and precision by #version 100 - ES 2.0
  int32 index = d.indexOf("in ");
  if(index == -1)
    index = d.indexOf("uniform ");
  if(index == -1)
    index = d.indexOf("out ");
  d.remove(0, index);
  d.push_front("#version 100\r\n\r\n");

  if(shader.type == NShader::TYPE_VERTEX)
  {
    d.replace("in ", "attribute ");
    d.replace("out ", "varying ");
  }
  else if(shader.type == NShader::TYPE_FRAGMENT)
  {
    d.replace("in ", "varying ");
    d.replace("out vec4 glFragColor;", "");
    d.replace("glFragColor", "gl_FragColor");
    d.replace("texture(", "texture2D(");
  }

  d.replace("float ", precision+" float ");
  d.replace("vec2 ", precision+" vec2 ");
  d.replace("vec3 ", precision+" vec3 ");
  d.replace("vec4 ", precision+" vec4 ");
  d.replace("mat2 ", precision+" mat2 ");
  d.replace("mat3 ", precision+" mat3 ");
  d.replace("mat4 ", precision+" mat4 ");
  d.replace("sampler2D ", precision+" sampler2D ");

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
  COpenGL *gl = context->getOpenGL();
  GLint status = 0;
  GLint infoLength = 0;
  QVector<char> log;

  program.program = gl->glCreateProgram();
  gl->glAttachShader(program.program, program.vertexShader->getShader()->shader);
  gl->glAttachShader(program.program, program.fragmentShader->getShader()->shader);
  gl->glLinkProgram(program.program);

  gl->glGetProgramiv(program.program, GL_LINK_STATUS, &status);
  gl->glGetProgramiv(program.program, GL_INFO_LOG_LENGTH, &infoLength);
  log.resize(infoLength);
  if(infoLength)
    gl->glGetProgramInfoLog(program.program, infoLength, &infoLength, &log[0]);
#ifndef Q_OS_SYMBIAN
  if(&log[0])
    qDebug(&log[0]);
#endif
  if(status == GL_FALSE)
  {
#ifdef Q_OS_SYMBIAN
    if(&log[0])
      qDebug(&log[0]);
#endif
    QMessageBox *msg = new QMessageBox();
    msg->setWindowTitle(QString("Shader Program Link Error: %1").arg(program.name));
    msg->setText(&log[0]);
    msg->setModal(false);
    msg->show();
  }
}
//------------------------------------------------------------------------------
void CShaderProgram::initUniforms()
{
  COpenGL *gl = context->getOpenGL();

  program.uniforms.vertexPosition = gl->glGetAttribLocation(program.program, NShader::STR_SHADER_UNIFORM_VERTEX_POSITION);
  program.uniforms.vertexNormal = gl->glGetAttribLocation(program.program, NShader::STR_SHADER_UNIFORM_VERTEX_NORMAL);
  program.uniforms.vertexNormalTangent = gl->glGetAttribLocation(program.program, NShader::STR_SHADER_UNIFORM_VERTEX_NORMAL_TANGENT);
  program.uniforms.vertexNormalBitangent = gl->glGetAttribLocation(program.program, NShader::STR_SHADER_UNIFORM_VERTEX_NORMAL_BITANGENT);
  program.uniforms.vertexTexCoord = gl->glGetAttribLocation(program.program, NShader::STR_SHADER_UNIFORM_VERTEX_TEX_COORD);
  program.uniforms.vertexColor = gl->glGetAttribLocation(program.program, NShader::STR_SHADER_UNIFORM_VERTEX_COLOR);
  program.uniforms.mw = gl->glGetUniformLocation(program.program, NShader::STR_SHADER_UNIFORM_MW);
  program.uniforms.mwnit = gl->glGetUniformLocation(program.program, NShader::STR_SHADER_UNIFORM_MWNIT);
  program.uniforms.mvp = gl->glGetUniformLocation(program.program, NShader::STR_SHADER_UNIFORM_MVP);
  program.uniforms.cam = gl->glGetUniformLocation(program.program, NShader::STR_SHADER_UNIFORM_CAM);
  program.uniforms.pos = gl->glGetUniformLocation(program.program, NShader::STR_SHADER_UNIFORM_POS);
  program.uniforms.texPos = gl->glGetUniformLocation(program.program, NShader::STR_SHADER_UNIFORM_TEX_POS);
  program.uniforms.difTex = gl->glGetUniformLocation(program.program, NShader::STR_SHADER_UNIFORM_DIF_TEX);
  program.uniforms.alpTex = gl->glGetUniformLocation(program.program, NShader::STR_SHADER_UNIFORM_ALP_TEX);
  program.uniforms.speTex = gl->glGetUniformLocation(program.program, NShader::STR_SHADER_UNIFORM_SPE_TEX);
  program.uniforms.norTex = gl->glGetUniformLocation(program.program, NShader::STR_SHADER_UNIFORM_NOR_TEX);
  program.uniforms.bumTex = gl->glGetUniformLocation(program.program, NShader::STR_SHADER_UNIFORM_BUM_TEX);
  program.uniforms.envTex = gl->glGetUniformLocation(program.program, NShader::STR_SHADER_UNIFORM_ENV_TEX);
  program.uniforms.opacity = gl->glGetUniformLocation(program.program, NShader::STR_SHADER_UNIFORM_OPACITY);
  program.uniforms.lightAmb = gl->glGetUniformLocation(program.program, NShader::STR_SHADER_UNIFORM_LIGHT_AMB);
  program.uniforms.lightPos = gl->glGetUniformLocation(program.program, NShader::STR_SHADER_UNIFORM_LIGHT_POS);
  program.uniforms.lightRange = gl->glGetUniformLocation(program.program, NShader::STR_SHADER_UNIFORM_LIGHT_RANGE);
  program.uniforms.lightColor = gl->glGetUniformLocation(program.program, NShader::STR_SHADER_UNIFORM_LIGHT_COLOR);
  program.uniforms.lightSpeColor = gl->glGetUniformLocation(program.program, NShader::STR_SHADER_UNIFORM_LIGHT_SPEC_COLOR);
  program.uniforms.fogRange = gl->glGetUniformLocation(program.program, NShader::STR_SHADER_UNIFORM_FOG_RANGE);
  program.uniforms.fogColor = gl->glGetUniformLocation(program.program, NShader::STR_SHADER_UNIFORM_FOG_COLOR);
}
//------------------------------------------------------------------------------
void CShaderProgram::bind() const
{
  context->getOpenGL()->glUseProgram(program.program);
}
//------------------------------------------------------------------------------
void CShaderProgram::begin(const SShaderTechnique *technique) const
{
  COpenGL *gl = context->getOpenGL();

  gl->glEnableVertexAttribArray(program.uniforms.vertexPosition);
  gl->glEnableVertexAttribArray(program.uniforms.vertexNormal);
  gl->glEnableVertexAttribArray(program.uniforms.vertexNormalTangent);
  gl->glEnableVertexAttribArray(program.uniforms.vertexNormalBitangent);
  gl->glEnableVertexAttribArray(program.uniforms.vertexTexCoord);
  gl->glEnableVertexAttribArray(program.uniforms.vertexColor);
  gl->glVertexAttribPointer(program.uniforms.vertexPosition, 3, GL_FLOAT, GL_FALSE, sizeof(float) * NModel::VERTEX_PNTBTC_SIZE, reinterpret_cast<float *>(sizeof(float) * NModel::VBO_OFFSET_POSITION));
  gl->glVertexAttribPointer(program.uniforms.vertexNormal, 3, GL_FLOAT, GL_FALSE, sizeof(float) * NModel::VERTEX_PNTBTC_SIZE, reinterpret_cast<float *>(sizeof(float) * NModel::VBO_OFFSET_NORMAL));
  gl->glVertexAttribPointer(program.uniforms.vertexNormalTangent, 3, GL_FLOAT, GL_FALSE, sizeof(float) * NModel::VERTEX_PNTBTC_SIZE, reinterpret_cast<float *>(sizeof(float) * NModel::VBO_OFFSET_NORMAL_TANGENT));
  gl->glVertexAttribPointer(program.uniforms.vertexNormalBitangent, 3, GL_FLOAT, GL_FALSE, sizeof(float) * NModel::VERTEX_PNTBTC_SIZE, reinterpret_cast<float *>(sizeof(float) * NModel::VBO_OFFSET_NORMAL_BITANGENT));
  gl->glVertexAttribPointer(program.uniforms.vertexTexCoord, 2, GL_FLOAT, GL_FALSE, sizeof(float) * NModel::VERTEX_PNTBTC_SIZE, reinterpret_cast<float *>(sizeof(float) * NModel::VBO_OFFSET_TEX_COORD));
  gl->glVertexAttribPointer(program.uniforms.vertexColor, 3, GL_FLOAT, GL_FALSE, sizeof(float) * NModel::VERTEX_PNTBTC_SIZE, reinterpret_cast<float *>(sizeof(float) * NModel::VBO_OFFSET_COLOR));

  if(!technique)
    return;

  gl->glUniformMatrix4fv(program.uniforms.mw, 1, GL_FALSE, &SMatrix::toFloat(technique->mw)[0]);
  gl->glUniformMatrix3fv(program.uniforms.mwnit, 1, GL_FALSE, &SMatrix::toFloat(technique->mwnit)[0]);
  gl->glUniformMatrix4fv(program.uniforms.mvp, 1, GL_FALSE, &SMatrix::toFloat(technique->mvp)[0]);
  gl->glUniform3f(program.uniforms.cam, technique->cam.x(), technique->cam.y(), technique->cam.z());

  if(technique->material)
  {
    const SMaterial *m = technique->material;

    if((program.name == NShader::PROGRAM_BASIC_ALPHA) ||
       (program.name == NShader::PROGRAM_GUI_TEXT) ||
       (program.name == NShader::PROGRAM_PARTICLES) ||
       (program.name == NShader::PROGRAM_PER_FRAGMENT_ALPHA) ||
       (program.name == NShader::PROGRAM_PER_FRAGMENT_NORMAL_ALPHA))
      gl->glEnable(GL_BLEND);

    if(program.name == NShader::PROGRAM_BASIC)
    {
      setSampler(m->diffuseTexture, program.uniforms.difTex, NShader::SAMPLER_BASIC_DIF, m->mipmap, m->edge);
    }
    else if((program.name == NShader::PROGRAM_BASIC_ALPHA) ||
            (program.name == NShader::PROGRAM_PARTICLES) ||
            (program.name == NShader::PROGRAM_GUI_TEXT))
    {
      setSampler(m->diffuseTexture, program.uniforms.difTex, NShader::SAMPLER_BASIC_APLHA_DIF, m->mipmap, m->edge);
      setSampler(m->alphaTexture, program.uniforms.alpTex, NShader::SAMPLER_BASIC_APLHA_ALP, m->mipmap, m->edge);
    }
    else if(program.name == NShader::PROGRAM_PER_FRAGMENT)
    {
      setSampler(m->diffuseTexture, program.uniforms.difTex, NShader::SAMPLER_PER_FRAGMENT_DIF, m->mipmap, m->edge);
      setSampler(m->specularTexture, program.uniforms.speTex, NShader::SAMPLER_PER_FRAGMENT_SPE, m->mipmap, m->edge);
    }
    else if(program.name == NShader::PROGRAM_PER_FRAGMENT_ALPHA)
    {
      setSampler(m->diffuseTexture, program.uniforms.difTex, NShader::SAMPLER_PER_FRAGMENT_ALPHA_DIF, m->mipmap, m->edge);
      setSampler(m->alphaTexture, program.uniforms.alpTex, NShader::SAMPLER_PER_FRAGMENT_ALPHA_ALP, m->mipmap, m->edge);
      setSampler(m->specularTexture, program.uniforms.speTex, NShader::SAMPLER_PER_FRAGMENT_ALPHA_SPE, m->mipmap, m->edge);
    }
    else if(program.name == NShader::PROGRAM_PER_FRAGMENT_NORMAL)
    {
      setSampler(m->diffuseTexture, program.uniforms.difTex, NShader::SAMPLER_PER_FRAGMENT_NORMAL_DIF, m->mipmap, m->edge);
      setSampler(m->specularTexture, program.uniforms.speTex, NShader::SAMPLER_PER_FRAGMENT_NORMAL_SPE, m->mipmap, m->edge);
      setSampler(m->normalTexture, program.uniforms.norTex, NShader::SAMPLER_PER_FRAGMENT_NORMAL_NOR, m->mipmap, m->edge);
    }
    else if(program.name == NShader::PROGRAM_PER_FRAGMENT_NORMAL_ALPHA)
    {
      setSampler(m->diffuseTexture, program.uniforms.difTex, NShader::SAMPLER_PER_FRAGMENT_NORMAL_ALPHA_DIF, m->mipmap, m->edge);
      setSampler(m->alphaTexture, program.uniforms.alpTex, NShader::SAMPLER_PER_FRAGMENT_NORMAL_ALPHA_ALP, m->mipmap, m->edge);
      setSampler(m->specularTexture, program.uniforms.speTex, NShader::SAMPLER_PER_FRAGMENT_NORMAL_ALPHA_SPE, m->mipmap, m->edge);
      setSampler(m->normalTexture, program.uniforms.norTex, NShader::SAMPLER_PER_FRAGMENT_NORMAL_ALPHA_NOR, m->mipmap, m->edge);
    }

    gl->glUniform1f(program.uniforms.opacity, m->opacity);
    context->getMaps()->finishBind();
  }

  if(program.name == NShader::PROGRAM_GUI_TEXT)
    gl->glUniform4f(program.uniforms.pos, technique->posOffset.x(), technique->posOffset.y(), technique->posOffset.z(), technique->posOffset.w());
  else
    gl->glUniform4f(program.uniforms.pos, technique->pos.x(), technique->pos.y(), technique->pos.z(), technique->pos.w());
  gl->glUniform2f(program.uniforms.texPos, technique->texPos.x(), technique->texPos.y());

  const SCamera *cam = context->getCamera()->getCamera();
  if(program.name == NShader::PROGRAM_COLOR)
    gl->glUniform3f(program.uniforms.lightAmb, technique->pickColor.x(), technique->pickColor.y(), technique->pickColor.z());
  else
    gl->glUniform3f(program.uniforms.lightAmb, technique->lightAmb.x(), technique->lightAmb.y(), technique->lightAmb.z());
  gl->glUniform3f(program.uniforms.lightPos, technique->lightPos.x(), technique->lightPos.y(), technique->lightPos.z());
  gl->glUniform2f(program.uniforms.lightRange, technique->lightRange.x(), technique->lightRange.y());
  gl->glUniform3f(program.uniforms.lightColor, technique->lightColor.x(), technique->lightColor.y(), technique->lightColor.z());
  gl->glUniform4f(program.uniforms.lightSpeColor, technique->lightSpeColor.x(), technique->lightSpeColor.y(), technique->lightSpeColor.z(), technique->lightSpeColor.w());
  gl->glUniform2f(program.uniforms.fogRange, technique->fogRange.x() * cam->clipFar, technique->fogRange.y() * cam->clipFar);
  gl->glUniform3f(program.uniforms.fogColor, technique->fogColor.x(), technique->fogColor.y(), technique->fogColor.z());
}
//------------------------------------------------------------------------------
void CShaderProgram::end(const SShaderTechnique *technique) const
{
  COpenGL *gl = context->getOpenGL();

  if((technique) && (technique->material))
  {
    if((program.name == NShader::PROGRAM_BASIC_ALPHA) ||
       (program.name == NShader::PROGRAM_GUI_TEXT) ||
       (program.name == NShader::PROGRAM_PARTICLES) ||
       (program.name == NShader::PROGRAM_PER_FRAGMENT_ALPHA) ||
       (program.name == NShader::PROGRAM_PER_FRAGMENT_NORMAL_ALPHA))
      gl->glDisable(GL_BLEND);
  }

  gl->glDisableVertexAttribArray(program.uniforms.vertexPosition);
  gl->glDisableVertexAttribArray(program.uniforms.vertexNormal);
  gl->glDisableVertexAttribArray(program.uniforms.vertexNormalTangent);
  gl->glDisableVertexAttribArray(program.uniforms.vertexNormalBitangent);
  gl->glDisableVertexAttribArray(program.uniforms.vertexTexCoord);
  gl->glDisableVertexAttribArray(program.uniforms.vertexColor);
}
//------------------------------------------------------------------------------
void CShaderProgram::unbind() const
{
  context->getOpenGL()->glUseProgram(0);
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
