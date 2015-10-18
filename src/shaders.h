//------------------------------------------------------------------------------
#ifndef SHADERS_H
#define SHADERS_H

#include <QMessageBox>
#include <QRegExp>

#include "pickColor.h"
#include "headers/shaderTypes.h"

//------------------------------------------------------------------------------
class CShader : public CEngineBase
{
  private:
  SShader shader;

  public:
  CShader();
  CShader(CContext *context, const SShader &shader);
  ~CShader();

  void compile();

  QString setES2compatible(const QString &data);

  inline const SShader *getShader() const { return &shader; }
};
//------------------------------------------------------------------------------
class CShaderProgram : public CEngineBase
{
  private:
  SShaderProgram program;

  void setSampler(const CMap *texture, GLuint uniform, uint8 sampler, bool mipmap = true, bool edge = false) const;

  public:
  CShaderProgram();
  CShaderProgram(CContext *context, const SShaderProgram &shaderProgram);
  ~CShaderProgram();

  void link();
  void initUniforms();

  void bind() const;
  void begin(const SShaderTechnique *technique) const;
  void end(const SShaderTechnique *technique) const;
  void unbind() const;

  inline const SShaderProgram *getShaderProgram() const { return &program; }
};
//------------------------------------------------------------------------------
class CShaders : public CEngineBase
{
  private:
  QList<CShader> vertexShaders;
  QList<CShader> fragmentShaders;
  QList<CShaderProgram> shaderPrograms;

  public:
  CShaders();
  CShaders(CContext *context);
  ~CShaders();

  CShader *addShader(const SShader &shader);
  CShaderProgram *addShaderProgram(const SShaderProgram &shaderProgram);

  inline CShader *getVertexShader(uint32 index) { return &vertexShaders[index]; }
  inline CShader *getFragmentShader(uint32 index) { return &fragmentShaders[index]; }
  inline CShaderProgram *getShaderProgram(NShader::EProgram index) { return &shaderPrograms[index]; }
};
//------------------------------------------------------------------------------
inline CShader *CShaders::addShader(const SShader &shader)
{
  if(shader.type == NShader::TYPE_VERTEX)
  {
    vertexShaders.push_back(CShader(context, shader));
    return &vertexShaders.back();
  }
  else if(shader.type == NShader::TYPE_FRAGMENT)
  {
    fragmentShaders.push_back(CShader(context, shader));
    return &fragmentShaders.back();
  }

  return NULL;
}
//------------------------------------------------------------------------------
inline CShaderProgram *CShaders::addShaderProgram(const SShaderProgram &shaderProgram)
{
  shaderPrograms.push_back(CShaderProgram(context, shaderProgram));
  return &shaderPrograms.back();
}
//------------------------------------------------------------------------------
inline void CShaderProgram::setSampler(const CMap *texture, GLuint uniform, uint8 sampler, bool mipmap, bool edge) const
{
  if(texture)
    texture->bind(uniform, sampler, mipmap, edge);
  else
    context->getMaps()->unbind(uniform, sampler);
}
//------------------------------------------------------------------------------
#endif // SHADERS_H
