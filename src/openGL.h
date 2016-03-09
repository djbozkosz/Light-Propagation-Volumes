//------------------------------------------------------------------------------
#ifndef OPENGL_H
#define OPENGL_H

#include "filesystem.h"
#include "headers/openGLTypes.h"

//------------------------------------------------------------------------------
class COpenGL : public CEngineBase
{
  private:
    // GL_VERSION_1_2
    NOpenGLProc::TCopyTexSubImage3D glCopyTexSubImage3D; NOpenGLProc::EProcType statusCopyTexSubImage3D;
    NOpenGLProc::TDrawRangeElements glDrawRangeElements; NOpenGLProc::EProcType statusDrawRangeElements;
    NOpenGLProc::TTexImage3D glTexImage3D; NOpenGLProc::EProcType statusTexImage3D;
    NOpenGLProc::TTexSubImage3D glTexSubImage3D; NOpenGLProc::EProcType statusTexSubImage3D;

    // GL_VERSION_1_3
    NOpenGLProc::TActiveTexture glActiveTexture; NOpenGLProc::EProcType statusActiveTexture;
    NOpenGLProc::TCompressedTexImage1D glCompressedTexImage1D; NOpenGLProc::EProcType statusCompressedTexImage1D;
    NOpenGLProc::TCompressedTexImage2D glCompressedTexImage2D; NOpenGLProc::EProcType statusCompressedTexImage2D;
    NOpenGLProc::TCompressedTexImage3D glCompressedTexImage3D; NOpenGLProc::EProcType statusCompressedTexImage3D;
    NOpenGLProc::TCompressedTexSubImage1D glCompressedTexSubImage1D; NOpenGLProc::EProcType statusCompressedTexSubImage1D;
    NOpenGLProc::TCompressedTexSubImage2D glCompressedTexSubImage2D; NOpenGLProc::EProcType statusCompressedTexSubImage2D;
    NOpenGLProc::TCompressedTexSubImage3D glCompressedTexSubImage3D; NOpenGLProc::EProcType statusCompressedTexSubImage3D;
    NOpenGLProc::TGetCompressedTexImage glGetCompressedTexImage; NOpenGLProc::EProcType statusGetCompressedTexImage;
    NOpenGLProc::TSampleCoverage glSampleCoverage; NOpenGLProc::EProcType statusSampleCoverage;

    // GL_VERSION_1_4
    NOpenGLProc::TBlendColor glBlendColor; NOpenGLProc::EProcType statusBlendColor;
    NOpenGLProc::TBlendEquation glBlendEquation; NOpenGLProc::EProcType statusBlendEquation;
    NOpenGLProc::TBlendFuncSeparate glBlendFuncSeparate; NOpenGLProc::EProcType statusBlendFuncSeparate;
    NOpenGLProc::TMultiDrawArrays glMultiDrawArrays; NOpenGLProc::EProcType statusMultiDrawArrays;
    NOpenGLProc::TMultiDrawElements glMultiDrawElements; NOpenGLProc::EProcType statusMultiDrawElements;
    NOpenGLProc::TPointParameterf glPointParameterf; NOpenGLProc::EProcType statusPointParameterf;
    NOpenGLProc::TPointParameterfv glPointParameterfv; NOpenGLProc::EProcType statusPointParameterfv;
    NOpenGLProc::TPointParameteri glPointParameteri; NOpenGLProc::EProcType statusPointParameteri;
    NOpenGLProc::TPointParameteriv glPointParameteriv; NOpenGLProc::EProcType statusPointParameteriv;

    // GL_VERSION_1_5
    NOpenGLProc::TBeginQuery glBeginQuery; NOpenGLProc::EProcType statusBeginQuery;
    NOpenGLProc::TBindBuffer glBindBuffer; NOpenGLProc::EProcType statusBindBuffer;
    NOpenGLProc::TBufferData glBufferData; NOpenGLProc::EProcType statusBufferData;
    NOpenGLProc::TBufferSubData glBufferSubData; NOpenGLProc::EProcType statusBufferSubData;
    NOpenGLProc::TDeleteBuffers glDeleteBuffers; NOpenGLProc::EProcType statusDeleteBuffers;
    NOpenGLProc::TDeleteQueries glDeleteQueries; NOpenGLProc::EProcType statusDeleteQueries;
    NOpenGLProc::TEndQuery glEndQuery; NOpenGLProc::EProcType statusEndQuery;
    NOpenGLProc::TGenBuffers glGenBuffers; NOpenGLProc::EProcType statusGenBuffers;
    NOpenGLProc::TGenQueries glGenQueries; NOpenGLProc::EProcType statusGenQueries;
    NOpenGLProc::TGetBufferParameteriv glGetBufferParameteriv; NOpenGLProc::EProcType statusGetBufferParameteriv;
    NOpenGLProc::TGetBufferPointerv glGetBufferPointerv; NOpenGLProc::EProcType statusGetBufferPointerv;
    NOpenGLProc::TGetBufferSubData glGetBufferSubData; NOpenGLProc::EProcType statusGetBufferSubData;
    NOpenGLProc::TGetQueryObjectiv glGetQueryObjectiv; NOpenGLProc::EProcType statusGetQueryObjectiv;
    NOpenGLProc::TGetQueryObjectuiv glGetQueryObjectuiv; NOpenGLProc::EProcType statusGetQueryObjectuiv;
    NOpenGLProc::TGetQueryiv glGetQueryiv; NOpenGLProc::EProcType statusGetQueryiv;
    NOpenGLProc::TIsBuffer glIsBuffer; NOpenGLProc::EProcType statusIsBuffer;
    NOpenGLProc::TIsQuery glIsQuery; NOpenGLProc::EProcType statusIsQuery;
    NOpenGLProc::TMapBuffer glMapBuffer; NOpenGLProc::EProcType statusMapBuffer;
    NOpenGLProc::TUnmapBuffer glUnmapBuffer; NOpenGLProc::EProcType statusUnmapBuffer;

    // GL_VERSION_2_0
    NOpenGLProc::TAttachShader glAttachShader; NOpenGLProc::EProcType statusAttachShader;
    NOpenGLProc::TBindAttribLocation glBindAttribLocation; NOpenGLProc::EProcType statusBindAttribLocation;
    NOpenGLProc::TBlendEquationSeparate glBlendEquationSeparate; NOpenGLProc::EProcType statusBlendEquationSeparate;
    NOpenGLProc::TCompileShader glCompileShader; NOpenGLProc::EProcType statusCompileShader;
    NOpenGLProc::TCreateProgram glCreateProgram; NOpenGLProc::EProcType statusCreateProgram;
    NOpenGLProc::TCreateShader glCreateShader; NOpenGLProc::EProcType statusCreateShader;
    NOpenGLProc::TDeleteProgram glDeleteProgram; NOpenGLProc::EProcType statusDeleteProgram;
    NOpenGLProc::TDeleteShader glDeleteShader; NOpenGLProc::EProcType statusDeleteShader;
    NOpenGLProc::TDetachShader glDetachShader; NOpenGLProc::EProcType statusDetachShader;
    NOpenGLProc::TDisableVertexAttribArray glDisableVertexAttribArray; NOpenGLProc::EProcType statusDisableVertexAttribArray;
    NOpenGLProc::TDrawBuffers glDrawBuffers; NOpenGLProc::EProcType statusDrawBuffers;
    NOpenGLProc::TEnableVertexAttribArray glEnableVertexAttribArray; NOpenGLProc::EProcType statusEnableVertexAttribArray;
    NOpenGLProc::TGetActiveAttrib glGetActiveAttrib; NOpenGLProc::EProcType statusGetActiveAttrib;
    NOpenGLProc::TGetActiveUniform glGetActiveUniform; NOpenGLProc::EProcType statusGetActiveUniform;
    NOpenGLProc::TGetAttachedShaders glGetAttachedShaders; NOpenGLProc::EProcType statusGetAttachedShaders;
    NOpenGLProc::TGetAttribLocation glGetAttribLocation; NOpenGLProc::EProcType statusGetAttribLocation;
    NOpenGLProc::TGetProgramInfoLog glGetProgramInfoLog; NOpenGLProc::EProcType statusGetProgramInfoLog;
    NOpenGLProc::TGetProgramiv glGetProgramiv; NOpenGLProc::EProcType statusGetProgramiv;
    NOpenGLProc::TGetShaderInfoLog glGetShaderInfoLog; NOpenGLProc::EProcType statusGetShaderInfoLog;
    NOpenGLProc::TGetShaderSource glGetShaderSource; NOpenGLProc::EProcType statusGetShaderSource;
    NOpenGLProc::TGetShaderiv glGetShaderiv; NOpenGLProc::EProcType statusGetShaderiv;
    NOpenGLProc::TGetUniformLocation glGetUniformLocation; NOpenGLProc::EProcType statusGetUniformLocation;
    NOpenGLProc::TGetUniformfv glGetUniformfv; NOpenGLProc::EProcType statusGetUniformfv;
    NOpenGLProc::TGetUniformiv glGetUniformiv; NOpenGLProc::EProcType statusGetUniformiv;
    NOpenGLProc::TGetVertexAttribPointerv glGetVertexAttribPointerv; NOpenGLProc::EProcType statusGetVertexAttribPointerv;
    NOpenGLProc::TGetVertexAttribdv glGetVertexAttribdv; NOpenGLProc::EProcType statusGetVertexAttribdv;
    NOpenGLProc::TGetVertexAttribfv glGetVertexAttribfv; NOpenGLProc::EProcType statusGetVertexAttribfv;
    NOpenGLProc::TGetVertexAttribiv glGetVertexAttribiv; NOpenGLProc::EProcType statusGetVertexAttribiv;
    NOpenGLProc::TIsProgram glIsProgram; NOpenGLProc::EProcType statusIsProgram;
    NOpenGLProc::TIsShader glIsShader; NOpenGLProc::EProcType statusIsShader;
    NOpenGLProc::TLinkProgram glLinkProgram; NOpenGLProc::EProcType statusLinkProgram;
    NOpenGLProc::TShaderSource glShaderSource; NOpenGLProc::EProcType statusShaderSource;
    NOpenGLProc::TStencilFuncSeparate glStencilFuncSeparate; NOpenGLProc::EProcType statusStencilFuncSeparate;
    NOpenGLProc::TStencilMaskSeparate glStencilMaskSeparate; NOpenGLProc::EProcType statusStencilMaskSeparate;
    NOpenGLProc::TStencilOpSeparate glStencilOpSeparate; NOpenGLProc::EProcType statusStencilOpSeparate;
    NOpenGLProc::TUniform1f glUniform1f; NOpenGLProc::EProcType statusUniform1f;
    NOpenGLProc::TUniform1fv glUniform1fv; NOpenGLProc::EProcType statusUniform1fv;
    NOpenGLProc::TUniform1i glUniform1i; NOpenGLProc::EProcType statusUniform1i;
    NOpenGLProc::TUniform1iv glUniform1iv; NOpenGLProc::EProcType statusUniform1iv;
    NOpenGLProc::TUniform2f glUniform2f; NOpenGLProc::EProcType statusUniform2f;
    NOpenGLProc::TUniform2fv glUniform2fv; NOpenGLProc::EProcType statusUniform2fv;
    NOpenGLProc::TUniform2i glUniform2i; NOpenGLProc::EProcType statusUniform2i;
    NOpenGLProc::TUniform2iv glUniform2iv; NOpenGLProc::EProcType statusUniform2iv;
    NOpenGLProc::TUniform3f glUniform3f; NOpenGLProc::EProcType statusUniform3f;
    NOpenGLProc::TUniform3fv glUniform3fv; NOpenGLProc::EProcType statusUniform3fv;
    NOpenGLProc::TUniform3i glUniform3i; NOpenGLProc::EProcType statusUniform3i;
    NOpenGLProc::TUniform3iv glUniform3iv; NOpenGLProc::EProcType statusUniform3iv;
    NOpenGLProc::TUniform4f glUniform4f; NOpenGLProc::EProcType statusUniform4f;
    NOpenGLProc::TUniform4fv glUniform4fv; NOpenGLProc::EProcType statusUniform4fv;
    NOpenGLProc::TUniform4i glUniform4i; NOpenGLProc::EProcType statusUniform4i;
    NOpenGLProc::TUniform4iv glUniform4iv; NOpenGLProc::EProcType statusUniform4iv;
    NOpenGLProc::TUniformMatrix2fv glUniformMatrix2fv; NOpenGLProc::EProcType statusUniformMatrix2fv;
    NOpenGLProc::TUniformMatrix3fv glUniformMatrix3fv; NOpenGLProc::EProcType statusUniformMatrix3fv;
    NOpenGLProc::TUniformMatrix4fv glUniformMatrix4fv; NOpenGLProc::EProcType statusUniformMatrix4fv;
    NOpenGLProc::TUseProgram glUseProgram; NOpenGLProc::EProcType statusUseProgram;
    NOpenGLProc::TValidateProgram glValidateProgram; NOpenGLProc::EProcType statusValidateProgram;
    NOpenGLProc::TVertexAttrib1d glVertexAttrib1d; NOpenGLProc::EProcType statusVertexAttrib1d;
    NOpenGLProc::TVertexAttrib1dv glVertexAttrib1dv; NOpenGLProc::EProcType statusVertexAttrib1dv;
    NOpenGLProc::TVertexAttrib1f glVertexAttrib1f; NOpenGLProc::EProcType statusVertexAttrib1f;
    NOpenGLProc::TVertexAttrib1fv glVertexAttrib1fv; NOpenGLProc::EProcType statusVertexAttrib1fv;
    NOpenGLProc::TVertexAttrib1s glVertexAttrib1s; NOpenGLProc::EProcType statusVertexAttrib1s;
    NOpenGLProc::TVertexAttrib1sv glVertexAttrib1sv; NOpenGLProc::EProcType statusVertexAttrib1sv;
    NOpenGLProc::TVertexAttrib2d glVertexAttrib2d; NOpenGLProc::EProcType statusVertexAttrib2d;
    NOpenGLProc::TVertexAttrib2dv glVertexAttrib2dv; NOpenGLProc::EProcType statusVertexAttrib2dv;
    NOpenGLProc::TVertexAttrib2f glVertexAttrib2f; NOpenGLProc::EProcType statusVertexAttrib2f;
    NOpenGLProc::TVertexAttrib2fv glVertexAttrib2fv; NOpenGLProc::EProcType statusVertexAttrib2fv;
    NOpenGLProc::TVertexAttrib2s glVertexAttrib2s; NOpenGLProc::EProcType statusVertexAttrib2s;
    NOpenGLProc::TVertexAttrib2sv glVertexAttrib2sv; NOpenGLProc::EProcType statusVertexAttrib2sv;
    NOpenGLProc::TVertexAttrib3d glVertexAttrib3d; NOpenGLProc::EProcType statusVertexAttrib3d;
    NOpenGLProc::TVertexAttrib3dv glVertexAttrib3dv; NOpenGLProc::EProcType statusVertexAttrib3dv;
    NOpenGLProc::TVertexAttrib3f glVertexAttrib3f; NOpenGLProc::EProcType statusVertexAttrib3f;
    NOpenGLProc::TVertexAttrib3fv glVertexAttrib3fv; NOpenGLProc::EProcType statusVertexAttrib3fv;
    NOpenGLProc::TVertexAttrib3s glVertexAttrib3s; NOpenGLProc::EProcType statusVertexAttrib3s;
    NOpenGLProc::TVertexAttrib3sv glVertexAttrib3sv; NOpenGLProc::EProcType statusVertexAttrib3sv;
    NOpenGLProc::TVertexAttrib4Nbv glVertexAttrib4Nbv; NOpenGLProc::EProcType statusVertexAttrib4Nbv;
    NOpenGLProc::TVertexAttrib4Niv glVertexAttrib4Niv; NOpenGLProc::EProcType statusVertexAttrib4Niv;
    NOpenGLProc::TVertexAttrib4Nsv glVertexAttrib4Nsv; NOpenGLProc::EProcType statusVertexAttrib4Nsv;
    NOpenGLProc::TVertexAttrib4Nub glVertexAttrib4Nub; NOpenGLProc::EProcType statusVertexAttrib4Nub;
    NOpenGLProc::TVertexAttrib4Nubv glVertexAttrib4Nubv; NOpenGLProc::EProcType statusVertexAttrib4Nubv;
    NOpenGLProc::TVertexAttrib4Nuiv glVertexAttrib4Nuiv; NOpenGLProc::EProcType statusVertexAttrib4Nuiv;
    NOpenGLProc::TVertexAttrib4Nusv glVertexAttrib4Nusv; NOpenGLProc::EProcType statusVertexAttrib4Nusv;
    NOpenGLProc::TVertexAttrib4bv glVertexAttrib4bv; NOpenGLProc::EProcType statusVertexAttrib4bv;
    NOpenGLProc::TVertexAttrib4d glVertexAttrib4d; NOpenGLProc::EProcType statusVertexAttrib4d;
    NOpenGLProc::TVertexAttrib4dv glVertexAttrib4dv; NOpenGLProc::EProcType statusVertexAttrib4dv;
    NOpenGLProc::TVertexAttrib4f glVertexAttrib4f; NOpenGLProc::EProcType statusVertexAttrib4f;
    NOpenGLProc::TVertexAttrib4fv glVertexAttrib4fv; NOpenGLProc::EProcType statusVertexAttrib4fv;
    NOpenGLProc::TVertexAttrib4iv glVertexAttrib4iv; NOpenGLProc::EProcType statusVertexAttrib4iv;
    NOpenGLProc::TVertexAttrib4s glVertexAttrib4s; NOpenGLProc::EProcType statusVertexAttrib4s;
    NOpenGLProc::TVertexAttrib4sv glVertexAttrib4sv; NOpenGLProc::EProcType statusVertexAttrib4sv;
    NOpenGLProc::TVertexAttrib4ubv glVertexAttrib4ubv; NOpenGLProc::EProcType statusVertexAttrib4ubv;
    NOpenGLProc::TVertexAttrib4uiv glVertexAttrib4uiv; NOpenGLProc::EProcType statusVertexAttrib4uiv;
    NOpenGLProc::TVertexAttrib4usv glVertexAttrib4usv; NOpenGLProc::EProcType statusVertexAttrib4usv;
    NOpenGLProc::TVertexAttribPointer glVertexAttribPointer; NOpenGLProc::EProcType statusVertexAttribPointer;

    // GL_VERSION_2_1
    NOpenGLProc::TUniformMatrix2x3fv glUniformMatrix2x3fv; NOpenGLProc::EProcType statusUniformMatrix2x3fv;
    NOpenGLProc::TUniformMatrix2x4fv glUniformMatrix2x4fv; NOpenGLProc::EProcType statusUniformMatrix2x4fv;
    NOpenGLProc::TUniformMatrix3x2fv glUniformMatrix3x2fv; NOpenGLProc::EProcType statusUniformMatrix3x2fv;
    NOpenGLProc::TUniformMatrix3x4fv glUniformMatrix3x4fv; NOpenGLProc::EProcType statusUniformMatrix3x4fv;
    NOpenGLProc::TUniformMatrix4x2fv glUniformMatrix4x2fv; NOpenGLProc::EProcType statusUniformMatrix4x2fv;
    NOpenGLProc::TUniformMatrix4x3fv glUniformMatrix4x3fv; NOpenGLProc::EProcType statusUniformMatrix4x3fv;

    // GL_VERSION_3_0
    NOpenGLProc::TBeginConditionalRender glBeginConditionalRender; NOpenGLProc::EProcType statusBeginConditionalRender;
    NOpenGLProc::TBeginTransformFeedback glBeginTransformFeedback; NOpenGLProc::EProcType statusBeginTransformFeedback;
    NOpenGLProc::TBindBufferBase glBindBufferBase; NOpenGLProc::EProcType statusBindBufferBase;
    NOpenGLProc::TBindBufferRange glBindBufferRange; NOpenGLProc::EProcType statusBindBufferRange;
    NOpenGLProc::TBindFragDataLocation glBindFragDataLocation; NOpenGLProc::EProcType statusBindFragDataLocation;
    NOpenGLProc::TBindFramebuffer glBindFramebuffer; NOpenGLProc::EProcType statusBindFramebuffer;
    NOpenGLProc::TBindRenderbuffer glBindRenderbuffer; NOpenGLProc::EProcType statusBindRenderbuffer;
    NOpenGLProc::TBindVertexArray glBindVertexArray; NOpenGLProc::EProcType statusBindVertexArray;
    NOpenGLProc::TBlitFramebuffer glBlitFramebuffer; NOpenGLProc::EProcType statusBlitFramebuffer;
    NOpenGLProc::TCheckFramebufferStatus glCheckFramebufferStatus; NOpenGLProc::EProcType statusCheckFramebufferStatus;
    NOpenGLProc::TClampColor glClampColor; NOpenGLProc::EProcType statusClampColor;
    NOpenGLProc::TClearBufferfi glClearBufferfi; NOpenGLProc::EProcType statusClearBufferfi;
    NOpenGLProc::TClearBufferfv glClearBufferfv; NOpenGLProc::EProcType statusClearBufferfv;
    NOpenGLProc::TClearBufferiv glClearBufferiv; NOpenGLProc::EProcType statusClearBufferiv;
    NOpenGLProc::TClearBufferuiv glClearBufferuiv; NOpenGLProc::EProcType statusClearBufferuiv;
    NOpenGLProc::TColorMaski glColorMaski; NOpenGLProc::EProcType statusColorMaski;
    NOpenGLProc::TDeleteFramebuffers glDeleteFramebuffers; NOpenGLProc::EProcType statusDeleteFramebuffers;
    NOpenGLProc::TDeleteRenderbuffers glDeleteRenderbuffers; NOpenGLProc::EProcType statusDeleteRenderbuffers;
    NOpenGLProc::TDeleteVertexArrays glDeleteVertexArrays; NOpenGLProc::EProcType statusDeleteVertexArrays;
    NOpenGLProc::TDisablei glDisablei; NOpenGLProc::EProcType statusDisablei;
    NOpenGLProc::TEnablei glEnablei; NOpenGLProc::EProcType statusEnablei;
    NOpenGLProc::TEndConditionalRender glEndConditionalRender; NOpenGLProc::EProcType statusEndConditionalRender;
    NOpenGLProc::TEndTransformFeedback glEndTransformFeedback; NOpenGLProc::EProcType statusEndTransformFeedback;
    NOpenGLProc::TFlushMappedBufferRange glFlushMappedBufferRange; NOpenGLProc::EProcType statusFlushMappedBufferRange;
    NOpenGLProc::TFramebufferRenderbuffer glFramebufferRenderbuffer; NOpenGLProc::EProcType statusFramebufferRenderbuffer;
    NOpenGLProc::TFramebufferTexture1D glFramebufferTexture1D; NOpenGLProc::EProcType statusFramebufferTexture1D;
    NOpenGLProc::TFramebufferTexture2D glFramebufferTexture2D; NOpenGLProc::EProcType statusFramebufferTexture2D;
    NOpenGLProc::TFramebufferTexture3D glFramebufferTexture3D; NOpenGLProc::EProcType statusFramebufferTexture3D;
    NOpenGLProc::TFramebufferTextureLayer glFramebufferTextureLayer; NOpenGLProc::EProcType statusFramebufferTextureLayer;
    NOpenGLProc::TGenFramebuffers glGenFramebuffers; NOpenGLProc::EProcType statusGenFramebuffers;
    NOpenGLProc::TGenRenderbuffers glGenRenderbuffers; NOpenGLProc::EProcType statusGenRenderbuffers;
    NOpenGLProc::TGenVertexArrays glGenVertexArrays; NOpenGLProc::EProcType statusGenVertexArrays;
    NOpenGLProc::TGenerateMipmap glGenerateMipmap; NOpenGLProc::EProcType statusGenerateMipmap;
    NOpenGLProc::TGetBooleani_v glGetBooleani_v; NOpenGLProc::EProcType statusGetBooleani_v;
    NOpenGLProc::TGetFragDataLocation glGetFragDataLocation; NOpenGLProc::EProcType statusGetFragDataLocation;
    NOpenGLProc::TGetFramebufferAttachmentParameteriv glGetFramebufferAttachmentParameteriv; NOpenGLProc::EProcType statusGetFramebufferAttachmentParameteriv;
    NOpenGLProc::TGetIntegeri_v glGetIntegeri_v; NOpenGLProc::EProcType statusGetIntegeri_v;
    NOpenGLProc::TGetRenderbufferParameteriv glGetRenderbufferParameteriv; NOpenGLProc::EProcType statusGetRenderbufferParameteriv;
    NOpenGLProc::TGetStringi glGetStringi; NOpenGLProc::EProcType statusGetStringi;
    NOpenGLProc::TGetTexParameterIiv glGetTexParameterIiv; NOpenGLProc::EProcType statusGetTexParameterIiv;
    NOpenGLProc::TGetTexParameterIuiv glGetTexParameterIuiv; NOpenGLProc::EProcType statusGetTexParameterIuiv;
    NOpenGLProc::TGetTransformFeedbackVarying glGetTransformFeedbackVarying; NOpenGLProc::EProcType statusGetTransformFeedbackVarying;
    NOpenGLProc::TGetUniformuiv glGetUniformuiv; NOpenGLProc::EProcType statusGetUniformuiv;
    NOpenGLProc::TGetVertexAttribIiv glGetVertexAttribIiv; NOpenGLProc::EProcType statusGetVertexAttribIiv;
    NOpenGLProc::TGetVertexAttribIuiv glGetVertexAttribIuiv; NOpenGLProc::EProcType statusGetVertexAttribIuiv;
    NOpenGLProc::TIsEnabledi glIsEnabledi; NOpenGLProc::EProcType statusIsEnabledi;
    NOpenGLProc::TIsFramebuffer glIsFramebuffer; NOpenGLProc::EProcType statusIsFramebuffer;
    NOpenGLProc::TIsRenderbuffer glIsRenderbuffer; NOpenGLProc::EProcType statusIsRenderbuffer;
    NOpenGLProc::TIsVertexArray glIsVertexArray; NOpenGLProc::EProcType statusIsVertexArray;
    NOpenGLProc::TMapBufferRange glMapBufferRange; NOpenGLProc::EProcType statusMapBufferRange;
    NOpenGLProc::TRenderbufferStorage glRenderbufferStorage; NOpenGLProc::EProcType statusRenderbufferStorage;
    NOpenGLProc::TRenderbufferStorageMultisample glRenderbufferStorageMultisample; NOpenGLProc::EProcType statusRenderbufferStorageMultisample;
    NOpenGLProc::TTexParameterIiv glTexParameterIiv; NOpenGLProc::EProcType statusTexParameterIiv;
    NOpenGLProc::TTexParameterIuiv glTexParameterIuiv; NOpenGLProc::EProcType statusTexParameterIuiv;
    NOpenGLProc::TTransformFeedbackVaryings glTransformFeedbackVaryings; NOpenGLProc::EProcType statusTransformFeedbackVaryings;
    NOpenGLProc::TUniform1ui glUniform1ui; NOpenGLProc::EProcType statusUniform1ui;
    NOpenGLProc::TUniform1uiv glUniform1uiv; NOpenGLProc::EProcType statusUniform1uiv;
    NOpenGLProc::TUniform2ui glUniform2ui; NOpenGLProc::EProcType statusUniform2ui;
    NOpenGLProc::TUniform2uiv glUniform2uiv; NOpenGLProc::EProcType statusUniform2uiv;
    NOpenGLProc::TUniform3ui glUniform3ui; NOpenGLProc::EProcType statusUniform3ui;
    NOpenGLProc::TUniform3uiv glUniform3uiv; NOpenGLProc::EProcType statusUniform3uiv;
    NOpenGLProc::TUniform4ui glUniform4ui; NOpenGLProc::EProcType statusUniform4ui;
    NOpenGLProc::TUniform4uiv glUniform4uiv; NOpenGLProc::EProcType statusUniform4uiv;
    NOpenGLProc::TVertexAttribI1i glVertexAttribI1i; NOpenGLProc::EProcType statusVertexAttribI1i;
    NOpenGLProc::TVertexAttribI1iv glVertexAttribI1iv; NOpenGLProc::EProcType statusVertexAttribI1iv;
    NOpenGLProc::TVertexAttribI1ui glVertexAttribI1ui; NOpenGLProc::EProcType statusVertexAttribI1ui;
    NOpenGLProc::TVertexAttribI1uiv glVertexAttribI1uiv; NOpenGLProc::EProcType statusVertexAttribI1uiv;
    NOpenGLProc::TVertexAttribI2i glVertexAttribI2i; NOpenGLProc::EProcType statusVertexAttribI2i;
    NOpenGLProc::TVertexAttribI2iv glVertexAttribI2iv; NOpenGLProc::EProcType statusVertexAttribI2iv;
    NOpenGLProc::TVertexAttribI2ui glVertexAttribI2ui; NOpenGLProc::EProcType statusVertexAttribI2ui;
    NOpenGLProc::TVertexAttribI2uiv glVertexAttribI2uiv; NOpenGLProc::EProcType statusVertexAttribI2uiv;
    NOpenGLProc::TVertexAttribI3i glVertexAttribI3i; NOpenGLProc::EProcType statusVertexAttribI3i;
    NOpenGLProc::TVertexAttribI3iv glVertexAttribI3iv; NOpenGLProc::EProcType statusVertexAttribI3iv;
    NOpenGLProc::TVertexAttribI3ui glVertexAttribI3ui; NOpenGLProc::EProcType statusVertexAttribI3ui;
    NOpenGLProc::TVertexAttribI3uiv glVertexAttribI3uiv; NOpenGLProc::EProcType statusVertexAttribI3uiv;
    NOpenGLProc::TVertexAttribI4bv glVertexAttribI4bv; NOpenGLProc::EProcType statusVertexAttribI4bv;
    NOpenGLProc::TVertexAttribI4i glVertexAttribI4i; NOpenGLProc::EProcType statusVertexAttribI4i;
    NOpenGLProc::TVertexAttribI4iv glVertexAttribI4iv; NOpenGLProc::EProcType statusVertexAttribI4iv;
    NOpenGLProc::TVertexAttribI4sv glVertexAttribI4sv; NOpenGLProc::EProcType statusVertexAttribI4sv;
    NOpenGLProc::TVertexAttribI4ubv glVertexAttribI4ubv; NOpenGLProc::EProcType statusVertexAttribI4ubv;
    NOpenGLProc::TVertexAttribI4ui glVertexAttribI4ui; NOpenGLProc::EProcType statusVertexAttribI4ui;
    NOpenGLProc::TVertexAttribI4uiv glVertexAttribI4uiv; NOpenGLProc::EProcType statusVertexAttribI4uiv;
    NOpenGLProc::TVertexAttribI4usv glVertexAttribI4usv; NOpenGLProc::EProcType statusVertexAttribI4usv;
    NOpenGLProc::TVertexAttribIPointer glVertexAttribIPointer; NOpenGLProc::EProcType statusVertexAttribIPointer;

    // GL_VERSION_3_1
    NOpenGLProc::TCopyBufferSubData glCopyBufferSubData; NOpenGLProc::EProcType statusCopyBufferSubData;
    NOpenGLProc::TDrawArraysInstanced glDrawArraysInstanced; NOpenGLProc::EProcType statusDrawArraysInstanced;
    NOpenGLProc::TDrawElementsInstanced glDrawElementsInstanced; NOpenGLProc::EProcType statusDrawElementsInstanced;
    NOpenGLProc::TGetActiveUniformBlockName glGetActiveUniformBlockName; NOpenGLProc::EProcType statusGetActiveUniformBlockName;
    NOpenGLProc::TGetActiveUniformBlockiv glGetActiveUniformBlockiv; NOpenGLProc::EProcType statusGetActiveUniformBlockiv;
    NOpenGLProc::TGetActiveUniformName glGetActiveUniformName; NOpenGLProc::EProcType statusGetActiveUniformName;
    NOpenGLProc::TGetActiveUniformsiv glGetActiveUniformsiv; NOpenGLProc::EProcType statusGetActiveUniformsiv;
    NOpenGLProc::TGetUniformBlockIndex glGetUniformBlockIndex; NOpenGLProc::EProcType statusGetUniformBlockIndex;
    NOpenGLProc::TGetUniformIndices glGetUniformIndices; NOpenGLProc::EProcType statusGetUniformIndices;
    NOpenGLProc::TPrimitiveRestartIndex glPrimitiveRestartIndex; NOpenGLProc::EProcType statusPrimitiveRestartIndex;
    NOpenGLProc::TTexBuffer glTexBuffer; NOpenGLProc::EProcType statusTexBuffer;
    NOpenGLProc::TUniformBlockBinding glUniformBlockBinding; NOpenGLProc::EProcType statusUniformBlockBinding;

    // GL_VERSION_3_2
    NOpenGLProc::TClientWaitSync glClientWaitSync; NOpenGLProc::EProcType statusClientWaitSync;
    NOpenGLProc::TDeleteSync glDeleteSync; NOpenGLProc::EProcType statusDeleteSync;
    NOpenGLProc::TDrawElementsBaseVertex glDrawElementsBaseVertex; NOpenGLProc::EProcType statusDrawElementsBaseVertex;
    NOpenGLProc::TDrawElementsInstancedBaseVertex glDrawElementsInstancedBaseVertex; NOpenGLProc::EProcType statusDrawElementsInstancedBaseVertex;
    NOpenGLProc::TDrawRangeElementsBaseVertex glDrawRangeElementsBaseVertex; NOpenGLProc::EProcType statusDrawRangeElementsBaseVertex;
    NOpenGLProc::TFenceSync glFenceSync; NOpenGLProc::EProcType statusFenceSync;
    NOpenGLProc::TFramebufferTexture glFramebufferTexture; NOpenGLProc::EProcType statusFramebufferTexture;
    NOpenGLProc::TGetBufferParameteri64v glGetBufferParameteri64v; NOpenGLProc::EProcType statusGetBufferParameteri64v;
    NOpenGLProc::TGetInteger64i_v glGetInteger64i_v; NOpenGLProc::EProcType statusGetInteger64i_v;
    NOpenGLProc::TGetInteger64v glGetInteger64v; NOpenGLProc::EProcType statusGetInteger64v;
    NOpenGLProc::TGetMultisamplefv glGetMultisamplefv; NOpenGLProc::EProcType statusGetMultisamplefv;
    NOpenGLProc::TGetSynciv glGetSynciv; NOpenGLProc::EProcType statusGetSynciv;
    NOpenGLProc::TIsSync glIsSync; NOpenGLProc::EProcType statusIsSync;
    NOpenGLProc::TMultiDrawElementsBaseVertex glMultiDrawElementsBaseVertex; NOpenGLProc::EProcType statusMultiDrawElementsBaseVertex;
    NOpenGLProc::TProvokingVertex glProvokingVertex; NOpenGLProc::EProcType statusProvokingVertex;
    NOpenGLProc::TSampleMaski glSampleMaski; NOpenGLProc::EProcType statusSampleMaski;
    NOpenGLProc::TTexImage2DMultisample glTexImage2DMultisample; NOpenGLProc::EProcType statusTexImage2DMultisample;
    NOpenGLProc::TTexImage3DMultisample glTexImage3DMultisample; NOpenGLProc::EProcType statusTexImage3DMultisample;
    NOpenGLProc::TWaitSync glWaitSync; NOpenGLProc::EProcType statusWaitSync;

    // GL_VERSION_3_3
    NOpenGLProc::TBindFragDataLocationIndexed glBindFragDataLocationIndexed; NOpenGLProc::EProcType statusBindFragDataLocationIndexed;
    NOpenGLProc::TBindSampler glBindSampler; NOpenGLProc::EProcType statusBindSampler;
    NOpenGLProc::TDeleteSamplers glDeleteSamplers; NOpenGLProc::EProcType statusDeleteSamplers;
    NOpenGLProc::TGenSamplers glGenSamplers; NOpenGLProc::EProcType statusGenSamplers;
    NOpenGLProc::TGetFragDataIndex glGetFragDataIndex; NOpenGLProc::EProcType statusGetFragDataIndex;
    NOpenGLProc::TGetQueryObjecti64v glGetQueryObjecti64v; NOpenGLProc::EProcType statusGetQueryObjecti64v;
    NOpenGLProc::TGetQueryObjectui64v glGetQueryObjectui64v; NOpenGLProc::EProcType statusGetQueryObjectui64v;
    NOpenGLProc::TGetSamplerParameterIiv glGetSamplerParameterIiv; NOpenGLProc::EProcType statusGetSamplerParameterIiv;
    NOpenGLProc::TGetSamplerParameterIuiv glGetSamplerParameterIuiv; NOpenGLProc::EProcType statusGetSamplerParameterIuiv;
    NOpenGLProc::TGetSamplerParameterfv glGetSamplerParameterfv; NOpenGLProc::EProcType statusGetSamplerParameterfv;
    NOpenGLProc::TGetSamplerParameteriv glGetSamplerParameteriv; NOpenGLProc::EProcType statusGetSamplerParameteriv;
    NOpenGLProc::TIsSampler glIsSampler; NOpenGLProc::EProcType statusIsSampler;
    NOpenGLProc::TQueryCounter glQueryCounter; NOpenGLProc::EProcType statusQueryCounter;
    NOpenGLProc::TSamplerParameterIiv glSamplerParameterIiv; NOpenGLProc::EProcType statusSamplerParameterIiv;
    NOpenGLProc::TSamplerParameterIuiv glSamplerParameterIuiv; NOpenGLProc::EProcType statusSamplerParameterIuiv;
    NOpenGLProc::TSamplerParameterf glSamplerParameterf; NOpenGLProc::EProcType statusSamplerParameterf;
    NOpenGLProc::TSamplerParameterfv glSamplerParameterfv; NOpenGLProc::EProcType statusSamplerParameterfv;
    NOpenGLProc::TSamplerParameteri glSamplerParameteri; NOpenGLProc::EProcType statusSamplerParameteri;
    NOpenGLProc::TSamplerParameteriv glSamplerParameteriv; NOpenGLProc::EProcType statusSamplerParameteriv;
    NOpenGLProc::TVertexAttribDivisor glVertexAttribDivisor; NOpenGLProc::EProcType statusVertexAttribDivisor;
    NOpenGLProc::TVertexAttribP1ui glVertexAttribP1ui; NOpenGLProc::EProcType statusVertexAttribP1ui;
    NOpenGLProc::TVertexAttribP1uiv glVertexAttribP1uiv; NOpenGLProc::EProcType statusVertexAttribP1uiv;
    NOpenGLProc::TVertexAttribP2ui glVertexAttribP2ui; NOpenGLProc::EProcType statusVertexAttribP2ui;
    NOpenGLProc::TVertexAttribP2uiv glVertexAttribP2uiv; NOpenGLProc::EProcType statusVertexAttribP2uiv;
    NOpenGLProc::TVertexAttribP3ui glVertexAttribP3ui; NOpenGLProc::EProcType statusVertexAttribP3ui;
    NOpenGLProc::TVertexAttribP3uiv glVertexAttribP3uiv; NOpenGLProc::EProcType statusVertexAttribP3uiv;
    NOpenGLProc::TVertexAttribP4ui glVertexAttribP4ui; NOpenGLProc::EProcType statusVertexAttribP4ui;
    NOpenGLProc::TVertexAttribP4uiv glVertexAttribP4uiv; NOpenGLProc::EProcType statusVertexAttribP4uiv;

    // GL_VERSION_4_0
    NOpenGLProc::TBeginQueryIndexed glBeginQueryIndexed; NOpenGLProc::EProcType statusBeginQueryIndexed;
    NOpenGLProc::TBindTransformFeedback glBindTransformFeedback; NOpenGLProc::EProcType statusBindTransformFeedback;
    NOpenGLProc::TBlendEquationSeparatei glBlendEquationSeparatei; NOpenGLProc::EProcType statusBlendEquationSeparatei;
    NOpenGLProc::TBlendEquationi glBlendEquationi; NOpenGLProc::EProcType statusBlendEquationi;
    NOpenGLProc::TBlendFuncSeparatei glBlendFuncSeparatei; NOpenGLProc::EProcType statusBlendFuncSeparatei;
    NOpenGLProc::TBlendFunci glBlendFunci; NOpenGLProc::EProcType statusBlendFunci;
    NOpenGLProc::TDeleteTransformFeedbacks glDeleteTransformFeedbacks; NOpenGLProc::EProcType statusDeleteTransformFeedbacks;
    NOpenGLProc::TDrawArraysIndirect glDrawArraysIndirect; NOpenGLProc::EProcType statusDrawArraysIndirect;
    NOpenGLProc::TDrawElementsIndirect glDrawElementsIndirect; NOpenGLProc::EProcType statusDrawElementsIndirect;
    NOpenGLProc::TDrawTransformFeedback glDrawTransformFeedback; NOpenGLProc::EProcType statusDrawTransformFeedback;
    NOpenGLProc::TDrawTransformFeedbackStream glDrawTransformFeedbackStream; NOpenGLProc::EProcType statusDrawTransformFeedbackStream;
    NOpenGLProc::TEndQueryIndexed glEndQueryIndexed; NOpenGLProc::EProcType statusEndQueryIndexed;
    NOpenGLProc::TGenTransformFeedbacks glGenTransformFeedbacks; NOpenGLProc::EProcType statusGenTransformFeedbacks;
    NOpenGLProc::TGetActiveSubroutineName glGetActiveSubroutineName; NOpenGLProc::EProcType statusGetActiveSubroutineName;
    NOpenGLProc::TGetActiveSubroutineUniformName glGetActiveSubroutineUniformName; NOpenGLProc::EProcType statusGetActiveSubroutineUniformName;
    NOpenGLProc::TGetActiveSubroutineUniformiv glGetActiveSubroutineUniformiv; NOpenGLProc::EProcType statusGetActiveSubroutineUniformiv;
    NOpenGLProc::TGetProgramStageiv glGetProgramStageiv; NOpenGLProc::EProcType statusGetProgramStageiv;
    NOpenGLProc::TGetQueryIndexediv glGetQueryIndexediv; NOpenGLProc::EProcType statusGetQueryIndexediv;
    NOpenGLProc::TGetSubroutineIndex glGetSubroutineIndex; NOpenGLProc::EProcType statusGetSubroutineIndex;
    NOpenGLProc::TGetSubroutineUniformLocation glGetSubroutineUniformLocation; NOpenGLProc::EProcType statusGetSubroutineUniformLocation;
    NOpenGLProc::TGetUniformSubroutineuiv glGetUniformSubroutineuiv; NOpenGLProc::EProcType statusGetUniformSubroutineuiv;
    NOpenGLProc::TGetUniformdv glGetUniformdv; NOpenGLProc::EProcType statusGetUniformdv;
    NOpenGLProc::TIsTransformFeedback glIsTransformFeedback; NOpenGLProc::EProcType statusIsTransformFeedback;
    NOpenGLProc::TMinSampleShading glMinSampleShading; NOpenGLProc::EProcType statusMinSampleShading;
    NOpenGLProc::TPatchParameterfv glPatchParameterfv; NOpenGLProc::EProcType statusPatchParameterfv;
    NOpenGLProc::TPatchParameteri glPatchParameteri; NOpenGLProc::EProcType statusPatchParameteri;
    NOpenGLProc::TPauseTransformFeedback glPauseTransformFeedback; NOpenGLProc::EProcType statusPauseTransformFeedback;
    NOpenGLProc::TResumeTransformFeedback glResumeTransformFeedback; NOpenGLProc::EProcType statusResumeTransformFeedback;
    NOpenGLProc::TUniform1d glUniform1d; NOpenGLProc::EProcType statusUniform1d;
    NOpenGLProc::TUniform1dv glUniform1dv; NOpenGLProc::EProcType statusUniform1dv;
    NOpenGLProc::TUniform2d glUniform2d; NOpenGLProc::EProcType statusUniform2d;
    NOpenGLProc::TUniform2dv glUniform2dv; NOpenGLProc::EProcType statusUniform2dv;
    NOpenGLProc::TUniform3d glUniform3d; NOpenGLProc::EProcType statusUniform3d;
    NOpenGLProc::TUniform3dv glUniform3dv; NOpenGLProc::EProcType statusUniform3dv;
    NOpenGLProc::TUniform4d glUniform4d; NOpenGLProc::EProcType statusUniform4d;
    NOpenGLProc::TUniform4dv glUniform4dv; NOpenGLProc::EProcType statusUniform4dv;
    NOpenGLProc::TUniformMatrix2dv glUniformMatrix2dv; NOpenGLProc::EProcType statusUniformMatrix2dv;
    NOpenGLProc::TUniformMatrix2x3dv glUniformMatrix2x3dv; NOpenGLProc::EProcType statusUniformMatrix2x3dv;
    NOpenGLProc::TUniformMatrix2x4dv glUniformMatrix2x4dv; NOpenGLProc::EProcType statusUniformMatrix2x4dv;
    NOpenGLProc::TUniformMatrix3dv glUniformMatrix3dv; NOpenGLProc::EProcType statusUniformMatrix3dv;
    NOpenGLProc::TUniformMatrix3x2dv glUniformMatrix3x2dv; NOpenGLProc::EProcType statusUniformMatrix3x2dv;
    NOpenGLProc::TUniformMatrix3x4dv glUniformMatrix3x4dv; NOpenGLProc::EProcType statusUniformMatrix3x4dv;
    NOpenGLProc::TUniformMatrix4dv glUniformMatrix4dv; NOpenGLProc::EProcType statusUniformMatrix4dv;
    NOpenGLProc::TUniformMatrix4x2dv glUniformMatrix4x2dv; NOpenGLProc::EProcType statusUniformMatrix4x2dv;
    NOpenGLProc::TUniformMatrix4x3dv glUniformMatrix4x3dv; NOpenGLProc::EProcType statusUniformMatrix4x3dv;
    NOpenGLProc::TUniformSubroutinesuiv glUniformSubroutinesuiv; NOpenGLProc::EProcType statusUniformSubroutinesuiv;

    // GL_VERSION_4_1
    NOpenGLProc::TActiveShaderProgram glActiveShaderProgram; NOpenGLProc::EProcType statusActiveShaderProgram;
    NOpenGLProc::TBindProgramPipeline glBindProgramPipeline; NOpenGLProc::EProcType statusBindProgramPipeline;
    NOpenGLProc::TClearDepthf glClearDepthf; NOpenGLProc::EProcType statusClearDepthf;
    NOpenGLProc::TCreateShaderProgramv glCreateShaderProgramv; NOpenGLProc::EProcType statusCreateShaderProgramv;
    NOpenGLProc::TDeleteProgramPipelines glDeleteProgramPipelines; NOpenGLProc::EProcType statusDeleteProgramPipelines;
    NOpenGLProc::TDepthRangeArrayv glDepthRangeArrayv; NOpenGLProc::EProcType statusDepthRangeArrayv;
    NOpenGLProc::TDepthRangeIndexed glDepthRangeIndexed; NOpenGLProc::EProcType statusDepthRangeIndexed;
    NOpenGLProc::TDepthRangef glDepthRangef; NOpenGLProc::EProcType statusDepthRangef;
    NOpenGLProc::TGenProgramPipelines glGenProgramPipelines; NOpenGLProc::EProcType statusGenProgramPipelines;
    NOpenGLProc::TGetDoublei_v glGetDoublei_v; NOpenGLProc::EProcType statusGetDoublei_v;
    NOpenGLProc::TGetFloati_v glGetFloati_v; NOpenGLProc::EProcType statusGetFloati_v;
    NOpenGLProc::TGetProgramBinary glGetProgramBinary; NOpenGLProc::EProcType statusGetProgramBinary;
    NOpenGLProc::TGetProgramPipelineInfoLog glGetProgramPipelineInfoLog; NOpenGLProc::EProcType statusGetProgramPipelineInfoLog;
    NOpenGLProc::TGetProgramPipelineiv glGetProgramPipelineiv; NOpenGLProc::EProcType statusGetProgramPipelineiv;
    NOpenGLProc::TGetShaderPrecisionFormat glGetShaderPrecisionFormat; NOpenGLProc::EProcType statusGetShaderPrecisionFormat;
    NOpenGLProc::TGetVertexAttribLdv glGetVertexAttribLdv; NOpenGLProc::EProcType statusGetVertexAttribLdv;
    NOpenGLProc::TIsProgramPipeline glIsProgramPipeline; NOpenGLProc::EProcType statusIsProgramPipeline;
    NOpenGLProc::TProgramBinary glProgramBinary; NOpenGLProc::EProcType statusProgramBinary;
    NOpenGLProc::TProgramParameteri glProgramParameteri; NOpenGLProc::EProcType statusProgramParameteri;
    NOpenGLProc::TProgramUniform1d glProgramUniform1d; NOpenGLProc::EProcType statusProgramUniform1d;
    NOpenGLProc::TProgramUniform1dv glProgramUniform1dv; NOpenGLProc::EProcType statusProgramUniform1dv;
    NOpenGLProc::TProgramUniform1f glProgramUniform1f; NOpenGLProc::EProcType statusProgramUniform1f;
    NOpenGLProc::TProgramUniform1fv glProgramUniform1fv; NOpenGLProc::EProcType statusProgramUniform1fv;
    NOpenGLProc::TProgramUniform1i glProgramUniform1i; NOpenGLProc::EProcType statusProgramUniform1i;
    NOpenGLProc::TProgramUniform1iv glProgramUniform1iv; NOpenGLProc::EProcType statusProgramUniform1iv;
    NOpenGLProc::TProgramUniform1ui glProgramUniform1ui; NOpenGLProc::EProcType statusProgramUniform1ui;
    NOpenGLProc::TProgramUniform1uiv glProgramUniform1uiv; NOpenGLProc::EProcType statusProgramUniform1uiv;
    NOpenGLProc::TProgramUniform2d glProgramUniform2d; NOpenGLProc::EProcType statusProgramUniform2d;
    NOpenGLProc::TProgramUniform2dv glProgramUniform2dv; NOpenGLProc::EProcType statusProgramUniform2dv;
    NOpenGLProc::TProgramUniform2f glProgramUniform2f; NOpenGLProc::EProcType statusProgramUniform2f;
    NOpenGLProc::TProgramUniform2fv glProgramUniform2fv; NOpenGLProc::EProcType statusProgramUniform2fv;
    NOpenGLProc::TProgramUniform2i glProgramUniform2i; NOpenGLProc::EProcType statusProgramUniform2i;
    NOpenGLProc::TProgramUniform2iv glProgramUniform2iv; NOpenGLProc::EProcType statusProgramUniform2iv;
    NOpenGLProc::TProgramUniform2ui glProgramUniform2ui; NOpenGLProc::EProcType statusProgramUniform2ui;
    NOpenGLProc::TProgramUniform2uiv glProgramUniform2uiv; NOpenGLProc::EProcType statusProgramUniform2uiv;
    NOpenGLProc::TProgramUniform3d glProgramUniform3d; NOpenGLProc::EProcType statusProgramUniform3d;
    NOpenGLProc::TProgramUniform3dv glProgramUniform3dv; NOpenGLProc::EProcType statusProgramUniform3dv;
    NOpenGLProc::TProgramUniform3f glProgramUniform3f; NOpenGLProc::EProcType statusProgramUniform3f;
    NOpenGLProc::TProgramUniform3fv glProgramUniform3fv; NOpenGLProc::EProcType statusProgramUniform3fv;
    NOpenGLProc::TProgramUniform3i glProgramUniform3i; NOpenGLProc::EProcType statusProgramUniform3i;
    NOpenGLProc::TProgramUniform3iv glProgramUniform3iv; NOpenGLProc::EProcType statusProgramUniform3iv;
    NOpenGLProc::TProgramUniform3ui glProgramUniform3ui; NOpenGLProc::EProcType statusProgramUniform3ui;
    NOpenGLProc::TProgramUniform3uiv glProgramUniform3uiv; NOpenGLProc::EProcType statusProgramUniform3uiv;
    NOpenGLProc::TProgramUniform4d glProgramUniform4d; NOpenGLProc::EProcType statusProgramUniform4d;
    NOpenGLProc::TProgramUniform4dv glProgramUniform4dv; NOpenGLProc::EProcType statusProgramUniform4dv;
    NOpenGLProc::TProgramUniform4f glProgramUniform4f; NOpenGLProc::EProcType statusProgramUniform4f;
    NOpenGLProc::TProgramUniform4fv glProgramUniform4fv; NOpenGLProc::EProcType statusProgramUniform4fv;
    NOpenGLProc::TProgramUniform4i glProgramUniform4i; NOpenGLProc::EProcType statusProgramUniform4i;
    NOpenGLProc::TProgramUniform4iv glProgramUniform4iv; NOpenGLProc::EProcType statusProgramUniform4iv;
    NOpenGLProc::TProgramUniform4ui glProgramUniform4ui; NOpenGLProc::EProcType statusProgramUniform4ui;
    NOpenGLProc::TProgramUniform4uiv glProgramUniform4uiv; NOpenGLProc::EProcType statusProgramUniform4uiv;
    NOpenGLProc::TProgramUniformMatrix2dv glProgramUniformMatrix2dv; NOpenGLProc::EProcType statusProgramUniformMatrix2dv;
    NOpenGLProc::TProgramUniformMatrix2fv glProgramUniformMatrix2fv; NOpenGLProc::EProcType statusProgramUniformMatrix2fv;
    NOpenGLProc::TProgramUniformMatrix2x3dv glProgramUniformMatrix2x3dv; NOpenGLProc::EProcType statusProgramUniformMatrix2x3dv;
    NOpenGLProc::TProgramUniformMatrix2x3fv glProgramUniformMatrix2x3fv; NOpenGLProc::EProcType statusProgramUniformMatrix2x3fv;
    NOpenGLProc::TProgramUniformMatrix2x4dv glProgramUniformMatrix2x4dv; NOpenGLProc::EProcType statusProgramUniformMatrix2x4dv;
    NOpenGLProc::TProgramUniformMatrix2x4fv glProgramUniformMatrix2x4fv; NOpenGLProc::EProcType statusProgramUniformMatrix2x4fv;
    NOpenGLProc::TProgramUniformMatrix3dv glProgramUniformMatrix3dv; NOpenGLProc::EProcType statusProgramUniformMatrix3dv;
    NOpenGLProc::TProgramUniformMatrix3fv glProgramUniformMatrix3fv; NOpenGLProc::EProcType statusProgramUniformMatrix3fv;
    NOpenGLProc::TProgramUniformMatrix3x2dv glProgramUniformMatrix3x2dv; NOpenGLProc::EProcType statusProgramUniformMatrix3x2dv;
    NOpenGLProc::TProgramUniformMatrix3x2fv glProgramUniformMatrix3x2fv; NOpenGLProc::EProcType statusProgramUniformMatrix3x2fv;
    NOpenGLProc::TProgramUniformMatrix3x4dv glProgramUniformMatrix3x4dv; NOpenGLProc::EProcType statusProgramUniformMatrix3x4dv;
    NOpenGLProc::TProgramUniformMatrix3x4fv glProgramUniformMatrix3x4fv; NOpenGLProc::EProcType statusProgramUniformMatrix3x4fv;
    NOpenGLProc::TProgramUniformMatrix4dv glProgramUniformMatrix4dv; NOpenGLProc::EProcType statusProgramUniformMatrix4dv;
    NOpenGLProc::TProgramUniformMatrix4fv glProgramUniformMatrix4fv; NOpenGLProc::EProcType statusProgramUniformMatrix4fv;
    NOpenGLProc::TProgramUniformMatrix4x2dv glProgramUniformMatrix4x2dv; NOpenGLProc::EProcType statusProgramUniformMatrix4x2dv;
    NOpenGLProc::TProgramUniformMatrix4x2fv glProgramUniformMatrix4x2fv; NOpenGLProc::EProcType statusProgramUniformMatrix4x2fv;
    NOpenGLProc::TProgramUniformMatrix4x3dv glProgramUniformMatrix4x3dv; NOpenGLProc::EProcType statusProgramUniformMatrix4x3dv;
    NOpenGLProc::TProgramUniformMatrix4x3fv glProgramUniformMatrix4x3fv; NOpenGLProc::EProcType statusProgramUniformMatrix4x3fv;
    NOpenGLProc::TReleaseShaderCompiler glReleaseShaderCompiler; NOpenGLProc::EProcType statusReleaseShaderCompiler;
    NOpenGLProc::TScissorArrayv glScissorArrayv; NOpenGLProc::EProcType statusScissorArrayv;
    NOpenGLProc::TScissorIndexed glScissorIndexed; NOpenGLProc::EProcType statusScissorIndexed;
    NOpenGLProc::TScissorIndexedv glScissorIndexedv; NOpenGLProc::EProcType statusScissorIndexedv;
    NOpenGLProc::TShaderBinary glShaderBinary; NOpenGLProc::EProcType statusShaderBinary;
    NOpenGLProc::TUseProgramStages glUseProgramStages; NOpenGLProc::EProcType statusUseProgramStages;
    NOpenGLProc::TValidateProgramPipeline glValidateProgramPipeline; NOpenGLProc::EProcType statusValidateProgramPipeline;
    NOpenGLProc::TVertexAttribL1d glVertexAttribL1d; NOpenGLProc::EProcType statusVertexAttribL1d;
    NOpenGLProc::TVertexAttribL1dv glVertexAttribL1dv; NOpenGLProc::EProcType statusVertexAttribL1dv;
    NOpenGLProc::TVertexAttribL2d glVertexAttribL2d; NOpenGLProc::EProcType statusVertexAttribL2d;
    NOpenGLProc::TVertexAttribL2dv glVertexAttribL2dv; NOpenGLProc::EProcType statusVertexAttribL2dv;
    NOpenGLProc::TVertexAttribL3d glVertexAttribL3d; NOpenGLProc::EProcType statusVertexAttribL3d;
    NOpenGLProc::TVertexAttribL3dv glVertexAttribL3dv; NOpenGLProc::EProcType statusVertexAttribL3dv;
    NOpenGLProc::TVertexAttribL4d glVertexAttribL4d; NOpenGLProc::EProcType statusVertexAttribL4d;
    NOpenGLProc::TVertexAttribL4dv glVertexAttribL4dv; NOpenGLProc::EProcType statusVertexAttribL4dv;
    NOpenGLProc::TVertexAttribLPointer glVertexAttribLPointer; NOpenGLProc::EProcType statusVertexAttribLPointer;
    NOpenGLProc::TViewportArrayv glViewportArrayv; NOpenGLProc::EProcType statusViewportArrayv;
    NOpenGLProc::TViewportIndexedf glViewportIndexedf; NOpenGLProc::EProcType statusViewportIndexedf;
    NOpenGLProc::TViewportIndexedfv glViewportIndexedfv; NOpenGLProc::EProcType statusViewportIndexedfv;

    // GL_VERSION_4_2
    NOpenGLProc::TBindImageTexture glBindImageTexture; NOpenGLProc::EProcType statusBindImageTexture;
    NOpenGLProc::TDrawArraysInstancedBaseInstance glDrawArraysInstancedBaseInstance; NOpenGLProc::EProcType statusDrawArraysInstancedBaseInstance;
    NOpenGLProc::TDrawElementsInstancedBaseInstance glDrawElementsInstancedBaseInstance; NOpenGLProc::EProcType statusDrawElementsInstancedBaseInstance;
    NOpenGLProc::TDrawElementsInstancedBaseVertexBaseInstance glDrawElementsInstancedBaseVertexBaseInstance; NOpenGLProc::EProcType statusDrawElementsInstancedBaseVertexBaseInstance;
    NOpenGLProc::TDrawTransformFeedbackInstanced glDrawTransformFeedbackInstanced; NOpenGLProc::EProcType statusDrawTransformFeedbackInstanced;
    NOpenGLProc::TDrawTransformFeedbackStreamInstanced glDrawTransformFeedbackStreamInstanced; NOpenGLProc::EProcType statusDrawTransformFeedbackStreamInstanced;
    NOpenGLProc::TGetActiveAtomicCounterBufferiv glGetActiveAtomicCounterBufferiv; NOpenGLProc::EProcType statusGetActiveAtomicCounterBufferiv;
    NOpenGLProc::TGetInternalformativ glGetInternalformativ; NOpenGLProc::EProcType statusGetInternalformativ;
    NOpenGLProc::TMemoryBarrier glMemoryBarrier; NOpenGLProc::EProcType statusMemoryBarrier;
    NOpenGLProc::TTexStorage1D glTexStorage1D; NOpenGLProc::EProcType statusTexStorage1D;
    NOpenGLProc::TTexStorage2D glTexStorage2D; NOpenGLProc::EProcType statusTexStorage2D;
    NOpenGLProc::TTexStorage3D glTexStorage3D; NOpenGLProc::EProcType statusTexStorage3D;

    // GL_VERSION_4_3
    NOpenGLProc::TBindVertexBuffer glBindVertexBuffer; NOpenGLProc::EProcType statusBindVertexBuffer;
    NOpenGLProc::TClearBufferData glClearBufferData; NOpenGLProc::EProcType statusClearBufferData;
    NOpenGLProc::TClearBufferSubData glClearBufferSubData; NOpenGLProc::EProcType statusClearBufferSubData;
    NOpenGLProc::TCopyImageSubData glCopyImageSubData; NOpenGLProc::EProcType statusCopyImageSubData;
    NOpenGLProc::TDebugMessageCallback glDebugMessageCallback; NOpenGLProc::EProcType statusDebugMessageCallback;
    NOpenGLProc::TDebugMessageControl glDebugMessageControl; NOpenGLProc::EProcType statusDebugMessageControl;
    NOpenGLProc::TDebugMessageInsert glDebugMessageInsert; NOpenGLProc::EProcType statusDebugMessageInsert;
    NOpenGLProc::TDispatchCompute glDispatchCompute; NOpenGLProc::EProcType statusDispatchCompute;
    NOpenGLProc::TDispatchComputeIndirect glDispatchComputeIndirect; NOpenGLProc::EProcType statusDispatchComputeIndirect;
    NOpenGLProc::TFramebufferParameteri glFramebufferParameteri; NOpenGLProc::EProcType statusFramebufferParameteri;
    NOpenGLProc::TGetDebugMessageLog glGetDebugMessageLog; NOpenGLProc::EProcType statusGetDebugMessageLog;
    NOpenGLProc::TGetFramebufferParameteriv glGetFramebufferParameteriv; NOpenGLProc::EProcType statusGetFramebufferParameteriv;
    NOpenGLProc::TGetInternalformati64v glGetInternalformati64v; NOpenGLProc::EProcType statusGetInternalformati64v;
    NOpenGLProc::TGetObjectLabel glGetObjectLabel; NOpenGLProc::EProcType statusGetObjectLabel;
    NOpenGLProc::TGetObjectPtrLabel glGetObjectPtrLabel; NOpenGLProc::EProcType statusGetObjectPtrLabel;
    NOpenGLProc::TGetProgramInterfaceiv glGetProgramInterfaceiv; NOpenGLProc::EProcType statusGetProgramInterfaceiv;
    NOpenGLProc::TGetProgramResourceIndex glGetProgramResourceIndex; NOpenGLProc::EProcType statusGetProgramResourceIndex;
    NOpenGLProc::TGetProgramResourceLocation glGetProgramResourceLocation; NOpenGLProc::EProcType statusGetProgramResourceLocation;
    NOpenGLProc::TGetProgramResourceLocationIndex glGetProgramResourceLocationIndex; NOpenGLProc::EProcType statusGetProgramResourceLocationIndex;
    NOpenGLProc::TGetProgramResourceName glGetProgramResourceName; NOpenGLProc::EProcType statusGetProgramResourceName;
    NOpenGLProc::TGetProgramResourceiv glGetProgramResourceiv; NOpenGLProc::EProcType statusGetProgramResourceiv;
    NOpenGLProc::TInvalidateBufferData glInvalidateBufferData; NOpenGLProc::EProcType statusInvalidateBufferData;
    NOpenGLProc::TInvalidateBufferSubData glInvalidateBufferSubData; NOpenGLProc::EProcType statusInvalidateBufferSubData;
    NOpenGLProc::TInvalidateFramebuffer glInvalidateFramebuffer; NOpenGLProc::EProcType statusInvalidateFramebuffer;
    NOpenGLProc::TInvalidateSubFramebuffer glInvalidateSubFramebuffer; NOpenGLProc::EProcType statusInvalidateSubFramebuffer;
    NOpenGLProc::TInvalidateTexImage glInvalidateTexImage; NOpenGLProc::EProcType statusInvalidateTexImage;
    NOpenGLProc::TInvalidateTexSubImage glInvalidateTexSubImage; NOpenGLProc::EProcType statusInvalidateTexSubImage;
    NOpenGLProc::TMultiDrawArraysIndirect glMultiDrawArraysIndirect; NOpenGLProc::EProcType statusMultiDrawArraysIndirect;
    NOpenGLProc::TMultiDrawElementsIndirect glMultiDrawElementsIndirect; NOpenGLProc::EProcType statusMultiDrawElementsIndirect;
    NOpenGLProc::TObjectLabel glObjectLabel; NOpenGLProc::EProcType statusObjectLabel;
    NOpenGLProc::TObjectPtrLabel glObjectPtrLabel; NOpenGLProc::EProcType statusObjectPtrLabel;
    NOpenGLProc::TPopDebugGroup glPopDebugGroup; NOpenGLProc::EProcType statusPopDebugGroup;
    NOpenGLProc::TPushDebugGroup glPushDebugGroup; NOpenGLProc::EProcType statusPushDebugGroup;
    NOpenGLProc::TShaderStorageBlockBinding glShaderStorageBlockBinding; NOpenGLProc::EProcType statusShaderStorageBlockBinding;
    NOpenGLProc::TTexBufferRange glTexBufferRange; NOpenGLProc::EProcType statusTexBufferRange;
    NOpenGLProc::TTexStorage2DMultisample glTexStorage2DMultisample; NOpenGLProc::EProcType statusTexStorage2DMultisample;
    NOpenGLProc::TTexStorage3DMultisample glTexStorage3DMultisample; NOpenGLProc::EProcType statusTexStorage3DMultisample;
    NOpenGLProc::TTextureView glTextureView; NOpenGLProc::EProcType statusTextureView;
    NOpenGLProc::TVertexAttribBinding glVertexAttribBinding; NOpenGLProc::EProcType statusVertexAttribBinding;
    NOpenGLProc::TVertexAttribFormat glVertexAttribFormat; NOpenGLProc::EProcType statusVertexAttribFormat;
    NOpenGLProc::TVertexAttribIFormat glVertexAttribIFormat; NOpenGLProc::EProcType statusVertexAttribIFormat;
    NOpenGLProc::TVertexAttribLFormat glVertexAttribLFormat; NOpenGLProc::EProcType statusVertexAttribLFormat;
    NOpenGLProc::TVertexBindingDivisor glVertexBindingDivisor; NOpenGLProc::EProcType statusVertexBindingDivisor;

    // GL_VERSION_4_4
    NOpenGLProc::TBindBuffersBase glBindBuffersBase; NOpenGLProc::EProcType statusBindBuffersBase;
    NOpenGLProc::TBindBuffersRange glBindBuffersRange; NOpenGLProc::EProcType statusBindBuffersRange;
    NOpenGLProc::TBindImageTextures glBindImageTextures; NOpenGLProc::EProcType statusBindImageTextures;
    NOpenGLProc::TBindSamplers glBindSamplers; NOpenGLProc::EProcType statusBindSamplers;
    NOpenGLProc::TBindTextures glBindTextures; NOpenGLProc::EProcType statusBindTextures;
    NOpenGLProc::TBindVertexBuffers glBindVertexBuffers; NOpenGLProc::EProcType statusBindVertexBuffers;
    NOpenGLProc::TBufferStorage glBufferStorage; NOpenGLProc::EProcType statusBufferStorage;
    NOpenGLProc::TClearTexImage glClearTexImage; NOpenGLProc::EProcType statusClearTexImage;
    NOpenGLProc::TClearTexSubImage glClearTexSubImage; NOpenGLProc::EProcType statusClearTexSubImage;

    // GL_VERSION_4_5
    NOpenGLProc::TBindTextureUnit glBindTextureUnit; NOpenGLProc::EProcType statusBindTextureUnit;
    NOpenGLProc::TBlitNamedFramebuffer glBlitNamedFramebuffer; NOpenGLProc::EProcType statusBlitNamedFramebuffer;
    NOpenGLProc::TCheckNamedFramebufferStatus glCheckNamedFramebufferStatus; NOpenGLProc::EProcType statusCheckNamedFramebufferStatus;
    NOpenGLProc::TClearNamedBufferData glClearNamedBufferData; NOpenGLProc::EProcType statusClearNamedBufferData;
    NOpenGLProc::TClearNamedBufferSubData glClearNamedBufferSubData; NOpenGLProc::EProcType statusClearNamedBufferSubData;
    NOpenGLProc::TClearNamedFramebufferfi glClearNamedFramebufferfi; NOpenGLProc::EProcType statusClearNamedFramebufferfi;
    NOpenGLProc::TClearNamedFramebufferfv glClearNamedFramebufferfv; NOpenGLProc::EProcType statusClearNamedFramebufferfv;
    NOpenGLProc::TClearNamedFramebufferiv glClearNamedFramebufferiv; NOpenGLProc::EProcType statusClearNamedFramebufferiv;
    NOpenGLProc::TClearNamedFramebufferuiv glClearNamedFramebufferuiv; NOpenGLProc::EProcType statusClearNamedFramebufferuiv;
    NOpenGLProc::TClipControl glClipControl; NOpenGLProc::EProcType statusClipControl;
    NOpenGLProc::TCompressedTextureSubImage1D glCompressedTextureSubImage1D; NOpenGLProc::EProcType statusCompressedTextureSubImage1D;
    NOpenGLProc::TCompressedTextureSubImage2D glCompressedTextureSubImage2D; NOpenGLProc::EProcType statusCompressedTextureSubImage2D;
    NOpenGLProc::TCompressedTextureSubImage3D glCompressedTextureSubImage3D; NOpenGLProc::EProcType statusCompressedTextureSubImage3D;
    NOpenGLProc::TCopyNamedBufferSubData glCopyNamedBufferSubData; NOpenGLProc::EProcType statusCopyNamedBufferSubData;
    NOpenGLProc::TCopyTextureSubImage1D glCopyTextureSubImage1D; NOpenGLProc::EProcType statusCopyTextureSubImage1D;
    NOpenGLProc::TCopyTextureSubImage2D glCopyTextureSubImage2D; NOpenGLProc::EProcType statusCopyTextureSubImage2D;
    NOpenGLProc::TCopyTextureSubImage3D glCopyTextureSubImage3D; NOpenGLProc::EProcType statusCopyTextureSubImage3D;
    NOpenGLProc::TCreateBuffers glCreateBuffers; NOpenGLProc::EProcType statusCreateBuffers;
    NOpenGLProc::TCreateFramebuffers glCreateFramebuffers; NOpenGLProc::EProcType statusCreateFramebuffers;
    NOpenGLProc::TCreateProgramPipelines glCreateProgramPipelines; NOpenGLProc::EProcType statusCreateProgramPipelines;
    NOpenGLProc::TCreateQueries glCreateQueries; NOpenGLProc::EProcType statusCreateQueries;
    NOpenGLProc::TCreateRenderbuffers glCreateRenderbuffers; NOpenGLProc::EProcType statusCreateRenderbuffers;
    NOpenGLProc::TCreateSamplers glCreateSamplers; NOpenGLProc::EProcType statusCreateSamplers;
    NOpenGLProc::TCreateTextures glCreateTextures; NOpenGLProc::EProcType statusCreateTextures;
    NOpenGLProc::TCreateTransformFeedbacks glCreateTransformFeedbacks; NOpenGLProc::EProcType statusCreateTransformFeedbacks;
    NOpenGLProc::TCreateVertexArrays glCreateVertexArrays; NOpenGLProc::EProcType statusCreateVertexArrays;
    NOpenGLProc::TDisableVertexArrayAttrib glDisableVertexArrayAttrib; NOpenGLProc::EProcType statusDisableVertexArrayAttrib;
    NOpenGLProc::TEnableVertexArrayAttrib glEnableVertexArrayAttrib; NOpenGLProc::EProcType statusEnableVertexArrayAttrib;
    NOpenGLProc::TFlushMappedNamedBufferRange glFlushMappedNamedBufferRange; NOpenGLProc::EProcType statusFlushMappedNamedBufferRange;
    NOpenGLProc::TGenerateTextureMipmap glGenerateTextureMipmap; NOpenGLProc::EProcType statusGenerateTextureMipmap;
    NOpenGLProc::TGetCompressedTextureImage glGetCompressedTextureImage; NOpenGLProc::EProcType statusGetCompressedTextureImage;
    NOpenGLProc::TGetCompressedTextureSubImage glGetCompressedTextureSubImage; NOpenGLProc::EProcType statusGetCompressedTextureSubImage;
    NOpenGLProc::TGetGraphicsResetStatus glGetGraphicsResetStatus; NOpenGLProc::EProcType statusGetGraphicsResetStatus;
    NOpenGLProc::TGetNamedBufferParameteri64v glGetNamedBufferParameteri64v; NOpenGLProc::EProcType statusGetNamedBufferParameteri64v;
    NOpenGLProc::TGetNamedBufferParameteriv glGetNamedBufferParameteriv; NOpenGLProc::EProcType statusGetNamedBufferParameteriv;
    NOpenGLProc::TGetNamedBufferPointerv glGetNamedBufferPointerv; NOpenGLProc::EProcType statusGetNamedBufferPointerv;
    NOpenGLProc::TGetNamedBufferSubData glGetNamedBufferSubData; NOpenGLProc::EProcType statusGetNamedBufferSubData;
    NOpenGLProc::TGetNamedFramebufferAttachmentParameteriv glGetNamedFramebufferAttachmentParameteriv; NOpenGLProc::EProcType statusGetNamedFramebufferAttachmentParameteriv;
    NOpenGLProc::TGetNamedFramebufferParameteriv glGetNamedFramebufferParameteriv; NOpenGLProc::EProcType statusGetNamedFramebufferParameteriv;
    NOpenGLProc::TGetNamedRenderbufferParameteriv glGetNamedRenderbufferParameteriv; NOpenGLProc::EProcType statusGetNamedRenderbufferParameteriv;
    NOpenGLProc::TGetQueryBufferObjecti64v glGetQueryBufferObjecti64v; NOpenGLProc::EProcType statusGetQueryBufferObjecti64v;
    NOpenGLProc::TGetQueryBufferObjectiv glGetQueryBufferObjectiv; NOpenGLProc::EProcType statusGetQueryBufferObjectiv;
    NOpenGLProc::TGetQueryBufferObjectui64v glGetQueryBufferObjectui64v; NOpenGLProc::EProcType statusGetQueryBufferObjectui64v;
    NOpenGLProc::TGetQueryBufferObjectuiv glGetQueryBufferObjectuiv; NOpenGLProc::EProcType statusGetQueryBufferObjectuiv;
    NOpenGLProc::TGetTextureImage glGetTextureImage; NOpenGLProc::EProcType statusGetTextureImage;
    NOpenGLProc::TGetTextureLevelParameterfv glGetTextureLevelParameterfv; NOpenGLProc::EProcType statusGetTextureLevelParameterfv;
    NOpenGLProc::TGetTextureLevelParameteriv glGetTextureLevelParameteriv; NOpenGLProc::EProcType statusGetTextureLevelParameteriv;
    NOpenGLProc::TGetTextureParameterIiv glGetTextureParameterIiv; NOpenGLProc::EProcType statusGetTextureParameterIiv;
    NOpenGLProc::TGetTextureParameterIuiv glGetTextureParameterIuiv; NOpenGLProc::EProcType statusGetTextureParameterIuiv;
    NOpenGLProc::TGetTextureParameterfv glGetTextureParameterfv; NOpenGLProc::EProcType statusGetTextureParameterfv;
    NOpenGLProc::TGetTextureParameteriv glGetTextureParameteriv; NOpenGLProc::EProcType statusGetTextureParameteriv;
    NOpenGLProc::TGetTextureSubImage glGetTextureSubImage; NOpenGLProc::EProcType statusGetTextureSubImage;
    NOpenGLProc::TGetTransformFeedbacki64_v glGetTransformFeedbacki64_v; NOpenGLProc::EProcType statusGetTransformFeedbacki64_v;
    NOpenGLProc::TGetTransformFeedbacki_v glGetTransformFeedbacki_v; NOpenGLProc::EProcType statusGetTransformFeedbacki_v;
    NOpenGLProc::TGetTransformFeedbackiv glGetTransformFeedbackiv; NOpenGLProc::EProcType statusGetTransformFeedbackiv;
    NOpenGLProc::TGetVertexArrayIndexed64iv glGetVertexArrayIndexed64iv; NOpenGLProc::EProcType statusGetVertexArrayIndexed64iv;
    NOpenGLProc::TGetVertexArrayIndexediv glGetVertexArrayIndexediv; NOpenGLProc::EProcType statusGetVertexArrayIndexediv;
    NOpenGLProc::TGetVertexArrayiv glGetVertexArrayiv; NOpenGLProc::EProcType statusGetVertexArrayiv;
    NOpenGLProc::TGetnCompressedTexImage glGetnCompressedTexImage; NOpenGLProc::EProcType statusGetnCompressedTexImage;
    NOpenGLProc::TGetnTexImage glGetnTexImage; NOpenGLProc::EProcType statusGetnTexImage;
    NOpenGLProc::TGetnUniformdv glGetnUniformdv; NOpenGLProc::EProcType statusGetnUniformdv;
    NOpenGLProc::TGetnUniformfv glGetnUniformfv; NOpenGLProc::EProcType statusGetnUniformfv;
    NOpenGLProc::TGetnUniformiv glGetnUniformiv; NOpenGLProc::EProcType statusGetnUniformiv;
    NOpenGLProc::TGetnUniformuiv glGetnUniformuiv; NOpenGLProc::EProcType statusGetnUniformuiv;
    NOpenGLProc::TInvalidateNamedFramebufferData glInvalidateNamedFramebufferData; NOpenGLProc::EProcType statusInvalidateNamedFramebufferData;
    NOpenGLProc::TInvalidateNamedFramebufferSubData glInvalidateNamedFramebufferSubData; NOpenGLProc::EProcType statusInvalidateNamedFramebufferSubData;
    NOpenGLProc::TMapNamedBuffer glMapNamedBuffer; NOpenGLProc::EProcType statusMapNamedBuffer;
    NOpenGLProc::TMapNamedBufferRange glMapNamedBufferRange; NOpenGLProc::EProcType statusMapNamedBufferRange;
    NOpenGLProc::TMemoryBarrierByRegion glMemoryBarrierByRegion; NOpenGLProc::EProcType statusMemoryBarrierByRegion;
    NOpenGLProc::TNamedBufferData glNamedBufferData; NOpenGLProc::EProcType statusNamedBufferData;
    NOpenGLProc::TNamedBufferStorage glNamedBufferStorage; NOpenGLProc::EProcType statusNamedBufferStorage;
    NOpenGLProc::TNamedBufferSubData glNamedBufferSubData; NOpenGLProc::EProcType statusNamedBufferSubData;
    NOpenGLProc::TNamedFramebufferDrawBuffer glNamedFramebufferDrawBuffer; NOpenGLProc::EProcType statusNamedFramebufferDrawBuffer;
    NOpenGLProc::TNamedFramebufferDrawBuffers glNamedFramebufferDrawBuffers; NOpenGLProc::EProcType statusNamedFramebufferDrawBuffers;
    NOpenGLProc::TNamedFramebufferParameteri glNamedFramebufferParameteri; NOpenGLProc::EProcType statusNamedFramebufferParameteri;
    NOpenGLProc::TNamedFramebufferReadBuffer glNamedFramebufferReadBuffer; NOpenGLProc::EProcType statusNamedFramebufferReadBuffer;
    NOpenGLProc::TNamedFramebufferRenderbuffer glNamedFramebufferRenderbuffer; NOpenGLProc::EProcType statusNamedFramebufferRenderbuffer;
    NOpenGLProc::TNamedFramebufferTexture glNamedFramebufferTexture; NOpenGLProc::EProcType statusNamedFramebufferTexture;
    NOpenGLProc::TNamedFramebufferTextureLayer glNamedFramebufferTextureLayer; NOpenGLProc::EProcType statusNamedFramebufferTextureLayer;
    NOpenGLProc::TNamedRenderbufferStorage glNamedRenderbufferStorage; NOpenGLProc::EProcType statusNamedRenderbufferStorage;
    NOpenGLProc::TNamedRenderbufferStorageMultisample glNamedRenderbufferStorageMultisample; NOpenGLProc::EProcType statusNamedRenderbufferStorageMultisample;
    NOpenGLProc::TReadnPixels glReadnPixels; NOpenGLProc::EProcType statusReadnPixels;
    NOpenGLProc::TTextureBarrier glTextureBarrier; NOpenGLProc::EProcType statusTextureBarrier;
    NOpenGLProc::TTextureBuffer glTextureBuffer; NOpenGLProc::EProcType statusTextureBuffer;
    NOpenGLProc::TTextureBufferRange glTextureBufferRange; NOpenGLProc::EProcType statusTextureBufferRange;
    NOpenGLProc::TTextureParameterIiv glTextureParameterIiv; NOpenGLProc::EProcType statusTextureParameterIiv;
    NOpenGLProc::TTextureParameterIuiv glTextureParameterIuiv; NOpenGLProc::EProcType statusTextureParameterIuiv;
    NOpenGLProc::TTextureParameterf glTextureParameterf; NOpenGLProc::EProcType statusTextureParameterf;
    NOpenGLProc::TTextureParameterfv glTextureParameterfv; NOpenGLProc::EProcType statusTextureParameterfv;
    NOpenGLProc::TTextureParameteri glTextureParameteri; NOpenGLProc::EProcType statusTextureParameteri;
    NOpenGLProc::TTextureParameteriv glTextureParameteriv; NOpenGLProc::EProcType statusTextureParameteriv;
    NOpenGLProc::TTextureStorage1D glTextureStorage1D; NOpenGLProc::EProcType statusTextureStorage1D;
    NOpenGLProc::TTextureStorage2D glTextureStorage2D; NOpenGLProc::EProcType statusTextureStorage2D;
    NOpenGLProc::TTextureStorage2DMultisample glTextureStorage2DMultisample; NOpenGLProc::EProcType statusTextureStorage2DMultisample;
    NOpenGLProc::TTextureStorage3D glTextureStorage3D; NOpenGLProc::EProcType statusTextureStorage3D;
    NOpenGLProc::TTextureStorage3DMultisample glTextureStorage3DMultisample; NOpenGLProc::EProcType statusTextureStorage3DMultisample;
    NOpenGLProc::TTextureSubImage1D glTextureSubImage1D; NOpenGLProc::EProcType statusTextureSubImage1D;
    NOpenGLProc::TTextureSubImage2D glTextureSubImage2D; NOpenGLProc::EProcType statusTextureSubImage2D;
    NOpenGLProc::TTextureSubImage3D glTextureSubImage3D; NOpenGLProc::EProcType statusTextureSubImage3D;
    NOpenGLProc::TTransformFeedbackBufferBase glTransformFeedbackBufferBase; NOpenGLProc::EProcType statusTransformFeedbackBufferBase;
    NOpenGLProc::TTransformFeedbackBufferRange glTransformFeedbackBufferRange; NOpenGLProc::EProcType statusTransformFeedbackBufferRange;
    NOpenGLProc::TUnmapNamedBuffer glUnmapNamedBuffer; NOpenGLProc::EProcType statusUnmapNamedBuffer;
    NOpenGLProc::TVertexArrayAttribBinding glVertexArrayAttribBinding; NOpenGLProc::EProcType statusVertexArrayAttribBinding;
    NOpenGLProc::TVertexArrayAttribFormat glVertexArrayAttribFormat; NOpenGLProc::EProcType statusVertexArrayAttribFormat;
    NOpenGLProc::TVertexArrayAttribIFormat glVertexArrayAttribIFormat; NOpenGLProc::EProcType statusVertexArrayAttribIFormat;
    NOpenGLProc::TVertexArrayAttribLFormat glVertexArrayAttribLFormat; NOpenGLProc::EProcType statusVertexArrayAttribLFormat;
    NOpenGLProc::TVertexArrayBindingDivisor glVertexArrayBindingDivisor; NOpenGLProc::EProcType statusVertexArrayBindingDivisor;
    NOpenGLProc::TVertexArrayElementBuffer glVertexArrayElementBuffer; NOpenGLProc::EProcType statusVertexArrayElementBuffer;
    NOpenGLProc::TVertexArrayVertexBuffer glVertexArrayVertexBuffer; NOpenGLProc::EProcType statusVertexArrayVertexBuffer;
    NOpenGLProc::TVertexArrayVertexBuffers glVertexArrayVertexBuffers; NOpenGLProc::EProcType statusVertexArrayVertexBuffers;

  public:
    COpenGL(CContext *context = NULL);
    ~COpenGL();
    void initializeGLFunctions(NEngine::EGPUPlatform explicitPlatofrm = NEngine::GPU_PLATFORM_KEEP);
    void makeCurrent();
    std::string getStatus() const;

    // GL_VERSION_1_0
    inline void blendFunc(GLenum sfactor, GLenum dfactor) { glBlendFunc(sfactor, dfactor); }
    inline void clear(GLbitfield mask) { glClear(mask); }
    inline void clearColor(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha) { glClearColor(red, green, blue, alpha); }
    inline void clearDepth(GLdouble depth) { glClearDepth(depth); }
    inline void clearStencil(GLint s) { glClearStencil(s); }
    inline void colorMask(GLboolean red, GLboolean green, GLboolean blue, GLboolean alpha) { glColorMask(red, green, blue, alpha); }
    inline void cullFace(GLenum mode) { glCullFace(mode); }
    inline void depthFunc(GLenum func) { glDepthFunc(func); }
    inline void depthMask(GLboolean flag) { glDepthMask(flag); }
    inline void depthRange(GLdouble rnear, GLdouble rfar) { glDepthRange(rnear, rfar); }
    inline void disable(GLenum cap) { glDisable(cap); }
    inline void drawBuffer(GLenum buf) { glDrawBuffer(buf); }
    inline void enable(GLenum cap) { glEnable(cap); }
    inline void finish(void) { glFinish(); }
    inline void flush(void) { glFlush(); }
    inline void frontFace(GLenum mode) { glFrontFace(mode); }
    inline void getBooleanv(GLenum pname, GLboolean *data) { glGetBooleanv(pname, data); }
    inline void getDoublev(GLenum pname, GLdouble *data) { glGetDoublev(pname, data); }
    inline GLenum getError(void) { return glGetError(); }
    inline void getFloatv(GLenum pname, GLfloat *data) { glGetFloatv(pname, data); }
    inline void getIntegerv(GLenum pname, GLint *data) { glGetIntegerv(pname, data); }
    inline const GLubyte *getString(GLenum name) { return glGetString(name); }
    inline void getTexImage(GLenum target, GLint level, GLenum format, GLenum type, void *pixels) { glGetTexImage(target, level, format, type, pixels); }
    inline void getTexLevelParameterfv(GLenum target, GLint level, GLenum pname, GLfloat *params) { glGetTexLevelParameterfv(target, level, pname, params); }
    inline void getTexLevelParameteriv(GLenum target, GLint level, GLenum pname, GLint *params) { glGetTexLevelParameteriv(target, level, pname, params); }
    inline void getTexParameterfv(GLenum target, GLenum pname, GLfloat *params) { glGetTexParameterfv(target, pname, params); }
    inline void getTexParameteriv(GLenum target, GLenum pname, GLint *params) { glGetTexParameteriv(target, pname, params); }
    inline void hint(GLenum target, GLenum mode) { glHint(target, mode); }
    inline GLboolean isEnabled(GLenum cap) { return glIsEnabled(cap); }
    inline void lineWidth(GLfloat width) { glLineWidth(width); }
    inline void logicOp(GLenum opcode) { glLogicOp(opcode); }
    inline void pixelStoref(GLenum pname, GLfloat param) { glPixelStoref(pname, param); }
    inline void pixelStorei(GLenum pname, GLint param) { glPixelStorei(pname, param); }
    inline void pointSize(GLfloat size) { glPointSize(size); }
    inline void polygonMode(GLenum face, GLenum mode) { glPolygonMode(face, mode); }
    inline void readBuffer(GLenum src) { glReadBuffer(src); }
    inline void readPixels(GLint x, GLint y, GLsizei width, GLsizei height, GLenum format, GLenum type, void *pixels) { glReadPixels(x, y, width, height, format, type, pixels); }
    inline void scissor(GLint x, GLint y, GLsizei width, GLsizei height) { glScissor(x, y, width, height); }
    inline void stencilFunc(GLenum func, GLint ref, GLuint mask) { glStencilFunc(func, ref, mask); }
    inline void stencilMask(GLuint mask) { glStencilMask(mask); }
    inline void stencilOp(GLenum fail, GLenum zfail, GLenum zpass) { glStencilOp(fail, zfail, zpass); }
    inline void texImage1D(GLenum target, GLint level, GLint internalformat, GLsizei width, GLint border, GLenum format, GLenum type, const void *pixels) { glTexImage1D(target, level, internalformat, width, border, format, type, pixels); }
    inline void texImage2D(GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLint border, GLenum format, GLenum type, const void *pixels) { glTexImage2D(target, level, internalformat, width, height, border, format, type, pixels); }
    inline void texParameterf(GLenum target, GLenum pname, GLfloat param) { glTexParameterf(target, pname, param); }
    inline void texParameterfv(GLenum target, GLenum pname, const GLfloat *params) { glTexParameterfv(target, pname, params); }
    inline void texParameteri(GLenum target, GLenum pname, GLint param) { glTexParameteri(target, pname, param); }
    inline void texParameteriv(GLenum target, GLenum pname, const GLint *params) { glTexParameteriv(target, pname, params); }
    inline void viewport(GLint x, GLint y, GLsizei width, GLsizei height) { glViewport(x, y, width, height); }

    // GL_VERSION_1_1
    inline void bindTexture(GLenum target, GLuint texture) { glBindTexture(target, texture); }
    inline void copyTexImage1D(GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLint border) { glCopyTexImage1D(target, level, internalformat, x, y, width, border); }
    inline void copyTexImage2D(GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLsizei height, GLint border) { glCopyTexImage2D(target, level, internalformat, x, y, width, height, border); }
    inline void copyTexSubImage1D(GLenum target, GLint level, GLint xoffset, GLint x, GLint y, GLsizei width) { glCopyTexSubImage1D(target, level, xoffset, x, y, width); }
    inline void copyTexSubImage2D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint x, GLint y, GLsizei width, GLsizei height) { glCopyTexSubImage2D(target, level, xoffset, yoffset, x, y, width, height); }
    inline void deleteTextures(GLsizei n, const GLuint *textures) { glDeleteTextures(n, textures); }
    inline void drawArrays(GLenum mode, GLint first, GLsizei count) { glDrawArrays(mode, first, count); }
    inline void drawElements(GLenum mode, GLsizei count, GLenum type, const void *indices) { glDrawElements(mode, count, type, indices); }
    inline void genTextures(GLsizei n, GLuint *textures) { glGenTextures(n, textures); }
    inline void getPointerv(GLenum pname, void **params) { glGetPointerv(pname, params); }
    inline GLboolean isTexture(GLuint texture) { return glIsTexture(texture); }
    inline void polygonOffset(GLfloat factor, GLfloat units) { glPolygonOffset(factor, units); }
    inline void texSubImage1D(GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLenum type, const void *pixels) { glTexSubImage1D(target, level, xoffset, width, format, type, pixels); }
    inline void texSubImage2D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLenum type, const void *pixels) { glTexSubImage2D(target, level, xoffset, yoffset, width, height, format, type, pixels); }

    // GL_VERSION_1_2
    inline void copyTexSubImage3D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLint x, GLint y, GLsizei width, GLsizei height) { glCopyTexSubImage3D(target, level, xoffset, yoffset, zoffset, x, y, width, height); }
    inline void drawRangeElements(GLenum mode, GLuint start, GLuint end, GLsizei count, GLenum type, const void *indices) { glDrawRangeElements(mode, start, end, count, type, indices); }
    inline void texImage3D(GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLenum format, GLenum type, const void *pixels) { glTexImage3D(target, level, internalformat, width, height, depth, border, format, type, pixels); }
    inline void texSubImage3D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const void *pixels) { glTexSubImage3D(target, level, xoffset, yoffset, zoffset, width, height, depth, format, type, pixels); }

    // GL_VERSION_1_3
    inline void activeTexture(GLenum texture) { glActiveTexture(texture); }
    inline void compressedTexImage1D(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLint border, GLsizei imageSize, const void *data) { glCompressedTexImage1D(target, level, internalformat, width, border, imageSize, data); }
    inline void compressedTexImage2D(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLint border, GLsizei imageSize, const void *data) { glCompressedTexImage2D(target, level, internalformat, width, height, border, imageSize, data); }
    inline void compressedTexImage3D(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLsizei imageSize, const void *data) { glCompressedTexImage3D(target, level, internalformat, width, height, depth, border, imageSize, data); }
    inline void compressedTexSubImage1D(GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLsizei imageSize, const void *data) { glCompressedTexSubImage1D(target, level, xoffset, width, format, imageSize, data); }
    inline void compressedTexSubImage2D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLsizei imageSize, const void *data) { glCompressedTexSubImage2D(target, level, xoffset, yoffset, width, height, format, imageSize, data); }
    inline void compressedTexSubImage3D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLsizei imageSize, const void *data) { glCompressedTexSubImage3D(target, level, xoffset, yoffset, zoffset, width, height, depth, format, imageSize, data); }
    inline void getCompressedTexImage(GLenum target, GLint level, void *img) { glGetCompressedTexImage(target, level, img); }
    inline void sampleCoverage(GLfloat value, GLboolean invert) { glSampleCoverage(value, invert); }

    // GL_VERSION_1_4
    inline void blendColor(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha) { glBlendColor(red, green, blue, alpha); }
    inline void blendEquation(GLenum mode) { glBlendEquation(mode); }
    inline void blendFuncSeparate(GLenum sfactorRGB, GLenum dfactorRGB, GLenum sfactorAlpha, GLenum dfactorAlpha) { glBlendFuncSeparate(sfactorRGB, dfactorRGB, sfactorAlpha, dfactorAlpha); }
    inline void multiDrawArrays(GLenum mode, const GLint *first, const GLsizei *count, GLsizei drawcount) { glMultiDrawArrays(mode, first, count, drawcount); }
    inline void multiDrawElements(GLenum mode, const GLsizei *count, GLenum type, const void *const*indices, GLsizei drawcount) { glMultiDrawElements(mode, count, type, indices, drawcount); }
    inline void pointParameterf(GLenum pname, GLfloat param) { glPointParameterf(pname, param); }
    inline void pointParameterfv(GLenum pname, const GLfloat *params) { glPointParameterfv(pname, params); }
    inline void pointParameteri(GLenum pname, GLint param) { glPointParameteri(pname, param); }
    inline void pointParameteriv(GLenum pname, const GLint *params) { glPointParameteriv(pname, params); }

    // GL_VERSION_1_5
    inline void beginQuery(GLenum target, GLuint id) { glBeginQuery(target, id); }
    inline void bindBuffer(GLenum target, GLuint buffer) { glBindBuffer(target, buffer); }
    inline void bufferData(GLenum target, GLsizeiptr size, const void *data, GLenum usage) { glBufferData(target, size, data, usage); }
    inline void bufferSubData(GLenum target, GLintptr offset, GLsizeiptr size, const void *data) { glBufferSubData(target, offset, size, data); }
    inline void deleteBuffers(GLsizei n, const GLuint *buffers) { glDeleteBuffers(n, buffers); }
    inline void deleteQueries(GLsizei n, const GLuint *ids) { glDeleteQueries(n, ids); }
    inline void endQuery(GLenum target) { glEndQuery(target); }
    inline void genBuffers(GLsizei n, GLuint *buffers) { glGenBuffers(n, buffers); }
    inline void genQueries(GLsizei n, GLuint *ids) { glGenQueries(n, ids); }
    inline void getBufferParameteriv(GLenum target, GLenum pname, GLint *params) { glGetBufferParameteriv(target, pname, params); }
    inline void getBufferPointerv(GLenum target, GLenum pname, void **params) { glGetBufferPointerv(target, pname, params); }
    inline void getBufferSubData(GLenum target, GLintptr offset, GLsizeiptr size, void *data) { glGetBufferSubData(target, offset, size, data); }
    inline void getQueryObjectiv(GLuint id, GLenum pname, GLint *params) { glGetQueryObjectiv(id, pname, params); }
    inline void getQueryObjectuiv(GLuint id, GLenum pname, GLuint *params) { glGetQueryObjectuiv(id, pname, params); }
    inline void getQueryiv(GLenum target, GLenum pname, GLint *params) { glGetQueryiv(target, pname, params); }
    inline GLboolean isBuffer(GLuint buffer) { return glIsBuffer(buffer); }
    inline GLboolean isQuery(GLuint id) { return glIsQuery(id); }
    inline void *mapBuffer(GLenum target, GLenum access) { return glMapBuffer(target, access); }
    inline GLboolean unmapBuffer(GLenum target) { return glUnmapBuffer(target); }

    // GL_VERSION_2_0
    inline void attachShader(GLuint program, GLuint shader) { glAttachShader(program, shader); }
    inline void bindAttribLocation(GLuint program, GLuint index, const GLchar *name) { glBindAttribLocation(program, index, name); }
    inline void blendEquationSeparate(GLenum modeRGB, GLenum modeAlpha) { glBlendEquationSeparate(modeRGB, modeAlpha); }
    inline void compileShader(GLuint shader) { glCompileShader(shader); }
    inline GLuint createProgram(void) { return glCreateProgram(); }
    inline GLuint createShader(GLenum type) { return glCreateShader(type); }
    inline void deleteProgram(GLuint program) { glDeleteProgram(program); }
    inline void deleteShader(GLuint shader) { glDeleteShader(shader); }
    inline void detachShader(GLuint program, GLuint shader) { glDetachShader(program, shader); }
    inline void disableVertexAttribArray(GLuint index) { glDisableVertexAttribArray(index); }
    inline void drawBuffers(GLsizei n, const GLenum *bufs) { glDrawBuffers(n, bufs); }
    inline void enableVertexAttribArray(GLuint index) { glEnableVertexAttribArray(index); }
    inline void getActiveAttrib(GLuint program, GLuint index, GLsizei bufSize, GLsizei *length, GLint *size, GLenum *type, GLchar *name) { glGetActiveAttrib(program, index, bufSize, length, size, type, name); }
    inline void getActiveUniform(GLuint program, GLuint index, GLsizei bufSize, GLsizei *length, GLint *size, GLenum *type, GLchar *name) { glGetActiveUniform(program, index, bufSize, length, size, type, name); }
    inline void getAttachedShaders(GLuint program, GLsizei maxCount, GLsizei *count, GLuint *shaders) { glGetAttachedShaders(program, maxCount, count, shaders); }
    inline GLint getAttribLocation(GLuint program, const GLchar *name) { return glGetAttribLocation(program, name); }
    inline void getProgramInfoLog(GLuint program, GLsizei bufSize, GLsizei *length, GLchar *infoLog) { glGetProgramInfoLog(program, bufSize, length, infoLog); }
    inline void getProgramiv(GLuint program, GLenum pname, GLint *params) { glGetProgramiv(program, pname, params); }
    inline void getShaderInfoLog(GLuint shader, GLsizei bufSize, GLsizei *length, GLchar *infoLog) { glGetShaderInfoLog(shader, bufSize, length, infoLog); }
    inline void getShaderSource(GLuint shader, GLsizei bufSize, GLsizei *length, GLchar *source) { glGetShaderSource(shader, bufSize, length, source); }
    inline void getShaderiv(GLuint shader, GLenum pname, GLint *params) { glGetShaderiv(shader, pname, params); }
    inline GLint getUniformLocation(GLuint program, const GLchar *name) { return glGetUniformLocation(program, name); }
    inline void getUniformfv(GLuint program, GLint location, GLfloat *params) { glGetUniformfv(program, location, params); }
    inline void getUniformiv(GLuint program, GLint location, GLint *params) { glGetUniformiv(program, location, params); }
    inline void getVertexAttribPointerv(GLuint index, GLenum pname, void **pointer) { glGetVertexAttribPointerv(index, pname, pointer); }
    inline void getVertexAttribdv(GLuint index, GLenum pname, GLdouble *params) { glGetVertexAttribdv(index, pname, params); }
    inline void getVertexAttribfv(GLuint index, GLenum pname, GLfloat *params) { glGetVertexAttribfv(index, pname, params); }
    inline void getVertexAttribiv(GLuint index, GLenum pname, GLint *params) { glGetVertexAttribiv(index, pname, params); }
    inline GLboolean isProgram(GLuint program) { return glIsProgram(program); }
    inline GLboolean isShader(GLuint shader) { return glIsShader(shader); }
    inline void linkProgram(GLuint program) { glLinkProgram(program); }
    inline void shaderSource(GLuint shader, GLsizei count, const GLchar *const*string, const GLint *length) { glShaderSource(shader, count, string, length); }
    inline void stencilFuncSeparate(GLenum face, GLenum func, GLint ref, GLuint mask) { glStencilFuncSeparate(face, func, ref, mask); }
    inline void stencilMaskSeparate(GLenum face, GLuint mask) { glStencilMaskSeparate(face, mask); }
    inline void stencilOpSeparate(GLenum face, GLenum sfail, GLenum dpfail, GLenum dppass) { glStencilOpSeparate(face, sfail, dpfail, dppass); }
    inline void uniform1f(GLint location, GLfloat v0) { glUniform1f(location, v0); }
    inline void uniform1fv(GLint location, GLsizei count, const GLfloat *value) { glUniform1fv(location, count, value); }
    inline void uniform1i(GLint location, GLint v0) { glUniform1i(location, v0); }
    inline void uniform1iv(GLint location, GLsizei count, const GLint *value) { glUniform1iv(location, count, value); }
    inline void uniform2f(GLint location, GLfloat v0, GLfloat v1) { glUniform2f(location, v0, v1); }
    inline void uniform2fv(GLint location, GLsizei count, const GLfloat *value) { glUniform2fv(location, count, value); }
    inline void uniform2i(GLint location, GLint v0, GLint v1) { glUniform2i(location, v0, v1); }
    inline void uniform2iv(GLint location, GLsizei count, const GLint *value) { glUniform2iv(location, count, value); }
    inline void uniform3f(GLint location, GLfloat v0, GLfloat v1, GLfloat v2) { glUniform3f(location, v0, v1, v2); }
    inline void uniform3fv(GLint location, GLsizei count, const GLfloat *value) { glUniform3fv(location, count, value); }
    inline void uniform3i(GLint location, GLint v0, GLint v1, GLint v2) { glUniform3i(location, v0, v1, v2); }
    inline void uniform3iv(GLint location, GLsizei count, const GLint *value) { glUniform3iv(location, count, value); }
    inline void uniform4f(GLint location, GLfloat v0, GLfloat v1, GLfloat v2, GLfloat v3) { glUniform4f(location, v0, v1, v2, v3); }
    inline void uniform4fv(GLint location, GLsizei count, const GLfloat *value) { glUniform4fv(location, count, value); }
    inline void uniform4i(GLint location, GLint v0, GLint v1, GLint v2, GLint v3) { glUniform4i(location, v0, v1, v2, v3); }
    inline void uniform4iv(GLint location, GLsizei count, const GLint *value) { glUniform4iv(location, count, value); }
    inline void uniformMatrix2fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value) { glUniformMatrix2fv(location, count, transpose, value); }
    inline void uniformMatrix3fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value) { glUniformMatrix3fv(location, count, transpose, value); }
    inline void uniformMatrix4fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value) { glUniformMatrix4fv(location, count, transpose, value); }
    inline void useProgram(GLuint program) { glUseProgram(program); }
    inline void validateProgram(GLuint program) { glValidateProgram(program); }
    inline void vertexAttrib1d(GLuint index, GLdouble x) { glVertexAttrib1d(index, x); }
    inline void vertexAttrib1dv(GLuint index, const GLdouble *v) { glVertexAttrib1dv(index, v); }
    inline void vertexAttrib1f(GLuint index, GLfloat x) { glVertexAttrib1f(index, x); }
    inline void vertexAttrib1fv(GLuint index, const GLfloat *v) { glVertexAttrib1fv(index, v); }
    inline void vertexAttrib1s(GLuint index, GLshort x) { glVertexAttrib1s(index, x); }
    inline void vertexAttrib1sv(GLuint index, const GLshort *v) { glVertexAttrib1sv(index, v); }
    inline void vertexAttrib2d(GLuint index, GLdouble x, GLdouble y) { glVertexAttrib2d(index, x, y); }
    inline void vertexAttrib2dv(GLuint index, const GLdouble *v) { glVertexAttrib2dv(index, v); }
    inline void vertexAttrib2f(GLuint index, GLfloat x, GLfloat y) { glVertexAttrib2f(index, x, y); }
    inline void vertexAttrib2fv(GLuint index, const GLfloat *v) { glVertexAttrib2fv(index, v); }
    inline void vertexAttrib2s(GLuint index, GLshort x, GLshort y) { glVertexAttrib2s(index, x, y); }
    inline void vertexAttrib2sv(GLuint index, const GLshort *v) { glVertexAttrib2sv(index, v); }
    inline void vertexAttrib3d(GLuint index, GLdouble x, GLdouble y, GLdouble z) { glVertexAttrib3d(index, x, y, z); }
    inline void vertexAttrib3dv(GLuint index, const GLdouble *v) { glVertexAttrib3dv(index, v); }
    inline void vertexAttrib3f(GLuint index, GLfloat x, GLfloat y, GLfloat z) { glVertexAttrib3f(index, x, y, z); }
    inline void vertexAttrib3fv(GLuint index, const GLfloat *v) { glVertexAttrib3fv(index, v); }
    inline void vertexAttrib3s(GLuint index, GLshort x, GLshort y, GLshort z) { glVertexAttrib3s(index, x, y, z); }
    inline void vertexAttrib3sv(GLuint index, const GLshort *v) { glVertexAttrib3sv(index, v); }
    inline void vertexAttrib4Nbv(GLuint index, const GLbyte *v) { glVertexAttrib4Nbv(index, v); }
    inline void vertexAttrib4Niv(GLuint index, const GLint *v) { glVertexAttrib4Niv(index, v); }
    inline void vertexAttrib4Nsv(GLuint index, const GLshort *v) { glVertexAttrib4Nsv(index, v); }
    inline void vertexAttrib4Nub(GLuint index, GLubyte x, GLubyte y, GLubyte z, GLubyte w) { glVertexAttrib4Nub(index, x, y, z, w); }
    inline void vertexAttrib4Nubv(GLuint index, const GLubyte *v) { glVertexAttrib4Nubv(index, v); }
    inline void vertexAttrib4Nuiv(GLuint index, const GLuint *v) { glVertexAttrib4Nuiv(index, v); }
    inline void vertexAttrib4Nusv(GLuint index, const GLushort *v) { glVertexAttrib4Nusv(index, v); }
    inline void vertexAttrib4bv(GLuint index, const GLbyte *v) { glVertexAttrib4bv(index, v); }
    inline void vertexAttrib4d(GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w) { glVertexAttrib4d(index, x, y, z, w); }
    inline void vertexAttrib4dv(GLuint index, const GLdouble *v) { glVertexAttrib4dv(index, v); }
    inline void vertexAttrib4f(GLuint index, GLfloat x, GLfloat y, GLfloat z, GLfloat w) { glVertexAttrib4f(index, x, y, z, w); }
    inline void vertexAttrib4fv(GLuint index, const GLfloat *v) { glVertexAttrib4fv(index, v); }
    inline void vertexAttrib4iv(GLuint index, const GLint *v) { glVertexAttrib4iv(index, v); }
    inline void vertexAttrib4s(GLuint index, GLshort x, GLshort y, GLshort z, GLshort w) { glVertexAttrib4s(index, x, y, z, w); }
    inline void vertexAttrib4sv(GLuint index, const GLshort *v) { glVertexAttrib4sv(index, v); }
    inline void vertexAttrib4ubv(GLuint index, const GLubyte *v) { glVertexAttrib4ubv(index, v); }
    inline void vertexAttrib4uiv(GLuint index, const GLuint *v) { glVertexAttrib4uiv(index, v); }
    inline void vertexAttrib4usv(GLuint index, const GLushort *v) { glVertexAttrib4usv(index, v); }
    inline void vertexAttribPointer(GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, const void *pointer) { glVertexAttribPointer(index, size, type, normalized, stride, pointer); }

    // GL_VERSION_2_1
    inline void uniformMatrix2x3fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value) { glUniformMatrix2x3fv(location, count, transpose, value); }
    inline void uniformMatrix2x4fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value) { glUniformMatrix2x4fv(location, count, transpose, value); }
    inline void uniformMatrix3x2fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value) { glUniformMatrix3x2fv(location, count, transpose, value); }
    inline void uniformMatrix3x4fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value) { glUniformMatrix3x4fv(location, count, transpose, value); }
    inline void uniformMatrix4x2fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value) { glUniformMatrix4x2fv(location, count, transpose, value); }
    inline void uniformMatrix4x3fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value) { glUniformMatrix4x3fv(location, count, transpose, value); }

    // GL_VERSION_3_0
    inline void beginConditionalRender(GLuint id, GLenum mode) { glBeginConditionalRender(id, mode); }
    inline void beginTransformFeedback(GLenum primitiveMode) { glBeginTransformFeedback(primitiveMode); }
    inline void bindBufferBase(GLenum target, GLuint index, GLuint buffer) { glBindBufferBase(target, index, buffer); }
    inline void bindBufferRange(GLenum target, GLuint index, GLuint buffer, GLintptr offset, GLsizeiptr size) { glBindBufferRange(target, index, buffer, offset, size); }
    inline void bindFragDataLocation(GLuint program, GLuint color, const GLchar *name) { glBindFragDataLocation(program, color, name); }
    inline void bindFramebuffer(GLenum target, GLuint framebuffer) { glBindFramebuffer(target, framebuffer); }
    inline void bindRenderbuffer(GLenum target, GLuint renderbuffer) { glBindRenderbuffer(target, renderbuffer); }
    inline void bindVertexArray(GLuint array) { glBindVertexArray(array); }
    inline void blitFramebuffer(GLint srcX0, GLint srcY0, GLint srcX1, GLint srcY1, GLint dstX0, GLint dstY0, GLint dstX1, GLint dstY1, GLbitfield mask, GLenum filter) { glBlitFramebuffer(srcX0, srcY0, srcX1, srcY1, dstX0, dstY0, dstX1, dstY1, mask, filter); }
    inline GLenum checkFramebufferStatus(GLenum target) { return glCheckFramebufferStatus(target); }
    inline void clampColor(GLenum target, GLenum clamp) { glClampColor(target, clamp); }
    inline void clearBufferfi(GLenum buffer, GLint drawbuffer, GLfloat depth, GLint stencil) { glClearBufferfi(buffer, drawbuffer, depth, stencil); }
    inline void clearBufferfv(GLenum buffer, GLint drawbuffer, const GLfloat *value) { glClearBufferfv(buffer, drawbuffer, value); }
    inline void clearBufferiv(GLenum buffer, GLint drawbuffer, const GLint *value) { glClearBufferiv(buffer, drawbuffer, value); }
    inline void clearBufferuiv(GLenum buffer, GLint drawbuffer, const GLuint *value) { glClearBufferuiv(buffer, drawbuffer, value); }
    inline void colorMaski(GLuint index, GLboolean r, GLboolean g, GLboolean b, GLboolean a) { glColorMaski(index, r, g, b, a); }
    inline void deleteFramebuffers(GLsizei n, const GLuint *framebuffers) { glDeleteFramebuffers(n, framebuffers); }
    inline void deleteRenderbuffers(GLsizei n, const GLuint *renderbuffers) { glDeleteRenderbuffers(n, renderbuffers); }
    inline void deleteVertexArrays(GLsizei n, const GLuint *arrays) { glDeleteVertexArrays(n, arrays); }
    inline void disablei(GLenum target, GLuint index) { glDisablei(target, index); }
    inline void enablei(GLenum target, GLuint index) { glEnablei(target, index); }
    inline void endConditionalRender(void) { glEndConditionalRender(); }
    inline void endTransformFeedback(void) { glEndTransformFeedback(); }
    inline void flushMappedBufferRange(GLenum target, GLintptr offset, GLsizeiptr length) { glFlushMappedBufferRange(target, offset, length); }
    inline void framebufferRenderbuffer(GLenum target, GLenum attachment, GLenum renderbuffertarget, GLuint renderbuffer) { glFramebufferRenderbuffer(target, attachment, renderbuffertarget, renderbuffer); }
    inline void framebufferTexture1D(GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level) { glFramebufferTexture1D(target, attachment, textarget, texture, level); }
    inline void framebufferTexture2D(GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level) { glFramebufferTexture2D(target, attachment, textarget, texture, level); }
    inline void framebufferTexture3D(GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level, GLint zoffset) { glFramebufferTexture3D(target, attachment, textarget, texture, level, zoffset); }
    inline void framebufferTextureLayer(GLenum target, GLenum attachment, GLuint texture, GLint level, GLint layer) { glFramebufferTextureLayer(target, attachment, texture, level, layer); }
    inline void genFramebuffers(GLsizei n, GLuint *framebuffers) { glGenFramebuffers(n, framebuffers); }
    inline void genRenderbuffers(GLsizei n, GLuint *renderbuffers) { glGenRenderbuffers(n, renderbuffers); }
    inline void genVertexArrays(GLsizei n, GLuint *arrays) { glGenVertexArrays(n, arrays); }
    inline void generateMipmap(GLenum target) { glGenerateMipmap(target); }
    inline void getBooleani_v(GLenum target, GLuint index, GLboolean *data) { glGetBooleani_v(target, index, data); }
    inline GLint getFragDataLocation(GLuint program, const GLchar *name) { return glGetFragDataLocation(program, name); }
    inline void getFramebufferAttachmentParameteriv(GLenum target, GLenum attachment, GLenum pname, GLint *params) { glGetFramebufferAttachmentParameteriv(target, attachment, pname, params); }
    inline void getIntegeri_v(GLenum target, GLuint index, GLint *data) { glGetIntegeri_v(target, index, data); }
    inline void getRenderbufferParameteriv(GLenum target, GLenum pname, GLint *params) { glGetRenderbufferParameteriv(target, pname, params); }
    inline const GLubyte *getStringi(GLenum name, GLuint index) { return glGetStringi(name, index); }
    inline void getTexParameterIiv(GLenum target, GLenum pname, GLint *params) { glGetTexParameterIiv(target, pname, params); }
    inline void getTexParameterIuiv(GLenum target, GLenum pname, GLuint *params) { glGetTexParameterIuiv(target, pname, params); }
    inline void getTransformFeedbackVarying(GLuint program, GLuint index, GLsizei bufSize, GLsizei *length, GLsizei *size, GLenum *type, GLchar *name) { glGetTransformFeedbackVarying(program, index, bufSize, length, size, type, name); }
    inline void getUniformuiv(GLuint program, GLint location, GLuint *params) { glGetUniformuiv(program, location, params); }
    inline void getVertexAttribIiv(GLuint index, GLenum pname, GLint *params) { glGetVertexAttribIiv(index, pname, params); }
    inline void getVertexAttribIuiv(GLuint index, GLenum pname, GLuint *params) { glGetVertexAttribIuiv(index, pname, params); }
    inline GLboolean isEnabledi(GLenum target, GLuint index) { return glIsEnabledi(target, index); }
    inline GLboolean isFramebuffer(GLuint framebuffer) { return glIsFramebuffer(framebuffer); }
    inline GLboolean isRenderbuffer(GLuint renderbuffer) { return glIsRenderbuffer(renderbuffer); }
    inline GLboolean isVertexArray(GLuint array) { return glIsVertexArray(array); }
    inline void *mapBufferRange(GLenum target, GLintptr offset, GLsizeiptr length, GLbitfield access) { return glMapBufferRange(target, offset, length, access); }
    inline void renderbufferStorage(GLenum target, GLenum internalformat, GLsizei width, GLsizei height) { glRenderbufferStorage(target, internalformat, width, height); }
    inline void renderbufferStorageMultisample(GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height) { glRenderbufferStorageMultisample(target, samples, internalformat, width, height); }
    inline void texParameterIiv(GLenum target, GLenum pname, const GLint *params) { glTexParameterIiv(target, pname, params); }
    inline void texParameterIuiv(GLenum target, GLenum pname, const GLuint *params) { glTexParameterIuiv(target, pname, params); }
    inline void transformFeedbackVaryings(GLuint program, GLsizei count, const GLchar *const*varyings, GLenum bufferMode) { glTransformFeedbackVaryings(program, count, varyings, bufferMode); }
    inline void uniform1ui(GLint location, GLuint v0) { glUniform1ui(location, v0); }
    inline void uniform1uiv(GLint location, GLsizei count, const GLuint *value) { glUniform1uiv(location, count, value); }
    inline void uniform2ui(GLint location, GLuint v0, GLuint v1) { glUniform2ui(location, v0, v1); }
    inline void uniform2uiv(GLint location, GLsizei count, const GLuint *value) { glUniform2uiv(location, count, value); }
    inline void uniform3ui(GLint location, GLuint v0, GLuint v1, GLuint v2) { glUniform3ui(location, v0, v1, v2); }
    inline void uniform3uiv(GLint location, GLsizei count, const GLuint *value) { glUniform3uiv(location, count, value); }
    inline void uniform4ui(GLint location, GLuint v0, GLuint v1, GLuint v2, GLuint v3) { glUniform4ui(location, v0, v1, v2, v3); }
    inline void uniform4uiv(GLint location, GLsizei count, const GLuint *value) { glUniform4uiv(location, count, value); }
    inline void vertexAttribI1i(GLuint index, GLint x) { glVertexAttribI1i(index, x); }
    inline void vertexAttribI1iv(GLuint index, const GLint *v) { glVertexAttribI1iv(index, v); }
    inline void vertexAttribI1ui(GLuint index, GLuint x) { glVertexAttribI1ui(index, x); }
    inline void vertexAttribI1uiv(GLuint index, const GLuint *v) { glVertexAttribI1uiv(index, v); }
    inline void vertexAttribI2i(GLuint index, GLint x, GLint y) { glVertexAttribI2i(index, x, y); }
    inline void vertexAttribI2iv(GLuint index, const GLint *v) { glVertexAttribI2iv(index, v); }
    inline void vertexAttribI2ui(GLuint index, GLuint x, GLuint y) { glVertexAttribI2ui(index, x, y); }
    inline void vertexAttribI2uiv(GLuint index, const GLuint *v) { glVertexAttribI2uiv(index, v); }
    inline void vertexAttribI3i(GLuint index, GLint x, GLint y, GLint z) { glVertexAttribI3i(index, x, y, z); }
    inline void vertexAttribI3iv(GLuint index, const GLint *v) { glVertexAttribI3iv(index, v); }
    inline void vertexAttribI3ui(GLuint index, GLuint x, GLuint y, GLuint z) { glVertexAttribI3ui(index, x, y, z); }
    inline void vertexAttribI3uiv(GLuint index, const GLuint *v) { glVertexAttribI3uiv(index, v); }
    inline void vertexAttribI4bv(GLuint index, const GLbyte *v) { glVertexAttribI4bv(index, v); }
    inline void vertexAttribI4i(GLuint index, GLint x, GLint y, GLint z, GLint w) { glVertexAttribI4i(index, x, y, z, w); }
    inline void vertexAttribI4iv(GLuint index, const GLint *v) { glVertexAttribI4iv(index, v); }
    inline void vertexAttribI4sv(GLuint index, const GLshort *v) { glVertexAttribI4sv(index, v); }
    inline void vertexAttribI4ubv(GLuint index, const GLubyte *v) { glVertexAttribI4ubv(index, v); }
    inline void vertexAttribI4ui(GLuint index, GLuint x, GLuint y, GLuint z, GLuint w) { glVertexAttribI4ui(index, x, y, z, w); }
    inline void vertexAttribI4uiv(GLuint index, const GLuint *v) { glVertexAttribI4uiv(index, v); }
    inline void vertexAttribI4usv(GLuint index, const GLushort *v) { glVertexAttribI4usv(index, v); }
    inline void vertexAttribIPointer(GLuint index, GLint size, GLenum type, GLsizei stride, const void *pointer) { glVertexAttribIPointer(index, size, type, stride, pointer); }

    // GL_VERSION_3_1
    inline void copyBufferSubData(GLenum readTarget, GLenum writeTarget, GLintptr readOffset, GLintptr writeOffset, GLsizeiptr size) { glCopyBufferSubData(readTarget, writeTarget, readOffset, writeOffset, size); }
    inline void drawArraysInstanced(GLenum mode, GLint first, GLsizei count, GLsizei instancecount) { glDrawArraysInstanced(mode, first, count, instancecount); }
    inline void drawElementsInstanced(GLenum mode, GLsizei count, GLenum type, const void *indices, GLsizei instancecount) { glDrawElementsInstanced(mode, count, type, indices, instancecount); }
    inline void getActiveUniformBlockName(GLuint program, GLuint uniformBlockIndex, GLsizei bufSize, GLsizei *length, GLchar *uniformBlockName) { glGetActiveUniformBlockName(program, uniformBlockIndex, bufSize, length, uniformBlockName); }
    inline void getActiveUniformBlockiv(GLuint program, GLuint uniformBlockIndex, GLenum pname, GLint *params) { glGetActiveUniformBlockiv(program, uniformBlockIndex, pname, params); }
    inline void getActiveUniformName(GLuint program, GLuint uniformIndex, GLsizei bufSize, GLsizei *length, GLchar *uniformName) { glGetActiveUniformName(program, uniformIndex, bufSize, length, uniformName); }
    inline void getActiveUniformsiv(GLuint program, GLsizei uniformCount, const GLuint *uniformIndices, GLenum pname, GLint *params) { glGetActiveUniformsiv(program, uniformCount, uniformIndices, pname, params); }
    inline GLuint getUniformBlockIndex(GLuint program, const GLchar *uniformBlockName) { return glGetUniformBlockIndex(program, uniformBlockName); }
    inline void getUniformIndices(GLuint program, GLsizei uniformCount, const GLchar *const*uniformNames, GLuint *uniformIndices) { glGetUniformIndices(program, uniformCount, uniformNames, uniformIndices); }
    inline void primitiveRestartIndex(GLuint index) { glPrimitiveRestartIndex(index); }
    inline void texBuffer(GLenum target, GLenum internalformat, GLuint buffer) { glTexBuffer(target, internalformat, buffer); }
    inline void uniformBlockBinding(GLuint program, GLuint uniformBlockIndex, GLuint uniformBlockBinding) { glUniformBlockBinding(program, uniformBlockIndex, uniformBlockBinding); }

    // GL_VERSION_3_2
    inline GLenum clientWaitSync(GLsync sync, GLbitfield flags, GLuint64 timeout) { return glClientWaitSync(sync, flags, timeout); }
    inline void deleteSync(GLsync sync) { glDeleteSync(sync); }
    inline void drawElementsBaseVertex(GLenum mode, GLsizei count, GLenum type, const void *indices, GLint basevertex) { glDrawElementsBaseVertex(mode, count, type, indices, basevertex); }
    inline void drawElementsInstancedBaseVertex(GLenum mode, GLsizei count, GLenum type, const void *indices, GLsizei instancecount, GLint basevertex) { glDrawElementsInstancedBaseVertex(mode, count, type, indices, instancecount, basevertex); }
    inline void drawRangeElementsBaseVertex(GLenum mode, GLuint start, GLuint end, GLsizei count, GLenum type, const void *indices, GLint basevertex) { glDrawRangeElementsBaseVertex(mode, start, end, count, type, indices, basevertex); }
    inline GLsync fenceSync(GLenum condition, GLbitfield flags) { return glFenceSync(condition, flags); }
    inline void framebufferTexture(GLenum target, GLenum attachment, GLuint texture, GLint level) { glFramebufferTexture(target, attachment, texture, level); }
    inline void getBufferParameteri64v(GLenum target, GLenum pname, GLint64 *params) { glGetBufferParameteri64v(target, pname, params); }
    inline void getInteger64i_v(GLenum target, GLuint index, GLint64 *data) { glGetInteger64i_v(target, index, data); }
    inline void getInteger64v(GLenum pname, GLint64 *data) { glGetInteger64v(pname, data); }
    inline void getMultisamplefv(GLenum pname, GLuint index, GLfloat *val) { glGetMultisamplefv(pname, index, val); }
    inline void getSynciv(GLsync sync, GLenum pname, GLsizei bufSize, GLsizei *length, GLint *values) { glGetSynciv(sync, pname, bufSize, length, values); }
    inline GLboolean isSync(GLsync sync) { return glIsSync(sync); }
    inline void multiDrawElementsBaseVertex(GLenum mode, const GLsizei *count, GLenum type, const void *const*indices, GLsizei drawcount, const GLint *basevertex) { glMultiDrawElementsBaseVertex(mode, count, type, indices, drawcount, basevertex); }
    inline void provokingVertex(GLenum mode) { glProvokingVertex(mode); }
    inline void sampleMaski(GLuint maskNumber, GLbitfield mask) { glSampleMaski(maskNumber, mask); }
    inline void texImage2DMultisample(GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLboolean fixedsamplelocations) { glTexImage2DMultisample(target, samples, internalformat, width, height, fixedsamplelocations); }
    inline void texImage3DMultisample(GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLboolean fixedsamplelocations) { glTexImage3DMultisample(target, samples, internalformat, width, height, depth, fixedsamplelocations); }
    inline void waitSync(GLsync sync, GLbitfield flags, GLuint64 timeout) { glWaitSync(sync, flags, timeout); }

    // GL_VERSION_3_3
    inline void bindFragDataLocationIndexed(GLuint program, GLuint colorNumber, GLuint index, const GLchar *name) { glBindFragDataLocationIndexed(program, colorNumber, index, name); }
    inline void bindSampler(GLuint unit, GLuint sampler) { glBindSampler(unit, sampler); }
    inline void deleteSamplers(GLsizei count, const GLuint *samplers) { glDeleteSamplers(count, samplers); }
    inline void genSamplers(GLsizei count, GLuint *samplers) { glGenSamplers(count, samplers); }
    inline GLint getFragDataIndex(GLuint program, const GLchar *name) { return glGetFragDataIndex(program, name); }
    inline void getQueryObjecti64v(GLuint id, GLenum pname, GLint64 *params) { glGetQueryObjecti64v(id, pname, params); }
    inline void getQueryObjectui64v(GLuint id, GLenum pname, GLuint64 *params) { glGetQueryObjectui64v(id, pname, params); }
    inline void getSamplerParameterIiv(GLuint sampler, GLenum pname, GLint *params) { glGetSamplerParameterIiv(sampler, pname, params); }
    inline void getSamplerParameterIuiv(GLuint sampler, GLenum pname, GLuint *params) { glGetSamplerParameterIuiv(sampler, pname, params); }
    inline void getSamplerParameterfv(GLuint sampler, GLenum pname, GLfloat *params) { glGetSamplerParameterfv(sampler, pname, params); }
    inline void getSamplerParameteriv(GLuint sampler, GLenum pname, GLint *params) { glGetSamplerParameteriv(sampler, pname, params); }
    inline GLboolean isSampler(GLuint sampler) { return glIsSampler(sampler); }
    inline void queryCounter(GLuint id, GLenum target) { glQueryCounter(id, target); }
    inline void samplerParameterIiv(GLuint sampler, GLenum pname, const GLint *param) { glSamplerParameterIiv(sampler, pname, param); }
    inline void samplerParameterIuiv(GLuint sampler, GLenum pname, const GLuint *param) { glSamplerParameterIuiv(sampler, pname, param); }
    inline void samplerParameterf(GLuint sampler, GLenum pname, GLfloat param) { glSamplerParameterf(sampler, pname, param); }
    inline void samplerParameterfv(GLuint sampler, GLenum pname, const GLfloat *param) { glSamplerParameterfv(sampler, pname, param); }
    inline void samplerParameteri(GLuint sampler, GLenum pname, GLint param) { glSamplerParameteri(sampler, pname, param); }
    inline void samplerParameteriv(GLuint sampler, GLenum pname, const GLint *param) { glSamplerParameteriv(sampler, pname, param); }
    inline void vertexAttribDivisor(GLuint index, GLuint divisor) { glVertexAttribDivisor(index, divisor); }
    inline void vertexAttribP1ui(GLuint index, GLenum type, GLboolean normalized, GLuint value) { glVertexAttribP1ui(index, type, normalized, value); }
    inline void vertexAttribP1uiv(GLuint index, GLenum type, GLboolean normalized, const GLuint *value) { glVertexAttribP1uiv(index, type, normalized, value); }
    inline void vertexAttribP2ui(GLuint index, GLenum type, GLboolean normalized, GLuint value) { glVertexAttribP2ui(index, type, normalized, value); }
    inline void vertexAttribP2uiv(GLuint index, GLenum type, GLboolean normalized, const GLuint *value) { glVertexAttribP2uiv(index, type, normalized, value); }
    inline void vertexAttribP3ui(GLuint index, GLenum type, GLboolean normalized, GLuint value) { glVertexAttribP3ui(index, type, normalized, value); }
    inline void vertexAttribP3uiv(GLuint index, GLenum type, GLboolean normalized, const GLuint *value) { glVertexAttribP3uiv(index, type, normalized, value); }
    inline void vertexAttribP4ui(GLuint index, GLenum type, GLboolean normalized, GLuint value) { glVertexAttribP4ui(index, type, normalized, value); }
    inline void vertexAttribP4uiv(GLuint index, GLenum type, GLboolean normalized, const GLuint *value) { glVertexAttribP4uiv(index, type, normalized, value); }

    // GL_VERSION_4_0
    inline void beginQueryIndexed(GLenum target, GLuint index, GLuint id) { glBeginQueryIndexed(target, index, id); }
    inline void bindTransformFeedback(GLenum target, GLuint id) { glBindTransformFeedback(target, id); }
    inline void blendEquationSeparatei(GLuint buf, GLenum modeRGB, GLenum modeAlpha) { glBlendEquationSeparatei(buf, modeRGB, modeAlpha); }
    inline void blendEquationi(GLuint buf, GLenum mode) { glBlendEquationi(buf, mode); }
    inline void blendFuncSeparatei(GLuint buf, GLenum srcRGB, GLenum dstRGB, GLenum srcAlpha, GLenum dstAlpha) { glBlendFuncSeparatei(buf, srcRGB, dstRGB, srcAlpha, dstAlpha); }
    inline void blendFunci(GLuint buf, GLenum src, GLenum dst) { glBlendFunci(buf, src, dst); }
    inline void deleteTransformFeedbacks(GLsizei n, const GLuint *ids) { glDeleteTransformFeedbacks(n, ids); }
    inline void drawArraysIndirect(GLenum mode, const void *indirect) { glDrawArraysIndirect(mode, indirect); }
    inline void drawElementsIndirect(GLenum mode, GLenum type, const void *indirect) { glDrawElementsIndirect(mode, type, indirect); }
    inline void drawTransformFeedback(GLenum mode, GLuint id) { glDrawTransformFeedback(mode, id); }
    inline void drawTransformFeedbackStream(GLenum mode, GLuint id, GLuint stream) { glDrawTransformFeedbackStream(mode, id, stream); }
    inline void endQueryIndexed(GLenum target, GLuint index) { glEndQueryIndexed(target, index); }
    inline void genTransformFeedbacks(GLsizei n, GLuint *ids) { glGenTransformFeedbacks(n, ids); }
    inline void getActiveSubroutineName(GLuint program, GLenum shadertype, GLuint index, GLsizei bufsize, GLsizei *length, GLchar *name) { glGetActiveSubroutineName(program, shadertype, index, bufsize, length, name); }
    inline void getActiveSubroutineUniformName(GLuint program, GLenum shadertype, GLuint index, GLsizei bufsize, GLsizei *length, GLchar *name) { glGetActiveSubroutineUniformName(program, shadertype, index, bufsize, length, name); }
    inline void getActiveSubroutineUniformiv(GLuint program, GLenum shadertype, GLuint index, GLenum pname, GLint *values) { glGetActiveSubroutineUniformiv(program, shadertype, index, pname, values); }
    inline void getProgramStageiv(GLuint program, GLenum shadertype, GLenum pname, GLint *values) { glGetProgramStageiv(program, shadertype, pname, values); }
    inline void getQueryIndexediv(GLenum target, GLuint index, GLenum pname, GLint *params) { glGetQueryIndexediv(target, index, pname, params); }
    inline GLuint getSubroutineIndex(GLuint program, GLenum shadertype, const GLchar *name) { return glGetSubroutineIndex(program, shadertype, name); }
    inline GLint getSubroutineUniformLocation(GLuint program, GLenum shadertype, const GLchar *name) { return glGetSubroutineUniformLocation(program, shadertype, name); }
    inline void getUniformSubroutineuiv(GLenum shadertype, GLint location, GLuint *params) { glGetUniformSubroutineuiv(shadertype, location, params); }
    inline void getUniformdv(GLuint program, GLint location, GLdouble *params) { glGetUniformdv(program, location, params); }
    inline GLboolean isTransformFeedback(GLuint id) { return glIsTransformFeedback(id); }
    inline void minSampleShading(GLfloat value) { glMinSampleShading(value); }
    inline void patchParameterfv(GLenum pname, const GLfloat *values) { glPatchParameterfv(pname, values); }
    inline void patchParameteri(GLenum pname, GLint value) { glPatchParameteri(pname, value); }
    inline void pauseTransformFeedback(void) { glPauseTransformFeedback(); }
    inline void resumeTransformFeedback(void) { glResumeTransformFeedback(); }
    inline void uniform1d(GLint location, GLdouble x) { glUniform1d(location, x); }
    inline void uniform1dv(GLint location, GLsizei count, const GLdouble *value) { glUniform1dv(location, count, value); }
    inline void uniform2d(GLint location, GLdouble x, GLdouble y) { glUniform2d(location, x, y); }
    inline void uniform2dv(GLint location, GLsizei count, const GLdouble *value) { glUniform2dv(location, count, value); }
    inline void uniform3d(GLint location, GLdouble x, GLdouble y, GLdouble z) { glUniform3d(location, x, y, z); }
    inline void uniform3dv(GLint location, GLsizei count, const GLdouble *value) { glUniform3dv(location, count, value); }
    inline void uniform4d(GLint location, GLdouble x, GLdouble y, GLdouble z, GLdouble w) { glUniform4d(location, x, y, z, w); }
    inline void uniform4dv(GLint location, GLsizei count, const GLdouble *value) { glUniform4dv(location, count, value); }
    inline void uniformMatrix2dv(GLint location, GLsizei count, GLboolean transpose, const GLdouble *value) { glUniformMatrix2dv(location, count, transpose, value); }
    inline void uniformMatrix2x3dv(GLint location, GLsizei count, GLboolean transpose, const GLdouble *value) { glUniformMatrix2x3dv(location, count, transpose, value); }
    inline void uniformMatrix2x4dv(GLint location, GLsizei count, GLboolean transpose, const GLdouble *value) { glUniformMatrix2x4dv(location, count, transpose, value); }
    inline void uniformMatrix3dv(GLint location, GLsizei count, GLboolean transpose, const GLdouble *value) { glUniformMatrix3dv(location, count, transpose, value); }
    inline void uniformMatrix3x2dv(GLint location, GLsizei count, GLboolean transpose, const GLdouble *value) { glUniformMatrix3x2dv(location, count, transpose, value); }
    inline void uniformMatrix3x4dv(GLint location, GLsizei count, GLboolean transpose, const GLdouble *value) { glUniformMatrix3x4dv(location, count, transpose, value); }
    inline void uniformMatrix4dv(GLint location, GLsizei count, GLboolean transpose, const GLdouble *value) { glUniformMatrix4dv(location, count, transpose, value); }
    inline void uniformMatrix4x2dv(GLint location, GLsizei count, GLboolean transpose, const GLdouble *value) { glUniformMatrix4x2dv(location, count, transpose, value); }
    inline void uniformMatrix4x3dv(GLint location, GLsizei count, GLboolean transpose, const GLdouble *value) { glUniformMatrix4x3dv(location, count, transpose, value); }
    inline void uniformSubroutinesuiv(GLenum shadertype, GLsizei count, const GLuint *indices) { glUniformSubroutinesuiv(shadertype, count, indices); }

    // GL_VERSION_4_1
    inline void activeShaderProgram(GLuint pipeline, GLuint program) { glActiveShaderProgram(pipeline, program); }
    inline void bindProgramPipeline(GLuint pipeline) { glBindProgramPipeline(pipeline); }
    inline void clearDepthf(GLfloat d) { glClearDepthf(d); }
    inline GLuint createShaderProgramv(GLenum type, GLsizei count, const GLchar *const*strings) { return glCreateShaderProgramv(type, count, strings); }
    inline void deleteProgramPipelines(GLsizei n, const GLuint *pipelines) { glDeleteProgramPipelines(n, pipelines); }
    inline void depthRangeArrayv(GLuint first, GLsizei count, const GLdouble *v) { glDepthRangeArrayv(first, count, v); }
    inline void depthRangeIndexed(GLuint index, GLdouble n, GLdouble f) { glDepthRangeIndexed(index, n, f); }
    inline void depthRangef(GLfloat n, GLfloat f) { glDepthRangef(n, f); }
    inline void genProgramPipelines(GLsizei n, GLuint *pipelines) { glGenProgramPipelines(n, pipelines); }
    inline void getDoublei_v(GLenum target, GLuint index, GLdouble *data) { glGetDoublei_v(target, index, data); }
    inline void getFloati_v(GLenum target, GLuint index, GLfloat *data) { glGetFloati_v(target, index, data); }
    inline void getProgramBinary(GLuint program, GLsizei bufSize, GLsizei *length, GLenum *binaryFormat, void *binary) { glGetProgramBinary(program, bufSize, length, binaryFormat, binary); }
    inline void getProgramPipelineInfoLog(GLuint pipeline, GLsizei bufSize, GLsizei *length, GLchar *infoLog) { glGetProgramPipelineInfoLog(pipeline, bufSize, length, infoLog); }
    inline void getProgramPipelineiv(GLuint pipeline, GLenum pname, GLint *params) { glGetProgramPipelineiv(pipeline, pname, params); }
    inline void getShaderPrecisionFormat(GLenum shadertype, GLenum precisiontype, GLint *range, GLint *precision) { glGetShaderPrecisionFormat(shadertype, precisiontype, range, precision); }
    inline void getVertexAttribLdv(GLuint index, GLenum pname, GLdouble *params) { glGetVertexAttribLdv(index, pname, params); }
    inline GLboolean isProgramPipeline(GLuint pipeline) { return glIsProgramPipeline(pipeline); }
    inline void programBinary(GLuint program, GLenum binaryFormat, const void *binary, GLsizei length) { glProgramBinary(program, binaryFormat, binary, length); }
    inline void programParameteri(GLuint program, GLenum pname, GLint value) { glProgramParameteri(program, pname, value); }
    inline void programUniform1d(GLuint program, GLint location, GLdouble v0) { glProgramUniform1d(program, location, v0); }
    inline void programUniform1dv(GLuint program, GLint location, GLsizei count, const GLdouble *value) { glProgramUniform1dv(program, location, count, value); }
    inline void programUniform1f(GLuint program, GLint location, GLfloat v0) { glProgramUniform1f(program, location, v0); }
    inline void programUniform1fv(GLuint program, GLint location, GLsizei count, const GLfloat *value) { glProgramUniform1fv(program, location, count, value); }
    inline void programUniform1i(GLuint program, GLint location, GLint v0) { glProgramUniform1i(program, location, v0); }
    inline void programUniform1iv(GLuint program, GLint location, GLsizei count, const GLint *value) { glProgramUniform1iv(program, location, count, value); }
    inline void programUniform1ui(GLuint program, GLint location, GLuint v0) { glProgramUniform1ui(program, location, v0); }
    inline void programUniform1uiv(GLuint program, GLint location, GLsizei count, const GLuint *value) { glProgramUniform1uiv(program, location, count, value); }
    inline void programUniform2d(GLuint program, GLint location, GLdouble v0, GLdouble v1) { glProgramUniform2d(program, location, v0, v1); }
    inline void programUniform2dv(GLuint program, GLint location, GLsizei count, const GLdouble *value) { glProgramUniform2dv(program, location, count, value); }
    inline void programUniform2f(GLuint program, GLint location, GLfloat v0, GLfloat v1) { glProgramUniform2f(program, location, v0, v1); }
    inline void programUniform2fv(GLuint program, GLint location, GLsizei count, const GLfloat *value) { glProgramUniform2fv(program, location, count, value); }
    inline void programUniform2i(GLuint program, GLint location, GLint v0, GLint v1) { glProgramUniform2i(program, location, v0, v1); }
    inline void programUniform2iv(GLuint program, GLint location, GLsizei count, const GLint *value) { glProgramUniform2iv(program, location, count, value); }
    inline void programUniform2ui(GLuint program, GLint location, GLuint v0, GLuint v1) { glProgramUniform2ui(program, location, v0, v1); }
    inline void programUniform2uiv(GLuint program, GLint location, GLsizei count, const GLuint *value) { glProgramUniform2uiv(program, location, count, value); }
    inline void programUniform3d(GLuint program, GLint location, GLdouble v0, GLdouble v1, GLdouble v2) { glProgramUniform3d(program, location, v0, v1, v2); }
    inline void programUniform3dv(GLuint program, GLint location, GLsizei count, const GLdouble *value) { glProgramUniform3dv(program, location, count, value); }
    inline void programUniform3f(GLuint program, GLint location, GLfloat v0, GLfloat v1, GLfloat v2) { glProgramUniform3f(program, location, v0, v1, v2); }
    inline void programUniform3fv(GLuint program, GLint location, GLsizei count, const GLfloat *value) { glProgramUniform3fv(program, location, count, value); }
    inline void programUniform3i(GLuint program, GLint location, GLint v0, GLint v1, GLint v2) { glProgramUniform3i(program, location, v0, v1, v2); }
    inline void programUniform3iv(GLuint program, GLint location, GLsizei count, const GLint *value) { glProgramUniform3iv(program, location, count, value); }
    inline void programUniform3ui(GLuint program, GLint location, GLuint v0, GLuint v1, GLuint v2) { glProgramUniform3ui(program, location, v0, v1, v2); }
    inline void programUniform3uiv(GLuint program, GLint location, GLsizei count, const GLuint *value) { glProgramUniform3uiv(program, location, count, value); }
    inline void programUniform4d(GLuint program, GLint location, GLdouble v0, GLdouble v1, GLdouble v2, GLdouble v3) { glProgramUniform4d(program, location, v0, v1, v2, v3); }
    inline void programUniform4dv(GLuint program, GLint location, GLsizei count, const GLdouble *value) { glProgramUniform4dv(program, location, count, value); }
    inline void programUniform4f(GLuint program, GLint location, GLfloat v0, GLfloat v1, GLfloat v2, GLfloat v3) { glProgramUniform4f(program, location, v0, v1, v2, v3); }
    inline void programUniform4fv(GLuint program, GLint location, GLsizei count, const GLfloat *value) { glProgramUniform4fv(program, location, count, value); }
    inline void programUniform4i(GLuint program, GLint location, GLint v0, GLint v1, GLint v2, GLint v3) { glProgramUniform4i(program, location, v0, v1, v2, v3); }
    inline void programUniform4iv(GLuint program, GLint location, GLsizei count, const GLint *value) { glProgramUniform4iv(program, location, count, value); }
    inline void programUniform4ui(GLuint program, GLint location, GLuint v0, GLuint v1, GLuint v2, GLuint v3) { glProgramUniform4ui(program, location, v0, v1, v2, v3); }
    inline void programUniform4uiv(GLuint program, GLint location, GLsizei count, const GLuint *value) { glProgramUniform4uiv(program, location, count, value); }
    inline void programUniformMatrix2dv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value) { glProgramUniformMatrix2dv(program, location, count, transpose, value); }
    inline void programUniformMatrix2fv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value) { glProgramUniformMatrix2fv(program, location, count, transpose, value); }
    inline void programUniformMatrix2x3dv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value) { glProgramUniformMatrix2x3dv(program, location, count, transpose, value); }
    inline void programUniformMatrix2x3fv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value) { glProgramUniformMatrix2x3fv(program, location, count, transpose, value); }
    inline void programUniformMatrix2x4dv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value) { glProgramUniformMatrix2x4dv(program, location, count, transpose, value); }
    inline void programUniformMatrix2x4fv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value) { glProgramUniformMatrix2x4fv(program, location, count, transpose, value); }
    inline void programUniformMatrix3dv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value) { glProgramUniformMatrix3dv(program, location, count, transpose, value); }
    inline void programUniformMatrix3fv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value) { glProgramUniformMatrix3fv(program, location, count, transpose, value); }
    inline void programUniformMatrix3x2dv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value) { glProgramUniformMatrix3x2dv(program, location, count, transpose, value); }
    inline void programUniformMatrix3x2fv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value) { glProgramUniformMatrix3x2fv(program, location, count, transpose, value); }
    inline void programUniformMatrix3x4dv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value) { glProgramUniformMatrix3x4dv(program, location, count, transpose, value); }
    inline void programUniformMatrix3x4fv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value) { glProgramUniformMatrix3x4fv(program, location, count, transpose, value); }
    inline void programUniformMatrix4dv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value) { glProgramUniformMatrix4dv(program, location, count, transpose, value); }
    inline void programUniformMatrix4fv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value) { glProgramUniformMatrix4fv(program, location, count, transpose, value); }
    inline void programUniformMatrix4x2dv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value) { glProgramUniformMatrix4x2dv(program, location, count, transpose, value); }
    inline void programUniformMatrix4x2fv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value) { glProgramUniformMatrix4x2fv(program, location, count, transpose, value); }
    inline void programUniformMatrix4x3dv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value) { glProgramUniformMatrix4x3dv(program, location, count, transpose, value); }
    inline void programUniformMatrix4x3fv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value) { glProgramUniformMatrix4x3fv(program, location, count, transpose, value); }
    inline void releaseShaderCompiler(void) { glReleaseShaderCompiler(); }
    inline void scissorArrayv(GLuint first, GLsizei count, const GLint *v) { glScissorArrayv(first, count, v); }
    inline void scissorIndexed(GLuint index, GLint left, GLint bottom, GLsizei width, GLsizei height) { glScissorIndexed(index, left, bottom, width, height); }
    inline void scissorIndexedv(GLuint index, const GLint *v) { glScissorIndexedv(index, v); }
    inline void shaderBinary(GLsizei count, const GLuint *shaders, GLenum binaryformat, const void *binary, GLsizei length) { glShaderBinary(count, shaders, binaryformat, binary, length); }
    inline void useProgramStages(GLuint pipeline, GLbitfield stages, GLuint program) { glUseProgramStages(pipeline, stages, program); }
    inline void validateProgramPipeline(GLuint pipeline) { glValidateProgramPipeline(pipeline); }
    inline void vertexAttribL1d(GLuint index, GLdouble x) { glVertexAttribL1d(index, x); }
    inline void vertexAttribL1dv(GLuint index, const GLdouble *v) { glVertexAttribL1dv(index, v); }
    inline void vertexAttribL2d(GLuint index, GLdouble x, GLdouble y) { glVertexAttribL2d(index, x, y); }
    inline void vertexAttribL2dv(GLuint index, const GLdouble *v) { glVertexAttribL2dv(index, v); }
    inline void vertexAttribL3d(GLuint index, GLdouble x, GLdouble y, GLdouble z) { glVertexAttribL3d(index, x, y, z); }
    inline void vertexAttribL3dv(GLuint index, const GLdouble *v) { glVertexAttribL3dv(index, v); }
    inline void vertexAttribL4d(GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w) { glVertexAttribL4d(index, x, y, z, w); }
    inline void vertexAttribL4dv(GLuint index, const GLdouble *v) { glVertexAttribL4dv(index, v); }
    inline void vertexAttribLPointer(GLuint index, GLint size, GLenum type, GLsizei stride, const void *pointer) { glVertexAttribLPointer(index, size, type, stride, pointer); }
    inline void viewportArrayv(GLuint first, GLsizei count, const GLfloat *v) { glViewportArrayv(first, count, v); }
    inline void viewportIndexedf(GLuint index, GLfloat x, GLfloat y, GLfloat w, GLfloat h) { glViewportIndexedf(index, x, y, w, h); }
    inline void viewportIndexedfv(GLuint index, const GLfloat *v) { glViewportIndexedfv(index, v); }

    // GL_VERSION_4_2
    inline void bindImageTexture(GLuint unit, GLuint texture, GLint level, GLboolean layered, GLint layer, GLenum access, GLenum format) { glBindImageTexture(unit, texture, level, layered, layer, access, format); }
    inline void drawArraysInstancedBaseInstance(GLenum mode, GLint first, GLsizei count, GLsizei instancecount, GLuint baseinstance) { glDrawArraysInstancedBaseInstance(mode, first, count, instancecount, baseinstance); }
    inline void drawElementsInstancedBaseInstance(GLenum mode, GLsizei count, GLenum type, const void *indices, GLsizei instancecount, GLuint baseinstance) { glDrawElementsInstancedBaseInstance(mode, count, type, indices, instancecount, baseinstance); }
    inline void drawElementsInstancedBaseVertexBaseInstance(GLenum mode, GLsizei count, GLenum type, const void *indices, GLsizei instancecount, GLint basevertex, GLuint baseinstance) { glDrawElementsInstancedBaseVertexBaseInstance(mode, count, type, indices, instancecount, basevertex, baseinstance); }
    inline void drawTransformFeedbackInstanced(GLenum mode, GLuint id, GLsizei instancecount) { glDrawTransformFeedbackInstanced(mode, id, instancecount); }
    inline void drawTransformFeedbackStreamInstanced(GLenum mode, GLuint id, GLuint stream, GLsizei instancecount) { glDrawTransformFeedbackStreamInstanced(mode, id, stream, instancecount); }
    inline void getActiveAtomicCounterBufferiv(GLuint program, GLuint bufferIndex, GLenum pname, GLint *params) { glGetActiveAtomicCounterBufferiv(program, bufferIndex, pname, params); }
    inline void getInternalformativ(GLenum target, GLenum internalformat, GLenum pname, GLsizei bufSize, GLint *params) { glGetInternalformativ(target, internalformat, pname, bufSize, params); }
    inline void memoryBarrier(GLbitfield barriers) { glMemoryBarrier(barriers); }
    inline void texStorage1D(GLenum target, GLsizei levels, GLenum internalformat, GLsizei width) { glTexStorage1D(target, levels, internalformat, width); }
    inline void texStorage2D(GLenum target, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height) { glTexStorage2D(target, levels, internalformat, width, height); }
    inline void texStorage3D(GLenum target, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth) { glTexStorage3D(target, levels, internalformat, width, height, depth); }

    // GL_VERSION_4_3
    inline void bindVertexBuffer(GLuint bindingindex, GLuint buffer, GLintptr offset, GLsizei stride) { glBindVertexBuffer(bindingindex, buffer, offset, stride); }
    inline void clearBufferData(GLenum target, GLenum internalformat, GLenum format, GLenum type, const void *data) { glClearBufferData(target, internalformat, format, type, data); }
    inline void clearBufferSubData(GLenum target, GLenum internalformat, GLintptr offset, GLsizeiptr size, GLenum format, GLenum type, const void *data) { glClearBufferSubData(target, internalformat, offset, size, format, type, data); }
    inline void copyImageSubData(GLuint srcName, GLenum srcTarget, GLint srcLevel, GLint srcX, GLint srcY, GLint srcZ, GLuint dstName, GLenum dstTarget, GLint dstLevel, GLint dstX, GLint dstY, GLint dstZ, GLsizei srcWidth, GLsizei srcHeight, GLsizei srcDepth) { glCopyImageSubData(srcName, srcTarget, srcLevel, srcX, srcY, srcZ, dstName, dstTarget, dstLevel, dstX, dstY, dstZ, srcWidth, srcHeight, srcDepth); }
    inline void debugMessageCallback(NOpenGLProc::TDebugCallback callback, const void *userParam) { glDebugMessageCallback(callback, userParam); }
    inline void debugMessageControl(GLenum source, GLenum type, GLenum severity, GLsizei count, const GLuint *ids, GLboolean enabled) { glDebugMessageControl(source, type, severity, count, ids, enabled); }
    inline void debugMessageInsert(GLenum source, GLenum type, GLuint id, GLenum severity, GLsizei length, const GLchar *buf) { glDebugMessageInsert(source, type, id, severity, length, buf); }
    inline void dispatchCompute(GLuint num_groups_x, GLuint num_groups_y, GLuint num_groups_z) { glDispatchCompute(num_groups_x, num_groups_y, num_groups_z); }
    inline void dispatchComputeIndirect(GLintptr indirect) { glDispatchComputeIndirect(indirect); }
    inline void framebufferParameteri(GLenum target, GLenum pname, GLint param) { glFramebufferParameteri(target, pname, param); }
    inline GLuint getDebugMessageLog(GLuint count, GLsizei bufSize, GLenum *sources, GLenum *types, GLuint *ids, GLenum *severities, GLsizei *lengths, GLchar *messageLog) { return glGetDebugMessageLog(count, bufSize, sources, types, ids, severities, lengths, messageLog); }
    inline void getFramebufferParameteriv(GLenum target, GLenum pname, GLint *params) { glGetFramebufferParameteriv(target, pname, params); }
    inline void getInternalformati64v(GLenum target, GLenum internalformat, GLenum pname, GLsizei bufSize, GLint64 *params) { glGetInternalformati64v(target, internalformat, pname, bufSize, params); }
    inline void getObjectLabel(GLenum identifier, GLuint name, GLsizei bufSize, GLsizei *length, GLchar *label) { glGetObjectLabel(identifier, name, bufSize, length, label); }
    inline void getObjectPtrLabel(const void *ptr, GLsizei bufSize, GLsizei *length, GLchar *label) { glGetObjectPtrLabel(ptr, bufSize, length, label); }
    inline void getProgramInterfaceiv(GLuint program, GLenum programInterface, GLenum pname, GLint *params) { glGetProgramInterfaceiv(program, programInterface, pname, params); }
    inline GLuint getProgramResourceIndex(GLuint program, GLenum programInterface, const GLchar *name) { return glGetProgramResourceIndex(program, programInterface, name); }
    inline GLint getProgramResourceLocation(GLuint program, GLenum programInterface, const GLchar *name) { return glGetProgramResourceLocation(program, programInterface, name); }
    inline GLint getProgramResourceLocationIndex(GLuint program, GLenum programInterface, const GLchar *name) { return glGetProgramResourceLocationIndex(program, programInterface, name); }
    inline void getProgramResourceName(GLuint program, GLenum programInterface, GLuint index, GLsizei bufSize, GLsizei *length, GLchar *name) { glGetProgramResourceName(program, programInterface, index, bufSize, length, name); }
    inline void getProgramResourceiv(GLuint program, GLenum programInterface, GLuint index, GLsizei propCount, const GLenum *props, GLsizei bufSize, GLsizei *length, GLint *params) { glGetProgramResourceiv(program, programInterface, index, propCount, props, bufSize, length, params); }
    inline void invalidateBufferData(GLuint buffer) { glInvalidateBufferData(buffer); }
    inline void invalidateBufferSubData(GLuint buffer, GLintptr offset, GLsizeiptr length) { glInvalidateBufferSubData(buffer, offset, length); }
    inline void invalidateFramebuffer(GLenum target, GLsizei numAttachments, const GLenum *attachments) { glInvalidateFramebuffer(target, numAttachments, attachments); }
    inline void invalidateSubFramebuffer(GLenum target, GLsizei numAttachments, const GLenum *attachments, GLint x, GLint y, GLsizei width, GLsizei height) { glInvalidateSubFramebuffer(target, numAttachments, attachments, x, y, width, height); }
    inline void invalidateTexImage(GLuint texture, GLint level) { glInvalidateTexImage(texture, level); }
    inline void invalidateTexSubImage(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth) { glInvalidateTexSubImage(texture, level, xoffset, yoffset, zoffset, width, height, depth); }
    inline void multiDrawArraysIndirect(GLenum mode, const void *indirect, GLsizei drawcount, GLsizei stride) { glMultiDrawArraysIndirect(mode, indirect, drawcount, stride); }
    inline void multiDrawElementsIndirect(GLenum mode, GLenum type, const void *indirect, GLsizei drawcount, GLsizei stride) { glMultiDrawElementsIndirect(mode, type, indirect, drawcount, stride); }
    inline void objectLabel(GLenum identifier, GLuint name, GLsizei length, const GLchar *label) { glObjectLabel(identifier, name, length, label); }
    inline void objectPtrLabel(const void *ptr, GLsizei length, const GLchar *label) { glObjectPtrLabel(ptr, length, label); }
    inline void popDebugGroup(void) { glPopDebugGroup(); }
    inline void pushDebugGroup(GLenum source, GLuint id, GLsizei length, const GLchar *message) { glPushDebugGroup(source, id, length, message); }
    inline void shaderStorageBlockBinding(GLuint program, GLuint storageBlockIndex, GLuint storageBlockBinding) { glShaderStorageBlockBinding(program, storageBlockIndex, storageBlockBinding); }
    inline void texBufferRange(GLenum target, GLenum internalformat, GLuint buffer, GLintptr offset, GLsizeiptr size) { glTexBufferRange(target, internalformat, buffer, offset, size); }
    inline void texStorage2DMultisample(GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLboolean fixedsamplelocations) { glTexStorage2DMultisample(target, samples, internalformat, width, height, fixedsamplelocations); }
    inline void texStorage3DMultisample(GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLboolean fixedsamplelocations) { glTexStorage3DMultisample(target, samples, internalformat, width, height, depth, fixedsamplelocations); }
    inline void textureView(GLuint texture, GLenum target, GLuint origtexture, GLenum internalformat, GLuint minlevel, GLuint numlevels, GLuint minlayer, GLuint numlayers) { glTextureView(texture, target, origtexture, internalformat, minlevel, numlevels, minlayer, numlayers); }
    inline void vertexAttribBinding(GLuint attribindex, GLuint bindingindex) { glVertexAttribBinding(attribindex, bindingindex); }
    inline void vertexAttribFormat(GLuint attribindex, GLint size, GLenum type, GLboolean normalized, GLuint relativeoffset) { glVertexAttribFormat(attribindex, size, type, normalized, relativeoffset); }
    inline void vertexAttribIFormat(GLuint attribindex, GLint size, GLenum type, GLuint relativeoffset) { glVertexAttribIFormat(attribindex, size, type, relativeoffset); }
    inline void vertexAttribLFormat(GLuint attribindex, GLint size, GLenum type, GLuint relativeoffset) { glVertexAttribLFormat(attribindex, size, type, relativeoffset); }
    inline void vertexBindingDivisor(GLuint bindingindex, GLuint divisor) { glVertexBindingDivisor(bindingindex, divisor); }

    // GL_VERSION_4_4
    inline void bindBuffersBase(GLenum target, GLuint first, GLsizei count, const GLuint *buffers) { glBindBuffersBase(target, first, count, buffers); }
    inline void bindBuffersRange(GLenum target, GLuint first, GLsizei count, const GLuint *buffers, const GLintptr *offsets, const GLsizeiptr *sizes) { glBindBuffersRange(target, first, count, buffers, offsets, sizes); }
    inline void bindImageTextures(GLuint first, GLsizei count, const GLuint *textures) { glBindImageTextures(first, count, textures); }
    inline void bindSamplers(GLuint first, GLsizei count, const GLuint *samplers) { glBindSamplers(first, count, samplers); }
    inline void bindTextures(GLuint first, GLsizei count, const GLuint *textures) { glBindTextures(first, count, textures); }
    inline void bindVertexBuffers(GLuint first, GLsizei count, const GLuint *buffers, const GLintptr *offsets, const GLsizei *strides) { glBindVertexBuffers(first, count, buffers, offsets, strides); }
    inline void bufferStorage(GLenum target, GLsizeiptr size, const void *data, GLbitfield flags) { glBufferStorage(target, size, data, flags); }
    inline void clearTexImage(GLuint texture, GLint level, GLenum format, GLenum type, const void *data) { glClearTexImage(texture, level, format, type, data); }
    inline void clearTexSubImage(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const void *data) { glClearTexSubImage(texture, level, xoffset, yoffset, zoffset, width, height, depth, format, type, data); }

    // GL_VERSION_4_5
    inline void bindTextureUnit(GLuint unit, GLuint texture) { glBindTextureUnit(unit, texture); }
    inline void blitNamedFramebuffer(GLuint readFramebuffer, GLuint drawFramebuffer, GLint srcX0, GLint srcY0, GLint srcX1, GLint srcY1, GLint dstX0, GLint dstY0, GLint dstX1, GLint dstY1, GLbitfield mask, GLenum filter) { glBlitNamedFramebuffer(readFramebuffer, drawFramebuffer, srcX0, srcY0, srcX1, srcY1, dstX0, dstY0, dstX1, dstY1, mask, filter); }
    inline GLenum checkNamedFramebufferStatus(GLuint framebuffer, GLenum target) { return glCheckNamedFramebufferStatus(framebuffer, target); }
    inline void clearNamedBufferData(GLuint buffer, GLenum internalformat, GLenum format, GLenum type, const void *data) { glClearNamedBufferData(buffer, internalformat, format, type, data); }
    inline void clearNamedBufferSubData(GLuint buffer, GLenum internalformat, GLintptr offset, GLsizeiptr size, GLenum format, GLenum type, const void *data) { glClearNamedBufferSubData(buffer, internalformat, offset, size, format, type, data); }
    inline void clearNamedFramebufferfi(GLuint framebuffer, GLenum buffer, GLint drawbuffer, GLfloat depth, GLint stencil) { glClearNamedFramebufferfi(framebuffer, buffer, drawbuffer, depth, stencil); }
    inline void clearNamedFramebufferfv(GLuint framebuffer, GLenum buffer, GLint drawbuffer, const GLfloat *value) { glClearNamedFramebufferfv(framebuffer, buffer, drawbuffer, value); }
    inline void clearNamedFramebufferiv(GLuint framebuffer, GLenum buffer, GLint drawbuffer, const GLint *value) { glClearNamedFramebufferiv(framebuffer, buffer, drawbuffer, value); }
    inline void clearNamedFramebufferuiv(GLuint framebuffer, GLenum buffer, GLint drawbuffer, const GLuint *value) { glClearNamedFramebufferuiv(framebuffer, buffer, drawbuffer, value); }
    inline void clipControl(GLenum origin, GLenum depth) { glClipControl(origin, depth); }
    inline void compressedTextureSubImage1D(GLuint texture, GLint level, GLint xoffset, GLsizei width, GLenum format, GLsizei imageSize, const void *data) { glCompressedTextureSubImage1D(texture, level, xoffset, width, format, imageSize, data); }
    inline void compressedTextureSubImage2D(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLsizei imageSize, const void *data) { glCompressedTextureSubImage2D(texture, level, xoffset, yoffset, width, height, format, imageSize, data); }
    inline void compressedTextureSubImage3D(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLsizei imageSize, const void *data) { glCompressedTextureSubImage3D(texture, level, xoffset, yoffset, zoffset, width, height, depth, format, imageSize, data); }
    inline void copyNamedBufferSubData(GLuint readBuffer, GLuint writeBuffer, GLintptr readOffset, GLintptr writeOffset, GLsizeiptr size) { glCopyNamedBufferSubData(readBuffer, writeBuffer, readOffset, writeOffset, size); }
    inline void copyTextureSubImage1D(GLuint texture, GLint level, GLint xoffset, GLint x, GLint y, GLsizei width) { glCopyTextureSubImage1D(texture, level, xoffset, x, y, width); }
    inline void copyTextureSubImage2D(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint x, GLint y, GLsizei width, GLsizei height) { glCopyTextureSubImage2D(texture, level, xoffset, yoffset, x, y, width, height); }
    inline void copyTextureSubImage3D(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLint x, GLint y, GLsizei width, GLsizei height) { glCopyTextureSubImage3D(texture, level, xoffset, yoffset, zoffset, x, y, width, height); }
    inline void createBuffers(GLsizei n, GLuint *buffers) { glCreateBuffers(n, buffers); }
    inline void createFramebuffers(GLsizei n, GLuint *framebuffers) { glCreateFramebuffers(n, framebuffers); }
    inline void createProgramPipelines(GLsizei n, GLuint *pipelines) { glCreateProgramPipelines(n, pipelines); }
    inline void createQueries(GLenum target, GLsizei n, GLuint *ids) { glCreateQueries(target, n, ids); }
    inline void createRenderbuffers(GLsizei n, GLuint *renderbuffers) { glCreateRenderbuffers(n, renderbuffers); }
    inline void createSamplers(GLsizei n, GLuint *samplers) { glCreateSamplers(n, samplers); }
    inline void createTextures(GLenum target, GLsizei n, GLuint *textures) { glCreateTextures(target, n, textures); }
    inline void createTransformFeedbacks(GLsizei n, GLuint *ids) { glCreateTransformFeedbacks(n, ids); }
    inline void createVertexArrays(GLsizei n, GLuint *arrays) { glCreateVertexArrays(n, arrays); }
    inline void disableVertexArrayAttrib(GLuint vaobj, GLuint index) { glDisableVertexArrayAttrib(vaobj, index); }
    inline void enableVertexArrayAttrib(GLuint vaobj, GLuint index) { glEnableVertexArrayAttrib(vaobj, index); }
    inline void flushMappedNamedBufferRange(GLuint buffer, GLintptr offset, GLsizeiptr length) { glFlushMappedNamedBufferRange(buffer, offset, length); }
    inline void generateTextureMipmap(GLuint texture) { glGenerateTextureMipmap(texture); }
    inline void getCompressedTextureImage(GLuint texture, GLint level, GLsizei bufSize, void *pixels) { glGetCompressedTextureImage(texture, level, bufSize, pixels); }
    inline void getCompressedTextureSubImage(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLsizei bufSize, void *pixels) { glGetCompressedTextureSubImage(texture, level, xoffset, yoffset, zoffset, width, height, depth, bufSize, pixels); }
    inline GLenum getGraphicsResetStatus(void) { return glGetGraphicsResetStatus(); }
    inline void getNamedBufferParameteri64v(GLuint buffer, GLenum pname, GLint64 *params) { glGetNamedBufferParameteri64v(buffer, pname, params); }
    inline void getNamedBufferParameteriv(GLuint buffer, GLenum pname, GLint *params) { glGetNamedBufferParameteriv(buffer, pname, params); }
    inline void getNamedBufferPointerv(GLuint buffer, GLenum pname, void **params) { glGetNamedBufferPointerv(buffer, pname, params); }
    inline void getNamedBufferSubData(GLuint buffer, GLintptr offset, GLsizeiptr size, void *data) { glGetNamedBufferSubData(buffer, offset, size, data); }
    inline void getNamedFramebufferAttachmentParameteriv(GLuint framebuffer, GLenum attachment, GLenum pname, GLint *params) { glGetNamedFramebufferAttachmentParameteriv(framebuffer, attachment, pname, params); }
    inline void getNamedFramebufferParameteriv(GLuint framebuffer, GLenum pname, GLint *param) { glGetNamedFramebufferParameteriv(framebuffer, pname, param); }
    inline void getNamedRenderbufferParameteriv(GLuint renderbuffer, GLenum pname, GLint *params) { glGetNamedRenderbufferParameteriv(renderbuffer, pname, params); }
    inline void getQueryBufferObjecti64v(GLuint id, GLuint buffer, GLenum pname, GLintptr offset) { glGetQueryBufferObjecti64v(id, buffer, pname, offset); }
    inline void getQueryBufferObjectiv(GLuint id, GLuint buffer, GLenum pname, GLintptr offset) { glGetQueryBufferObjectiv(id, buffer, pname, offset); }
    inline void getQueryBufferObjectui64v(GLuint id, GLuint buffer, GLenum pname, GLintptr offset) { glGetQueryBufferObjectui64v(id, buffer, pname, offset); }
    inline void getQueryBufferObjectuiv(GLuint id, GLuint buffer, GLenum pname, GLintptr offset) { glGetQueryBufferObjectuiv(id, buffer, pname, offset); }
    inline void getTextureImage(GLuint texture, GLint level, GLenum format, GLenum type, GLsizei bufSize, void *pixels) { glGetTextureImage(texture, level, format, type, bufSize, pixels); }
    inline void getTextureLevelParameterfv(GLuint texture, GLint level, GLenum pname, GLfloat *params) { glGetTextureLevelParameterfv(texture, level, pname, params); }
    inline void getTextureLevelParameteriv(GLuint texture, GLint level, GLenum pname, GLint *params) { glGetTextureLevelParameteriv(texture, level, pname, params); }
    inline void getTextureParameterIiv(GLuint texture, GLenum pname, GLint *params) { glGetTextureParameterIiv(texture, pname, params); }
    inline void getTextureParameterIuiv(GLuint texture, GLenum pname, GLuint *params) { glGetTextureParameterIuiv(texture, pname, params); }
    inline void getTextureParameterfv(GLuint texture, GLenum pname, GLfloat *params) { glGetTextureParameterfv(texture, pname, params); }
    inline void getTextureParameteriv(GLuint texture, GLenum pname, GLint *params) { glGetTextureParameteriv(texture, pname, params); }
    inline void getTextureSubImage(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, GLsizei bufSize, void *pixels) { glGetTextureSubImage(texture, level, xoffset, yoffset, zoffset, width, height, depth, format, type, bufSize, pixels); }
    inline void getTransformFeedbacki64_v(GLuint xfb, GLenum pname, GLuint index, GLint64 *param) { glGetTransformFeedbacki64_v(xfb, pname, index, param); }
    inline void getTransformFeedbacki_v(GLuint xfb, GLenum pname, GLuint index, GLint *param) { glGetTransformFeedbacki_v(xfb, pname, index, param); }
    inline void getTransformFeedbackiv(GLuint xfb, GLenum pname, GLint *param) { glGetTransformFeedbackiv(xfb, pname, param); }
    inline void getVertexArrayIndexed64iv(GLuint vaobj, GLuint index, GLenum pname, GLint64 *param) { glGetVertexArrayIndexed64iv(vaobj, index, pname, param); }
    inline void getVertexArrayIndexediv(GLuint vaobj, GLuint index, GLenum pname, GLint *param) { glGetVertexArrayIndexediv(vaobj, index, pname, param); }
    inline void getVertexArrayiv(GLuint vaobj, GLenum pname, GLint *param) { glGetVertexArrayiv(vaobj, pname, param); }
    inline void getnCompressedTexImage(GLenum target, GLint lod, GLsizei bufSize, void *pixels) { glGetnCompressedTexImage(target, lod, bufSize, pixels); }
    inline void getnTexImage(GLenum target, GLint level, GLenum format, GLenum type, GLsizei bufSize, void *pixels) { glGetnTexImage(target, level, format, type, bufSize, pixels); }
    inline void getnUniformdv(GLuint program, GLint location, GLsizei bufSize, GLdouble *params) { glGetnUniformdv(program, location, bufSize, params); }
    inline void getnUniformfv(GLuint program, GLint location, GLsizei bufSize, GLfloat *params) { glGetnUniformfv(program, location, bufSize, params); }
    inline void getnUniformiv(GLuint program, GLint location, GLsizei bufSize, GLint *params) { glGetnUniformiv(program, location, bufSize, params); }
    inline void getnUniformuiv(GLuint program, GLint location, GLsizei bufSize, GLuint *params) { glGetnUniformuiv(program, location, bufSize, params); }
    inline void invalidateNamedFramebufferData(GLuint framebuffer, GLsizei numAttachments, const GLenum *attachments) { glInvalidateNamedFramebufferData(framebuffer, numAttachments, attachments); }
    inline void invalidateNamedFramebufferSubData(GLuint framebuffer, GLsizei numAttachments, const GLenum *attachments, GLint x, GLint y, GLsizei width, GLsizei height) { glInvalidateNamedFramebufferSubData(framebuffer, numAttachments, attachments, x, y, width, height); }
    inline void *mapNamedBuffer(GLuint buffer, GLenum access) { return glMapNamedBuffer(buffer, access); }
    inline void *mapNamedBufferRange(GLuint buffer, GLintptr offset, GLsizeiptr length, GLbitfield access) { return glMapNamedBufferRange(buffer, offset, length, access); }
    inline void memoryBarrierByRegion(GLbitfield barriers) { glMemoryBarrierByRegion(barriers); }
    inline void namedBufferData(GLuint buffer, GLsizeiptr size, const void *data, GLenum usage) { glNamedBufferData(buffer, size, data, usage); }
    inline void namedBufferStorage(GLuint buffer, GLsizeiptr size, const void *data, GLbitfield flags) { glNamedBufferStorage(buffer, size, data, flags); }
    inline void namedBufferSubData(GLuint buffer, GLintptr offset, GLsizeiptr size, const void *data) { glNamedBufferSubData(buffer, offset, size, data); }
    inline void namedFramebufferDrawBuffer(GLuint framebuffer, GLenum buf) { glNamedFramebufferDrawBuffer(framebuffer, buf); }
    inline void namedFramebufferDrawBuffers(GLuint framebuffer, GLsizei n, const GLenum *bufs) { glNamedFramebufferDrawBuffers(framebuffer, n, bufs); }
    inline void namedFramebufferParameteri(GLuint framebuffer, GLenum pname, GLint param) { glNamedFramebufferParameteri(framebuffer, pname, param); }
    inline void namedFramebufferReadBuffer(GLuint framebuffer, GLenum src) { glNamedFramebufferReadBuffer(framebuffer, src); }
    inline void namedFramebufferRenderbuffer(GLuint framebuffer, GLenum attachment, GLenum renderbuffertarget, GLuint renderbuffer) { glNamedFramebufferRenderbuffer(framebuffer, attachment, renderbuffertarget, renderbuffer); }
    inline void namedFramebufferTexture(GLuint framebuffer, GLenum attachment, GLuint texture, GLint level) { glNamedFramebufferTexture(framebuffer, attachment, texture, level); }
    inline void namedFramebufferTextureLayer(GLuint framebuffer, GLenum attachment, GLuint texture, GLint level, GLint layer) { glNamedFramebufferTextureLayer(framebuffer, attachment, texture, level, layer); }
    inline void namedRenderbufferStorage(GLuint renderbuffer, GLenum internalformat, GLsizei width, GLsizei height) { glNamedRenderbufferStorage(renderbuffer, internalformat, width, height); }
    inline void namedRenderbufferStorageMultisample(GLuint renderbuffer, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height) { glNamedRenderbufferStorageMultisample(renderbuffer, samples, internalformat, width, height); }
    inline void readnPixels(GLint x, GLint y, GLsizei width, GLsizei height, GLenum format, GLenum type, GLsizei bufSize, void *data) { glReadnPixels(x, y, width, height, format, type, bufSize, data); }
    inline void textureBarrier(void) { glTextureBarrier(); }
    inline void textureBuffer(GLuint texture, GLenum internalformat, GLuint buffer) { glTextureBuffer(texture, internalformat, buffer); }
    inline void textureBufferRange(GLuint texture, GLenum internalformat, GLuint buffer, GLintptr offset, GLsizeiptr size) { glTextureBufferRange(texture, internalformat, buffer, offset, size); }
    inline void textureParameterIiv(GLuint texture, GLenum pname, const GLint *params) { glTextureParameterIiv(texture, pname, params); }
    inline void textureParameterIuiv(GLuint texture, GLenum pname, const GLuint *params) { glTextureParameterIuiv(texture, pname, params); }
    inline void textureParameterf(GLuint texture, GLenum pname, GLfloat param) { glTextureParameterf(texture, pname, param); }
    inline void textureParameterfv(GLuint texture, GLenum pname, const GLfloat *param) { glTextureParameterfv(texture, pname, param); }
    inline void textureParameteri(GLuint texture, GLenum pname, GLint param) { glTextureParameteri(texture, pname, param); }
    inline void textureParameteriv(GLuint texture, GLenum pname, const GLint *param) { glTextureParameteriv(texture, pname, param); }
    inline void textureStorage1D(GLuint texture, GLsizei levels, GLenum internalformat, GLsizei width) { glTextureStorage1D(texture, levels, internalformat, width); }
    inline void textureStorage2D(GLuint texture, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height) { glTextureStorage2D(texture, levels, internalformat, width, height); }
    inline void textureStorage2DMultisample(GLuint texture, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLboolean fixedsamplelocations) { glTextureStorage2DMultisample(texture, samples, internalformat, width, height, fixedsamplelocations); }
    inline void textureStorage3D(GLuint texture, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth) { glTextureStorage3D(texture, levels, internalformat, width, height, depth); }
    inline void textureStorage3DMultisample(GLuint texture, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLboolean fixedsamplelocations) { glTextureStorage3DMultisample(texture, samples, internalformat, width, height, depth, fixedsamplelocations); }
    inline void textureSubImage1D(GLuint texture, GLint level, GLint xoffset, GLsizei width, GLenum format, GLenum type, const void *pixels) { glTextureSubImage1D(texture, level, xoffset, width, format, type, pixels); }
    inline void textureSubImage2D(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLenum type, const void *pixels) { glTextureSubImage2D(texture, level, xoffset, yoffset, width, height, format, type, pixels); }
    inline void textureSubImage3D(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const void *pixels) { glTextureSubImage3D(texture, level, xoffset, yoffset, zoffset, width, height, depth, format, type, pixels); }
    inline void transformFeedbackBufferBase(GLuint xfb, GLuint index, GLuint buffer) { glTransformFeedbackBufferBase(xfb, index, buffer); }
    inline void transformFeedbackBufferRange(GLuint xfb, GLuint index, GLuint buffer, GLintptr offset, GLsizeiptr size) { glTransformFeedbackBufferRange(xfb, index, buffer, offset, size); }
    inline GLboolean unmapNamedBuffer(GLuint buffer) { return glUnmapNamedBuffer(buffer); }
    inline void vertexArrayAttribBinding(GLuint vaobj, GLuint attribindex, GLuint bindingindex) { glVertexArrayAttribBinding(vaobj, attribindex, bindingindex); }
    inline void vertexArrayAttribFormat(GLuint vaobj, GLuint attribindex, GLint size, GLenum type, GLboolean normalized, GLuint relativeoffset) { glVertexArrayAttribFormat(vaobj, attribindex, size, type, normalized, relativeoffset); }
    inline void vertexArrayAttribIFormat(GLuint vaobj, GLuint attribindex, GLint size, GLenum type, GLuint relativeoffset) { glVertexArrayAttribIFormat(vaobj, attribindex, size, type, relativeoffset); }
    inline void vertexArrayAttribLFormat(GLuint vaobj, GLuint attribindex, GLint size, GLenum type, GLuint relativeoffset) { glVertexArrayAttribLFormat(vaobj, attribindex, size, type, relativeoffset); }
    inline void vertexArrayBindingDivisor(GLuint vaobj, GLuint bindingindex, GLuint divisor) { glVertexArrayBindingDivisor(vaobj, bindingindex, divisor); }
    inline void vertexArrayElementBuffer(GLuint vaobj, GLuint buffer) { glVertexArrayElementBuffer(vaobj, buffer); }
    inline void vertexArrayVertexBuffer(GLuint vaobj, GLuint bindingindex, GLuint buffer, GLintptr offset, GLsizei stride) { glVertexArrayVertexBuffer(vaobj, bindingindex, buffer, offset, stride); }
    inline void vertexArrayVertexBuffers(GLuint vaobj, GLuint first, GLsizei count, const GLuint *buffers, const GLintptr *offsets, const GLsizei *strides) { glVertexArrayVertexBuffers(vaobj, first, count, buffers, offsets, strides); }
};
//------------------------------------------------------------------------------
inline void COpenGL::makeCurrent()
{
}
//------------------------------------------------------------------------------
#endif // OPENGL_H
