//------------------------------------------------------------------------------
#ifndef SHADERS_H
#define SHADERS_H

#if defined(ENV_QT)
#include <QMessageBox>
#endif

#include "culling.h"
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

    std::string setES2compatible(const std::string &data);

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
    std::map<std::string, CShader> vertexShaders;
    std::map<std::string, CShader> fragmentShaders;
    std::map<NShader::EProgram, CShaderProgram> shaderPrograms;

  public:
    CShaders();
    CShaders(CContext *context);
    ~CShaders();

    CShader *addShader(const SShader &shader);
    CShaderProgram *addShaderProgram(const SShaderProgram &shaderProgram);

    inline CShader *getVertexShader(const std::string &file) { auto it = vertexShaders.find(file); if(it == vertexShaders.end()) return NULL; return &it->second; }
    inline CShader *getFragmentShader(const std::string &file) { auto it = fragmentShaders.find(file); if(it == fragmentShaders.end()) return NULL; return &it->second; }
    inline CShaderProgram *getShaderProgram(NShader::EProgram name) { auto it = shaderPrograms.find(name); if(it == shaderPrograms.end()) return NULL; return &it->second; }
};
//------------------------------------------------------------------------------
inline CShader *CShaders::addShader(const SShader &shader)
{
  if(shader.type == NShader::TYPE_VERTEX)
  {
    if(CShader *vs = getVertexShader(shader.file))
      return vs;

    vertexShaders[shader.file] = CShader(context, shader);

    return getVertexShader(shader.file);
  }
  else if(shader.type == NShader::TYPE_FRAGMENT)
  {
    if(CShader *fs = getFragmentShader(shader.file))
      return fs;

    fragmentShaders[shader.file] = CShader(context, shader);

    return getFragmentShader(shader.file);
  }

  return NULL;
}
//------------------------------------------------------------------------------
inline CShaderProgram *CShaders::addShaderProgram(const SShaderProgram &shaderProgram)
{
  if(CShaderProgram *sp = getShaderProgram(shaderProgram.name))
    return sp;

  shaderPrograms[shaderProgram.name] = CShaderProgram(context, shaderProgram);

  return getShaderProgram(shaderProgram.name);
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
