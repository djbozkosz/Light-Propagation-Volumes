//------------------------------------------------------------------------------
#ifndef SHADERS_H
#define SHADERS_H

#if defined(ENV_QT)
#include <QMessageBox>
#endif

#include "culling.h"
#include "headers/rendererTypes.h"
#include "headers/windowTypes.h"
#include "headers/sceneTypes.h"

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

    void setSampler(const CMap *texture, GLuint uniform, uint8 sampler, uint32 format = NMap::FORMAT_MIPMAP) const;
    void beginLPV(NShader::ESampler startDepthSampler, const CMap *depthMap) const;

  public:
    CShaderProgram();
    CShaderProgram(CContext *context, const SShaderProgram &shaderProgram);
    ~CShaderProgram();

    void link();
    void initUniforms();

    void bind() const;
    void begin(const SShaderTechnique *technique, NRenderer::EMode mode = NRenderer::MODE_STANDARD) const;
    void end(const SShaderTechnique *technique) const;
    void unbind() const;
    void dispatch(uint32 x, uint32 y, uint32 z, NRenderer::EMode mode, GLbitfield preSync = GL_NONE, GLbitfield postSync = GL_NONE) const;

    inline const SShaderProgram *getProgram() const { return &program; }
};
//------------------------------------------------------------------------------
class CShaders : public CEngineBase
{
  private:
    std::map<std::string, CShader> shaders;
    std::map<NShader::EProgram, CShaderProgram> programs;

  public:
    CShaders();
    CShaders(CContext *context);
    ~CShaders();

    CShader *addShader(const SShader &shader);
    CShaderProgram *addShaderProgram(const SShaderProgram &shaderProgram);

    inline CShader *getShader(const std::string &file) { auto it = shaders.find(file); if(it == shaders.end()) return NULL; return &it->second; }
    inline CShaderProgram *getProgram(NShader::EProgram name) { auto it = programs.find(name); if(it == programs.end()) return NULL; return &it->second; }
};
//------------------------------------------------------------------------------
inline CShader *CShaders::addShader(const SShader &shader)
{
  CShader *vs = getShader(shader.file);

  if(vs)
    return vs;

  shaders[shader.file] = CShader(context, shader);
  vs = getShader(shader.file);
  vs->compile();

  return vs;
}
//------------------------------------------------------------------------------
inline CShaderProgram *CShaders::addShaderProgram(const SShaderProgram &shaderProgram)
{
  CShaderProgram *sp = getProgram(shaderProgram.name);

  if(sp)
    return sp;

  programs[shaderProgram.name] = CShaderProgram(context, shaderProgram);
  sp = getProgram(shaderProgram.name);
  sp->link();
  sp->initUniforms();

  return sp;
}
//------------------------------------------------------------------------------
inline void CShaderProgram::setSampler(const CMap *texture, GLuint uniform, uint8 sampler, uint32 format) const
{
  if(texture)
    texture->bind(uniform, sampler, format);
  else
    context->getMaps()->unbind(uniform, sampler, format);
}
//------------------------------------------------------------------------------
inline void CShaderProgram::beginLPV(NShader::ESampler startDepthSampler, const CMap *depthMap) const
{
  setSampler(depthMap, program.uniforms.depthTex, NShader::SAMPLER_PER_FRAGMENT_DEPTH, NMap::FORMAT_LINEAR | NMap::FORMAT_DEPTH | NMap::FORMAT_BORDER);
  setSampler(lpvMapR, program.uniforms.lpv0ImgR, NShader::SAMPLER_PER_FRAGMENT_LPV_R, NMap::FORMAT_LINEAR | NMap::FORMAT_BORDER);
  setSampler(lpvMapG, program.uniforms.lpv0ImgG, NShader::SAMPLER_PER_FRAGMENT_LPV_G, NMap::FORMAT_LINEAR | NMap::FORMAT_BORDER);
  setSampler(lpvMapB, program.uniforms.lpv0ImgB, NShader::SAMPLER_PER_FRAGMENT_LPV_B, NMap::FORMAT_LINEAR | NMap::FORMAT_BORDER);//
}
//------------------------------------------------------------------------------
#endif // SHADERS_H
