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
    NOpenGLProc::TCopyTexSubImage3D glCopyTexSubImage3D;
    NOpenGLProc::TDrawRangeElements glDrawRangeElements;
    NOpenGLProc::TTexImage3D glTexImage3D;
    NOpenGLProc::TTexSubImage3D glTexSubImage3D;

    // GL_VERSION_1_3
    NOpenGLProc::TActiveTexture glActiveTexture;
    NOpenGLProc::TCompressedTexImage1D glCompressedTexImage1D;
    NOpenGLProc::TCompressedTexImage2D glCompressedTexImage2D;
    NOpenGLProc::TCompressedTexImage3D glCompressedTexImage3D;
    NOpenGLProc::TCompressedTexSubImage1D glCompressedTexSubImage1D;
    NOpenGLProc::TCompressedTexSubImage2D glCompressedTexSubImage2D;
    NOpenGLProc::TCompressedTexSubImage3D glCompressedTexSubImage3D;
    NOpenGLProc::TGetCompressedTexImage glGetCompressedTexImage;
    NOpenGLProc::TSampleCoverage glSampleCoverage;

    // GL_VERSION_1_4
    NOpenGLProc::TBlendColor glBlendColor;
    NOpenGLProc::TBlendEquation glBlendEquation;
    NOpenGLProc::TBlendFuncSeparate glBlendFuncSeparate;
    NOpenGLProc::TMultiDrawArrays glMultiDrawArrays;
    NOpenGLProc::TMultiDrawElements glMultiDrawElements;
    NOpenGLProc::TPointParameterf glPointParameterf;
    NOpenGLProc::TPointParameterfv glPointParameterfv;
    NOpenGLProc::TPointParameteri glPointParameteri;
    NOpenGLProc::TPointParameteriv glPointParameteriv;

    // GL_VERSION_1_5
    NOpenGLProc::TBeginQuery glBeginQuery;
    NOpenGLProc::TBindBuffer glBindBuffer;
    NOpenGLProc::TBufferData glBufferData;
    NOpenGLProc::TBufferSubData glBufferSubData;
    NOpenGLProc::TDeleteBuffers glDeleteBuffers;
    NOpenGLProc::TDeleteQueries glDeleteQueries;
    NOpenGLProc::TEndQuery glEndQuery;
    NOpenGLProc::TGenBuffers glGenBuffers;
    NOpenGLProc::TGenQueries glGenQueries;
    NOpenGLProc::TGetBufferParameteriv glGetBufferParameteriv;
    NOpenGLProc::TGetBufferPointerv glGetBufferPointerv;
    NOpenGLProc::TGetBufferSubData glGetBufferSubData;
    NOpenGLProc::TGetQueryObjectiv glGetQueryObjectiv;
    NOpenGLProc::TGetQueryObjectuiv glGetQueryObjectuiv;
    NOpenGLProc::TGetQueryiv glGetQueryiv;
    NOpenGLProc::TIsBuffer glIsBuffer;
    NOpenGLProc::TIsQuery glIsQuery;
    NOpenGLProc::TMapBuffer glMapBuffer;
    NOpenGLProc::TUnmapBuffer glUnmapBuffer;

    // GL_VERSION_2_0
    NOpenGLProc::TAttachShader glAttachShader;
    NOpenGLProc::TBindAttribLocation glBindAttribLocation;
    NOpenGLProc::TBlendEquationSeparate glBlendEquationSeparate;
    NOpenGLProc::TCompileShader glCompileShader;
    NOpenGLProc::TCreateProgram glCreateProgram;
    NOpenGLProc::TCreateShader glCreateShader;
    NOpenGLProc::TDeleteProgram glDeleteProgram;
    NOpenGLProc::TDeleteShader glDeleteShader;
    NOpenGLProc::TDetachShader glDetachShader;
    NOpenGLProc::TDisableVertexAttribArray glDisableVertexAttribArray;
    NOpenGLProc::TDrawBuffers glDrawBuffers;
    NOpenGLProc::TEnableVertexAttribArray glEnableVertexAttribArray;
    NOpenGLProc::TGetActiveAttrib glGetActiveAttrib;
    NOpenGLProc::TGetActiveUniform glGetActiveUniform;
    NOpenGLProc::TGetAttachedShaders glGetAttachedShaders;
    NOpenGLProc::TGetAttribLocation glGetAttribLocation;
    NOpenGLProc::TGetProgramInfoLog glGetProgramInfoLog;
    NOpenGLProc::TGetProgramiv glGetProgramiv;
    NOpenGLProc::TGetShaderInfoLog glGetShaderInfoLog;
    NOpenGLProc::TGetShaderSource glGetShaderSource;
    NOpenGLProc::TGetShaderiv glGetShaderiv;
    NOpenGLProc::TGetUniformLocation glGetUniformLocation;
    NOpenGLProc::TGetUniformfv glGetUniformfv;
    NOpenGLProc::TGetUniformiv glGetUniformiv;
    NOpenGLProc::TGetVertexAttribPointerv glGetVertexAttribPointerv;
    NOpenGLProc::TGetVertexAttribdv glGetVertexAttribdv;
    NOpenGLProc::TGetVertexAttribfv glGetVertexAttribfv;
    NOpenGLProc::TGetVertexAttribiv glGetVertexAttribiv;
    NOpenGLProc::TIsProgram glIsProgram;
    NOpenGLProc::TIsShader glIsShader;
    NOpenGLProc::TLinkProgram glLinkProgram;
    NOpenGLProc::TShaderSource glShaderSource;
    NOpenGLProc::TStencilFuncSeparate glStencilFuncSeparate;
    NOpenGLProc::TStencilMaskSeparate glStencilMaskSeparate;
    NOpenGLProc::TStencilOpSeparate glStencilOpSeparate;
    NOpenGLProc::TUniform1f glUniform1f;
    NOpenGLProc::TUniform1fv glUniform1fv;
    NOpenGLProc::TUniform1i glUniform1i;
    NOpenGLProc::TUniform1iv glUniform1iv;
    NOpenGLProc::TUniform2f glUniform2f;
    NOpenGLProc::TUniform2fv glUniform2fv;
    NOpenGLProc::TUniform2i glUniform2i;
    NOpenGLProc::TUniform2iv glUniform2iv;
    NOpenGLProc::TUniform3f glUniform3f;
    NOpenGLProc::TUniform3fv glUniform3fv;
    NOpenGLProc::TUniform3i glUniform3i;
    NOpenGLProc::TUniform3iv glUniform3iv;
    NOpenGLProc::TUniform4f glUniform4f;
    NOpenGLProc::TUniform4fv glUniform4fv;
    NOpenGLProc::TUniform4i glUniform4i;
    NOpenGLProc::TUniform4iv glUniform4iv;
    NOpenGLProc::TUniformMatrix2fv glUniformMatrix2fv;
    NOpenGLProc::TUniformMatrix3fv glUniformMatrix3fv;
    NOpenGLProc::TUniformMatrix4fv glUniformMatrix4fv;
    NOpenGLProc::TUseProgram glUseProgram;
    NOpenGLProc::TValidateProgram glValidateProgram;
    NOpenGLProc::TVertexAttrib1d glVertexAttrib1d;
    NOpenGLProc::TVertexAttrib1dv glVertexAttrib1dv;
    NOpenGLProc::TVertexAttrib1f glVertexAttrib1f;
    NOpenGLProc::TVertexAttrib1fv glVertexAttrib1fv;
    NOpenGLProc::TVertexAttrib1s glVertexAttrib1s;
    NOpenGLProc::TVertexAttrib1sv glVertexAttrib1sv;
    NOpenGLProc::TVertexAttrib2d glVertexAttrib2d;
    NOpenGLProc::TVertexAttrib2dv glVertexAttrib2dv;
    NOpenGLProc::TVertexAttrib2f glVertexAttrib2f;
    NOpenGLProc::TVertexAttrib2fv glVertexAttrib2fv;
    NOpenGLProc::TVertexAttrib2s glVertexAttrib2s;
    NOpenGLProc::TVertexAttrib2sv glVertexAttrib2sv;
    NOpenGLProc::TVertexAttrib3d glVertexAttrib3d;
    NOpenGLProc::TVertexAttrib3dv glVertexAttrib3dv;
    NOpenGLProc::TVertexAttrib3f glVertexAttrib3f;
    NOpenGLProc::TVertexAttrib3fv glVertexAttrib3fv;
    NOpenGLProc::TVertexAttrib3s glVertexAttrib3s;
    NOpenGLProc::TVertexAttrib3sv glVertexAttrib3sv;
    NOpenGLProc::TVertexAttrib4Nbv glVertexAttrib4Nbv;
    NOpenGLProc::TVertexAttrib4Niv glVertexAttrib4Niv;
    NOpenGLProc::TVertexAttrib4Nsv glVertexAttrib4Nsv;
    NOpenGLProc::TVertexAttrib4Nub glVertexAttrib4Nub;
    NOpenGLProc::TVertexAttrib4Nubv glVertexAttrib4Nubv;
    NOpenGLProc::TVertexAttrib4Nuiv glVertexAttrib4Nuiv;
    NOpenGLProc::TVertexAttrib4Nusv glVertexAttrib4Nusv;
    NOpenGLProc::TVertexAttrib4bv glVertexAttrib4bv;
    NOpenGLProc::TVertexAttrib4d glVertexAttrib4d;
    NOpenGLProc::TVertexAttrib4dv glVertexAttrib4dv;
    NOpenGLProc::TVertexAttrib4f glVertexAttrib4f;
    NOpenGLProc::TVertexAttrib4fv glVertexAttrib4fv;
    NOpenGLProc::TVertexAttrib4iv glVertexAttrib4iv;
    NOpenGLProc::TVertexAttrib4s glVertexAttrib4s;
    NOpenGLProc::TVertexAttrib4sv glVertexAttrib4sv;
    NOpenGLProc::TVertexAttrib4ubv glVertexAttrib4ubv;
    NOpenGLProc::TVertexAttrib4uiv glVertexAttrib4uiv;
    NOpenGLProc::TVertexAttrib4usv glVertexAttrib4usv;
    NOpenGLProc::TVertexAttribPointer glVertexAttribPointer;

    // GL_VERSION_2_1
    NOpenGLProc::TUniformMatrix2x3fv glUniformMatrix2x3fv;
    NOpenGLProc::TUniformMatrix2x4fv glUniformMatrix2x4fv;
    NOpenGLProc::TUniformMatrix3x2fv glUniformMatrix3x2fv;
    NOpenGLProc::TUniformMatrix3x4fv glUniformMatrix3x4fv;
    NOpenGLProc::TUniformMatrix4x2fv glUniformMatrix4x2fv;
    NOpenGLProc::TUniformMatrix4x3fv glUniformMatrix4x3fv;

    // GL_VERSION_3_0
    NOpenGLProc::TBeginConditionalRender glBeginConditionalRender;
    NOpenGLProc::TBeginTransformFeedback glBeginTransformFeedback;
    NOpenGLProc::TBindBufferBase glBindBufferBase;
    NOpenGLProc::TBindBufferRange glBindBufferRange;
    NOpenGLProc::TBindFragDataLocation glBindFragDataLocation;
    NOpenGLProc::TBindFramebuffer glBindFramebuffer;
    NOpenGLProc::TBindRenderbuffer glBindRenderbuffer;
    NOpenGLProc::TBindVertexArray glBindVertexArray;
    NOpenGLProc::TBlitFramebuffer glBlitFramebuffer;
    NOpenGLProc::TCheckFramebufferStatus glCheckFramebufferStatus;
    NOpenGLProc::TClampColor glClampColor;
    NOpenGLProc::TClearBufferfi glClearBufferfi;
    NOpenGLProc::TClearBufferfv glClearBufferfv;
    NOpenGLProc::TClearBufferiv glClearBufferiv;
    NOpenGLProc::TClearBufferuiv glClearBufferuiv;
    NOpenGLProc::TColorMaski glColorMaski;
    NOpenGLProc::TDeleteFramebuffers glDeleteFramebuffers;
    NOpenGLProc::TDeleteRenderbuffers glDeleteRenderbuffers;
    NOpenGLProc::TDeleteVertexArrays glDeleteVertexArrays;
    NOpenGLProc::TDisablei glDisablei;
    NOpenGLProc::TEnablei glEnablei;
    NOpenGLProc::TEndConditionalRender glEndConditionalRender;
    NOpenGLProc::TEndTransformFeedback glEndTransformFeedback;
    NOpenGLProc::TFlushMappedBufferRange glFlushMappedBufferRange;
    NOpenGLProc::TFramebufferRenderbuffer glFramebufferRenderbuffer;
    NOpenGLProc::TFramebufferTexture1D glFramebufferTexture1D;
    NOpenGLProc::TFramebufferTexture2D glFramebufferTexture2D;
    NOpenGLProc::TFramebufferTexture3D glFramebufferTexture3D;
    NOpenGLProc::TFramebufferTextureLayer glFramebufferTextureLayer;
    NOpenGLProc::TGenFramebuffers glGenFramebuffers;
    NOpenGLProc::TGenRenderbuffers glGenRenderbuffers;
    NOpenGLProc::TGenVertexArrays glGenVertexArrays;
    NOpenGLProc::TGenerateMipmap glGenerateMipmap;
    NOpenGLProc::TGetBooleani_v glGetBooleani_v;
    NOpenGLProc::TGetFragDataLocation glGetFragDataLocation;
    NOpenGLProc::TGetFramebufferAttachmentParameteriv glGetFramebufferAttachmentParameteriv;
    NOpenGLProc::TGetIntegeri_v glGetIntegeri_v;
    NOpenGLProc::TGetRenderbufferParameteriv glGetRenderbufferParameteriv;
    NOpenGLProc::TGetStringi glGetStringi;
    NOpenGLProc::TGetTexParameterIiv glGetTexParameterIiv;
    NOpenGLProc::TGetTexParameterIuiv glGetTexParameterIuiv;
    NOpenGLProc::TGetTransformFeedbackVarying glGetTransformFeedbackVarying;
    NOpenGLProc::TGetUniformuiv glGetUniformuiv;
    NOpenGLProc::TGetVertexAttribIiv glGetVertexAttribIiv;
    NOpenGLProc::TGetVertexAttribIuiv glGetVertexAttribIuiv;
    NOpenGLProc::TIsEnabledi glIsEnabledi;
    NOpenGLProc::TIsFramebuffer glIsFramebuffer;
    NOpenGLProc::TIsRenderbuffer glIsRenderbuffer;
    NOpenGLProc::TIsVertexArray glIsVertexArray;
    NOpenGLProc::TMapBufferRange glMapBufferRange;
    NOpenGLProc::TRenderbufferStorage glRenderbufferStorage;
    NOpenGLProc::TRenderbufferStorageMultisample glRenderbufferStorageMultisample;
    NOpenGLProc::TTexParameterIiv glTexParameterIiv;
    NOpenGLProc::TTexParameterIuiv glTexParameterIuiv;
    NOpenGLProc::TTransformFeedbackVaryings glTransformFeedbackVaryings;
    NOpenGLProc::TUniform1ui glUniform1ui;
    NOpenGLProc::TUniform1uiv glUniform1uiv;
    NOpenGLProc::TUniform2ui glUniform2ui;
    NOpenGLProc::TUniform2uiv glUniform2uiv;
    NOpenGLProc::TUniform3ui glUniform3ui;
    NOpenGLProc::TUniform3uiv glUniform3uiv;
    NOpenGLProc::TUniform4ui glUniform4ui;
    NOpenGLProc::TUniform4uiv glUniform4uiv;
    NOpenGLProc::TVertexAttribI1i glVertexAttribI1i;
    NOpenGLProc::TVertexAttribI1iv glVertexAttribI1iv;
    NOpenGLProc::TVertexAttribI1ui glVertexAttribI1ui;
    NOpenGLProc::TVertexAttribI1uiv glVertexAttribI1uiv;
    NOpenGLProc::TVertexAttribI2i glVertexAttribI2i;
    NOpenGLProc::TVertexAttribI2iv glVertexAttribI2iv;
    NOpenGLProc::TVertexAttribI2ui glVertexAttribI2ui;
    NOpenGLProc::TVertexAttribI2uiv glVertexAttribI2uiv;
    NOpenGLProc::TVertexAttribI3i glVertexAttribI3i;
    NOpenGLProc::TVertexAttribI3iv glVertexAttribI3iv;
    NOpenGLProc::TVertexAttribI3ui glVertexAttribI3ui;
    NOpenGLProc::TVertexAttribI3uiv glVertexAttribI3uiv;
    NOpenGLProc::TVertexAttribI4bv glVertexAttribI4bv;
    NOpenGLProc::TVertexAttribI4i glVertexAttribI4i;
    NOpenGLProc::TVertexAttribI4iv glVertexAttribI4iv;
    NOpenGLProc::TVertexAttribI4sv glVertexAttribI4sv;
    NOpenGLProc::TVertexAttribI4ubv glVertexAttribI4ubv;
    NOpenGLProc::TVertexAttribI4ui glVertexAttribI4ui;
    NOpenGLProc::TVertexAttribI4uiv glVertexAttribI4uiv;
    NOpenGLProc::TVertexAttribI4usv glVertexAttribI4usv;
    NOpenGLProc::TVertexAttribIPointer glVertexAttribIPointer;

    // GL_VERSION_3_1
    NOpenGLProc::TCopyBufferSubData glCopyBufferSubData;
    NOpenGLProc::TDrawArraysInstanced glDrawArraysInstanced;
    NOpenGLProc::TDrawElementsInstanced glDrawElementsInstanced;
    NOpenGLProc::TGetActiveUniformBlockName glGetActiveUniformBlockName;
    NOpenGLProc::TGetActiveUniformBlockiv glGetActiveUniformBlockiv;
    NOpenGLProc::TGetActiveUniformName glGetActiveUniformName;
    NOpenGLProc::TGetActiveUniformsiv glGetActiveUniformsiv;
    NOpenGLProc::TGetUniformBlockIndex glGetUniformBlockIndex;
    NOpenGLProc::TGetUniformIndices glGetUniformIndices;
    NOpenGLProc::TPrimitiveRestartIndex glPrimitiveRestartIndex;
    NOpenGLProc::TTexBuffer glTexBuffer;
    NOpenGLProc::TUniformBlockBinding glUniformBlockBinding;

    // GL_VERSION_3_2
    NOpenGLProc::TClientWaitSync glClientWaitSync;
    NOpenGLProc::TDeleteSync glDeleteSync;
    NOpenGLProc::TDrawElementsBaseVertex glDrawElementsBaseVertex;
    NOpenGLProc::TDrawElementsInstancedBaseVertex glDrawElementsInstancedBaseVertex;
    NOpenGLProc::TDrawRangeElementsBaseVertex glDrawRangeElementsBaseVertex;
    NOpenGLProc::TFenceSync glFenceSync;
    NOpenGLProc::TFramebufferTexture glFramebufferTexture;
    NOpenGLProc::TGetBufferParameteri64v glGetBufferParameteri64v;
    NOpenGLProc::TGetInteger64i_v glGetInteger64i_v;
    NOpenGLProc::TGetInteger64v glGetInteger64v;
    NOpenGLProc::TGetMultisamplefv glGetMultisamplefv;
    NOpenGLProc::TGetSynciv glGetSynciv;
    NOpenGLProc::TIsSync glIsSync;
    NOpenGLProc::TMultiDrawElementsBaseVertex glMultiDrawElementsBaseVertex;
    NOpenGLProc::TProvokingVertex glProvokingVertex;
    NOpenGLProc::TSampleMaski glSampleMaski;
    NOpenGLProc::TTexImage2DMultisample glTexImage2DMultisample;
    NOpenGLProc::TTexImage3DMultisample glTexImage3DMultisample;
    NOpenGLProc::TWaitSync glWaitSync;

    // GL_VERSION_3_3
    NOpenGLProc::TBindFragDataLocationIndexed glBindFragDataLocationIndexed;
    NOpenGLProc::TBindSampler glBindSampler;
    NOpenGLProc::TDeleteSamplers glDeleteSamplers;
    NOpenGLProc::TGenSamplers glGenSamplers;
    NOpenGLProc::TGetFragDataIndex glGetFragDataIndex;
    NOpenGLProc::TGetQueryObjecti64v glGetQueryObjecti64v;
    NOpenGLProc::TGetQueryObjectui64v glGetQueryObjectui64v;
    NOpenGLProc::TGetSamplerParameterIiv glGetSamplerParameterIiv;
    NOpenGLProc::TGetSamplerParameterIuiv glGetSamplerParameterIuiv;
    NOpenGLProc::TGetSamplerParameterfv glGetSamplerParameterfv;
    NOpenGLProc::TGetSamplerParameteriv glGetSamplerParameteriv;
    NOpenGLProc::TIsSampler glIsSampler;
    NOpenGLProc::TQueryCounter glQueryCounter;
    NOpenGLProc::TSamplerParameterIiv glSamplerParameterIiv;
    NOpenGLProc::TSamplerParameterIuiv glSamplerParameterIuiv;
    NOpenGLProc::TSamplerParameterf glSamplerParameterf;
    NOpenGLProc::TSamplerParameterfv glSamplerParameterfv;
    NOpenGLProc::TSamplerParameteri glSamplerParameteri;
    NOpenGLProc::TSamplerParameteriv glSamplerParameteriv;
    NOpenGLProc::TVertexAttribDivisor glVertexAttribDivisor;
    NOpenGLProc::TVertexAttribP1ui glVertexAttribP1ui;
    NOpenGLProc::TVertexAttribP1uiv glVertexAttribP1uiv;
    NOpenGLProc::TVertexAttribP2ui glVertexAttribP2ui;
    NOpenGLProc::TVertexAttribP2uiv glVertexAttribP2uiv;
    NOpenGLProc::TVertexAttribP3ui glVertexAttribP3ui;
    NOpenGLProc::TVertexAttribP3uiv glVertexAttribP3uiv;
    NOpenGLProc::TVertexAttribP4ui glVertexAttribP4ui;
    NOpenGLProc::TVertexAttribP4uiv glVertexAttribP4uiv;

    // GL_VERSION_4_0
    NOpenGLProc::TBeginQueryIndexed glBeginQueryIndexed;
    NOpenGLProc::TBindTransformFeedback glBindTransformFeedback;
    NOpenGLProc::TBlendEquationSeparatei glBlendEquationSeparatei;
    NOpenGLProc::TBlendEquationi glBlendEquationi;
    NOpenGLProc::TBlendFuncSeparatei glBlendFuncSeparatei;
    NOpenGLProc::TBlendFunci glBlendFunci;
    NOpenGLProc::TDeleteTransformFeedbacks glDeleteTransformFeedbacks;
    NOpenGLProc::TDrawArraysIndirect glDrawArraysIndirect;
    NOpenGLProc::TDrawElementsIndirect glDrawElementsIndirect;
    NOpenGLProc::TDrawTransformFeedback glDrawTransformFeedback;
    NOpenGLProc::TDrawTransformFeedbackStream glDrawTransformFeedbackStream;
    NOpenGLProc::TEndQueryIndexed glEndQueryIndexed;
    NOpenGLProc::TGenTransformFeedbacks glGenTransformFeedbacks;
    NOpenGLProc::TGetActiveSubroutineName glGetActiveSubroutineName;
    NOpenGLProc::TGetActiveSubroutineUniformName glGetActiveSubroutineUniformName;
    NOpenGLProc::TGetActiveSubroutineUniformiv glGetActiveSubroutineUniformiv;
    NOpenGLProc::TGetProgramStageiv glGetProgramStageiv;
    NOpenGLProc::TGetQueryIndexediv glGetQueryIndexediv;
    NOpenGLProc::TGetSubroutineIndex glGetSubroutineIndex;
    NOpenGLProc::TGetSubroutineUniformLocation glGetSubroutineUniformLocation;
    NOpenGLProc::TGetUniformSubroutineuiv glGetUniformSubroutineuiv;
    NOpenGLProc::TGetUniformdv glGetUniformdv;
    NOpenGLProc::TIsTransformFeedback glIsTransformFeedback;
    NOpenGLProc::TMinSampleShading glMinSampleShading;
    NOpenGLProc::TPatchParameterfv glPatchParameterfv;
    NOpenGLProc::TPatchParameteri glPatchParameteri;
    NOpenGLProc::TPauseTransformFeedback glPauseTransformFeedback;
    NOpenGLProc::TResumeTransformFeedback glResumeTransformFeedback;
    NOpenGLProc::TUniform1d glUniform1d;
    NOpenGLProc::TUniform1dv glUniform1dv;
    NOpenGLProc::TUniform2d glUniform2d;
    NOpenGLProc::TUniform2dv glUniform2dv;
    NOpenGLProc::TUniform3d glUniform3d;
    NOpenGLProc::TUniform3dv glUniform3dv;
    NOpenGLProc::TUniform4d glUniform4d;
    NOpenGLProc::TUniform4dv glUniform4dv;
    NOpenGLProc::TUniformMatrix2dv glUniformMatrix2dv;
    NOpenGLProc::TUniformMatrix2x3dv glUniformMatrix2x3dv;
    NOpenGLProc::TUniformMatrix2x4dv glUniformMatrix2x4dv;
    NOpenGLProc::TUniformMatrix3dv glUniformMatrix3dv;
    NOpenGLProc::TUniformMatrix3x2dv glUniformMatrix3x2dv;
    NOpenGLProc::TUniformMatrix3x4dv glUniformMatrix3x4dv;
    NOpenGLProc::TUniformMatrix4dv glUniformMatrix4dv;
    NOpenGLProc::TUniformMatrix4x2dv glUniformMatrix4x2dv;
    NOpenGLProc::TUniformMatrix4x3dv glUniformMatrix4x3dv;
    NOpenGLProc::TUniformSubroutinesuiv glUniformSubroutinesuiv;

    // GL_VERSION_4_1
    NOpenGLProc::TActiveShaderProgram glActiveShaderProgram;
    NOpenGLProc::TBindProgramPipeline glBindProgramPipeline;
    NOpenGLProc::TClearDepthf glClearDepthf;
    NOpenGLProc::TCreateShaderProgramv glCreateShaderProgramv;
    NOpenGLProc::TDeleteProgramPipelines glDeleteProgramPipelines;
    NOpenGLProc::TDepthRangeArrayv glDepthRangeArrayv;
    NOpenGLProc::TDepthRangeIndexed glDepthRangeIndexed;
    NOpenGLProc::TDepthRangef glDepthRangef;
    NOpenGLProc::TGenProgramPipelines glGenProgramPipelines;
    NOpenGLProc::TGetDoublei_v glGetDoublei_v;
    NOpenGLProc::TGetFloati_v glGetFloati_v;
    NOpenGLProc::TGetProgramBinary glGetProgramBinary;
    NOpenGLProc::TGetProgramPipelineInfoLog glGetProgramPipelineInfoLog;
    NOpenGLProc::TGetProgramPipelineiv glGetProgramPipelineiv;
    NOpenGLProc::TGetShaderPrecisionFormat glGetShaderPrecisionFormat;
    NOpenGLProc::TGetVertexAttribLdv glGetVertexAttribLdv;
    NOpenGLProc::TIsProgramPipeline glIsProgramPipeline;
    NOpenGLProc::TProgramBinary glProgramBinary;
    NOpenGLProc::TProgramParameteri glProgramParameteri;
    NOpenGLProc::TProgramUniform1d glProgramUniform1d;
    NOpenGLProc::TProgramUniform1dv glProgramUniform1dv;
    NOpenGLProc::TProgramUniform1f glProgramUniform1f;
    NOpenGLProc::TProgramUniform1fv glProgramUniform1fv;
    NOpenGLProc::TProgramUniform1i glProgramUniform1i;
    NOpenGLProc::TProgramUniform1iv glProgramUniform1iv;
    NOpenGLProc::TProgramUniform1ui glProgramUniform1ui;
    NOpenGLProc::TProgramUniform1uiv glProgramUniform1uiv;
    NOpenGLProc::TProgramUniform2d glProgramUniform2d;
    NOpenGLProc::TProgramUniform2dv glProgramUniform2dv;
    NOpenGLProc::TProgramUniform2f glProgramUniform2f;
    NOpenGLProc::TProgramUniform2fv glProgramUniform2fv;
    NOpenGLProc::TProgramUniform2i glProgramUniform2i;
    NOpenGLProc::TProgramUniform2iv glProgramUniform2iv;
    NOpenGLProc::TProgramUniform2ui glProgramUniform2ui;
    NOpenGLProc::TProgramUniform2uiv glProgramUniform2uiv;
    NOpenGLProc::TProgramUniform3d glProgramUniform3d;
    NOpenGLProc::TProgramUniform3dv glProgramUniform3dv;
    NOpenGLProc::TProgramUniform3f glProgramUniform3f;
    NOpenGLProc::TProgramUniform3fv glProgramUniform3fv;
    NOpenGLProc::TProgramUniform3i glProgramUniform3i;
    NOpenGLProc::TProgramUniform3iv glProgramUniform3iv;
    NOpenGLProc::TProgramUniform3ui glProgramUniform3ui;
    NOpenGLProc::TProgramUniform3uiv glProgramUniform3uiv;
    NOpenGLProc::TProgramUniform4d glProgramUniform4d;
    NOpenGLProc::TProgramUniform4dv glProgramUniform4dv;
    NOpenGLProc::TProgramUniform4f glProgramUniform4f;
    NOpenGLProc::TProgramUniform4fv glProgramUniform4fv;
    NOpenGLProc::TProgramUniform4i glProgramUniform4i;
    NOpenGLProc::TProgramUniform4iv glProgramUniform4iv;
    NOpenGLProc::TProgramUniform4ui glProgramUniform4ui;
    NOpenGLProc::TProgramUniform4uiv glProgramUniform4uiv;
    NOpenGLProc::TProgramUniformMatrix2dv glProgramUniformMatrix2dv;
    NOpenGLProc::TProgramUniformMatrix2fv glProgramUniformMatrix2fv;
    NOpenGLProc::TProgramUniformMatrix2x3dv glProgramUniformMatrix2x3dv;
    NOpenGLProc::TProgramUniformMatrix2x3fv glProgramUniformMatrix2x3fv;
    NOpenGLProc::TProgramUniformMatrix2x4dv glProgramUniformMatrix2x4dv;
    NOpenGLProc::TProgramUniformMatrix2x4fv glProgramUniformMatrix2x4fv;
    NOpenGLProc::TProgramUniformMatrix3dv glProgramUniformMatrix3dv;
    NOpenGLProc::TProgramUniformMatrix3fv glProgramUniformMatrix3fv;
    NOpenGLProc::TProgramUniformMatrix3x2dv glProgramUniformMatrix3x2dv;
    NOpenGLProc::TProgramUniformMatrix3x2fv glProgramUniformMatrix3x2fv;
    NOpenGLProc::TProgramUniformMatrix3x4dv glProgramUniformMatrix3x4dv;
    NOpenGLProc::TProgramUniformMatrix3x4fv glProgramUniformMatrix3x4fv;
    NOpenGLProc::TProgramUniformMatrix4dv glProgramUniformMatrix4dv;
    NOpenGLProc::TProgramUniformMatrix4fv glProgramUniformMatrix4fv;
    NOpenGLProc::TProgramUniformMatrix4x2dv glProgramUniformMatrix4x2dv;
    NOpenGLProc::TProgramUniformMatrix4x2fv glProgramUniformMatrix4x2fv;
    NOpenGLProc::TProgramUniformMatrix4x3dv glProgramUniformMatrix4x3dv;
    NOpenGLProc::TProgramUniformMatrix4x3fv glProgramUniformMatrix4x3fv;
    NOpenGLProc::TReleaseShaderCompiler glReleaseShaderCompiler;
    NOpenGLProc::TScissorArrayv glScissorArrayv;
    NOpenGLProc::TScissorIndexed glScissorIndexed;
    NOpenGLProc::TScissorIndexedv glScissorIndexedv;
    NOpenGLProc::TShaderBinary glShaderBinary;
    NOpenGLProc::TUseProgramStages glUseProgramStages;
    NOpenGLProc::TValidateProgramPipeline glValidateProgramPipeline;
    NOpenGLProc::TVertexAttribL1d glVertexAttribL1d;
    NOpenGLProc::TVertexAttribL1dv glVertexAttribL1dv;
    NOpenGLProc::TVertexAttribL2d glVertexAttribL2d;
    NOpenGLProc::TVertexAttribL2dv glVertexAttribL2dv;
    NOpenGLProc::TVertexAttribL3d glVertexAttribL3d;
    NOpenGLProc::TVertexAttribL3dv glVertexAttribL3dv;
    NOpenGLProc::TVertexAttribL4d glVertexAttribL4d;
    NOpenGLProc::TVertexAttribL4dv glVertexAttribL4dv;
    NOpenGLProc::TVertexAttribLPointer glVertexAttribLPointer;
    NOpenGLProc::TViewportArrayv glViewportArrayv;
    NOpenGLProc::TViewportIndexedf glViewportIndexedf;
    NOpenGLProc::TViewportIndexedfv glViewportIndexedfv;

    // GL_VERSION_4_2
    NOpenGLProc::TBindImageTexture glBindImageTexture;
    NOpenGLProc::TDrawArraysInstancedBaseInstance glDrawArraysInstancedBaseInstance;
    NOpenGLProc::TDrawElementsInstancedBaseInstance glDrawElementsInstancedBaseInstance;
    NOpenGLProc::TDrawElementsInstancedBaseVertexBaseInstance glDrawElementsInstancedBaseVertexBaseInstance;
    NOpenGLProc::TDrawTransformFeedbackInstanced glDrawTransformFeedbackInstanced;
    NOpenGLProc::TDrawTransformFeedbackStreamInstanced glDrawTransformFeedbackStreamInstanced;
    NOpenGLProc::TGetActiveAtomicCounterBufferiv glGetActiveAtomicCounterBufferiv;
    NOpenGLProc::TGetInternalformativ glGetInternalformativ;
    NOpenGLProc::TMemoryBarrier glMemoryBarrier;
    NOpenGLProc::TTexStorage1D glTexStorage1D;
    NOpenGLProc::TTexStorage2D glTexStorage2D;
    NOpenGLProc::TTexStorage3D glTexStorage3D;

    // GL_VERSION_4_3
    NOpenGLProc::TBindVertexBuffer glBindVertexBuffer;
    NOpenGLProc::TClearBufferData glClearBufferData;
    NOpenGLProc::TClearBufferSubData glClearBufferSubData;
    NOpenGLProc::TCopyImageSubData glCopyImageSubData;
    NOpenGLProc::TDebugMessageCallback glDebugMessageCallback;
    NOpenGLProc::TDebugMessageControl glDebugMessageControl;
    NOpenGLProc::TDebugMessageInsert glDebugMessageInsert;
    NOpenGLProc::TDispatchCompute glDispatchCompute;
    NOpenGLProc::TDispatchComputeIndirect glDispatchComputeIndirect;
    NOpenGLProc::TFramebufferParameteri glFramebufferParameteri;
    NOpenGLProc::TGetDebugMessageLog glGetDebugMessageLog;
    NOpenGLProc::TGetFramebufferParameteriv glGetFramebufferParameteriv;
    NOpenGLProc::TGetInternalformati64v glGetInternalformati64v;
    NOpenGLProc::TGetObjectLabel glGetObjectLabel;
    NOpenGLProc::TGetObjectPtrLabel glGetObjectPtrLabel;
    NOpenGLProc::TGetProgramInterfaceiv glGetProgramInterfaceiv;
    NOpenGLProc::TGetProgramResourceIndex glGetProgramResourceIndex;
    NOpenGLProc::TGetProgramResourceLocation glGetProgramResourceLocation;
    NOpenGLProc::TGetProgramResourceLocationIndex glGetProgramResourceLocationIndex;
    NOpenGLProc::TGetProgramResourceName glGetProgramResourceName;
    NOpenGLProc::TGetProgramResourceiv glGetProgramResourceiv;
    NOpenGLProc::TInvalidateBufferData glInvalidateBufferData;
    NOpenGLProc::TInvalidateBufferSubData glInvalidateBufferSubData;
    NOpenGLProc::TInvalidateFramebuffer glInvalidateFramebuffer;
    NOpenGLProc::TInvalidateSubFramebuffer glInvalidateSubFramebuffer;
    NOpenGLProc::TInvalidateTexImage glInvalidateTexImage;
    NOpenGLProc::TInvalidateTexSubImage glInvalidateTexSubImage;
    NOpenGLProc::TMultiDrawArraysIndirect glMultiDrawArraysIndirect;
    NOpenGLProc::TMultiDrawElementsIndirect glMultiDrawElementsIndirect;
    NOpenGLProc::TObjectLabel glObjectLabel;
    NOpenGLProc::TObjectPtrLabel glObjectPtrLabel;
    NOpenGLProc::TPopDebugGroup glPopDebugGroup;
    NOpenGLProc::TPushDebugGroup glPushDebugGroup;
    NOpenGLProc::TShaderStorageBlockBinding glShaderStorageBlockBinding;
    NOpenGLProc::TTexBufferRange glTexBufferRange;
    NOpenGLProc::TTexStorage2DMultisample glTexStorage2DMultisample;
    NOpenGLProc::TTexStorage3DMultisample glTexStorage3DMultisample;
    NOpenGLProc::TTextureView glTextureView;
    NOpenGLProc::TVertexAttribBinding glVertexAttribBinding;
    NOpenGLProc::TVertexAttribFormat glVertexAttribFormat;
    NOpenGLProc::TVertexAttribIFormat glVertexAttribIFormat;
    NOpenGLProc::TVertexAttribLFormat glVertexAttribLFormat;
    NOpenGLProc::TVertexBindingDivisor glVertexBindingDivisor;

    // GL_VERSION_4_4
    NOpenGLProc::TBindBuffersBase glBindBuffersBase;
    NOpenGLProc::TBindBuffersRange glBindBuffersRange;
    NOpenGLProc::TBindImageTextures glBindImageTextures;
    NOpenGLProc::TBindSamplers glBindSamplers;
    NOpenGLProc::TBindTextures glBindTextures;
    NOpenGLProc::TBindVertexBuffers glBindVertexBuffers;
    NOpenGLProc::TBufferStorage glBufferStorage;
    NOpenGLProc::TClearTexImage glClearTexImage;
    NOpenGLProc::TClearTexSubImage glClearTexSubImage;

    // GL_VERSION_4_5
    NOpenGLProc::TBindTextureUnit glBindTextureUnit;
    NOpenGLProc::TBlitNamedFramebuffer glBlitNamedFramebuffer;
    NOpenGLProc::TCheckNamedFramebufferStatus glCheckNamedFramebufferStatus;
    NOpenGLProc::TClearNamedBufferData glClearNamedBufferData;
    NOpenGLProc::TClearNamedBufferSubData glClearNamedBufferSubData;
    NOpenGLProc::TClearNamedFramebufferfi glClearNamedFramebufferfi;
    NOpenGLProc::TClearNamedFramebufferfv glClearNamedFramebufferfv;
    NOpenGLProc::TClearNamedFramebufferiv glClearNamedFramebufferiv;
    NOpenGLProc::TClearNamedFramebufferuiv glClearNamedFramebufferuiv;
    NOpenGLProc::TClipControl glClipControl;
    NOpenGLProc::TCompressedTextureSubImage1D glCompressedTextureSubImage1D;
    NOpenGLProc::TCompressedTextureSubImage2D glCompressedTextureSubImage2D;
    NOpenGLProc::TCompressedTextureSubImage3D glCompressedTextureSubImage3D;
    NOpenGLProc::TCopyNamedBufferSubData glCopyNamedBufferSubData;
    NOpenGLProc::TCopyTextureSubImage1D glCopyTextureSubImage1D;
    NOpenGLProc::TCopyTextureSubImage2D glCopyTextureSubImage2D;
    NOpenGLProc::TCopyTextureSubImage3D glCopyTextureSubImage3D;
    NOpenGLProc::TCreateBuffers glCreateBuffers;
    NOpenGLProc::TCreateFramebuffers glCreateFramebuffers;
    NOpenGLProc::TCreateProgramPipelines glCreateProgramPipelines;
    NOpenGLProc::TCreateQueries glCreateQueries;
    NOpenGLProc::TCreateRenderbuffers glCreateRenderbuffers;
    NOpenGLProc::TCreateSamplers glCreateSamplers;
    NOpenGLProc::TCreateTextures glCreateTextures;
    NOpenGLProc::TCreateTransformFeedbacks glCreateTransformFeedbacks;
    NOpenGLProc::TCreateVertexArrays glCreateVertexArrays;
    NOpenGLProc::TDisableVertexArrayAttrib glDisableVertexArrayAttrib;
    NOpenGLProc::TEnableVertexArrayAttrib glEnableVertexArrayAttrib;
    NOpenGLProc::TFlushMappedNamedBufferRange glFlushMappedNamedBufferRange;
    NOpenGLProc::TGenerateTextureMipmap glGenerateTextureMipmap;
    NOpenGLProc::TGetCompressedTextureImage glGetCompressedTextureImage;
    NOpenGLProc::TGetCompressedTextureSubImage glGetCompressedTextureSubImage;
    NOpenGLProc::TGetGraphicsResetStatus glGetGraphicsResetStatus;
    NOpenGLProc::TGetNamedBufferParameteri64v glGetNamedBufferParameteri64v;
    NOpenGLProc::TGetNamedBufferParameteriv glGetNamedBufferParameteriv;
    NOpenGLProc::TGetNamedBufferPointerv glGetNamedBufferPointerv;
    NOpenGLProc::TGetNamedBufferSubData glGetNamedBufferSubData;
    NOpenGLProc::TGetNamedFramebufferAttachmentParameteriv glGetNamedFramebufferAttachmentParameteriv;
    NOpenGLProc::TGetNamedFramebufferParameteriv glGetNamedFramebufferParameteriv;
    NOpenGLProc::TGetNamedRenderbufferParameteriv glGetNamedRenderbufferParameteriv;
    NOpenGLProc::TGetQueryBufferObjecti64v glGetQueryBufferObjecti64v;
    NOpenGLProc::TGetQueryBufferObjectiv glGetQueryBufferObjectiv;
    NOpenGLProc::TGetQueryBufferObjectui64v glGetQueryBufferObjectui64v;
    NOpenGLProc::TGetQueryBufferObjectuiv glGetQueryBufferObjectuiv;
    NOpenGLProc::TGetTextureImage glGetTextureImage;
    NOpenGLProc::TGetTextureLevelParameterfv glGetTextureLevelParameterfv;
    NOpenGLProc::TGetTextureLevelParameteriv glGetTextureLevelParameteriv;
    NOpenGLProc::TGetTextureParameterIiv glGetTextureParameterIiv;
    NOpenGLProc::TGetTextureParameterIuiv glGetTextureParameterIuiv;
    NOpenGLProc::TGetTextureParameterfv glGetTextureParameterfv;
    NOpenGLProc::TGetTextureParameteriv glGetTextureParameteriv;
    NOpenGLProc::TGetTextureSubImage glGetTextureSubImage;
    NOpenGLProc::TGetTransformFeedbacki64_v glGetTransformFeedbacki64_v;
    NOpenGLProc::TGetTransformFeedbacki_v glGetTransformFeedbacki_v;
    NOpenGLProc::TGetTransformFeedbackiv glGetTransformFeedbackiv;
    NOpenGLProc::TGetVertexArrayIndexed64iv glGetVertexArrayIndexed64iv;
    NOpenGLProc::TGetVertexArrayIndexediv glGetVertexArrayIndexediv;
    NOpenGLProc::TGetVertexArrayiv glGetVertexArrayiv;
    NOpenGLProc::TGetnCompressedTexImage glGetnCompressedTexImage;
    NOpenGLProc::TGetnTexImage glGetnTexImage;
    NOpenGLProc::TGetnUniformdv glGetnUniformdv;
    NOpenGLProc::TGetnUniformfv glGetnUniformfv;
    NOpenGLProc::TGetnUniformiv glGetnUniformiv;
    NOpenGLProc::TGetnUniformuiv glGetnUniformuiv;
    NOpenGLProc::TInvalidateNamedFramebufferData glInvalidateNamedFramebufferData;
    NOpenGLProc::TInvalidateNamedFramebufferSubData glInvalidateNamedFramebufferSubData;
    NOpenGLProc::TMapNamedBuffer glMapNamedBuffer;
    NOpenGLProc::TMapNamedBufferRange glMapNamedBufferRange;
    NOpenGLProc::TMemoryBarrierByRegion glMemoryBarrierByRegion;
    NOpenGLProc::TNamedBufferData glNamedBufferData;
    NOpenGLProc::TNamedBufferStorage glNamedBufferStorage;
    NOpenGLProc::TNamedBufferSubData glNamedBufferSubData;
    NOpenGLProc::TNamedFramebufferDrawBuffer glNamedFramebufferDrawBuffer;
    NOpenGLProc::TNamedFramebufferDrawBuffers glNamedFramebufferDrawBuffers;
    NOpenGLProc::TNamedFramebufferParameteri glNamedFramebufferParameteri;
    NOpenGLProc::TNamedFramebufferReadBuffer glNamedFramebufferReadBuffer;
    NOpenGLProc::TNamedFramebufferRenderbuffer glNamedFramebufferRenderbuffer;
    NOpenGLProc::TNamedFramebufferTexture glNamedFramebufferTexture;
    NOpenGLProc::TNamedFramebufferTextureLayer glNamedFramebufferTextureLayer;
    NOpenGLProc::TNamedRenderbufferStorage glNamedRenderbufferStorage;
    NOpenGLProc::TNamedRenderbufferStorageMultisample glNamedRenderbufferStorageMultisample;
    NOpenGLProc::TReadnPixels glReadnPixels;
    NOpenGLProc::TTextureBarrier glTextureBarrier;
    NOpenGLProc::TTextureBuffer glTextureBuffer;
    NOpenGLProc::TTextureBufferRange glTextureBufferRange;
    NOpenGLProc::TTextureParameterIiv glTextureParameterIiv;
    NOpenGLProc::TTextureParameterIuiv glTextureParameterIuiv;
    NOpenGLProc::TTextureParameterf glTextureParameterf;
    NOpenGLProc::TTextureParameterfv glTextureParameterfv;
    NOpenGLProc::TTextureParameteri glTextureParameteri;
    NOpenGLProc::TTextureParameteriv glTextureParameteriv;
    NOpenGLProc::TTextureStorage1D glTextureStorage1D;
    NOpenGLProc::TTextureStorage2D glTextureStorage2D;
    NOpenGLProc::TTextureStorage2DMultisample glTextureStorage2DMultisample;
    NOpenGLProc::TTextureStorage3D glTextureStorage3D;
    NOpenGLProc::TTextureStorage3DMultisample glTextureStorage3DMultisample;
    NOpenGLProc::TTextureSubImage1D glTextureSubImage1D;
    NOpenGLProc::TTextureSubImage2D glTextureSubImage2D;
    NOpenGLProc::TTextureSubImage3D glTextureSubImage3D;
    NOpenGLProc::TTransformFeedbackBufferBase glTransformFeedbackBufferBase;
    NOpenGLProc::TTransformFeedbackBufferRange glTransformFeedbackBufferRange;
    NOpenGLProc::TUnmapNamedBuffer glUnmapNamedBuffer;
    NOpenGLProc::TVertexArrayAttribBinding glVertexArrayAttribBinding;
    NOpenGLProc::TVertexArrayAttribFormat glVertexArrayAttribFormat;
    NOpenGLProc::TVertexArrayAttribIFormat glVertexArrayAttribIFormat;
    NOpenGLProc::TVertexArrayAttribLFormat glVertexArrayAttribLFormat;
    NOpenGLProc::TVertexArrayBindingDivisor glVertexArrayBindingDivisor;
    NOpenGLProc::TVertexArrayElementBuffer glVertexArrayElementBuffer;
    NOpenGLProc::TVertexArrayVertexBuffer glVertexArrayVertexBuffer;
    NOpenGLProc::TVertexArrayVertexBuffers glVertexArrayVertexBuffers;

  public:
    COpenGL(CContext *context = NULL);
    ~COpenGL();
    void initializeGLFunctions(NEngine::EGPUPlatform explicitPlatofrm = NEngine::GPU_PLATFORM_KEEP);
    void makeCurrent();

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
inline COpenGL::COpenGL(CContext *context) : CEngineBase(context),
  // GL_VERSION_1_2
  glCopyTexSubImage3D(NULL),
  glDrawRangeElements(NULL),
  glTexImage3D(NULL),
  glTexSubImage3D(NULL),

  // GL_VERSION_1_3
  glActiveTexture(NULL),
  glCompressedTexImage1D(NULL),
  glCompressedTexImage2D(NULL),
  glCompressedTexImage3D(NULL),
  glCompressedTexSubImage1D(NULL),
  glCompressedTexSubImage2D(NULL),
  glCompressedTexSubImage3D(NULL),
  glGetCompressedTexImage(NULL),
  glSampleCoverage(NULL),

  // GL_VERSION_1_4
  glBlendColor(NULL),
  glBlendEquation(NULL),
  glBlendFuncSeparate(NULL),
  glMultiDrawArrays(NULL),
  glMultiDrawElements(NULL),
  glPointParameterf(NULL),
  glPointParameterfv(NULL),
  glPointParameteri(NULL),
  glPointParameteriv(NULL),

  // GL_VERSION_1_5
  glBeginQuery(NULL),
  glBindBuffer(NULL),
  glBufferData(NULL),
  glBufferSubData(NULL),
  glDeleteBuffers(NULL),
  glDeleteQueries(NULL),
  glEndQuery(NULL),
  glGenBuffers(NULL),
  glGenQueries(NULL),
  glGetBufferParameteriv(NULL),
  glGetBufferPointerv(NULL),
  glGetBufferSubData(NULL),
  glGetQueryObjectiv(NULL),
  glGetQueryObjectuiv(NULL),
  glGetQueryiv(NULL),
  glIsBuffer(NULL),
  glIsQuery(NULL),
  glMapBuffer(NULL),
  glUnmapBuffer(NULL),

  // GL_VERSION_2_0
  glAttachShader(NULL),
  glBindAttribLocation(NULL),
  glBlendEquationSeparate(NULL),
  glCompileShader(NULL),
  glCreateProgram(NULL),
  glCreateShader(NULL),
  glDeleteProgram(NULL),
  glDeleteShader(NULL),
  glDetachShader(NULL),
  glDisableVertexAttribArray(NULL),
  glDrawBuffers(NULL),
  glEnableVertexAttribArray(NULL),
  glGetActiveAttrib(NULL),
  glGetActiveUniform(NULL),
  glGetAttachedShaders(NULL),
  glGetAttribLocation(NULL),
  glGetProgramInfoLog(NULL),
  glGetProgramiv(NULL),
  glGetShaderInfoLog(NULL),
  glGetShaderSource(NULL),
  glGetShaderiv(NULL),
  glGetUniformLocation(NULL),
  glGetUniformfv(NULL),
  glGetUniformiv(NULL),
  glGetVertexAttribPointerv(NULL),
  glGetVertexAttribdv(NULL),
  glGetVertexAttribfv(NULL),
  glGetVertexAttribiv(NULL),
  glIsProgram(NULL),
  glIsShader(NULL),
  glLinkProgram(NULL),
  glShaderSource(NULL),
  glStencilFuncSeparate(NULL),
  glStencilMaskSeparate(NULL),
  glStencilOpSeparate(NULL),
  glUniform1f(NULL),
  glUniform1fv(NULL),
  glUniform1i(NULL),
  glUniform1iv(NULL),
  glUniform2f(NULL),
  glUniform2fv(NULL),
  glUniform2i(NULL),
  glUniform2iv(NULL),
  glUniform3f(NULL),
  glUniform3fv(NULL),
  glUniform3i(NULL),
  glUniform3iv(NULL),
  glUniform4f(NULL),
  glUniform4fv(NULL),
  glUniform4i(NULL),
  glUniform4iv(NULL),
  glUniformMatrix2fv(NULL),
  glUniformMatrix3fv(NULL),
  glUniformMatrix4fv(NULL),
  glUseProgram(NULL),
  glValidateProgram(NULL),
  glVertexAttrib1d(NULL),
  glVertexAttrib1dv(NULL),
  glVertexAttrib1f(NULL),
  glVertexAttrib1fv(NULL),
  glVertexAttrib1s(NULL),
  glVertexAttrib1sv(NULL),
  glVertexAttrib2d(NULL),
  glVertexAttrib2dv(NULL),
  glVertexAttrib2f(NULL),
  glVertexAttrib2fv(NULL),
  glVertexAttrib2s(NULL),
  glVertexAttrib2sv(NULL),
  glVertexAttrib3d(NULL),
  glVertexAttrib3dv(NULL),
  glVertexAttrib3f(NULL),
  glVertexAttrib3fv(NULL),
  glVertexAttrib3s(NULL),
  glVertexAttrib3sv(NULL),
  glVertexAttrib4Nbv(NULL),
  glVertexAttrib4Niv(NULL),
  glVertexAttrib4Nsv(NULL),
  glVertexAttrib4Nub(NULL),
  glVertexAttrib4Nubv(NULL),
  glVertexAttrib4Nuiv(NULL),
  glVertexAttrib4Nusv(NULL),
  glVertexAttrib4bv(NULL),
  glVertexAttrib4d(NULL),
  glVertexAttrib4dv(NULL),
  glVertexAttrib4f(NULL),
  glVertexAttrib4fv(NULL),
  glVertexAttrib4iv(NULL),
  glVertexAttrib4s(NULL),
  glVertexAttrib4sv(NULL),
  glVertexAttrib4ubv(NULL),
  glVertexAttrib4uiv(NULL),
  glVertexAttrib4usv(NULL),
  glVertexAttribPointer(NULL),

  // GL_VERSION_2_1
  glUniformMatrix2x3fv(NULL),
  glUniformMatrix2x4fv(NULL),
  glUniformMatrix3x2fv(NULL),
  glUniformMatrix3x4fv(NULL),
  glUniformMatrix4x2fv(NULL),
  glUniformMatrix4x3fv(NULL),

  // GL_VERSION_3_0
  glBeginConditionalRender(NULL),
  glBeginTransformFeedback(NULL),
  glBindBufferBase(NULL),
  glBindBufferRange(NULL),
  glBindFragDataLocation(NULL),
  glBindFramebuffer(NULL),
  glBindRenderbuffer(NULL),
  glBindVertexArray(NULL),
  glBlitFramebuffer(NULL),
  glCheckFramebufferStatus(NULL),
  glClampColor(NULL),
  glClearBufferfi(NULL),
  glClearBufferfv(NULL),
  glClearBufferiv(NULL),
  glClearBufferuiv(NULL),
  glColorMaski(NULL),
  glDeleteFramebuffers(NULL),
  glDeleteRenderbuffers(NULL),
  glDeleteVertexArrays(NULL),
  glDisablei(NULL),
  glEnablei(NULL),
  glEndConditionalRender(NULL),
  glEndTransformFeedback(NULL),
  glFlushMappedBufferRange(NULL),
  glFramebufferRenderbuffer(NULL),
  glFramebufferTexture1D(NULL),
  glFramebufferTexture2D(NULL),
  glFramebufferTexture3D(NULL),
  glFramebufferTextureLayer(NULL),
  glGenFramebuffers(NULL),
  glGenRenderbuffers(NULL),
  glGenVertexArrays(NULL),
  glGenerateMipmap(NULL),
  glGetBooleani_v(NULL),
  glGetFragDataLocation(NULL),
  glGetFramebufferAttachmentParameteriv(NULL),
  glGetIntegeri_v(NULL),
  glGetRenderbufferParameteriv(NULL),
  glGetStringi(NULL),
  glGetTexParameterIiv(NULL),
  glGetTexParameterIuiv(NULL),
  glGetTransformFeedbackVarying(NULL),
  glGetUniformuiv(NULL),
  glGetVertexAttribIiv(NULL),
  glGetVertexAttribIuiv(NULL),
  glIsEnabledi(NULL),
  glIsFramebuffer(NULL),
  glIsRenderbuffer(NULL),
  glIsVertexArray(NULL),
  glMapBufferRange(NULL),
  glRenderbufferStorage(NULL),
  glRenderbufferStorageMultisample(NULL),
  glTexParameterIiv(NULL),
  glTexParameterIuiv(NULL),
  glTransformFeedbackVaryings(NULL),
  glUniform1ui(NULL),
  glUniform1uiv(NULL),
  glUniform2ui(NULL),
  glUniform2uiv(NULL),
  glUniform3ui(NULL),
  glUniform3uiv(NULL),
  glUniform4ui(NULL),
  glUniform4uiv(NULL),
  glVertexAttribI1i(NULL),
  glVertexAttribI1iv(NULL),
  glVertexAttribI1ui(NULL),
  glVertexAttribI1uiv(NULL),
  glVertexAttribI2i(NULL),
  glVertexAttribI2iv(NULL),
  glVertexAttribI2ui(NULL),
  glVertexAttribI2uiv(NULL),
  glVertexAttribI3i(NULL),
  glVertexAttribI3iv(NULL),
  glVertexAttribI3ui(NULL),
  glVertexAttribI3uiv(NULL),
  glVertexAttribI4bv(NULL),
  glVertexAttribI4i(NULL),
  glVertexAttribI4iv(NULL),
  glVertexAttribI4sv(NULL),
  glVertexAttribI4ubv(NULL),
  glVertexAttribI4ui(NULL),
  glVertexAttribI4uiv(NULL),
  glVertexAttribI4usv(NULL),
  glVertexAttribIPointer(NULL),

  // GL_VERSION_3_1
  glCopyBufferSubData(NULL),
  glDrawArraysInstanced(NULL),
  glDrawElementsInstanced(NULL),
  glGetActiveUniformBlockName(NULL),
  glGetActiveUniformBlockiv(NULL),
  glGetActiveUniformName(NULL),
  glGetActiveUniformsiv(NULL),
  glGetUniformBlockIndex(NULL),
  glGetUniformIndices(NULL),
  glPrimitiveRestartIndex(NULL),
  glTexBuffer(NULL),
  glUniformBlockBinding(NULL),

  // GL_VERSION_3_2
  glClientWaitSync(NULL),
  glDeleteSync(NULL),
  glDrawElementsBaseVertex(NULL),
  glDrawElementsInstancedBaseVertex(NULL),
  glDrawRangeElementsBaseVertex(NULL),
  glFenceSync(NULL),
  glFramebufferTexture(NULL),
  glGetBufferParameteri64v(NULL),
  glGetInteger64i_v(NULL),
  glGetInteger64v(NULL),
  glGetMultisamplefv(NULL),
  glGetSynciv(NULL),
  glIsSync(NULL),
  glMultiDrawElementsBaseVertex(NULL),
  glProvokingVertex(NULL),
  glSampleMaski(NULL),
  glTexImage2DMultisample(NULL),
  glTexImage3DMultisample(NULL),
  glWaitSync(NULL),

  // GL_VERSION_3_3
  glBindFragDataLocationIndexed(NULL),
  glBindSampler(NULL),
  glDeleteSamplers(NULL),
  glGenSamplers(NULL),
  glGetFragDataIndex(NULL),
  glGetQueryObjecti64v(NULL),
  glGetQueryObjectui64v(NULL),
  glGetSamplerParameterIiv(NULL),
  glGetSamplerParameterIuiv(NULL),
  glGetSamplerParameterfv(NULL),
  glGetSamplerParameteriv(NULL),
  glIsSampler(NULL),
  glQueryCounter(NULL),
  glSamplerParameterIiv(NULL),
  glSamplerParameterIuiv(NULL),
  glSamplerParameterf(NULL),
  glSamplerParameterfv(NULL),
  glSamplerParameteri(NULL),
  glSamplerParameteriv(NULL),
  glVertexAttribDivisor(NULL),
  glVertexAttribP1ui(NULL),
  glVertexAttribP1uiv(NULL),
  glVertexAttribP2ui(NULL),
  glVertexAttribP2uiv(NULL),
  glVertexAttribP3ui(NULL),
  glVertexAttribP3uiv(NULL),
  glVertexAttribP4ui(NULL),
  glVertexAttribP4uiv(NULL),

  // GL_VERSION_4_0
  glBeginQueryIndexed(NULL),
  glBindTransformFeedback(NULL),
  glBlendEquationSeparatei(NULL),
  glBlendEquationi(NULL),
  glBlendFuncSeparatei(NULL),
  glBlendFunci(NULL),
  glDeleteTransformFeedbacks(NULL),
  glDrawArraysIndirect(NULL),
  glDrawElementsIndirect(NULL),
  glDrawTransformFeedback(NULL),
  glDrawTransformFeedbackStream(NULL),
  glEndQueryIndexed(NULL),
  glGenTransformFeedbacks(NULL),
  glGetActiveSubroutineName(NULL),
  glGetActiveSubroutineUniformName(NULL),
  glGetActiveSubroutineUniformiv(NULL),
  glGetProgramStageiv(NULL),
  glGetQueryIndexediv(NULL),
  glGetSubroutineIndex(NULL),
  glGetSubroutineUniformLocation(NULL),
  glGetUniformSubroutineuiv(NULL),
  glGetUniformdv(NULL),
  glIsTransformFeedback(NULL),
  glMinSampleShading(NULL),
  glPatchParameterfv(NULL),
  glPatchParameteri(NULL),
  glPauseTransformFeedback(NULL),
  glResumeTransformFeedback(NULL),
  glUniform1d(NULL),
  glUniform1dv(NULL),
  glUniform2d(NULL),
  glUniform2dv(NULL),
  glUniform3d(NULL),
  glUniform3dv(NULL),
  glUniform4d(NULL),
  glUniform4dv(NULL),
  glUniformMatrix2dv(NULL),
  glUniformMatrix2x3dv(NULL),
  glUniformMatrix2x4dv(NULL),
  glUniformMatrix3dv(NULL),
  glUniformMatrix3x2dv(NULL),
  glUniformMatrix3x4dv(NULL),
  glUniformMatrix4dv(NULL),
  glUniformMatrix4x2dv(NULL),
  glUniformMatrix4x3dv(NULL),
  glUniformSubroutinesuiv(NULL),

  // GL_VERSION_4_1
  glActiveShaderProgram(NULL),
  glBindProgramPipeline(NULL),
  glClearDepthf(NULL),
  glCreateShaderProgramv(NULL),
  glDeleteProgramPipelines(NULL),
  glDepthRangeArrayv(NULL),
  glDepthRangeIndexed(NULL),
  glDepthRangef(NULL),
  glGenProgramPipelines(NULL),
  glGetDoublei_v(NULL),
  glGetFloati_v(NULL),
  glGetProgramBinary(NULL),
  glGetProgramPipelineInfoLog(NULL),
  glGetProgramPipelineiv(NULL),
  glGetShaderPrecisionFormat(NULL),
  glGetVertexAttribLdv(NULL),
  glIsProgramPipeline(NULL),
  glProgramBinary(NULL),
  glProgramParameteri(NULL),
  glProgramUniform1d(NULL),
  glProgramUniform1dv(NULL),
  glProgramUniform1f(NULL),
  glProgramUniform1fv(NULL),
  glProgramUniform1i(NULL),
  glProgramUniform1iv(NULL),
  glProgramUniform1ui(NULL),
  glProgramUniform1uiv(NULL),
  glProgramUniform2d(NULL),
  glProgramUniform2dv(NULL),
  glProgramUniform2f(NULL),
  glProgramUniform2fv(NULL),
  glProgramUniform2i(NULL),
  glProgramUniform2iv(NULL),
  glProgramUniform2ui(NULL),
  glProgramUniform2uiv(NULL),
  glProgramUniform3d(NULL),
  glProgramUniform3dv(NULL),
  glProgramUniform3f(NULL),
  glProgramUniform3fv(NULL),
  glProgramUniform3i(NULL),
  glProgramUniform3iv(NULL),
  glProgramUniform3ui(NULL),
  glProgramUniform3uiv(NULL),
  glProgramUniform4d(NULL),
  glProgramUniform4dv(NULL),
  glProgramUniform4f(NULL),
  glProgramUniform4fv(NULL),
  glProgramUniform4i(NULL),
  glProgramUniform4iv(NULL),
  glProgramUniform4ui(NULL),
  glProgramUniform4uiv(NULL),
  glProgramUniformMatrix2dv(NULL),
  glProgramUniformMatrix2fv(NULL),
  glProgramUniformMatrix2x3dv(NULL),
  glProgramUniformMatrix2x3fv(NULL),
  glProgramUniformMatrix2x4dv(NULL),
  glProgramUniformMatrix2x4fv(NULL),
  glProgramUniformMatrix3dv(NULL),
  glProgramUniformMatrix3fv(NULL),
  glProgramUniformMatrix3x2dv(NULL),
  glProgramUniformMatrix3x2fv(NULL),
  glProgramUniformMatrix3x4dv(NULL),
  glProgramUniformMatrix3x4fv(NULL),
  glProgramUniformMatrix4dv(NULL),
  glProgramUniformMatrix4fv(NULL),
  glProgramUniformMatrix4x2dv(NULL),
  glProgramUniformMatrix4x2fv(NULL),
  glProgramUniformMatrix4x3dv(NULL),
  glProgramUniformMatrix4x3fv(NULL),
  glReleaseShaderCompiler(NULL),
  glScissorArrayv(NULL),
  glScissorIndexed(NULL),
  glScissorIndexedv(NULL),
  glShaderBinary(NULL),
  glUseProgramStages(NULL),
  glValidateProgramPipeline(NULL),
  glVertexAttribL1d(NULL),
  glVertexAttribL1dv(NULL),
  glVertexAttribL2d(NULL),
  glVertexAttribL2dv(NULL),
  glVertexAttribL3d(NULL),
  glVertexAttribL3dv(NULL),
  glVertexAttribL4d(NULL),
  glVertexAttribL4dv(NULL),
  glVertexAttribLPointer(NULL),
  glViewportArrayv(NULL),
  glViewportIndexedf(NULL),
  glViewportIndexedfv(NULL),

  // GL_VERSION_4_2
  glBindImageTexture(NULL),
  glDrawArraysInstancedBaseInstance(NULL),
  glDrawElementsInstancedBaseInstance(NULL),
  glDrawElementsInstancedBaseVertexBaseInstance(NULL),
  glDrawTransformFeedbackInstanced(NULL),
  glDrawTransformFeedbackStreamInstanced(NULL),
  glGetActiveAtomicCounterBufferiv(NULL),
  glGetInternalformativ(NULL),
  glMemoryBarrier(NULL),
  glTexStorage1D(NULL),
  glTexStorage2D(NULL),
  glTexStorage3D(NULL),

  // GL_VERSION_4_3
  glBindVertexBuffer(NULL),
  glClearBufferData(NULL),
  glClearBufferSubData(NULL),
  glCopyImageSubData(NULL),
  glDebugMessageCallback(NULL),
  glDebugMessageControl(NULL),
  glDebugMessageInsert(NULL),
  glDispatchCompute(NULL),
  glDispatchComputeIndirect(NULL),
  glFramebufferParameteri(NULL),
  glGetDebugMessageLog(NULL),
  glGetFramebufferParameteriv(NULL),
  glGetInternalformati64v(NULL),
  glGetObjectLabel(NULL),
  glGetObjectPtrLabel(NULL),
  glGetProgramInterfaceiv(NULL),
  glGetProgramResourceIndex(NULL),
  glGetProgramResourceLocation(NULL),
  glGetProgramResourceLocationIndex(NULL),
  glGetProgramResourceName(NULL),
  glGetProgramResourceiv(NULL),
  glInvalidateBufferData(NULL),
  glInvalidateBufferSubData(NULL),
  glInvalidateFramebuffer(NULL),
  glInvalidateSubFramebuffer(NULL),
  glInvalidateTexImage(NULL),
  glInvalidateTexSubImage(NULL),
  glMultiDrawArraysIndirect(NULL),
  glMultiDrawElementsIndirect(NULL),
  glObjectLabel(NULL),
  glObjectPtrLabel(NULL),
  glPopDebugGroup(NULL),
  glPushDebugGroup(NULL),
  glShaderStorageBlockBinding(NULL),
  glTexBufferRange(NULL),
  glTexStorage2DMultisample(NULL),
  glTexStorage3DMultisample(NULL),
  glTextureView(NULL),
  glVertexAttribBinding(NULL),
  glVertexAttribFormat(NULL),
  glVertexAttribIFormat(NULL),
  glVertexAttribLFormat(NULL),
  glVertexBindingDivisor(NULL),

  // GL_VERSION_4_4
  glBindBuffersBase(NULL),
  glBindBuffersRange(NULL),
  glBindImageTextures(NULL),
  glBindSamplers(NULL),
  glBindTextures(NULL),
  glBindVertexBuffers(NULL),
  glBufferStorage(NULL),
  glClearTexImage(NULL),
  glClearTexSubImage(NULL),

  // GL_VERSION_4_5
  glBindTextureUnit(NULL),
  glBlitNamedFramebuffer(NULL),
  glCheckNamedFramebufferStatus(NULL),
  glClearNamedBufferData(NULL),
  glClearNamedBufferSubData(NULL),
  glClearNamedFramebufferfi(NULL),
  glClearNamedFramebufferfv(NULL),
  glClearNamedFramebufferiv(NULL),
  glClearNamedFramebufferuiv(NULL),
  glClipControl(NULL),
  glCompressedTextureSubImage1D(NULL),
  glCompressedTextureSubImage2D(NULL),
  glCompressedTextureSubImage3D(NULL),
  glCopyNamedBufferSubData(NULL),
  glCopyTextureSubImage1D(NULL),
  glCopyTextureSubImage2D(NULL),
  glCopyTextureSubImage3D(NULL),
  glCreateBuffers(NULL),
  glCreateFramebuffers(NULL),
  glCreateProgramPipelines(NULL),
  glCreateQueries(NULL),
  glCreateRenderbuffers(NULL),
  glCreateSamplers(NULL),
  glCreateTextures(NULL),
  glCreateTransformFeedbacks(NULL),
  glCreateVertexArrays(NULL),
  glDisableVertexArrayAttrib(NULL),
  glEnableVertexArrayAttrib(NULL),
  glFlushMappedNamedBufferRange(NULL),
  glGenerateTextureMipmap(NULL),
  glGetCompressedTextureImage(NULL),
  glGetCompressedTextureSubImage(NULL),
  glGetGraphicsResetStatus(NULL),
  glGetNamedBufferParameteri64v(NULL),
  glGetNamedBufferParameteriv(NULL),
  glGetNamedBufferPointerv(NULL),
  glGetNamedBufferSubData(NULL),
  glGetNamedFramebufferAttachmentParameteriv(NULL),
  glGetNamedFramebufferParameteriv(NULL),
  glGetNamedRenderbufferParameteriv(NULL),
  glGetQueryBufferObjecti64v(NULL),
  glGetQueryBufferObjectiv(NULL),
  glGetQueryBufferObjectui64v(NULL),
  glGetQueryBufferObjectuiv(NULL),
  glGetTextureImage(NULL),
  glGetTextureLevelParameterfv(NULL),
  glGetTextureLevelParameteriv(NULL),
  glGetTextureParameterIiv(NULL),
  glGetTextureParameterIuiv(NULL),
  glGetTextureParameterfv(NULL),
  glGetTextureParameteriv(NULL),
  glGetTextureSubImage(NULL),
  glGetTransformFeedbacki64_v(NULL),
  glGetTransformFeedbacki_v(NULL),
  glGetTransformFeedbackiv(NULL),
  glGetVertexArrayIndexed64iv(NULL),
  glGetVertexArrayIndexediv(NULL),
  glGetVertexArrayiv(NULL),
  glGetnCompressedTexImage(NULL),
  glGetnTexImage(NULL),
  glGetnUniformdv(NULL),
  glGetnUniformfv(NULL),
  glGetnUniformiv(NULL),
  glGetnUniformuiv(NULL),
  glInvalidateNamedFramebufferData(NULL),
  glInvalidateNamedFramebufferSubData(NULL),
  glMapNamedBuffer(NULL),
  glMapNamedBufferRange(NULL),
  glMemoryBarrierByRegion(NULL),
  glNamedBufferData(NULL),
  glNamedBufferStorage(NULL),
  glNamedBufferSubData(NULL),
  glNamedFramebufferDrawBuffer(NULL),
  glNamedFramebufferDrawBuffers(NULL),
  glNamedFramebufferParameteri(NULL),
  glNamedFramebufferReadBuffer(NULL),
  glNamedFramebufferRenderbuffer(NULL),
  glNamedFramebufferTexture(NULL),
  glNamedFramebufferTextureLayer(NULL),
  glNamedRenderbufferStorage(NULL),
  glNamedRenderbufferStorageMultisample(NULL),
  glReadnPixels(NULL),
  glTextureBarrier(NULL),
  glTextureBuffer(NULL),
  glTextureBufferRange(NULL),
  glTextureParameterIiv(NULL),
  glTextureParameterIuiv(NULL),
  glTextureParameterf(NULL),
  glTextureParameterfv(NULL),
  glTextureParameteri(NULL),
  glTextureParameteriv(NULL),
  glTextureStorage1D(NULL),
  glTextureStorage2D(NULL),
  glTextureStorage2DMultisample(NULL),
  glTextureStorage3D(NULL),
  glTextureStorage3DMultisample(NULL),
  glTextureSubImage1D(NULL),
  glTextureSubImage2D(NULL),
  glTextureSubImage3D(NULL),
  glTransformFeedbackBufferBase(NULL),
  glTransformFeedbackBufferRange(NULL),
  glUnmapNamedBuffer(NULL),
  glVertexArrayAttribBinding(NULL),
  glVertexArrayAttribFormat(NULL),
  glVertexArrayAttribIFormat(NULL),
  glVertexArrayAttribLFormat(NULL),
  glVertexArrayBindingDivisor(NULL),
  glVertexArrayElementBuffer(NULL),
  glVertexArrayVertexBuffer(NULL),
  glVertexArrayVertexBuffers(NULL)
{
}
//------------------------------------------------------------------------------
inline void COpenGL::initializeGLFunctions(NEngine::EGPUPlatform explicitPlatofrm)
{
  const NEngine::EGPUPlatform platform = (explicitPlatofrm == NEngine::GPU_PLATFORM_KEEP) ? context->engineGetEngine()->gpuPlatform : explicitPlatofrm;

  context->log("Loading OpenGL Functions...");

  // GL_VERSION_1_2
  if(platform >= NEngine::GPU_PLATFORM_GL0102)
  {
    glCopyTexSubImage3D = reinterpret_cast<NOpenGLProc::TCopyTexSubImage3D>(GL_GET_EXTENSION("glCopyTexSubImage3D"));
    glDrawRangeElements = reinterpret_cast<NOpenGLProc::TDrawRangeElements>(GL_GET_EXTENSION("glDrawRangeElements"));
    glTexImage3D = reinterpret_cast<NOpenGLProc::TTexImage3D>(GL_GET_EXTENSION("glTexImage3D"));
    glTexSubImage3D = reinterpret_cast<NOpenGLProc::TTexSubImage3D>(GL_GET_EXTENSION("glTexSubImage3D"));
  }

  // GL_VERSION_1_3
  if(platform >= NEngine::GPU_PLATFORM_GL0103)
  {
    glActiveTexture = reinterpret_cast<NOpenGLProc::TActiveTexture>(GL_GET_EXTENSION("glActiveTexture"));
    glCompressedTexImage1D = reinterpret_cast<NOpenGLProc::TCompressedTexImage1D>(GL_GET_EXTENSION("glCompressedTexImage1D"));
    glCompressedTexImage2D = reinterpret_cast<NOpenGLProc::TCompressedTexImage2D>(GL_GET_EXTENSION("glCompressedTexImage2D"));
    glCompressedTexImage3D = reinterpret_cast<NOpenGLProc::TCompressedTexImage3D>(GL_GET_EXTENSION("glCompressedTexImage3D"));
    glCompressedTexSubImage1D = reinterpret_cast<NOpenGLProc::TCompressedTexSubImage1D>(GL_GET_EXTENSION("glCompressedTexSubImage1D"));
    glCompressedTexSubImage2D = reinterpret_cast<NOpenGLProc::TCompressedTexSubImage2D>(GL_GET_EXTENSION("glCompressedTexSubImage2D"));
    glCompressedTexSubImage3D = reinterpret_cast<NOpenGLProc::TCompressedTexSubImage3D>(GL_GET_EXTENSION("glCompressedTexSubImage3D"));
    glGetCompressedTexImage = reinterpret_cast<NOpenGLProc::TGetCompressedTexImage>(GL_GET_EXTENSION("glGetCompressedTexImage"));
    glSampleCoverage = reinterpret_cast<NOpenGLProc::TSampleCoverage>(GL_GET_EXTENSION("glSampleCoverage"));
  }

  // GL_VERSION_1_4
  if(platform >= NEngine::GPU_PLATFORM_GL0104)
  {
    glBlendColor = reinterpret_cast<NOpenGLProc::TBlendColor>(GL_GET_EXTENSION("glBlendColor"));
    glBlendEquation = reinterpret_cast<NOpenGLProc::TBlendEquation>(GL_GET_EXTENSION("glBlendEquation"));
    glBlendFuncSeparate = reinterpret_cast<NOpenGLProc::TBlendFuncSeparate>(GL_GET_EXTENSION("glBlendFuncSeparate"));
    glMultiDrawArrays = reinterpret_cast<NOpenGLProc::TMultiDrawArrays>(GL_GET_EXTENSION("glMultiDrawArrays"));
    glMultiDrawElements = reinterpret_cast<NOpenGLProc::TMultiDrawElements>(GL_GET_EXTENSION("glMultiDrawElements"));
    glPointParameterf = reinterpret_cast<NOpenGLProc::TPointParameterf>(GL_GET_EXTENSION("glPointParameterf"));
    glPointParameterfv = reinterpret_cast<NOpenGLProc::TPointParameterfv>(GL_GET_EXTENSION("glPointParameterfv"));
    glPointParameteri = reinterpret_cast<NOpenGLProc::TPointParameteri>(GL_GET_EXTENSION("glPointParameteri"));
    glPointParameteriv = reinterpret_cast<NOpenGLProc::TPointParameteriv>(GL_GET_EXTENSION("glPointParameteriv"));
  }

  // GL_VERSION_1_5
  if(platform >= NEngine::GPU_PLATFORM_GL0105)
  {
    glBeginQuery = reinterpret_cast<NOpenGLProc::TBeginQuery>(GL_GET_EXTENSION("glBeginQuery"));
    glBindBuffer = reinterpret_cast<NOpenGLProc::TBindBuffer>(GL_GET_EXTENSION("glBindBuffer"));
    glBufferData = reinterpret_cast<NOpenGLProc::TBufferData>(GL_GET_EXTENSION("glBufferData"));
    glBufferSubData = reinterpret_cast<NOpenGLProc::TBufferSubData>(GL_GET_EXTENSION("glBufferSubData"));
    glDeleteBuffers = reinterpret_cast<NOpenGLProc::TDeleteBuffers>(GL_GET_EXTENSION("glDeleteBuffers"));
    glDeleteQueries = reinterpret_cast<NOpenGLProc::TDeleteQueries>(GL_GET_EXTENSION("glDeleteQueries"));
    glEndQuery = reinterpret_cast<NOpenGLProc::TEndQuery>(GL_GET_EXTENSION("glEndQuery"));
    glGenBuffers = reinterpret_cast<NOpenGLProc::TGenBuffers>(GL_GET_EXTENSION("glGenBuffers"));
    glGenQueries = reinterpret_cast<NOpenGLProc::TGenQueries>(GL_GET_EXTENSION("glGenQueries"));
    glGetBufferParameteriv = reinterpret_cast<NOpenGLProc::TGetBufferParameteriv>(GL_GET_EXTENSION("glGetBufferParameteriv"));
    glGetBufferPointerv = reinterpret_cast<NOpenGLProc::TGetBufferPointerv>(GL_GET_EXTENSION("glGetBufferPointerv"));
    glGetBufferSubData = reinterpret_cast<NOpenGLProc::TGetBufferSubData>(GL_GET_EXTENSION("glGetBufferSubData"));
    glGetQueryObjectiv = reinterpret_cast<NOpenGLProc::TGetQueryObjectiv>(GL_GET_EXTENSION("glGetQueryObjectiv"));
    glGetQueryObjectuiv = reinterpret_cast<NOpenGLProc::TGetQueryObjectuiv>(GL_GET_EXTENSION("glGetQueryObjectuiv"));
    glGetQueryiv = reinterpret_cast<NOpenGLProc::TGetQueryiv>(GL_GET_EXTENSION("glGetQueryiv"));
    glIsBuffer = reinterpret_cast<NOpenGLProc::TIsBuffer>(GL_GET_EXTENSION("glIsBuffer"));
    glIsQuery = reinterpret_cast<NOpenGLProc::TIsQuery>(GL_GET_EXTENSION("glIsQuery"));
    glMapBuffer = reinterpret_cast<NOpenGLProc::TMapBuffer>(GL_GET_EXTENSION("glMapBuffer"));
    glUnmapBuffer = reinterpret_cast<NOpenGLProc::TUnmapBuffer>(GL_GET_EXTENSION("glUnmapBuffer"));
  }

  // GL_VERSION_2_0
  if(platform >= NEngine::GPU_PLATFORM_GL0200)
  {
    glAttachShader = reinterpret_cast<NOpenGLProc::TAttachShader>(GL_GET_EXTENSION("glAttachShader"));
    glBindAttribLocation = reinterpret_cast<NOpenGLProc::TBindAttribLocation>(GL_GET_EXTENSION("glBindAttribLocation"));
    glBlendEquationSeparate = reinterpret_cast<NOpenGLProc::TBlendEquationSeparate>(GL_GET_EXTENSION("glBlendEquationSeparate"));
    glCompileShader = reinterpret_cast<NOpenGLProc::TCompileShader>(GL_GET_EXTENSION("glCompileShader"));
    glCreateProgram = reinterpret_cast<NOpenGLProc::TCreateProgram>(GL_GET_EXTENSION("glCreateProgram"));
    glCreateShader = reinterpret_cast<NOpenGLProc::TCreateShader>(GL_GET_EXTENSION("glCreateShader"));
    glDeleteProgram = reinterpret_cast<NOpenGLProc::TDeleteProgram>(GL_GET_EXTENSION("glDeleteProgram"));
    glDeleteShader = reinterpret_cast<NOpenGLProc::TDeleteShader>(GL_GET_EXTENSION("glDeleteShader"));
    glDetachShader = reinterpret_cast<NOpenGLProc::TDetachShader>(GL_GET_EXTENSION("glDetachShader"));
    glDisableVertexAttribArray = reinterpret_cast<NOpenGLProc::TDisableVertexAttribArray>(GL_GET_EXTENSION("glDisableVertexAttribArray"));
    glDrawBuffers = reinterpret_cast<NOpenGLProc::TDrawBuffers>(GL_GET_EXTENSION("glDrawBuffers"));
    glEnableVertexAttribArray = reinterpret_cast<NOpenGLProc::TEnableVertexAttribArray>(GL_GET_EXTENSION("glEnableVertexAttribArray"));
    glGetActiveAttrib = reinterpret_cast<NOpenGLProc::TGetActiveAttrib>(GL_GET_EXTENSION("glGetActiveAttrib"));
    glGetActiveUniform = reinterpret_cast<NOpenGLProc::TGetActiveUniform>(GL_GET_EXTENSION("glGetActiveUniform"));
    glGetAttachedShaders = reinterpret_cast<NOpenGLProc::TGetAttachedShaders>(GL_GET_EXTENSION("glGetAttachedShaders"));
    glGetAttribLocation = reinterpret_cast<NOpenGLProc::TGetAttribLocation>(GL_GET_EXTENSION("glGetAttribLocation"));
    glGetProgramInfoLog = reinterpret_cast<NOpenGLProc::TGetProgramInfoLog>(GL_GET_EXTENSION("glGetProgramInfoLog"));
    glGetProgramiv = reinterpret_cast<NOpenGLProc::TGetProgramiv>(GL_GET_EXTENSION("glGetProgramiv"));
    glGetShaderInfoLog = reinterpret_cast<NOpenGLProc::TGetShaderInfoLog>(GL_GET_EXTENSION("glGetShaderInfoLog"));
    glGetShaderSource = reinterpret_cast<NOpenGLProc::TGetShaderSource>(GL_GET_EXTENSION("glGetShaderSource"));
    glGetShaderiv = reinterpret_cast<NOpenGLProc::TGetShaderiv>(GL_GET_EXTENSION("glGetShaderiv"));
    glGetUniformLocation = reinterpret_cast<NOpenGLProc::TGetUniformLocation>(GL_GET_EXTENSION("glGetUniformLocation"));
    glGetUniformfv = reinterpret_cast<NOpenGLProc::TGetUniformfv>(GL_GET_EXTENSION("glGetUniformfv"));
    glGetUniformiv = reinterpret_cast<NOpenGLProc::TGetUniformiv>(GL_GET_EXTENSION("glGetUniformiv"));
    glGetVertexAttribPointerv = reinterpret_cast<NOpenGLProc::TGetVertexAttribPointerv>(GL_GET_EXTENSION("glGetVertexAttribPointerv"));
    glGetVertexAttribdv = reinterpret_cast<NOpenGLProc::TGetVertexAttribdv>(GL_GET_EXTENSION("glGetVertexAttribdv"));
    glGetVertexAttribfv = reinterpret_cast<NOpenGLProc::TGetVertexAttribfv>(GL_GET_EXTENSION("glGetVertexAttribfv"));
    glGetVertexAttribiv = reinterpret_cast<NOpenGLProc::TGetVertexAttribiv>(GL_GET_EXTENSION("glGetVertexAttribiv"));
    glIsProgram = reinterpret_cast<NOpenGLProc::TIsProgram>(GL_GET_EXTENSION("glIsProgram"));
    glIsShader = reinterpret_cast<NOpenGLProc::TIsShader>(GL_GET_EXTENSION("glIsShader"));
    glLinkProgram = reinterpret_cast<NOpenGLProc::TLinkProgram>(GL_GET_EXTENSION("glLinkProgram"));
    glShaderSource = reinterpret_cast<NOpenGLProc::TShaderSource>(GL_GET_EXTENSION("glShaderSource"));
    glStencilFuncSeparate = reinterpret_cast<NOpenGLProc::TStencilFuncSeparate>(GL_GET_EXTENSION("glStencilFuncSeparate"));
    glStencilMaskSeparate = reinterpret_cast<NOpenGLProc::TStencilMaskSeparate>(GL_GET_EXTENSION("glStencilMaskSeparate"));
    glStencilOpSeparate = reinterpret_cast<NOpenGLProc::TStencilOpSeparate>(GL_GET_EXTENSION("glStencilOpSeparate"));
    glUniform1f = reinterpret_cast<NOpenGLProc::TUniform1f>(GL_GET_EXTENSION("glUniform1f"));
    glUniform1fv = reinterpret_cast<NOpenGLProc::TUniform1fv>(GL_GET_EXTENSION("glUniform1fv"));
    glUniform1i = reinterpret_cast<NOpenGLProc::TUniform1i>(GL_GET_EXTENSION("glUniform1i"));
    glUniform1iv = reinterpret_cast<NOpenGLProc::TUniform1iv>(GL_GET_EXTENSION("glUniform1iv"));
    glUniform2f = reinterpret_cast<NOpenGLProc::TUniform2f>(GL_GET_EXTENSION("glUniform2f"));
    glUniform2fv = reinterpret_cast<NOpenGLProc::TUniform2fv>(GL_GET_EXTENSION("glUniform2fv"));
    glUniform2i = reinterpret_cast<NOpenGLProc::TUniform2i>(GL_GET_EXTENSION("glUniform2i"));
    glUniform2iv = reinterpret_cast<NOpenGLProc::TUniform2iv>(GL_GET_EXTENSION("glUniform2iv"));
    glUniform3f = reinterpret_cast<NOpenGLProc::TUniform3f>(GL_GET_EXTENSION("glUniform3f"));
    glUniform3fv = reinterpret_cast<NOpenGLProc::TUniform3fv>(GL_GET_EXTENSION("glUniform3fv"));
    glUniform3i = reinterpret_cast<NOpenGLProc::TUniform3i>(GL_GET_EXTENSION("glUniform3i"));
    glUniform3iv = reinterpret_cast<NOpenGLProc::TUniform3iv>(GL_GET_EXTENSION("glUniform3iv"));
    glUniform4f = reinterpret_cast<NOpenGLProc::TUniform4f>(GL_GET_EXTENSION("glUniform4f"));
    glUniform4fv = reinterpret_cast<NOpenGLProc::TUniform4fv>(GL_GET_EXTENSION("glUniform4fv"));
    glUniform4i = reinterpret_cast<NOpenGLProc::TUniform4i>(GL_GET_EXTENSION("glUniform4i"));
    glUniform4iv = reinterpret_cast<NOpenGLProc::TUniform4iv>(GL_GET_EXTENSION("glUniform4iv"));
    glUniformMatrix2fv = reinterpret_cast<NOpenGLProc::TUniformMatrix2fv>(GL_GET_EXTENSION("glUniformMatrix2fv"));
    glUniformMatrix3fv = reinterpret_cast<NOpenGLProc::TUniformMatrix3fv>(GL_GET_EXTENSION("glUniformMatrix3fv"));
    glUniformMatrix4fv = reinterpret_cast<NOpenGLProc::TUniformMatrix4fv>(GL_GET_EXTENSION("glUniformMatrix4fv"));
    glUseProgram = reinterpret_cast<NOpenGLProc::TUseProgram>(GL_GET_EXTENSION("glUseProgram"));
    glValidateProgram = reinterpret_cast<NOpenGLProc::TValidateProgram>(GL_GET_EXTENSION("glValidateProgram"));
    glVertexAttrib1d = reinterpret_cast<NOpenGLProc::TVertexAttrib1d>(GL_GET_EXTENSION("glVertexAttrib1d"));
    glVertexAttrib1dv = reinterpret_cast<NOpenGLProc::TVertexAttrib1dv>(GL_GET_EXTENSION("glVertexAttrib1dv"));
    glVertexAttrib1f = reinterpret_cast<NOpenGLProc::TVertexAttrib1f>(GL_GET_EXTENSION("glVertexAttrib1f"));
    glVertexAttrib1fv = reinterpret_cast<NOpenGLProc::TVertexAttrib1fv>(GL_GET_EXTENSION("glVertexAttrib1fv"));
    glVertexAttrib1s = reinterpret_cast<NOpenGLProc::TVertexAttrib1s>(GL_GET_EXTENSION("glVertexAttrib1s"));
    glVertexAttrib1sv = reinterpret_cast<NOpenGLProc::TVertexAttrib1sv>(GL_GET_EXTENSION("glVertexAttrib1sv"));
    glVertexAttrib2d = reinterpret_cast<NOpenGLProc::TVertexAttrib2d>(GL_GET_EXTENSION("glVertexAttrib2d"));
    glVertexAttrib2dv = reinterpret_cast<NOpenGLProc::TVertexAttrib2dv>(GL_GET_EXTENSION("glVertexAttrib2dv"));
    glVertexAttrib2f = reinterpret_cast<NOpenGLProc::TVertexAttrib2f>(GL_GET_EXTENSION("glVertexAttrib2f"));
    glVertexAttrib2fv = reinterpret_cast<NOpenGLProc::TVertexAttrib2fv>(GL_GET_EXTENSION("glVertexAttrib2fv"));
    glVertexAttrib2s = reinterpret_cast<NOpenGLProc::TVertexAttrib2s>(GL_GET_EXTENSION("glVertexAttrib2s"));
    glVertexAttrib2sv = reinterpret_cast<NOpenGLProc::TVertexAttrib2sv>(GL_GET_EXTENSION("glVertexAttrib2sv"));
    glVertexAttrib3d = reinterpret_cast<NOpenGLProc::TVertexAttrib3d>(GL_GET_EXTENSION("glVertexAttrib3d"));
    glVertexAttrib3dv = reinterpret_cast<NOpenGLProc::TVertexAttrib3dv>(GL_GET_EXTENSION("glVertexAttrib3dv"));
    glVertexAttrib3f = reinterpret_cast<NOpenGLProc::TVertexAttrib3f>(GL_GET_EXTENSION("glVertexAttrib3f"));
    glVertexAttrib3fv = reinterpret_cast<NOpenGLProc::TVertexAttrib3fv>(GL_GET_EXTENSION("glVertexAttrib3fv"));
    glVertexAttrib3s = reinterpret_cast<NOpenGLProc::TVertexAttrib3s>(GL_GET_EXTENSION("glVertexAttrib3s"));
    glVertexAttrib3sv = reinterpret_cast<NOpenGLProc::TVertexAttrib3sv>(GL_GET_EXTENSION("glVertexAttrib3sv"));
    glVertexAttrib4Nbv = reinterpret_cast<NOpenGLProc::TVertexAttrib4Nbv>(GL_GET_EXTENSION("glVertexAttrib4Nbv"));
    glVertexAttrib4Niv = reinterpret_cast<NOpenGLProc::TVertexAttrib4Niv>(GL_GET_EXTENSION("glVertexAttrib4Niv"));
    glVertexAttrib4Nsv = reinterpret_cast<NOpenGLProc::TVertexAttrib4Nsv>(GL_GET_EXTENSION("glVertexAttrib4Nsv"));
    glVertexAttrib4Nub = reinterpret_cast<NOpenGLProc::TVertexAttrib4Nub>(GL_GET_EXTENSION("glVertexAttrib4Nub"));
    glVertexAttrib4Nubv = reinterpret_cast<NOpenGLProc::TVertexAttrib4Nubv>(GL_GET_EXTENSION("glVertexAttrib4Nubv"));
    glVertexAttrib4Nuiv = reinterpret_cast<NOpenGLProc::TVertexAttrib4Nuiv>(GL_GET_EXTENSION("glVertexAttrib4Nuiv"));
    glVertexAttrib4Nusv = reinterpret_cast<NOpenGLProc::TVertexAttrib4Nusv>(GL_GET_EXTENSION("glVertexAttrib4Nusv"));
    glVertexAttrib4bv = reinterpret_cast<NOpenGLProc::TVertexAttrib4bv>(GL_GET_EXTENSION("glVertexAttrib4bv"));
    glVertexAttrib4d = reinterpret_cast<NOpenGLProc::TVertexAttrib4d>(GL_GET_EXTENSION("glVertexAttrib4d"));
    glVertexAttrib4dv = reinterpret_cast<NOpenGLProc::TVertexAttrib4dv>(GL_GET_EXTENSION("glVertexAttrib4dv"));
    glVertexAttrib4f = reinterpret_cast<NOpenGLProc::TVertexAttrib4f>(GL_GET_EXTENSION("glVertexAttrib4f"));
    glVertexAttrib4fv = reinterpret_cast<NOpenGLProc::TVertexAttrib4fv>(GL_GET_EXTENSION("glVertexAttrib4fv"));
    glVertexAttrib4iv = reinterpret_cast<NOpenGLProc::TVertexAttrib4iv>(GL_GET_EXTENSION("glVertexAttrib4iv"));
    glVertexAttrib4s = reinterpret_cast<NOpenGLProc::TVertexAttrib4s>(GL_GET_EXTENSION("glVertexAttrib4s"));
    glVertexAttrib4sv = reinterpret_cast<NOpenGLProc::TVertexAttrib4sv>(GL_GET_EXTENSION("glVertexAttrib4sv"));
    glVertexAttrib4ubv = reinterpret_cast<NOpenGLProc::TVertexAttrib4ubv>(GL_GET_EXTENSION("glVertexAttrib4ubv"));
    glVertexAttrib4uiv = reinterpret_cast<NOpenGLProc::TVertexAttrib4uiv>(GL_GET_EXTENSION("glVertexAttrib4uiv"));
    glVertexAttrib4usv = reinterpret_cast<NOpenGLProc::TVertexAttrib4usv>(GL_GET_EXTENSION("glVertexAttrib4usv"));
    glVertexAttribPointer = reinterpret_cast<NOpenGLProc::TVertexAttribPointer>(GL_GET_EXTENSION("glVertexAttribPointer"));
  }

  // GL_VERSION_2_1
  if(platform >= NEngine::GPU_PLATFORM_GL0201)
  {
    glUniformMatrix2x3fv = reinterpret_cast<NOpenGLProc::TUniformMatrix2x3fv>(GL_GET_EXTENSION("glUniformMatrix2x3fv"));
    glUniformMatrix2x4fv = reinterpret_cast<NOpenGLProc::TUniformMatrix2x4fv>(GL_GET_EXTENSION("glUniformMatrix2x4fv"));
    glUniformMatrix3x2fv = reinterpret_cast<NOpenGLProc::TUniformMatrix3x2fv>(GL_GET_EXTENSION("glUniformMatrix3x2fv"));
    glUniformMatrix3x4fv = reinterpret_cast<NOpenGLProc::TUniformMatrix3x4fv>(GL_GET_EXTENSION("glUniformMatrix3x4fv"));
    glUniformMatrix4x2fv = reinterpret_cast<NOpenGLProc::TUniformMatrix4x2fv>(GL_GET_EXTENSION("glUniformMatrix4x2fv"));
    glUniformMatrix4x3fv = reinterpret_cast<NOpenGLProc::TUniformMatrix4x3fv>(GL_GET_EXTENSION("glUniformMatrix4x3fv"));
  }

  // GL_VERSION_3_0
  if(platform >= NEngine::GPU_PLATFORM_GL0300)
  {
    glBeginConditionalRender = reinterpret_cast<NOpenGLProc::TBeginConditionalRender>(GL_GET_EXTENSION("glBeginConditionalRender"));
    glBeginTransformFeedback = reinterpret_cast<NOpenGLProc::TBeginTransformFeedback>(GL_GET_EXTENSION("glBeginTransformFeedback"));
    glBindBufferBase = reinterpret_cast<NOpenGLProc::TBindBufferBase>(GL_GET_EXTENSION("glBindBufferBase"));
    glBindBufferRange = reinterpret_cast<NOpenGLProc::TBindBufferRange>(GL_GET_EXTENSION("glBindBufferRange"));
    glBindFragDataLocation = reinterpret_cast<NOpenGLProc::TBindFragDataLocation>(GL_GET_EXTENSION("glBindFragDataLocation"));
    glBindFramebuffer = reinterpret_cast<NOpenGLProc::TBindFramebuffer>(GL_GET_EXTENSION("glBindFramebuffer"));
    glBindRenderbuffer = reinterpret_cast<NOpenGLProc::TBindRenderbuffer>(GL_GET_EXTENSION("glBindRenderbuffer"));
    glBindVertexArray = reinterpret_cast<NOpenGLProc::TBindVertexArray>(GL_GET_EXTENSION("glBindVertexArray"));
    glBlitFramebuffer = reinterpret_cast<NOpenGLProc::TBlitFramebuffer>(GL_GET_EXTENSION("glBlitFramebuffer"));
    glCheckFramebufferStatus = reinterpret_cast<NOpenGLProc::TCheckFramebufferStatus>(GL_GET_EXTENSION("glCheckFramebufferStatus"));
    glClampColor = reinterpret_cast<NOpenGLProc::TClampColor>(GL_GET_EXTENSION("glClampColor"));
    glClearBufferfi = reinterpret_cast<NOpenGLProc::TClearBufferfi>(GL_GET_EXTENSION("glClearBufferfi"));
    glClearBufferfv = reinterpret_cast<NOpenGLProc::TClearBufferfv>(GL_GET_EXTENSION("glClearBufferfv"));
    glClearBufferiv = reinterpret_cast<NOpenGLProc::TClearBufferiv>(GL_GET_EXTENSION("glClearBufferiv"));
    glClearBufferuiv = reinterpret_cast<NOpenGLProc::TClearBufferuiv>(GL_GET_EXTENSION("glClearBufferuiv"));
    glColorMaski = reinterpret_cast<NOpenGLProc::TColorMaski>(GL_GET_EXTENSION("glColorMaski"));
    glDeleteFramebuffers = reinterpret_cast<NOpenGLProc::TDeleteFramebuffers>(GL_GET_EXTENSION("glDeleteFramebuffers"));
    glDeleteRenderbuffers = reinterpret_cast<NOpenGLProc::TDeleteRenderbuffers>(GL_GET_EXTENSION("glDeleteRenderbuffers"));
    glDeleteVertexArrays = reinterpret_cast<NOpenGLProc::TDeleteVertexArrays>(GL_GET_EXTENSION("glDeleteVertexArrays"));
    glDisablei = reinterpret_cast<NOpenGLProc::TDisablei>(GL_GET_EXTENSION("glDisablei"));
    glEnablei = reinterpret_cast<NOpenGLProc::TEnablei>(GL_GET_EXTENSION("glEnablei"));
    glEndConditionalRender = reinterpret_cast<NOpenGLProc::TEndConditionalRender>(GL_GET_EXTENSION("glEndConditionalRender"));
    glEndTransformFeedback = reinterpret_cast<NOpenGLProc::TEndTransformFeedback>(GL_GET_EXTENSION("glEndTransformFeedback"));
    glFlushMappedBufferRange = reinterpret_cast<NOpenGLProc::TFlushMappedBufferRange>(GL_GET_EXTENSION("glFlushMappedBufferRange"));
    glFramebufferRenderbuffer = reinterpret_cast<NOpenGLProc::TFramebufferRenderbuffer>(GL_GET_EXTENSION("glFramebufferRenderbuffer"));
    glFramebufferTexture1D = reinterpret_cast<NOpenGLProc::TFramebufferTexture1D>(GL_GET_EXTENSION("glFramebufferTexture1D"));
    glFramebufferTexture2D = reinterpret_cast<NOpenGLProc::TFramebufferTexture2D>(GL_GET_EXTENSION("glFramebufferTexture2D"));
    glFramebufferTexture3D = reinterpret_cast<NOpenGLProc::TFramebufferTexture3D>(GL_GET_EXTENSION("glFramebufferTexture3D"));
    glFramebufferTextureLayer = reinterpret_cast<NOpenGLProc::TFramebufferTextureLayer>(GL_GET_EXTENSION("glFramebufferTextureLayer"));
    glGenFramebuffers = reinterpret_cast<NOpenGLProc::TGenFramebuffers>(GL_GET_EXTENSION("glGenFramebuffers"));
    glGenRenderbuffers = reinterpret_cast<NOpenGLProc::TGenRenderbuffers>(GL_GET_EXTENSION("glGenRenderbuffers"));
    glGenVertexArrays = reinterpret_cast<NOpenGLProc::TGenVertexArrays>(GL_GET_EXTENSION("glGenVertexArrays"));
    glGenerateMipmap = reinterpret_cast<NOpenGLProc::TGenerateMipmap>(GL_GET_EXTENSION("glGenerateMipmap"));
    glGetBooleani_v = reinterpret_cast<NOpenGLProc::TGetBooleani_v>(GL_GET_EXTENSION("glGetBooleani_v"));
    glGetFragDataLocation = reinterpret_cast<NOpenGLProc::TGetFragDataLocation>(GL_GET_EXTENSION("glGetFragDataLocation"));
    glGetFramebufferAttachmentParameteriv = reinterpret_cast<NOpenGLProc::TGetFramebufferAttachmentParameteriv>(GL_GET_EXTENSION("glGetFramebufferAttachmentParameteriv"));
    glGetIntegeri_v = reinterpret_cast<NOpenGLProc::TGetIntegeri_v>(GL_GET_EXTENSION("glGetIntegeri_v"));
    glGetRenderbufferParameteriv = reinterpret_cast<NOpenGLProc::TGetRenderbufferParameteriv>(GL_GET_EXTENSION("glGetRenderbufferParameteriv"));
    glGetStringi = reinterpret_cast<NOpenGLProc::TGetStringi>(GL_GET_EXTENSION("glGetStringi"));
    glGetTexParameterIiv = reinterpret_cast<NOpenGLProc::TGetTexParameterIiv>(GL_GET_EXTENSION("glGetTexParameterIiv"));
    glGetTexParameterIuiv = reinterpret_cast<NOpenGLProc::TGetTexParameterIuiv>(GL_GET_EXTENSION("glGetTexParameterIuiv"));
    glGetTransformFeedbackVarying = reinterpret_cast<NOpenGLProc::TGetTransformFeedbackVarying>(GL_GET_EXTENSION("glGetTransformFeedbackVarying"));
    glGetUniformuiv = reinterpret_cast<NOpenGLProc::TGetUniformuiv>(GL_GET_EXTENSION("glGetUniformuiv"));
    glGetVertexAttribIiv = reinterpret_cast<NOpenGLProc::TGetVertexAttribIiv>(GL_GET_EXTENSION("glGetVertexAttribIiv"));
    glGetVertexAttribIuiv = reinterpret_cast<NOpenGLProc::TGetVertexAttribIuiv>(GL_GET_EXTENSION("glGetVertexAttribIuiv"));
    glIsEnabledi = reinterpret_cast<NOpenGLProc::TIsEnabledi>(GL_GET_EXTENSION("glIsEnabledi"));
    glIsFramebuffer = reinterpret_cast<NOpenGLProc::TIsFramebuffer>(GL_GET_EXTENSION("glIsFramebuffer"));
    glIsRenderbuffer = reinterpret_cast<NOpenGLProc::TIsRenderbuffer>(GL_GET_EXTENSION("glIsRenderbuffer"));
    glIsVertexArray = reinterpret_cast<NOpenGLProc::TIsVertexArray>(GL_GET_EXTENSION("glIsVertexArray"));
    glMapBufferRange = reinterpret_cast<NOpenGLProc::TMapBufferRange>(GL_GET_EXTENSION("glMapBufferRange"));
    glRenderbufferStorage = reinterpret_cast<NOpenGLProc::TRenderbufferStorage>(GL_GET_EXTENSION("glRenderbufferStorage"));
    glRenderbufferStorageMultisample = reinterpret_cast<NOpenGLProc::TRenderbufferStorageMultisample>(GL_GET_EXTENSION("glRenderbufferStorageMultisample"));
    glTexParameterIiv = reinterpret_cast<NOpenGLProc::TTexParameterIiv>(GL_GET_EXTENSION("glTexParameterIiv"));
    glTexParameterIuiv = reinterpret_cast<NOpenGLProc::TTexParameterIuiv>(GL_GET_EXTENSION("glTexParameterIuiv"));
    glTransformFeedbackVaryings = reinterpret_cast<NOpenGLProc::TTransformFeedbackVaryings>(GL_GET_EXTENSION("glTransformFeedbackVaryings"));
    glUniform1ui = reinterpret_cast<NOpenGLProc::TUniform1ui>(GL_GET_EXTENSION("glUniform1ui"));
    glUniform1uiv = reinterpret_cast<NOpenGLProc::TUniform1uiv>(GL_GET_EXTENSION("glUniform1uiv"));
    glUniform2ui = reinterpret_cast<NOpenGLProc::TUniform2ui>(GL_GET_EXTENSION("glUniform2ui"));
    glUniform2uiv = reinterpret_cast<NOpenGLProc::TUniform2uiv>(GL_GET_EXTENSION("glUniform2uiv"));
    glUniform3ui = reinterpret_cast<NOpenGLProc::TUniform3ui>(GL_GET_EXTENSION("glUniform3ui"));
    glUniform3uiv = reinterpret_cast<NOpenGLProc::TUniform3uiv>(GL_GET_EXTENSION("glUniform3uiv"));
    glUniform4ui = reinterpret_cast<NOpenGLProc::TUniform4ui>(GL_GET_EXTENSION("glUniform4ui"));
    glUniform4uiv = reinterpret_cast<NOpenGLProc::TUniform4uiv>(GL_GET_EXTENSION("glUniform4uiv"));
    glVertexAttribI1i = reinterpret_cast<NOpenGLProc::TVertexAttribI1i>(GL_GET_EXTENSION("glVertexAttribI1i"));
    glVertexAttribI1iv = reinterpret_cast<NOpenGLProc::TVertexAttribI1iv>(GL_GET_EXTENSION("glVertexAttribI1iv"));
    glVertexAttribI1ui = reinterpret_cast<NOpenGLProc::TVertexAttribI1ui>(GL_GET_EXTENSION("glVertexAttribI1ui"));
    glVertexAttribI1uiv = reinterpret_cast<NOpenGLProc::TVertexAttribI1uiv>(GL_GET_EXTENSION("glVertexAttribI1uiv"));
    glVertexAttribI2i = reinterpret_cast<NOpenGLProc::TVertexAttribI2i>(GL_GET_EXTENSION("glVertexAttribI2i"));
    glVertexAttribI2iv = reinterpret_cast<NOpenGLProc::TVertexAttribI2iv>(GL_GET_EXTENSION("glVertexAttribI2iv"));
    glVertexAttribI2ui = reinterpret_cast<NOpenGLProc::TVertexAttribI2ui>(GL_GET_EXTENSION("glVertexAttribI2ui"));
    glVertexAttribI2uiv = reinterpret_cast<NOpenGLProc::TVertexAttribI2uiv>(GL_GET_EXTENSION("glVertexAttribI2uiv"));
    glVertexAttribI3i = reinterpret_cast<NOpenGLProc::TVertexAttribI3i>(GL_GET_EXTENSION("glVertexAttribI3i"));
    glVertexAttribI3iv = reinterpret_cast<NOpenGLProc::TVertexAttribI3iv>(GL_GET_EXTENSION("glVertexAttribI3iv"));
    glVertexAttribI3ui = reinterpret_cast<NOpenGLProc::TVertexAttribI3ui>(GL_GET_EXTENSION("glVertexAttribI3ui"));
    glVertexAttribI3uiv = reinterpret_cast<NOpenGLProc::TVertexAttribI3uiv>(GL_GET_EXTENSION("glVertexAttribI3uiv"));
    glVertexAttribI4bv = reinterpret_cast<NOpenGLProc::TVertexAttribI4bv>(GL_GET_EXTENSION("glVertexAttribI4bv"));
    glVertexAttribI4i = reinterpret_cast<NOpenGLProc::TVertexAttribI4i>(GL_GET_EXTENSION("glVertexAttribI4i"));
    glVertexAttribI4iv = reinterpret_cast<NOpenGLProc::TVertexAttribI4iv>(GL_GET_EXTENSION("glVertexAttribI4iv"));
    glVertexAttribI4sv = reinterpret_cast<NOpenGLProc::TVertexAttribI4sv>(GL_GET_EXTENSION("glVertexAttribI4sv"));
    glVertexAttribI4ubv = reinterpret_cast<NOpenGLProc::TVertexAttribI4ubv>(GL_GET_EXTENSION("glVertexAttribI4ubv"));
    glVertexAttribI4ui = reinterpret_cast<NOpenGLProc::TVertexAttribI4ui>(GL_GET_EXTENSION("glVertexAttribI4ui"));
    glVertexAttribI4uiv = reinterpret_cast<NOpenGLProc::TVertexAttribI4uiv>(GL_GET_EXTENSION("glVertexAttribI4uiv"));
    glVertexAttribI4usv = reinterpret_cast<NOpenGLProc::TVertexAttribI4usv>(GL_GET_EXTENSION("glVertexAttribI4usv"));
    glVertexAttribIPointer = reinterpret_cast<NOpenGLProc::TVertexAttribIPointer>(GL_GET_EXTENSION("glVertexAttribIPointer"));
  }

  // GL_VERSION_3_1
  if(platform >= NEngine::GPU_PLATFORM_GL0301)
  {
    glCopyBufferSubData = reinterpret_cast<NOpenGLProc::TCopyBufferSubData>(GL_GET_EXTENSION("glCopyBufferSubData"));
    glDrawArraysInstanced = reinterpret_cast<NOpenGLProc::TDrawArraysInstanced>(GL_GET_EXTENSION("glDrawArraysInstanced"));
    glDrawElementsInstanced = reinterpret_cast<NOpenGLProc::TDrawElementsInstanced>(GL_GET_EXTENSION("glDrawElementsInstanced"));
    glGetActiveUniformBlockName = reinterpret_cast<NOpenGLProc::TGetActiveUniformBlockName>(GL_GET_EXTENSION("glGetActiveUniformBlockName"));
    glGetActiveUniformBlockiv = reinterpret_cast<NOpenGLProc::TGetActiveUniformBlockiv>(GL_GET_EXTENSION("glGetActiveUniformBlockiv"));
    glGetActiveUniformName = reinterpret_cast<NOpenGLProc::TGetActiveUniformName>(GL_GET_EXTENSION("glGetActiveUniformName"));
    glGetActiveUniformsiv = reinterpret_cast<NOpenGLProc::TGetActiveUniformsiv>(GL_GET_EXTENSION("glGetActiveUniformsiv"));
    glGetUniformBlockIndex = reinterpret_cast<NOpenGLProc::TGetUniformBlockIndex>(GL_GET_EXTENSION("glGetUniformBlockIndex"));
    glGetUniformIndices = reinterpret_cast<NOpenGLProc::TGetUniformIndices>(GL_GET_EXTENSION("glGetUniformIndices"));
    glPrimitiveRestartIndex = reinterpret_cast<NOpenGLProc::TPrimitiveRestartIndex>(GL_GET_EXTENSION("glPrimitiveRestartIndex"));
    glTexBuffer = reinterpret_cast<NOpenGLProc::TTexBuffer>(GL_GET_EXTENSION("glTexBuffer"));
    glUniformBlockBinding = reinterpret_cast<NOpenGLProc::TUniformBlockBinding>(GL_GET_EXTENSION("glUniformBlockBinding"));
  }

  // GL_VERSION_3_2
  if(platform >= NEngine::GPU_PLATFORM_GL0302)
  {
    glClientWaitSync = reinterpret_cast<NOpenGLProc::TClientWaitSync>(GL_GET_EXTENSION("glClientWaitSync"));
    glDeleteSync = reinterpret_cast<NOpenGLProc::TDeleteSync>(GL_GET_EXTENSION("glDeleteSync"));
    glDrawElementsBaseVertex = reinterpret_cast<NOpenGLProc::TDrawElementsBaseVertex>(GL_GET_EXTENSION("glDrawElementsBaseVertex"));
    glDrawElementsInstancedBaseVertex = reinterpret_cast<NOpenGLProc::TDrawElementsInstancedBaseVertex>(GL_GET_EXTENSION("glDrawElementsInstancedBaseVertex"));
    glDrawRangeElementsBaseVertex = reinterpret_cast<NOpenGLProc::TDrawRangeElementsBaseVertex>(GL_GET_EXTENSION("glDrawRangeElementsBaseVertex"));
    glFenceSync = reinterpret_cast<NOpenGLProc::TFenceSync>(GL_GET_EXTENSION("glFenceSync"));
    glFramebufferTexture = reinterpret_cast<NOpenGLProc::TFramebufferTexture>(GL_GET_EXTENSION("glFramebufferTexture"));
    glGetBufferParameteri64v = reinterpret_cast<NOpenGLProc::TGetBufferParameteri64v>(GL_GET_EXTENSION("glGetBufferParameteri64v"));
    glGetInteger64i_v = reinterpret_cast<NOpenGLProc::TGetInteger64i_v>(GL_GET_EXTENSION("glGetInteger64i_v"));
    glGetInteger64v = reinterpret_cast<NOpenGLProc::TGetInteger64v>(GL_GET_EXTENSION("glGetInteger64v"));
    glGetMultisamplefv = reinterpret_cast<NOpenGLProc::TGetMultisamplefv>(GL_GET_EXTENSION("glGetMultisamplefv"));
    glGetSynciv = reinterpret_cast<NOpenGLProc::TGetSynciv>(GL_GET_EXTENSION("glGetSynciv"));
    glIsSync = reinterpret_cast<NOpenGLProc::TIsSync>(GL_GET_EXTENSION("glIsSync"));
    glMultiDrawElementsBaseVertex = reinterpret_cast<NOpenGLProc::TMultiDrawElementsBaseVertex>(GL_GET_EXTENSION("glMultiDrawElementsBaseVertex"));
    glProvokingVertex = reinterpret_cast<NOpenGLProc::TProvokingVertex>(GL_GET_EXTENSION("glProvokingVertex"));
    glSampleMaski = reinterpret_cast<NOpenGLProc::TSampleMaski>(GL_GET_EXTENSION("glSampleMaski"));
    glTexImage2DMultisample = reinterpret_cast<NOpenGLProc::TTexImage2DMultisample>(GL_GET_EXTENSION("glTexImage2DMultisample"));
    glTexImage3DMultisample = reinterpret_cast<NOpenGLProc::TTexImage3DMultisample>(GL_GET_EXTENSION("glTexImage3DMultisample"));
    glWaitSync = reinterpret_cast<NOpenGLProc::TWaitSync>(GL_GET_EXTENSION("glWaitSync"));
  }

  // GL_VERSION_3_3
  if(platform >= NEngine::GPU_PLATFORM_GL0303)
  {
    glBindFragDataLocationIndexed = reinterpret_cast<NOpenGLProc::TBindFragDataLocationIndexed>(GL_GET_EXTENSION("glBindFragDataLocationIndexed"));
    glBindSampler = reinterpret_cast<NOpenGLProc::TBindSampler>(GL_GET_EXTENSION("glBindSampler"));
    glDeleteSamplers = reinterpret_cast<NOpenGLProc::TDeleteSamplers>(GL_GET_EXTENSION("glDeleteSamplers"));
    glGenSamplers = reinterpret_cast<NOpenGLProc::TGenSamplers>(GL_GET_EXTENSION("glGenSamplers"));
    glGetFragDataIndex = reinterpret_cast<NOpenGLProc::TGetFragDataIndex>(GL_GET_EXTENSION("glGetFragDataIndex"));
    glGetQueryObjecti64v = reinterpret_cast<NOpenGLProc::TGetQueryObjecti64v>(GL_GET_EXTENSION("glGetQueryObjecti64v"));
    glGetQueryObjectui64v = reinterpret_cast<NOpenGLProc::TGetQueryObjectui64v>(GL_GET_EXTENSION("glGetQueryObjectui64v"));
    glGetSamplerParameterIiv = reinterpret_cast<NOpenGLProc::TGetSamplerParameterIiv>(GL_GET_EXTENSION("glGetSamplerParameterIiv"));
    glGetSamplerParameterIuiv = reinterpret_cast<NOpenGLProc::TGetSamplerParameterIuiv>(GL_GET_EXTENSION("glGetSamplerParameterIuiv"));
    glGetSamplerParameterfv = reinterpret_cast<NOpenGLProc::TGetSamplerParameterfv>(GL_GET_EXTENSION("glGetSamplerParameterfv"));
    glGetSamplerParameteriv = reinterpret_cast<NOpenGLProc::TGetSamplerParameteriv>(GL_GET_EXTENSION("glGetSamplerParameteriv"));
    glIsSampler = reinterpret_cast<NOpenGLProc::TIsSampler>(GL_GET_EXTENSION("glIsSampler"));
    glQueryCounter = reinterpret_cast<NOpenGLProc::TQueryCounter>(GL_GET_EXTENSION("glQueryCounter"));
    glSamplerParameterIiv = reinterpret_cast<NOpenGLProc::TSamplerParameterIiv>(GL_GET_EXTENSION("glSamplerParameterIiv"));
    glSamplerParameterIuiv = reinterpret_cast<NOpenGLProc::TSamplerParameterIuiv>(GL_GET_EXTENSION("glSamplerParameterIuiv"));
    glSamplerParameterf = reinterpret_cast<NOpenGLProc::TSamplerParameterf>(GL_GET_EXTENSION("glSamplerParameterf"));
    glSamplerParameterfv = reinterpret_cast<NOpenGLProc::TSamplerParameterfv>(GL_GET_EXTENSION("glSamplerParameterfv"));
    glSamplerParameteri = reinterpret_cast<NOpenGLProc::TSamplerParameteri>(GL_GET_EXTENSION("glSamplerParameteri"));
    glSamplerParameteriv = reinterpret_cast<NOpenGLProc::TSamplerParameteriv>(GL_GET_EXTENSION("glSamplerParameteriv"));
    glVertexAttribDivisor = reinterpret_cast<NOpenGLProc::TVertexAttribDivisor>(GL_GET_EXTENSION("glVertexAttribDivisor"));
    glVertexAttribP1ui = reinterpret_cast<NOpenGLProc::TVertexAttribP1ui>(GL_GET_EXTENSION("glVertexAttribP1ui"));
    glVertexAttribP1uiv = reinterpret_cast<NOpenGLProc::TVertexAttribP1uiv>(GL_GET_EXTENSION("glVertexAttribP1uiv"));
    glVertexAttribP2ui = reinterpret_cast<NOpenGLProc::TVertexAttribP2ui>(GL_GET_EXTENSION("glVertexAttribP2ui"));
    glVertexAttribP2uiv = reinterpret_cast<NOpenGLProc::TVertexAttribP2uiv>(GL_GET_EXTENSION("glVertexAttribP2uiv"));
    glVertexAttribP3ui = reinterpret_cast<NOpenGLProc::TVertexAttribP3ui>(GL_GET_EXTENSION("glVertexAttribP3ui"));
    glVertexAttribP3uiv = reinterpret_cast<NOpenGLProc::TVertexAttribP3uiv>(GL_GET_EXTENSION("glVertexAttribP3uiv"));
    glVertexAttribP4ui = reinterpret_cast<NOpenGLProc::TVertexAttribP4ui>(GL_GET_EXTENSION("glVertexAttribP4ui"));
    glVertexAttribP4uiv = reinterpret_cast<NOpenGLProc::TVertexAttribP4uiv>(GL_GET_EXTENSION("glVertexAttribP4uiv"));
  }

  // GL_VERSION_4_0
  if(platform >= NEngine::GPU_PLATFORM_GL0400)
  {
    glBeginQueryIndexed = reinterpret_cast<NOpenGLProc::TBeginQueryIndexed>(GL_GET_EXTENSION("glBeginQueryIndexed"));
    glBindTransformFeedback = reinterpret_cast<NOpenGLProc::TBindTransformFeedback>(GL_GET_EXTENSION("glBindTransformFeedback"));
    glBlendEquationSeparatei = reinterpret_cast<NOpenGLProc::TBlendEquationSeparatei>(GL_GET_EXTENSION("glBlendEquationSeparatei"));
    glBlendEquationi = reinterpret_cast<NOpenGLProc::TBlendEquationi>(GL_GET_EXTENSION("glBlendEquationi"));
    glBlendFuncSeparatei = reinterpret_cast<NOpenGLProc::TBlendFuncSeparatei>(GL_GET_EXTENSION("glBlendFuncSeparatei"));
    glBlendFunci = reinterpret_cast<NOpenGLProc::TBlendFunci>(GL_GET_EXTENSION("glBlendFunci"));
    glDeleteTransformFeedbacks = reinterpret_cast<NOpenGLProc::TDeleteTransformFeedbacks>(GL_GET_EXTENSION("glDeleteTransformFeedbacks"));
    glDrawArraysIndirect = reinterpret_cast<NOpenGLProc::TDrawArraysIndirect>(GL_GET_EXTENSION("glDrawArraysIndirect"));
    glDrawElementsIndirect = reinterpret_cast<NOpenGLProc::TDrawElementsIndirect>(GL_GET_EXTENSION("glDrawElementsIndirect"));
    glDrawTransformFeedback = reinterpret_cast<NOpenGLProc::TDrawTransformFeedback>(GL_GET_EXTENSION("glDrawTransformFeedback"));
    glDrawTransformFeedbackStream = reinterpret_cast<NOpenGLProc::TDrawTransformFeedbackStream>(GL_GET_EXTENSION("glDrawTransformFeedbackStream"));
    glEndQueryIndexed = reinterpret_cast<NOpenGLProc::TEndQueryIndexed>(GL_GET_EXTENSION("glEndQueryIndexed"));
    glGenTransformFeedbacks = reinterpret_cast<NOpenGLProc::TGenTransformFeedbacks>(GL_GET_EXTENSION("glGenTransformFeedbacks"));
    glGetActiveSubroutineName = reinterpret_cast<NOpenGLProc::TGetActiveSubroutineName>(GL_GET_EXTENSION("glGetActiveSubroutineName"));
    glGetActiveSubroutineUniformName = reinterpret_cast<NOpenGLProc::TGetActiveSubroutineUniformName>(GL_GET_EXTENSION("glGetActiveSubroutineUniformName"));
    glGetActiveSubroutineUniformiv = reinterpret_cast<NOpenGLProc::TGetActiveSubroutineUniformiv>(GL_GET_EXTENSION("glGetActiveSubroutineUniformiv"));
    glGetProgramStageiv = reinterpret_cast<NOpenGLProc::TGetProgramStageiv>(GL_GET_EXTENSION("glGetProgramStageiv"));
    glGetQueryIndexediv = reinterpret_cast<NOpenGLProc::TGetQueryIndexediv>(GL_GET_EXTENSION("glGetQueryIndexediv"));
    glGetSubroutineIndex = reinterpret_cast<NOpenGLProc::TGetSubroutineIndex>(GL_GET_EXTENSION("glGetSubroutineIndex"));
    glGetSubroutineUniformLocation = reinterpret_cast<NOpenGLProc::TGetSubroutineUniformLocation>(GL_GET_EXTENSION("glGetSubroutineUniformLocation"));
    glGetUniformSubroutineuiv = reinterpret_cast<NOpenGLProc::TGetUniformSubroutineuiv>(GL_GET_EXTENSION("glGetUniformSubroutineuiv"));
    glGetUniformdv = reinterpret_cast<NOpenGLProc::TGetUniformdv>(GL_GET_EXTENSION("glGetUniformdv"));
    glIsTransformFeedback = reinterpret_cast<NOpenGLProc::TIsTransformFeedback>(GL_GET_EXTENSION("glIsTransformFeedback"));
    glMinSampleShading = reinterpret_cast<NOpenGLProc::TMinSampleShading>(GL_GET_EXTENSION("glMinSampleShading"));
    glPatchParameterfv = reinterpret_cast<NOpenGLProc::TPatchParameterfv>(GL_GET_EXTENSION("glPatchParameterfv"));
    glPatchParameteri = reinterpret_cast<NOpenGLProc::TPatchParameteri>(GL_GET_EXTENSION("glPatchParameteri"));
    glPauseTransformFeedback = reinterpret_cast<NOpenGLProc::TPauseTransformFeedback>(GL_GET_EXTENSION("glPauseTransformFeedback"));
    glResumeTransformFeedback = reinterpret_cast<NOpenGLProc::TResumeTransformFeedback>(GL_GET_EXTENSION("glResumeTransformFeedback"));
    glUniform1d = reinterpret_cast<NOpenGLProc::TUniform1d>(GL_GET_EXTENSION("glUniform1d"));
    glUniform1dv = reinterpret_cast<NOpenGLProc::TUniform1dv>(GL_GET_EXTENSION("glUniform1dv"));
    glUniform2d = reinterpret_cast<NOpenGLProc::TUniform2d>(GL_GET_EXTENSION("glUniform2d"));
    glUniform2dv = reinterpret_cast<NOpenGLProc::TUniform2dv>(GL_GET_EXTENSION("glUniform2dv"));
    glUniform3d = reinterpret_cast<NOpenGLProc::TUniform3d>(GL_GET_EXTENSION("glUniform3d"));
    glUniform3dv = reinterpret_cast<NOpenGLProc::TUniform3dv>(GL_GET_EXTENSION("glUniform3dv"));
    glUniform4d = reinterpret_cast<NOpenGLProc::TUniform4d>(GL_GET_EXTENSION("glUniform4d"));
    glUniform4dv = reinterpret_cast<NOpenGLProc::TUniform4dv>(GL_GET_EXTENSION("glUniform4dv"));
    glUniformMatrix2dv = reinterpret_cast<NOpenGLProc::TUniformMatrix2dv>(GL_GET_EXTENSION("glUniformMatrix2dv"));
    glUniformMatrix2x3dv = reinterpret_cast<NOpenGLProc::TUniformMatrix2x3dv>(GL_GET_EXTENSION("glUniformMatrix2x3dv"));
    glUniformMatrix2x4dv = reinterpret_cast<NOpenGLProc::TUniformMatrix2x4dv>(GL_GET_EXTENSION("glUniformMatrix2x4dv"));
    glUniformMatrix3dv = reinterpret_cast<NOpenGLProc::TUniformMatrix3dv>(GL_GET_EXTENSION("glUniformMatrix3dv"));
    glUniformMatrix3x2dv = reinterpret_cast<NOpenGLProc::TUniformMatrix3x2dv>(GL_GET_EXTENSION("glUniformMatrix3x2dv"));
    glUniformMatrix3x4dv = reinterpret_cast<NOpenGLProc::TUniformMatrix3x4dv>(GL_GET_EXTENSION("glUniformMatrix3x4dv"));
    glUniformMatrix4dv = reinterpret_cast<NOpenGLProc::TUniformMatrix4dv>(GL_GET_EXTENSION("glUniformMatrix4dv"));
    glUniformMatrix4x2dv = reinterpret_cast<NOpenGLProc::TUniformMatrix4x2dv>(GL_GET_EXTENSION("glUniformMatrix4x2dv"));
    glUniformMatrix4x3dv = reinterpret_cast<NOpenGLProc::TUniformMatrix4x3dv>(GL_GET_EXTENSION("glUniformMatrix4x3dv"));
    glUniformSubroutinesuiv = reinterpret_cast<NOpenGLProc::TUniformSubroutinesuiv>(GL_GET_EXTENSION("glUniformSubroutinesuiv"));
  }

  // GL_VERSION_4_1
  if(platform >= NEngine::GPU_PLATFORM_GL0401)
  {
    glActiveShaderProgram = reinterpret_cast<NOpenGLProc::TActiveShaderProgram>(GL_GET_EXTENSION("glActiveShaderProgram"));
    glBindProgramPipeline = reinterpret_cast<NOpenGLProc::TBindProgramPipeline>(GL_GET_EXTENSION("glBindProgramPipeline"));
    glClearDepthf = reinterpret_cast<NOpenGLProc::TClearDepthf>(GL_GET_EXTENSION("glClearDepthf"));
    glCreateShaderProgramv = reinterpret_cast<NOpenGLProc::TCreateShaderProgramv>(GL_GET_EXTENSION("glCreateShaderProgramv"));
    glDeleteProgramPipelines = reinterpret_cast<NOpenGLProc::TDeleteProgramPipelines>(GL_GET_EXTENSION("glDeleteProgramPipelines"));
    glDepthRangeArrayv = reinterpret_cast<NOpenGLProc::TDepthRangeArrayv>(GL_GET_EXTENSION("glDepthRangeArrayv"));
    glDepthRangeIndexed = reinterpret_cast<NOpenGLProc::TDepthRangeIndexed>(GL_GET_EXTENSION("glDepthRangeIndexed"));
    glDepthRangef = reinterpret_cast<NOpenGLProc::TDepthRangef>(GL_GET_EXTENSION("glDepthRangef"));
    glGenProgramPipelines = reinterpret_cast<NOpenGLProc::TGenProgramPipelines>(GL_GET_EXTENSION("glGenProgramPipelines"));
    glGetDoublei_v = reinterpret_cast<NOpenGLProc::TGetDoublei_v>(GL_GET_EXTENSION("glGetDoublei_v"));
    glGetFloati_v = reinterpret_cast<NOpenGLProc::TGetFloati_v>(GL_GET_EXTENSION("glGetFloati_v"));
    glGetProgramBinary = reinterpret_cast<NOpenGLProc::TGetProgramBinary>(GL_GET_EXTENSION("glGetProgramBinary"));
    glGetProgramPipelineInfoLog = reinterpret_cast<NOpenGLProc::TGetProgramPipelineInfoLog>(GL_GET_EXTENSION("glGetProgramPipelineInfoLog"));
    glGetProgramPipelineiv = reinterpret_cast<NOpenGLProc::TGetProgramPipelineiv>(GL_GET_EXTENSION("glGetProgramPipelineiv"));
    glGetShaderPrecisionFormat = reinterpret_cast<NOpenGLProc::TGetShaderPrecisionFormat>(GL_GET_EXTENSION("glGetShaderPrecisionFormat"));
    glGetVertexAttribLdv = reinterpret_cast<NOpenGLProc::TGetVertexAttribLdv>(GL_GET_EXTENSION("glGetVertexAttribLdv"));
    glIsProgramPipeline = reinterpret_cast<NOpenGLProc::TIsProgramPipeline>(GL_GET_EXTENSION("glIsProgramPipeline"));
    glProgramBinary = reinterpret_cast<NOpenGLProc::TProgramBinary>(GL_GET_EXTENSION("glProgramBinary"));
    glProgramParameteri = reinterpret_cast<NOpenGLProc::TProgramParameteri>(GL_GET_EXTENSION("glProgramParameteri"));
    glProgramUniform1d = reinterpret_cast<NOpenGLProc::TProgramUniform1d>(GL_GET_EXTENSION("glProgramUniform1d"));
    glProgramUniform1dv = reinterpret_cast<NOpenGLProc::TProgramUniform1dv>(GL_GET_EXTENSION("glProgramUniform1dv"));
    glProgramUniform1f = reinterpret_cast<NOpenGLProc::TProgramUniform1f>(GL_GET_EXTENSION("glProgramUniform1f"));
    glProgramUniform1fv = reinterpret_cast<NOpenGLProc::TProgramUniform1fv>(GL_GET_EXTENSION("glProgramUniform1fv"));
    glProgramUniform1i = reinterpret_cast<NOpenGLProc::TProgramUniform1i>(GL_GET_EXTENSION("glProgramUniform1i"));
    glProgramUniform1iv = reinterpret_cast<NOpenGLProc::TProgramUniform1iv>(GL_GET_EXTENSION("glProgramUniform1iv"));
    glProgramUniform1ui = reinterpret_cast<NOpenGLProc::TProgramUniform1ui>(GL_GET_EXTENSION("glProgramUniform1ui"));
    glProgramUniform1uiv = reinterpret_cast<NOpenGLProc::TProgramUniform1uiv>(GL_GET_EXTENSION("glProgramUniform1uiv"));
    glProgramUniform2d = reinterpret_cast<NOpenGLProc::TProgramUniform2d>(GL_GET_EXTENSION("glProgramUniform2d"));
    glProgramUniform2dv = reinterpret_cast<NOpenGLProc::TProgramUniform2dv>(GL_GET_EXTENSION("glProgramUniform2dv"));
    glProgramUniform2f = reinterpret_cast<NOpenGLProc::TProgramUniform2f>(GL_GET_EXTENSION("glProgramUniform2f"));
    glProgramUniform2fv = reinterpret_cast<NOpenGLProc::TProgramUniform2fv>(GL_GET_EXTENSION("glProgramUniform2fv"));
    glProgramUniform2i = reinterpret_cast<NOpenGLProc::TProgramUniform2i>(GL_GET_EXTENSION("glProgramUniform2i"));
    glProgramUniform2iv = reinterpret_cast<NOpenGLProc::TProgramUniform2iv>(GL_GET_EXTENSION("glProgramUniform2iv"));
    glProgramUniform2ui = reinterpret_cast<NOpenGLProc::TProgramUniform2ui>(GL_GET_EXTENSION("glProgramUniform2ui"));
    glProgramUniform2uiv = reinterpret_cast<NOpenGLProc::TProgramUniform2uiv>(GL_GET_EXTENSION("glProgramUniform2uiv"));
    glProgramUniform3d = reinterpret_cast<NOpenGLProc::TProgramUniform3d>(GL_GET_EXTENSION("glProgramUniform3d"));
    glProgramUniform3dv = reinterpret_cast<NOpenGLProc::TProgramUniform3dv>(GL_GET_EXTENSION("glProgramUniform3dv"));
    glProgramUniform3f = reinterpret_cast<NOpenGLProc::TProgramUniform3f>(GL_GET_EXTENSION("glProgramUniform3f"));
    glProgramUniform3fv = reinterpret_cast<NOpenGLProc::TProgramUniform3fv>(GL_GET_EXTENSION("glProgramUniform3fv"));
    glProgramUniform3i = reinterpret_cast<NOpenGLProc::TProgramUniform3i>(GL_GET_EXTENSION("glProgramUniform3i"));
    glProgramUniform3iv = reinterpret_cast<NOpenGLProc::TProgramUniform3iv>(GL_GET_EXTENSION("glProgramUniform3iv"));
    glProgramUniform3ui = reinterpret_cast<NOpenGLProc::TProgramUniform3ui>(GL_GET_EXTENSION("glProgramUniform3ui"));
    glProgramUniform3uiv = reinterpret_cast<NOpenGLProc::TProgramUniform3uiv>(GL_GET_EXTENSION("glProgramUniform3uiv"));
    glProgramUniform4d = reinterpret_cast<NOpenGLProc::TProgramUniform4d>(GL_GET_EXTENSION("glProgramUniform4d"));
    glProgramUniform4dv = reinterpret_cast<NOpenGLProc::TProgramUniform4dv>(GL_GET_EXTENSION("glProgramUniform4dv"));
    glProgramUniform4f = reinterpret_cast<NOpenGLProc::TProgramUniform4f>(GL_GET_EXTENSION("glProgramUniform4f"));
    glProgramUniform4fv = reinterpret_cast<NOpenGLProc::TProgramUniform4fv>(GL_GET_EXTENSION("glProgramUniform4fv"));
    glProgramUniform4i = reinterpret_cast<NOpenGLProc::TProgramUniform4i>(GL_GET_EXTENSION("glProgramUniform4i"));
    glProgramUniform4iv = reinterpret_cast<NOpenGLProc::TProgramUniform4iv>(GL_GET_EXTENSION("glProgramUniform4iv"));
    glProgramUniform4ui = reinterpret_cast<NOpenGLProc::TProgramUniform4ui>(GL_GET_EXTENSION("glProgramUniform4ui"));
    glProgramUniform4uiv = reinterpret_cast<NOpenGLProc::TProgramUniform4uiv>(GL_GET_EXTENSION("glProgramUniform4uiv"));
    glProgramUniformMatrix2dv = reinterpret_cast<NOpenGLProc::TProgramUniformMatrix2dv>(GL_GET_EXTENSION("glProgramUniformMatrix2dv"));
    glProgramUniformMatrix2fv = reinterpret_cast<NOpenGLProc::TProgramUniformMatrix2fv>(GL_GET_EXTENSION("glProgramUniformMatrix2fv"));
    glProgramUniformMatrix2x3dv = reinterpret_cast<NOpenGLProc::TProgramUniformMatrix2x3dv>(GL_GET_EXTENSION("glProgramUniformMatrix2x3dv"));
    glProgramUniformMatrix2x3fv = reinterpret_cast<NOpenGLProc::TProgramUniformMatrix2x3fv>(GL_GET_EXTENSION("glProgramUniformMatrix2x3fv"));
    glProgramUniformMatrix2x4dv = reinterpret_cast<NOpenGLProc::TProgramUniformMatrix2x4dv>(GL_GET_EXTENSION("glProgramUniformMatrix2x4dv"));
    glProgramUniformMatrix2x4fv = reinterpret_cast<NOpenGLProc::TProgramUniformMatrix2x4fv>(GL_GET_EXTENSION("glProgramUniformMatrix2x4fv"));
    glProgramUniformMatrix3dv = reinterpret_cast<NOpenGLProc::TProgramUniformMatrix3dv>(GL_GET_EXTENSION("glProgramUniformMatrix3dv"));
    glProgramUniformMatrix3fv = reinterpret_cast<NOpenGLProc::TProgramUniformMatrix3fv>(GL_GET_EXTENSION("glProgramUniformMatrix3fv"));
    glProgramUniformMatrix3x2dv = reinterpret_cast<NOpenGLProc::TProgramUniformMatrix3x2dv>(GL_GET_EXTENSION("glProgramUniformMatrix3x2dv"));
    glProgramUniformMatrix3x2fv = reinterpret_cast<NOpenGLProc::TProgramUniformMatrix3x2fv>(GL_GET_EXTENSION("glProgramUniformMatrix3x2fv"));
    glProgramUniformMatrix3x4dv = reinterpret_cast<NOpenGLProc::TProgramUniformMatrix3x4dv>(GL_GET_EXTENSION("glProgramUniformMatrix3x4dv"));
    glProgramUniformMatrix3x4fv = reinterpret_cast<NOpenGLProc::TProgramUniformMatrix3x4fv>(GL_GET_EXTENSION("glProgramUniformMatrix3x4fv"));
    glProgramUniformMatrix4dv = reinterpret_cast<NOpenGLProc::TProgramUniformMatrix4dv>(GL_GET_EXTENSION("glProgramUniformMatrix4dv"));
    glProgramUniformMatrix4fv = reinterpret_cast<NOpenGLProc::TProgramUniformMatrix4fv>(GL_GET_EXTENSION("glProgramUniformMatrix4fv"));
    glProgramUniformMatrix4x2dv = reinterpret_cast<NOpenGLProc::TProgramUniformMatrix4x2dv>(GL_GET_EXTENSION("glProgramUniformMatrix4x2dv"));
    glProgramUniformMatrix4x2fv = reinterpret_cast<NOpenGLProc::TProgramUniformMatrix4x2fv>(GL_GET_EXTENSION("glProgramUniformMatrix4x2fv"));
    glProgramUniformMatrix4x3dv = reinterpret_cast<NOpenGLProc::TProgramUniformMatrix4x3dv>(GL_GET_EXTENSION("glProgramUniformMatrix4x3dv"));
    glProgramUniformMatrix4x3fv = reinterpret_cast<NOpenGLProc::TProgramUniformMatrix4x3fv>(GL_GET_EXTENSION("glProgramUniformMatrix4x3fv"));
    glReleaseShaderCompiler = reinterpret_cast<NOpenGLProc::TReleaseShaderCompiler>(GL_GET_EXTENSION("glReleaseShaderCompiler"));
    glScissorArrayv = reinterpret_cast<NOpenGLProc::TScissorArrayv>(GL_GET_EXTENSION("glScissorArrayv"));
    glScissorIndexed = reinterpret_cast<NOpenGLProc::TScissorIndexed>(GL_GET_EXTENSION("glScissorIndexed"));
    glScissorIndexedv = reinterpret_cast<NOpenGLProc::TScissorIndexedv>(GL_GET_EXTENSION("glScissorIndexedv"));
    glShaderBinary = reinterpret_cast<NOpenGLProc::TShaderBinary>(GL_GET_EXTENSION("glShaderBinary"));
    glUseProgramStages = reinterpret_cast<NOpenGLProc::TUseProgramStages>(GL_GET_EXTENSION("glUseProgramStages"));
    glValidateProgramPipeline = reinterpret_cast<NOpenGLProc::TValidateProgramPipeline>(GL_GET_EXTENSION("glValidateProgramPipeline"));
    glVertexAttribL1d = reinterpret_cast<NOpenGLProc::TVertexAttribL1d>(GL_GET_EXTENSION("glVertexAttribL1d"));
    glVertexAttribL1dv = reinterpret_cast<NOpenGLProc::TVertexAttribL1dv>(GL_GET_EXTENSION("glVertexAttribL1dv"));
    glVertexAttribL2d = reinterpret_cast<NOpenGLProc::TVertexAttribL2d>(GL_GET_EXTENSION("glVertexAttribL2d"));
    glVertexAttribL2dv = reinterpret_cast<NOpenGLProc::TVertexAttribL2dv>(GL_GET_EXTENSION("glVertexAttribL2dv"));
    glVertexAttribL3d = reinterpret_cast<NOpenGLProc::TVertexAttribL3d>(GL_GET_EXTENSION("glVertexAttribL3d"));
    glVertexAttribL3dv = reinterpret_cast<NOpenGLProc::TVertexAttribL3dv>(GL_GET_EXTENSION("glVertexAttribL3dv"));
    glVertexAttribL4d = reinterpret_cast<NOpenGLProc::TVertexAttribL4d>(GL_GET_EXTENSION("glVertexAttribL4d"));
    glVertexAttribL4dv = reinterpret_cast<NOpenGLProc::TVertexAttribL4dv>(GL_GET_EXTENSION("glVertexAttribL4dv"));
    glVertexAttribLPointer = reinterpret_cast<NOpenGLProc::TVertexAttribLPointer>(GL_GET_EXTENSION("glVertexAttribLPointer"));
    glViewportArrayv = reinterpret_cast<NOpenGLProc::TViewportArrayv>(GL_GET_EXTENSION("glViewportArrayv"));
    glViewportIndexedf = reinterpret_cast<NOpenGLProc::TViewportIndexedf>(GL_GET_EXTENSION("glViewportIndexedf"));
    glViewportIndexedfv = reinterpret_cast<NOpenGLProc::TViewportIndexedfv>(GL_GET_EXTENSION("glViewportIndexedfv"));
  }

  // GL_VERSION_4_2
  if(platform >= NEngine::GPU_PLATFORM_GL0402)
  {
    glBindImageTexture = reinterpret_cast<NOpenGLProc::TBindImageTexture>(GL_GET_EXTENSION("glBindImageTexture"));
    glDrawArraysInstancedBaseInstance = reinterpret_cast<NOpenGLProc::TDrawArraysInstancedBaseInstance>(GL_GET_EXTENSION("glDrawArraysInstancedBaseInstance"));
    glDrawElementsInstancedBaseInstance = reinterpret_cast<NOpenGLProc::TDrawElementsInstancedBaseInstance>(GL_GET_EXTENSION("glDrawElementsInstancedBaseInstance"));
    glDrawElementsInstancedBaseVertexBaseInstance = reinterpret_cast<NOpenGLProc::TDrawElementsInstancedBaseVertexBaseInstance>(GL_GET_EXTENSION("glDrawElementsInstancedBaseVertexBaseInstance"));
    glDrawTransformFeedbackInstanced = reinterpret_cast<NOpenGLProc::TDrawTransformFeedbackInstanced>(GL_GET_EXTENSION("glDrawTransformFeedbackInstanced"));
    glDrawTransformFeedbackStreamInstanced = reinterpret_cast<NOpenGLProc::TDrawTransformFeedbackStreamInstanced>(GL_GET_EXTENSION("glDrawTransformFeedbackStreamInstanced"));
    glGetActiveAtomicCounterBufferiv = reinterpret_cast<NOpenGLProc::TGetActiveAtomicCounterBufferiv>(GL_GET_EXTENSION("glGetActiveAtomicCounterBufferiv"));
    glGetInternalformativ = reinterpret_cast<NOpenGLProc::TGetInternalformativ>(GL_GET_EXTENSION("glGetInternalformativ"));
    glMemoryBarrier = reinterpret_cast<NOpenGLProc::TMemoryBarrier>(GL_GET_EXTENSION("glMemoryBarrier"));
    glTexStorage1D = reinterpret_cast<NOpenGLProc::TTexStorage1D>(GL_GET_EXTENSION("glTexStorage1D"));
    glTexStorage2D = reinterpret_cast<NOpenGLProc::TTexStorage2D>(GL_GET_EXTENSION("glTexStorage2D"));
    glTexStorage3D = reinterpret_cast<NOpenGLProc::TTexStorage3D>(GL_GET_EXTENSION("glTexStorage3D"));
  }

  // GL_VERSION_4_3
  if(platform >= NEngine::GPU_PLATFORM_GL0403)
  {
    glBindVertexBuffer = reinterpret_cast<NOpenGLProc::TBindVertexBuffer>(GL_GET_EXTENSION("glBindVertexBuffer"));
    glClearBufferData = reinterpret_cast<NOpenGLProc::TClearBufferData>(GL_GET_EXTENSION("glClearBufferData"));
    glClearBufferSubData = reinterpret_cast<NOpenGLProc::TClearBufferSubData>(GL_GET_EXTENSION("glClearBufferSubData"));
    glCopyImageSubData = reinterpret_cast<NOpenGLProc::TCopyImageSubData>(GL_GET_EXTENSION("glCopyImageSubData"));
    glDebugMessageCallback = reinterpret_cast<NOpenGLProc::TDebugMessageCallback>(GL_GET_EXTENSION("glDebugMessageCallback"));
    glDebugMessageControl = reinterpret_cast<NOpenGLProc::TDebugMessageControl>(GL_GET_EXTENSION("glDebugMessageControl"));
    glDebugMessageInsert = reinterpret_cast<NOpenGLProc::TDebugMessageInsert>(GL_GET_EXTENSION("glDebugMessageInsert"));
    glDispatchCompute = reinterpret_cast<NOpenGLProc::TDispatchCompute>(GL_GET_EXTENSION("glDispatchCompute"));
    glDispatchComputeIndirect = reinterpret_cast<NOpenGLProc::TDispatchComputeIndirect>(GL_GET_EXTENSION("glDispatchComputeIndirect"));
    glFramebufferParameteri = reinterpret_cast<NOpenGLProc::TFramebufferParameteri>(GL_GET_EXTENSION("glFramebufferParameteri"));
    glGetDebugMessageLog = reinterpret_cast<NOpenGLProc::TGetDebugMessageLog>(GL_GET_EXTENSION("glGetDebugMessageLog"));
    glGetFramebufferParameteriv = reinterpret_cast<NOpenGLProc::TGetFramebufferParameteriv>(GL_GET_EXTENSION("glGetFramebufferParameteriv"));
    glGetInternalformati64v = reinterpret_cast<NOpenGLProc::TGetInternalformati64v>(GL_GET_EXTENSION("glGetInternalformati64v"));
    glGetObjectLabel = reinterpret_cast<NOpenGLProc::TGetObjectLabel>(GL_GET_EXTENSION("glGetObjectLabel"));
    glGetObjectPtrLabel = reinterpret_cast<NOpenGLProc::TGetObjectPtrLabel>(GL_GET_EXTENSION("glGetObjectPtrLabel"));
    glGetProgramInterfaceiv = reinterpret_cast<NOpenGLProc::TGetProgramInterfaceiv>(GL_GET_EXTENSION("glGetProgramInterfaceiv"));
    glGetProgramResourceIndex = reinterpret_cast<NOpenGLProc::TGetProgramResourceIndex>(GL_GET_EXTENSION("glGetProgramResourceIndex"));
    glGetProgramResourceLocation = reinterpret_cast<NOpenGLProc::TGetProgramResourceLocation>(GL_GET_EXTENSION("glGetProgramResourceLocation"));
    glGetProgramResourceLocationIndex = reinterpret_cast<NOpenGLProc::TGetProgramResourceLocationIndex>(GL_GET_EXTENSION("glGetProgramResourceLocationIndex"));
    glGetProgramResourceName = reinterpret_cast<NOpenGLProc::TGetProgramResourceName>(GL_GET_EXTENSION("glGetProgramResourceName"));
    glGetProgramResourceiv = reinterpret_cast<NOpenGLProc::TGetProgramResourceiv>(GL_GET_EXTENSION("glGetProgramResourceiv"));
    glInvalidateBufferData = reinterpret_cast<NOpenGLProc::TInvalidateBufferData>(GL_GET_EXTENSION("glInvalidateBufferData"));
    glInvalidateBufferSubData = reinterpret_cast<NOpenGLProc::TInvalidateBufferSubData>(GL_GET_EXTENSION("glInvalidateBufferSubData"));
    glInvalidateFramebuffer = reinterpret_cast<NOpenGLProc::TInvalidateFramebuffer>(GL_GET_EXTENSION("glInvalidateFramebuffer"));
    glInvalidateSubFramebuffer = reinterpret_cast<NOpenGLProc::TInvalidateSubFramebuffer>(GL_GET_EXTENSION("glInvalidateSubFramebuffer"));
    glInvalidateTexImage = reinterpret_cast<NOpenGLProc::TInvalidateTexImage>(GL_GET_EXTENSION("glInvalidateTexImage"));
    glInvalidateTexSubImage = reinterpret_cast<NOpenGLProc::TInvalidateTexSubImage>(GL_GET_EXTENSION("glInvalidateTexSubImage"));
    glMultiDrawArraysIndirect = reinterpret_cast<NOpenGLProc::TMultiDrawArraysIndirect>(GL_GET_EXTENSION("glMultiDrawArraysIndirect"));
    glMultiDrawElementsIndirect = reinterpret_cast<NOpenGLProc::TMultiDrawElementsIndirect>(GL_GET_EXTENSION("glMultiDrawElementsIndirect"));
    glObjectLabel = reinterpret_cast<NOpenGLProc::TObjectLabel>(GL_GET_EXTENSION("glObjectLabel"));
    glObjectPtrLabel = reinterpret_cast<NOpenGLProc::TObjectPtrLabel>(GL_GET_EXTENSION("glObjectPtrLabel"));
    glPopDebugGroup = reinterpret_cast<NOpenGLProc::TPopDebugGroup>(GL_GET_EXTENSION("glPopDebugGroup"));
    glPushDebugGroup = reinterpret_cast<NOpenGLProc::TPushDebugGroup>(GL_GET_EXTENSION("glPushDebugGroup"));
    glShaderStorageBlockBinding = reinterpret_cast<NOpenGLProc::TShaderStorageBlockBinding>(GL_GET_EXTENSION("glShaderStorageBlockBinding"));
    glTexBufferRange = reinterpret_cast<NOpenGLProc::TTexBufferRange>(GL_GET_EXTENSION("glTexBufferRange"));
    glTexStorage2DMultisample = reinterpret_cast<NOpenGLProc::TTexStorage2DMultisample>(GL_GET_EXTENSION("glTexStorage2DMultisample"));
    glTexStorage3DMultisample = reinterpret_cast<NOpenGLProc::TTexStorage3DMultisample>(GL_GET_EXTENSION("glTexStorage3DMultisample"));
    glTextureView = reinterpret_cast<NOpenGLProc::TTextureView>(GL_GET_EXTENSION("glTextureView"));
    glVertexAttribBinding = reinterpret_cast<NOpenGLProc::TVertexAttribBinding>(GL_GET_EXTENSION("glVertexAttribBinding"));
    glVertexAttribFormat = reinterpret_cast<NOpenGLProc::TVertexAttribFormat>(GL_GET_EXTENSION("glVertexAttribFormat"));
    glVertexAttribIFormat = reinterpret_cast<NOpenGLProc::TVertexAttribIFormat>(GL_GET_EXTENSION("glVertexAttribIFormat"));
    glVertexAttribLFormat = reinterpret_cast<NOpenGLProc::TVertexAttribLFormat>(GL_GET_EXTENSION("glVertexAttribLFormat"));
    glVertexBindingDivisor = reinterpret_cast<NOpenGLProc::TVertexBindingDivisor>(GL_GET_EXTENSION("glVertexBindingDivisor"));
  }

  // GL_VERSION_4_4
  if(platform >= NEngine::GPU_PLATFORM_GL0404)
  {
    glBindBuffersBase = reinterpret_cast<NOpenGLProc::TBindBuffersBase>(GL_GET_EXTENSION("glBindBuffersBase"));
    glBindBuffersRange = reinterpret_cast<NOpenGLProc::TBindBuffersRange>(GL_GET_EXTENSION("glBindBuffersRange"));
    glBindImageTextures = reinterpret_cast<NOpenGLProc::TBindImageTextures>(GL_GET_EXTENSION("glBindImageTextures"));
    glBindSamplers = reinterpret_cast<NOpenGLProc::TBindSamplers>(GL_GET_EXTENSION("glBindSamplers"));
    glBindTextures = reinterpret_cast<NOpenGLProc::TBindTextures>(GL_GET_EXTENSION("glBindTextures"));
    glBindVertexBuffers = reinterpret_cast<NOpenGLProc::TBindVertexBuffers>(GL_GET_EXTENSION("glBindVertexBuffers"));
    glBufferStorage = reinterpret_cast<NOpenGLProc::TBufferStorage>(GL_GET_EXTENSION("glBufferStorage"));
    glClearTexImage = reinterpret_cast<NOpenGLProc::TClearTexImage>(GL_GET_EXTENSION("glClearTexImage"));
    glClearTexSubImage = reinterpret_cast<NOpenGLProc::TClearTexSubImage>(GL_GET_EXTENSION("glClearTexSubImage"));
  }

  // GL_VERSION_4_5
  if(platform >= NEngine::GPU_PLATFORM_GL0405)
  {
    glBindTextureUnit = reinterpret_cast<NOpenGLProc::TBindTextureUnit>(GL_GET_EXTENSION("glBindTextureUnit"));
    glBlitNamedFramebuffer = reinterpret_cast<NOpenGLProc::TBlitNamedFramebuffer>(GL_GET_EXTENSION("glBlitNamedFramebuffer"));
    glCheckNamedFramebufferStatus = reinterpret_cast<NOpenGLProc::TCheckNamedFramebufferStatus>(GL_GET_EXTENSION("glCheckNamedFramebufferStatus"));
    glClearNamedBufferData = reinterpret_cast<NOpenGLProc::TClearNamedBufferData>(GL_GET_EXTENSION("glClearNamedBufferData"));
    glClearNamedBufferSubData = reinterpret_cast<NOpenGLProc::TClearNamedBufferSubData>(GL_GET_EXTENSION("glClearNamedBufferSubData"));
    glClearNamedFramebufferfi = reinterpret_cast<NOpenGLProc::TClearNamedFramebufferfi>(GL_GET_EXTENSION("glClearNamedFramebufferfi"));
    glClearNamedFramebufferfv = reinterpret_cast<NOpenGLProc::TClearNamedFramebufferfv>(GL_GET_EXTENSION("glClearNamedFramebufferfv"));
    glClearNamedFramebufferiv = reinterpret_cast<NOpenGLProc::TClearNamedFramebufferiv>(GL_GET_EXTENSION("glClearNamedFramebufferiv"));
    glClearNamedFramebufferuiv = reinterpret_cast<NOpenGLProc::TClearNamedFramebufferuiv>(GL_GET_EXTENSION("glClearNamedFramebufferuiv"));
    glClipControl = reinterpret_cast<NOpenGLProc::TClipControl>(GL_GET_EXTENSION("glClipControl"));
    glCompressedTextureSubImage1D = reinterpret_cast<NOpenGLProc::TCompressedTextureSubImage1D>(GL_GET_EXTENSION("glCompressedTextureSubImage1D"));
    glCompressedTextureSubImage2D = reinterpret_cast<NOpenGLProc::TCompressedTextureSubImage2D>(GL_GET_EXTENSION("glCompressedTextureSubImage2D"));
    glCompressedTextureSubImage3D = reinterpret_cast<NOpenGLProc::TCompressedTextureSubImage3D>(GL_GET_EXTENSION("glCompressedTextureSubImage3D"));
    glCopyNamedBufferSubData = reinterpret_cast<NOpenGLProc::TCopyNamedBufferSubData>(GL_GET_EXTENSION("glCopyNamedBufferSubData"));
    glCopyTextureSubImage1D = reinterpret_cast<NOpenGLProc::TCopyTextureSubImage1D>(GL_GET_EXTENSION("glCopyTextureSubImage1D"));
    glCopyTextureSubImage2D = reinterpret_cast<NOpenGLProc::TCopyTextureSubImage2D>(GL_GET_EXTENSION("glCopyTextureSubImage2D"));
    glCopyTextureSubImage3D = reinterpret_cast<NOpenGLProc::TCopyTextureSubImage3D>(GL_GET_EXTENSION("glCopyTextureSubImage3D"));
    glCreateBuffers = reinterpret_cast<NOpenGLProc::TCreateBuffers>(GL_GET_EXTENSION("glCreateBuffers"));
    glCreateFramebuffers = reinterpret_cast<NOpenGLProc::TCreateFramebuffers>(GL_GET_EXTENSION("glCreateFramebuffers"));
    glCreateProgramPipelines = reinterpret_cast<NOpenGLProc::TCreateProgramPipelines>(GL_GET_EXTENSION("glCreateProgramPipelines"));
    glCreateQueries = reinterpret_cast<NOpenGLProc::TCreateQueries>(GL_GET_EXTENSION("glCreateQueries"));
    glCreateRenderbuffers = reinterpret_cast<NOpenGLProc::TCreateRenderbuffers>(GL_GET_EXTENSION("glCreateRenderbuffers"));
    glCreateSamplers = reinterpret_cast<NOpenGLProc::TCreateSamplers>(GL_GET_EXTENSION("glCreateSamplers"));
    glCreateTextures = reinterpret_cast<NOpenGLProc::TCreateTextures>(GL_GET_EXTENSION("glCreateTextures"));
    glCreateTransformFeedbacks = reinterpret_cast<NOpenGLProc::TCreateTransformFeedbacks>(GL_GET_EXTENSION("glCreateTransformFeedbacks"));
    glCreateVertexArrays = reinterpret_cast<NOpenGLProc::TCreateVertexArrays>(GL_GET_EXTENSION("glCreateVertexArrays"));
    glDisableVertexArrayAttrib = reinterpret_cast<NOpenGLProc::TDisableVertexArrayAttrib>(GL_GET_EXTENSION("glDisableVertexArrayAttrib"));
    glEnableVertexArrayAttrib = reinterpret_cast<NOpenGLProc::TEnableVertexArrayAttrib>(GL_GET_EXTENSION("glEnableVertexArrayAttrib"));
    glFlushMappedNamedBufferRange = reinterpret_cast<NOpenGLProc::TFlushMappedNamedBufferRange>(GL_GET_EXTENSION("glFlushMappedNamedBufferRange"));
    glGenerateTextureMipmap = reinterpret_cast<NOpenGLProc::TGenerateTextureMipmap>(GL_GET_EXTENSION("glGenerateTextureMipmap"));
    glGetCompressedTextureImage = reinterpret_cast<NOpenGLProc::TGetCompressedTextureImage>(GL_GET_EXTENSION("glGetCompressedTextureImage"));
    glGetCompressedTextureSubImage = reinterpret_cast<NOpenGLProc::TGetCompressedTextureSubImage>(GL_GET_EXTENSION("glGetCompressedTextureSubImage"));
    glGetGraphicsResetStatus = reinterpret_cast<NOpenGLProc::TGetGraphicsResetStatus>(GL_GET_EXTENSION("glGetGraphicsResetStatus"));
    glGetNamedBufferParameteri64v = reinterpret_cast<NOpenGLProc::TGetNamedBufferParameteri64v>(GL_GET_EXTENSION("glGetNamedBufferParameteri64v"));
    glGetNamedBufferParameteriv = reinterpret_cast<NOpenGLProc::TGetNamedBufferParameteriv>(GL_GET_EXTENSION("glGetNamedBufferParameteriv"));
    glGetNamedBufferPointerv = reinterpret_cast<NOpenGLProc::TGetNamedBufferPointerv>(GL_GET_EXTENSION("glGetNamedBufferPointerv"));
    glGetNamedBufferSubData = reinterpret_cast<NOpenGLProc::TGetNamedBufferSubData>(GL_GET_EXTENSION("glGetNamedBufferSubData"));
    glGetNamedFramebufferAttachmentParameteriv = reinterpret_cast<NOpenGLProc::TGetNamedFramebufferAttachmentParameteriv>(GL_GET_EXTENSION("glGetNamedFramebufferAttachmentParameteriv"));
    glGetNamedFramebufferParameteriv = reinterpret_cast<NOpenGLProc::TGetNamedFramebufferParameteriv>(GL_GET_EXTENSION("glGetNamedFramebufferParameteriv"));
    glGetNamedRenderbufferParameteriv = reinterpret_cast<NOpenGLProc::TGetNamedRenderbufferParameteriv>(GL_GET_EXTENSION("glGetNamedRenderbufferParameteriv"));
    glGetQueryBufferObjecti64v = reinterpret_cast<NOpenGLProc::TGetQueryBufferObjecti64v>(GL_GET_EXTENSION("glGetQueryBufferObjecti64v"));
    glGetQueryBufferObjectiv = reinterpret_cast<NOpenGLProc::TGetQueryBufferObjectiv>(GL_GET_EXTENSION("glGetQueryBufferObjectiv"));
    glGetQueryBufferObjectui64v = reinterpret_cast<NOpenGLProc::TGetQueryBufferObjectui64v>(GL_GET_EXTENSION("glGetQueryBufferObjectui64v"));
    glGetQueryBufferObjectuiv = reinterpret_cast<NOpenGLProc::TGetQueryBufferObjectuiv>(GL_GET_EXTENSION("glGetQueryBufferObjectuiv"));
    glGetTextureImage = reinterpret_cast<NOpenGLProc::TGetTextureImage>(GL_GET_EXTENSION("glGetTextureImage"));
    glGetTextureLevelParameterfv = reinterpret_cast<NOpenGLProc::TGetTextureLevelParameterfv>(GL_GET_EXTENSION("glGetTextureLevelParameterfv"));
    glGetTextureLevelParameteriv = reinterpret_cast<NOpenGLProc::TGetTextureLevelParameteriv>(GL_GET_EXTENSION("glGetTextureLevelParameteriv"));
    glGetTextureParameterIiv = reinterpret_cast<NOpenGLProc::TGetTextureParameterIiv>(GL_GET_EXTENSION("glGetTextureParameterIiv"));
    glGetTextureParameterIuiv = reinterpret_cast<NOpenGLProc::TGetTextureParameterIuiv>(GL_GET_EXTENSION("glGetTextureParameterIuiv"));
    glGetTextureParameterfv = reinterpret_cast<NOpenGLProc::TGetTextureParameterfv>(GL_GET_EXTENSION("glGetTextureParameterfv"));
    glGetTextureParameteriv = reinterpret_cast<NOpenGLProc::TGetTextureParameteriv>(GL_GET_EXTENSION("glGetTextureParameteriv"));
    glGetTextureSubImage = reinterpret_cast<NOpenGLProc::TGetTextureSubImage>(GL_GET_EXTENSION("glGetTextureSubImage"));
    glGetTransformFeedbacki64_v = reinterpret_cast<NOpenGLProc::TGetTransformFeedbacki64_v>(GL_GET_EXTENSION("glGetTransformFeedbacki64_v"));
    glGetTransformFeedbacki_v = reinterpret_cast<NOpenGLProc::TGetTransformFeedbacki_v>(GL_GET_EXTENSION("glGetTransformFeedbacki_v"));
    glGetTransformFeedbackiv = reinterpret_cast<NOpenGLProc::TGetTransformFeedbackiv>(GL_GET_EXTENSION("glGetTransformFeedbackiv"));
    glGetVertexArrayIndexed64iv = reinterpret_cast<NOpenGLProc::TGetVertexArrayIndexed64iv>(GL_GET_EXTENSION("glGetVertexArrayIndexed64iv"));
    glGetVertexArrayIndexediv = reinterpret_cast<NOpenGLProc::TGetVertexArrayIndexediv>(GL_GET_EXTENSION("glGetVertexArrayIndexediv"));
    glGetVertexArrayiv = reinterpret_cast<NOpenGLProc::TGetVertexArrayiv>(GL_GET_EXTENSION("glGetVertexArrayiv"));
    glGetnCompressedTexImage = reinterpret_cast<NOpenGLProc::TGetnCompressedTexImage>(GL_GET_EXTENSION("glGetnCompressedTexImage"));
    glGetnTexImage = reinterpret_cast<NOpenGLProc::TGetnTexImage>(GL_GET_EXTENSION("glGetnTexImage"));
    glGetnUniformdv = reinterpret_cast<NOpenGLProc::TGetnUniformdv>(GL_GET_EXTENSION("glGetnUniformdv"));
    glGetnUniformfv = reinterpret_cast<NOpenGLProc::TGetnUniformfv>(GL_GET_EXTENSION("glGetnUniformfv"));
    glGetnUniformiv = reinterpret_cast<NOpenGLProc::TGetnUniformiv>(GL_GET_EXTENSION("glGetnUniformiv"));
    glGetnUniformuiv = reinterpret_cast<NOpenGLProc::TGetnUniformuiv>(GL_GET_EXTENSION("glGetnUniformuiv"));
    glInvalidateNamedFramebufferData = reinterpret_cast<NOpenGLProc::TInvalidateNamedFramebufferData>(GL_GET_EXTENSION("glInvalidateNamedFramebufferData"));
    glInvalidateNamedFramebufferSubData = reinterpret_cast<NOpenGLProc::TInvalidateNamedFramebufferSubData>(GL_GET_EXTENSION("glInvalidateNamedFramebufferSubData"));
    glMapNamedBuffer = reinterpret_cast<NOpenGLProc::TMapNamedBuffer>(GL_GET_EXTENSION("glMapNamedBuffer"));
    glMapNamedBufferRange = reinterpret_cast<NOpenGLProc::TMapNamedBufferRange>(GL_GET_EXTENSION("glMapNamedBufferRange"));
    glMemoryBarrierByRegion = reinterpret_cast<NOpenGLProc::TMemoryBarrierByRegion>(GL_GET_EXTENSION("glMemoryBarrierByRegion"));
    glNamedBufferData = reinterpret_cast<NOpenGLProc::TNamedBufferData>(GL_GET_EXTENSION("glNamedBufferData"));
    glNamedBufferStorage = reinterpret_cast<NOpenGLProc::TNamedBufferStorage>(GL_GET_EXTENSION("glNamedBufferStorage"));
    glNamedBufferSubData = reinterpret_cast<NOpenGLProc::TNamedBufferSubData>(GL_GET_EXTENSION("glNamedBufferSubData"));
    glNamedFramebufferDrawBuffer = reinterpret_cast<NOpenGLProc::TNamedFramebufferDrawBuffer>(GL_GET_EXTENSION("glNamedFramebufferDrawBuffer"));
    glNamedFramebufferDrawBuffers = reinterpret_cast<NOpenGLProc::TNamedFramebufferDrawBuffers>(GL_GET_EXTENSION("glNamedFramebufferDrawBuffers"));
    glNamedFramebufferParameteri = reinterpret_cast<NOpenGLProc::TNamedFramebufferParameteri>(GL_GET_EXTENSION("glNamedFramebufferParameteri"));
    glNamedFramebufferReadBuffer = reinterpret_cast<NOpenGLProc::TNamedFramebufferReadBuffer>(GL_GET_EXTENSION("glNamedFramebufferReadBuffer"));
    glNamedFramebufferRenderbuffer = reinterpret_cast<NOpenGLProc::TNamedFramebufferRenderbuffer>(GL_GET_EXTENSION("glNamedFramebufferRenderbuffer"));
    glNamedFramebufferTexture = reinterpret_cast<NOpenGLProc::TNamedFramebufferTexture>(GL_GET_EXTENSION("glNamedFramebufferTexture"));
    glNamedFramebufferTextureLayer = reinterpret_cast<NOpenGLProc::TNamedFramebufferTextureLayer>(GL_GET_EXTENSION("glNamedFramebufferTextureLayer"));
    glNamedRenderbufferStorage = reinterpret_cast<NOpenGLProc::TNamedRenderbufferStorage>(GL_GET_EXTENSION("glNamedRenderbufferStorage"));
    glNamedRenderbufferStorageMultisample = reinterpret_cast<NOpenGLProc::TNamedRenderbufferStorageMultisample>(GL_GET_EXTENSION("glNamedRenderbufferStorageMultisample"));
    glReadnPixels = reinterpret_cast<NOpenGLProc::TReadnPixels>(GL_GET_EXTENSION("glReadnPixels"));
    glTextureBarrier = reinterpret_cast<NOpenGLProc::TTextureBarrier>(GL_GET_EXTENSION("glTextureBarrier"));
    glTextureBuffer = reinterpret_cast<NOpenGLProc::TTextureBuffer>(GL_GET_EXTENSION("glTextureBuffer"));
    glTextureBufferRange = reinterpret_cast<NOpenGLProc::TTextureBufferRange>(GL_GET_EXTENSION("glTextureBufferRange"));
    glTextureParameterIiv = reinterpret_cast<NOpenGLProc::TTextureParameterIiv>(GL_GET_EXTENSION("glTextureParameterIiv"));
    glTextureParameterIuiv = reinterpret_cast<NOpenGLProc::TTextureParameterIuiv>(GL_GET_EXTENSION("glTextureParameterIuiv"));
    glTextureParameterf = reinterpret_cast<NOpenGLProc::TTextureParameterf>(GL_GET_EXTENSION("glTextureParameterf"));
    glTextureParameterfv = reinterpret_cast<NOpenGLProc::TTextureParameterfv>(GL_GET_EXTENSION("glTextureParameterfv"));
    glTextureParameteri = reinterpret_cast<NOpenGLProc::TTextureParameteri>(GL_GET_EXTENSION("glTextureParameteri"));
    glTextureParameteriv = reinterpret_cast<NOpenGLProc::TTextureParameteriv>(GL_GET_EXTENSION("glTextureParameteriv"));
    glTextureStorage1D = reinterpret_cast<NOpenGLProc::TTextureStorage1D>(GL_GET_EXTENSION("glTextureStorage1D"));
    glTextureStorage2D = reinterpret_cast<NOpenGLProc::TTextureStorage2D>(GL_GET_EXTENSION("glTextureStorage2D"));
    glTextureStorage2DMultisample = reinterpret_cast<NOpenGLProc::TTextureStorage2DMultisample>(GL_GET_EXTENSION("glTextureStorage2DMultisample"));
    glTextureStorage3D = reinterpret_cast<NOpenGLProc::TTextureStorage3D>(GL_GET_EXTENSION("glTextureStorage3D"));
    glTextureStorage3DMultisample = reinterpret_cast<NOpenGLProc::TTextureStorage3DMultisample>(GL_GET_EXTENSION("glTextureStorage3DMultisample"));
    glTextureSubImage1D = reinterpret_cast<NOpenGLProc::TTextureSubImage1D>(GL_GET_EXTENSION("glTextureSubImage1D"));
    glTextureSubImage2D = reinterpret_cast<NOpenGLProc::TTextureSubImage2D>(GL_GET_EXTENSION("glTextureSubImage2D"));
    glTextureSubImage3D = reinterpret_cast<NOpenGLProc::TTextureSubImage3D>(GL_GET_EXTENSION("glTextureSubImage3D"));
    glTransformFeedbackBufferBase = reinterpret_cast<NOpenGLProc::TTransformFeedbackBufferBase>(GL_GET_EXTENSION("glTransformFeedbackBufferBase"));
    glTransformFeedbackBufferRange = reinterpret_cast<NOpenGLProc::TTransformFeedbackBufferRange>(GL_GET_EXTENSION("glTransformFeedbackBufferRange"));
    glUnmapNamedBuffer = reinterpret_cast<NOpenGLProc::TUnmapNamedBuffer>(GL_GET_EXTENSION("glUnmapNamedBuffer"));
    glVertexArrayAttribBinding = reinterpret_cast<NOpenGLProc::TVertexArrayAttribBinding>(GL_GET_EXTENSION("glVertexArrayAttribBinding"));
    glVertexArrayAttribFormat = reinterpret_cast<NOpenGLProc::TVertexArrayAttribFormat>(GL_GET_EXTENSION("glVertexArrayAttribFormat"));
    glVertexArrayAttribIFormat = reinterpret_cast<NOpenGLProc::TVertexArrayAttribIFormat>(GL_GET_EXTENSION("glVertexArrayAttribIFormat"));
    glVertexArrayAttribLFormat = reinterpret_cast<NOpenGLProc::TVertexArrayAttribLFormat>(GL_GET_EXTENSION("glVertexArrayAttribLFormat"));
    glVertexArrayBindingDivisor = reinterpret_cast<NOpenGLProc::TVertexArrayBindingDivisor>(GL_GET_EXTENSION("glVertexArrayBindingDivisor"));
    glVertexArrayElementBuffer = reinterpret_cast<NOpenGLProc::TVertexArrayElementBuffer>(GL_GET_EXTENSION("glVertexArrayElementBuffer"));
    glVertexArrayVertexBuffer = reinterpret_cast<NOpenGLProc::TVertexArrayVertexBuffer>(GL_GET_EXTENSION("glVertexArrayVertexBuffer"));
    glVertexArrayVertexBuffers = reinterpret_cast<NOpenGLProc::TVertexArrayVertexBuffers>(GL_GET_EXTENSION("glVertexArrayVertexBuffers"));
  }
}
//------------------------------------------------------------------------------
inline COpenGL::~COpenGL()
{
  //
}
//------------------------------------------------------------------------------
inline void COpenGL::makeCurrent()
{
  //
}
//------------------------------------------------------------------------------
#endif // OPENGL_H
