//------------------------------------------------------------------------------

#include "openGL.h"
//------------------------------------------------------------------------------
COpenGL::COpenGL(CContext *context) : CEngineBase(context),
  // GL_VERSION_1_2
  glCopyTexSubImage3D(NULL), statusCopyTexSubImage3D(NOpenGLProc::TYPE_NOT_LOADED),
  glDrawRangeElements(NULL), statusDrawRangeElements(NOpenGLProc::TYPE_NOT_LOADED),
  glTexImage3D(NULL), statusTexImage3D(NOpenGLProc::TYPE_NOT_LOADED),
  glTexSubImage3D(NULL), statusTexSubImage3D(NOpenGLProc::TYPE_NOT_LOADED),

  // GL_VERSION_1_3
  glActiveTexture(NULL), statusActiveTexture(NOpenGLProc::TYPE_NOT_LOADED),
  glCompressedTexImage1D(NULL), statusCompressedTexImage1D(NOpenGLProc::TYPE_NOT_LOADED),
  glCompressedTexImage2D(NULL), statusCompressedTexImage2D(NOpenGLProc::TYPE_NOT_LOADED),
  glCompressedTexImage3D(NULL), statusCompressedTexImage3D(NOpenGLProc::TYPE_NOT_LOADED),
  glCompressedTexSubImage1D(NULL), statusCompressedTexSubImage1D(NOpenGLProc::TYPE_NOT_LOADED),
  glCompressedTexSubImage2D(NULL), statusCompressedTexSubImage2D(NOpenGLProc::TYPE_NOT_LOADED),
  glCompressedTexSubImage3D(NULL), statusCompressedTexSubImage3D(NOpenGLProc::TYPE_NOT_LOADED),
  glGetCompressedTexImage(NULL), statusGetCompressedTexImage(NOpenGLProc::TYPE_NOT_LOADED),
  glSampleCoverage(NULL), statusSampleCoverage(NOpenGLProc::TYPE_NOT_LOADED),

  // GL_VERSION_1_4
  glBlendColor(NULL), statusBlendColor(NOpenGLProc::TYPE_NOT_LOADED),
  glBlendEquation(NULL), statusBlendEquation(NOpenGLProc::TYPE_NOT_LOADED),
  glBlendFuncSeparate(NULL), statusBlendFuncSeparate(NOpenGLProc::TYPE_NOT_LOADED),
  glMultiDrawArrays(NULL), statusMultiDrawArrays(NOpenGLProc::TYPE_NOT_LOADED),
  glMultiDrawElements(NULL), statusMultiDrawElements(NOpenGLProc::TYPE_NOT_LOADED),
  glPointParameterf(NULL), statusPointParameterf(NOpenGLProc::TYPE_NOT_LOADED),
  glPointParameterfv(NULL), statusPointParameterfv(NOpenGLProc::TYPE_NOT_LOADED),
  glPointParameteri(NULL), statusPointParameteri(NOpenGLProc::TYPE_NOT_LOADED),
  glPointParameteriv(NULL), statusPointParameteriv(NOpenGLProc::TYPE_NOT_LOADED),

  // GL_VERSION_1_5
  glBeginQuery(NULL), statusBeginQuery(NOpenGLProc::TYPE_NOT_LOADED),
  glBindBuffer(NULL), statusBindBuffer(NOpenGLProc::TYPE_NOT_LOADED),
  glBufferData(NULL), statusBufferData(NOpenGLProc::TYPE_NOT_LOADED),
  glBufferSubData(NULL), statusBufferSubData(NOpenGLProc::TYPE_NOT_LOADED),
  glDeleteBuffers(NULL), statusDeleteBuffers(NOpenGLProc::TYPE_NOT_LOADED),
  glDeleteQueries(NULL), statusDeleteQueries(NOpenGLProc::TYPE_NOT_LOADED),
  glEndQuery(NULL), statusEndQuery(NOpenGLProc::TYPE_NOT_LOADED),
  glGenBuffers(NULL), statusGenBuffers(NOpenGLProc::TYPE_NOT_LOADED),
  glGenQueries(NULL), statusGenQueries(NOpenGLProc::TYPE_NOT_LOADED),
  glGetBufferParameteriv(NULL), statusGetBufferParameteriv(NOpenGLProc::TYPE_NOT_LOADED),
  glGetBufferPointerv(NULL), statusGetBufferPointerv(NOpenGLProc::TYPE_NOT_LOADED),
  glGetBufferSubData(NULL), statusGetBufferSubData(NOpenGLProc::TYPE_NOT_LOADED),
  glGetQueryObjectiv(NULL), statusGetQueryObjectiv(NOpenGLProc::TYPE_NOT_LOADED),
  glGetQueryObjectuiv(NULL), statusGetQueryObjectuiv(NOpenGLProc::TYPE_NOT_LOADED),
  glGetQueryiv(NULL), statusGetQueryiv(NOpenGLProc::TYPE_NOT_LOADED),
  glIsBuffer(NULL), statusIsBuffer(NOpenGLProc::TYPE_NOT_LOADED),
  glIsQuery(NULL), statusIsQuery(NOpenGLProc::TYPE_NOT_LOADED),
  glMapBuffer(NULL), statusMapBuffer(NOpenGLProc::TYPE_NOT_LOADED),
  glUnmapBuffer(NULL), statusUnmapBuffer(NOpenGLProc::TYPE_NOT_LOADED),

  // GL_VERSION_2_0
  glAttachShader(NULL), statusAttachShader(NOpenGLProc::TYPE_NOT_LOADED),
  glBindAttribLocation(NULL), statusBindAttribLocation(NOpenGLProc::TYPE_NOT_LOADED),
  glBlendEquationSeparate(NULL), statusBlendEquationSeparate(NOpenGLProc::TYPE_NOT_LOADED),
  glCompileShader(NULL), statusCompileShader(NOpenGLProc::TYPE_NOT_LOADED),
  glCreateProgram(NULL), statusCreateProgram(NOpenGLProc::TYPE_NOT_LOADED),
  glCreateShader(NULL), statusCreateShader(NOpenGLProc::TYPE_NOT_LOADED),
  glDeleteProgram(NULL), statusDeleteProgram(NOpenGLProc::TYPE_NOT_LOADED),
  glDeleteShader(NULL), statusDeleteShader(NOpenGLProc::TYPE_NOT_LOADED),
  glDetachShader(NULL), statusDetachShader(NOpenGLProc::TYPE_NOT_LOADED),
  glDisableVertexAttribArray(NULL), statusDisableVertexAttribArray(NOpenGLProc::TYPE_NOT_LOADED),
  glDrawBuffers(NULL), statusDrawBuffers(NOpenGLProc::TYPE_NOT_LOADED),
  glEnableVertexAttribArray(NULL), statusEnableVertexAttribArray(NOpenGLProc::TYPE_NOT_LOADED),
  glGetActiveAttrib(NULL), statusGetActiveAttrib(NOpenGLProc::TYPE_NOT_LOADED),
  glGetActiveUniform(NULL), statusGetActiveUniform(NOpenGLProc::TYPE_NOT_LOADED),
  glGetAttachedShaders(NULL), statusGetAttachedShaders(NOpenGLProc::TYPE_NOT_LOADED),
  glGetAttribLocation(NULL), statusGetAttribLocation(NOpenGLProc::TYPE_NOT_LOADED),
  glGetProgramInfoLog(NULL), statusGetProgramInfoLog(NOpenGLProc::TYPE_NOT_LOADED),
  glGetProgramiv(NULL), statusGetProgramiv(NOpenGLProc::TYPE_NOT_LOADED),
  glGetShaderInfoLog(NULL), statusGetShaderInfoLog(NOpenGLProc::TYPE_NOT_LOADED),
  glGetShaderSource(NULL), statusGetShaderSource(NOpenGLProc::TYPE_NOT_LOADED),
  glGetShaderiv(NULL), statusGetShaderiv(NOpenGLProc::TYPE_NOT_LOADED),
  glGetUniformLocation(NULL), statusGetUniformLocation(NOpenGLProc::TYPE_NOT_LOADED),
  glGetUniformfv(NULL), statusGetUniformfv(NOpenGLProc::TYPE_NOT_LOADED),
  glGetUniformiv(NULL), statusGetUniformiv(NOpenGLProc::TYPE_NOT_LOADED),
  glGetVertexAttribPointerv(NULL), statusGetVertexAttribPointerv(NOpenGLProc::TYPE_NOT_LOADED),
  glGetVertexAttribdv(NULL), statusGetVertexAttribdv(NOpenGLProc::TYPE_NOT_LOADED),
  glGetVertexAttribfv(NULL), statusGetVertexAttribfv(NOpenGLProc::TYPE_NOT_LOADED),
  glGetVertexAttribiv(NULL), statusGetVertexAttribiv(NOpenGLProc::TYPE_NOT_LOADED),
  glIsProgram(NULL), statusIsProgram(NOpenGLProc::TYPE_NOT_LOADED),
  glIsShader(NULL), statusIsShader(NOpenGLProc::TYPE_NOT_LOADED),
  glLinkProgram(NULL), statusLinkProgram(NOpenGLProc::TYPE_NOT_LOADED),
  glShaderSource(NULL), statusShaderSource(NOpenGLProc::TYPE_NOT_LOADED),
  glStencilFuncSeparate(NULL), statusStencilFuncSeparate(NOpenGLProc::TYPE_NOT_LOADED),
  glStencilMaskSeparate(NULL), statusStencilMaskSeparate(NOpenGLProc::TYPE_NOT_LOADED),
  glStencilOpSeparate(NULL), statusStencilOpSeparate(NOpenGLProc::TYPE_NOT_LOADED),
  glUniform1f(NULL), statusUniform1f(NOpenGLProc::TYPE_NOT_LOADED),
  glUniform1fv(NULL), statusUniform1fv(NOpenGLProc::TYPE_NOT_LOADED),
  glUniform1i(NULL), statusUniform1i(NOpenGLProc::TYPE_NOT_LOADED),
  glUniform1iv(NULL), statusUniform1iv(NOpenGLProc::TYPE_NOT_LOADED),
  glUniform2f(NULL), statusUniform2f(NOpenGLProc::TYPE_NOT_LOADED),
  glUniform2fv(NULL), statusUniform2fv(NOpenGLProc::TYPE_NOT_LOADED),
  glUniform2i(NULL), statusUniform2i(NOpenGLProc::TYPE_NOT_LOADED),
  glUniform2iv(NULL), statusUniform2iv(NOpenGLProc::TYPE_NOT_LOADED),
  glUniform3f(NULL), statusUniform3f(NOpenGLProc::TYPE_NOT_LOADED),
  glUniform3fv(NULL), statusUniform3fv(NOpenGLProc::TYPE_NOT_LOADED),
  glUniform3i(NULL), statusUniform3i(NOpenGLProc::TYPE_NOT_LOADED),
  glUniform3iv(NULL), statusUniform3iv(NOpenGLProc::TYPE_NOT_LOADED),
  glUniform4f(NULL), statusUniform4f(NOpenGLProc::TYPE_NOT_LOADED),
  glUniform4fv(NULL), statusUniform4fv(NOpenGLProc::TYPE_NOT_LOADED),
  glUniform4i(NULL), statusUniform4i(NOpenGLProc::TYPE_NOT_LOADED),
  glUniform4iv(NULL), statusUniform4iv(NOpenGLProc::TYPE_NOT_LOADED),
  glUniformMatrix2fv(NULL), statusUniformMatrix2fv(NOpenGLProc::TYPE_NOT_LOADED),
  glUniformMatrix3fv(NULL), statusUniformMatrix3fv(NOpenGLProc::TYPE_NOT_LOADED),
  glUniformMatrix4fv(NULL), statusUniformMatrix4fv(NOpenGLProc::TYPE_NOT_LOADED),
  glUseProgram(NULL), statusUseProgram(NOpenGLProc::TYPE_NOT_LOADED),
  glValidateProgram(NULL), statusValidateProgram(NOpenGLProc::TYPE_NOT_LOADED),
  glVertexAttrib1d(NULL), statusVertexAttrib1d(NOpenGLProc::TYPE_NOT_LOADED),
  glVertexAttrib1dv(NULL), statusVertexAttrib1dv(NOpenGLProc::TYPE_NOT_LOADED),
  glVertexAttrib1f(NULL), statusVertexAttrib1f(NOpenGLProc::TYPE_NOT_LOADED),
  glVertexAttrib1fv(NULL), statusVertexAttrib1fv(NOpenGLProc::TYPE_NOT_LOADED),
  glVertexAttrib1s(NULL), statusVertexAttrib1s(NOpenGLProc::TYPE_NOT_LOADED),
  glVertexAttrib1sv(NULL), statusVertexAttrib1sv(NOpenGLProc::TYPE_NOT_LOADED),
  glVertexAttrib2d(NULL), statusVertexAttrib2d(NOpenGLProc::TYPE_NOT_LOADED),
  glVertexAttrib2dv(NULL), statusVertexAttrib2dv(NOpenGLProc::TYPE_NOT_LOADED),
  glVertexAttrib2f(NULL), statusVertexAttrib2f(NOpenGLProc::TYPE_NOT_LOADED),
  glVertexAttrib2fv(NULL), statusVertexAttrib2fv(NOpenGLProc::TYPE_NOT_LOADED),
  glVertexAttrib2s(NULL), statusVertexAttrib2s(NOpenGLProc::TYPE_NOT_LOADED),
  glVertexAttrib2sv(NULL), statusVertexAttrib2sv(NOpenGLProc::TYPE_NOT_LOADED),
  glVertexAttrib3d(NULL), statusVertexAttrib3d(NOpenGLProc::TYPE_NOT_LOADED),
  glVertexAttrib3dv(NULL), statusVertexAttrib3dv(NOpenGLProc::TYPE_NOT_LOADED),
  glVertexAttrib3f(NULL), statusVertexAttrib3f(NOpenGLProc::TYPE_NOT_LOADED),
  glVertexAttrib3fv(NULL), statusVertexAttrib3fv(NOpenGLProc::TYPE_NOT_LOADED),
  glVertexAttrib3s(NULL), statusVertexAttrib3s(NOpenGLProc::TYPE_NOT_LOADED),
  glVertexAttrib3sv(NULL), statusVertexAttrib3sv(NOpenGLProc::TYPE_NOT_LOADED),
  glVertexAttrib4Nbv(NULL), statusVertexAttrib4Nbv(NOpenGLProc::TYPE_NOT_LOADED),
  glVertexAttrib4Niv(NULL), statusVertexAttrib4Niv(NOpenGLProc::TYPE_NOT_LOADED),
  glVertexAttrib4Nsv(NULL), statusVertexAttrib4Nsv(NOpenGLProc::TYPE_NOT_LOADED),
  glVertexAttrib4Nub(NULL), statusVertexAttrib4Nub(NOpenGLProc::TYPE_NOT_LOADED),
  glVertexAttrib4Nubv(NULL), statusVertexAttrib4Nubv(NOpenGLProc::TYPE_NOT_LOADED),
  glVertexAttrib4Nuiv(NULL), statusVertexAttrib4Nuiv(NOpenGLProc::TYPE_NOT_LOADED),
  glVertexAttrib4Nusv(NULL), statusVertexAttrib4Nusv(NOpenGLProc::TYPE_NOT_LOADED),
  glVertexAttrib4bv(NULL), statusVertexAttrib4bv(NOpenGLProc::TYPE_NOT_LOADED),
  glVertexAttrib4d(NULL), statusVertexAttrib4d(NOpenGLProc::TYPE_NOT_LOADED),
  glVertexAttrib4dv(NULL), statusVertexAttrib4dv(NOpenGLProc::TYPE_NOT_LOADED),
  glVertexAttrib4f(NULL), statusVertexAttrib4f(NOpenGLProc::TYPE_NOT_LOADED),
  glVertexAttrib4fv(NULL), statusVertexAttrib4fv(NOpenGLProc::TYPE_NOT_LOADED),
  glVertexAttrib4iv(NULL), statusVertexAttrib4iv(NOpenGLProc::TYPE_NOT_LOADED),
  glVertexAttrib4s(NULL), statusVertexAttrib4s(NOpenGLProc::TYPE_NOT_LOADED),
  glVertexAttrib4sv(NULL), statusVertexAttrib4sv(NOpenGLProc::TYPE_NOT_LOADED),
  glVertexAttrib4ubv(NULL), statusVertexAttrib4ubv(NOpenGLProc::TYPE_NOT_LOADED),
  glVertexAttrib4uiv(NULL), statusVertexAttrib4uiv(NOpenGLProc::TYPE_NOT_LOADED),
  glVertexAttrib4usv(NULL), statusVertexAttrib4usv(NOpenGLProc::TYPE_NOT_LOADED),
  glVertexAttribPointer(NULL), statusVertexAttribPointer(NOpenGLProc::TYPE_NOT_LOADED),

  // GL_VERSION_2_1
  glUniformMatrix2x3fv(NULL), statusUniformMatrix2x3fv(NOpenGLProc::TYPE_NOT_LOADED),
  glUniformMatrix2x4fv(NULL), statusUniformMatrix2x4fv(NOpenGLProc::TYPE_NOT_LOADED),
  glUniformMatrix3x2fv(NULL), statusUniformMatrix3x2fv(NOpenGLProc::TYPE_NOT_LOADED),
  glUniformMatrix3x4fv(NULL), statusUniformMatrix3x4fv(NOpenGLProc::TYPE_NOT_LOADED),
  glUniformMatrix4x2fv(NULL), statusUniformMatrix4x2fv(NOpenGLProc::TYPE_NOT_LOADED),
  glUniformMatrix4x3fv(NULL), statusUniformMatrix4x3fv(NOpenGLProc::TYPE_NOT_LOADED),

  // GL_VERSION_3_0
  glBeginConditionalRender(NULL), statusBeginConditionalRender(NOpenGLProc::TYPE_NOT_LOADED),
  glBeginTransformFeedback(NULL), statusBeginTransformFeedback(NOpenGLProc::TYPE_NOT_LOADED),
  glBindBufferBase(NULL), statusBindBufferBase(NOpenGLProc::TYPE_NOT_LOADED),
  glBindBufferRange(NULL), statusBindBufferRange(NOpenGLProc::TYPE_NOT_LOADED),
  glBindFragDataLocation(NULL), statusBindFragDataLocation(NOpenGLProc::TYPE_NOT_LOADED),
  glBindFramebuffer(NULL), statusBindFramebuffer(NOpenGLProc::TYPE_NOT_LOADED),
  glBindRenderbuffer(NULL), statusBindRenderbuffer(NOpenGLProc::TYPE_NOT_LOADED),
  glBindVertexArray(NULL), statusBindVertexArray(NOpenGLProc::TYPE_NOT_LOADED),
  glBlitFramebuffer(NULL), statusBlitFramebuffer(NOpenGLProc::TYPE_NOT_LOADED),
  glCheckFramebufferStatus(NULL), statusCheckFramebufferStatus(NOpenGLProc::TYPE_NOT_LOADED),
  glClampColor(NULL), statusClampColor(NOpenGLProc::TYPE_NOT_LOADED),
  glClearBufferfi(NULL), statusClearBufferfi(NOpenGLProc::TYPE_NOT_LOADED),
  glClearBufferfv(NULL), statusClearBufferfv(NOpenGLProc::TYPE_NOT_LOADED),
  glClearBufferiv(NULL), statusClearBufferiv(NOpenGLProc::TYPE_NOT_LOADED),
  glClearBufferuiv(NULL), statusClearBufferuiv(NOpenGLProc::TYPE_NOT_LOADED),
  glColorMaski(NULL), statusColorMaski(NOpenGLProc::TYPE_NOT_LOADED),
  glDeleteFramebuffers(NULL), statusDeleteFramebuffers(NOpenGLProc::TYPE_NOT_LOADED),
  glDeleteRenderbuffers(NULL), statusDeleteRenderbuffers(NOpenGLProc::TYPE_NOT_LOADED),
  glDeleteVertexArrays(NULL), statusDeleteVertexArrays(NOpenGLProc::TYPE_NOT_LOADED),
  glDisablei(NULL), statusDisablei(NOpenGLProc::TYPE_NOT_LOADED),
  glEnablei(NULL), statusEnablei(NOpenGLProc::TYPE_NOT_LOADED),
  glEndConditionalRender(NULL), statusEndConditionalRender(NOpenGLProc::TYPE_NOT_LOADED),
  glEndTransformFeedback(NULL), statusEndTransformFeedback(NOpenGLProc::TYPE_NOT_LOADED),
  glFlushMappedBufferRange(NULL), statusFlushMappedBufferRange(NOpenGLProc::TYPE_NOT_LOADED),
  glFramebufferRenderbuffer(NULL), statusFramebufferRenderbuffer(NOpenGLProc::TYPE_NOT_LOADED),
  glFramebufferTexture1D(NULL), statusFramebufferTexture1D(NOpenGLProc::TYPE_NOT_LOADED),
  glFramebufferTexture2D(NULL), statusFramebufferTexture2D(NOpenGLProc::TYPE_NOT_LOADED),
  glFramebufferTexture3D(NULL), statusFramebufferTexture3D(NOpenGLProc::TYPE_NOT_LOADED),
  glFramebufferTextureLayer(NULL), statusFramebufferTextureLayer(NOpenGLProc::TYPE_NOT_LOADED),
  glGenFramebuffers(NULL), statusGenFramebuffers(NOpenGLProc::TYPE_NOT_LOADED),
  glGenRenderbuffers(NULL), statusGenRenderbuffers(NOpenGLProc::TYPE_NOT_LOADED),
  glGenVertexArrays(NULL), statusGenVertexArrays(NOpenGLProc::TYPE_NOT_LOADED),
  glGenerateMipmap(NULL), statusGenerateMipmap(NOpenGLProc::TYPE_NOT_LOADED),
  glGetBooleani_v(NULL), statusGetBooleani_v(NOpenGLProc::TYPE_NOT_LOADED),
  glGetFragDataLocation(NULL), statusGetFragDataLocation(NOpenGLProc::TYPE_NOT_LOADED),
  glGetFramebufferAttachmentParameteriv(NULL), statusGetFramebufferAttachmentParameteriv(NOpenGLProc::TYPE_NOT_LOADED),
  glGetIntegeri_v(NULL), statusGetIntegeri_v(NOpenGLProc::TYPE_NOT_LOADED),
  glGetRenderbufferParameteriv(NULL), statusGetRenderbufferParameteriv(NOpenGLProc::TYPE_NOT_LOADED),
  glGetStringi(NULL), statusGetStringi(NOpenGLProc::TYPE_NOT_LOADED),
  glGetTexParameterIiv(NULL), statusGetTexParameterIiv(NOpenGLProc::TYPE_NOT_LOADED),
  glGetTexParameterIuiv(NULL), statusGetTexParameterIuiv(NOpenGLProc::TYPE_NOT_LOADED),
  glGetTransformFeedbackVarying(NULL), statusGetTransformFeedbackVarying(NOpenGLProc::TYPE_NOT_LOADED),
  glGetUniformuiv(NULL), statusGetUniformuiv(NOpenGLProc::TYPE_NOT_LOADED),
  glGetVertexAttribIiv(NULL), statusGetVertexAttribIiv(NOpenGLProc::TYPE_NOT_LOADED),
  glGetVertexAttribIuiv(NULL), statusGetVertexAttribIuiv(NOpenGLProc::TYPE_NOT_LOADED),
  glIsEnabledi(NULL), statusIsEnabledi(NOpenGLProc::TYPE_NOT_LOADED),
  glIsFramebuffer(NULL), statusIsFramebuffer(NOpenGLProc::TYPE_NOT_LOADED),
  glIsRenderbuffer(NULL), statusIsRenderbuffer(NOpenGLProc::TYPE_NOT_LOADED),
  glIsVertexArray(NULL), statusIsVertexArray(NOpenGLProc::TYPE_NOT_LOADED),
  glMapBufferRange(NULL), statusMapBufferRange(NOpenGLProc::TYPE_NOT_LOADED),
  glRenderbufferStorage(NULL), statusRenderbufferStorage(NOpenGLProc::TYPE_NOT_LOADED),
  glRenderbufferStorageMultisample(NULL), statusRenderbufferStorageMultisample(NOpenGLProc::TYPE_NOT_LOADED),
  glTexParameterIiv(NULL), statusTexParameterIiv(NOpenGLProc::TYPE_NOT_LOADED),
  glTexParameterIuiv(NULL), statusTexParameterIuiv(NOpenGLProc::TYPE_NOT_LOADED),
  glTransformFeedbackVaryings(NULL), statusTransformFeedbackVaryings(NOpenGLProc::TYPE_NOT_LOADED),
  glUniform1ui(NULL), statusUniform1ui(NOpenGLProc::TYPE_NOT_LOADED),
  glUniform1uiv(NULL), statusUniform1uiv(NOpenGLProc::TYPE_NOT_LOADED),
  glUniform2ui(NULL), statusUniform2ui(NOpenGLProc::TYPE_NOT_LOADED),
  glUniform2uiv(NULL), statusUniform2uiv(NOpenGLProc::TYPE_NOT_LOADED),
  glUniform3ui(NULL), statusUniform3ui(NOpenGLProc::TYPE_NOT_LOADED),
  glUniform3uiv(NULL), statusUniform3uiv(NOpenGLProc::TYPE_NOT_LOADED),
  glUniform4ui(NULL), statusUniform4ui(NOpenGLProc::TYPE_NOT_LOADED),
  glUniform4uiv(NULL), statusUniform4uiv(NOpenGLProc::TYPE_NOT_LOADED),
  glVertexAttribI1i(NULL), statusVertexAttribI1i(NOpenGLProc::TYPE_NOT_LOADED),
  glVertexAttribI1iv(NULL), statusVertexAttribI1iv(NOpenGLProc::TYPE_NOT_LOADED),
  glVertexAttribI1ui(NULL), statusVertexAttribI1ui(NOpenGLProc::TYPE_NOT_LOADED),
  glVertexAttribI1uiv(NULL), statusVertexAttribI1uiv(NOpenGLProc::TYPE_NOT_LOADED),
  glVertexAttribI2i(NULL), statusVertexAttribI2i(NOpenGLProc::TYPE_NOT_LOADED),
  glVertexAttribI2iv(NULL), statusVertexAttribI2iv(NOpenGLProc::TYPE_NOT_LOADED),
  glVertexAttribI2ui(NULL), statusVertexAttribI2ui(NOpenGLProc::TYPE_NOT_LOADED),
  glVertexAttribI2uiv(NULL), statusVertexAttribI2uiv(NOpenGLProc::TYPE_NOT_LOADED),
  glVertexAttribI3i(NULL), statusVertexAttribI3i(NOpenGLProc::TYPE_NOT_LOADED),
  glVertexAttribI3iv(NULL), statusVertexAttribI3iv(NOpenGLProc::TYPE_NOT_LOADED),
  glVertexAttribI3ui(NULL), statusVertexAttribI3ui(NOpenGLProc::TYPE_NOT_LOADED),
  glVertexAttribI3uiv(NULL), statusVertexAttribI3uiv(NOpenGLProc::TYPE_NOT_LOADED),
  glVertexAttribI4bv(NULL), statusVertexAttribI4bv(NOpenGLProc::TYPE_NOT_LOADED),
  glVertexAttribI4i(NULL), statusVertexAttribI4i(NOpenGLProc::TYPE_NOT_LOADED),
  glVertexAttribI4iv(NULL), statusVertexAttribI4iv(NOpenGLProc::TYPE_NOT_LOADED),
  glVertexAttribI4sv(NULL), statusVertexAttribI4sv(NOpenGLProc::TYPE_NOT_LOADED),
  glVertexAttribI4ubv(NULL), statusVertexAttribI4ubv(NOpenGLProc::TYPE_NOT_LOADED),
  glVertexAttribI4ui(NULL), statusVertexAttribI4ui(NOpenGLProc::TYPE_NOT_LOADED),
  glVertexAttribI4uiv(NULL), statusVertexAttribI4uiv(NOpenGLProc::TYPE_NOT_LOADED),
  glVertexAttribI4usv(NULL), statusVertexAttribI4usv(NOpenGLProc::TYPE_NOT_LOADED),
  glVertexAttribIPointer(NULL), statusVertexAttribIPointer(NOpenGLProc::TYPE_NOT_LOADED),

  // GL_VERSION_3_1
  glCopyBufferSubData(NULL), statusCopyBufferSubData(NOpenGLProc::TYPE_NOT_LOADED),
  glDrawArraysInstanced(NULL), statusDrawArraysInstanced(NOpenGLProc::TYPE_NOT_LOADED),
  glDrawElementsInstanced(NULL), statusDrawElementsInstanced(NOpenGLProc::TYPE_NOT_LOADED),
  glGetActiveUniformBlockName(NULL), statusGetActiveUniformBlockName(NOpenGLProc::TYPE_NOT_LOADED),
  glGetActiveUniformBlockiv(NULL), statusGetActiveUniformBlockiv(NOpenGLProc::TYPE_NOT_LOADED),
  glGetActiveUniformName(NULL), statusGetActiveUniformName(NOpenGLProc::TYPE_NOT_LOADED),
  glGetActiveUniformsiv(NULL), statusGetActiveUniformsiv(NOpenGLProc::TYPE_NOT_LOADED),
  glGetUniformBlockIndex(NULL), statusGetUniformBlockIndex(NOpenGLProc::TYPE_NOT_LOADED),
  glGetUniformIndices(NULL), statusGetUniformIndices(NOpenGLProc::TYPE_NOT_LOADED),
  glPrimitiveRestartIndex(NULL), statusPrimitiveRestartIndex(NOpenGLProc::TYPE_NOT_LOADED),
  glTexBuffer(NULL), statusTexBuffer(NOpenGLProc::TYPE_NOT_LOADED),
  glUniformBlockBinding(NULL), statusUniformBlockBinding(NOpenGLProc::TYPE_NOT_LOADED),

  // GL_VERSION_3_2
  glClientWaitSync(NULL), statusClientWaitSync(NOpenGLProc::TYPE_NOT_LOADED),
  glDeleteSync(NULL), statusDeleteSync(NOpenGLProc::TYPE_NOT_LOADED),
  glDrawElementsBaseVertex(NULL), statusDrawElementsBaseVertex(NOpenGLProc::TYPE_NOT_LOADED),
  glDrawElementsInstancedBaseVertex(NULL), statusDrawElementsInstancedBaseVertex(NOpenGLProc::TYPE_NOT_LOADED),
  glDrawRangeElementsBaseVertex(NULL), statusDrawRangeElementsBaseVertex(NOpenGLProc::TYPE_NOT_LOADED),
  glFenceSync(NULL), statusFenceSync(NOpenGLProc::TYPE_NOT_LOADED),
  glFramebufferTexture(NULL), statusFramebufferTexture(NOpenGLProc::TYPE_NOT_LOADED),
  glGetBufferParameteri64v(NULL), statusGetBufferParameteri64v(NOpenGLProc::TYPE_NOT_LOADED),
  glGetInteger64i_v(NULL), statusGetInteger64i_v(NOpenGLProc::TYPE_NOT_LOADED),
  glGetInteger64v(NULL), statusGetInteger64v(NOpenGLProc::TYPE_NOT_LOADED),
  glGetMultisamplefv(NULL), statusGetMultisamplefv(NOpenGLProc::TYPE_NOT_LOADED),
  glGetSynciv(NULL), statusGetSynciv(NOpenGLProc::TYPE_NOT_LOADED),
  glIsSync(NULL), statusIsSync(NOpenGLProc::TYPE_NOT_LOADED),
  glMultiDrawElementsBaseVertex(NULL), statusMultiDrawElementsBaseVertex(NOpenGLProc::TYPE_NOT_LOADED),
  glProvokingVertex(NULL), statusProvokingVertex(NOpenGLProc::TYPE_NOT_LOADED),
  glSampleMaski(NULL), statusSampleMaski(NOpenGLProc::TYPE_NOT_LOADED),
  glTexImage2DMultisample(NULL), statusTexImage2DMultisample(NOpenGLProc::TYPE_NOT_LOADED),
  glTexImage3DMultisample(NULL), statusTexImage3DMultisample(NOpenGLProc::TYPE_NOT_LOADED),
  glWaitSync(NULL), statusWaitSync(NOpenGLProc::TYPE_NOT_LOADED),

  // GL_VERSION_3_3
  glBindFragDataLocationIndexed(NULL), statusBindFragDataLocationIndexed(NOpenGLProc::TYPE_NOT_LOADED),
  glBindSampler(NULL), statusBindSampler(NOpenGLProc::TYPE_NOT_LOADED),
  glDeleteSamplers(NULL), statusDeleteSamplers(NOpenGLProc::TYPE_NOT_LOADED),
  glGenSamplers(NULL), statusGenSamplers(NOpenGLProc::TYPE_NOT_LOADED),
  glGetFragDataIndex(NULL), statusGetFragDataIndex(NOpenGLProc::TYPE_NOT_LOADED),
  glGetQueryObjecti64v(NULL), statusGetQueryObjecti64v(NOpenGLProc::TYPE_NOT_LOADED),
  glGetQueryObjectui64v(NULL), statusGetQueryObjectui64v(NOpenGLProc::TYPE_NOT_LOADED),
  glGetSamplerParameterIiv(NULL), statusGetSamplerParameterIiv(NOpenGLProc::TYPE_NOT_LOADED),
  glGetSamplerParameterIuiv(NULL), statusGetSamplerParameterIuiv(NOpenGLProc::TYPE_NOT_LOADED),
  glGetSamplerParameterfv(NULL), statusGetSamplerParameterfv(NOpenGLProc::TYPE_NOT_LOADED),
  glGetSamplerParameteriv(NULL), statusGetSamplerParameteriv(NOpenGLProc::TYPE_NOT_LOADED),
  glIsSampler(NULL), statusIsSampler(NOpenGLProc::TYPE_NOT_LOADED),
  glQueryCounter(NULL), statusQueryCounter(NOpenGLProc::TYPE_NOT_LOADED),
  glSamplerParameterIiv(NULL), statusSamplerParameterIiv(NOpenGLProc::TYPE_NOT_LOADED),
  glSamplerParameterIuiv(NULL), statusSamplerParameterIuiv(NOpenGLProc::TYPE_NOT_LOADED),
  glSamplerParameterf(NULL), statusSamplerParameterf(NOpenGLProc::TYPE_NOT_LOADED),
  glSamplerParameterfv(NULL), statusSamplerParameterfv(NOpenGLProc::TYPE_NOT_LOADED),
  glSamplerParameteri(NULL), statusSamplerParameteri(NOpenGLProc::TYPE_NOT_LOADED),
  glSamplerParameteriv(NULL), statusSamplerParameteriv(NOpenGLProc::TYPE_NOT_LOADED),
  glVertexAttribDivisor(NULL), statusVertexAttribDivisor(NOpenGLProc::TYPE_NOT_LOADED),
  glVertexAttribP1ui(NULL), statusVertexAttribP1ui(NOpenGLProc::TYPE_NOT_LOADED),
  glVertexAttribP1uiv(NULL), statusVertexAttribP1uiv(NOpenGLProc::TYPE_NOT_LOADED),
  glVertexAttribP2ui(NULL), statusVertexAttribP2ui(NOpenGLProc::TYPE_NOT_LOADED),
  glVertexAttribP2uiv(NULL), statusVertexAttribP2uiv(NOpenGLProc::TYPE_NOT_LOADED),
  glVertexAttribP3ui(NULL), statusVertexAttribP3ui(NOpenGLProc::TYPE_NOT_LOADED),
  glVertexAttribP3uiv(NULL), statusVertexAttribP3uiv(NOpenGLProc::TYPE_NOT_LOADED),
  glVertexAttribP4ui(NULL), statusVertexAttribP4ui(NOpenGLProc::TYPE_NOT_LOADED),
  glVertexAttribP4uiv(NULL), statusVertexAttribP4uiv(NOpenGLProc::TYPE_NOT_LOADED),

  // GL_VERSION_4_0
  glBeginQueryIndexed(NULL), statusBeginQueryIndexed(NOpenGLProc::TYPE_NOT_LOADED),
  glBindTransformFeedback(NULL), statusBindTransformFeedback(NOpenGLProc::TYPE_NOT_LOADED),
  glBlendEquationSeparatei(NULL), statusBlendEquationSeparatei(NOpenGLProc::TYPE_NOT_LOADED),
  glBlendEquationi(NULL), statusBlendEquationi(NOpenGLProc::TYPE_NOT_LOADED),
  glBlendFuncSeparatei(NULL), statusBlendFuncSeparatei(NOpenGLProc::TYPE_NOT_LOADED),
  glBlendFunci(NULL), statusBlendFunci(NOpenGLProc::TYPE_NOT_LOADED),
  glDeleteTransformFeedbacks(NULL), statusDeleteTransformFeedbacks(NOpenGLProc::TYPE_NOT_LOADED),
  glDrawArraysIndirect(NULL), statusDrawArraysIndirect(NOpenGLProc::TYPE_NOT_LOADED),
  glDrawElementsIndirect(NULL), statusDrawElementsIndirect(NOpenGLProc::TYPE_NOT_LOADED),
  glDrawTransformFeedback(NULL), statusDrawTransformFeedback(NOpenGLProc::TYPE_NOT_LOADED),
  glDrawTransformFeedbackStream(NULL), statusDrawTransformFeedbackStream(NOpenGLProc::TYPE_NOT_LOADED),
  glEndQueryIndexed(NULL), statusEndQueryIndexed(NOpenGLProc::TYPE_NOT_LOADED),
  glGenTransformFeedbacks(NULL), statusGenTransformFeedbacks(NOpenGLProc::TYPE_NOT_LOADED),
  glGetActiveSubroutineName(NULL), statusGetActiveSubroutineName(NOpenGLProc::TYPE_NOT_LOADED),
  glGetActiveSubroutineUniformName(NULL), statusGetActiveSubroutineUniformName(NOpenGLProc::TYPE_NOT_LOADED),
  glGetActiveSubroutineUniformiv(NULL), statusGetActiveSubroutineUniformiv(NOpenGLProc::TYPE_NOT_LOADED),
  glGetProgramStageiv(NULL), statusGetProgramStageiv(NOpenGLProc::TYPE_NOT_LOADED),
  glGetQueryIndexediv(NULL), statusGetQueryIndexediv(NOpenGLProc::TYPE_NOT_LOADED),
  glGetSubroutineIndex(NULL), statusGetSubroutineIndex(NOpenGLProc::TYPE_NOT_LOADED),
  glGetSubroutineUniformLocation(NULL), statusGetSubroutineUniformLocation(NOpenGLProc::TYPE_NOT_LOADED),
  glGetUniformSubroutineuiv(NULL), statusGetUniformSubroutineuiv(NOpenGLProc::TYPE_NOT_LOADED),
  glGetUniformdv(NULL), statusGetUniformdv(NOpenGLProc::TYPE_NOT_LOADED),
  glIsTransformFeedback(NULL), statusIsTransformFeedback(NOpenGLProc::TYPE_NOT_LOADED),
  glMinSampleShading(NULL), statusMinSampleShading(NOpenGLProc::TYPE_NOT_LOADED),
  glPatchParameterfv(NULL), statusPatchParameterfv(NOpenGLProc::TYPE_NOT_LOADED),
  glPatchParameteri(NULL), statusPatchParameteri(NOpenGLProc::TYPE_NOT_LOADED),
  glPauseTransformFeedback(NULL), statusPauseTransformFeedback(NOpenGLProc::TYPE_NOT_LOADED),
  glResumeTransformFeedback(NULL), statusResumeTransformFeedback(NOpenGLProc::TYPE_NOT_LOADED),
  glUniform1d(NULL), statusUniform1d(NOpenGLProc::TYPE_NOT_LOADED),
  glUniform1dv(NULL), statusUniform1dv(NOpenGLProc::TYPE_NOT_LOADED),
  glUniform2d(NULL), statusUniform2d(NOpenGLProc::TYPE_NOT_LOADED),
  glUniform2dv(NULL), statusUniform2dv(NOpenGLProc::TYPE_NOT_LOADED),
  glUniform3d(NULL), statusUniform3d(NOpenGLProc::TYPE_NOT_LOADED),
  glUniform3dv(NULL), statusUniform3dv(NOpenGLProc::TYPE_NOT_LOADED),
  glUniform4d(NULL), statusUniform4d(NOpenGLProc::TYPE_NOT_LOADED),
  glUniform4dv(NULL), statusUniform4dv(NOpenGLProc::TYPE_NOT_LOADED),
  glUniformMatrix2dv(NULL), statusUniformMatrix2dv(NOpenGLProc::TYPE_NOT_LOADED),
  glUniformMatrix2x3dv(NULL), statusUniformMatrix2x3dv(NOpenGLProc::TYPE_NOT_LOADED),
  glUniformMatrix2x4dv(NULL), statusUniformMatrix2x4dv(NOpenGLProc::TYPE_NOT_LOADED),
  glUniformMatrix3dv(NULL), statusUniformMatrix3dv(NOpenGLProc::TYPE_NOT_LOADED),
  glUniformMatrix3x2dv(NULL), statusUniformMatrix3x2dv(NOpenGLProc::TYPE_NOT_LOADED),
  glUniformMatrix3x4dv(NULL), statusUniformMatrix3x4dv(NOpenGLProc::TYPE_NOT_LOADED),
  glUniformMatrix4dv(NULL), statusUniformMatrix4dv(NOpenGLProc::TYPE_NOT_LOADED),
  glUniformMatrix4x2dv(NULL), statusUniformMatrix4x2dv(NOpenGLProc::TYPE_NOT_LOADED),
  glUniformMatrix4x3dv(NULL), statusUniformMatrix4x3dv(NOpenGLProc::TYPE_NOT_LOADED),
  glUniformSubroutinesuiv(NULL), statusUniformSubroutinesuiv(NOpenGLProc::TYPE_NOT_LOADED),

  // GL_VERSION_4_1
  glActiveShaderProgram(NULL), statusActiveShaderProgram(NOpenGLProc::TYPE_NOT_LOADED),
  glBindProgramPipeline(NULL), statusBindProgramPipeline(NOpenGLProc::TYPE_NOT_LOADED),
  glClearDepthf(NULL), statusClearDepthf(NOpenGLProc::TYPE_NOT_LOADED),
  glCreateShaderProgramv(NULL), statusCreateShaderProgramv(NOpenGLProc::TYPE_NOT_LOADED),
  glDeleteProgramPipelines(NULL), statusDeleteProgramPipelines(NOpenGLProc::TYPE_NOT_LOADED),
  glDepthRangeArrayv(NULL), statusDepthRangeArrayv(NOpenGLProc::TYPE_NOT_LOADED),
  glDepthRangeIndexed(NULL), statusDepthRangeIndexed(NOpenGLProc::TYPE_NOT_LOADED),
  glDepthRangef(NULL), statusDepthRangef(NOpenGLProc::TYPE_NOT_LOADED),
  glGenProgramPipelines(NULL), statusGenProgramPipelines(NOpenGLProc::TYPE_NOT_LOADED),
  glGetDoublei_v(NULL), statusGetDoublei_v(NOpenGLProc::TYPE_NOT_LOADED),
  glGetFloati_v(NULL), statusGetFloati_v(NOpenGLProc::TYPE_NOT_LOADED),
  glGetProgramBinary(NULL), statusGetProgramBinary(NOpenGLProc::TYPE_NOT_LOADED),
  glGetProgramPipelineInfoLog(NULL), statusGetProgramPipelineInfoLog(NOpenGLProc::TYPE_NOT_LOADED),
  glGetProgramPipelineiv(NULL), statusGetProgramPipelineiv(NOpenGLProc::TYPE_NOT_LOADED),
  glGetShaderPrecisionFormat(NULL), statusGetShaderPrecisionFormat(NOpenGLProc::TYPE_NOT_LOADED),
  glGetVertexAttribLdv(NULL), statusGetVertexAttribLdv(NOpenGLProc::TYPE_NOT_LOADED),
  glIsProgramPipeline(NULL), statusIsProgramPipeline(NOpenGLProc::TYPE_NOT_LOADED),
  glProgramBinary(NULL), statusProgramBinary(NOpenGLProc::TYPE_NOT_LOADED),
  glProgramParameteri(NULL), statusProgramParameteri(NOpenGLProc::TYPE_NOT_LOADED),
  glProgramUniform1d(NULL), statusProgramUniform1d(NOpenGLProc::TYPE_NOT_LOADED),
  glProgramUniform1dv(NULL), statusProgramUniform1dv(NOpenGLProc::TYPE_NOT_LOADED),
  glProgramUniform1f(NULL), statusProgramUniform1f(NOpenGLProc::TYPE_NOT_LOADED),
  glProgramUniform1fv(NULL), statusProgramUniform1fv(NOpenGLProc::TYPE_NOT_LOADED),
  glProgramUniform1i(NULL), statusProgramUniform1i(NOpenGLProc::TYPE_NOT_LOADED),
  glProgramUniform1iv(NULL), statusProgramUniform1iv(NOpenGLProc::TYPE_NOT_LOADED),
  glProgramUniform1ui(NULL), statusProgramUniform1ui(NOpenGLProc::TYPE_NOT_LOADED),
  glProgramUniform1uiv(NULL), statusProgramUniform1uiv(NOpenGLProc::TYPE_NOT_LOADED),
  glProgramUniform2d(NULL), statusProgramUniform2d(NOpenGLProc::TYPE_NOT_LOADED),
  glProgramUniform2dv(NULL), statusProgramUniform2dv(NOpenGLProc::TYPE_NOT_LOADED),
  glProgramUniform2f(NULL), statusProgramUniform2f(NOpenGLProc::TYPE_NOT_LOADED),
  glProgramUniform2fv(NULL), statusProgramUniform2fv(NOpenGLProc::TYPE_NOT_LOADED),
  glProgramUniform2i(NULL), statusProgramUniform2i(NOpenGLProc::TYPE_NOT_LOADED),
  glProgramUniform2iv(NULL), statusProgramUniform2iv(NOpenGLProc::TYPE_NOT_LOADED),
  glProgramUniform2ui(NULL), statusProgramUniform2ui(NOpenGLProc::TYPE_NOT_LOADED),
  glProgramUniform2uiv(NULL), statusProgramUniform2uiv(NOpenGLProc::TYPE_NOT_LOADED),
  glProgramUniform3d(NULL), statusProgramUniform3d(NOpenGLProc::TYPE_NOT_LOADED),
  glProgramUniform3dv(NULL), statusProgramUniform3dv(NOpenGLProc::TYPE_NOT_LOADED),
  glProgramUniform3f(NULL), statusProgramUniform3f(NOpenGLProc::TYPE_NOT_LOADED),
  glProgramUniform3fv(NULL), statusProgramUniform3fv(NOpenGLProc::TYPE_NOT_LOADED),
  glProgramUniform3i(NULL), statusProgramUniform3i(NOpenGLProc::TYPE_NOT_LOADED),
  glProgramUniform3iv(NULL), statusProgramUniform3iv(NOpenGLProc::TYPE_NOT_LOADED),
  glProgramUniform3ui(NULL), statusProgramUniform3ui(NOpenGLProc::TYPE_NOT_LOADED),
  glProgramUniform3uiv(NULL), statusProgramUniform3uiv(NOpenGLProc::TYPE_NOT_LOADED),
  glProgramUniform4d(NULL), statusProgramUniform4d(NOpenGLProc::TYPE_NOT_LOADED),
  glProgramUniform4dv(NULL), statusProgramUniform4dv(NOpenGLProc::TYPE_NOT_LOADED),
  glProgramUniform4f(NULL), statusProgramUniform4f(NOpenGLProc::TYPE_NOT_LOADED),
  glProgramUniform4fv(NULL), statusProgramUniform4fv(NOpenGLProc::TYPE_NOT_LOADED),
  glProgramUniform4i(NULL), statusProgramUniform4i(NOpenGLProc::TYPE_NOT_LOADED),
  glProgramUniform4iv(NULL), statusProgramUniform4iv(NOpenGLProc::TYPE_NOT_LOADED),
  glProgramUniform4ui(NULL), statusProgramUniform4ui(NOpenGLProc::TYPE_NOT_LOADED),
  glProgramUniform4uiv(NULL), statusProgramUniform4uiv(NOpenGLProc::TYPE_NOT_LOADED),
  glProgramUniformMatrix2dv(NULL), statusProgramUniformMatrix2dv(NOpenGLProc::TYPE_NOT_LOADED),
  glProgramUniformMatrix2fv(NULL), statusProgramUniformMatrix2fv(NOpenGLProc::TYPE_NOT_LOADED),
  glProgramUniformMatrix2x3dv(NULL), statusProgramUniformMatrix2x3dv(NOpenGLProc::TYPE_NOT_LOADED),
  glProgramUniformMatrix2x3fv(NULL), statusProgramUniformMatrix2x3fv(NOpenGLProc::TYPE_NOT_LOADED),
  glProgramUniformMatrix2x4dv(NULL), statusProgramUniformMatrix2x4dv(NOpenGLProc::TYPE_NOT_LOADED),
  glProgramUniformMatrix2x4fv(NULL), statusProgramUniformMatrix2x4fv(NOpenGLProc::TYPE_NOT_LOADED),
  glProgramUniformMatrix3dv(NULL), statusProgramUniformMatrix3dv(NOpenGLProc::TYPE_NOT_LOADED),
  glProgramUniformMatrix3fv(NULL), statusProgramUniformMatrix3fv(NOpenGLProc::TYPE_NOT_LOADED),
  glProgramUniformMatrix3x2dv(NULL), statusProgramUniformMatrix3x2dv(NOpenGLProc::TYPE_NOT_LOADED),
  glProgramUniformMatrix3x2fv(NULL), statusProgramUniformMatrix3x2fv(NOpenGLProc::TYPE_NOT_LOADED),
  glProgramUniformMatrix3x4dv(NULL), statusProgramUniformMatrix3x4dv(NOpenGLProc::TYPE_NOT_LOADED),
  glProgramUniformMatrix3x4fv(NULL), statusProgramUniformMatrix3x4fv(NOpenGLProc::TYPE_NOT_LOADED),
  glProgramUniformMatrix4dv(NULL), statusProgramUniformMatrix4dv(NOpenGLProc::TYPE_NOT_LOADED),
  glProgramUniformMatrix4fv(NULL), statusProgramUniformMatrix4fv(NOpenGLProc::TYPE_NOT_LOADED),
  glProgramUniformMatrix4x2dv(NULL), statusProgramUniformMatrix4x2dv(NOpenGLProc::TYPE_NOT_LOADED),
  glProgramUniformMatrix4x2fv(NULL), statusProgramUniformMatrix4x2fv(NOpenGLProc::TYPE_NOT_LOADED),
  glProgramUniformMatrix4x3dv(NULL), statusProgramUniformMatrix4x3dv(NOpenGLProc::TYPE_NOT_LOADED),
  glProgramUniformMatrix4x3fv(NULL), statusProgramUniformMatrix4x3fv(NOpenGLProc::TYPE_NOT_LOADED),
  glReleaseShaderCompiler(NULL), statusReleaseShaderCompiler(NOpenGLProc::TYPE_NOT_LOADED),
  glScissorArrayv(NULL), statusScissorArrayv(NOpenGLProc::TYPE_NOT_LOADED),
  glScissorIndexed(NULL), statusScissorIndexed(NOpenGLProc::TYPE_NOT_LOADED),
  glScissorIndexedv(NULL), statusScissorIndexedv(NOpenGLProc::TYPE_NOT_LOADED),
  glShaderBinary(NULL), statusShaderBinary(NOpenGLProc::TYPE_NOT_LOADED),
  glUseProgramStages(NULL), statusUseProgramStages(NOpenGLProc::TYPE_NOT_LOADED),
  glValidateProgramPipeline(NULL), statusValidateProgramPipeline(NOpenGLProc::TYPE_NOT_LOADED),
  glVertexAttribL1d(NULL), statusVertexAttribL1d(NOpenGLProc::TYPE_NOT_LOADED),
  glVertexAttribL1dv(NULL), statusVertexAttribL1dv(NOpenGLProc::TYPE_NOT_LOADED),
  glVertexAttribL2d(NULL), statusVertexAttribL2d(NOpenGLProc::TYPE_NOT_LOADED),
  glVertexAttribL2dv(NULL), statusVertexAttribL2dv(NOpenGLProc::TYPE_NOT_LOADED),
  glVertexAttribL3d(NULL), statusVertexAttribL3d(NOpenGLProc::TYPE_NOT_LOADED),
  glVertexAttribL3dv(NULL), statusVertexAttribL3dv(NOpenGLProc::TYPE_NOT_LOADED),
  glVertexAttribL4d(NULL), statusVertexAttribL4d(NOpenGLProc::TYPE_NOT_LOADED),
  glVertexAttribL4dv(NULL), statusVertexAttribL4dv(NOpenGLProc::TYPE_NOT_LOADED),
  glVertexAttribLPointer(NULL), statusVertexAttribLPointer(NOpenGLProc::TYPE_NOT_LOADED),
  glViewportArrayv(NULL), statusViewportArrayv(NOpenGLProc::TYPE_NOT_LOADED),
  glViewportIndexedf(NULL), statusViewportIndexedf(NOpenGLProc::TYPE_NOT_LOADED),
  glViewportIndexedfv(NULL), statusViewportIndexedfv(NOpenGLProc::TYPE_NOT_LOADED),

  // GL_VERSION_4_2
  glBindImageTexture(NULL), statusBindImageTexture(NOpenGLProc::TYPE_NOT_LOADED),
  glDrawArraysInstancedBaseInstance(NULL), statusDrawArraysInstancedBaseInstance(NOpenGLProc::TYPE_NOT_LOADED),
  glDrawElementsInstancedBaseInstance(NULL), statusDrawElementsInstancedBaseInstance(NOpenGLProc::TYPE_NOT_LOADED),
  glDrawElementsInstancedBaseVertexBaseInstance(NULL), statusDrawElementsInstancedBaseVertexBaseInstance(NOpenGLProc::TYPE_NOT_LOADED),
  glDrawTransformFeedbackInstanced(NULL), statusDrawTransformFeedbackInstanced(NOpenGLProc::TYPE_NOT_LOADED),
  glDrawTransformFeedbackStreamInstanced(NULL), statusDrawTransformFeedbackStreamInstanced(NOpenGLProc::TYPE_NOT_LOADED),
  glGetActiveAtomicCounterBufferiv(NULL), statusGetActiveAtomicCounterBufferiv(NOpenGLProc::TYPE_NOT_LOADED),
  glGetInternalformativ(NULL), statusGetInternalformativ(NOpenGLProc::TYPE_NOT_LOADED),
  glMemoryBarrier(NULL), statusMemoryBarrier(NOpenGLProc::TYPE_NOT_LOADED),
  glTexStorage1D(NULL), statusTexStorage1D(NOpenGLProc::TYPE_NOT_LOADED),
  glTexStorage2D(NULL), statusTexStorage2D(NOpenGLProc::TYPE_NOT_LOADED),
  glTexStorage3D(NULL), statusTexStorage3D(NOpenGLProc::TYPE_NOT_LOADED),

  // GL_VERSION_4_3
  glBindVertexBuffer(NULL), statusBindVertexBuffer(NOpenGLProc::TYPE_NOT_LOADED),
  glClearBufferData(NULL), statusClearBufferData(NOpenGLProc::TYPE_NOT_LOADED),
  glClearBufferSubData(NULL), statusClearBufferSubData(NOpenGLProc::TYPE_NOT_LOADED),
  glCopyImageSubData(NULL), statusCopyImageSubData(NOpenGLProc::TYPE_NOT_LOADED),
  glDebugMessageCallback(NULL), statusDebugMessageCallback(NOpenGLProc::TYPE_NOT_LOADED),
  glDebugMessageControl(NULL), statusDebugMessageControl(NOpenGLProc::TYPE_NOT_LOADED),
  glDebugMessageInsert(NULL), statusDebugMessageInsert(NOpenGLProc::TYPE_NOT_LOADED),
  glDispatchCompute(NULL), statusDispatchCompute(NOpenGLProc::TYPE_NOT_LOADED),
  glDispatchComputeIndirect(NULL), statusDispatchComputeIndirect(NOpenGLProc::TYPE_NOT_LOADED),
  glFramebufferParameteri(NULL), statusFramebufferParameteri(NOpenGLProc::TYPE_NOT_LOADED),
  glGetDebugMessageLog(NULL), statusGetDebugMessageLog(NOpenGLProc::TYPE_NOT_LOADED),
  glGetFramebufferParameteriv(NULL), statusGetFramebufferParameteriv(NOpenGLProc::TYPE_NOT_LOADED),
  glGetInternalformati64v(NULL), statusGetInternalformati64v(NOpenGLProc::TYPE_NOT_LOADED),
  glGetObjectLabel(NULL), statusGetObjectLabel(NOpenGLProc::TYPE_NOT_LOADED),
  glGetObjectPtrLabel(NULL), statusGetObjectPtrLabel(NOpenGLProc::TYPE_NOT_LOADED),
  glGetProgramInterfaceiv(NULL), statusGetProgramInterfaceiv(NOpenGLProc::TYPE_NOT_LOADED),
  glGetProgramResourceIndex(NULL), statusGetProgramResourceIndex(NOpenGLProc::TYPE_NOT_LOADED),
  glGetProgramResourceLocation(NULL), statusGetProgramResourceLocation(NOpenGLProc::TYPE_NOT_LOADED),
  glGetProgramResourceLocationIndex(NULL), statusGetProgramResourceLocationIndex(NOpenGLProc::TYPE_NOT_LOADED),
  glGetProgramResourceName(NULL), statusGetProgramResourceName(NOpenGLProc::TYPE_NOT_LOADED),
  glGetProgramResourceiv(NULL), statusGetProgramResourceiv(NOpenGLProc::TYPE_NOT_LOADED),
  glInvalidateBufferData(NULL), statusInvalidateBufferData(NOpenGLProc::TYPE_NOT_LOADED),
  glInvalidateBufferSubData(NULL), statusInvalidateBufferSubData(NOpenGLProc::TYPE_NOT_LOADED),
  glInvalidateFramebuffer(NULL), statusInvalidateFramebuffer(NOpenGLProc::TYPE_NOT_LOADED),
  glInvalidateSubFramebuffer(NULL), statusInvalidateSubFramebuffer(NOpenGLProc::TYPE_NOT_LOADED),
  glInvalidateTexImage(NULL), statusInvalidateTexImage(NOpenGLProc::TYPE_NOT_LOADED),
  glInvalidateTexSubImage(NULL), statusInvalidateTexSubImage(NOpenGLProc::TYPE_NOT_LOADED),
  glMultiDrawArraysIndirect(NULL), statusMultiDrawArraysIndirect(NOpenGLProc::TYPE_NOT_LOADED),
  glMultiDrawElementsIndirect(NULL), statusMultiDrawElementsIndirect(NOpenGLProc::TYPE_NOT_LOADED),
  glObjectLabel(NULL), statusObjectLabel(NOpenGLProc::TYPE_NOT_LOADED),
  glObjectPtrLabel(NULL), statusObjectPtrLabel(NOpenGLProc::TYPE_NOT_LOADED),
  glPopDebugGroup(NULL), statusPopDebugGroup(NOpenGLProc::TYPE_NOT_LOADED),
  glPushDebugGroup(NULL), statusPushDebugGroup(NOpenGLProc::TYPE_NOT_LOADED),
  glShaderStorageBlockBinding(NULL), statusShaderStorageBlockBinding(NOpenGLProc::TYPE_NOT_LOADED),
  glTexBufferRange(NULL), statusTexBufferRange(NOpenGLProc::TYPE_NOT_LOADED),
  glTexStorage2DMultisample(NULL), statusTexStorage2DMultisample(NOpenGLProc::TYPE_NOT_LOADED),
  glTexStorage3DMultisample(NULL), statusTexStorage3DMultisample(NOpenGLProc::TYPE_NOT_LOADED),
  glTextureView(NULL), statusTextureView(NOpenGLProc::TYPE_NOT_LOADED),
  glVertexAttribBinding(NULL), statusVertexAttribBinding(NOpenGLProc::TYPE_NOT_LOADED),
  glVertexAttribFormat(NULL), statusVertexAttribFormat(NOpenGLProc::TYPE_NOT_LOADED),
  glVertexAttribIFormat(NULL), statusVertexAttribIFormat(NOpenGLProc::TYPE_NOT_LOADED),
  glVertexAttribLFormat(NULL), statusVertexAttribLFormat(NOpenGLProc::TYPE_NOT_LOADED),
  glVertexBindingDivisor(NULL), statusVertexBindingDivisor(NOpenGLProc::TYPE_NOT_LOADED),

  // GL_VERSION_4_4
  glBindBuffersBase(NULL), statusBindBuffersBase(NOpenGLProc::TYPE_NOT_LOADED),
  glBindBuffersRange(NULL), statusBindBuffersRange(NOpenGLProc::TYPE_NOT_LOADED),
  glBindImageTextures(NULL), statusBindImageTextures(NOpenGLProc::TYPE_NOT_LOADED),
  glBindSamplers(NULL), statusBindSamplers(NOpenGLProc::TYPE_NOT_LOADED),
  glBindTextures(NULL), statusBindTextures(NOpenGLProc::TYPE_NOT_LOADED),
  glBindVertexBuffers(NULL), statusBindVertexBuffers(NOpenGLProc::TYPE_NOT_LOADED),
  glBufferStorage(NULL), statusBufferStorage(NOpenGLProc::TYPE_NOT_LOADED),
  glClearTexImage(NULL), statusClearTexImage(NOpenGLProc::TYPE_NOT_LOADED),
  glClearTexSubImage(NULL), statusClearTexSubImage(NOpenGLProc::TYPE_NOT_LOADED),

  // GL_VERSION_4_5
  glBindTextureUnit(NULL), statusBindTextureUnit(NOpenGLProc::TYPE_NOT_LOADED),
  glBlitNamedFramebuffer(NULL), statusBlitNamedFramebuffer(NOpenGLProc::TYPE_NOT_LOADED),
  glCheckNamedFramebufferStatus(NULL), statusCheckNamedFramebufferStatus(NOpenGLProc::TYPE_NOT_LOADED),
  glClearNamedBufferData(NULL), statusClearNamedBufferData(NOpenGLProc::TYPE_NOT_LOADED),
  glClearNamedBufferSubData(NULL), statusClearNamedBufferSubData(NOpenGLProc::TYPE_NOT_LOADED),
  glClearNamedFramebufferfi(NULL), statusClearNamedFramebufferfi(NOpenGLProc::TYPE_NOT_LOADED),
  glClearNamedFramebufferfv(NULL), statusClearNamedFramebufferfv(NOpenGLProc::TYPE_NOT_LOADED),
  glClearNamedFramebufferiv(NULL), statusClearNamedFramebufferiv(NOpenGLProc::TYPE_NOT_LOADED),
  glClearNamedFramebufferuiv(NULL), statusClearNamedFramebufferuiv(NOpenGLProc::TYPE_NOT_LOADED),
  glClipControl(NULL), statusClipControl(NOpenGLProc::TYPE_NOT_LOADED),
  glCompressedTextureSubImage1D(NULL), statusCompressedTextureSubImage1D(NOpenGLProc::TYPE_NOT_LOADED),
  glCompressedTextureSubImage2D(NULL), statusCompressedTextureSubImage2D(NOpenGLProc::TYPE_NOT_LOADED),
  glCompressedTextureSubImage3D(NULL), statusCompressedTextureSubImage3D(NOpenGLProc::TYPE_NOT_LOADED),
  glCopyNamedBufferSubData(NULL), statusCopyNamedBufferSubData(NOpenGLProc::TYPE_NOT_LOADED),
  glCopyTextureSubImage1D(NULL), statusCopyTextureSubImage1D(NOpenGLProc::TYPE_NOT_LOADED),
  glCopyTextureSubImage2D(NULL), statusCopyTextureSubImage2D(NOpenGLProc::TYPE_NOT_LOADED),
  glCopyTextureSubImage3D(NULL), statusCopyTextureSubImage3D(NOpenGLProc::TYPE_NOT_LOADED),
  glCreateBuffers(NULL), statusCreateBuffers(NOpenGLProc::TYPE_NOT_LOADED),
  glCreateFramebuffers(NULL), statusCreateFramebuffers(NOpenGLProc::TYPE_NOT_LOADED),
  glCreateProgramPipelines(NULL), statusCreateProgramPipelines(NOpenGLProc::TYPE_NOT_LOADED),
  glCreateQueries(NULL), statusCreateQueries(NOpenGLProc::TYPE_NOT_LOADED),
  glCreateRenderbuffers(NULL), statusCreateRenderbuffers(NOpenGLProc::TYPE_NOT_LOADED),
  glCreateSamplers(NULL), statusCreateSamplers(NOpenGLProc::TYPE_NOT_LOADED),
  glCreateTextures(NULL), statusCreateTextures(NOpenGLProc::TYPE_NOT_LOADED),
  glCreateTransformFeedbacks(NULL), statusCreateTransformFeedbacks(NOpenGLProc::TYPE_NOT_LOADED),
  glCreateVertexArrays(NULL), statusCreateVertexArrays(NOpenGLProc::TYPE_NOT_LOADED),
  glDisableVertexArrayAttrib(NULL), statusDisableVertexArrayAttrib(NOpenGLProc::TYPE_NOT_LOADED),
  glEnableVertexArrayAttrib(NULL), statusEnableVertexArrayAttrib(NOpenGLProc::TYPE_NOT_LOADED),
  glFlushMappedNamedBufferRange(NULL), statusFlushMappedNamedBufferRange(NOpenGLProc::TYPE_NOT_LOADED),
  glGenerateTextureMipmap(NULL), statusGenerateTextureMipmap(NOpenGLProc::TYPE_NOT_LOADED),
  glGetCompressedTextureImage(NULL), statusGetCompressedTextureImage(NOpenGLProc::TYPE_NOT_LOADED),
  glGetCompressedTextureSubImage(NULL), statusGetCompressedTextureSubImage(NOpenGLProc::TYPE_NOT_LOADED),
  glGetGraphicsResetStatus(NULL), statusGetGraphicsResetStatus(NOpenGLProc::TYPE_NOT_LOADED),
  glGetNamedBufferParameteri64v(NULL), statusGetNamedBufferParameteri64v(NOpenGLProc::TYPE_NOT_LOADED),
  glGetNamedBufferParameteriv(NULL), statusGetNamedBufferParameteriv(NOpenGLProc::TYPE_NOT_LOADED),
  glGetNamedBufferPointerv(NULL), statusGetNamedBufferPointerv(NOpenGLProc::TYPE_NOT_LOADED),
  glGetNamedBufferSubData(NULL), statusGetNamedBufferSubData(NOpenGLProc::TYPE_NOT_LOADED),
  glGetNamedFramebufferAttachmentParameteriv(NULL), statusGetNamedFramebufferAttachmentParameteriv(NOpenGLProc::TYPE_NOT_LOADED),
  glGetNamedFramebufferParameteriv(NULL), statusGetNamedFramebufferParameteriv(NOpenGLProc::TYPE_NOT_LOADED),
  glGetNamedRenderbufferParameteriv(NULL), statusGetNamedRenderbufferParameteriv(NOpenGLProc::TYPE_NOT_LOADED),
  glGetQueryBufferObjecti64v(NULL), statusGetQueryBufferObjecti64v(NOpenGLProc::TYPE_NOT_LOADED),
  glGetQueryBufferObjectiv(NULL), statusGetQueryBufferObjectiv(NOpenGLProc::TYPE_NOT_LOADED),
  glGetQueryBufferObjectui64v(NULL), statusGetQueryBufferObjectui64v(NOpenGLProc::TYPE_NOT_LOADED),
  glGetQueryBufferObjectuiv(NULL), statusGetQueryBufferObjectuiv(NOpenGLProc::TYPE_NOT_LOADED),
  glGetTextureImage(NULL), statusGetTextureImage(NOpenGLProc::TYPE_NOT_LOADED),
  glGetTextureLevelParameterfv(NULL), statusGetTextureLevelParameterfv(NOpenGLProc::TYPE_NOT_LOADED),
  glGetTextureLevelParameteriv(NULL), statusGetTextureLevelParameteriv(NOpenGLProc::TYPE_NOT_LOADED),
  glGetTextureParameterIiv(NULL), statusGetTextureParameterIiv(NOpenGLProc::TYPE_NOT_LOADED),
  glGetTextureParameterIuiv(NULL), statusGetTextureParameterIuiv(NOpenGLProc::TYPE_NOT_LOADED),
  glGetTextureParameterfv(NULL), statusGetTextureParameterfv(NOpenGLProc::TYPE_NOT_LOADED),
  glGetTextureParameteriv(NULL), statusGetTextureParameteriv(NOpenGLProc::TYPE_NOT_LOADED),
  glGetTextureSubImage(NULL), statusGetTextureSubImage(NOpenGLProc::TYPE_NOT_LOADED),
  glGetTransformFeedbacki64_v(NULL), statusGetTransformFeedbacki64_v(NOpenGLProc::TYPE_NOT_LOADED),
  glGetTransformFeedbacki_v(NULL), statusGetTransformFeedbacki_v(NOpenGLProc::TYPE_NOT_LOADED),
  glGetTransformFeedbackiv(NULL), statusGetTransformFeedbackiv(NOpenGLProc::TYPE_NOT_LOADED),
  glGetVertexArrayIndexed64iv(NULL), statusGetVertexArrayIndexed64iv(NOpenGLProc::TYPE_NOT_LOADED),
  glGetVertexArrayIndexediv(NULL), statusGetVertexArrayIndexediv(NOpenGLProc::TYPE_NOT_LOADED),
  glGetVertexArrayiv(NULL), statusGetVertexArrayiv(NOpenGLProc::TYPE_NOT_LOADED),
  glGetnCompressedTexImage(NULL), statusGetnCompressedTexImage(NOpenGLProc::TYPE_NOT_LOADED),
  glGetnTexImage(NULL), statusGetnTexImage(NOpenGLProc::TYPE_NOT_LOADED),
  glGetnUniformdv(NULL), statusGetnUniformdv(NOpenGLProc::TYPE_NOT_LOADED),
  glGetnUniformfv(NULL), statusGetnUniformfv(NOpenGLProc::TYPE_NOT_LOADED),
  glGetnUniformiv(NULL), statusGetnUniformiv(NOpenGLProc::TYPE_NOT_LOADED),
  glGetnUniformuiv(NULL), statusGetnUniformuiv(NOpenGLProc::TYPE_NOT_LOADED),
  glInvalidateNamedFramebufferData(NULL), statusInvalidateNamedFramebufferData(NOpenGLProc::TYPE_NOT_LOADED),
  glInvalidateNamedFramebufferSubData(NULL), statusInvalidateNamedFramebufferSubData(NOpenGLProc::TYPE_NOT_LOADED),
  glMapNamedBuffer(NULL), statusMapNamedBuffer(NOpenGLProc::TYPE_NOT_LOADED),
  glMapNamedBufferRange(NULL), statusMapNamedBufferRange(NOpenGLProc::TYPE_NOT_LOADED),
  glMemoryBarrierByRegion(NULL), statusMemoryBarrierByRegion(NOpenGLProc::TYPE_NOT_LOADED),
  glNamedBufferData(NULL), statusNamedBufferData(NOpenGLProc::TYPE_NOT_LOADED),
  glNamedBufferStorage(NULL), statusNamedBufferStorage(NOpenGLProc::TYPE_NOT_LOADED),
  glNamedBufferSubData(NULL), statusNamedBufferSubData(NOpenGLProc::TYPE_NOT_LOADED),
  glNamedFramebufferDrawBuffer(NULL), statusNamedFramebufferDrawBuffer(NOpenGLProc::TYPE_NOT_LOADED),
  glNamedFramebufferDrawBuffers(NULL), statusNamedFramebufferDrawBuffers(NOpenGLProc::TYPE_NOT_LOADED),
  glNamedFramebufferParameteri(NULL), statusNamedFramebufferParameteri(NOpenGLProc::TYPE_NOT_LOADED),
  glNamedFramebufferReadBuffer(NULL), statusNamedFramebufferReadBuffer(NOpenGLProc::TYPE_NOT_LOADED),
  glNamedFramebufferRenderbuffer(NULL), statusNamedFramebufferRenderbuffer(NOpenGLProc::TYPE_NOT_LOADED),
  glNamedFramebufferTexture(NULL), statusNamedFramebufferTexture(NOpenGLProc::TYPE_NOT_LOADED),
  glNamedFramebufferTextureLayer(NULL), statusNamedFramebufferTextureLayer(NOpenGLProc::TYPE_NOT_LOADED),
  glNamedRenderbufferStorage(NULL), statusNamedRenderbufferStorage(NOpenGLProc::TYPE_NOT_LOADED),
  glNamedRenderbufferStorageMultisample(NULL), statusNamedRenderbufferStorageMultisample(NOpenGLProc::TYPE_NOT_LOADED),
  glReadnPixels(NULL), statusReadnPixels(NOpenGLProc::TYPE_NOT_LOADED),
  glTextureBarrier(NULL), statusTextureBarrier(NOpenGLProc::TYPE_NOT_LOADED),
  glTextureBuffer(NULL), statusTextureBuffer(NOpenGLProc::TYPE_NOT_LOADED),
  glTextureBufferRange(NULL), statusTextureBufferRange(NOpenGLProc::TYPE_NOT_LOADED),
  glTextureParameterIiv(NULL), statusTextureParameterIiv(NOpenGLProc::TYPE_NOT_LOADED),
  glTextureParameterIuiv(NULL), statusTextureParameterIuiv(NOpenGLProc::TYPE_NOT_LOADED),
  glTextureParameterf(NULL), statusTextureParameterf(NOpenGLProc::TYPE_NOT_LOADED),
  glTextureParameterfv(NULL), statusTextureParameterfv(NOpenGLProc::TYPE_NOT_LOADED),
  glTextureParameteri(NULL), statusTextureParameteri(NOpenGLProc::TYPE_NOT_LOADED),
  glTextureParameteriv(NULL), statusTextureParameteriv(NOpenGLProc::TYPE_NOT_LOADED),
  glTextureStorage1D(NULL), statusTextureStorage1D(NOpenGLProc::TYPE_NOT_LOADED),
  glTextureStorage2D(NULL), statusTextureStorage2D(NOpenGLProc::TYPE_NOT_LOADED),
  glTextureStorage2DMultisample(NULL), statusTextureStorage2DMultisample(NOpenGLProc::TYPE_NOT_LOADED),
  glTextureStorage3D(NULL), statusTextureStorage3D(NOpenGLProc::TYPE_NOT_LOADED),
  glTextureStorage3DMultisample(NULL), statusTextureStorage3DMultisample(NOpenGLProc::TYPE_NOT_LOADED),
  glTextureSubImage1D(NULL), statusTextureSubImage1D(NOpenGLProc::TYPE_NOT_LOADED),
  glTextureSubImage2D(NULL), statusTextureSubImage2D(NOpenGLProc::TYPE_NOT_LOADED),
  glTextureSubImage3D(NULL), statusTextureSubImage3D(NOpenGLProc::TYPE_NOT_LOADED),
  glTransformFeedbackBufferBase(NULL), statusTransformFeedbackBufferBase(NOpenGLProc::TYPE_NOT_LOADED),
  glTransformFeedbackBufferRange(NULL), statusTransformFeedbackBufferRange(NOpenGLProc::TYPE_NOT_LOADED),
  glUnmapNamedBuffer(NULL), statusUnmapNamedBuffer(NOpenGLProc::TYPE_NOT_LOADED),
  glVertexArrayAttribBinding(NULL), statusVertexArrayAttribBinding(NOpenGLProc::TYPE_NOT_LOADED),
  glVertexArrayAttribFormat(NULL), statusVertexArrayAttribFormat(NOpenGLProc::TYPE_NOT_LOADED),
  glVertexArrayAttribIFormat(NULL), statusVertexArrayAttribIFormat(NOpenGLProc::TYPE_NOT_LOADED),
  glVertexArrayAttribLFormat(NULL), statusVertexArrayAttribLFormat(NOpenGLProc::TYPE_NOT_LOADED),
  glVertexArrayBindingDivisor(NULL), statusVertexArrayBindingDivisor(NOpenGLProc::TYPE_NOT_LOADED),
  glVertexArrayElementBuffer(NULL), statusVertexArrayElementBuffer(NOpenGLProc::TYPE_NOT_LOADED),
  glVertexArrayVertexBuffer(NULL), statusVertexArrayVertexBuffer(NOpenGLProc::TYPE_NOT_LOADED),
  glVertexArrayVertexBuffers(NULL), statusVertexArrayVertexBuffers(NOpenGLProc::TYPE_NOT_LOADED)
{
}
//------------------------------------------------------------------------------
COpenGL::~COpenGL()
{
}
//------------------------------------------------------------------------------
void COpenGL::initializeGLFunctions(NEngine::EGPUPlatform explicitPlatofrm)
{
  const NEngine::EGPUPlatform platform = (explicitPlatofrm == NEngine::GPU_PLATFORM_KEEP) ? context->engineGetEngine()->gpuPlatform : explicitPlatofrm;

  context->log("Loading OpenGL Functions...");

  // GL_VERSION_1_2
  if(platform >= NEngine::GPU_PLATFORM_GL0102)
  {
    LOAD_GL_EXTENSION(glCopyTexSubImage3D, statusCopyTexSubImage3D, NOpenGLProc::TCopyTexSubImage3D, "glCopyTexSubImage3D", "glCopyTexSubImage3DARB", "glCopyTexSubImage3DEXT");
    LOAD_GL_EXTENSION(glDrawRangeElements, statusDrawRangeElements, NOpenGLProc::TDrawRangeElements, "glDrawRangeElements", "glDrawRangeElementsARB", "glDrawRangeElementsEXT");
    LOAD_GL_EXTENSION(glTexImage3D, statusTexImage3D, NOpenGLProc::TTexImage3D, "glTexImage3D", "glTexImage3DARB", "glTexImage3DEXT");
    LOAD_GL_EXTENSION(glTexSubImage3D, statusTexSubImage3D, NOpenGLProc::TTexSubImage3D, "glTexSubImage3D", "glTexSubImage3DARB", "glTexSubImage3DEXT");
  }

  // GL_VERSION_1_3
  if(platform >= NEngine::GPU_PLATFORM_GL0103)
  {
    LOAD_GL_EXTENSION(glActiveTexture, statusActiveTexture, NOpenGLProc::TActiveTexture, "glActiveTexture", "glActiveTextureARB", "glActiveTextureEXT");
    LOAD_GL_EXTENSION(glCompressedTexImage1D, statusCompressedTexImage1D, NOpenGLProc::TCompressedTexImage1D, "glCompressedTexImage1D", "glCompressedTexImage1DARB", "glCompressedTexImage1DEXT");
    LOAD_GL_EXTENSION(glCompressedTexImage2D, statusCompressedTexImage2D, NOpenGLProc::TCompressedTexImage2D, "glCompressedTexImage2D", "glCompressedTexImage2DARB", "glCompressedTexImage2DEXT");
    LOAD_GL_EXTENSION(glCompressedTexImage3D, statusCompressedTexImage3D, NOpenGLProc::TCompressedTexImage3D, "glCompressedTexImage3D", "glCompressedTexImage3DARB", "glCompressedTexImage3DEXT");
    LOAD_GL_EXTENSION(glCompressedTexSubImage1D, statusCompressedTexSubImage1D, NOpenGLProc::TCompressedTexSubImage1D, "glCompressedTexSubImage1D", "glCompressedTexSubImage1DARB", "glCompressedTexSubImage1DEXT");
    LOAD_GL_EXTENSION(glCompressedTexSubImage2D, statusCompressedTexSubImage2D, NOpenGLProc::TCompressedTexSubImage2D, "glCompressedTexSubImage2D", "glCompressedTexSubImage2DARB", "glCompressedTexSubImage2DEXT");
    LOAD_GL_EXTENSION(glCompressedTexSubImage3D, statusCompressedTexSubImage3D, NOpenGLProc::TCompressedTexSubImage3D, "glCompressedTexSubImage3D", "glCompressedTexSubImage3DARB", "glCompressedTexSubImage3DEXT");
    LOAD_GL_EXTENSION(glGetCompressedTexImage, statusGetCompressedTexImage, NOpenGLProc::TGetCompressedTexImage, "glGetCompressedTexImage", "glGetCompressedTexImageARB", "glGetCompressedTexImageEXT");
    LOAD_GL_EXTENSION(glSampleCoverage, statusSampleCoverage, NOpenGLProc::TSampleCoverage, "glSampleCoverage", "glSampleCoverageARB", "glSampleCoverageEXT");
  }

  // GL_VERSION_1_4
  if(platform >= NEngine::GPU_PLATFORM_GL0104)
  {
    LOAD_GL_EXTENSION(glBlendColor, statusBlendColor, NOpenGLProc::TBlendColor, "glBlendColor", "glBlendColorARB", "glBlendColorEXT");
    LOAD_GL_EXTENSION(glBlendEquation, statusBlendEquation, NOpenGLProc::TBlendEquation, "glBlendEquation", "glBlendEquationARB", "glBlendEquationEXT");
    LOAD_GL_EXTENSION(glBlendFuncSeparate, statusBlendFuncSeparate, NOpenGLProc::TBlendFuncSeparate, "glBlendFuncSeparate", "glBlendFuncSeparateARB", "glBlendFuncSeparateEXT");
    LOAD_GL_EXTENSION(glMultiDrawArrays, statusMultiDrawArrays, NOpenGLProc::TMultiDrawArrays, "glMultiDrawArrays", "glMultiDrawArraysARB", "glMultiDrawArraysEXT");
    LOAD_GL_EXTENSION(glMultiDrawElements, statusMultiDrawElements, NOpenGLProc::TMultiDrawElements, "glMultiDrawElements", "glMultiDrawElementsARB", "glMultiDrawElementsEXT");
    LOAD_GL_EXTENSION(glPointParameterf, statusPointParameterf, NOpenGLProc::TPointParameterf, "glPointParameterf", "glPointParameterfARB", "glPointParameterfEXT");
    LOAD_GL_EXTENSION(glPointParameterfv, statusPointParameterfv, NOpenGLProc::TPointParameterfv, "glPointParameterfv", "glPointParameterfvARB", "glPointParameterfvEXT");
    LOAD_GL_EXTENSION(glPointParameteri, statusPointParameteri, NOpenGLProc::TPointParameteri, "glPointParameteri", "glPointParameteriARB", "glPointParameteriEXT");
    LOAD_GL_EXTENSION(glPointParameteriv, statusPointParameteriv, NOpenGLProc::TPointParameteriv, "glPointParameteriv", "glPointParameterivARB", "glPointParameterivEXT");
  }

  // GL_VERSION_1_5
  if(platform >= NEngine::GPU_PLATFORM_GL0105)
  {
    LOAD_GL_EXTENSION(glBeginQuery, statusBeginQuery, NOpenGLProc::TBeginQuery, "glBeginQuery", "glBeginQueryARB", "glBeginQueryEXT");
    LOAD_GL_EXTENSION(glBindBuffer, statusBindBuffer, NOpenGLProc::TBindBuffer, "glBindBuffer", "glBindBufferARB", "glBindBufferEXT");
    LOAD_GL_EXTENSION(glBufferData, statusBufferData, NOpenGLProc::TBufferData, "glBufferData", "glBufferDataARB", "glBufferDataEXT");
    LOAD_GL_EXTENSION(glBufferSubData, statusBufferSubData, NOpenGLProc::TBufferSubData, "glBufferSubData", "glBufferSubDataARB", "glBufferSubDataEXT");
    LOAD_GL_EXTENSION(glDeleteBuffers, statusDeleteBuffers, NOpenGLProc::TDeleteBuffers, "glDeleteBuffers", "glDeleteBuffersARB", "glDeleteBuffersEXT");
    LOAD_GL_EXTENSION(glDeleteQueries, statusDeleteQueries, NOpenGLProc::TDeleteQueries, "glDeleteQueries", "glDeleteQueriesARB", "glDeleteQueriesEXT");
    LOAD_GL_EXTENSION(glEndQuery, statusEndQuery, NOpenGLProc::TEndQuery, "glEndQuery", "glEndQueryARB", "glEndQueryEXT");
    LOAD_GL_EXTENSION(glGenBuffers, statusGenBuffers, NOpenGLProc::TGenBuffers, "glGenBuffers", "glGenBuffersARB", "glGenBuffersEXT");
    LOAD_GL_EXTENSION(glGenQueries, statusGenQueries, NOpenGLProc::TGenQueries, "glGenQueries", "glGenQueriesARB", "glGenQueriesEXT");
    LOAD_GL_EXTENSION(glGetBufferParameteriv, statusGetBufferParameteriv, NOpenGLProc::TGetBufferParameteriv, "glGetBufferParameteriv", "glGetBufferParameterivARB", "glGetBufferParameterivEXT");
    LOAD_GL_EXTENSION(glGetBufferPointerv, statusGetBufferPointerv, NOpenGLProc::TGetBufferPointerv, "glGetBufferPointerv", "glGetBufferPointervARB", "glGetBufferPointervEXT");
    LOAD_GL_EXTENSION(glGetBufferSubData, statusGetBufferSubData, NOpenGLProc::TGetBufferSubData, "glGetBufferSubData", "glGetBufferSubDataARB", "glGetBufferSubDataEXT");
    LOAD_GL_EXTENSION(glGetQueryObjectiv, statusGetQueryObjectiv, NOpenGLProc::TGetQueryObjectiv, "glGetQueryObjectiv", "glGetQueryObjectivARB", "glGetQueryObjectivEXT");
    LOAD_GL_EXTENSION(glGetQueryObjectuiv, statusGetQueryObjectuiv, NOpenGLProc::TGetQueryObjectuiv, "glGetQueryObjectuiv", "glGetQueryObjectuivARB", "glGetQueryObjectuivEXT");
    LOAD_GL_EXTENSION(glGetQueryiv, statusGetQueryiv, NOpenGLProc::TGetQueryiv, "glGetQueryiv", "glGetQueryivARB", "glGetQueryivEXT");
    LOAD_GL_EXTENSION(glIsBuffer, statusIsBuffer, NOpenGLProc::TIsBuffer, "glIsBuffer", "glIsBufferARB", "glIsBufferEXT");
    LOAD_GL_EXTENSION(glIsQuery, statusIsQuery, NOpenGLProc::TIsQuery, "glIsQuery", "glIsQueryARB", "glIsQueryEXT");
    LOAD_GL_EXTENSION(glMapBuffer, statusMapBuffer, NOpenGLProc::TMapBuffer, "glMapBuffer", "glMapBufferARB", "glMapBufferEXT");
    LOAD_GL_EXTENSION(glUnmapBuffer, statusUnmapBuffer, NOpenGLProc::TUnmapBuffer, "glUnmapBuffer", "glUnmapBufferARB", "glUnmapBufferEXT");
  }

  // GL_VERSION_2_0
  if(platform >= NEngine::GPU_PLATFORM_GL0200)
  {
    LOAD_GL_EXTENSION(glAttachShader, statusAttachShader, NOpenGLProc::TAttachShader, "glAttachShader", "glAttachShaderARB", "glAttachShaderEXT");
    LOAD_GL_EXTENSION(glBindAttribLocation, statusBindAttribLocation, NOpenGLProc::TBindAttribLocation, "glBindAttribLocation", "glBindAttribLocationARB", "glBindAttribLocationEXT");
    LOAD_GL_EXTENSION(glBlendEquationSeparate, statusBlendEquationSeparate, NOpenGLProc::TBlendEquationSeparate, "glBlendEquationSeparate", "glBlendEquationSeparateARB", "glBlendEquationSeparateEXT");
    LOAD_GL_EXTENSION(glCompileShader, statusCompileShader, NOpenGLProc::TCompileShader, "glCompileShader", "glCompileShaderARB", "glCompileShaderEXT");
    LOAD_GL_EXTENSION(glCreateProgram, statusCreateProgram, NOpenGLProc::TCreateProgram, "glCreateProgram", "glCreateProgramARB", "glCreateProgramEXT");
    LOAD_GL_EXTENSION(glCreateShader, statusCreateShader, NOpenGLProc::TCreateShader, "glCreateShader", "glCreateShaderARB", "glCreateShaderEXT");
    LOAD_GL_EXTENSION(glDeleteProgram, statusDeleteProgram, NOpenGLProc::TDeleteProgram, "glDeleteProgram", "glDeleteProgramARB", "glDeleteProgramEXT");
    LOAD_GL_EXTENSION(glDeleteShader, statusDeleteShader, NOpenGLProc::TDeleteShader, "glDeleteShader", "glDeleteShaderARB", "glDeleteShaderEXT");
    LOAD_GL_EXTENSION(glDetachShader, statusDetachShader, NOpenGLProc::TDetachShader, "glDetachShader", "glDetachShaderARB", "glDetachShaderEXT");
    LOAD_GL_EXTENSION(glDisableVertexAttribArray, statusDisableVertexAttribArray, NOpenGLProc::TDisableVertexAttribArray, "glDisableVertexAttribArray", "glDisableVertexAttribArrayARB", "glDisableVertexAttribArrayEXT");
    LOAD_GL_EXTENSION(glDrawBuffers, statusDrawBuffers, NOpenGLProc::TDrawBuffers, "glDrawBuffers", "glDrawBuffersARB", "glDrawBuffersEXT");
    LOAD_GL_EXTENSION(glEnableVertexAttribArray, statusEnableVertexAttribArray, NOpenGLProc::TEnableVertexAttribArray, "glEnableVertexAttribArray", "glEnableVertexAttribArrayARB", "glEnableVertexAttribArrayEXT");
    LOAD_GL_EXTENSION(glGetActiveAttrib, statusGetActiveAttrib, NOpenGLProc::TGetActiveAttrib, "glGetActiveAttrib", "glGetActiveAttribARB", "glGetActiveAttribEXT");
    LOAD_GL_EXTENSION(glGetActiveUniform, statusGetActiveUniform, NOpenGLProc::TGetActiveUniform, "glGetActiveUniform", "glGetActiveUniformARB", "glGetActiveUniformEXT");
    LOAD_GL_EXTENSION(glGetAttachedShaders, statusGetAttachedShaders, NOpenGLProc::TGetAttachedShaders, "glGetAttachedShaders", "glGetAttachedShadersARB", "glGetAttachedShadersEXT");
    LOAD_GL_EXTENSION(glGetAttribLocation, statusGetAttribLocation, NOpenGLProc::TGetAttribLocation, "glGetAttribLocation", "glGetAttribLocationARB", "glGetAttribLocationEXT");
    LOAD_GL_EXTENSION(glGetProgramInfoLog, statusGetProgramInfoLog, NOpenGLProc::TGetProgramInfoLog, "glGetProgramInfoLog", "glGetProgramInfoLogARB", "glGetProgramInfoLogEXT");
    LOAD_GL_EXTENSION(glGetProgramiv, statusGetProgramiv, NOpenGLProc::TGetProgramiv, "glGetProgramiv", "glGetProgramivARB", "glGetProgramivEXT");
    LOAD_GL_EXTENSION(glGetShaderInfoLog, statusGetShaderInfoLog, NOpenGLProc::TGetShaderInfoLog, "glGetShaderInfoLog", "glGetShaderInfoLogARB", "glGetShaderInfoLogEXT");
    LOAD_GL_EXTENSION(glGetShaderSource, statusGetShaderSource, NOpenGLProc::TGetShaderSource, "glGetShaderSource", "glGetShaderSourceARB", "glGetShaderSourceEXT");
    LOAD_GL_EXTENSION(glGetShaderiv, statusGetShaderiv, NOpenGLProc::TGetShaderiv, "glGetShaderiv", "glGetShaderivARB", "glGetShaderivEXT");
    LOAD_GL_EXTENSION(glGetUniformLocation, statusGetUniformLocation, NOpenGLProc::TGetUniformLocation, "glGetUniformLocation", "glGetUniformLocationARB", "glGetUniformLocationEXT");
    LOAD_GL_EXTENSION(glGetUniformfv, statusGetUniformfv, NOpenGLProc::TGetUniformfv, "glGetUniformfv", "glGetUniformfvARB", "glGetUniformfvEXT");
    LOAD_GL_EXTENSION(glGetUniformiv, statusGetUniformiv, NOpenGLProc::TGetUniformiv, "glGetUniformiv", "glGetUniformivARB", "glGetUniformivEXT");
    LOAD_GL_EXTENSION(glGetVertexAttribPointerv, statusGetVertexAttribPointerv, NOpenGLProc::TGetVertexAttribPointerv, "glGetVertexAttribPointerv", "glGetVertexAttribPointervARB", "glGetVertexAttribPointervEXT");
    LOAD_GL_EXTENSION(glGetVertexAttribdv, statusGetVertexAttribdv, NOpenGLProc::TGetVertexAttribdv, "glGetVertexAttribdv", "glGetVertexAttribdvARB", "glGetVertexAttribdvEXT");
    LOAD_GL_EXTENSION(glGetVertexAttribfv, statusGetVertexAttribfv, NOpenGLProc::TGetVertexAttribfv, "glGetVertexAttribfv", "glGetVertexAttribfvARB", "glGetVertexAttribfvEXT");
    LOAD_GL_EXTENSION(glGetVertexAttribiv, statusGetVertexAttribiv, NOpenGLProc::TGetVertexAttribiv, "glGetVertexAttribiv", "glGetVertexAttribivARB", "glGetVertexAttribivEXT");
    LOAD_GL_EXTENSION(glIsProgram, statusIsProgram, NOpenGLProc::TIsProgram, "glIsProgram", "glIsProgramARB", "glIsProgramEXT");
    LOAD_GL_EXTENSION(glIsShader, statusIsShader, NOpenGLProc::TIsShader, "glIsShader", "glIsShaderARB", "glIsShaderEXT");
    LOAD_GL_EXTENSION(glLinkProgram, statusLinkProgram, NOpenGLProc::TLinkProgram, "glLinkProgram", "glLinkProgramARB", "glLinkProgramEXT");
    LOAD_GL_EXTENSION(glShaderSource, statusShaderSource, NOpenGLProc::TShaderSource, "glShaderSource", "glShaderSourceARB", "glShaderSourceEXT");
    LOAD_GL_EXTENSION(glStencilFuncSeparate, statusStencilFuncSeparate, NOpenGLProc::TStencilFuncSeparate, "glStencilFuncSeparate", "glStencilFuncSeparateARB", "glStencilFuncSeparateEXT");
    LOAD_GL_EXTENSION(glStencilMaskSeparate, statusStencilMaskSeparate, NOpenGLProc::TStencilMaskSeparate, "glStencilMaskSeparate", "glStencilMaskSeparateARB", "glStencilMaskSeparateEXT");
    LOAD_GL_EXTENSION(glStencilOpSeparate, statusStencilOpSeparate, NOpenGLProc::TStencilOpSeparate, "glStencilOpSeparate", "glStencilOpSeparateARB", "glStencilOpSeparateEXT");
    LOAD_GL_EXTENSION(glUniform1f, statusUniform1f, NOpenGLProc::TUniform1f, "glUniform1f", "glUniform1fARB", "glUniform1fEXT");
    LOAD_GL_EXTENSION(glUniform1fv, statusUniform1fv, NOpenGLProc::TUniform1fv, "glUniform1fv", "glUniform1fvARB", "glUniform1fvEXT");
    LOAD_GL_EXTENSION(glUniform1i, statusUniform1i, NOpenGLProc::TUniform1i, "glUniform1i", "glUniform1iARB", "glUniform1iEXT");
    LOAD_GL_EXTENSION(glUniform1iv, statusUniform1iv, NOpenGLProc::TUniform1iv, "glUniform1iv", "glUniform1ivARB", "glUniform1ivEXT");
    LOAD_GL_EXTENSION(glUniform2f, statusUniform2f, NOpenGLProc::TUniform2f, "glUniform2f", "glUniform2fARB", "glUniform2fEXT");
    LOAD_GL_EXTENSION(glUniform2fv, statusUniform2fv, NOpenGLProc::TUniform2fv, "glUniform2fv", "glUniform2fvARB", "glUniform2fvEXT");
    LOAD_GL_EXTENSION(glUniform2i, statusUniform2i, NOpenGLProc::TUniform2i, "glUniform2i", "glUniform2iARB", "glUniform2iEXT");
    LOAD_GL_EXTENSION(glUniform2iv, statusUniform2iv, NOpenGLProc::TUniform2iv, "glUniform2iv", "glUniform2ivARB", "glUniform2ivEXT");
    LOAD_GL_EXTENSION(glUniform3f, statusUniform3f, NOpenGLProc::TUniform3f, "glUniform3f", "glUniform3fARB", "glUniform3fEXT");
    LOAD_GL_EXTENSION(glUniform3fv, statusUniform3fv, NOpenGLProc::TUniform3fv, "glUniform3fv", "glUniform3fvARB", "glUniform3fvEXT");
    LOAD_GL_EXTENSION(glUniform3i, statusUniform3i, NOpenGLProc::TUniform3i, "glUniform3i", "glUniform3iARB", "glUniform3iEXT");
    LOAD_GL_EXTENSION(glUniform3iv, statusUniform3iv, NOpenGLProc::TUniform3iv, "glUniform3iv", "glUniform3ivARB", "glUniform3ivEXT");
    LOAD_GL_EXTENSION(glUniform4f, statusUniform4f, NOpenGLProc::TUniform4f, "glUniform4f", "glUniform4fARB", "glUniform4fEXT");
    LOAD_GL_EXTENSION(glUniform4fv, statusUniform4fv, NOpenGLProc::TUniform4fv, "glUniform4fv", "glUniform4fvARB", "glUniform4fvEXT");
    LOAD_GL_EXTENSION(glUniform4i, statusUniform4i, NOpenGLProc::TUniform4i, "glUniform4i", "glUniform4iARB", "glUniform4iEXT");
    LOAD_GL_EXTENSION(glUniform4iv, statusUniform4iv, NOpenGLProc::TUniform4iv, "glUniform4iv", "glUniform4ivARB", "glUniform4ivEXT");
    LOAD_GL_EXTENSION(glUniformMatrix2fv, statusUniformMatrix2fv, NOpenGLProc::TUniformMatrix2fv, "glUniformMatrix2fv", "glUniformMatrix2fvARB", "glUniformMatrix2fvEXT");
    LOAD_GL_EXTENSION(glUniformMatrix3fv, statusUniformMatrix3fv, NOpenGLProc::TUniformMatrix3fv, "glUniformMatrix3fv", "glUniformMatrix3fvARB", "glUniformMatrix3fvEXT");
    LOAD_GL_EXTENSION(glUniformMatrix4fv, statusUniformMatrix4fv, NOpenGLProc::TUniformMatrix4fv, "glUniformMatrix4fv", "glUniformMatrix4fvARB", "glUniformMatrix4fvEXT");
    LOAD_GL_EXTENSION(glUseProgram, statusUseProgram, NOpenGLProc::TUseProgram, "glUseProgram", "glUseProgramARB", "glUseProgramEXT");
    LOAD_GL_EXTENSION(glValidateProgram, statusValidateProgram, NOpenGLProc::TValidateProgram, "glValidateProgram", "glValidateProgramARB", "glValidateProgramEXT");
    LOAD_GL_EXTENSION(glVertexAttrib1d, statusVertexAttrib1d, NOpenGLProc::TVertexAttrib1d, "glVertexAttrib1d", "glVertexAttrib1dARB", "glVertexAttrib1dEXT");
    LOAD_GL_EXTENSION(glVertexAttrib1dv, statusVertexAttrib1dv, NOpenGLProc::TVertexAttrib1dv, "glVertexAttrib1dv", "glVertexAttrib1dvARB", "glVertexAttrib1dvEXT");
    LOAD_GL_EXTENSION(glVertexAttrib1f, statusVertexAttrib1f, NOpenGLProc::TVertexAttrib1f, "glVertexAttrib1f", "glVertexAttrib1fARB", "glVertexAttrib1fEXT");
    LOAD_GL_EXTENSION(glVertexAttrib1fv, statusVertexAttrib1fv, NOpenGLProc::TVertexAttrib1fv, "glVertexAttrib1fv", "glVertexAttrib1fvARB", "glVertexAttrib1fvEXT");
    LOAD_GL_EXTENSION(glVertexAttrib1s, statusVertexAttrib1s, NOpenGLProc::TVertexAttrib1s, "glVertexAttrib1s", "glVertexAttrib1sARB", "glVertexAttrib1sEXT");
    LOAD_GL_EXTENSION(glVertexAttrib1sv, statusVertexAttrib1sv, NOpenGLProc::TVertexAttrib1sv, "glVertexAttrib1sv", "glVertexAttrib1svARB", "glVertexAttrib1svEXT");
    LOAD_GL_EXTENSION(glVertexAttrib2d, statusVertexAttrib2d, NOpenGLProc::TVertexAttrib2d, "glVertexAttrib2d", "glVertexAttrib2dARB", "glVertexAttrib2dEXT");
    LOAD_GL_EXTENSION(glVertexAttrib2dv, statusVertexAttrib2dv, NOpenGLProc::TVertexAttrib2dv, "glVertexAttrib2dv", "glVertexAttrib2dvARB", "glVertexAttrib2dvEXT");
    LOAD_GL_EXTENSION(glVertexAttrib2f, statusVertexAttrib2f, NOpenGLProc::TVertexAttrib2f, "glVertexAttrib2f", "glVertexAttrib2fARB", "glVertexAttrib2fEXT");
    LOAD_GL_EXTENSION(glVertexAttrib2fv, statusVertexAttrib2fv, NOpenGLProc::TVertexAttrib2fv, "glVertexAttrib2fv", "glVertexAttrib2fvARB", "glVertexAttrib2fvEXT");
    LOAD_GL_EXTENSION(glVertexAttrib2s, statusVertexAttrib2s, NOpenGLProc::TVertexAttrib2s, "glVertexAttrib2s", "glVertexAttrib2sARB", "glVertexAttrib2sEXT");
    LOAD_GL_EXTENSION(glVertexAttrib2sv, statusVertexAttrib2sv, NOpenGLProc::TVertexAttrib2sv, "glVertexAttrib2sv", "glVertexAttrib2svARB", "glVertexAttrib2svEXT");
    LOAD_GL_EXTENSION(glVertexAttrib3d, statusVertexAttrib3d, NOpenGLProc::TVertexAttrib3d, "glVertexAttrib3d", "glVertexAttrib3dARB", "glVertexAttrib3dEXT");
    LOAD_GL_EXTENSION(glVertexAttrib3dv, statusVertexAttrib3dv, NOpenGLProc::TVertexAttrib3dv, "glVertexAttrib3dv", "glVertexAttrib3dvARB", "glVertexAttrib3dvEXT");
    LOAD_GL_EXTENSION(glVertexAttrib3f, statusVertexAttrib3f, NOpenGLProc::TVertexAttrib3f, "glVertexAttrib3f", "glVertexAttrib3fARB", "glVertexAttrib3fEXT");
    LOAD_GL_EXTENSION(glVertexAttrib3fv, statusVertexAttrib3fv, NOpenGLProc::TVertexAttrib3fv, "glVertexAttrib3fv", "glVertexAttrib3fvARB", "glVertexAttrib3fvEXT");
    LOAD_GL_EXTENSION(glVertexAttrib3s, statusVertexAttrib3s, NOpenGLProc::TVertexAttrib3s, "glVertexAttrib3s", "glVertexAttrib3sARB", "glVertexAttrib3sEXT");
    LOAD_GL_EXTENSION(glVertexAttrib3sv, statusVertexAttrib3sv, NOpenGLProc::TVertexAttrib3sv, "glVertexAttrib3sv", "glVertexAttrib3svARB", "glVertexAttrib3svEXT");
    LOAD_GL_EXTENSION(glVertexAttrib4Nbv, statusVertexAttrib4Nbv, NOpenGLProc::TVertexAttrib4Nbv, "glVertexAttrib4Nbv", "glVertexAttrib4NbvARB", "glVertexAttrib4NbvEXT");
    LOAD_GL_EXTENSION(glVertexAttrib4Niv, statusVertexAttrib4Niv, NOpenGLProc::TVertexAttrib4Niv, "glVertexAttrib4Niv", "glVertexAttrib4NivARB", "glVertexAttrib4NivEXT");
    LOAD_GL_EXTENSION(glVertexAttrib4Nsv, statusVertexAttrib4Nsv, NOpenGLProc::TVertexAttrib4Nsv, "glVertexAttrib4Nsv", "glVertexAttrib4NsvARB", "glVertexAttrib4NsvEXT");
    LOAD_GL_EXTENSION(glVertexAttrib4Nub, statusVertexAttrib4Nub, NOpenGLProc::TVertexAttrib4Nub, "glVertexAttrib4Nub", "glVertexAttrib4NubARB", "glVertexAttrib4NubEXT");
    LOAD_GL_EXTENSION(glVertexAttrib4Nubv, statusVertexAttrib4Nubv, NOpenGLProc::TVertexAttrib4Nubv, "glVertexAttrib4Nubv", "glVertexAttrib4NubvARB", "glVertexAttrib4NubvEXT");
    LOAD_GL_EXTENSION(glVertexAttrib4Nuiv, statusVertexAttrib4Nuiv, NOpenGLProc::TVertexAttrib4Nuiv, "glVertexAttrib4Nuiv", "glVertexAttrib4NuivARB", "glVertexAttrib4NuivEXT");
    LOAD_GL_EXTENSION(glVertexAttrib4Nusv, statusVertexAttrib4Nusv, NOpenGLProc::TVertexAttrib4Nusv, "glVertexAttrib4Nusv", "glVertexAttrib4NusvARB", "glVertexAttrib4NusvEXT");
    LOAD_GL_EXTENSION(glVertexAttrib4bv, statusVertexAttrib4bv, NOpenGLProc::TVertexAttrib4bv, "glVertexAttrib4bv", "glVertexAttrib4bvARB", "glVertexAttrib4bvEXT");
    LOAD_GL_EXTENSION(glVertexAttrib4d, statusVertexAttrib4d, NOpenGLProc::TVertexAttrib4d, "glVertexAttrib4d", "glVertexAttrib4dARB", "glVertexAttrib4dEXT");
    LOAD_GL_EXTENSION(glVertexAttrib4dv, statusVertexAttrib4dv, NOpenGLProc::TVertexAttrib4dv, "glVertexAttrib4dv", "glVertexAttrib4dvARB", "glVertexAttrib4dvEXT");
    LOAD_GL_EXTENSION(glVertexAttrib4f, statusVertexAttrib4f, NOpenGLProc::TVertexAttrib4f, "glVertexAttrib4f", "glVertexAttrib4fARB", "glVertexAttrib4fEXT");
    LOAD_GL_EXTENSION(glVertexAttrib4fv, statusVertexAttrib4fv, NOpenGLProc::TVertexAttrib4fv, "glVertexAttrib4fv", "glVertexAttrib4fvARB", "glVertexAttrib4fvEXT");
    LOAD_GL_EXTENSION(glVertexAttrib4iv, statusVertexAttrib4iv, NOpenGLProc::TVertexAttrib4iv, "glVertexAttrib4iv", "glVertexAttrib4ivARB", "glVertexAttrib4ivEXT");
    LOAD_GL_EXTENSION(glVertexAttrib4s, statusVertexAttrib4s, NOpenGLProc::TVertexAttrib4s, "glVertexAttrib4s", "glVertexAttrib4sARB", "glVertexAttrib4sEXT");
    LOAD_GL_EXTENSION(glVertexAttrib4sv, statusVertexAttrib4sv, NOpenGLProc::TVertexAttrib4sv, "glVertexAttrib4sv", "glVertexAttrib4svARB", "glVertexAttrib4svEXT");
    LOAD_GL_EXTENSION(glVertexAttrib4ubv, statusVertexAttrib4ubv, NOpenGLProc::TVertexAttrib4ubv, "glVertexAttrib4ubv", "glVertexAttrib4ubvARB", "glVertexAttrib4ubvEXT");
    LOAD_GL_EXTENSION(glVertexAttrib4uiv, statusVertexAttrib4uiv, NOpenGLProc::TVertexAttrib4uiv, "glVertexAttrib4uiv", "glVertexAttrib4uivARB", "glVertexAttrib4uivEXT");
    LOAD_GL_EXTENSION(glVertexAttrib4usv, statusVertexAttrib4usv, NOpenGLProc::TVertexAttrib4usv, "glVertexAttrib4usv", "glVertexAttrib4usvARB", "glVertexAttrib4usvEXT");
    LOAD_GL_EXTENSION(glVertexAttribPointer, statusVertexAttribPointer, NOpenGLProc::TVertexAttribPointer, "glVertexAttribPointer", "glVertexAttribPointerARB", "glVertexAttribPointerEXT");
  }

  // GL_VERSION_2_1
  if(platform >= NEngine::GPU_PLATFORM_GL0201)
  {
    LOAD_GL_EXTENSION(glUniformMatrix2x3fv, statusUniformMatrix2x3fv, NOpenGLProc::TUniformMatrix2x3fv, "glUniformMatrix2x3fv", "glUniformMatrix2x3fvARB", "glUniformMatrix2x3fvEXT");
    LOAD_GL_EXTENSION(glUniformMatrix2x4fv, statusUniformMatrix2x4fv, NOpenGLProc::TUniformMatrix2x4fv, "glUniformMatrix2x4fv", "glUniformMatrix2x4fvARB", "glUniformMatrix2x4fvEXT");
    LOAD_GL_EXTENSION(glUniformMatrix3x2fv, statusUniformMatrix3x2fv, NOpenGLProc::TUniformMatrix3x2fv, "glUniformMatrix3x2fv", "glUniformMatrix3x2fvARB", "glUniformMatrix3x2fvEXT");
    LOAD_GL_EXTENSION(glUniformMatrix3x4fv, statusUniformMatrix3x4fv, NOpenGLProc::TUniformMatrix3x4fv, "glUniformMatrix3x4fv", "glUniformMatrix3x4fvARB", "glUniformMatrix3x4fvEXT");
    LOAD_GL_EXTENSION(glUniformMatrix4x2fv, statusUniformMatrix4x2fv, NOpenGLProc::TUniformMatrix4x2fv, "glUniformMatrix4x2fv", "glUniformMatrix4x2fvARB", "glUniformMatrix4x2fvEXT");
    LOAD_GL_EXTENSION(glUniformMatrix4x3fv, statusUniformMatrix4x3fv, NOpenGLProc::TUniformMatrix4x3fv, "glUniformMatrix4x3fv", "glUniformMatrix4x3fvARB", "glUniformMatrix4x3fvEXT");
  }

  // GL_VERSION_3_0
  if(platform >= NEngine::GPU_PLATFORM_GL0300)
  {
    LOAD_GL_EXTENSION(glBeginConditionalRender, statusBeginConditionalRender, NOpenGLProc::TBeginConditionalRender, "glBeginConditionalRender", "glBeginConditionalRenderARB", "glBeginConditionalRenderEXT");
    LOAD_GL_EXTENSION(glBeginTransformFeedback, statusBeginTransformFeedback, NOpenGLProc::TBeginTransformFeedback, "glBeginTransformFeedback", "glBeginTransformFeedbackARB", "glBeginTransformFeedbackEXT");
    LOAD_GL_EXTENSION(glBindBufferBase, statusBindBufferBase, NOpenGLProc::TBindBufferBase, "glBindBufferBase", "glBindBufferBaseARB", "glBindBufferBaseEXT");
    LOAD_GL_EXTENSION(glBindBufferRange, statusBindBufferRange, NOpenGLProc::TBindBufferRange, "glBindBufferRange", "glBindBufferRangeARB", "glBindBufferRangeEXT");
    LOAD_GL_EXTENSION(glBindFragDataLocation, statusBindFragDataLocation, NOpenGLProc::TBindFragDataLocation, "glBindFragDataLocation", "glBindFragDataLocationARB", "glBindFragDataLocationEXT");
    LOAD_GL_EXTENSION(glBindFramebuffer, statusBindFramebuffer, NOpenGLProc::TBindFramebuffer, "glBindFramebuffer", "glBindFramebufferARB", "glBindFramebufferEXT");
    LOAD_GL_EXTENSION(glBindRenderbuffer, statusBindRenderbuffer, NOpenGLProc::TBindRenderbuffer, "glBindRenderbuffer", "glBindRenderbufferARB", "glBindRenderbufferEXT");
    LOAD_GL_EXTENSION(glBindVertexArray, statusBindVertexArray, NOpenGLProc::TBindVertexArray, "glBindVertexArray", "glBindVertexArrayARB", "glBindVertexArrayEXT");
    LOAD_GL_EXTENSION(glBlitFramebuffer, statusBlitFramebuffer, NOpenGLProc::TBlitFramebuffer, "glBlitFramebuffer", "glBlitFramebufferARB", "glBlitFramebufferEXT");
    LOAD_GL_EXTENSION(glCheckFramebufferStatus, statusCheckFramebufferStatus, NOpenGLProc::TCheckFramebufferStatus, "glCheckFramebufferStatus", "glCheckFramebufferStatusARB", "glCheckFramebufferStatusEXT");
    LOAD_GL_EXTENSION(glClampColor, statusClampColor, NOpenGLProc::TClampColor, "glClampColor", "glClampColorARB", "glClampColorEXT");
    LOAD_GL_EXTENSION(glClearBufferfi, statusClearBufferfi, NOpenGLProc::TClearBufferfi, "glClearBufferfi", "glClearBufferfiARB", "glClearBufferfiEXT");
    LOAD_GL_EXTENSION(glClearBufferfv, statusClearBufferfv, NOpenGLProc::TClearBufferfv, "glClearBufferfv", "glClearBufferfvARB", "glClearBufferfvEXT");
    LOAD_GL_EXTENSION(glClearBufferiv, statusClearBufferiv, NOpenGLProc::TClearBufferiv, "glClearBufferiv", "glClearBufferivARB", "glClearBufferivEXT");
    LOAD_GL_EXTENSION(glClearBufferuiv, statusClearBufferuiv, NOpenGLProc::TClearBufferuiv, "glClearBufferuiv", "glClearBufferuivARB", "glClearBufferuivEXT");
    LOAD_GL_EXTENSION(glColorMaski, statusColorMaski, NOpenGLProc::TColorMaski, "glColorMaski", "glColorMaskiARB", "glColorMaskiEXT");
    LOAD_GL_EXTENSION(glDeleteFramebuffers, statusDeleteFramebuffers, NOpenGLProc::TDeleteFramebuffers, "glDeleteFramebuffers", "glDeleteFramebuffersARB", "glDeleteFramebuffersEXT");
    LOAD_GL_EXTENSION(glDeleteRenderbuffers, statusDeleteRenderbuffers, NOpenGLProc::TDeleteRenderbuffers, "glDeleteRenderbuffers", "glDeleteRenderbuffersARB", "glDeleteRenderbuffersEXT");
    LOAD_GL_EXTENSION(glDeleteVertexArrays, statusDeleteVertexArrays, NOpenGLProc::TDeleteVertexArrays, "glDeleteVertexArrays", "glDeleteVertexArraysARB", "glDeleteVertexArraysEXT");
    LOAD_GL_EXTENSION(glDisablei, statusDisablei, NOpenGLProc::TDisablei, "glDisablei", "glDisableiARB", "glDisableiEXT");
    LOAD_GL_EXTENSION(glEnablei, statusEnablei, NOpenGLProc::TEnablei, "glEnablei", "glEnableiARB", "glEnableiEXT");
    LOAD_GL_EXTENSION(glEndConditionalRender, statusEndConditionalRender, NOpenGLProc::TEndConditionalRender, "glEndConditionalRender", "glEndConditionalRenderARB", "glEndConditionalRenderEXT");
    LOAD_GL_EXTENSION(glEndTransformFeedback, statusEndTransformFeedback, NOpenGLProc::TEndTransformFeedback, "glEndTransformFeedback", "glEndTransformFeedbackARB", "glEndTransformFeedbackEXT");
    LOAD_GL_EXTENSION(glFlushMappedBufferRange, statusFlushMappedBufferRange, NOpenGLProc::TFlushMappedBufferRange, "glFlushMappedBufferRange", "glFlushMappedBufferRangeARB", "glFlushMappedBufferRangeEXT");
    LOAD_GL_EXTENSION(glFramebufferRenderbuffer, statusFramebufferRenderbuffer, NOpenGLProc::TFramebufferRenderbuffer, "glFramebufferRenderbuffer", "glFramebufferRenderbufferARB", "glFramebufferRenderbufferEXT");
    LOAD_GL_EXTENSION(glFramebufferTexture1D, statusFramebufferTexture1D, NOpenGLProc::TFramebufferTexture1D, "glFramebufferTexture1D", "glFramebufferTexture1DARB", "glFramebufferTexture1DEXT");
    LOAD_GL_EXTENSION(glFramebufferTexture2D, statusFramebufferTexture2D, NOpenGLProc::TFramebufferTexture2D, "glFramebufferTexture2D", "glFramebufferTexture2DARB", "glFramebufferTexture2DEXT");
    LOAD_GL_EXTENSION(glFramebufferTexture3D, statusFramebufferTexture3D, NOpenGLProc::TFramebufferTexture3D, "glFramebufferTexture3D", "glFramebufferTexture3DARB", "glFramebufferTexture3DEXT");
    LOAD_GL_EXTENSION(glFramebufferTextureLayer, statusFramebufferTextureLayer, NOpenGLProc::TFramebufferTextureLayer, "glFramebufferTextureLayer", "glFramebufferTextureLayerARB", "glFramebufferTextureLayerEXT");
    LOAD_GL_EXTENSION(glGenFramebuffers, statusGenFramebuffers, NOpenGLProc::TGenFramebuffers, "glGenFramebuffers", "glGenFramebuffersARB", "glGenFramebuffersEXT");
    LOAD_GL_EXTENSION(glGenRenderbuffers, statusGenRenderbuffers, NOpenGLProc::TGenRenderbuffers, "glGenRenderbuffers", "glGenRenderbuffersARB", "glGenRenderbuffersEXT");
    LOAD_GL_EXTENSION(glGenVertexArrays, statusGenVertexArrays, NOpenGLProc::TGenVertexArrays, "glGenVertexArrays", "glGenVertexArraysARB", "glGenVertexArraysEXT");
    LOAD_GL_EXTENSION(glGenerateMipmap, statusGenerateMipmap, NOpenGLProc::TGenerateMipmap, "glGenerateMipmap", "glGenerateMipmapARB", "glGenerateMipmapEXT");
    LOAD_GL_EXTENSION(glGetBooleani_v, statusGetBooleani_v, NOpenGLProc::TGetBooleani_v, "glGetBooleani_v", "glGetBooleani_vARB", "glGetBooleani_vEXT");
    LOAD_GL_EXTENSION(glGetFragDataLocation, statusGetFragDataLocation, NOpenGLProc::TGetFragDataLocation, "glGetFragDataLocation", "glGetFragDataLocationARB", "glGetFragDataLocationEXT");
    LOAD_GL_EXTENSION(glGetFramebufferAttachmentParameteriv, statusGetFramebufferAttachmentParameteriv, NOpenGLProc::TGetFramebufferAttachmentParameteriv, "glGetFramebufferAttachmentParameteriv", "glGetFramebufferAttachmentParameterivARB", "glGetFramebufferAttachmentParameterivEXT");
    LOAD_GL_EXTENSION(glGetIntegeri_v, statusGetIntegeri_v, NOpenGLProc::TGetIntegeri_v, "glGetIntegeri_v", "glGetIntegeri_vARB", "glGetIntegeri_vEXT");
    LOAD_GL_EXTENSION(glGetRenderbufferParameteriv, statusGetRenderbufferParameteriv, NOpenGLProc::TGetRenderbufferParameteriv, "glGetRenderbufferParameteriv", "glGetRenderbufferParameterivARB", "glGetRenderbufferParameterivEXT");
    LOAD_GL_EXTENSION(glGetStringi, statusGetStringi, NOpenGLProc::TGetStringi, "glGetStringi", "glGetStringiARB", "glGetStringiEXT");
    LOAD_GL_EXTENSION(glGetTexParameterIiv, statusGetTexParameterIiv, NOpenGLProc::TGetTexParameterIiv, "glGetTexParameterIiv", "glGetTexParameterIivARB", "glGetTexParameterIivEXT");
    LOAD_GL_EXTENSION(glGetTexParameterIuiv, statusGetTexParameterIuiv, NOpenGLProc::TGetTexParameterIuiv, "glGetTexParameterIuiv", "glGetTexParameterIuivARB", "glGetTexParameterIuivEXT");
    LOAD_GL_EXTENSION(glGetTransformFeedbackVarying, statusGetTransformFeedbackVarying, NOpenGLProc::TGetTransformFeedbackVarying, "glGetTransformFeedbackVarying", "glGetTransformFeedbackVaryingARB", "glGetTransformFeedbackVaryingEXT");
    LOAD_GL_EXTENSION(glGetUniformuiv, statusGetUniformuiv, NOpenGLProc::TGetUniformuiv, "glGetUniformuiv", "glGetUniformuivARB", "glGetUniformuivEXT");
    LOAD_GL_EXTENSION(glGetVertexAttribIiv, statusGetVertexAttribIiv, NOpenGLProc::TGetVertexAttribIiv, "glGetVertexAttribIiv", "glGetVertexAttribIivARB", "glGetVertexAttribIivEXT");
    LOAD_GL_EXTENSION(glGetVertexAttribIuiv, statusGetVertexAttribIuiv, NOpenGLProc::TGetVertexAttribIuiv, "glGetVertexAttribIuiv", "glGetVertexAttribIuivARB", "glGetVertexAttribIuivEXT");
    LOAD_GL_EXTENSION(glIsEnabledi, statusIsEnabledi, NOpenGLProc::TIsEnabledi, "glIsEnabledi", "glIsEnablediARB", "glIsEnablediEXT");
    LOAD_GL_EXTENSION(glIsFramebuffer, statusIsFramebuffer, NOpenGLProc::TIsFramebuffer, "glIsFramebuffer", "glIsFramebufferARB", "glIsFramebufferEXT");
    LOAD_GL_EXTENSION(glIsRenderbuffer, statusIsRenderbuffer, NOpenGLProc::TIsRenderbuffer, "glIsRenderbuffer", "glIsRenderbufferARB", "glIsRenderbufferEXT");
    LOAD_GL_EXTENSION(glIsVertexArray, statusIsVertexArray, NOpenGLProc::TIsVertexArray, "glIsVertexArray", "glIsVertexArrayARB", "glIsVertexArrayEXT");
    LOAD_GL_EXTENSION(glMapBufferRange, statusMapBufferRange, NOpenGLProc::TMapBufferRange, "glMapBufferRange", "glMapBufferRangeARB", "glMapBufferRangeEXT");
    LOAD_GL_EXTENSION(glRenderbufferStorage, statusRenderbufferStorage, NOpenGLProc::TRenderbufferStorage, "glRenderbufferStorage", "glRenderbufferStorageARB", "glRenderbufferStorageEXT");
    LOAD_GL_EXTENSION(glRenderbufferStorageMultisample, statusRenderbufferStorageMultisample, NOpenGLProc::TRenderbufferStorageMultisample, "glRenderbufferStorageMultisample", "glRenderbufferStorageMultisampleARB", "glRenderbufferStorageMultisampleEXT");
    LOAD_GL_EXTENSION(glTexParameterIiv, statusTexParameterIiv, NOpenGLProc::TTexParameterIiv, "glTexParameterIiv", "glTexParameterIivARB", "glTexParameterIivEXT");
    LOAD_GL_EXTENSION(glTexParameterIuiv, statusTexParameterIuiv, NOpenGLProc::TTexParameterIuiv, "glTexParameterIuiv", "glTexParameterIuivARB", "glTexParameterIuivEXT");
    LOAD_GL_EXTENSION(glTransformFeedbackVaryings, statusTransformFeedbackVaryings, NOpenGLProc::TTransformFeedbackVaryings, "glTransformFeedbackVaryings", "glTransformFeedbackVaryingsARB", "glTransformFeedbackVaryingsEXT");
    LOAD_GL_EXTENSION(glUniform1ui, statusUniform1ui, NOpenGLProc::TUniform1ui, "glUniform1ui", "glUniform1uiARB", "glUniform1uiEXT");
    LOAD_GL_EXTENSION(glUniform1uiv, statusUniform1uiv, NOpenGLProc::TUniform1uiv, "glUniform1uiv", "glUniform1uivARB", "glUniform1uivEXT");
    LOAD_GL_EXTENSION(glUniform2ui, statusUniform2ui, NOpenGLProc::TUniform2ui, "glUniform2ui", "glUniform2uiARB", "glUniform2uiEXT");
    LOAD_GL_EXTENSION(glUniform2uiv, statusUniform2uiv, NOpenGLProc::TUniform2uiv, "glUniform2uiv", "glUniform2uivARB", "glUniform2uivEXT");
    LOAD_GL_EXTENSION(glUniform3ui, statusUniform3ui, NOpenGLProc::TUniform3ui, "glUniform3ui", "glUniform3uiARB", "glUniform3uiEXT");
    LOAD_GL_EXTENSION(glUniform3uiv, statusUniform3uiv, NOpenGLProc::TUniform3uiv, "glUniform3uiv", "glUniform3uivARB", "glUniform3uivEXT");
    LOAD_GL_EXTENSION(glUniform4ui, statusUniform4ui, NOpenGLProc::TUniform4ui, "glUniform4ui", "glUniform4uiARB", "glUniform4uiEXT");
    LOAD_GL_EXTENSION(glUniform4uiv, statusUniform4uiv, NOpenGLProc::TUniform4uiv, "glUniform4uiv", "glUniform4uivARB", "glUniform4uivEXT");
    LOAD_GL_EXTENSION(glVertexAttribI1i, statusVertexAttribI1i, NOpenGLProc::TVertexAttribI1i, "glVertexAttribI1i", "glVertexAttribI1iARB", "glVertexAttribI1iEXT");
    LOAD_GL_EXTENSION(glVertexAttribI1iv, statusVertexAttribI1iv, NOpenGLProc::TVertexAttribI1iv, "glVertexAttribI1iv", "glVertexAttribI1ivARB", "glVertexAttribI1ivEXT");
    LOAD_GL_EXTENSION(glVertexAttribI1ui, statusVertexAttribI1ui, NOpenGLProc::TVertexAttribI1ui, "glVertexAttribI1ui", "glVertexAttribI1uiARB", "glVertexAttribI1uiEXT");
    LOAD_GL_EXTENSION(glVertexAttribI1uiv, statusVertexAttribI1uiv, NOpenGLProc::TVertexAttribI1uiv, "glVertexAttribI1uiv", "glVertexAttribI1uivARB", "glVertexAttribI1uivEXT");
    LOAD_GL_EXTENSION(glVertexAttribI2i, statusVertexAttribI2i, NOpenGLProc::TVertexAttribI2i, "glVertexAttribI2i", "glVertexAttribI2iARB", "glVertexAttribI2iEXT");
    LOAD_GL_EXTENSION(glVertexAttribI2iv, statusVertexAttribI2iv, NOpenGLProc::TVertexAttribI2iv, "glVertexAttribI2iv", "glVertexAttribI2ivARB", "glVertexAttribI2ivEXT");
    LOAD_GL_EXTENSION(glVertexAttribI2ui, statusVertexAttribI2ui, NOpenGLProc::TVertexAttribI2ui, "glVertexAttribI2ui", "glVertexAttribI2uiARB", "glVertexAttribI2uiEXT");
    LOAD_GL_EXTENSION(glVertexAttribI2uiv, statusVertexAttribI2uiv, NOpenGLProc::TVertexAttribI2uiv, "glVertexAttribI2uiv", "glVertexAttribI2uivARB", "glVertexAttribI2uivEXT");
    LOAD_GL_EXTENSION(glVertexAttribI3i, statusVertexAttribI3i, NOpenGLProc::TVertexAttribI3i, "glVertexAttribI3i", "glVertexAttribI3iARB", "glVertexAttribI3iEXT");
    LOAD_GL_EXTENSION(glVertexAttribI3iv, statusVertexAttribI3iv, NOpenGLProc::TVertexAttribI3iv, "glVertexAttribI3iv", "glVertexAttribI3ivARB", "glVertexAttribI3ivEXT");
    LOAD_GL_EXTENSION(glVertexAttribI3ui, statusVertexAttribI3ui, NOpenGLProc::TVertexAttribI3ui, "glVertexAttribI3ui", "glVertexAttribI3uiARB", "glVertexAttribI3uiEXT");
    LOAD_GL_EXTENSION(glVertexAttribI3uiv, statusVertexAttribI3uiv, NOpenGLProc::TVertexAttribI3uiv, "glVertexAttribI3uiv", "glVertexAttribI3uivARB", "glVertexAttribI3uivEXT");
    LOAD_GL_EXTENSION(glVertexAttribI4bv, statusVertexAttribI4bv, NOpenGLProc::TVertexAttribI4bv, "glVertexAttribI4bv", "glVertexAttribI4bvARB", "glVertexAttribI4bvEXT");
    LOAD_GL_EXTENSION(glVertexAttribI4i, statusVertexAttribI4i, NOpenGLProc::TVertexAttribI4i, "glVertexAttribI4i", "glVertexAttribI4iARB", "glVertexAttribI4iEXT");
    LOAD_GL_EXTENSION(glVertexAttribI4iv, statusVertexAttribI4iv, NOpenGLProc::TVertexAttribI4iv, "glVertexAttribI4iv", "glVertexAttribI4ivARB", "glVertexAttribI4ivEXT");
    LOAD_GL_EXTENSION(glVertexAttribI4sv, statusVertexAttribI4sv, NOpenGLProc::TVertexAttribI4sv, "glVertexAttribI4sv", "glVertexAttribI4svARB", "glVertexAttribI4svEXT");
    LOAD_GL_EXTENSION(glVertexAttribI4ubv, statusVertexAttribI4ubv, NOpenGLProc::TVertexAttribI4ubv, "glVertexAttribI4ubv", "glVertexAttribI4ubvARB", "glVertexAttribI4ubvEXT");
    LOAD_GL_EXTENSION(glVertexAttribI4ui, statusVertexAttribI4ui, NOpenGLProc::TVertexAttribI4ui, "glVertexAttribI4ui", "glVertexAttribI4uiARB", "glVertexAttribI4uiEXT");
    LOAD_GL_EXTENSION(glVertexAttribI4uiv, statusVertexAttribI4uiv, NOpenGLProc::TVertexAttribI4uiv, "glVertexAttribI4uiv", "glVertexAttribI4uivARB", "glVertexAttribI4uivEXT");
    LOAD_GL_EXTENSION(glVertexAttribI4usv, statusVertexAttribI4usv, NOpenGLProc::TVertexAttribI4usv, "glVertexAttribI4usv", "glVertexAttribI4usvARB", "glVertexAttribI4usvEXT");
    LOAD_GL_EXTENSION(glVertexAttribIPointer, statusVertexAttribIPointer, NOpenGLProc::TVertexAttribIPointer, "glVertexAttribIPointer", "glVertexAttribIPointerARB", "glVertexAttribIPointerEXT");
  }

  // GL_VERSION_3_1
  if(platform >= NEngine::GPU_PLATFORM_GL0301)
  {
    LOAD_GL_EXTENSION(glCopyBufferSubData, statusCopyBufferSubData, NOpenGLProc::TCopyBufferSubData, "glCopyBufferSubData", "glCopyBufferSubDataARB", "glCopyBufferSubDataEXT");
    LOAD_GL_EXTENSION(glDrawArraysInstanced, statusDrawArraysInstanced, NOpenGLProc::TDrawArraysInstanced, "glDrawArraysInstanced", "glDrawArraysInstancedARB", "glDrawArraysInstancedEXT");
    LOAD_GL_EXTENSION(glDrawElementsInstanced, statusDrawElementsInstanced, NOpenGLProc::TDrawElementsInstanced, "glDrawElementsInstanced", "glDrawElementsInstancedARB", "glDrawElementsInstancedEXT");
    LOAD_GL_EXTENSION(glGetActiveUniformBlockName, statusGetActiveUniformBlockName, NOpenGLProc::TGetActiveUniformBlockName, "glGetActiveUniformBlockName", "glGetActiveUniformBlockNameARB", "glGetActiveUniformBlockNameEXT");
    LOAD_GL_EXTENSION(glGetActiveUniformBlockiv, statusGetActiveUniformBlockiv, NOpenGLProc::TGetActiveUniformBlockiv, "glGetActiveUniformBlockiv", "glGetActiveUniformBlockivARB", "glGetActiveUniformBlockivEXT");
    LOAD_GL_EXTENSION(glGetActiveUniformName, statusGetActiveUniformName, NOpenGLProc::TGetActiveUniformName, "glGetActiveUniformName", "glGetActiveUniformNameARB", "glGetActiveUniformNameEXT");
    LOAD_GL_EXTENSION(glGetActiveUniformsiv, statusGetActiveUniformsiv, NOpenGLProc::TGetActiveUniformsiv, "glGetActiveUniformsiv", "glGetActiveUniformsivARB", "glGetActiveUniformsivEXT");
    LOAD_GL_EXTENSION(glGetUniformBlockIndex, statusGetUniformBlockIndex, NOpenGLProc::TGetUniformBlockIndex, "glGetUniformBlockIndex", "glGetUniformBlockIndexARB", "glGetUniformBlockIndexEXT");
    LOAD_GL_EXTENSION(glGetUniformIndices, statusGetUniformIndices, NOpenGLProc::TGetUniformIndices, "glGetUniformIndices", "glGetUniformIndicesARB", "glGetUniformIndicesEXT");
    LOAD_GL_EXTENSION(glPrimitiveRestartIndex, statusPrimitiveRestartIndex, NOpenGLProc::TPrimitiveRestartIndex, "glPrimitiveRestartIndex", "glPrimitiveRestartIndexARB", "glPrimitiveRestartIndexEXT");
    LOAD_GL_EXTENSION(glTexBuffer, statusTexBuffer, NOpenGLProc::TTexBuffer, "glTexBuffer", "glTexBufferARB", "glTexBufferEXT");
    LOAD_GL_EXTENSION(glUniformBlockBinding, statusUniformBlockBinding, NOpenGLProc::TUniformBlockBinding, "glUniformBlockBinding", "glUniformBlockBindingARB", "glUniformBlockBindingEXT");
  }

  // GL_VERSION_3_2
  if(platform >= NEngine::GPU_PLATFORM_GL0302)
  {
    LOAD_GL_EXTENSION(glClientWaitSync, statusClientWaitSync, NOpenGLProc::TClientWaitSync, "glClientWaitSync", "glClientWaitSyncARB", "glClientWaitSyncEXT");
    LOAD_GL_EXTENSION(glDeleteSync, statusDeleteSync, NOpenGLProc::TDeleteSync, "glDeleteSync", "glDeleteSyncARB", "glDeleteSyncEXT");
    LOAD_GL_EXTENSION(glDrawElementsBaseVertex, statusDrawElementsBaseVertex, NOpenGLProc::TDrawElementsBaseVertex, "glDrawElementsBaseVertex", "glDrawElementsBaseVertexARB", "glDrawElementsBaseVertexEXT");
    LOAD_GL_EXTENSION(glDrawElementsInstancedBaseVertex, statusDrawElementsInstancedBaseVertex, NOpenGLProc::TDrawElementsInstancedBaseVertex, "glDrawElementsInstancedBaseVertex", "glDrawElementsInstancedBaseVertexARB", "glDrawElementsInstancedBaseVertexEXT");
    LOAD_GL_EXTENSION(glDrawRangeElementsBaseVertex, statusDrawRangeElementsBaseVertex, NOpenGLProc::TDrawRangeElementsBaseVertex, "glDrawRangeElementsBaseVertex", "glDrawRangeElementsBaseVertexARB", "glDrawRangeElementsBaseVertexEXT");
    LOAD_GL_EXTENSION(glFenceSync, statusFenceSync, NOpenGLProc::TFenceSync, "glFenceSync", "glFenceSyncARB", "glFenceSyncEXT");
    LOAD_GL_EXTENSION(glFramebufferTexture, statusFramebufferTexture, NOpenGLProc::TFramebufferTexture, "glFramebufferTexture", "glFramebufferTextureARB", "glFramebufferTextureEXT");
    LOAD_GL_EXTENSION(glGetBufferParameteri64v, statusGetBufferParameteri64v, NOpenGLProc::TGetBufferParameteri64v, "glGetBufferParameteri64v", "glGetBufferParameteri64vARB", "glGetBufferParameteri64vEXT");
    LOAD_GL_EXTENSION(glGetInteger64i_v, statusGetInteger64i_v, NOpenGLProc::TGetInteger64i_v, "glGetInteger64i_v", "glGetInteger64i_vARB", "glGetInteger64i_vEXT");
    LOAD_GL_EXTENSION(glGetInteger64v, statusGetInteger64v, NOpenGLProc::TGetInteger64v, "glGetInteger64v", "glGetInteger64vARB", "glGetInteger64vEXT");
    LOAD_GL_EXTENSION(glGetMultisamplefv, statusGetMultisamplefv, NOpenGLProc::TGetMultisamplefv, "glGetMultisamplefv", "glGetMultisamplefvARB", "glGetMultisamplefvEXT");
    LOAD_GL_EXTENSION(glGetSynciv, statusGetSynciv, NOpenGLProc::TGetSynciv, "glGetSynciv", "glGetSyncivARB", "glGetSyncivEXT");
    LOAD_GL_EXTENSION(glIsSync, statusIsSync, NOpenGLProc::TIsSync, "glIsSync", "glIsSyncARB", "glIsSyncEXT");
    LOAD_GL_EXTENSION(glMultiDrawElementsBaseVertex, statusMultiDrawElementsBaseVertex, NOpenGLProc::TMultiDrawElementsBaseVertex, "glMultiDrawElementsBaseVertex", "glMultiDrawElementsBaseVertexARB", "glMultiDrawElementsBaseVertexEXT");
    LOAD_GL_EXTENSION(glProvokingVertex, statusProvokingVertex, NOpenGLProc::TProvokingVertex, "glProvokingVertex", "glProvokingVertexARB", "glProvokingVertexEXT");
    LOAD_GL_EXTENSION(glSampleMaski, statusSampleMaski, NOpenGLProc::TSampleMaski, "glSampleMaski", "glSampleMaskiARB", "glSampleMaskiEXT");
    LOAD_GL_EXTENSION(glTexImage2DMultisample, statusTexImage2DMultisample, NOpenGLProc::TTexImage2DMultisample, "glTexImage2DMultisample", "glTexImage2DMultisampleARB", "glTexImage2DMultisampleEXT");
    LOAD_GL_EXTENSION(glTexImage3DMultisample, statusTexImage3DMultisample, NOpenGLProc::TTexImage3DMultisample, "glTexImage3DMultisample", "glTexImage3DMultisampleARB", "glTexImage3DMultisampleEXT");
    LOAD_GL_EXTENSION(glWaitSync, statusWaitSync, NOpenGLProc::TWaitSync, "glWaitSync", "glWaitSyncARB", "glWaitSyncEXT");
  }

  // GL_VERSION_3_3
  if(platform >= NEngine::GPU_PLATFORM_GL0303)
  {
    LOAD_GL_EXTENSION(glBindFragDataLocationIndexed, statusBindFragDataLocationIndexed, NOpenGLProc::TBindFragDataLocationIndexed, "glBindFragDataLocationIndexed", "glBindFragDataLocationIndexedARB", "glBindFragDataLocationIndexedEXT");
    LOAD_GL_EXTENSION(glBindSampler, statusBindSampler, NOpenGLProc::TBindSampler, "glBindSampler", "glBindSamplerARB", "glBindSamplerEXT");
    LOAD_GL_EXTENSION(glDeleteSamplers, statusDeleteSamplers, NOpenGLProc::TDeleteSamplers, "glDeleteSamplers", "glDeleteSamplersARB", "glDeleteSamplersEXT");
    LOAD_GL_EXTENSION(glGenSamplers, statusGenSamplers, NOpenGLProc::TGenSamplers, "glGenSamplers", "glGenSamplersARB", "glGenSamplersEXT");
    LOAD_GL_EXTENSION(glGetFragDataIndex, statusGetFragDataIndex, NOpenGLProc::TGetFragDataIndex, "glGetFragDataIndex", "glGetFragDataIndexARB", "glGetFragDataIndexEXT");
    LOAD_GL_EXTENSION(glGetQueryObjecti64v, statusGetQueryObjecti64v, NOpenGLProc::TGetQueryObjecti64v, "glGetQueryObjecti64v", "glGetQueryObjecti64vARB", "glGetQueryObjecti64vEXT");
    LOAD_GL_EXTENSION(glGetQueryObjectui64v, statusGetQueryObjectui64v, NOpenGLProc::TGetQueryObjectui64v, "glGetQueryObjectui64v", "glGetQueryObjectui64vARB", "glGetQueryObjectui64vEXT");
    LOAD_GL_EXTENSION(glGetSamplerParameterIiv, statusGetSamplerParameterIiv, NOpenGLProc::TGetSamplerParameterIiv, "glGetSamplerParameterIiv", "glGetSamplerParameterIivARB", "glGetSamplerParameterIivEXT");
    LOAD_GL_EXTENSION(glGetSamplerParameterIuiv, statusGetSamplerParameterIuiv, NOpenGLProc::TGetSamplerParameterIuiv, "glGetSamplerParameterIuiv", "glGetSamplerParameterIuivARB", "glGetSamplerParameterIuivEXT");
    LOAD_GL_EXTENSION(glGetSamplerParameterfv, statusGetSamplerParameterfv, NOpenGLProc::TGetSamplerParameterfv, "glGetSamplerParameterfv", "glGetSamplerParameterfvARB", "glGetSamplerParameterfvEXT");
    LOAD_GL_EXTENSION(glGetSamplerParameteriv, statusGetSamplerParameteriv, NOpenGLProc::TGetSamplerParameteriv, "glGetSamplerParameteriv", "glGetSamplerParameterivARB", "glGetSamplerParameterivEXT");
    LOAD_GL_EXTENSION(glIsSampler, statusIsSampler, NOpenGLProc::TIsSampler, "glIsSampler", "glIsSamplerARB", "glIsSamplerEXT");
    LOAD_GL_EXTENSION(glQueryCounter, statusQueryCounter, NOpenGLProc::TQueryCounter, "glQueryCounter", "glQueryCounterARB", "glQueryCounterEXT");
    LOAD_GL_EXTENSION(glSamplerParameterIiv, statusSamplerParameterIiv, NOpenGLProc::TSamplerParameterIiv, "glSamplerParameterIiv", "glSamplerParameterIivARB", "glSamplerParameterIivEXT");
    LOAD_GL_EXTENSION(glSamplerParameterIuiv, statusSamplerParameterIuiv, NOpenGLProc::TSamplerParameterIuiv, "glSamplerParameterIuiv", "glSamplerParameterIuivARB", "glSamplerParameterIuivEXT");
    LOAD_GL_EXTENSION(glSamplerParameterf, statusSamplerParameterf, NOpenGLProc::TSamplerParameterf, "glSamplerParameterf", "glSamplerParameterfARB", "glSamplerParameterfEXT");
    LOAD_GL_EXTENSION(glSamplerParameterfv, statusSamplerParameterfv, NOpenGLProc::TSamplerParameterfv, "glSamplerParameterfv", "glSamplerParameterfvARB", "glSamplerParameterfvEXT");
    LOAD_GL_EXTENSION(glSamplerParameteri, statusSamplerParameteri, NOpenGLProc::TSamplerParameteri, "glSamplerParameteri", "glSamplerParameteriARB", "glSamplerParameteriEXT");
    LOAD_GL_EXTENSION(glSamplerParameteriv, statusSamplerParameteriv, NOpenGLProc::TSamplerParameteriv, "glSamplerParameteriv", "glSamplerParameterivARB", "glSamplerParameterivEXT");
    LOAD_GL_EXTENSION(glVertexAttribDivisor, statusVertexAttribDivisor, NOpenGLProc::TVertexAttribDivisor, "glVertexAttribDivisor", "glVertexAttribDivisorARB", "glVertexAttribDivisorEXT");
    LOAD_GL_EXTENSION(glVertexAttribP1ui, statusVertexAttribP1ui, NOpenGLProc::TVertexAttribP1ui, "glVertexAttribP1ui", "glVertexAttribP1uiARB", "glVertexAttribP1uiEXT");
    LOAD_GL_EXTENSION(glVertexAttribP1uiv, statusVertexAttribP1uiv, NOpenGLProc::TVertexAttribP1uiv, "glVertexAttribP1uiv", "glVertexAttribP1uivARB", "glVertexAttribP1uivEXT");
    LOAD_GL_EXTENSION(glVertexAttribP2ui, statusVertexAttribP2ui, NOpenGLProc::TVertexAttribP2ui, "glVertexAttribP2ui", "glVertexAttribP2uiARB", "glVertexAttribP2uiEXT");
    LOAD_GL_EXTENSION(glVertexAttribP2uiv, statusVertexAttribP2uiv, NOpenGLProc::TVertexAttribP2uiv, "glVertexAttribP2uiv", "glVertexAttribP2uivARB", "glVertexAttribP2uivEXT");
    LOAD_GL_EXTENSION(glVertexAttribP3ui, statusVertexAttribP3ui, NOpenGLProc::TVertexAttribP3ui, "glVertexAttribP3ui", "glVertexAttribP3uiARB", "glVertexAttribP3uiEXT");
    LOAD_GL_EXTENSION(glVertexAttribP3uiv, statusVertexAttribP3uiv, NOpenGLProc::TVertexAttribP3uiv, "glVertexAttribP3uiv", "glVertexAttribP3uivARB", "glVertexAttribP3uivEXT");
    LOAD_GL_EXTENSION(glVertexAttribP4ui, statusVertexAttribP4ui, NOpenGLProc::TVertexAttribP4ui, "glVertexAttribP4ui", "glVertexAttribP4uiARB", "glVertexAttribP4uiEXT");
    LOAD_GL_EXTENSION(glVertexAttribP4uiv, statusVertexAttribP4uiv, NOpenGLProc::TVertexAttribP4uiv, "glVertexAttribP4uiv", "glVertexAttribP4uivARB", "glVertexAttribP4uivEXT");
  }

  // GL_VERSION_4_0
  if(platform >= NEngine::GPU_PLATFORM_GL0400)
  {
    LOAD_GL_EXTENSION(glBeginQueryIndexed, statusBeginQueryIndexed, NOpenGLProc::TBeginQueryIndexed, "glBeginQueryIndexed", "glBeginQueryIndexedARB", "glBeginQueryIndexedEXT");
    LOAD_GL_EXTENSION(glBindTransformFeedback, statusBindTransformFeedback, NOpenGLProc::TBindTransformFeedback, "glBindTransformFeedback", "glBindTransformFeedbackARB", "glBindTransformFeedbackEXT");
    LOAD_GL_EXTENSION(glBlendEquationSeparatei, statusBlendEquationSeparatei, NOpenGLProc::TBlendEquationSeparatei, "glBlendEquationSeparatei", "glBlendEquationSeparateiARB", "glBlendEquationSeparateiEXT");
    LOAD_GL_EXTENSION(glBlendEquationi, statusBlendEquationi, NOpenGLProc::TBlendEquationi, "glBlendEquationi", "glBlendEquationiARB", "glBlendEquationiEXT");
    LOAD_GL_EXTENSION(glBlendFuncSeparatei, statusBlendFuncSeparatei, NOpenGLProc::TBlendFuncSeparatei, "glBlendFuncSeparatei", "glBlendFuncSeparateiARB", "glBlendFuncSeparateiEXT");
    LOAD_GL_EXTENSION(glBlendFunci, statusBlendFunci, NOpenGLProc::TBlendFunci, "glBlendFunci", "glBlendFunciARB", "glBlendFunciEXT");
    LOAD_GL_EXTENSION(glDeleteTransformFeedbacks, statusDeleteTransformFeedbacks, NOpenGLProc::TDeleteTransformFeedbacks, "glDeleteTransformFeedbacks", "glDeleteTransformFeedbacksARB", "glDeleteTransformFeedbacksEXT");
    LOAD_GL_EXTENSION(glDrawArraysIndirect, statusDrawArraysIndirect, NOpenGLProc::TDrawArraysIndirect, "glDrawArraysIndirect", "glDrawArraysIndirectARB", "glDrawArraysIndirectEXT");
    LOAD_GL_EXTENSION(glDrawElementsIndirect, statusDrawElementsIndirect, NOpenGLProc::TDrawElementsIndirect, "glDrawElementsIndirect", "glDrawElementsIndirectARB", "glDrawElementsIndirectEXT");
    LOAD_GL_EXTENSION(glDrawTransformFeedback, statusDrawTransformFeedback, NOpenGLProc::TDrawTransformFeedback, "glDrawTransformFeedback", "glDrawTransformFeedbackARB", "glDrawTransformFeedbackEXT");
    LOAD_GL_EXTENSION(glDrawTransformFeedbackStream, statusDrawTransformFeedbackStream, NOpenGLProc::TDrawTransformFeedbackStream, "glDrawTransformFeedbackStream", "glDrawTransformFeedbackStreamARB", "glDrawTransformFeedbackStreamEXT");
    LOAD_GL_EXTENSION(glEndQueryIndexed, statusEndQueryIndexed, NOpenGLProc::TEndQueryIndexed, "glEndQueryIndexed", "glEndQueryIndexedARB", "glEndQueryIndexedEXT");
    LOAD_GL_EXTENSION(glGenTransformFeedbacks, statusGenTransformFeedbacks, NOpenGLProc::TGenTransformFeedbacks, "glGenTransformFeedbacks", "glGenTransformFeedbacksARB", "glGenTransformFeedbacksEXT");
    LOAD_GL_EXTENSION(glGetActiveSubroutineName, statusGetActiveSubroutineName, NOpenGLProc::TGetActiveSubroutineName, "glGetActiveSubroutineName", "glGetActiveSubroutineNameARB", "glGetActiveSubroutineNameEXT");
    LOAD_GL_EXTENSION(glGetActiveSubroutineUniformName, statusGetActiveSubroutineUniformName, NOpenGLProc::TGetActiveSubroutineUniformName, "glGetActiveSubroutineUniformName", "glGetActiveSubroutineUniformNameARB", "glGetActiveSubroutineUniformNameEXT");
    LOAD_GL_EXTENSION(glGetActiveSubroutineUniformiv, statusGetActiveSubroutineUniformiv, NOpenGLProc::TGetActiveSubroutineUniformiv, "glGetActiveSubroutineUniformiv", "glGetActiveSubroutineUniformivARB", "glGetActiveSubroutineUniformivEXT");
    LOAD_GL_EXTENSION(glGetProgramStageiv, statusGetProgramStageiv, NOpenGLProc::TGetProgramStageiv, "glGetProgramStageiv", "glGetProgramStageivARB", "glGetProgramStageivEXT");
    LOAD_GL_EXTENSION(glGetQueryIndexediv, statusGetQueryIndexediv, NOpenGLProc::TGetQueryIndexediv, "glGetQueryIndexediv", "glGetQueryIndexedivARB", "glGetQueryIndexedivEXT");
    LOAD_GL_EXTENSION(glGetSubroutineIndex, statusGetSubroutineIndex, NOpenGLProc::TGetSubroutineIndex, "glGetSubroutineIndex", "glGetSubroutineIndexARB", "glGetSubroutineIndexEXT");
    LOAD_GL_EXTENSION(glGetSubroutineUniformLocation, statusGetSubroutineUniformLocation, NOpenGLProc::TGetSubroutineUniformLocation, "glGetSubroutineUniformLocation", "glGetSubroutineUniformLocationARB", "glGetSubroutineUniformLocationEXT");
    LOAD_GL_EXTENSION(glGetUniformSubroutineuiv, statusGetUniformSubroutineuiv, NOpenGLProc::TGetUniformSubroutineuiv, "glGetUniformSubroutineuiv", "glGetUniformSubroutineuivARB", "glGetUniformSubroutineuivEXT");
    LOAD_GL_EXTENSION(glGetUniformdv, statusGetUniformdv, NOpenGLProc::TGetUniformdv, "glGetUniformdv", "glGetUniformdvARB", "glGetUniformdvEXT");
    LOAD_GL_EXTENSION(glIsTransformFeedback, statusIsTransformFeedback, NOpenGLProc::TIsTransformFeedback, "glIsTransformFeedback", "glIsTransformFeedbackARB", "glIsTransformFeedbackEXT");
    LOAD_GL_EXTENSION(glMinSampleShading, statusMinSampleShading, NOpenGLProc::TMinSampleShading, "glMinSampleShading", "glMinSampleShadingARB", "glMinSampleShadingEXT");
    LOAD_GL_EXTENSION(glPatchParameterfv, statusPatchParameterfv, NOpenGLProc::TPatchParameterfv, "glPatchParameterfv", "glPatchParameterfvARB", "glPatchParameterfvEXT");
    LOAD_GL_EXTENSION(glPatchParameteri, statusPatchParameteri, NOpenGLProc::TPatchParameteri, "glPatchParameteri", "glPatchParameteriARB", "glPatchParameteriEXT");
    LOAD_GL_EXTENSION(glPauseTransformFeedback, statusPauseTransformFeedback, NOpenGLProc::TPauseTransformFeedback, "glPauseTransformFeedback", "glPauseTransformFeedbackARB", "glPauseTransformFeedbackEXT");
    LOAD_GL_EXTENSION(glResumeTransformFeedback, statusResumeTransformFeedback, NOpenGLProc::TResumeTransformFeedback, "glResumeTransformFeedback", "glResumeTransformFeedbackARB", "glResumeTransformFeedbackEXT");
    LOAD_GL_EXTENSION(glUniform1d, statusUniform1d, NOpenGLProc::TUniform1d, "glUniform1d", "glUniform1dARB", "glUniform1dEXT");
    LOAD_GL_EXTENSION(glUniform1dv, statusUniform1dv, NOpenGLProc::TUniform1dv, "glUniform1dv", "glUniform1dvARB", "glUniform1dvEXT");
    LOAD_GL_EXTENSION(glUniform2d, statusUniform2d, NOpenGLProc::TUniform2d, "glUniform2d", "glUniform2dARB", "glUniform2dEXT");
    LOAD_GL_EXTENSION(glUniform2dv, statusUniform2dv, NOpenGLProc::TUniform2dv, "glUniform2dv", "glUniform2dvARB", "glUniform2dvEXT");
    LOAD_GL_EXTENSION(glUniform3d, statusUniform3d, NOpenGLProc::TUniform3d, "glUniform3d", "glUniform3dARB", "glUniform3dEXT");
    LOAD_GL_EXTENSION(glUniform3dv, statusUniform3dv, NOpenGLProc::TUniform3dv, "glUniform3dv", "glUniform3dvARB", "glUniform3dvEXT");
    LOAD_GL_EXTENSION(glUniform4d, statusUniform4d, NOpenGLProc::TUniform4d, "glUniform4d", "glUniform4dARB", "glUniform4dEXT");
    LOAD_GL_EXTENSION(glUniform4dv, statusUniform4dv, NOpenGLProc::TUniform4dv, "glUniform4dv", "glUniform4dvARB", "glUniform4dvEXT");
    LOAD_GL_EXTENSION(glUniformMatrix2dv, statusUniformMatrix2dv, NOpenGLProc::TUniformMatrix2dv, "glUniformMatrix2dv", "glUniformMatrix2dvARB", "glUniformMatrix2dvEXT");
    LOAD_GL_EXTENSION(glUniformMatrix2x3dv, statusUniformMatrix2x3dv, NOpenGLProc::TUniformMatrix2x3dv, "glUniformMatrix2x3dv", "glUniformMatrix2x3dvARB", "glUniformMatrix2x3dvEXT");
    LOAD_GL_EXTENSION(glUniformMatrix2x4dv, statusUniformMatrix2x4dv, NOpenGLProc::TUniformMatrix2x4dv, "glUniformMatrix2x4dv", "glUniformMatrix2x4dvARB", "glUniformMatrix2x4dvEXT");
    LOAD_GL_EXTENSION(glUniformMatrix3dv, statusUniformMatrix3dv, NOpenGLProc::TUniformMatrix3dv, "glUniformMatrix3dv", "glUniformMatrix3dvARB", "glUniformMatrix3dvEXT");
    LOAD_GL_EXTENSION(glUniformMatrix3x2dv, statusUniformMatrix3x2dv, NOpenGLProc::TUniformMatrix3x2dv, "glUniformMatrix3x2dv", "glUniformMatrix3x2dvARB", "glUniformMatrix3x2dvEXT");
    LOAD_GL_EXTENSION(glUniformMatrix3x4dv, statusUniformMatrix3x4dv, NOpenGLProc::TUniformMatrix3x4dv, "glUniformMatrix3x4dv", "glUniformMatrix3x4dvARB", "glUniformMatrix3x4dvEXT");
    LOAD_GL_EXTENSION(glUniformMatrix4dv, statusUniformMatrix4dv, NOpenGLProc::TUniformMatrix4dv, "glUniformMatrix4dv", "glUniformMatrix4dvARB", "glUniformMatrix4dvEXT");
    LOAD_GL_EXTENSION(glUniformMatrix4x2dv, statusUniformMatrix4x2dv, NOpenGLProc::TUniformMatrix4x2dv, "glUniformMatrix4x2dv", "glUniformMatrix4x2dvARB", "glUniformMatrix4x2dvEXT");
    LOAD_GL_EXTENSION(glUniformMatrix4x3dv, statusUniformMatrix4x3dv, NOpenGLProc::TUniformMatrix4x3dv, "glUniformMatrix4x3dv", "glUniformMatrix4x3dvARB", "glUniformMatrix4x3dvEXT");
    LOAD_GL_EXTENSION(glUniformSubroutinesuiv, statusUniformSubroutinesuiv, NOpenGLProc::TUniformSubroutinesuiv, "glUniformSubroutinesuiv", "glUniformSubroutinesuivARB", "glUniformSubroutinesuivEXT");
  }

  // GL_VERSION_4_1
  if(platform >= NEngine::GPU_PLATFORM_GL0401)
  {
    LOAD_GL_EXTENSION(glActiveShaderProgram, statusActiveShaderProgram, NOpenGLProc::TActiveShaderProgram, "glActiveShaderProgram", "glActiveShaderProgramARB", "glActiveShaderProgramEXT");
    LOAD_GL_EXTENSION(glBindProgramPipeline, statusBindProgramPipeline, NOpenGLProc::TBindProgramPipeline, "glBindProgramPipeline", "glBindProgramPipelineARB", "glBindProgramPipelineEXT");
    LOAD_GL_EXTENSION(glClearDepthf, statusClearDepthf, NOpenGLProc::TClearDepthf, "glClearDepthf", "glClearDepthfARB", "glClearDepthfEXT");
    LOAD_GL_EXTENSION(glCreateShaderProgramv, statusCreateShaderProgramv, NOpenGLProc::TCreateShaderProgramv, "glCreateShaderProgramv", "glCreateShaderProgramvARB", "glCreateShaderProgramvEXT");
    LOAD_GL_EXTENSION(glDeleteProgramPipelines, statusDeleteProgramPipelines, NOpenGLProc::TDeleteProgramPipelines, "glDeleteProgramPipelines", "glDeleteProgramPipelinesARB", "glDeleteProgramPipelinesEXT");
    LOAD_GL_EXTENSION(glDepthRangeArrayv, statusDepthRangeArrayv, NOpenGLProc::TDepthRangeArrayv, "glDepthRangeArrayv", "glDepthRangeArrayvARB", "glDepthRangeArrayvEXT");
    LOAD_GL_EXTENSION(glDepthRangeIndexed, statusDepthRangeIndexed, NOpenGLProc::TDepthRangeIndexed, "glDepthRangeIndexed", "glDepthRangeIndexedARB", "glDepthRangeIndexedEXT");
    LOAD_GL_EXTENSION(glDepthRangef, statusDepthRangef, NOpenGLProc::TDepthRangef, "glDepthRangef", "glDepthRangefARB", "glDepthRangefEXT");
    LOAD_GL_EXTENSION(glGenProgramPipelines, statusGenProgramPipelines, NOpenGLProc::TGenProgramPipelines, "glGenProgramPipelines", "glGenProgramPipelinesARB", "glGenProgramPipelinesEXT");
    LOAD_GL_EXTENSION(glGetDoublei_v, statusGetDoublei_v, NOpenGLProc::TGetDoublei_v, "glGetDoublei_v", "glGetDoublei_vARB", "glGetDoublei_vEXT");
    LOAD_GL_EXTENSION(glGetFloati_v, statusGetFloati_v, NOpenGLProc::TGetFloati_v, "glGetFloati_v", "glGetFloati_vARB", "glGetFloati_vEXT");
    LOAD_GL_EXTENSION(glGetProgramBinary, statusGetProgramBinary, NOpenGLProc::TGetProgramBinary, "glGetProgramBinary", "glGetProgramBinaryARB", "glGetProgramBinaryEXT");
    LOAD_GL_EXTENSION(glGetProgramPipelineInfoLog, statusGetProgramPipelineInfoLog, NOpenGLProc::TGetProgramPipelineInfoLog, "glGetProgramPipelineInfoLog", "glGetProgramPipelineInfoLogARB", "glGetProgramPipelineInfoLogEXT");
    LOAD_GL_EXTENSION(glGetProgramPipelineiv, statusGetProgramPipelineiv, NOpenGLProc::TGetProgramPipelineiv, "glGetProgramPipelineiv", "glGetProgramPipelineivARB", "glGetProgramPipelineivEXT");
    LOAD_GL_EXTENSION(glGetShaderPrecisionFormat, statusGetShaderPrecisionFormat, NOpenGLProc::TGetShaderPrecisionFormat, "glGetShaderPrecisionFormat", "glGetShaderPrecisionFormatARB", "glGetShaderPrecisionFormatEXT");
    LOAD_GL_EXTENSION(glGetVertexAttribLdv, statusGetVertexAttribLdv, NOpenGLProc::TGetVertexAttribLdv, "glGetVertexAttribLdv", "glGetVertexAttribLdvARB", "glGetVertexAttribLdvEXT");
    LOAD_GL_EXTENSION(glIsProgramPipeline, statusIsProgramPipeline, NOpenGLProc::TIsProgramPipeline, "glIsProgramPipeline", "glIsProgramPipelineARB", "glIsProgramPipelineEXT");
    LOAD_GL_EXTENSION(glProgramBinary, statusProgramBinary, NOpenGLProc::TProgramBinary, "glProgramBinary", "glProgramBinaryARB", "glProgramBinaryEXT");
    LOAD_GL_EXTENSION(glProgramParameteri, statusProgramParameteri, NOpenGLProc::TProgramParameteri, "glProgramParameteri", "glProgramParameteriARB", "glProgramParameteriEXT");
    LOAD_GL_EXTENSION(glProgramUniform1d, statusProgramUniform1d, NOpenGLProc::TProgramUniform1d, "glProgramUniform1d", "glProgramUniform1dARB", "glProgramUniform1dEXT");
    LOAD_GL_EXTENSION(glProgramUniform1dv, statusProgramUniform1dv, NOpenGLProc::TProgramUniform1dv, "glProgramUniform1dv", "glProgramUniform1dvARB", "glProgramUniform1dvEXT");
    LOAD_GL_EXTENSION(glProgramUniform1f, statusProgramUniform1f, NOpenGLProc::TProgramUniform1f, "glProgramUniform1f", "glProgramUniform1fARB", "glProgramUniform1fEXT");
    LOAD_GL_EXTENSION(glProgramUniform1fv, statusProgramUniform1fv, NOpenGLProc::TProgramUniform1fv, "glProgramUniform1fv", "glProgramUniform1fvARB", "glProgramUniform1fvEXT");
    LOAD_GL_EXTENSION(glProgramUniform1i, statusProgramUniform1i, NOpenGLProc::TProgramUniform1i, "glProgramUniform1i", "glProgramUniform1iARB", "glProgramUniform1iEXT");
    LOAD_GL_EXTENSION(glProgramUniform1iv, statusProgramUniform1iv, NOpenGLProc::TProgramUniform1iv, "glProgramUniform1iv", "glProgramUniform1ivARB", "glProgramUniform1ivEXT");
    LOAD_GL_EXTENSION(glProgramUniform1ui, statusProgramUniform1ui, NOpenGLProc::TProgramUniform1ui, "glProgramUniform1ui", "glProgramUniform1uiARB", "glProgramUniform1uiEXT");
    LOAD_GL_EXTENSION(glProgramUniform1uiv, statusProgramUniform1uiv, NOpenGLProc::TProgramUniform1uiv, "glProgramUniform1uiv", "glProgramUniform1uivARB", "glProgramUniform1uivEXT");
    LOAD_GL_EXTENSION(glProgramUniform2d, statusProgramUniform2d, NOpenGLProc::TProgramUniform2d, "glProgramUniform2d", "glProgramUniform2dARB", "glProgramUniform2dEXT");
    LOAD_GL_EXTENSION(glProgramUniform2dv, statusProgramUniform2dv, NOpenGLProc::TProgramUniform2dv, "glProgramUniform2dv", "glProgramUniform2dvARB", "glProgramUniform2dvEXT");
    LOAD_GL_EXTENSION(glProgramUniform2f, statusProgramUniform2f, NOpenGLProc::TProgramUniform2f, "glProgramUniform2f", "glProgramUniform2fARB", "glProgramUniform2fEXT");
    LOAD_GL_EXTENSION(glProgramUniform2fv, statusProgramUniform2fv, NOpenGLProc::TProgramUniform2fv, "glProgramUniform2fv", "glProgramUniform2fvARB", "glProgramUniform2fvEXT");
    LOAD_GL_EXTENSION(glProgramUniform2i, statusProgramUniform2i, NOpenGLProc::TProgramUniform2i, "glProgramUniform2i", "glProgramUniform2iARB", "glProgramUniform2iEXT");
    LOAD_GL_EXTENSION(glProgramUniform2iv, statusProgramUniform2iv, NOpenGLProc::TProgramUniform2iv, "glProgramUniform2iv", "glProgramUniform2ivARB", "glProgramUniform2ivEXT");
    LOAD_GL_EXTENSION(glProgramUniform2ui, statusProgramUniform2ui, NOpenGLProc::TProgramUniform2ui, "glProgramUniform2ui", "glProgramUniform2uiARB", "glProgramUniform2uiEXT");
    LOAD_GL_EXTENSION(glProgramUniform2uiv, statusProgramUniform2uiv, NOpenGLProc::TProgramUniform2uiv, "glProgramUniform2uiv", "glProgramUniform2uivARB", "glProgramUniform2uivEXT");
    LOAD_GL_EXTENSION(glProgramUniform3d, statusProgramUniform3d, NOpenGLProc::TProgramUniform3d, "glProgramUniform3d", "glProgramUniform3dARB", "glProgramUniform3dEXT");
    LOAD_GL_EXTENSION(glProgramUniform3dv, statusProgramUniform3dv, NOpenGLProc::TProgramUniform3dv, "glProgramUniform3dv", "glProgramUniform3dvARB", "glProgramUniform3dvEXT");
    LOAD_GL_EXTENSION(glProgramUniform3f, statusProgramUniform3f, NOpenGLProc::TProgramUniform3f, "glProgramUniform3f", "glProgramUniform3fARB", "glProgramUniform3fEXT");
    LOAD_GL_EXTENSION(glProgramUniform3fv, statusProgramUniform3fv, NOpenGLProc::TProgramUniform3fv, "glProgramUniform3fv", "glProgramUniform3fvARB", "glProgramUniform3fvEXT");
    LOAD_GL_EXTENSION(glProgramUniform3i, statusProgramUniform3i, NOpenGLProc::TProgramUniform3i, "glProgramUniform3i", "glProgramUniform3iARB", "glProgramUniform3iEXT");
    LOAD_GL_EXTENSION(glProgramUniform3iv, statusProgramUniform3iv, NOpenGLProc::TProgramUniform3iv, "glProgramUniform3iv", "glProgramUniform3ivARB", "glProgramUniform3ivEXT");
    LOAD_GL_EXTENSION(glProgramUniform3ui, statusProgramUniform3ui, NOpenGLProc::TProgramUniform3ui, "glProgramUniform3ui", "glProgramUniform3uiARB", "glProgramUniform3uiEXT");
    LOAD_GL_EXTENSION(glProgramUniform3uiv, statusProgramUniform3uiv, NOpenGLProc::TProgramUniform3uiv, "glProgramUniform3uiv", "glProgramUniform3uivARB", "glProgramUniform3uivEXT");
    LOAD_GL_EXTENSION(glProgramUniform4d, statusProgramUniform4d, NOpenGLProc::TProgramUniform4d, "glProgramUniform4d", "glProgramUniform4dARB", "glProgramUniform4dEXT");
    LOAD_GL_EXTENSION(glProgramUniform4dv, statusProgramUniform4dv, NOpenGLProc::TProgramUniform4dv, "glProgramUniform4dv", "glProgramUniform4dvARB", "glProgramUniform4dvEXT");
    LOAD_GL_EXTENSION(glProgramUniform4f, statusProgramUniform4f, NOpenGLProc::TProgramUniform4f, "glProgramUniform4f", "glProgramUniform4fARB", "glProgramUniform4fEXT");
    LOAD_GL_EXTENSION(glProgramUniform4fv, statusProgramUniform4fv, NOpenGLProc::TProgramUniform4fv, "glProgramUniform4fv", "glProgramUniform4fvARB", "glProgramUniform4fvEXT");
    LOAD_GL_EXTENSION(glProgramUniform4i, statusProgramUniform4i, NOpenGLProc::TProgramUniform4i, "glProgramUniform4i", "glProgramUniform4iARB", "glProgramUniform4iEXT");
    LOAD_GL_EXTENSION(glProgramUniform4iv, statusProgramUniform4iv, NOpenGLProc::TProgramUniform4iv, "glProgramUniform4iv", "glProgramUniform4ivARB", "glProgramUniform4ivEXT");
    LOAD_GL_EXTENSION(glProgramUniform4ui, statusProgramUniform4ui, NOpenGLProc::TProgramUniform4ui, "glProgramUniform4ui", "glProgramUniform4uiARB", "glProgramUniform4uiEXT");
    LOAD_GL_EXTENSION(glProgramUniform4uiv, statusProgramUniform4uiv, NOpenGLProc::TProgramUniform4uiv, "glProgramUniform4uiv", "glProgramUniform4uivARB", "glProgramUniform4uivEXT");
    LOAD_GL_EXTENSION(glProgramUniformMatrix2dv, statusProgramUniformMatrix2dv, NOpenGLProc::TProgramUniformMatrix2dv, "glProgramUniformMatrix2dv", "glProgramUniformMatrix2dvARB", "glProgramUniformMatrix2dvEXT");
    LOAD_GL_EXTENSION(glProgramUniformMatrix2fv, statusProgramUniformMatrix2fv, NOpenGLProc::TProgramUniformMatrix2fv, "glProgramUniformMatrix2fv", "glProgramUniformMatrix2fvARB", "glProgramUniformMatrix2fvEXT");
    LOAD_GL_EXTENSION(glProgramUniformMatrix2x3dv, statusProgramUniformMatrix2x3dv, NOpenGLProc::TProgramUniformMatrix2x3dv, "glProgramUniformMatrix2x3dv", "glProgramUniformMatrix2x3dvARB", "glProgramUniformMatrix2x3dvEXT");
    LOAD_GL_EXTENSION(glProgramUniformMatrix2x3fv, statusProgramUniformMatrix2x3fv, NOpenGLProc::TProgramUniformMatrix2x3fv, "glProgramUniformMatrix2x3fv", "glProgramUniformMatrix2x3fvARB", "glProgramUniformMatrix2x3fvEXT");
    LOAD_GL_EXTENSION(glProgramUniformMatrix2x4dv, statusProgramUniformMatrix2x4dv, NOpenGLProc::TProgramUniformMatrix2x4dv, "glProgramUniformMatrix2x4dv", "glProgramUniformMatrix2x4dvARB", "glProgramUniformMatrix2x4dvEXT");
    LOAD_GL_EXTENSION(glProgramUniformMatrix2x4fv, statusProgramUniformMatrix2x4fv, NOpenGLProc::TProgramUniformMatrix2x4fv, "glProgramUniformMatrix2x4fv", "glProgramUniformMatrix2x4fvARB", "glProgramUniformMatrix2x4fvEXT");
    LOAD_GL_EXTENSION(glProgramUniformMatrix3dv, statusProgramUniformMatrix3dv, NOpenGLProc::TProgramUniformMatrix3dv, "glProgramUniformMatrix3dv", "glProgramUniformMatrix3dvARB", "glProgramUniformMatrix3dvEXT");
    LOAD_GL_EXTENSION(glProgramUniformMatrix3fv, statusProgramUniformMatrix3fv, NOpenGLProc::TProgramUniformMatrix3fv, "glProgramUniformMatrix3fv", "glProgramUniformMatrix3fvARB", "glProgramUniformMatrix3fvEXT");
    LOAD_GL_EXTENSION(glProgramUniformMatrix3x2dv, statusProgramUniformMatrix3x2dv, NOpenGLProc::TProgramUniformMatrix3x2dv, "glProgramUniformMatrix3x2dv", "glProgramUniformMatrix3x2dvARB", "glProgramUniformMatrix3x2dvEXT");
    LOAD_GL_EXTENSION(glProgramUniformMatrix3x2fv, statusProgramUniformMatrix3x2fv, NOpenGLProc::TProgramUniformMatrix3x2fv, "glProgramUniformMatrix3x2fv", "glProgramUniformMatrix3x2fvARB", "glProgramUniformMatrix3x2fvEXT");
    LOAD_GL_EXTENSION(glProgramUniformMatrix3x4dv, statusProgramUniformMatrix3x4dv, NOpenGLProc::TProgramUniformMatrix3x4dv, "glProgramUniformMatrix3x4dv", "glProgramUniformMatrix3x4dvARB", "glProgramUniformMatrix3x4dvEXT");
    LOAD_GL_EXTENSION(glProgramUniformMatrix3x4fv, statusProgramUniformMatrix3x4fv, NOpenGLProc::TProgramUniformMatrix3x4fv, "glProgramUniformMatrix3x4fv", "glProgramUniformMatrix3x4fvARB", "glProgramUniformMatrix3x4fvEXT");
    LOAD_GL_EXTENSION(glProgramUniformMatrix4dv, statusProgramUniformMatrix4dv, NOpenGLProc::TProgramUniformMatrix4dv, "glProgramUniformMatrix4dv", "glProgramUniformMatrix4dvARB", "glProgramUniformMatrix4dvEXT");
    LOAD_GL_EXTENSION(glProgramUniformMatrix4fv, statusProgramUniformMatrix4fv, NOpenGLProc::TProgramUniformMatrix4fv, "glProgramUniformMatrix4fv", "glProgramUniformMatrix4fvARB", "glProgramUniformMatrix4fvEXT");
    LOAD_GL_EXTENSION(glProgramUniformMatrix4x2dv, statusProgramUniformMatrix4x2dv, NOpenGLProc::TProgramUniformMatrix4x2dv, "glProgramUniformMatrix4x2dv", "glProgramUniformMatrix4x2dvARB", "glProgramUniformMatrix4x2dvEXT");
    LOAD_GL_EXTENSION(glProgramUniformMatrix4x2fv, statusProgramUniformMatrix4x2fv, NOpenGLProc::TProgramUniformMatrix4x2fv, "glProgramUniformMatrix4x2fv", "glProgramUniformMatrix4x2fvARB", "glProgramUniformMatrix4x2fvEXT");
    LOAD_GL_EXTENSION(glProgramUniformMatrix4x3dv, statusProgramUniformMatrix4x3dv, NOpenGLProc::TProgramUniformMatrix4x3dv, "glProgramUniformMatrix4x3dv", "glProgramUniformMatrix4x3dvARB", "glProgramUniformMatrix4x3dvEXT");
    LOAD_GL_EXTENSION(glProgramUniformMatrix4x3fv, statusProgramUniformMatrix4x3fv, NOpenGLProc::TProgramUniformMatrix4x3fv, "glProgramUniformMatrix4x3fv", "glProgramUniformMatrix4x3fvARB", "glProgramUniformMatrix4x3fvEXT");
    LOAD_GL_EXTENSION(glReleaseShaderCompiler, statusReleaseShaderCompiler, NOpenGLProc::TReleaseShaderCompiler, "glReleaseShaderCompiler", "glReleaseShaderCompilerARB", "glReleaseShaderCompilerEXT");
    LOAD_GL_EXTENSION(glScissorArrayv, statusScissorArrayv, NOpenGLProc::TScissorArrayv, "glScissorArrayv", "glScissorArrayvARB", "glScissorArrayvEXT");
    LOAD_GL_EXTENSION(glScissorIndexed, statusScissorIndexed, NOpenGLProc::TScissorIndexed, "glScissorIndexed", "glScissorIndexedARB", "glScissorIndexedEXT");
    LOAD_GL_EXTENSION(glScissorIndexedv, statusScissorIndexedv, NOpenGLProc::TScissorIndexedv, "glScissorIndexedv", "glScissorIndexedvARB", "glScissorIndexedvEXT");
    LOAD_GL_EXTENSION(glShaderBinary, statusShaderBinary, NOpenGLProc::TShaderBinary, "glShaderBinary", "glShaderBinaryARB", "glShaderBinaryEXT");
    LOAD_GL_EXTENSION(glUseProgramStages, statusUseProgramStages, NOpenGLProc::TUseProgramStages, "glUseProgramStages", "glUseProgramStagesARB", "glUseProgramStagesEXT");
    LOAD_GL_EXTENSION(glValidateProgramPipeline, statusValidateProgramPipeline, NOpenGLProc::TValidateProgramPipeline, "glValidateProgramPipeline", "glValidateProgramPipelineARB", "glValidateProgramPipelineEXT");
    LOAD_GL_EXTENSION(glVertexAttribL1d, statusVertexAttribL1d, NOpenGLProc::TVertexAttribL1d, "glVertexAttribL1d", "glVertexAttribL1dARB", "glVertexAttribL1dEXT");
    LOAD_GL_EXTENSION(glVertexAttribL1dv, statusVertexAttribL1dv, NOpenGLProc::TVertexAttribL1dv, "glVertexAttribL1dv", "glVertexAttribL1dvARB", "glVertexAttribL1dvEXT");
    LOAD_GL_EXTENSION(glVertexAttribL2d, statusVertexAttribL2d, NOpenGLProc::TVertexAttribL2d, "glVertexAttribL2d", "glVertexAttribL2dARB", "glVertexAttribL2dEXT");
    LOAD_GL_EXTENSION(glVertexAttribL2dv, statusVertexAttribL2dv, NOpenGLProc::TVertexAttribL2dv, "glVertexAttribL2dv", "glVertexAttribL2dvARB", "glVertexAttribL2dvEXT");
    LOAD_GL_EXTENSION(glVertexAttribL3d, statusVertexAttribL3d, NOpenGLProc::TVertexAttribL3d, "glVertexAttribL3d", "glVertexAttribL3dARB", "glVertexAttribL3dEXT");
    LOAD_GL_EXTENSION(glVertexAttribL3dv, statusVertexAttribL3dv, NOpenGLProc::TVertexAttribL3dv, "glVertexAttribL3dv", "glVertexAttribL3dvARB", "glVertexAttribL3dvEXT");
    LOAD_GL_EXTENSION(glVertexAttribL4d, statusVertexAttribL4d, NOpenGLProc::TVertexAttribL4d, "glVertexAttribL4d", "glVertexAttribL4dARB", "glVertexAttribL4dEXT");
    LOAD_GL_EXTENSION(glVertexAttribL4dv, statusVertexAttribL4dv, NOpenGLProc::TVertexAttribL4dv, "glVertexAttribL4dv", "glVertexAttribL4dvARB", "glVertexAttribL4dvEXT");
    LOAD_GL_EXTENSION(glVertexAttribLPointer, statusVertexAttribLPointer, NOpenGLProc::TVertexAttribLPointer, "glVertexAttribLPointer", "glVertexAttribLPointerARB", "glVertexAttribLPointerEXT");
    LOAD_GL_EXTENSION(glViewportArrayv, statusViewportArrayv, NOpenGLProc::TViewportArrayv, "glViewportArrayv", "glViewportArrayvARB", "glViewportArrayvEXT");
    LOAD_GL_EXTENSION(glViewportIndexedf, statusViewportIndexedf, NOpenGLProc::TViewportIndexedf, "glViewportIndexedf", "glViewportIndexedfARB", "glViewportIndexedfEXT");
    LOAD_GL_EXTENSION(glViewportIndexedfv, statusViewportIndexedfv, NOpenGLProc::TViewportIndexedfv, "glViewportIndexedfv", "glViewportIndexedfvARB", "glViewportIndexedfvEXT");
  }

  // GL_VERSION_4_2
  if(platform >= NEngine::GPU_PLATFORM_GL0402)
  {
    LOAD_GL_EXTENSION(glBindImageTexture, statusBindImageTexture, NOpenGLProc::TBindImageTexture, "glBindImageTexture", "glBindImageTextureARB", "glBindImageTextureEXT");
    LOAD_GL_EXTENSION(glDrawArraysInstancedBaseInstance, statusDrawArraysInstancedBaseInstance, NOpenGLProc::TDrawArraysInstancedBaseInstance, "glDrawArraysInstancedBaseInstance", "glDrawArraysInstancedBaseInstanceARB", "glDrawArraysInstancedBaseInstanceEXT");
    LOAD_GL_EXTENSION(glDrawElementsInstancedBaseInstance, statusDrawElementsInstancedBaseInstance, NOpenGLProc::TDrawElementsInstancedBaseInstance, "glDrawElementsInstancedBaseInstance", "glDrawElementsInstancedBaseInstanceARB", "glDrawElementsInstancedBaseInstanceEXT");
    LOAD_GL_EXTENSION(glDrawElementsInstancedBaseVertexBaseInstance, statusDrawElementsInstancedBaseVertexBaseInstance, NOpenGLProc::TDrawElementsInstancedBaseVertexBaseInstance, "glDrawElementsInstancedBaseVertexBaseInstance", "glDrawElementsInstancedBaseVertexBaseInstanceARB", "glDrawElementsInstancedBaseVertexBaseInstanceEXT");
    LOAD_GL_EXTENSION(glDrawTransformFeedbackInstanced, statusDrawTransformFeedbackInstanced, NOpenGLProc::TDrawTransformFeedbackInstanced, "glDrawTransformFeedbackInstanced", "glDrawTransformFeedbackInstancedARB", "glDrawTransformFeedbackInstancedEXT");
    LOAD_GL_EXTENSION(glDrawTransformFeedbackStreamInstanced, statusDrawTransformFeedbackStreamInstanced, NOpenGLProc::TDrawTransformFeedbackStreamInstanced, "glDrawTransformFeedbackStreamInstanced", "glDrawTransformFeedbackStreamInstancedARB", "glDrawTransformFeedbackStreamInstancedEXT");
    LOAD_GL_EXTENSION(glGetActiveAtomicCounterBufferiv, statusGetActiveAtomicCounterBufferiv, NOpenGLProc::TGetActiveAtomicCounterBufferiv, "glGetActiveAtomicCounterBufferiv", "glGetActiveAtomicCounterBufferivARB", "glGetActiveAtomicCounterBufferivEXT");
    LOAD_GL_EXTENSION(glGetInternalformativ, statusGetInternalformativ, NOpenGLProc::TGetInternalformativ, "glGetInternalformativ", "glGetInternalformativARB", "glGetInternalformativEXT");
    LOAD_GL_EXTENSION(glMemoryBarrier, statusMemoryBarrier, NOpenGLProc::TMemoryBarrier, "glMemoryBarrier", "glMemoryBarrierARB", "glMemoryBarrierEXT");
    LOAD_GL_EXTENSION(glTexStorage1D, statusTexStorage1D, NOpenGLProc::TTexStorage1D, "glTexStorage1D", "glTexStorage1DARB", "glTexStorage1DEXT");
    LOAD_GL_EXTENSION(glTexStorage2D, statusTexStorage2D, NOpenGLProc::TTexStorage2D, "glTexStorage2D", "glTexStorage2DARB", "glTexStorage2DEXT");
    LOAD_GL_EXTENSION(glTexStorage3D, statusTexStorage3D, NOpenGLProc::TTexStorage3D, "glTexStorage3D", "glTexStorage3DARB", "glTexStorage3DEXT");
  }

  // GL_VERSION_4_3
  if(platform >= NEngine::GPU_PLATFORM_GL0403)
  {
    LOAD_GL_EXTENSION(glBindVertexBuffer, statusBindVertexBuffer, NOpenGLProc::TBindVertexBuffer, "glBindVertexBuffer", "glBindVertexBufferARB", "glBindVertexBufferEXT");
    LOAD_GL_EXTENSION(glClearBufferData, statusClearBufferData, NOpenGLProc::TClearBufferData, "glClearBufferData", "glClearBufferDataARB", "glClearBufferDataEXT");
    LOAD_GL_EXTENSION(glClearBufferSubData, statusClearBufferSubData, NOpenGLProc::TClearBufferSubData, "glClearBufferSubData", "glClearBufferSubDataARB", "glClearBufferSubDataEXT");
    LOAD_GL_EXTENSION(glCopyImageSubData, statusCopyImageSubData, NOpenGLProc::TCopyImageSubData, "glCopyImageSubData", "glCopyImageSubDataARB", "glCopyImageSubDataEXT");
    LOAD_GL_EXTENSION(glDebugMessageCallback, statusDebugMessageCallback, NOpenGLProc::TDebugMessageCallback, "glDebugMessageCallback", "glDebugMessageCallbackARB", "glDebugMessageCallbackEXT");
    LOAD_GL_EXTENSION(glDebugMessageControl, statusDebugMessageControl, NOpenGLProc::TDebugMessageControl, "glDebugMessageControl", "glDebugMessageControlARB", "glDebugMessageControlEXT");
    LOAD_GL_EXTENSION(glDebugMessageInsert, statusDebugMessageInsert, NOpenGLProc::TDebugMessageInsert, "glDebugMessageInsert", "glDebugMessageInsertARB", "glDebugMessageInsertEXT");
    LOAD_GL_EXTENSION(glDispatchCompute, statusDispatchCompute, NOpenGLProc::TDispatchCompute, "glDispatchCompute", "glDispatchComputeARB", "glDispatchComputeEXT");
    LOAD_GL_EXTENSION(glDispatchComputeIndirect, statusDispatchComputeIndirect, NOpenGLProc::TDispatchComputeIndirect, "glDispatchComputeIndirect", "glDispatchComputeIndirectARB", "glDispatchComputeIndirectEXT");
    LOAD_GL_EXTENSION(glFramebufferParameteri, statusFramebufferParameteri, NOpenGLProc::TFramebufferParameteri, "glFramebufferParameteri", "glFramebufferParameteriARB", "glFramebufferParameteriEXT");
    LOAD_GL_EXTENSION(glGetDebugMessageLog, statusGetDebugMessageLog, NOpenGLProc::TGetDebugMessageLog, "glGetDebugMessageLog", "glGetDebugMessageLogARB", "glGetDebugMessageLogEXT");
    LOAD_GL_EXTENSION(glGetFramebufferParameteriv, statusGetFramebufferParameteriv, NOpenGLProc::TGetFramebufferParameteriv, "glGetFramebufferParameteriv", "glGetFramebufferParameterivARB", "glGetFramebufferParameterivEXT");
    LOAD_GL_EXTENSION(glGetInternalformati64v, statusGetInternalformati64v, NOpenGLProc::TGetInternalformati64v, "glGetInternalformati64v", "glGetInternalformati64vARB", "glGetInternalformati64vEXT");
    LOAD_GL_EXTENSION(glGetObjectLabel, statusGetObjectLabel, NOpenGLProc::TGetObjectLabel, "glGetObjectLabel", "glGetObjectLabelARB", "glGetObjectLabelEXT");
    LOAD_GL_EXTENSION(glGetObjectPtrLabel, statusGetObjectPtrLabel, NOpenGLProc::TGetObjectPtrLabel, "glGetObjectPtrLabel", "glGetObjectPtrLabelARB", "glGetObjectPtrLabelEXT");
    LOAD_GL_EXTENSION(glGetProgramInterfaceiv, statusGetProgramInterfaceiv, NOpenGLProc::TGetProgramInterfaceiv, "glGetProgramInterfaceiv", "glGetProgramInterfaceivARB", "glGetProgramInterfaceivEXT");
    LOAD_GL_EXTENSION(glGetProgramResourceIndex, statusGetProgramResourceIndex, NOpenGLProc::TGetProgramResourceIndex, "glGetProgramResourceIndex", "glGetProgramResourceIndexARB", "glGetProgramResourceIndexEXT");
    LOAD_GL_EXTENSION(glGetProgramResourceLocation, statusGetProgramResourceLocation, NOpenGLProc::TGetProgramResourceLocation, "glGetProgramResourceLocation", "glGetProgramResourceLocationARB", "glGetProgramResourceLocationEXT");
    LOAD_GL_EXTENSION(glGetProgramResourceLocationIndex, statusGetProgramResourceLocationIndex, NOpenGLProc::TGetProgramResourceLocationIndex, "glGetProgramResourceLocationIndex", "glGetProgramResourceLocationIndexARB", "glGetProgramResourceLocationIndexEXT");
    LOAD_GL_EXTENSION(glGetProgramResourceName, statusGetProgramResourceName, NOpenGLProc::TGetProgramResourceName, "glGetProgramResourceName", "glGetProgramResourceNameARB", "glGetProgramResourceNameEXT");
    LOAD_GL_EXTENSION(glGetProgramResourceiv, statusGetProgramResourceiv, NOpenGLProc::TGetProgramResourceiv, "glGetProgramResourceiv", "glGetProgramResourceivARB", "glGetProgramResourceivEXT");
    LOAD_GL_EXTENSION(glInvalidateBufferData, statusInvalidateBufferData, NOpenGLProc::TInvalidateBufferData, "glInvalidateBufferData", "glInvalidateBufferDataARB", "glInvalidateBufferDataEXT");
    LOAD_GL_EXTENSION(glInvalidateBufferSubData, statusInvalidateBufferSubData, NOpenGLProc::TInvalidateBufferSubData, "glInvalidateBufferSubData", "glInvalidateBufferSubDataARB", "glInvalidateBufferSubDataEXT");
    LOAD_GL_EXTENSION(glInvalidateFramebuffer, statusInvalidateFramebuffer, NOpenGLProc::TInvalidateFramebuffer, "glInvalidateFramebuffer", "glInvalidateFramebufferARB", "glInvalidateFramebufferEXT");
    LOAD_GL_EXTENSION(glInvalidateSubFramebuffer, statusInvalidateSubFramebuffer, NOpenGLProc::TInvalidateSubFramebuffer, "glInvalidateSubFramebuffer", "glInvalidateSubFramebufferARB", "glInvalidateSubFramebufferEXT");
    LOAD_GL_EXTENSION(glInvalidateTexImage, statusInvalidateTexImage, NOpenGLProc::TInvalidateTexImage, "glInvalidateTexImage", "glInvalidateTexImageARB", "glInvalidateTexImageEXT");
    LOAD_GL_EXTENSION(glInvalidateTexSubImage, statusInvalidateTexSubImage, NOpenGLProc::TInvalidateTexSubImage, "glInvalidateTexSubImage", "glInvalidateTexSubImageARB", "glInvalidateTexSubImageEXT");
    LOAD_GL_EXTENSION(glMultiDrawArraysIndirect, statusMultiDrawArraysIndirect, NOpenGLProc::TMultiDrawArraysIndirect, "glMultiDrawArraysIndirect", "glMultiDrawArraysIndirectARB", "glMultiDrawArraysIndirectEXT");
    LOAD_GL_EXTENSION(glMultiDrawElementsIndirect, statusMultiDrawElementsIndirect, NOpenGLProc::TMultiDrawElementsIndirect, "glMultiDrawElementsIndirect", "glMultiDrawElementsIndirectARB", "glMultiDrawElementsIndirectEXT");
    LOAD_GL_EXTENSION(glObjectLabel, statusObjectLabel, NOpenGLProc::TObjectLabel, "glObjectLabel", "glObjectLabelARB", "glObjectLabelEXT");
    LOAD_GL_EXTENSION(glObjectPtrLabel, statusObjectPtrLabel, NOpenGLProc::TObjectPtrLabel, "glObjectPtrLabel", "glObjectPtrLabelARB", "glObjectPtrLabelEXT");
    LOAD_GL_EXTENSION(glPopDebugGroup, statusPopDebugGroup, NOpenGLProc::TPopDebugGroup, "glPopDebugGroup", "glPopDebugGroupARB", "glPopDebugGroupEXT");
    LOAD_GL_EXTENSION(glPushDebugGroup, statusPushDebugGroup, NOpenGLProc::TPushDebugGroup, "glPushDebugGroup", "glPushDebugGroupARB", "glPushDebugGroupEXT");
    LOAD_GL_EXTENSION(glShaderStorageBlockBinding, statusShaderStorageBlockBinding, NOpenGLProc::TShaderStorageBlockBinding, "glShaderStorageBlockBinding", "glShaderStorageBlockBindingARB", "glShaderStorageBlockBindingEXT");
    LOAD_GL_EXTENSION(glTexBufferRange, statusTexBufferRange, NOpenGLProc::TTexBufferRange, "glTexBufferRange", "glTexBufferRangeARB", "glTexBufferRangeEXT");
    LOAD_GL_EXTENSION(glTexStorage2DMultisample, statusTexStorage2DMultisample, NOpenGLProc::TTexStorage2DMultisample, "glTexStorage2DMultisample", "glTexStorage2DMultisampleARB", "glTexStorage2DMultisampleEXT");
    LOAD_GL_EXTENSION(glTexStorage3DMultisample, statusTexStorage3DMultisample, NOpenGLProc::TTexStorage3DMultisample, "glTexStorage3DMultisample", "glTexStorage3DMultisampleARB", "glTexStorage3DMultisampleEXT");
    LOAD_GL_EXTENSION(glTextureView, statusTextureView, NOpenGLProc::TTextureView, "glTextureView", "glTextureViewARB", "glTextureViewEXT");
    LOAD_GL_EXTENSION(glVertexAttribBinding, statusVertexAttribBinding, NOpenGLProc::TVertexAttribBinding, "glVertexAttribBinding", "glVertexAttribBindingARB", "glVertexAttribBindingEXT");
    LOAD_GL_EXTENSION(glVertexAttribFormat, statusVertexAttribFormat, NOpenGLProc::TVertexAttribFormat, "glVertexAttribFormat", "glVertexAttribFormatARB", "glVertexAttribFormatEXT");
    LOAD_GL_EXTENSION(glVertexAttribIFormat, statusVertexAttribIFormat, NOpenGLProc::TVertexAttribIFormat, "glVertexAttribIFormat", "glVertexAttribIFormatARB", "glVertexAttribIFormatEXT");
    LOAD_GL_EXTENSION(glVertexAttribLFormat, statusVertexAttribLFormat, NOpenGLProc::TVertexAttribLFormat, "glVertexAttribLFormat", "glVertexAttribLFormatARB", "glVertexAttribLFormatEXT");
    LOAD_GL_EXTENSION(glVertexBindingDivisor, statusVertexBindingDivisor, NOpenGLProc::TVertexBindingDivisor, "glVertexBindingDivisor", "glVertexBindingDivisorARB", "glVertexBindingDivisorEXT");
  }

  // GL_VERSION_4_4
  if(platform >= NEngine::GPU_PLATFORM_GL0404)
  {
    LOAD_GL_EXTENSION(glBindBuffersBase, statusBindBuffersBase, NOpenGLProc::TBindBuffersBase, "glBindBuffersBase", "glBindBuffersBaseARB", "glBindBuffersBaseEXT");
    LOAD_GL_EXTENSION(glBindBuffersRange, statusBindBuffersRange, NOpenGLProc::TBindBuffersRange, "glBindBuffersRange", "glBindBuffersRangeARB", "glBindBuffersRangeEXT");
    LOAD_GL_EXTENSION(glBindImageTextures, statusBindImageTextures, NOpenGLProc::TBindImageTextures, "glBindImageTextures", "glBindImageTexturesARB", "glBindImageTexturesEXT");
    LOAD_GL_EXTENSION(glBindSamplers, statusBindSamplers, NOpenGLProc::TBindSamplers, "glBindSamplers", "glBindSamplersARB", "glBindSamplersEXT");
    LOAD_GL_EXTENSION(glBindTextures, statusBindTextures, NOpenGLProc::TBindTextures, "glBindTextures", "glBindTexturesARB", "glBindTexturesEXT");
    LOAD_GL_EXTENSION(glBindVertexBuffers, statusBindVertexBuffers, NOpenGLProc::TBindVertexBuffers, "glBindVertexBuffers", "glBindVertexBuffersARB", "glBindVertexBuffersEXT");
    LOAD_GL_EXTENSION(glBufferStorage, statusBufferStorage, NOpenGLProc::TBufferStorage, "glBufferStorage", "glBufferStorageARB", "glBufferStorageEXT");
    LOAD_GL_EXTENSION(glClearTexImage, statusClearTexImage, NOpenGLProc::TClearTexImage, "glClearTexImage", "glClearTexImageARB", "glClearTexImageEXT");
    LOAD_GL_EXTENSION(glClearTexSubImage, statusClearTexSubImage, NOpenGLProc::TClearTexSubImage, "glClearTexSubImage", "glClearTexSubImageARB", "glClearTexSubImageEXT");
  }

  // GL_VERSION_4_5
  if(platform >= NEngine::GPU_PLATFORM_GL0405)
  {
    LOAD_GL_EXTENSION(glBindTextureUnit, statusBindTextureUnit, NOpenGLProc::TBindTextureUnit, "glBindTextureUnit", "glBindTextureUnitARB", "glBindTextureUnitEXT");
    LOAD_GL_EXTENSION(glBlitNamedFramebuffer, statusBlitNamedFramebuffer, NOpenGLProc::TBlitNamedFramebuffer, "glBlitNamedFramebuffer", "glBlitNamedFramebufferARB", "glBlitNamedFramebufferEXT");
    LOAD_GL_EXTENSION(glCheckNamedFramebufferStatus, statusCheckNamedFramebufferStatus, NOpenGLProc::TCheckNamedFramebufferStatus, "glCheckNamedFramebufferStatus", "glCheckNamedFramebufferStatusARB", "glCheckNamedFramebufferStatusEXT");
    LOAD_GL_EXTENSION(glClearNamedBufferData, statusClearNamedBufferData, NOpenGLProc::TClearNamedBufferData, "glClearNamedBufferData", "glClearNamedBufferDataARB", "glClearNamedBufferDataEXT");
    LOAD_GL_EXTENSION(glClearNamedBufferSubData, statusClearNamedBufferSubData, NOpenGLProc::TClearNamedBufferSubData, "glClearNamedBufferSubData", "glClearNamedBufferSubDataARB", "glClearNamedBufferSubDataEXT");
    LOAD_GL_EXTENSION(glClearNamedFramebufferfi, statusClearNamedFramebufferfi, NOpenGLProc::TClearNamedFramebufferfi, "glClearNamedFramebufferfi", "glClearNamedFramebufferfiARB", "glClearNamedFramebufferfiEXT");
    LOAD_GL_EXTENSION(glClearNamedFramebufferfv, statusClearNamedFramebufferfv, NOpenGLProc::TClearNamedFramebufferfv, "glClearNamedFramebufferfv", "glClearNamedFramebufferfvARB", "glClearNamedFramebufferfvEXT");
    LOAD_GL_EXTENSION(glClearNamedFramebufferiv, statusClearNamedFramebufferiv, NOpenGLProc::TClearNamedFramebufferiv, "glClearNamedFramebufferiv", "glClearNamedFramebufferivARB", "glClearNamedFramebufferivEXT");
    LOAD_GL_EXTENSION(glClearNamedFramebufferuiv, statusClearNamedFramebufferuiv, NOpenGLProc::TClearNamedFramebufferuiv, "glClearNamedFramebufferuiv", "glClearNamedFramebufferuivARB", "glClearNamedFramebufferuivEXT");
    LOAD_GL_EXTENSION(glClipControl, statusClipControl, NOpenGLProc::TClipControl, "glClipControl", "glClipControlARB", "glClipControlEXT");
    LOAD_GL_EXTENSION(glCompressedTextureSubImage1D, statusCompressedTextureSubImage1D, NOpenGLProc::TCompressedTextureSubImage1D, "glCompressedTextureSubImage1D", "glCompressedTextureSubImage1DARB", "glCompressedTextureSubImage1DEXT");
    LOAD_GL_EXTENSION(glCompressedTextureSubImage2D, statusCompressedTextureSubImage2D, NOpenGLProc::TCompressedTextureSubImage2D, "glCompressedTextureSubImage2D", "glCompressedTextureSubImage2DARB", "glCompressedTextureSubImage2DEXT");
    LOAD_GL_EXTENSION(glCompressedTextureSubImage3D, statusCompressedTextureSubImage3D, NOpenGLProc::TCompressedTextureSubImage3D, "glCompressedTextureSubImage3D", "glCompressedTextureSubImage3DARB", "glCompressedTextureSubImage3DEXT");
    LOAD_GL_EXTENSION(glCopyNamedBufferSubData, statusCopyNamedBufferSubData, NOpenGLProc::TCopyNamedBufferSubData, "glCopyNamedBufferSubData", "glCopyNamedBufferSubDataARB", "glCopyNamedBufferSubDataEXT");
    LOAD_GL_EXTENSION(glCopyTextureSubImage1D, statusCopyTextureSubImage1D, NOpenGLProc::TCopyTextureSubImage1D, "glCopyTextureSubImage1D", "glCopyTextureSubImage1DARB", "glCopyTextureSubImage1DEXT");
    LOAD_GL_EXTENSION(glCopyTextureSubImage2D, statusCopyTextureSubImage2D, NOpenGLProc::TCopyTextureSubImage2D, "glCopyTextureSubImage2D", "glCopyTextureSubImage2DARB", "glCopyTextureSubImage2DEXT");
    LOAD_GL_EXTENSION(glCopyTextureSubImage3D, statusCopyTextureSubImage3D, NOpenGLProc::TCopyTextureSubImage3D, "glCopyTextureSubImage3D", "glCopyTextureSubImage3DARB", "glCopyTextureSubImage3DEXT");
    LOAD_GL_EXTENSION(glCreateBuffers, statusCreateBuffers, NOpenGLProc::TCreateBuffers, "glCreateBuffers", "glCreateBuffersARB", "glCreateBuffersEXT");
    LOAD_GL_EXTENSION(glCreateFramebuffers, statusCreateFramebuffers, NOpenGLProc::TCreateFramebuffers, "glCreateFramebuffers", "glCreateFramebuffersARB", "glCreateFramebuffersEXT");
    LOAD_GL_EXTENSION(glCreateProgramPipelines, statusCreateProgramPipelines, NOpenGLProc::TCreateProgramPipelines, "glCreateProgramPipelines", "glCreateProgramPipelinesARB", "glCreateProgramPipelinesEXT");
    LOAD_GL_EXTENSION(glCreateQueries, statusCreateQueries, NOpenGLProc::TCreateQueries, "glCreateQueries", "glCreateQueriesARB", "glCreateQueriesEXT");
    LOAD_GL_EXTENSION(glCreateRenderbuffers, statusCreateRenderbuffers, NOpenGLProc::TCreateRenderbuffers, "glCreateRenderbuffers", "glCreateRenderbuffersARB", "glCreateRenderbuffersEXT");
    LOAD_GL_EXTENSION(glCreateSamplers, statusCreateSamplers, NOpenGLProc::TCreateSamplers, "glCreateSamplers", "glCreateSamplersARB", "glCreateSamplersEXT");
    LOAD_GL_EXTENSION(glCreateTextures, statusCreateTextures, NOpenGLProc::TCreateTextures, "glCreateTextures", "glCreateTexturesARB", "glCreateTexturesEXT");
    LOAD_GL_EXTENSION(glCreateTransformFeedbacks, statusCreateTransformFeedbacks, NOpenGLProc::TCreateTransformFeedbacks, "glCreateTransformFeedbacks", "glCreateTransformFeedbacksARB", "glCreateTransformFeedbacksEXT");
    LOAD_GL_EXTENSION(glCreateVertexArrays, statusCreateVertexArrays, NOpenGLProc::TCreateVertexArrays, "glCreateVertexArrays", "glCreateVertexArraysARB", "glCreateVertexArraysEXT");
    LOAD_GL_EXTENSION(glDisableVertexArrayAttrib, statusDisableVertexArrayAttrib, NOpenGLProc::TDisableVertexArrayAttrib, "glDisableVertexArrayAttrib", "glDisableVertexArrayAttribARB", "glDisableVertexArrayAttribEXT");
    LOAD_GL_EXTENSION(glEnableVertexArrayAttrib, statusEnableVertexArrayAttrib, NOpenGLProc::TEnableVertexArrayAttrib, "glEnableVertexArrayAttrib", "glEnableVertexArrayAttribARB", "glEnableVertexArrayAttribEXT");
    LOAD_GL_EXTENSION(glFlushMappedNamedBufferRange, statusFlushMappedNamedBufferRange, NOpenGLProc::TFlushMappedNamedBufferRange, "glFlushMappedNamedBufferRange", "glFlushMappedNamedBufferRangeARB", "glFlushMappedNamedBufferRangeEXT");
    LOAD_GL_EXTENSION(glGenerateTextureMipmap, statusGenerateTextureMipmap, NOpenGLProc::TGenerateTextureMipmap, "glGenerateTextureMipmap", "glGenerateTextureMipmapARB", "glGenerateTextureMipmapEXT");
    LOAD_GL_EXTENSION(glGetCompressedTextureImage, statusGetCompressedTextureImage, NOpenGLProc::TGetCompressedTextureImage, "glGetCompressedTextureImage", "glGetCompressedTextureImageARB", "glGetCompressedTextureImageEXT");
    LOAD_GL_EXTENSION(glGetCompressedTextureSubImage, statusGetCompressedTextureSubImage, NOpenGLProc::TGetCompressedTextureSubImage, "glGetCompressedTextureSubImage", "glGetCompressedTextureSubImageARB", "glGetCompressedTextureSubImageEXT");
    LOAD_GL_EXTENSION(glGetGraphicsResetStatus, statusGetGraphicsResetStatus, NOpenGLProc::TGetGraphicsResetStatus, "glGetGraphicsResetStatus", "glGetGraphicsResetStatusARB", "glGetGraphicsResetStatusEXT");
    LOAD_GL_EXTENSION(glGetNamedBufferParameteri64v, statusGetNamedBufferParameteri64v, NOpenGLProc::TGetNamedBufferParameteri64v, "glGetNamedBufferParameteri64v", "glGetNamedBufferParameteri64vARB", "glGetNamedBufferParameteri64vEXT");
    LOAD_GL_EXTENSION(glGetNamedBufferParameteriv, statusGetNamedBufferParameteriv, NOpenGLProc::TGetNamedBufferParameteriv, "glGetNamedBufferParameteriv", "glGetNamedBufferParameterivARB", "glGetNamedBufferParameterivEXT");
    LOAD_GL_EXTENSION(glGetNamedBufferPointerv, statusGetNamedBufferPointerv, NOpenGLProc::TGetNamedBufferPointerv, "glGetNamedBufferPointerv", "glGetNamedBufferPointervARB", "glGetNamedBufferPointervEXT");
    LOAD_GL_EXTENSION(glGetNamedBufferSubData, statusGetNamedBufferSubData, NOpenGLProc::TGetNamedBufferSubData, "glGetNamedBufferSubData", "glGetNamedBufferSubDataARB", "glGetNamedBufferSubDataEXT");
    LOAD_GL_EXTENSION(glGetNamedFramebufferAttachmentParameteriv, statusGetNamedFramebufferAttachmentParameteriv, NOpenGLProc::TGetNamedFramebufferAttachmentParameteriv, "glGetNamedFramebufferAttachmentParameteriv", "glGetNamedFramebufferAttachmentParameterivARB", "glGetNamedFramebufferAttachmentParameterivEXT");
    LOAD_GL_EXTENSION(glGetNamedFramebufferParameteriv, statusGetNamedFramebufferParameteriv, NOpenGLProc::TGetNamedFramebufferParameteriv, "glGetNamedFramebufferParameteriv", "glGetNamedFramebufferParameterivARB", "glGetNamedFramebufferParameterivEXT");
    LOAD_GL_EXTENSION(glGetNamedRenderbufferParameteriv, statusGetNamedRenderbufferParameteriv, NOpenGLProc::TGetNamedRenderbufferParameteriv, "glGetNamedRenderbufferParameteriv", "glGetNamedRenderbufferParameterivARB", "glGetNamedRenderbufferParameterivEXT");
    LOAD_GL_EXTENSION(glGetQueryBufferObjecti64v, statusGetQueryBufferObjecti64v, NOpenGLProc::TGetQueryBufferObjecti64v, "glGetQueryBufferObjecti64v", "glGetQueryBufferObjecti64vARB", "glGetQueryBufferObjecti64vEXT");
    LOAD_GL_EXTENSION(glGetQueryBufferObjectiv, statusGetQueryBufferObjectiv, NOpenGLProc::TGetQueryBufferObjectiv, "glGetQueryBufferObjectiv", "glGetQueryBufferObjectivARB", "glGetQueryBufferObjectivEXT");
    LOAD_GL_EXTENSION(glGetQueryBufferObjectui64v, statusGetQueryBufferObjectui64v, NOpenGLProc::TGetQueryBufferObjectui64v, "glGetQueryBufferObjectui64v", "glGetQueryBufferObjectui64vARB", "glGetQueryBufferObjectui64vEXT");
    LOAD_GL_EXTENSION(glGetQueryBufferObjectuiv, statusGetQueryBufferObjectuiv, NOpenGLProc::TGetQueryBufferObjectuiv, "glGetQueryBufferObjectuiv", "glGetQueryBufferObjectuivARB", "glGetQueryBufferObjectuivEXT");
    LOAD_GL_EXTENSION(glGetTextureImage, statusGetTextureImage, NOpenGLProc::TGetTextureImage, "glGetTextureImage", "glGetTextureImageARB", "glGetTextureImageEXT");
    LOAD_GL_EXTENSION(glGetTextureLevelParameterfv, statusGetTextureLevelParameterfv, NOpenGLProc::TGetTextureLevelParameterfv, "glGetTextureLevelParameterfv", "glGetTextureLevelParameterfvARB", "glGetTextureLevelParameterfvEXT");
    LOAD_GL_EXTENSION(glGetTextureLevelParameteriv, statusGetTextureLevelParameteriv, NOpenGLProc::TGetTextureLevelParameteriv, "glGetTextureLevelParameteriv", "glGetTextureLevelParameterivARB", "glGetTextureLevelParameterivEXT");
    LOAD_GL_EXTENSION(glGetTextureParameterIiv, statusGetTextureParameterIiv, NOpenGLProc::TGetTextureParameterIiv, "glGetTextureParameterIiv", "glGetTextureParameterIivARB", "glGetTextureParameterIivEXT");
    LOAD_GL_EXTENSION(glGetTextureParameterIuiv, statusGetTextureParameterIuiv, NOpenGLProc::TGetTextureParameterIuiv, "glGetTextureParameterIuiv", "glGetTextureParameterIuivARB", "glGetTextureParameterIuivEXT");
    LOAD_GL_EXTENSION(glGetTextureParameterfv, statusGetTextureParameterfv, NOpenGLProc::TGetTextureParameterfv, "glGetTextureParameterfv", "glGetTextureParameterfvARB", "glGetTextureParameterfvEXT");
    LOAD_GL_EXTENSION(glGetTextureParameteriv, statusGetTextureParameteriv, NOpenGLProc::TGetTextureParameteriv, "glGetTextureParameteriv", "glGetTextureParameterivARB", "glGetTextureParameterivEXT");
    LOAD_GL_EXTENSION(glGetTextureSubImage, statusGetTextureSubImage, NOpenGLProc::TGetTextureSubImage, "glGetTextureSubImage", "glGetTextureSubImageARB", "glGetTextureSubImageEXT");
    LOAD_GL_EXTENSION(glGetTransformFeedbacki64_v, statusGetTransformFeedbacki64_v, NOpenGLProc::TGetTransformFeedbacki64_v, "glGetTransformFeedbacki64_v", "glGetTransformFeedbacki64_vARB", "glGetTransformFeedbacki64_vEXT");
    LOAD_GL_EXTENSION(glGetTransformFeedbacki_v, statusGetTransformFeedbacki_v, NOpenGLProc::TGetTransformFeedbacki_v, "glGetTransformFeedbacki_v", "glGetTransformFeedbacki_vARB", "glGetTransformFeedbacki_vEXT");
    LOAD_GL_EXTENSION(glGetTransformFeedbackiv, statusGetTransformFeedbackiv, NOpenGLProc::TGetTransformFeedbackiv, "glGetTransformFeedbackiv", "glGetTransformFeedbackivARB", "glGetTransformFeedbackivEXT");
    LOAD_GL_EXTENSION(glGetVertexArrayIndexed64iv, statusGetVertexArrayIndexed64iv, NOpenGLProc::TGetVertexArrayIndexed64iv, "glGetVertexArrayIndexed64iv", "glGetVertexArrayIndexed64ivARB", "glGetVertexArrayIndexed64ivEXT");
    LOAD_GL_EXTENSION(glGetVertexArrayIndexediv, statusGetVertexArrayIndexediv, NOpenGLProc::TGetVertexArrayIndexediv, "glGetVertexArrayIndexediv", "glGetVertexArrayIndexedivARB", "glGetVertexArrayIndexedivEXT");
    LOAD_GL_EXTENSION(glGetVertexArrayiv, statusGetVertexArrayiv, NOpenGLProc::TGetVertexArrayiv, "glGetVertexArrayiv", "glGetVertexArrayivARB", "glGetVertexArrayivEXT");
    LOAD_GL_EXTENSION(glGetnCompressedTexImage, statusGetnCompressedTexImage, NOpenGLProc::TGetnCompressedTexImage, "glGetnCompressedTexImage", "glGetnCompressedTexImageARB", "glGetnCompressedTexImageEXT");
    LOAD_GL_EXTENSION(glGetnTexImage, statusGetnTexImage, NOpenGLProc::TGetnTexImage, "glGetnTexImage", "glGetnTexImageARB", "glGetnTexImageEXT");
    LOAD_GL_EXTENSION(glGetnUniformdv, statusGetnUniformdv, NOpenGLProc::TGetnUniformdv, "glGetnUniformdv", "glGetnUniformdvARB", "glGetnUniformdvEXT");
    LOAD_GL_EXTENSION(glGetnUniformfv, statusGetnUniformfv, NOpenGLProc::TGetnUniformfv, "glGetnUniformfv", "glGetnUniformfvARB", "glGetnUniformfvEXT");
    LOAD_GL_EXTENSION(glGetnUniformiv, statusGetnUniformiv, NOpenGLProc::TGetnUniformiv, "glGetnUniformiv", "glGetnUniformivARB", "glGetnUniformivEXT");
    LOAD_GL_EXTENSION(glGetnUniformuiv, statusGetnUniformuiv, NOpenGLProc::TGetnUniformuiv, "glGetnUniformuiv", "glGetnUniformuivARB", "glGetnUniformuivEXT");
    LOAD_GL_EXTENSION(glInvalidateNamedFramebufferData, statusInvalidateNamedFramebufferData, NOpenGLProc::TInvalidateNamedFramebufferData, "glInvalidateNamedFramebufferData", "glInvalidateNamedFramebufferDataARB", "glInvalidateNamedFramebufferDataEXT");
    LOAD_GL_EXTENSION(glInvalidateNamedFramebufferSubData, statusInvalidateNamedFramebufferSubData, NOpenGLProc::TInvalidateNamedFramebufferSubData, "glInvalidateNamedFramebufferSubData", "glInvalidateNamedFramebufferSubDataARB", "glInvalidateNamedFramebufferSubDataEXT");
    LOAD_GL_EXTENSION(glMapNamedBuffer, statusMapNamedBuffer, NOpenGLProc::TMapNamedBuffer, "glMapNamedBuffer", "glMapNamedBufferARB", "glMapNamedBufferEXT");
    LOAD_GL_EXTENSION(glMapNamedBufferRange, statusMapNamedBufferRange, NOpenGLProc::TMapNamedBufferRange, "glMapNamedBufferRange", "glMapNamedBufferRangeARB", "glMapNamedBufferRangeEXT");
    LOAD_GL_EXTENSION(glMemoryBarrierByRegion, statusMemoryBarrierByRegion, NOpenGLProc::TMemoryBarrierByRegion, "glMemoryBarrierByRegion", "glMemoryBarrierByRegionARB", "glMemoryBarrierByRegionEXT");
    LOAD_GL_EXTENSION(glNamedBufferData, statusNamedBufferData, NOpenGLProc::TNamedBufferData, "glNamedBufferData", "glNamedBufferDataARB", "glNamedBufferDataEXT");
    LOAD_GL_EXTENSION(glNamedBufferStorage, statusNamedBufferStorage, NOpenGLProc::TNamedBufferStorage, "glNamedBufferStorage", "glNamedBufferStorageARB", "glNamedBufferStorageEXT");
    LOAD_GL_EXTENSION(glNamedBufferSubData, statusNamedBufferSubData, NOpenGLProc::TNamedBufferSubData, "glNamedBufferSubData", "glNamedBufferSubDataARB", "glNamedBufferSubDataEXT");
    LOAD_GL_EXTENSION(glNamedFramebufferDrawBuffer, statusNamedFramebufferDrawBuffer, NOpenGLProc::TNamedFramebufferDrawBuffer, "glNamedFramebufferDrawBuffer", "glNamedFramebufferDrawBufferARB", "glNamedFramebufferDrawBufferEXT");
    LOAD_GL_EXTENSION(glNamedFramebufferDrawBuffers, statusNamedFramebufferDrawBuffers, NOpenGLProc::TNamedFramebufferDrawBuffers, "glNamedFramebufferDrawBuffers", "glNamedFramebufferDrawBuffersARB", "glNamedFramebufferDrawBuffersEXT");
    LOAD_GL_EXTENSION(glNamedFramebufferParameteri, statusNamedFramebufferParameteri, NOpenGLProc::TNamedFramebufferParameteri, "glNamedFramebufferParameteri", "glNamedFramebufferParameteriARB", "glNamedFramebufferParameteriEXT");
    LOAD_GL_EXTENSION(glNamedFramebufferReadBuffer, statusNamedFramebufferReadBuffer, NOpenGLProc::TNamedFramebufferReadBuffer, "glNamedFramebufferReadBuffer", "glNamedFramebufferReadBufferARB", "glNamedFramebufferReadBufferEXT");
    LOAD_GL_EXTENSION(glNamedFramebufferRenderbuffer, statusNamedFramebufferRenderbuffer, NOpenGLProc::TNamedFramebufferRenderbuffer, "glNamedFramebufferRenderbuffer", "glNamedFramebufferRenderbufferARB", "glNamedFramebufferRenderbufferEXT");
    LOAD_GL_EXTENSION(glNamedFramebufferTexture, statusNamedFramebufferTexture, NOpenGLProc::TNamedFramebufferTexture, "glNamedFramebufferTexture", "glNamedFramebufferTextureARB", "glNamedFramebufferTextureEXT");
    LOAD_GL_EXTENSION(glNamedFramebufferTextureLayer, statusNamedFramebufferTextureLayer, NOpenGLProc::TNamedFramebufferTextureLayer, "glNamedFramebufferTextureLayer", "glNamedFramebufferTextureLayerARB", "glNamedFramebufferTextureLayerEXT");
    LOAD_GL_EXTENSION(glNamedRenderbufferStorage, statusNamedRenderbufferStorage, NOpenGLProc::TNamedRenderbufferStorage, "glNamedRenderbufferStorage", "glNamedRenderbufferStorageARB", "glNamedRenderbufferStorageEXT");
    LOAD_GL_EXTENSION(glNamedRenderbufferStorageMultisample, statusNamedRenderbufferStorageMultisample, NOpenGLProc::TNamedRenderbufferStorageMultisample, "glNamedRenderbufferStorageMultisample", "glNamedRenderbufferStorageMultisampleARB", "glNamedRenderbufferStorageMultisampleEXT");
    LOAD_GL_EXTENSION(glReadnPixels, statusReadnPixels, NOpenGLProc::TReadnPixels, "glReadnPixels", "glReadnPixelsARB", "glReadnPixelsEXT");
    LOAD_GL_EXTENSION(glTextureBarrier, statusTextureBarrier, NOpenGLProc::TTextureBarrier, "glTextureBarrier", "glTextureBarrierARB", "glTextureBarrierEXT");
    LOAD_GL_EXTENSION(glTextureBuffer, statusTextureBuffer, NOpenGLProc::TTextureBuffer, "glTextureBuffer", "glTextureBufferARB", "glTextureBufferEXT");
    LOAD_GL_EXTENSION(glTextureBufferRange, statusTextureBufferRange, NOpenGLProc::TTextureBufferRange, "glTextureBufferRange", "glTextureBufferRangeARB", "glTextureBufferRangeEXT");
    LOAD_GL_EXTENSION(glTextureParameterIiv, statusTextureParameterIiv, NOpenGLProc::TTextureParameterIiv, "glTextureParameterIiv", "glTextureParameterIivARB", "glTextureParameterIivEXT");
    LOAD_GL_EXTENSION(glTextureParameterIuiv, statusTextureParameterIuiv, NOpenGLProc::TTextureParameterIuiv, "glTextureParameterIuiv", "glTextureParameterIuivARB", "glTextureParameterIuivEXT");
    LOAD_GL_EXTENSION(glTextureParameterf, statusTextureParameterf, NOpenGLProc::TTextureParameterf, "glTextureParameterf", "glTextureParameterfARB", "glTextureParameterfEXT");
    LOAD_GL_EXTENSION(glTextureParameterfv, statusTextureParameterfv, NOpenGLProc::TTextureParameterfv, "glTextureParameterfv", "glTextureParameterfvARB", "glTextureParameterfvEXT");
    LOAD_GL_EXTENSION(glTextureParameteri, statusTextureParameteri, NOpenGLProc::TTextureParameteri, "glTextureParameteri", "glTextureParameteriARB", "glTextureParameteriEXT");
    LOAD_GL_EXTENSION(glTextureParameteriv, statusTextureParameteriv, NOpenGLProc::TTextureParameteriv, "glTextureParameteriv", "glTextureParameterivARB", "glTextureParameterivEXT");
    LOAD_GL_EXTENSION(glTextureStorage1D, statusTextureStorage1D, NOpenGLProc::TTextureStorage1D, "glTextureStorage1D", "glTextureStorage1DARB", "glTextureStorage1DEXT");
    LOAD_GL_EXTENSION(glTextureStorage2D, statusTextureStorage2D, NOpenGLProc::TTextureStorage2D, "glTextureStorage2D", "glTextureStorage2DARB", "glTextureStorage2DEXT");
    LOAD_GL_EXTENSION(glTextureStorage2DMultisample, statusTextureStorage2DMultisample, NOpenGLProc::TTextureStorage2DMultisample, "glTextureStorage2DMultisample", "glTextureStorage2DMultisampleARB", "glTextureStorage2DMultisampleEXT");
    LOAD_GL_EXTENSION(glTextureStorage3D, statusTextureStorage3D, NOpenGLProc::TTextureStorage3D, "glTextureStorage3D", "glTextureStorage3DARB", "glTextureStorage3DEXT");
    LOAD_GL_EXTENSION(glTextureStorage3DMultisample, statusTextureStorage3DMultisample, NOpenGLProc::TTextureStorage3DMultisample, "glTextureStorage3DMultisample", "glTextureStorage3DMultisampleARB", "glTextureStorage3DMultisampleEXT");
    LOAD_GL_EXTENSION(glTextureSubImage1D, statusTextureSubImage1D, NOpenGLProc::TTextureSubImage1D, "glTextureSubImage1D", "glTextureSubImage1DARB", "glTextureSubImage1DEXT");
    LOAD_GL_EXTENSION(glTextureSubImage2D, statusTextureSubImage2D, NOpenGLProc::TTextureSubImage2D, "glTextureSubImage2D", "glTextureSubImage2DARB", "glTextureSubImage2DEXT");
    LOAD_GL_EXTENSION(glTextureSubImage3D, statusTextureSubImage3D, NOpenGLProc::TTextureSubImage3D, "glTextureSubImage3D", "glTextureSubImage3DARB", "glTextureSubImage3DEXT");
    LOAD_GL_EXTENSION(glTransformFeedbackBufferBase, statusTransformFeedbackBufferBase, NOpenGLProc::TTransformFeedbackBufferBase, "glTransformFeedbackBufferBase", "glTransformFeedbackBufferBaseARB", "glTransformFeedbackBufferBaseEXT");
    LOAD_GL_EXTENSION(glTransformFeedbackBufferRange, statusTransformFeedbackBufferRange, NOpenGLProc::TTransformFeedbackBufferRange, "glTransformFeedbackBufferRange", "glTransformFeedbackBufferRangeARB", "glTransformFeedbackBufferRangeEXT");
    LOAD_GL_EXTENSION(glUnmapNamedBuffer, statusUnmapNamedBuffer, NOpenGLProc::TUnmapNamedBuffer, "glUnmapNamedBuffer", "glUnmapNamedBufferARB", "glUnmapNamedBufferEXT");
    LOAD_GL_EXTENSION(glVertexArrayAttribBinding, statusVertexArrayAttribBinding, NOpenGLProc::TVertexArrayAttribBinding, "glVertexArrayAttribBinding", "glVertexArrayAttribBindingARB", "glVertexArrayAttribBindingEXT");
    LOAD_GL_EXTENSION(glVertexArrayAttribFormat, statusVertexArrayAttribFormat, NOpenGLProc::TVertexArrayAttribFormat, "glVertexArrayAttribFormat", "glVertexArrayAttribFormatARB", "glVertexArrayAttribFormatEXT");
    LOAD_GL_EXTENSION(glVertexArrayAttribIFormat, statusVertexArrayAttribIFormat, NOpenGLProc::TVertexArrayAttribIFormat, "glVertexArrayAttribIFormat", "glVertexArrayAttribIFormatARB", "glVertexArrayAttribIFormatEXT");
    LOAD_GL_EXTENSION(glVertexArrayAttribLFormat, statusVertexArrayAttribLFormat, NOpenGLProc::TVertexArrayAttribLFormat, "glVertexArrayAttribLFormat", "glVertexArrayAttribLFormatARB", "glVertexArrayAttribLFormatEXT");
    LOAD_GL_EXTENSION(glVertexArrayBindingDivisor, statusVertexArrayBindingDivisor, NOpenGLProc::TVertexArrayBindingDivisor, "glVertexArrayBindingDivisor", "glVertexArrayBindingDivisorARB", "glVertexArrayBindingDivisorEXT");
    LOAD_GL_EXTENSION(glVertexArrayElementBuffer, statusVertexArrayElementBuffer, NOpenGLProc::TVertexArrayElementBuffer, "glVertexArrayElementBuffer", "glVertexArrayElementBufferARB", "glVertexArrayElementBufferEXT");
    LOAD_GL_EXTENSION(glVertexArrayVertexBuffer, statusVertexArrayVertexBuffer, NOpenGLProc::TVertexArrayVertexBuffer, "glVertexArrayVertexBuffer", "glVertexArrayVertexBufferARB", "glVertexArrayVertexBufferEXT");
    LOAD_GL_EXTENSION(glVertexArrayVertexBuffers, statusVertexArrayVertexBuffers, NOpenGLProc::TVertexArrayVertexBuffers, "glVertexArrayVertexBuffers", "glVertexArrayVertexBuffersARB", "glVertexArrayVertexBuffersEXT");
  }

  context->log("Done.");
}
//------------------------------------------------------------------------------
std::string COpenGL::getStatus() const
{
  std::string status;

  status += "GL_VERSION_1_0\n";
  status += std::string("  blendFunc                                     ")+"   "+" : true"+"\n";
  status += std::string("  clear                                         ")+"   "+" : true"+"\n";
  status += std::string("  clearColor                                    ")+"   "+" : true"+"\n";
  status += std::string("  clearDepth                                    ")+"   "+" : true"+"\n";
  status += std::string("  clearStencil                                  ")+"   "+" : true"+"\n";
  status += std::string("  colorMask                                     ")+"   "+" : true"+"\n";
  status += std::string("  cullFace                                      ")+"   "+" : true"+"\n";
  status += std::string("  depthFunc                                     ")+"   "+" : true"+"\n";
  status += std::string("  depthMask                                     ")+"   "+" : true"+"\n";
  status += std::string("  depthRange                                    ")+"   "+" : true"+"\n";
  status += std::string("  disable                                       ")+"   "+" : true"+"\n";
  status += std::string("  drawBuffer                                    ")+"   "+" : true"+"\n";
  status += std::string("  enable                                        ")+"   "+" : true"+"\n";
  status += std::string("  finish                                        ")+"   "+" : true"+"\n";
  status += std::string("  flush                                         ")+"   "+" : true"+"\n";
  status += std::string("  frontFace                                     ")+"   "+" : true"+"\n";
  status += std::string("  getBooleanv                                   ")+"   "+" : true"+"\n";
  status += std::string("  getDoublev                                    ")+"   "+" : true"+"\n";
  status += std::string("  getError                                      ")+"   "+" : true"+"\n";
  status += std::string("  getFloatv                                     ")+"   "+" : true"+"\n";
  status += std::string("  getIntegerv                                   ")+"   "+" : true"+"\n";
  status += std::string("  getString                                     ")+"   "+" : true"+"\n";
  status += std::string("  getTexImage                                   ")+"   "+" : true"+"\n";
  status += std::string("  getTexLevelParameterfv                        ")+"   "+" : true"+"\n";
  status += std::string("  getTexLevelParameteriv                        ")+"   "+" : true"+"\n";
  status += std::string("  getTexParameterfv                             ")+"   "+" : true"+"\n";
  status += std::string("  getTexParameteriv                             ")+"   "+" : true"+"\n";
  status += std::string("  hint                                          ")+"   "+" : true"+"\n";
  status += std::string("  isEnabled                                     ")+"   "+" : true"+"\n";
  status += std::string("  lineWidth                                     ")+"   "+" : true"+"\n";
  status += std::string("  logicOp                                       ")+"   "+" : true"+"\n";
  status += std::string("  pixelStoref                                   ")+"   "+" : true"+"\n";
  status += std::string("  pixelStorei                                   ")+"   "+" : true"+"\n";
  status += std::string("  pointSize                                     ")+"   "+" : true"+"\n";
  status += std::string("  polygonMode                                   ")+"   "+" : true"+"\n";
  status += std::string("  readBuffer                                    ")+"   "+" : true"+"\n";
  status += std::string("  readPixels                                    ")+"   "+" : true"+"\n";
  status += std::string("  scissor                                       ")+"   "+" : true"+"\n";
  status += std::string("  stencilFunc                                   ")+"   "+" : true"+"\n";
  status += std::string("  stencilMask                                   ")+"   "+" : true"+"\n";
  status += std::string("  stencilOp                                     ")+"   "+" : true"+"\n";
  status += std::string("  texImage1D                                    ")+"   "+" : true"+"\n";
  status += std::string("  texImage2D                                    ")+"   "+" : true"+"\n";
  status += std::string("  texParameterf                                 ")+"   "+" : true"+"\n";
  status += std::string("  texParameterfv                                ")+"   "+" : true"+"\n";
  status += std::string("  texParameteri                                 ")+"   "+" : true"+"\n";
  status += std::string("  texParameteriv                                ")+"   "+" : true"+"\n";
  status += std::string("  viewport                                      ")+"   "+" : true"+"\n";
  status += "\n";
  status += "GL_VERSION_1_1\n";
  status += std::string("  bindTexture                                   ")+"   "+" : true"+"\n";
  status += std::string("  copyTexImage1D                                ")+"   "+" : true"+"\n";
  status += std::string("  copyTexImage2D                                ")+"   "+" : true"+"\n";
  status += std::string("  copyTexSubImage1D                             ")+"   "+" : true"+"\n";
  status += std::string("  copyTexSubImage2D                             ")+"   "+" : true"+"\n";
  status += std::string("  deleteTextures                                ")+"   "+" : true"+"\n";
  status += std::string("  drawArrays                                    ")+"   "+" : true"+"\n";
  status += std::string("  drawElements                                  ")+"   "+" : true"+"\n";
  status += std::string("  genTextures                                   ")+"   "+" : true"+"\n";
  status += std::string("  getPointerv                                   ")+"   "+" : true"+"\n";
  status += std::string("  isTexture                                     ")+"   "+" : true"+"\n";
  status += std::string("  polygonOffset                                 ")+"   "+" : true"+"\n";
  status += std::string("  texSubImage1D                                 ")+"   "+" : true"+"\n";
  status += std::string("  texSubImage2D                                 ")+"   "+" : true"+"\n";
  status += "\n";
  status += "GL_VERSION_1_2\n";
  status += std::string("  copyTexSubImage3D                             ")+((statusCopyTexSubImage3D == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusCopyTexSubImage3D == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glCopyTexSubImage3D) ? "true" : "false")+"\n";
  status += std::string("  drawRangeElements                             ")+((statusDrawRangeElements == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusDrawRangeElements == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glDrawRangeElements) ? "true" : "false")+"\n";
  status += std::string("  texImage3D                                    ")+((statusTexImage3D == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusTexImage3D == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glTexImage3D) ? "true" : "false")+"\n";
  status += std::string("  texSubImage3D                                 ")+((statusTexSubImage3D == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusTexSubImage3D == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glTexSubImage3D) ? "true" : "false")+"\n";
  status += "\n";
  status += "GL_VERSION_1_3\n";
  status += std::string("  activeTexture                                 ")+((statusActiveTexture == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusActiveTexture == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glActiveTexture) ? "true" : "false")+"\n";
  status += std::string("  compressedTexImage1D                          ")+((statusCompressedTexImage1D == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusCompressedTexImage1D == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glCompressedTexImage1D) ? "true" : "false")+"\n";
  status += std::string("  compressedTexImage2D                          ")+((statusCompressedTexImage2D == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusCompressedTexImage2D == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glCompressedTexImage2D) ? "true" : "false")+"\n";
  status += std::string("  compressedTexImage3D                          ")+((statusCompressedTexImage3D == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusCompressedTexImage3D == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glCompressedTexImage3D) ? "true" : "false")+"\n";
  status += std::string("  compressedTexSubImage1D                       ")+((statusCompressedTexSubImage1D == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusCompressedTexSubImage1D == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glCompressedTexSubImage1D) ? "true" : "false")+"\n";
  status += std::string("  compressedTexSubImage2D                       ")+((statusCompressedTexSubImage2D == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusCompressedTexSubImage2D == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glCompressedTexSubImage2D) ? "true" : "false")+"\n";
  status += std::string("  compressedTexSubImage3D                       ")+((statusCompressedTexSubImage3D == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusCompressedTexSubImage3D == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glCompressedTexSubImage3D) ? "true" : "false")+"\n";
  status += std::string("  getCompressedTexImage                         ")+((statusGetCompressedTexImage == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusGetCompressedTexImage == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glGetCompressedTexImage) ? "true" : "false")+"\n";
  status += std::string("  sampleCoverage                                ")+((statusSampleCoverage == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusSampleCoverage == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glSampleCoverage) ? "true" : "false")+"\n";
  status += "\n";
  status += "GL_VERSION_1_4\n";
  status += std::string("  blendColor                                    ")+((statusBlendColor == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusBlendColor == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glBlendColor) ? "true" : "false")+"\n";
  status += std::string("  blendEquation                                 ")+((statusBlendEquation == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusBlendEquation == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glBlendEquation) ? "true" : "false")+"\n";
  status += std::string("  blendFuncSeparate                             ")+((statusBlendFuncSeparate == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusBlendFuncSeparate == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glBlendFuncSeparate) ? "true" : "false")+"\n";
  status += std::string("  multiDrawArrays                               ")+((statusMultiDrawArrays == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusMultiDrawArrays == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glMultiDrawArrays) ? "true" : "false")+"\n";
  status += std::string("  multiDrawElements                             ")+((statusMultiDrawElements == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusMultiDrawElements == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glMultiDrawElements) ? "true" : "false")+"\n";
  status += std::string("  pointParameterf                               ")+((statusPointParameterf == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusPointParameterf == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glPointParameterf) ? "true" : "false")+"\n";
  status += std::string("  pointParameterfv                              ")+((statusPointParameterfv == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusPointParameterfv == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glPointParameterfv) ? "true" : "false")+"\n";
  status += std::string("  pointParameteri                               ")+((statusPointParameteri == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusPointParameteri == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glPointParameteri) ? "true" : "false")+"\n";
  status += std::string("  pointParameteriv                              ")+((statusPointParameteriv == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusPointParameteriv == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glPointParameteriv) ? "true" : "false")+"\n";
  status += "\n";
  status += "GL_VERSION_1_5\n";
  status += std::string("  beginQuery                                    ")+((statusBeginQuery == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusBeginQuery == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glBeginQuery) ? "true" : "false")+"\n";
  status += std::string("  bindBuffer                                    ")+((statusBindBuffer == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusBindBuffer == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glBindBuffer) ? "true" : "false")+"\n";
  status += std::string("  bufferData                                    ")+((statusBufferData == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusBufferData == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glBufferData) ? "true" : "false")+"\n";
  status += std::string("  bufferSubData                                 ")+((statusBufferSubData == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusBufferSubData == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glBufferSubData) ? "true" : "false")+"\n";
  status += std::string("  deleteBuffers                                 ")+((statusDeleteBuffers == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusDeleteBuffers == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glDeleteBuffers) ? "true" : "false")+"\n";
  status += std::string("  deleteQueries                                 ")+((statusDeleteQueries == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusDeleteQueries == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glDeleteQueries) ? "true" : "false")+"\n";
  status += std::string("  endQuery                                      ")+((statusEndQuery == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusEndQuery == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glEndQuery) ? "true" : "false")+"\n";
  status += std::string("  genBuffers                                    ")+((statusGenBuffers == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusGenBuffers == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glGenBuffers) ? "true" : "false")+"\n";
  status += std::string("  genQueries                                    ")+((statusGenQueries == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusGenQueries == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glGenQueries) ? "true" : "false")+"\n";
  status += std::string("  getBufferParameteriv                          ")+((statusGetBufferParameteriv == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusGetBufferParameteriv == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glGetBufferParameteriv) ? "true" : "false")+"\n";
  status += std::string("  getBufferPointerv                             ")+((statusGetBufferPointerv == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusGetBufferPointerv == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glGetBufferPointerv) ? "true" : "false")+"\n";
  status += std::string("  getBufferSubData                              ")+((statusGetBufferSubData == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusGetBufferSubData == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glGetBufferSubData) ? "true" : "false")+"\n";
  status += std::string("  getQueryObjectiv                              ")+((statusGetQueryObjectiv == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusGetQueryObjectiv == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glGetQueryObjectiv) ? "true" : "false")+"\n";
  status += std::string("  getQueryObjectuiv                             ")+((statusGetQueryObjectuiv == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusGetQueryObjectuiv == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glGetQueryObjectuiv) ? "true" : "false")+"\n";
  status += std::string("  getQueryiv                                    ")+((statusGetQueryiv == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusGetQueryiv == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glGetQueryiv) ? "true" : "false")+"\n";
  status += std::string("  isBuffer                                      ")+((statusIsBuffer == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusIsBuffer == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glIsBuffer) ? "true" : "false")+"\n";
  status += std::string("  isQuery                                       ")+((statusIsQuery == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusIsQuery == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glIsQuery) ? "true" : "false")+"\n";
  status += std::string("  mapBuffer                                     ")+((statusMapBuffer == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusMapBuffer == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glMapBuffer) ? "true" : "false")+"\n";
  status += std::string("  unmapBuffer                                   ")+((statusUnmapBuffer == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusUnmapBuffer == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glUnmapBuffer) ? "true" : "false")+"\n";
  status += "\n";
  status += "GL_VERSION_2_0\n";
  status += std::string("  attachShader                                  ")+((statusAttachShader == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusAttachShader == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glAttachShader) ? "true" : "false")+"\n";
  status += std::string("  bindAttribLocation                            ")+((statusBindAttribLocation == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusBindAttribLocation == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glBindAttribLocation) ? "true" : "false")+"\n";
  status += std::string("  blendEquationSeparate                         ")+((statusBlendEquationSeparate == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusBlendEquationSeparate == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glBlendEquationSeparate) ? "true" : "false")+"\n";
  status += std::string("  compileShader                                 ")+((statusCompileShader == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusCompileShader == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glCompileShader) ? "true" : "false")+"\n";
  status += std::string("  createProgram                                 ")+((statusCreateProgram == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusCreateProgram == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glCreateProgram) ? "true" : "false")+"\n";
  status += std::string("  createShader                                  ")+((statusCreateShader == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusCreateShader == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glCreateShader) ? "true" : "false")+"\n";
  status += std::string("  deleteProgram                                 ")+((statusDeleteProgram == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusDeleteProgram == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glDeleteProgram) ? "true" : "false")+"\n";
  status += std::string("  deleteShader                                  ")+((statusDeleteShader == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusDeleteShader == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glDeleteShader) ? "true" : "false")+"\n";
  status += std::string("  detachShader                                  ")+((statusDetachShader == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusDetachShader == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glDetachShader) ? "true" : "false")+"\n";
  status += std::string("  disableVertexAttribArray                      ")+((statusDisableVertexAttribArray == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusDisableVertexAttribArray == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glDisableVertexAttribArray) ? "true" : "false")+"\n";
  status += std::string("  drawBuffers                                   ")+((statusDrawBuffers == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusDrawBuffers == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glDrawBuffers) ? "true" : "false")+"\n";
  status += std::string("  enableVertexAttribArray                       ")+((statusEnableVertexAttribArray == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusEnableVertexAttribArray == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glEnableVertexAttribArray) ? "true" : "false")+"\n";
  status += std::string("  getActiveAttrib                               ")+((statusGetActiveAttrib == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusGetActiveAttrib == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glGetActiveAttrib) ? "true" : "false")+"\n";
  status += std::string("  getActiveUniform                              ")+((statusGetActiveUniform == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusGetActiveUniform == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glGetActiveUniform) ? "true" : "false")+"\n";
  status += std::string("  getAttachedShaders                            ")+((statusGetAttachedShaders == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusGetAttachedShaders == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glGetAttachedShaders) ? "true" : "false")+"\n";
  status += std::string("  getAttribLocation                             ")+((statusGetAttribLocation == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusGetAttribLocation == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glGetAttribLocation) ? "true" : "false")+"\n";
  status += std::string("  getProgramInfoLog                             ")+((statusGetProgramInfoLog == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusGetProgramInfoLog == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glGetProgramInfoLog) ? "true" : "false")+"\n";
  status += std::string("  getProgramiv                                  ")+((statusGetProgramiv == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusGetProgramiv == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glGetProgramiv) ? "true" : "false")+"\n";
  status += std::string("  getShaderInfoLog                              ")+((statusGetShaderInfoLog == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusGetShaderInfoLog == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glGetShaderInfoLog) ? "true" : "false")+"\n";
  status += std::string("  getShaderSource                               ")+((statusGetShaderSource == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusGetShaderSource == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glGetShaderSource) ? "true" : "false")+"\n";
  status += std::string("  getShaderiv                                   ")+((statusGetShaderiv == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusGetShaderiv == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glGetShaderiv) ? "true" : "false")+"\n";
  status += std::string("  getUniformLocation                            ")+((statusGetUniformLocation == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusGetUniformLocation == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glGetUniformLocation) ? "true" : "false")+"\n";
  status += std::string("  getUniformfv                                  ")+((statusGetUniformfv == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusGetUniformfv == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glGetUniformfv) ? "true" : "false")+"\n";
  status += std::string("  getUniformiv                                  ")+((statusGetUniformiv == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusGetUniformiv == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glGetUniformiv) ? "true" : "false")+"\n";
  status += std::string("  getVertexAttribPointerv                       ")+((statusGetVertexAttribPointerv == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusGetVertexAttribPointerv == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glGetVertexAttribPointerv) ? "true" : "false")+"\n";
  status += std::string("  getVertexAttribdv                             ")+((statusGetVertexAttribdv == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusGetVertexAttribdv == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glGetVertexAttribdv) ? "true" : "false")+"\n";
  status += std::string("  getVertexAttribfv                             ")+((statusGetVertexAttribfv == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusGetVertexAttribfv == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glGetVertexAttribfv) ? "true" : "false")+"\n";
  status += std::string("  getVertexAttribiv                             ")+((statusGetVertexAttribiv == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusGetVertexAttribiv == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glGetVertexAttribiv) ? "true" : "false")+"\n";
  status += std::string("  isProgram                                     ")+((statusIsProgram == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusIsProgram == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glIsProgram) ? "true" : "false")+"\n";
  status += std::string("  isShader                                      ")+((statusIsShader == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusIsShader == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glIsShader) ? "true" : "false")+"\n";
  status += std::string("  linkProgram                                   ")+((statusLinkProgram == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusLinkProgram == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glLinkProgram) ? "true" : "false")+"\n";
  status += std::string("  shaderSource                                  ")+((statusShaderSource == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusShaderSource == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glShaderSource) ? "true" : "false")+"\n";
  status += std::string("  stencilFuncSeparate                           ")+((statusStencilFuncSeparate == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusStencilFuncSeparate == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glStencilFuncSeparate) ? "true" : "false")+"\n";
  status += std::string("  stencilMaskSeparate                           ")+((statusStencilMaskSeparate == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusStencilMaskSeparate == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glStencilMaskSeparate) ? "true" : "false")+"\n";
  status += std::string("  stencilOpSeparate                             ")+((statusStencilOpSeparate == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusStencilOpSeparate == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glStencilOpSeparate) ? "true" : "false")+"\n";
  status += std::string("  uniform1f                                     ")+((statusUniform1f == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusUniform1f == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glUniform1f) ? "true" : "false")+"\n";
  status += std::string("  uniform1fv                                    ")+((statusUniform1fv == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusUniform1fv == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glUniform1fv) ? "true" : "false")+"\n";
  status += std::string("  uniform1i                                     ")+((statusUniform1i == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusUniform1i == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glUniform1i) ? "true" : "false")+"\n";
  status += std::string("  uniform1iv                                    ")+((statusUniform1iv == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusUniform1iv == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glUniform1iv) ? "true" : "false")+"\n";
  status += std::string("  uniform2f                                     ")+((statusUniform2f == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusUniform2f == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glUniform2f) ? "true" : "false")+"\n";
  status += std::string("  uniform2fv                                    ")+((statusUniform2fv == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusUniform2fv == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glUniform2fv) ? "true" : "false")+"\n";
  status += std::string("  uniform2i                                     ")+((statusUniform2i == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusUniform2i == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glUniform2i) ? "true" : "false")+"\n";
  status += std::string("  uniform2iv                                    ")+((statusUniform2iv == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusUniform2iv == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glUniform2iv) ? "true" : "false")+"\n";
  status += std::string("  uniform3f                                     ")+((statusUniform3f == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusUniform3f == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glUniform3f) ? "true" : "false")+"\n";
  status += std::string("  uniform3fv                                    ")+((statusUniform3fv == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusUniform3fv == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glUniform3fv) ? "true" : "false")+"\n";
  status += std::string("  uniform3i                                     ")+((statusUniform3i == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusUniform3i == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glUniform3i) ? "true" : "false")+"\n";
  status += std::string("  uniform3iv                                    ")+((statusUniform3iv == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusUniform3iv == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glUniform3iv) ? "true" : "false")+"\n";
  status += std::string("  uniform4f                                     ")+((statusUniform4f == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusUniform4f == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glUniform4f) ? "true" : "false")+"\n";
  status += std::string("  uniform4fv                                    ")+((statusUniform4fv == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusUniform4fv == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glUniform4fv) ? "true" : "false")+"\n";
  status += std::string("  uniform4i                                     ")+((statusUniform4i == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusUniform4i == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glUniform4i) ? "true" : "false")+"\n";
  status += std::string("  uniform4iv                                    ")+((statusUniform4iv == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusUniform4iv == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glUniform4iv) ? "true" : "false")+"\n";
  status += std::string("  uniformMatrix2fv                              ")+((statusUniformMatrix2fv == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusUniformMatrix2fv == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glUniformMatrix2fv) ? "true" : "false")+"\n";
  status += std::string("  uniformMatrix3fv                              ")+((statusUniformMatrix3fv == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusUniformMatrix3fv == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glUniformMatrix3fv) ? "true" : "false")+"\n";
  status += std::string("  uniformMatrix4fv                              ")+((statusUniformMatrix4fv == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusUniformMatrix4fv == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glUniformMatrix4fv) ? "true" : "false")+"\n";
  status += std::string("  useProgram                                    ")+((statusUseProgram == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusUseProgram == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glUseProgram) ? "true" : "false")+"\n";
  status += std::string("  validateProgram                               ")+((statusValidateProgram == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusValidateProgram == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glValidateProgram) ? "true" : "false")+"\n";
  status += std::string("  vertexAttrib1d                                ")+((statusVertexAttrib1d == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusVertexAttrib1d == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glVertexAttrib1d) ? "true" : "false")+"\n";
  status += std::string("  vertexAttrib1dv                               ")+((statusVertexAttrib1dv == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusVertexAttrib1dv == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glVertexAttrib1dv) ? "true" : "false")+"\n";
  status += std::string("  vertexAttrib1f                                ")+((statusVertexAttrib1f == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusVertexAttrib1f == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glVertexAttrib1f) ? "true" : "false")+"\n";
  status += std::string("  vertexAttrib1fv                               ")+((statusVertexAttrib1fv == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusVertexAttrib1fv == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glVertexAttrib1fv) ? "true" : "false")+"\n";
  status += std::string("  vertexAttrib1s                                ")+((statusVertexAttrib1s == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusVertexAttrib1s == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glVertexAttrib1s) ? "true" : "false")+"\n";
  status += std::string("  vertexAttrib1sv                               ")+((statusVertexAttrib1sv == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusVertexAttrib1sv == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glVertexAttrib1sv) ? "true" : "false")+"\n";
  status += std::string("  vertexAttrib2d                                ")+((statusVertexAttrib2d == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusVertexAttrib2d == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glVertexAttrib2d) ? "true" : "false")+"\n";
  status += std::string("  vertexAttrib2dv                               ")+((statusVertexAttrib2dv == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusVertexAttrib2dv == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glVertexAttrib2dv) ? "true" : "false")+"\n";
  status += std::string("  vertexAttrib2f                                ")+((statusVertexAttrib2f == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusVertexAttrib2f == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glVertexAttrib2f) ? "true" : "false")+"\n";
  status += std::string("  vertexAttrib2fv                               ")+((statusVertexAttrib2fv == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusVertexAttrib2fv == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glVertexAttrib2fv) ? "true" : "false")+"\n";
  status += std::string("  vertexAttrib2s                                ")+((statusVertexAttrib2s == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusVertexAttrib2s == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glVertexAttrib2s) ? "true" : "false")+"\n";
  status += std::string("  vertexAttrib2sv                               ")+((statusVertexAttrib2sv == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusVertexAttrib2sv == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glVertexAttrib2sv) ? "true" : "false")+"\n";
  status += std::string("  vertexAttrib3d                                ")+((statusVertexAttrib3d == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusVertexAttrib3d == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glVertexAttrib3d) ? "true" : "false")+"\n";
  status += std::string("  vertexAttrib3dv                               ")+((statusVertexAttrib3dv == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusVertexAttrib3dv == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glVertexAttrib3dv) ? "true" : "false")+"\n";
  status += std::string("  vertexAttrib3f                                ")+((statusVertexAttrib3f == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusVertexAttrib3f == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glVertexAttrib3f) ? "true" : "false")+"\n";
  status += std::string("  vertexAttrib3fv                               ")+((statusVertexAttrib3fv == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusVertexAttrib3fv == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glVertexAttrib3fv) ? "true" : "false")+"\n";
  status += std::string("  vertexAttrib3s                                ")+((statusVertexAttrib3s == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusVertexAttrib3s == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glVertexAttrib3s) ? "true" : "false")+"\n";
  status += std::string("  vertexAttrib3sv                               ")+((statusVertexAttrib3sv == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusVertexAttrib3sv == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glVertexAttrib3sv) ? "true" : "false")+"\n";
  status += std::string("  vertexAttrib4Nbv                              ")+((statusVertexAttrib4Nbv == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusVertexAttrib4Nbv == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glVertexAttrib4Nbv) ? "true" : "false")+"\n";
  status += std::string("  vertexAttrib4Niv                              ")+((statusVertexAttrib4Niv == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusVertexAttrib4Niv == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glVertexAttrib4Niv) ? "true" : "false")+"\n";
  status += std::string("  vertexAttrib4Nsv                              ")+((statusVertexAttrib4Nsv == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusVertexAttrib4Nsv == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glVertexAttrib4Nsv) ? "true" : "false")+"\n";
  status += std::string("  vertexAttrib4Nub                              ")+((statusVertexAttrib4Nub == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusVertexAttrib4Nub == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glVertexAttrib4Nub) ? "true" : "false")+"\n";
  status += std::string("  vertexAttrib4Nubv                             ")+((statusVertexAttrib4Nubv == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusVertexAttrib4Nubv == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glVertexAttrib4Nubv) ? "true" : "false")+"\n";
  status += std::string("  vertexAttrib4Nuiv                             ")+((statusVertexAttrib4Nuiv == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusVertexAttrib4Nuiv == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glVertexAttrib4Nuiv) ? "true" : "false")+"\n";
  status += std::string("  vertexAttrib4Nusv                             ")+((statusVertexAttrib4Nusv == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusVertexAttrib4Nusv == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glVertexAttrib4Nusv) ? "true" : "false")+"\n";
  status += std::string("  vertexAttrib4bv                               ")+((statusVertexAttrib4bv == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusVertexAttrib4bv == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glVertexAttrib4bv) ? "true" : "false")+"\n";
  status += std::string("  vertexAttrib4d                                ")+((statusVertexAttrib4d == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusVertexAttrib4d == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glVertexAttrib4d) ? "true" : "false")+"\n";
  status += std::string("  vertexAttrib4dv                               ")+((statusVertexAttrib4dv == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusVertexAttrib4dv == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glVertexAttrib4dv) ? "true" : "false")+"\n";
  status += std::string("  vertexAttrib4f                                ")+((statusVertexAttrib4f == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusVertexAttrib4f == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glVertexAttrib4f) ? "true" : "false")+"\n";
  status += std::string("  vertexAttrib4fv                               ")+((statusVertexAttrib4fv == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusVertexAttrib4fv == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glVertexAttrib4fv) ? "true" : "false")+"\n";
  status += std::string("  vertexAttrib4iv                               ")+((statusVertexAttrib4iv == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusVertexAttrib4iv == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glVertexAttrib4iv) ? "true" : "false")+"\n";
  status += std::string("  vertexAttrib4s                                ")+((statusVertexAttrib4s == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusVertexAttrib4s == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glVertexAttrib4s) ? "true" : "false")+"\n";
  status += std::string("  vertexAttrib4sv                               ")+((statusVertexAttrib4sv == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusVertexAttrib4sv == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glVertexAttrib4sv) ? "true" : "false")+"\n";
  status += std::string("  vertexAttrib4ubv                              ")+((statusVertexAttrib4ubv == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusVertexAttrib4ubv == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glVertexAttrib4ubv) ? "true" : "false")+"\n";
  status += std::string("  vertexAttrib4uiv                              ")+((statusVertexAttrib4uiv == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusVertexAttrib4uiv == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glVertexAttrib4uiv) ? "true" : "false")+"\n";
  status += std::string("  vertexAttrib4usv                              ")+((statusVertexAttrib4usv == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusVertexAttrib4usv == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glVertexAttrib4usv) ? "true" : "false")+"\n";
  status += std::string("  vertexAttribPointer                           ")+((statusVertexAttribPointer == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusVertexAttribPointer == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glVertexAttribPointer) ? "true" : "false")+"\n";
  status += "\n";
  status += "GL_VERSION_2_1\n";
  status += std::string("  uniformMatrix2x3fv                            ")+((statusUniformMatrix2x3fv == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusUniformMatrix2x3fv == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glUniformMatrix2x3fv) ? "true" : "false")+"\n";
  status += std::string("  uniformMatrix2x4fv                            ")+((statusUniformMatrix2x4fv == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusUniformMatrix2x4fv == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glUniformMatrix2x4fv) ? "true" : "false")+"\n";
  status += std::string("  uniformMatrix3x2fv                            ")+((statusUniformMatrix3x2fv == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusUniformMatrix3x2fv == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glUniformMatrix3x2fv) ? "true" : "false")+"\n";
  status += std::string("  uniformMatrix3x4fv                            ")+((statusUniformMatrix3x4fv == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusUniformMatrix3x4fv == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glUniformMatrix3x4fv) ? "true" : "false")+"\n";
  status += std::string("  uniformMatrix4x2fv                            ")+((statusUniformMatrix4x2fv == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusUniformMatrix4x2fv == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glUniformMatrix4x2fv) ? "true" : "false")+"\n";
  status += std::string("  uniformMatrix4x3fv                            ")+((statusUniformMatrix4x3fv == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusUniformMatrix4x3fv == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glUniformMatrix4x3fv) ? "true" : "false")+"\n";
  status += "\n";
  status += "GL_VERSION_3_0\n";
  status += std::string("  beginConditionalRender                        ")+((statusBeginConditionalRender == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusBeginConditionalRender == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glBeginConditionalRender) ? "true" : "false")+"\n";
  status += std::string("  beginTransformFeedback                        ")+((statusBeginTransformFeedback == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusBeginTransformFeedback == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glBeginTransformFeedback) ? "true" : "false")+"\n";
  status += std::string("  bindBufferBase                                ")+((statusBindBufferBase == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusBindBufferBase == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glBindBufferBase) ? "true" : "false")+"\n";
  status += std::string("  bindBufferRange                               ")+((statusBindBufferRange == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusBindBufferRange == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glBindBufferRange) ? "true" : "false")+"\n";
  status += std::string("  bindFragDataLocation                          ")+((statusBindFragDataLocation == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusBindFragDataLocation == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glBindFragDataLocation) ? "true" : "false")+"\n";
  status += std::string("  bindFramebuffer                               ")+((statusBindFramebuffer == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusBindFramebuffer == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glBindFramebuffer) ? "true" : "false")+"\n";
  status += std::string("  bindRenderbuffer                              ")+((statusBindRenderbuffer == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusBindRenderbuffer == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glBindRenderbuffer) ? "true" : "false")+"\n";
  status += std::string("  bindVertexArray                               ")+((statusBindVertexArray == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusBindVertexArray == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glBindVertexArray) ? "true" : "false")+"\n";
  status += std::string("  blitFramebuffer                               ")+((statusBlitFramebuffer == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusBlitFramebuffer == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glBlitFramebuffer) ? "true" : "false")+"\n";
  status += std::string("  checkFramebufferStatus                        ")+((statusCheckFramebufferStatus == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusCheckFramebufferStatus == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glCheckFramebufferStatus) ? "true" : "false")+"\n";
  status += std::string("  clampColor                                    ")+((statusClampColor == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusClampColor == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glClampColor) ? "true" : "false")+"\n";
  status += std::string("  clearBufferfi                                 ")+((statusClearBufferfi == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusClearBufferfi == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glClearBufferfi) ? "true" : "false")+"\n";
  status += std::string("  clearBufferfv                                 ")+((statusClearBufferfv == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusClearBufferfv == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glClearBufferfv) ? "true" : "false")+"\n";
  status += std::string("  clearBufferiv                                 ")+((statusClearBufferiv == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusClearBufferiv == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glClearBufferiv) ? "true" : "false")+"\n";
  status += std::string("  clearBufferuiv                                ")+((statusClearBufferuiv == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusClearBufferuiv == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glClearBufferuiv) ? "true" : "false")+"\n";
  status += std::string("  colorMaski                                    ")+((statusColorMaski == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusColorMaski == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glColorMaski) ? "true" : "false")+"\n";
  status += std::string("  deleteFramebuffers                            ")+((statusDeleteFramebuffers == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusDeleteFramebuffers == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glDeleteFramebuffers) ? "true" : "false")+"\n";
  status += std::string("  deleteRenderbuffers                           ")+((statusDeleteRenderbuffers == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusDeleteRenderbuffers == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glDeleteRenderbuffers) ? "true" : "false")+"\n";
  status += std::string("  deleteVertexArrays                            ")+((statusDeleteVertexArrays == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusDeleteVertexArrays == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glDeleteVertexArrays) ? "true" : "false")+"\n";
  status += std::string("  disablei                                      ")+((statusDisablei == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusDisablei == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glDisablei) ? "true" : "false")+"\n";
  status += std::string("  enablei                                       ")+((statusEnablei == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusEnablei == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glEnablei) ? "true" : "false")+"\n";
  status += std::string("  endConditionalRender                          ")+((statusEndConditionalRender == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusEndConditionalRender == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glEndConditionalRender) ? "true" : "false")+"\n";
  status += std::string("  endTransformFeedback                          ")+((statusEndTransformFeedback == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusEndTransformFeedback == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glEndTransformFeedback) ? "true" : "false")+"\n";
  status += std::string("  flushMappedBufferRange                        ")+((statusFlushMappedBufferRange == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusFlushMappedBufferRange == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glFlushMappedBufferRange) ? "true" : "false")+"\n";
  status += std::string("  framebufferRenderbuffer                       ")+((statusFramebufferRenderbuffer == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusFramebufferRenderbuffer == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glFramebufferRenderbuffer) ? "true" : "false")+"\n";
  status += std::string("  framebufferTexture1D                          ")+((statusFramebufferTexture1D == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusFramebufferTexture1D == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glFramebufferTexture1D) ? "true" : "false")+"\n";
  status += std::string("  framebufferTexture2D                          ")+((statusFramebufferTexture2D == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusFramebufferTexture2D == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glFramebufferTexture2D) ? "true" : "false")+"\n";
  status += std::string("  framebufferTexture3D                          ")+((statusFramebufferTexture3D == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusFramebufferTexture3D == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glFramebufferTexture3D) ? "true" : "false")+"\n";
  status += std::string("  framebufferTextureLayer                       ")+((statusFramebufferTextureLayer == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusFramebufferTextureLayer == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glFramebufferTextureLayer) ? "true" : "false")+"\n";
  status += std::string("  genFramebuffers                               ")+((statusGenFramebuffers == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusGenFramebuffers == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glGenFramebuffers) ? "true" : "false")+"\n";
  status += std::string("  genRenderbuffers                              ")+((statusGenRenderbuffers == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusGenRenderbuffers == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glGenRenderbuffers) ? "true" : "false")+"\n";
  status += std::string("  genVertexArrays                               ")+((statusGenVertexArrays == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusGenVertexArrays == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glGenVertexArrays) ? "true" : "false")+"\n";
  status += std::string("  generateMipmap                                ")+((statusGenerateMipmap == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusGenerateMipmap == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glGenerateMipmap) ? "true" : "false")+"\n";
  status += std::string("  getBooleani_v                                 ")+((statusGetBooleani_v == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusGetBooleani_v == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glGetBooleani_v) ? "true" : "false")+"\n";
  status += std::string("  getFragDataLocation                           ")+((statusGetFragDataLocation == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusGetFragDataLocation == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glGetFragDataLocation) ? "true" : "false")+"\n";
  status += std::string("  getFramebufferAttachmentParameteriv           ")+((statusGetFramebufferAttachmentParameteriv == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusGetFramebufferAttachmentParameteriv == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glGetFramebufferAttachmentParameteriv) ? "true" : "false")+"\n";
  status += std::string("  getIntegeri_v                                 ")+((statusGetIntegeri_v == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusGetIntegeri_v == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glGetIntegeri_v) ? "true" : "false")+"\n";
  status += std::string("  getRenderbufferParameteriv                    ")+((statusGetRenderbufferParameteriv == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusGetRenderbufferParameteriv == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glGetRenderbufferParameteriv) ? "true" : "false")+"\n";
  status += std::string("  getStringi                                    ")+((statusGetStringi == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusGetStringi == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glGetStringi) ? "true" : "false")+"\n";
  status += std::string("  getTexParameterIiv                            ")+((statusGetTexParameterIiv == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusGetTexParameterIiv == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glGetTexParameterIiv) ? "true" : "false")+"\n";
  status += std::string("  getTexParameterIuiv                           ")+((statusGetTexParameterIuiv == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusGetTexParameterIuiv == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glGetTexParameterIuiv) ? "true" : "false")+"\n";
  status += std::string("  getTransformFeedbackVarying                   ")+((statusGetTransformFeedbackVarying == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusGetTransformFeedbackVarying == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glGetTransformFeedbackVarying) ? "true" : "false")+"\n";
  status += std::string("  getUniformuiv                                 ")+((statusGetUniformuiv == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusGetUniformuiv == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glGetUniformuiv) ? "true" : "false")+"\n";
  status += std::string("  getVertexAttribIiv                            ")+((statusGetVertexAttribIiv == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusGetVertexAttribIiv == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glGetVertexAttribIiv) ? "true" : "false")+"\n";
  status += std::string("  getVertexAttribIuiv                           ")+((statusGetVertexAttribIuiv == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusGetVertexAttribIuiv == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glGetVertexAttribIuiv) ? "true" : "false")+"\n";
  status += std::string("  isEnabledi                                    ")+((statusIsEnabledi == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusIsEnabledi == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glIsEnabledi) ? "true" : "false")+"\n";
  status += std::string("  isFramebuffer                                 ")+((statusIsFramebuffer == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusIsFramebuffer == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glIsFramebuffer) ? "true" : "false")+"\n";
  status += std::string("  isRenderbuffer                                ")+((statusIsRenderbuffer == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusIsRenderbuffer == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glIsRenderbuffer) ? "true" : "false")+"\n";
  status += std::string("  isVertexArray                                 ")+((statusIsVertexArray == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusIsVertexArray == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glIsVertexArray) ? "true" : "false")+"\n";
  status += std::string("  mapBufferRange                                ")+((statusMapBufferRange == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusMapBufferRange == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glMapBufferRange) ? "true" : "false")+"\n";
  status += std::string("  renderbufferStorage                           ")+((statusRenderbufferStorage == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusRenderbufferStorage == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glRenderbufferStorage) ? "true" : "false")+"\n";
  status += std::string("  renderbufferStorageMultisample                ")+((statusRenderbufferStorageMultisample == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusRenderbufferStorageMultisample == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glRenderbufferStorageMultisample) ? "true" : "false")+"\n";
  status += std::string("  texParameterIiv                               ")+((statusTexParameterIiv == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusTexParameterIiv == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glTexParameterIiv) ? "true" : "false")+"\n";
  status += std::string("  texParameterIuiv                              ")+((statusTexParameterIuiv == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusTexParameterIuiv == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glTexParameterIuiv) ? "true" : "false")+"\n";
  status += std::string("  transformFeedbackVaryings                     ")+((statusTransformFeedbackVaryings == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusTransformFeedbackVaryings == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glTransformFeedbackVaryings) ? "true" : "false")+"\n";
  status += std::string("  uniform1ui                                    ")+((statusUniform1ui == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusUniform1ui == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glUniform1ui) ? "true" : "false")+"\n";
  status += std::string("  uniform1uiv                                   ")+((statusUniform1uiv == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusUniform1uiv == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glUniform1uiv) ? "true" : "false")+"\n";
  status += std::string("  uniform2ui                                    ")+((statusUniform2ui == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusUniform2ui == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glUniform2ui) ? "true" : "false")+"\n";
  status += std::string("  uniform2uiv                                   ")+((statusUniform2uiv == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusUniform2uiv == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glUniform2uiv) ? "true" : "false")+"\n";
  status += std::string("  uniform3ui                                    ")+((statusUniform3ui == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusUniform3ui == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glUniform3ui) ? "true" : "false")+"\n";
  status += std::string("  uniform3uiv                                   ")+((statusUniform3uiv == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusUniform3uiv == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glUniform3uiv) ? "true" : "false")+"\n";
  status += std::string("  uniform4ui                                    ")+((statusUniform4ui == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusUniform4ui == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glUniform4ui) ? "true" : "false")+"\n";
  status += std::string("  uniform4uiv                                   ")+((statusUniform4uiv == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusUniform4uiv == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glUniform4uiv) ? "true" : "false")+"\n";
  status += std::string("  vertexAttribI1i                               ")+((statusVertexAttribI1i == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusVertexAttribI1i == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glVertexAttribI1i) ? "true" : "false")+"\n";
  status += std::string("  vertexAttribI1iv                              ")+((statusVertexAttribI1iv == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusVertexAttribI1iv == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glVertexAttribI1iv) ? "true" : "false")+"\n";
  status += std::string("  vertexAttribI1ui                              ")+((statusVertexAttribI1ui == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusVertexAttribI1ui == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glVertexAttribI1ui) ? "true" : "false")+"\n";
  status += std::string("  vertexAttribI1uiv                             ")+((statusVertexAttribI1uiv == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusVertexAttribI1uiv == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glVertexAttribI1uiv) ? "true" : "false")+"\n";
  status += std::string("  vertexAttribI2i                               ")+((statusVertexAttribI2i == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusVertexAttribI2i == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glVertexAttribI2i) ? "true" : "false")+"\n";
  status += std::string("  vertexAttribI2iv                              ")+((statusVertexAttribI2iv == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusVertexAttribI2iv == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glVertexAttribI2iv) ? "true" : "false")+"\n";
  status += std::string("  vertexAttribI2ui                              ")+((statusVertexAttribI2ui == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusVertexAttribI2ui == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glVertexAttribI2ui) ? "true" : "false")+"\n";
  status += std::string("  vertexAttribI2uiv                             ")+((statusVertexAttribI2uiv == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusVertexAttribI2uiv == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glVertexAttribI2uiv) ? "true" : "false")+"\n";
  status += std::string("  vertexAttribI3i                               ")+((statusVertexAttribI3i == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusVertexAttribI3i == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glVertexAttribI3i) ? "true" : "false")+"\n";
  status += std::string("  vertexAttribI3iv                              ")+((statusVertexAttribI3iv == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusVertexAttribI3iv == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glVertexAttribI3iv) ? "true" : "false")+"\n";
  status += std::string("  vertexAttribI3ui                              ")+((statusVertexAttribI3ui == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusVertexAttribI3ui == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glVertexAttribI3ui) ? "true" : "false")+"\n";
  status += std::string("  vertexAttribI3uiv                             ")+((statusVertexAttribI3uiv == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusVertexAttribI3uiv == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glVertexAttribI3uiv) ? "true" : "false")+"\n";
  status += std::string("  vertexAttribI4bv                              ")+((statusVertexAttribI4bv == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusVertexAttribI4bv == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glVertexAttribI4bv) ? "true" : "false")+"\n";
  status += std::string("  vertexAttribI4i                               ")+((statusVertexAttribI4i == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusVertexAttribI4i == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glVertexAttribI4i) ? "true" : "false")+"\n";
  status += std::string("  vertexAttribI4iv                              ")+((statusVertexAttribI4iv == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusVertexAttribI4iv == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glVertexAttribI4iv) ? "true" : "false")+"\n";
  status += std::string("  vertexAttribI4sv                              ")+((statusVertexAttribI4sv == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusVertexAttribI4sv == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glVertexAttribI4sv) ? "true" : "false")+"\n";
  status += std::string("  vertexAttribI4ubv                             ")+((statusVertexAttribI4ubv == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusVertexAttribI4ubv == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glVertexAttribI4ubv) ? "true" : "false")+"\n";
  status += std::string("  vertexAttribI4ui                              ")+((statusVertexAttribI4ui == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusVertexAttribI4ui == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glVertexAttribI4ui) ? "true" : "false")+"\n";
  status += std::string("  vertexAttribI4uiv                             ")+((statusVertexAttribI4uiv == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusVertexAttribI4uiv == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glVertexAttribI4uiv) ? "true" : "false")+"\n";
  status += std::string("  vertexAttribI4usv                             ")+((statusVertexAttribI4usv == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusVertexAttribI4usv == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glVertexAttribI4usv) ? "true" : "false")+"\n";
  status += std::string("  vertexAttribIPointer                          ")+((statusVertexAttribIPointer == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusVertexAttribIPointer == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glVertexAttribIPointer) ? "true" : "false")+"\n";
  status += "\n";
  status += "GL_VERSION_3_1\n";
  status += std::string("  copyBufferSubData                             ")+((statusCopyBufferSubData == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusCopyBufferSubData == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glCopyBufferSubData) ? "true" : "false")+"\n";
  status += std::string("  drawArraysInstanced                           ")+((statusDrawArraysInstanced == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusDrawArraysInstanced == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glDrawArraysInstanced) ? "true" : "false")+"\n";
  status += std::string("  drawElementsInstanced                         ")+((statusDrawElementsInstanced == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusDrawElementsInstanced == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glDrawElementsInstanced) ? "true" : "false")+"\n";
  status += std::string("  getActiveUniformBlockName                     ")+((statusGetActiveUniformBlockName == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusGetActiveUniformBlockName == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glGetActiveUniformBlockName) ? "true" : "false")+"\n";
  status += std::string("  getActiveUniformBlockiv                       ")+((statusGetActiveUniformBlockiv == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusGetActiveUniformBlockiv == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glGetActiveUniformBlockiv) ? "true" : "false")+"\n";
  status += std::string("  getActiveUniformName                          ")+((statusGetActiveUniformName == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusGetActiveUniformName == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glGetActiveUniformName) ? "true" : "false")+"\n";
  status += std::string("  getActiveUniformsiv                           ")+((statusGetActiveUniformsiv == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusGetActiveUniformsiv == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glGetActiveUniformsiv) ? "true" : "false")+"\n";
  status += std::string("  getUniformBlockIndex                          ")+((statusGetUniformBlockIndex == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusGetUniformBlockIndex == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glGetUniformBlockIndex) ? "true" : "false")+"\n";
  status += std::string("  getUniformIndices                             ")+((statusGetUniformIndices == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusGetUniformIndices == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glGetUniformIndices) ? "true" : "false")+"\n";
  status += std::string("  primitiveRestartIndex                         ")+((statusPrimitiveRestartIndex == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusPrimitiveRestartIndex == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glPrimitiveRestartIndex) ? "true" : "false")+"\n";
  status += std::string("  texBuffer                                     ")+((statusTexBuffer == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusTexBuffer == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glTexBuffer) ? "true" : "false")+"\n";
  status += std::string("  uniformBlockBinding                           ")+((statusUniformBlockBinding == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusUniformBlockBinding == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glUniformBlockBinding) ? "true" : "false")+"\n";
  status += "\n";
  status += "GL_VERSION_3_2\n";
  status += std::string("  clientWaitSync                                ")+((statusClientWaitSync == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusClientWaitSync == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glClientWaitSync) ? "true" : "false")+"\n";
  status += std::string("  deleteSync                                    ")+((statusDeleteSync == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusDeleteSync == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glDeleteSync) ? "true" : "false")+"\n";
  status += std::string("  drawElementsBaseVertex                        ")+((statusDrawElementsBaseVertex == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusDrawElementsBaseVertex == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glDrawElementsBaseVertex) ? "true" : "false")+"\n";
  status += std::string("  drawElementsInstancedBaseVertex               ")+((statusDrawElementsInstancedBaseVertex == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusDrawElementsInstancedBaseVertex == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glDrawElementsInstancedBaseVertex) ? "true" : "false")+"\n";
  status += std::string("  drawRangeElementsBaseVertex                   ")+((statusDrawRangeElementsBaseVertex == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusDrawRangeElementsBaseVertex == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glDrawRangeElementsBaseVertex) ? "true" : "false")+"\n";
  status += std::string("  fenceSync                                     ")+((statusFenceSync == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusFenceSync == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glFenceSync) ? "true" : "false")+"\n";
  status += std::string("  framebufferTexture                            ")+((statusFramebufferTexture == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusFramebufferTexture == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glFramebufferTexture) ? "true" : "false")+"\n";
  status += std::string("  getBufferParameteri64v                        ")+((statusGetBufferParameteri64v == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusGetBufferParameteri64v == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glGetBufferParameteri64v) ? "true" : "false")+"\n";
  status += std::string("  getInteger64i_v                               ")+((statusGetInteger64i_v == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusGetInteger64i_v == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glGetInteger64i_v) ? "true" : "false")+"\n";
  status += std::string("  getInteger64v                                 ")+((statusGetInteger64v == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusGetInteger64v == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glGetInteger64v) ? "true" : "false")+"\n";
  status += std::string("  getMultisamplefv                              ")+((statusGetMultisamplefv == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusGetMultisamplefv == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glGetMultisamplefv) ? "true" : "false")+"\n";
  status += std::string("  getSynciv                                     ")+((statusGetSynciv == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusGetSynciv == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glGetSynciv) ? "true" : "false")+"\n";
  status += std::string("  isSync                                        ")+((statusIsSync == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusIsSync == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glIsSync) ? "true" : "false")+"\n";
  status += std::string("  multiDrawElementsBaseVertex                   ")+((statusMultiDrawElementsBaseVertex == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusMultiDrawElementsBaseVertex == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glMultiDrawElementsBaseVertex) ? "true" : "false")+"\n";
  status += std::string("  provokingVertex                               ")+((statusProvokingVertex == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusProvokingVertex == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glProvokingVertex) ? "true" : "false")+"\n";
  status += std::string("  sampleMaski                                   ")+((statusSampleMaski == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusSampleMaski == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glSampleMaski) ? "true" : "false")+"\n";
  status += std::string("  texImage2DMultisample                         ")+((statusTexImage2DMultisample == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusTexImage2DMultisample == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glTexImage2DMultisample) ? "true" : "false")+"\n";
  status += std::string("  texImage3DMultisample                         ")+((statusTexImage3DMultisample == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusTexImage3DMultisample == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glTexImage3DMultisample) ? "true" : "false")+"\n";
  status += std::string("  waitSync                                      ")+((statusWaitSync == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusWaitSync == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glWaitSync) ? "true" : "false")+"\n";
  status += "\n";
  status += "GL_VERSION_3_3\n";
  status += std::string("  bindFragDataLocationIndexed                   ")+((statusBindFragDataLocationIndexed == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusBindFragDataLocationIndexed == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glBindFragDataLocationIndexed) ? "true" : "false")+"\n";
  status += std::string("  bindSampler                                   ")+((statusBindSampler == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusBindSampler == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glBindSampler) ? "true" : "false")+"\n";
  status += std::string("  deleteSamplers                                ")+((statusDeleteSamplers == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusDeleteSamplers == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glDeleteSamplers) ? "true" : "false")+"\n";
  status += std::string("  genSamplers                                   ")+((statusGenSamplers == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusGenSamplers == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glGenSamplers) ? "true" : "false")+"\n";
  status += std::string("  getFragDataIndex                              ")+((statusGetFragDataIndex == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusGetFragDataIndex == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glGetFragDataIndex) ? "true" : "false")+"\n";
  status += std::string("  getQueryObjecti64v                            ")+((statusGetQueryObjecti64v == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusGetQueryObjecti64v == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glGetQueryObjecti64v) ? "true" : "false")+"\n";
  status += std::string("  getQueryObjectui64v                           ")+((statusGetQueryObjectui64v == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusGetQueryObjectui64v == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glGetQueryObjectui64v) ? "true" : "false")+"\n";
  status += std::string("  getSamplerParameterIiv                        ")+((statusGetSamplerParameterIiv == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusGetSamplerParameterIiv == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glGetSamplerParameterIiv) ? "true" : "false")+"\n";
  status += std::string("  getSamplerParameterIuiv                       ")+((statusGetSamplerParameterIuiv == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusGetSamplerParameterIuiv == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glGetSamplerParameterIuiv) ? "true" : "false")+"\n";
  status += std::string("  getSamplerParameterfv                         ")+((statusGetSamplerParameterfv == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusGetSamplerParameterfv == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glGetSamplerParameterfv) ? "true" : "false")+"\n";
  status += std::string("  getSamplerParameteriv                         ")+((statusGetSamplerParameteriv == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusGetSamplerParameteriv == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glGetSamplerParameteriv) ? "true" : "false")+"\n";
  status += std::string("  isSampler                                     ")+((statusIsSampler == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusIsSampler == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glIsSampler) ? "true" : "false")+"\n";
  status += std::string("  queryCounter                                  ")+((statusQueryCounter == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusQueryCounter == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glQueryCounter) ? "true" : "false")+"\n";
  status += std::string("  samplerParameterIiv                           ")+((statusSamplerParameterIiv == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusSamplerParameterIiv == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glSamplerParameterIiv) ? "true" : "false")+"\n";
  status += std::string("  samplerParameterIuiv                          ")+((statusSamplerParameterIuiv == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusSamplerParameterIuiv == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glSamplerParameterIuiv) ? "true" : "false")+"\n";
  status += std::string("  samplerParameterf                             ")+((statusSamplerParameterf == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusSamplerParameterf == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glSamplerParameterf) ? "true" : "false")+"\n";
  status += std::string("  samplerParameterfv                            ")+((statusSamplerParameterfv == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusSamplerParameterfv == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glSamplerParameterfv) ? "true" : "false")+"\n";
  status += std::string("  samplerParameteri                             ")+((statusSamplerParameteri == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusSamplerParameteri == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glSamplerParameteri) ? "true" : "false")+"\n";
  status += std::string("  samplerParameteriv                            ")+((statusSamplerParameteriv == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusSamplerParameteriv == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glSamplerParameteriv) ? "true" : "false")+"\n";
  status += std::string("  vertexAttribDivisor                           ")+((statusVertexAttribDivisor == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusVertexAttribDivisor == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glVertexAttribDivisor) ? "true" : "false")+"\n";
  status += std::string("  vertexAttribP1ui                              ")+((statusVertexAttribP1ui == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusVertexAttribP1ui == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glVertexAttribP1ui) ? "true" : "false")+"\n";
  status += std::string("  vertexAttribP1uiv                             ")+((statusVertexAttribP1uiv == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusVertexAttribP1uiv == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glVertexAttribP1uiv) ? "true" : "false")+"\n";
  status += std::string("  vertexAttribP2ui                              ")+((statusVertexAttribP2ui == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusVertexAttribP2ui == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glVertexAttribP2ui) ? "true" : "false")+"\n";
  status += std::string("  vertexAttribP2uiv                             ")+((statusVertexAttribP2uiv == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusVertexAttribP2uiv == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glVertexAttribP2uiv) ? "true" : "false")+"\n";
  status += std::string("  vertexAttribP3ui                              ")+((statusVertexAttribP3ui == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusVertexAttribP3ui == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glVertexAttribP3ui) ? "true" : "false")+"\n";
  status += std::string("  vertexAttribP3uiv                             ")+((statusVertexAttribP3uiv == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusVertexAttribP3uiv == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glVertexAttribP3uiv) ? "true" : "false")+"\n";
  status += std::string("  vertexAttribP4ui                              ")+((statusVertexAttribP4ui == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusVertexAttribP4ui == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glVertexAttribP4ui) ? "true" : "false")+"\n";
  status += std::string("  vertexAttribP4uiv                             ")+((statusVertexAttribP4uiv == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusVertexAttribP4uiv == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glVertexAttribP4uiv) ? "true" : "false")+"\n";
  status += "\n";
  status += "GL_VERSION_4_0\n";
  status += std::string("  beginQueryIndexed                             ")+((statusBeginQueryIndexed == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusBeginQueryIndexed == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glBeginQueryIndexed) ? "true" : "false")+"\n";
  status += std::string("  bindTransformFeedback                         ")+((statusBindTransformFeedback == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusBindTransformFeedback == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glBindTransformFeedback) ? "true" : "false")+"\n";
  status += std::string("  blendEquationSeparatei                        ")+((statusBlendEquationSeparatei == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusBlendEquationSeparatei == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glBlendEquationSeparatei) ? "true" : "false")+"\n";
  status += std::string("  blendEquationi                                ")+((statusBlendEquationi == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusBlendEquationi == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glBlendEquationi) ? "true" : "false")+"\n";
  status += std::string("  blendFuncSeparatei                            ")+((statusBlendFuncSeparatei == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusBlendFuncSeparatei == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glBlendFuncSeparatei) ? "true" : "false")+"\n";
  status += std::string("  blendFunci                                    ")+((statusBlendFunci == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusBlendFunci == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glBlendFunci) ? "true" : "false")+"\n";
  status += std::string("  deleteTransformFeedbacks                      ")+((statusDeleteTransformFeedbacks == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusDeleteTransformFeedbacks == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glDeleteTransformFeedbacks) ? "true" : "false")+"\n";
  status += std::string("  drawArraysIndirect                            ")+((statusDrawArraysIndirect == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusDrawArraysIndirect == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glDrawArraysIndirect) ? "true" : "false")+"\n";
  status += std::string("  drawElementsIndirect                          ")+((statusDrawElementsIndirect == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusDrawElementsIndirect == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glDrawElementsIndirect) ? "true" : "false")+"\n";
  status += std::string("  drawTransformFeedback                         ")+((statusDrawTransformFeedback == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusDrawTransformFeedback == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glDrawTransformFeedback) ? "true" : "false")+"\n";
  status += std::string("  drawTransformFeedbackStream                   ")+((statusDrawTransformFeedbackStream == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusDrawTransformFeedbackStream == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glDrawTransformFeedbackStream) ? "true" : "false")+"\n";
  status += std::string("  endQueryIndexed                               ")+((statusEndQueryIndexed == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusEndQueryIndexed == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glEndQueryIndexed) ? "true" : "false")+"\n";
  status += std::string("  genTransformFeedbacks                         ")+((statusGenTransformFeedbacks == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusGenTransformFeedbacks == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glGenTransformFeedbacks) ? "true" : "false")+"\n";
  status += std::string("  getActiveSubroutineName                       ")+((statusGetActiveSubroutineName == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusGetActiveSubroutineName == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glGetActiveSubroutineName) ? "true" : "false")+"\n";
  status += std::string("  getActiveSubroutineUniformName                ")+((statusGetActiveSubroutineUniformName == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusGetActiveSubroutineUniformName == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glGetActiveSubroutineUniformName) ? "true" : "false")+"\n";
  status += std::string("  getActiveSubroutineUniformiv                  ")+((statusGetActiveSubroutineUniformiv == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusGetActiveSubroutineUniformiv == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glGetActiveSubroutineUniformiv) ? "true" : "false")+"\n";
  status += std::string("  getProgramStageiv                             ")+((statusGetProgramStageiv == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusGetProgramStageiv == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glGetProgramStageiv) ? "true" : "false")+"\n";
  status += std::string("  getQueryIndexediv                             ")+((statusGetQueryIndexediv == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusGetQueryIndexediv == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glGetQueryIndexediv) ? "true" : "false")+"\n";
  status += std::string("  getSubroutineIndex                            ")+((statusGetSubroutineIndex == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusGetSubroutineIndex == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glGetSubroutineIndex) ? "true" : "false")+"\n";
  status += std::string("  getSubroutineUniformLocation                  ")+((statusGetSubroutineUniformLocation == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusGetSubroutineUniformLocation == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glGetSubroutineUniformLocation) ? "true" : "false")+"\n";
  status += std::string("  getUniformSubroutineuiv                       ")+((statusGetUniformSubroutineuiv == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusGetUniformSubroutineuiv == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glGetUniformSubroutineuiv) ? "true" : "false")+"\n";
  status += std::string("  getUniformdv                                  ")+((statusGetUniformdv == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusGetUniformdv == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glGetUniformdv) ? "true" : "false")+"\n";
  status += std::string("  isTransformFeedback                           ")+((statusIsTransformFeedback == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusIsTransformFeedback == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glIsTransformFeedback) ? "true" : "false")+"\n";
  status += std::string("  minSampleShading                              ")+((statusMinSampleShading == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusMinSampleShading == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glMinSampleShading) ? "true" : "false")+"\n";
  status += std::string("  patchParameterfv                              ")+((statusPatchParameterfv == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusPatchParameterfv == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glPatchParameterfv) ? "true" : "false")+"\n";
  status += std::string("  patchParameteri                               ")+((statusPatchParameteri == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusPatchParameteri == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glPatchParameteri) ? "true" : "false")+"\n";
  status += std::string("  pauseTransformFeedback                        ")+((statusPauseTransformFeedback == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusPauseTransformFeedback == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glPauseTransformFeedback) ? "true" : "false")+"\n";
  status += std::string("  resumeTransformFeedback                       ")+((statusResumeTransformFeedback == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusResumeTransformFeedback == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glResumeTransformFeedback) ? "true" : "false")+"\n";
  status += std::string("  uniform1d                                     ")+((statusUniform1d == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusUniform1d == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glUniform1d) ? "true" : "false")+"\n";
  status += std::string("  uniform1dv                                    ")+((statusUniform1dv == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusUniform1dv == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glUniform1dv) ? "true" : "false")+"\n";
  status += std::string("  uniform2d                                     ")+((statusUniform2d == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusUniform2d == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glUniform2d) ? "true" : "false")+"\n";
  status += std::string("  uniform2dv                                    ")+((statusUniform2dv == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusUniform2dv == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glUniform2dv) ? "true" : "false")+"\n";
  status += std::string("  uniform3d                                     ")+((statusUniform3d == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusUniform3d == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glUniform3d) ? "true" : "false")+"\n";
  status += std::string("  uniform3dv                                    ")+((statusUniform3dv == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusUniform3dv == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glUniform3dv) ? "true" : "false")+"\n";
  status += std::string("  uniform4d                                     ")+((statusUniform4d == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusUniform4d == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glUniform4d) ? "true" : "false")+"\n";
  status += std::string("  uniform4dv                                    ")+((statusUniform4dv == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusUniform4dv == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glUniform4dv) ? "true" : "false")+"\n";
  status += std::string("  uniformMatrix2dv                              ")+((statusUniformMatrix2dv == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusUniformMatrix2dv == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glUniformMatrix2dv) ? "true" : "false")+"\n";
  status += std::string("  uniformMatrix2x3dv                            ")+((statusUniformMatrix2x3dv == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusUniformMatrix2x3dv == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glUniformMatrix2x3dv) ? "true" : "false")+"\n";
  status += std::string("  uniformMatrix2x4dv                            ")+((statusUniformMatrix2x4dv == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusUniformMatrix2x4dv == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glUniformMatrix2x4dv) ? "true" : "false")+"\n";
  status += std::string("  uniformMatrix3dv                              ")+((statusUniformMatrix3dv == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusUniformMatrix3dv == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glUniformMatrix3dv) ? "true" : "false")+"\n";
  status += std::string("  uniformMatrix3x2dv                            ")+((statusUniformMatrix3x2dv == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusUniformMatrix3x2dv == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glUniformMatrix3x2dv) ? "true" : "false")+"\n";
  status += std::string("  uniformMatrix3x4dv                            ")+((statusUniformMatrix3x4dv == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusUniformMatrix3x4dv == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glUniformMatrix3x4dv) ? "true" : "false")+"\n";
  status += std::string("  uniformMatrix4dv                              ")+((statusUniformMatrix4dv == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusUniformMatrix4dv == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glUniformMatrix4dv) ? "true" : "false")+"\n";
  status += std::string("  uniformMatrix4x2dv                            ")+((statusUniformMatrix4x2dv == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusUniformMatrix4x2dv == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glUniformMatrix4x2dv) ? "true" : "false")+"\n";
  status += std::string("  uniformMatrix4x3dv                            ")+((statusUniformMatrix4x3dv == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusUniformMatrix4x3dv == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glUniformMatrix4x3dv) ? "true" : "false")+"\n";
  status += std::string("  uniformSubroutinesuiv                         ")+((statusUniformSubroutinesuiv == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusUniformSubroutinesuiv == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glUniformSubroutinesuiv) ? "true" : "false")+"\n";
  status += "\n";
  status += "GL_VERSION_4_1\n";
  status += std::string("  activeShaderProgram                           ")+((statusActiveShaderProgram == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusActiveShaderProgram == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glActiveShaderProgram) ? "true" : "false")+"\n";
  status += std::string("  bindProgramPipeline                           ")+((statusBindProgramPipeline == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusBindProgramPipeline == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glBindProgramPipeline) ? "true" : "false")+"\n";
  status += std::string("  clearDepthf                                   ")+((statusClearDepthf == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusClearDepthf == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glClearDepthf) ? "true" : "false")+"\n";
  status += std::string("  createShaderProgramv                          ")+((statusCreateShaderProgramv == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusCreateShaderProgramv == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glCreateShaderProgramv) ? "true" : "false")+"\n";
  status += std::string("  deleteProgramPipelines                        ")+((statusDeleteProgramPipelines == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusDeleteProgramPipelines == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glDeleteProgramPipelines) ? "true" : "false")+"\n";
  status += std::string("  depthRangeArrayv                              ")+((statusDepthRangeArrayv == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusDepthRangeArrayv == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glDepthRangeArrayv) ? "true" : "false")+"\n";
  status += std::string("  depthRangeIndexed                             ")+((statusDepthRangeIndexed == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusDepthRangeIndexed == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glDepthRangeIndexed) ? "true" : "false")+"\n";
  status += std::string("  depthRangef                                   ")+((statusDepthRangef == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusDepthRangef == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glDepthRangef) ? "true" : "false")+"\n";
  status += std::string("  genProgramPipelines                           ")+((statusGenProgramPipelines == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusGenProgramPipelines == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glGenProgramPipelines) ? "true" : "false")+"\n";
  status += std::string("  getDoublei_v                                  ")+((statusGetDoublei_v == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusGetDoublei_v == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glGetDoublei_v) ? "true" : "false")+"\n";
  status += std::string("  getFloati_v                                   ")+((statusGetFloati_v == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusGetFloati_v == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glGetFloati_v) ? "true" : "false")+"\n";
  status += std::string("  getProgramBinary                              ")+((statusGetProgramBinary == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusGetProgramBinary == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glGetProgramBinary) ? "true" : "false")+"\n";
  status += std::string("  getProgramPipelineInfoLog                     ")+((statusGetProgramPipelineInfoLog == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusGetProgramPipelineInfoLog == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glGetProgramPipelineInfoLog) ? "true" : "false")+"\n";
  status += std::string("  getProgramPipelineiv                          ")+((statusGetProgramPipelineiv == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusGetProgramPipelineiv == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glGetProgramPipelineiv) ? "true" : "false")+"\n";
  status += std::string("  getShaderPrecisionFormat                      ")+((statusGetShaderPrecisionFormat == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusGetShaderPrecisionFormat == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glGetShaderPrecisionFormat) ? "true" : "false")+"\n";
  status += std::string("  getVertexAttribLdv                            ")+((statusGetVertexAttribLdv == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusGetVertexAttribLdv == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glGetVertexAttribLdv) ? "true" : "false")+"\n";
  status += std::string("  isProgramPipeline                             ")+((statusIsProgramPipeline == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusIsProgramPipeline == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glIsProgramPipeline) ? "true" : "false")+"\n";
  status += std::string("  programBinary                                 ")+((statusProgramBinary == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusProgramBinary == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glProgramBinary) ? "true" : "false")+"\n";
  status += std::string("  programParameteri                             ")+((statusProgramParameteri == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusProgramParameteri == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glProgramParameteri) ? "true" : "false")+"\n";
  status += std::string("  programUniform1d                              ")+((statusProgramUniform1d == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusProgramUniform1d == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glProgramUniform1d) ? "true" : "false")+"\n";
  status += std::string("  programUniform1dv                             ")+((statusProgramUniform1dv == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusProgramUniform1dv == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glProgramUniform1dv) ? "true" : "false")+"\n";
  status += std::string("  programUniform1f                              ")+((statusProgramUniform1f == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusProgramUniform1f == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glProgramUniform1f) ? "true" : "false")+"\n";
  status += std::string("  programUniform1fv                             ")+((statusProgramUniform1fv == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusProgramUniform1fv == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glProgramUniform1fv) ? "true" : "false")+"\n";
  status += std::string("  programUniform1i                              ")+((statusProgramUniform1i == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusProgramUniform1i == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glProgramUniform1i) ? "true" : "false")+"\n";
  status += std::string("  programUniform1iv                             ")+((statusProgramUniform1iv == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusProgramUniform1iv == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glProgramUniform1iv) ? "true" : "false")+"\n";
  status += std::string("  programUniform1ui                             ")+((statusProgramUniform1ui == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusProgramUniform1ui == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glProgramUniform1ui) ? "true" : "false")+"\n";
  status += std::string("  programUniform1uiv                            ")+((statusProgramUniform1uiv == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusProgramUniform1uiv == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glProgramUniform1uiv) ? "true" : "false")+"\n";
  status += std::string("  programUniform2d                              ")+((statusProgramUniform2d == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusProgramUniform2d == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glProgramUniform2d) ? "true" : "false")+"\n";
  status += std::string("  programUniform2dv                             ")+((statusProgramUniform2dv == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusProgramUniform2dv == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glProgramUniform2dv) ? "true" : "false")+"\n";
  status += std::string("  programUniform2f                              ")+((statusProgramUniform2f == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusProgramUniform2f == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glProgramUniform2f) ? "true" : "false")+"\n";
  status += std::string("  programUniform2fv                             ")+((statusProgramUniform2fv == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusProgramUniform2fv == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glProgramUniform2fv) ? "true" : "false")+"\n";
  status += std::string("  programUniform2i                              ")+((statusProgramUniform2i == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusProgramUniform2i == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glProgramUniform2i) ? "true" : "false")+"\n";
  status += std::string("  programUniform2iv                             ")+((statusProgramUniform2iv == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusProgramUniform2iv == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glProgramUniform2iv) ? "true" : "false")+"\n";
  status += std::string("  programUniform2ui                             ")+((statusProgramUniform2ui == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusProgramUniform2ui == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glProgramUniform2ui) ? "true" : "false")+"\n";
  status += std::string("  programUniform2uiv                            ")+((statusProgramUniform2uiv == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusProgramUniform2uiv == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glProgramUniform2uiv) ? "true" : "false")+"\n";
  status += std::string("  programUniform3d                              ")+((statusProgramUniform3d == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusProgramUniform3d == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glProgramUniform3d) ? "true" : "false")+"\n";
  status += std::string("  programUniform3dv                             ")+((statusProgramUniform3dv == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusProgramUniform3dv == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glProgramUniform3dv) ? "true" : "false")+"\n";
  status += std::string("  programUniform3f                              ")+((statusProgramUniform3f == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusProgramUniform3f == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glProgramUniform3f) ? "true" : "false")+"\n";
  status += std::string("  programUniform3fv                             ")+((statusProgramUniform3fv == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusProgramUniform3fv == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glProgramUniform3fv) ? "true" : "false")+"\n";
  status += std::string("  programUniform3i                              ")+((statusProgramUniform3i == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusProgramUniform3i == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glProgramUniform3i) ? "true" : "false")+"\n";
  status += std::string("  programUniform3iv                             ")+((statusProgramUniform3iv == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusProgramUniform3iv == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glProgramUniform3iv) ? "true" : "false")+"\n";
  status += std::string("  programUniform3ui                             ")+((statusProgramUniform3ui == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusProgramUniform3ui == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glProgramUniform3ui) ? "true" : "false")+"\n";
  status += std::string("  programUniform3uiv                            ")+((statusProgramUniform3uiv == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusProgramUniform3uiv == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glProgramUniform3uiv) ? "true" : "false")+"\n";
  status += std::string("  programUniform4d                              ")+((statusProgramUniform4d == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusProgramUniform4d == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glProgramUniform4d) ? "true" : "false")+"\n";
  status += std::string("  programUniform4dv                             ")+((statusProgramUniform4dv == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusProgramUniform4dv == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glProgramUniform4dv) ? "true" : "false")+"\n";
  status += std::string("  programUniform4f                              ")+((statusProgramUniform4f == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusProgramUniform4f == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glProgramUniform4f) ? "true" : "false")+"\n";
  status += std::string("  programUniform4fv                             ")+((statusProgramUniform4fv == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusProgramUniform4fv == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glProgramUniform4fv) ? "true" : "false")+"\n";
  status += std::string("  programUniform4i                              ")+((statusProgramUniform4i == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusProgramUniform4i == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glProgramUniform4i) ? "true" : "false")+"\n";
  status += std::string("  programUniform4iv                             ")+((statusProgramUniform4iv == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusProgramUniform4iv == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glProgramUniform4iv) ? "true" : "false")+"\n";
  status += std::string("  programUniform4ui                             ")+((statusProgramUniform4ui == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusProgramUniform4ui == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glProgramUniform4ui) ? "true" : "false")+"\n";
  status += std::string("  programUniform4uiv                            ")+((statusProgramUniform4uiv == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusProgramUniform4uiv == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glProgramUniform4uiv) ? "true" : "false")+"\n";
  status += std::string("  programUniformMatrix2dv                       ")+((statusProgramUniformMatrix2dv == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusProgramUniformMatrix2dv == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glProgramUniformMatrix2dv) ? "true" : "false")+"\n";
  status += std::string("  programUniformMatrix2fv                       ")+((statusProgramUniformMatrix2fv == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusProgramUniformMatrix2fv == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glProgramUniformMatrix2fv) ? "true" : "false")+"\n";
  status += std::string("  programUniformMatrix2x3dv                     ")+((statusProgramUniformMatrix2x3dv == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusProgramUniformMatrix2x3dv == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glProgramUniformMatrix2x3dv) ? "true" : "false")+"\n";
  status += std::string("  programUniformMatrix2x3fv                     ")+((statusProgramUniformMatrix2x3fv == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusProgramUniformMatrix2x3fv == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glProgramUniformMatrix2x3fv) ? "true" : "false")+"\n";
  status += std::string("  programUniformMatrix2x4dv                     ")+((statusProgramUniformMatrix2x4dv == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusProgramUniformMatrix2x4dv == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glProgramUniformMatrix2x4dv) ? "true" : "false")+"\n";
  status += std::string("  programUniformMatrix2x4fv                     ")+((statusProgramUniformMatrix2x4fv == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusProgramUniformMatrix2x4fv == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glProgramUniformMatrix2x4fv) ? "true" : "false")+"\n";
  status += std::string("  programUniformMatrix3dv                       ")+((statusProgramUniformMatrix3dv == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusProgramUniformMatrix3dv == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glProgramUniformMatrix3dv) ? "true" : "false")+"\n";
  status += std::string("  programUniformMatrix3fv                       ")+((statusProgramUniformMatrix3fv == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusProgramUniformMatrix3fv == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glProgramUniformMatrix3fv) ? "true" : "false")+"\n";
  status += std::string("  programUniformMatrix3x2dv                     ")+((statusProgramUniformMatrix3x2dv == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusProgramUniformMatrix3x2dv == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glProgramUniformMatrix3x2dv) ? "true" : "false")+"\n";
  status += std::string("  programUniformMatrix3x2fv                     ")+((statusProgramUniformMatrix3x2fv == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusProgramUniformMatrix3x2fv == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glProgramUniformMatrix3x2fv) ? "true" : "false")+"\n";
  status += std::string("  programUniformMatrix3x4dv                     ")+((statusProgramUniformMatrix3x4dv == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusProgramUniformMatrix3x4dv == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glProgramUniformMatrix3x4dv) ? "true" : "false")+"\n";
  status += std::string("  programUniformMatrix3x4fv                     ")+((statusProgramUniformMatrix3x4fv == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusProgramUniformMatrix3x4fv == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glProgramUniformMatrix3x4fv) ? "true" : "false")+"\n";
  status += std::string("  programUniformMatrix4dv                       ")+((statusProgramUniformMatrix4dv == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusProgramUniformMatrix4dv == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glProgramUniformMatrix4dv) ? "true" : "false")+"\n";
  status += std::string("  programUniformMatrix4fv                       ")+((statusProgramUniformMatrix4fv == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusProgramUniformMatrix4fv == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glProgramUniformMatrix4fv) ? "true" : "false")+"\n";
  status += std::string("  programUniformMatrix4x2dv                     ")+((statusProgramUniformMatrix4x2dv == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusProgramUniformMatrix4x2dv == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glProgramUniformMatrix4x2dv) ? "true" : "false")+"\n";
  status += std::string("  programUniformMatrix4x2fv                     ")+((statusProgramUniformMatrix4x2fv == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusProgramUniformMatrix4x2fv == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glProgramUniformMatrix4x2fv) ? "true" : "false")+"\n";
  status += std::string("  programUniformMatrix4x3dv                     ")+((statusProgramUniformMatrix4x3dv == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusProgramUniformMatrix4x3dv == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glProgramUniformMatrix4x3dv) ? "true" : "false")+"\n";
  status += std::string("  programUniformMatrix4x3fv                     ")+((statusProgramUniformMatrix4x3fv == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusProgramUniformMatrix4x3fv == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glProgramUniformMatrix4x3fv) ? "true" : "false")+"\n";
  status += std::string("  releaseShaderCompiler                         ")+((statusReleaseShaderCompiler == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusReleaseShaderCompiler == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glReleaseShaderCompiler) ? "true" : "false")+"\n";
  status += std::string("  scissorArrayv                                 ")+((statusScissorArrayv == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusScissorArrayv == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glScissorArrayv) ? "true" : "false")+"\n";
  status += std::string("  scissorIndexed                                ")+((statusScissorIndexed == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusScissorIndexed == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glScissorIndexed) ? "true" : "false")+"\n";
  status += std::string("  scissorIndexedv                               ")+((statusScissorIndexedv == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusScissorIndexedv == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glScissorIndexedv) ? "true" : "false")+"\n";
  status += std::string("  shaderBinary                                  ")+((statusShaderBinary == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusShaderBinary == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glShaderBinary) ? "true" : "false")+"\n";
  status += std::string("  useProgramStages                              ")+((statusUseProgramStages == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusUseProgramStages == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glUseProgramStages) ? "true" : "false")+"\n";
  status += std::string("  validateProgramPipeline                       ")+((statusValidateProgramPipeline == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusValidateProgramPipeline == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glValidateProgramPipeline) ? "true" : "false")+"\n";
  status += std::string("  vertexAttribL1d                               ")+((statusVertexAttribL1d == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusVertexAttribL1d == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glVertexAttribL1d) ? "true" : "false")+"\n";
  status += std::string("  vertexAttribL1dv                              ")+((statusVertexAttribL1dv == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusVertexAttribL1dv == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glVertexAttribL1dv) ? "true" : "false")+"\n";
  status += std::string("  vertexAttribL2d                               ")+((statusVertexAttribL2d == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusVertexAttribL2d == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glVertexAttribL2d) ? "true" : "false")+"\n";
  status += std::string("  vertexAttribL2dv                              ")+((statusVertexAttribL2dv == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusVertexAttribL2dv == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glVertexAttribL2dv) ? "true" : "false")+"\n";
  status += std::string("  vertexAttribL3d                               ")+((statusVertexAttribL3d == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusVertexAttribL3d == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glVertexAttribL3d) ? "true" : "false")+"\n";
  status += std::string("  vertexAttribL3dv                              ")+((statusVertexAttribL3dv == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusVertexAttribL3dv == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glVertexAttribL3dv) ? "true" : "false")+"\n";
  status += std::string("  vertexAttribL4d                               ")+((statusVertexAttribL4d == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusVertexAttribL4d == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glVertexAttribL4d) ? "true" : "false")+"\n";
  status += std::string("  vertexAttribL4dv                              ")+((statusVertexAttribL4dv == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusVertexAttribL4dv == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glVertexAttribL4dv) ? "true" : "false")+"\n";
  status += std::string("  vertexAttribLPointer                          ")+((statusVertexAttribLPointer == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusVertexAttribLPointer == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glVertexAttribLPointer) ? "true" : "false")+"\n";
  status += std::string("  viewportArrayv                                ")+((statusViewportArrayv == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusViewportArrayv == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glViewportArrayv) ? "true" : "false")+"\n";
  status += std::string("  viewportIndexedf                              ")+((statusViewportIndexedf == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusViewportIndexedf == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glViewportIndexedf) ? "true" : "false")+"\n";
  status += std::string("  viewportIndexedfv                             ")+((statusViewportIndexedfv == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusViewportIndexedfv == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glViewportIndexedfv) ? "true" : "false")+"\n";
  status += "\n";
  status += "GL_VERSION_4_2\n";
  status += std::string("  bindImageTexture                              ")+((statusBindImageTexture == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusBindImageTexture == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glBindImageTexture) ? "true" : "false")+"\n";
  status += std::string("  drawArraysInstancedBaseInstance               ")+((statusDrawArraysInstancedBaseInstance == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusDrawArraysInstancedBaseInstance == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glDrawArraysInstancedBaseInstance) ? "true" : "false")+"\n";
  status += std::string("  drawElementsInstancedBaseInstance             ")+((statusDrawElementsInstancedBaseInstance == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusDrawElementsInstancedBaseInstance == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glDrawElementsInstancedBaseInstance) ? "true" : "false")+"\n";
  status += std::string("  drawElementsInstancedBaseVertexBaseInstance   ")+((statusDrawElementsInstancedBaseVertexBaseInstance == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusDrawElementsInstancedBaseVertexBaseInstance == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glDrawElementsInstancedBaseVertexBaseInstance) ? "true" : "false")+"\n";
  status += std::string("  drawTransformFeedbackInstanced                ")+((statusDrawTransformFeedbackInstanced == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusDrawTransformFeedbackInstanced == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glDrawTransformFeedbackInstanced) ? "true" : "false")+"\n";
  status += std::string("  drawTransformFeedbackStreamInstanced          ")+((statusDrawTransformFeedbackStreamInstanced == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusDrawTransformFeedbackStreamInstanced == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glDrawTransformFeedbackStreamInstanced) ? "true" : "false")+"\n";
  status += std::string("  getActiveAtomicCounterBufferiv                ")+((statusGetActiveAtomicCounterBufferiv == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusGetActiveAtomicCounterBufferiv == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glGetActiveAtomicCounterBufferiv) ? "true" : "false")+"\n";
  status += std::string("  getInternalformativ                           ")+((statusGetInternalformativ == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusGetInternalformativ == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glGetInternalformativ) ? "true" : "false")+"\n";
  status += std::string("  memoryBarrier                                 ")+((statusMemoryBarrier == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusMemoryBarrier == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glMemoryBarrier) ? "true" : "false")+"\n";
  status += std::string("  texStorage1D                                  ")+((statusTexStorage1D == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusTexStorage1D == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glTexStorage1D) ? "true" : "false")+"\n";
  status += std::string("  texStorage2D                                  ")+((statusTexStorage2D == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusTexStorage2D == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glTexStorage2D) ? "true" : "false")+"\n";
  status += std::string("  texStorage3D                                  ")+((statusTexStorage3D == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusTexStorage3D == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glTexStorage3D) ? "true" : "false")+"\n";
  status += "\n";
  status += "GL_VERSION_4_3\n";
  status += std::string("  bindVertexBuffer                              ")+((statusBindVertexBuffer == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusBindVertexBuffer == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glBindVertexBuffer) ? "true" : "false")+"\n";
  status += std::string("  clearBufferData                               ")+((statusClearBufferData == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusClearBufferData == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glClearBufferData) ? "true" : "false")+"\n";
  status += std::string("  clearBufferSubData                            ")+((statusClearBufferSubData == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusClearBufferSubData == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glClearBufferSubData) ? "true" : "false")+"\n";
  status += std::string("  copyImageSubData                              ")+((statusCopyImageSubData == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusCopyImageSubData == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glCopyImageSubData) ? "true" : "false")+"\n";
  status += std::string("  debugMessageCallback                          ")+((statusDebugMessageCallback == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusDebugMessageCallback == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glDebugMessageCallback) ? "true" : "false")+"\n";
  status += std::string("  debugMessageControl                           ")+((statusDebugMessageControl == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusDebugMessageControl == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glDebugMessageControl) ? "true" : "false")+"\n";
  status += std::string("  debugMessageInsert                            ")+((statusDebugMessageInsert == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusDebugMessageInsert == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glDebugMessageInsert) ? "true" : "false")+"\n";
  status += std::string("  dispatchCompute                               ")+((statusDispatchCompute == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusDispatchCompute == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glDispatchCompute) ? "true" : "false")+"\n";
  status += std::string("  dispatchComputeIndirect                       ")+((statusDispatchComputeIndirect == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusDispatchComputeIndirect == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glDispatchComputeIndirect) ? "true" : "false")+"\n";
  status += std::string("  framebufferParameteri                         ")+((statusFramebufferParameteri == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusFramebufferParameteri == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glFramebufferParameteri) ? "true" : "false")+"\n";
  status += std::string("  getDebugMessageLog                            ")+((statusGetDebugMessageLog == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusGetDebugMessageLog == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glGetDebugMessageLog) ? "true" : "false")+"\n";
  status += std::string("  getFramebufferParameteriv                     ")+((statusGetFramebufferParameteriv == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusGetFramebufferParameteriv == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glGetFramebufferParameteriv) ? "true" : "false")+"\n";
  status += std::string("  getInternalformati64v                         ")+((statusGetInternalformati64v == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusGetInternalformati64v == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glGetInternalformati64v) ? "true" : "false")+"\n";
  status += std::string("  getObjectLabel                                ")+((statusGetObjectLabel == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusGetObjectLabel == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glGetObjectLabel) ? "true" : "false")+"\n";
  status += std::string("  getObjectPtrLabel                             ")+((statusGetObjectPtrLabel == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusGetObjectPtrLabel == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glGetObjectPtrLabel) ? "true" : "false")+"\n";
  status += std::string("  getProgramInterfaceiv                         ")+((statusGetProgramInterfaceiv == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusGetProgramInterfaceiv == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glGetProgramInterfaceiv) ? "true" : "false")+"\n";
  status += std::string("  getProgramResourceIndex                       ")+((statusGetProgramResourceIndex == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusGetProgramResourceIndex == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glGetProgramResourceIndex) ? "true" : "false")+"\n";
  status += std::string("  getProgramResourceLocation                    ")+((statusGetProgramResourceLocation == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusGetProgramResourceLocation == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glGetProgramResourceLocation) ? "true" : "false")+"\n";
  status += std::string("  getProgramResourceLocationIndex               ")+((statusGetProgramResourceLocationIndex == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusGetProgramResourceLocationIndex == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glGetProgramResourceLocationIndex) ? "true" : "false")+"\n";
  status += std::string("  getProgramResourceName                        ")+((statusGetProgramResourceName == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusGetProgramResourceName == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glGetProgramResourceName) ? "true" : "false")+"\n";
  status += std::string("  getProgramResourceiv                          ")+((statusGetProgramResourceiv == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusGetProgramResourceiv == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glGetProgramResourceiv) ? "true" : "false")+"\n";
  status += std::string("  invalidateBufferData                          ")+((statusInvalidateBufferData == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusInvalidateBufferData == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glInvalidateBufferData) ? "true" : "false")+"\n";
  status += std::string("  invalidateBufferSubData                       ")+((statusInvalidateBufferSubData == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusInvalidateBufferSubData == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glInvalidateBufferSubData) ? "true" : "false")+"\n";
  status += std::string("  invalidateFramebuffer                         ")+((statusInvalidateFramebuffer == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusInvalidateFramebuffer == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glInvalidateFramebuffer) ? "true" : "false")+"\n";
  status += std::string("  invalidateSubFramebuffer                      ")+((statusInvalidateSubFramebuffer == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusInvalidateSubFramebuffer == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glInvalidateSubFramebuffer) ? "true" : "false")+"\n";
  status += std::string("  invalidateTexImage                            ")+((statusInvalidateTexImage == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusInvalidateTexImage == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glInvalidateTexImage) ? "true" : "false")+"\n";
  status += std::string("  invalidateTexSubImage                         ")+((statusInvalidateTexSubImage == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusInvalidateTexSubImage == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glInvalidateTexSubImage) ? "true" : "false")+"\n";
  status += std::string("  multiDrawArraysIndirect                       ")+((statusMultiDrawArraysIndirect == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusMultiDrawArraysIndirect == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glMultiDrawArraysIndirect) ? "true" : "false")+"\n";
  status += std::string("  multiDrawElementsIndirect                     ")+((statusMultiDrawElementsIndirect == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusMultiDrawElementsIndirect == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glMultiDrawElementsIndirect) ? "true" : "false")+"\n";
  status += std::string("  objectLabel                                   ")+((statusObjectLabel == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusObjectLabel == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glObjectLabel) ? "true" : "false")+"\n";
  status += std::string("  objectPtrLabel                                ")+((statusObjectPtrLabel == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusObjectPtrLabel == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glObjectPtrLabel) ? "true" : "false")+"\n";
  status += std::string("  popDebugGroup                                 ")+((statusPopDebugGroup == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusPopDebugGroup == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glPopDebugGroup) ? "true" : "false")+"\n";
  status += std::string("  pushDebugGroup                                ")+((statusPushDebugGroup == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusPushDebugGroup == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glPushDebugGroup) ? "true" : "false")+"\n";
  status += std::string("  shaderStorageBlockBinding                     ")+((statusShaderStorageBlockBinding == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusShaderStorageBlockBinding == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glShaderStorageBlockBinding) ? "true" : "false")+"\n";
  status += std::string("  texBufferRange                                ")+((statusTexBufferRange == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusTexBufferRange == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glTexBufferRange) ? "true" : "false")+"\n";
  status += std::string("  texStorage2DMultisample                       ")+((statusTexStorage2DMultisample == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusTexStorage2DMultisample == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glTexStorage2DMultisample) ? "true" : "false")+"\n";
  status += std::string("  texStorage3DMultisample                       ")+((statusTexStorage3DMultisample == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusTexStorage3DMultisample == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glTexStorage3DMultisample) ? "true" : "false")+"\n";
  status += std::string("  textureView                                   ")+((statusTextureView == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusTextureView == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glTextureView) ? "true" : "false")+"\n";
  status += std::string("  vertexAttribBinding                           ")+((statusVertexAttribBinding == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusVertexAttribBinding == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glVertexAttribBinding) ? "true" : "false")+"\n";
  status += std::string("  vertexAttribFormat                            ")+((statusVertexAttribFormat == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusVertexAttribFormat == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glVertexAttribFormat) ? "true" : "false")+"\n";
  status += std::string("  vertexAttribIFormat                           ")+((statusVertexAttribIFormat == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusVertexAttribIFormat == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glVertexAttribIFormat) ? "true" : "false")+"\n";
  status += std::string("  vertexAttribLFormat                           ")+((statusVertexAttribLFormat == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusVertexAttribLFormat == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glVertexAttribLFormat) ? "true" : "false")+"\n";
  status += std::string("  vertexBindingDivisor                          ")+((statusVertexBindingDivisor == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusVertexBindingDivisor == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glVertexBindingDivisor) ? "true" : "false")+"\n";
  status += "\n";
  status += "GL_VERSION_4_4\n";
  status += std::string("  bindBuffersBase                               ")+((statusBindBuffersBase == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusBindBuffersBase == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glBindBuffersBase) ? "true" : "false")+"\n";
  status += std::string("  bindBuffersRange                              ")+((statusBindBuffersRange == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusBindBuffersRange == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glBindBuffersRange) ? "true" : "false")+"\n";
  status += std::string("  bindImageTextures                             ")+((statusBindImageTextures == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusBindImageTextures == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glBindImageTextures) ? "true" : "false")+"\n";
  status += std::string("  bindSamplers                                  ")+((statusBindSamplers == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusBindSamplers == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glBindSamplers) ? "true" : "false")+"\n";
  status += std::string("  bindTextures                                  ")+((statusBindTextures == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusBindTextures == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glBindTextures) ? "true" : "false")+"\n";
  status += std::string("  bindVertexBuffers                             ")+((statusBindVertexBuffers == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusBindVertexBuffers == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glBindVertexBuffers) ? "true" : "false")+"\n";
  status += std::string("  bufferStorage                                 ")+((statusBufferStorage == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusBufferStorage == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glBufferStorage) ? "true" : "false")+"\n";
  status += std::string("  clearTexImage                                 ")+((statusClearTexImage == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusClearTexImage == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glClearTexImage) ? "true" : "false")+"\n";
  status += std::string("  clearTexSubImage                              ")+((statusClearTexSubImage == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusClearTexSubImage == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glClearTexSubImage) ? "true" : "false")+"\n";
  status += "\n";
  status += "GL_VERSION_4_5\n";
  status += std::string("  bindTextureUnit                               ")+((statusBindTextureUnit == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusBindTextureUnit == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glBindTextureUnit) ? "true" : "false")+"\n";
  status += std::string("  blitNamedFramebuffer                          ")+((statusBlitNamedFramebuffer == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusBlitNamedFramebuffer == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glBlitNamedFramebuffer) ? "true" : "false")+"\n";
  status += std::string("  checkNamedFramebufferStatus                   ")+((statusCheckNamedFramebufferStatus == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusCheckNamedFramebufferStatus == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glCheckNamedFramebufferStatus) ? "true" : "false")+"\n";
  status += std::string("  clearNamedBufferData                          ")+((statusClearNamedBufferData == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusClearNamedBufferData == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glClearNamedBufferData) ? "true" : "false")+"\n";
  status += std::string("  clearNamedBufferSubData                       ")+((statusClearNamedBufferSubData == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusClearNamedBufferSubData == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glClearNamedBufferSubData) ? "true" : "false")+"\n";
  status += std::string("  clearNamedFramebufferfi                       ")+((statusClearNamedFramebufferfi == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusClearNamedFramebufferfi == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glClearNamedFramebufferfi) ? "true" : "false")+"\n";
  status += std::string("  clearNamedFramebufferfv                       ")+((statusClearNamedFramebufferfv == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusClearNamedFramebufferfv == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glClearNamedFramebufferfv) ? "true" : "false")+"\n";
  status += std::string("  clearNamedFramebufferiv                       ")+((statusClearNamedFramebufferiv == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusClearNamedFramebufferiv == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glClearNamedFramebufferiv) ? "true" : "false")+"\n";
  status += std::string("  clearNamedFramebufferuiv                      ")+((statusClearNamedFramebufferuiv == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusClearNamedFramebufferuiv == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glClearNamedFramebufferuiv) ? "true" : "false")+"\n";
  status += std::string("  clipControl                                   ")+((statusClipControl == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusClipControl == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glClipControl) ? "true" : "false")+"\n";
  status += std::string("  compressedTextureSubImage1D                   ")+((statusCompressedTextureSubImage1D == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusCompressedTextureSubImage1D == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glCompressedTextureSubImage1D) ? "true" : "false")+"\n";
  status += std::string("  compressedTextureSubImage2D                   ")+((statusCompressedTextureSubImage2D == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusCompressedTextureSubImage2D == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glCompressedTextureSubImage2D) ? "true" : "false")+"\n";
  status += std::string("  compressedTextureSubImage3D                   ")+((statusCompressedTextureSubImage3D == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusCompressedTextureSubImage3D == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glCompressedTextureSubImage3D) ? "true" : "false")+"\n";
  status += std::string("  copyNamedBufferSubData                        ")+((statusCopyNamedBufferSubData == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusCopyNamedBufferSubData == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glCopyNamedBufferSubData) ? "true" : "false")+"\n";
  status += std::string("  copyTextureSubImage1D                         ")+((statusCopyTextureSubImage1D == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusCopyTextureSubImage1D == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glCopyTextureSubImage1D) ? "true" : "false")+"\n";
  status += std::string("  copyTextureSubImage2D                         ")+((statusCopyTextureSubImage2D == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusCopyTextureSubImage2D == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glCopyTextureSubImage2D) ? "true" : "false")+"\n";
  status += std::string("  copyTextureSubImage3D                         ")+((statusCopyTextureSubImage3D == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusCopyTextureSubImage3D == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glCopyTextureSubImage3D) ? "true" : "false")+"\n";
  status += std::string("  createBuffers                                 ")+((statusCreateBuffers == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusCreateBuffers == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glCreateBuffers) ? "true" : "false")+"\n";
  status += std::string("  createFramebuffers                            ")+((statusCreateFramebuffers == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusCreateFramebuffers == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glCreateFramebuffers) ? "true" : "false")+"\n";
  status += std::string("  createProgramPipelines                        ")+((statusCreateProgramPipelines == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusCreateProgramPipelines == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glCreateProgramPipelines) ? "true" : "false")+"\n";
  status += std::string("  createQueries                                 ")+((statusCreateQueries == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusCreateQueries == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glCreateQueries) ? "true" : "false")+"\n";
  status += std::string("  createRenderbuffers                           ")+((statusCreateRenderbuffers == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusCreateRenderbuffers == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glCreateRenderbuffers) ? "true" : "false")+"\n";
  status += std::string("  createSamplers                                ")+((statusCreateSamplers == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusCreateSamplers == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glCreateSamplers) ? "true" : "false")+"\n";
  status += std::string("  createTextures                                ")+((statusCreateTextures == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusCreateTextures == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glCreateTextures) ? "true" : "false")+"\n";
  status += std::string("  createTransformFeedbacks                      ")+((statusCreateTransformFeedbacks == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusCreateTransformFeedbacks == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glCreateTransformFeedbacks) ? "true" : "false")+"\n";
  status += std::string("  createVertexArrays                            ")+((statusCreateVertexArrays == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusCreateVertexArrays == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glCreateVertexArrays) ? "true" : "false")+"\n";
  status += std::string("  disableVertexArrayAttrib                      ")+((statusDisableVertexArrayAttrib == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusDisableVertexArrayAttrib == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glDisableVertexArrayAttrib) ? "true" : "false")+"\n";
  status += std::string("  enableVertexArrayAttrib                       ")+((statusEnableVertexArrayAttrib == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusEnableVertexArrayAttrib == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glEnableVertexArrayAttrib) ? "true" : "false")+"\n";
  status += std::string("  flushMappedNamedBufferRange                   ")+((statusFlushMappedNamedBufferRange == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusFlushMappedNamedBufferRange == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glFlushMappedNamedBufferRange) ? "true" : "false")+"\n";
  status += std::string("  generateTextureMipmap                         ")+((statusGenerateTextureMipmap == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusGenerateTextureMipmap == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glGenerateTextureMipmap) ? "true" : "false")+"\n";
  status += std::string("  getCompressedTextureImage                     ")+((statusGetCompressedTextureImage == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusGetCompressedTextureImage == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glGetCompressedTextureImage) ? "true" : "false")+"\n";
  status += std::string("  getCompressedTextureSubImage                  ")+((statusGetCompressedTextureSubImage == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusGetCompressedTextureSubImage == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glGetCompressedTextureSubImage) ? "true" : "false")+"\n";
  status += std::string("  getGraphicsResetStatus                        ")+((statusGetGraphicsResetStatus == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusGetGraphicsResetStatus == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glGetGraphicsResetStatus) ? "true" : "false")+"\n";
  status += std::string("  getNamedBufferParameteri64v                   ")+((statusGetNamedBufferParameteri64v == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusGetNamedBufferParameteri64v == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glGetNamedBufferParameteri64v) ? "true" : "false")+"\n";
  status += std::string("  getNamedBufferParameteriv                     ")+((statusGetNamedBufferParameteriv == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusGetNamedBufferParameteriv == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glGetNamedBufferParameteriv) ? "true" : "false")+"\n";
  status += std::string("  getNamedBufferPointerv                        ")+((statusGetNamedBufferPointerv == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusGetNamedBufferPointerv == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glGetNamedBufferPointerv) ? "true" : "false")+"\n";
  status += std::string("  getNamedBufferSubData                         ")+((statusGetNamedBufferSubData == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusGetNamedBufferSubData == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glGetNamedBufferSubData) ? "true" : "false")+"\n";
  status += std::string("  getNamedFramebufferAttachmentParameteriv      ")+((statusGetNamedFramebufferAttachmentParameteriv == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusGetNamedFramebufferAttachmentParameteriv == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glGetNamedFramebufferAttachmentParameteriv) ? "true" : "false")+"\n";
  status += std::string("  getNamedFramebufferParameteriv                ")+((statusGetNamedFramebufferParameteriv == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusGetNamedFramebufferParameteriv == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glGetNamedFramebufferParameteriv) ? "true" : "false")+"\n";
  status += std::string("  getNamedRenderbufferParameteriv               ")+((statusGetNamedRenderbufferParameteriv == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusGetNamedRenderbufferParameteriv == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glGetNamedRenderbufferParameteriv) ? "true" : "false")+"\n";
  status += std::string("  getQueryBufferObjecti64v                      ")+((statusGetQueryBufferObjecti64v == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusGetQueryBufferObjecti64v == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glGetQueryBufferObjecti64v) ? "true" : "false")+"\n";
  status += std::string("  getQueryBufferObjectiv                        ")+((statusGetQueryBufferObjectiv == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusGetQueryBufferObjectiv == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glGetQueryBufferObjectiv) ? "true" : "false")+"\n";
  status += std::string("  getQueryBufferObjectui64v                     ")+((statusGetQueryBufferObjectui64v == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusGetQueryBufferObjectui64v == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glGetQueryBufferObjectui64v) ? "true" : "false")+"\n";
  status += std::string("  getQueryBufferObjectuiv                       ")+((statusGetQueryBufferObjectuiv == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusGetQueryBufferObjectuiv == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glGetQueryBufferObjectuiv) ? "true" : "false")+"\n";
  status += std::string("  getTextureImage                               ")+((statusGetTextureImage == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusGetTextureImage == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glGetTextureImage) ? "true" : "false")+"\n";
  status += std::string("  getTextureLevelParameterfv                    ")+((statusGetTextureLevelParameterfv == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusGetTextureLevelParameterfv == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glGetTextureLevelParameterfv) ? "true" : "false")+"\n";
  status += std::string("  getTextureLevelParameteriv                    ")+((statusGetTextureLevelParameteriv == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusGetTextureLevelParameteriv == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glGetTextureLevelParameteriv) ? "true" : "false")+"\n";
  status += std::string("  getTextureParameterIiv                        ")+((statusGetTextureParameterIiv == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusGetTextureParameterIiv == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glGetTextureParameterIiv) ? "true" : "false")+"\n";
  status += std::string("  getTextureParameterIuiv                       ")+((statusGetTextureParameterIuiv == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusGetTextureParameterIuiv == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glGetTextureParameterIuiv) ? "true" : "false")+"\n";
  status += std::string("  getTextureParameterfv                         ")+((statusGetTextureParameterfv == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusGetTextureParameterfv == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glGetTextureParameterfv) ? "true" : "false")+"\n";
  status += std::string("  getTextureParameteriv                         ")+((statusGetTextureParameteriv == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusGetTextureParameteriv == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glGetTextureParameteriv) ? "true" : "false")+"\n";
  status += std::string("  getTextureSubImage                            ")+((statusGetTextureSubImage == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusGetTextureSubImage == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glGetTextureSubImage) ? "true" : "false")+"\n";
  status += std::string("  getTransformFeedbacki64_v                     ")+((statusGetTransformFeedbacki64_v == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusGetTransformFeedbacki64_v == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glGetTransformFeedbacki64_v) ? "true" : "false")+"\n";
  status += std::string("  getTransformFeedbacki_v                       ")+((statusGetTransformFeedbacki_v == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusGetTransformFeedbacki_v == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glGetTransformFeedbacki_v) ? "true" : "false")+"\n";
  status += std::string("  getTransformFeedbackiv                        ")+((statusGetTransformFeedbackiv == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusGetTransformFeedbackiv == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glGetTransformFeedbackiv) ? "true" : "false")+"\n";
  status += std::string("  getVertexArrayIndexed64iv                     ")+((statusGetVertexArrayIndexed64iv == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusGetVertexArrayIndexed64iv == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glGetVertexArrayIndexed64iv) ? "true" : "false")+"\n";
  status += std::string("  getVertexArrayIndexediv                       ")+((statusGetVertexArrayIndexediv == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusGetVertexArrayIndexediv == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glGetVertexArrayIndexediv) ? "true" : "false")+"\n";
  status += std::string("  getVertexArrayiv                              ")+((statusGetVertexArrayiv == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusGetVertexArrayiv == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glGetVertexArrayiv) ? "true" : "false")+"\n";
  status += std::string("  getnCompressedTexImage                        ")+((statusGetnCompressedTexImage == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusGetnCompressedTexImage == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glGetnCompressedTexImage) ? "true" : "false")+"\n";
  status += std::string("  getnTexImage                                  ")+((statusGetnTexImage == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusGetnTexImage == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glGetnTexImage) ? "true" : "false")+"\n";
  status += std::string("  getnUniformdv                                 ")+((statusGetnUniformdv == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusGetnUniformdv == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glGetnUniformdv) ? "true" : "false")+"\n";
  status += std::string("  getnUniformfv                                 ")+((statusGetnUniformfv == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusGetnUniformfv == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glGetnUniformfv) ? "true" : "false")+"\n";
  status += std::string("  getnUniformiv                                 ")+((statusGetnUniformiv == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusGetnUniformiv == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glGetnUniformiv) ? "true" : "false")+"\n";
  status += std::string("  getnUniformuiv                                ")+((statusGetnUniformuiv == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusGetnUniformuiv == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glGetnUniformuiv) ? "true" : "false")+"\n";
  status += std::string("  invalidateNamedFramebufferData                ")+((statusInvalidateNamedFramebufferData == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusInvalidateNamedFramebufferData == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glInvalidateNamedFramebufferData) ? "true" : "false")+"\n";
  status += std::string("  invalidateNamedFramebufferSubData             ")+((statusInvalidateNamedFramebufferSubData == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusInvalidateNamedFramebufferSubData == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glInvalidateNamedFramebufferSubData) ? "true" : "false")+"\n";
  status += std::string("  mapNamedBuffer                                ")+((statusMapNamedBuffer == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusMapNamedBuffer == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glMapNamedBuffer) ? "true" : "false")+"\n";
  status += std::string("  mapNamedBufferRange                           ")+((statusMapNamedBufferRange == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusMapNamedBufferRange == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glMapNamedBufferRange) ? "true" : "false")+"\n";
  status += std::string("  memoryBarrierByRegion                         ")+((statusMemoryBarrierByRegion == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusMemoryBarrierByRegion == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glMemoryBarrierByRegion) ? "true" : "false")+"\n";
  status += std::string("  namedBufferData                               ")+((statusNamedBufferData == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusNamedBufferData == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glNamedBufferData) ? "true" : "false")+"\n";
  status += std::string("  namedBufferStorage                            ")+((statusNamedBufferStorage == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusNamedBufferStorage == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glNamedBufferStorage) ? "true" : "false")+"\n";
  status += std::string("  namedBufferSubData                            ")+((statusNamedBufferSubData == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusNamedBufferSubData == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glNamedBufferSubData) ? "true" : "false")+"\n";
  status += std::string("  namedFramebufferDrawBuffer                    ")+((statusNamedFramebufferDrawBuffer == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusNamedFramebufferDrawBuffer == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glNamedFramebufferDrawBuffer) ? "true" : "false")+"\n";
  status += std::string("  namedFramebufferDrawBuffers                   ")+((statusNamedFramebufferDrawBuffers == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusNamedFramebufferDrawBuffers == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glNamedFramebufferDrawBuffers) ? "true" : "false")+"\n";
  status += std::string("  namedFramebufferParameteri                    ")+((statusNamedFramebufferParameteri == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusNamedFramebufferParameteri == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glNamedFramebufferParameteri) ? "true" : "false")+"\n";
  status += std::string("  namedFramebufferReadBuffer                    ")+((statusNamedFramebufferReadBuffer == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusNamedFramebufferReadBuffer == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glNamedFramebufferReadBuffer) ? "true" : "false")+"\n";
  status += std::string("  namedFramebufferRenderbuffer                  ")+((statusNamedFramebufferRenderbuffer == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusNamedFramebufferRenderbuffer == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glNamedFramebufferRenderbuffer) ? "true" : "false")+"\n";
  status += std::string("  namedFramebufferTexture                       ")+((statusNamedFramebufferTexture == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusNamedFramebufferTexture == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glNamedFramebufferTexture) ? "true" : "false")+"\n";
  status += std::string("  namedFramebufferTextureLayer                  ")+((statusNamedFramebufferTextureLayer == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusNamedFramebufferTextureLayer == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glNamedFramebufferTextureLayer) ? "true" : "false")+"\n";
  status += std::string("  namedRenderbufferStorage                      ")+((statusNamedRenderbufferStorage == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusNamedRenderbufferStorage == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glNamedRenderbufferStorage) ? "true" : "false")+"\n";
  status += std::string("  namedRenderbufferStorageMultisample           ")+((statusNamedRenderbufferStorageMultisample == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusNamedRenderbufferStorageMultisample == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glNamedRenderbufferStorageMultisample) ? "true" : "false")+"\n";
  status += std::string("  readnPixels                                   ")+((statusReadnPixels == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusReadnPixels == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glReadnPixels) ? "true" : "false")+"\n";
  status += std::string("  textureBarrier                                ")+((statusTextureBarrier == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusTextureBarrier == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glTextureBarrier) ? "true" : "false")+"\n";
  status += std::string("  textureBuffer                                 ")+((statusTextureBuffer == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusTextureBuffer == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glTextureBuffer) ? "true" : "false")+"\n";
  status += std::string("  textureBufferRange                            ")+((statusTextureBufferRange == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusTextureBufferRange == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glTextureBufferRange) ? "true" : "false")+"\n";
  status += std::string("  textureParameterIiv                           ")+((statusTextureParameterIiv == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusTextureParameterIiv == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glTextureParameterIiv) ? "true" : "false")+"\n";
  status += std::string("  textureParameterIuiv                          ")+((statusTextureParameterIuiv == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusTextureParameterIuiv == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glTextureParameterIuiv) ? "true" : "false")+"\n";
  status += std::string("  textureParameterf                             ")+((statusTextureParameterf == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusTextureParameterf == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glTextureParameterf) ? "true" : "false")+"\n";
  status += std::string("  textureParameterfv                            ")+((statusTextureParameterfv == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusTextureParameterfv == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glTextureParameterfv) ? "true" : "false")+"\n";
  status += std::string("  textureParameteri                             ")+((statusTextureParameteri == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusTextureParameteri == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glTextureParameteri) ? "true" : "false")+"\n";
  status += std::string("  textureParameteriv                            ")+((statusTextureParameteriv == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusTextureParameteriv == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glTextureParameteriv) ? "true" : "false")+"\n";
  status += std::string("  textureStorage1D                              ")+((statusTextureStorage1D == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusTextureStorage1D == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glTextureStorage1D) ? "true" : "false")+"\n";
  status += std::string("  textureStorage2D                              ")+((statusTextureStorage2D == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusTextureStorage2D == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glTextureStorage2D) ? "true" : "false")+"\n";
  status += std::string("  textureStorage2DMultisample                   ")+((statusTextureStorage2DMultisample == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusTextureStorage2DMultisample == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glTextureStorage2DMultisample) ? "true" : "false")+"\n";
  status += std::string("  textureStorage3D                              ")+((statusTextureStorage3D == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusTextureStorage3D == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glTextureStorage3D) ? "true" : "false")+"\n";
  status += std::string("  textureStorage3DMultisample                   ")+((statusTextureStorage3DMultisample == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusTextureStorage3DMultisample == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glTextureStorage3DMultisample) ? "true" : "false")+"\n";
  status += std::string("  textureSubImage1D                             ")+((statusTextureSubImage1D == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusTextureSubImage1D == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glTextureSubImage1D) ? "true" : "false")+"\n";
  status += std::string("  textureSubImage2D                             ")+((statusTextureSubImage2D == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusTextureSubImage2D == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glTextureSubImage2D) ? "true" : "false")+"\n";
  status += std::string("  textureSubImage3D                             ")+((statusTextureSubImage3D == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusTextureSubImage3D == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glTextureSubImage3D) ? "true" : "false")+"\n";
  status += std::string("  transformFeedbackBufferBase                   ")+((statusTransformFeedbackBufferBase == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusTransformFeedbackBufferBase == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glTransformFeedbackBufferBase) ? "true" : "false")+"\n";
  status += std::string("  transformFeedbackBufferRange                  ")+((statusTransformFeedbackBufferRange == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusTransformFeedbackBufferRange == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glTransformFeedbackBufferRange) ? "true" : "false")+"\n";
  status += std::string("  unmapNamedBuffer                              ")+((statusUnmapNamedBuffer == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusUnmapNamedBuffer == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glUnmapNamedBuffer) ? "true" : "false")+"\n";
  status += std::string("  vertexArrayAttribBinding                      ")+((statusVertexArrayAttribBinding == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusVertexArrayAttribBinding == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glVertexArrayAttribBinding) ? "true" : "false")+"\n";
  status += std::string("  vertexArrayAttribFormat                       ")+((statusVertexArrayAttribFormat == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusVertexArrayAttribFormat == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glVertexArrayAttribFormat) ? "true" : "false")+"\n";
  status += std::string("  vertexArrayAttribIFormat                      ")+((statusVertexArrayAttribIFormat == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusVertexArrayAttribIFormat == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glVertexArrayAttribIFormat) ? "true" : "false")+"\n";
  status += std::string("  vertexArrayAttribLFormat                      ")+((statusVertexArrayAttribLFormat == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusVertexArrayAttribLFormat == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glVertexArrayAttribLFormat) ? "true" : "false")+"\n";
  status += std::string("  vertexArrayBindingDivisor                     ")+((statusVertexArrayBindingDivisor == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusVertexArrayBindingDivisor == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glVertexArrayBindingDivisor) ? "true" : "false")+"\n";
  status += std::string("  vertexArrayElementBuffer                      ")+((statusVertexArrayElementBuffer == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusVertexArrayElementBuffer == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glVertexArrayElementBuffer) ? "true" : "false")+"\n";
  status += std::string("  vertexArrayVertexBuffer                       ")+((statusVertexArrayVertexBuffer == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusVertexArrayVertexBuffer == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glVertexArrayVertexBuffer) ? "true" : "false")+"\n";
  status += std::string("  vertexArrayVertexBuffers                      ")+((statusVertexArrayVertexBuffers == NOpenGLProc::TYPE_ARB) ? "ARB" : ((statusVertexArrayVertexBuffers == NOpenGLProc::TYPE_EXT) ? "EXT" : "   "))+" : "+((glVertexArrayVertexBuffers) ? "true" : "false")+"\n";

  return status;
}
//------------------------------------------------------------------------------
