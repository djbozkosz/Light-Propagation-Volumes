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
    COpenGL();
    COpenGL(CContext *context);
    ~COpenGL();

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
    inline void depthRange(GLdouble near, GLdouble far) { glDepthRange(near, far); }
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
    inline void debugMessageCallback(GLDEBUGPROC callback, const void *userParam) { glDebugMessageCallback(callback, userParam); }
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

    // GL_VERSION_1_2
    inline NOpenGLProc::EProcType getStatusCopyTexSubImage3D() const { return statusCopyTexSubImage3D; }
    inline NOpenGLProc::EProcType getStatusDrawRangeElements() const { return statusDrawRangeElements; }
    inline NOpenGLProc::EProcType getStatusTexImage3D() const { return statusTexImage3D; }
    inline NOpenGLProc::EProcType getStatusTexSubImage3D() const { return statusTexSubImage3D; }

    // GL_VERSION_1_3
    inline NOpenGLProc::EProcType getStatusActiveTexture() const { return statusActiveTexture; }
    inline NOpenGLProc::EProcType getStatusCompressedTexImage1D() const { return statusCompressedTexImage1D; }
    inline NOpenGLProc::EProcType getStatusCompressedTexImage2D() const { return statusCompressedTexImage2D; }
    inline NOpenGLProc::EProcType getStatusCompressedTexImage3D() const { return statusCompressedTexImage3D; }
    inline NOpenGLProc::EProcType getStatusCompressedTexSubImage1D() const { return statusCompressedTexSubImage1D; }
    inline NOpenGLProc::EProcType getStatusCompressedTexSubImage2D() const { return statusCompressedTexSubImage2D; }
    inline NOpenGLProc::EProcType getStatusCompressedTexSubImage3D() const { return statusCompressedTexSubImage3D; }
    inline NOpenGLProc::EProcType getStatusGetCompressedTexImage() const { return statusGetCompressedTexImage; }
    inline NOpenGLProc::EProcType getStatusSampleCoverage() const { return statusSampleCoverage; }

    // GL_VERSION_1_4
    inline NOpenGLProc::EProcType getStatusBlendColor() const { return statusBlendColor; }
    inline NOpenGLProc::EProcType getStatusBlendEquation() const { return statusBlendEquation; }
    inline NOpenGLProc::EProcType getStatusBlendFuncSeparate() const { return statusBlendFuncSeparate; }
    inline NOpenGLProc::EProcType getStatusMultiDrawArrays() const { return statusMultiDrawArrays; }
    inline NOpenGLProc::EProcType getStatusMultiDrawElements() const { return statusMultiDrawElements; }
    inline NOpenGLProc::EProcType getStatusPointParameterf() const { return statusPointParameterf; }
    inline NOpenGLProc::EProcType getStatusPointParameterfv() const { return statusPointParameterfv; }
    inline NOpenGLProc::EProcType getStatusPointParameteri() const { return statusPointParameteri; }
    inline NOpenGLProc::EProcType getStatusPointParameteriv() const { return statusPointParameteriv; }

    // GL_VERSION_1_5
    inline NOpenGLProc::EProcType getStatusBeginQuery() const { return statusBeginQuery; }
    inline NOpenGLProc::EProcType getStatusBindBuffer() const { return statusBindBuffer; }
    inline NOpenGLProc::EProcType getStatusBufferData() const { return statusBufferData; }
    inline NOpenGLProc::EProcType getStatusBufferSubData() const { return statusBufferSubData; }
    inline NOpenGLProc::EProcType getStatusDeleteBuffers() const { return statusDeleteBuffers; }
    inline NOpenGLProc::EProcType getStatusDeleteQueries() const { return statusDeleteQueries; }
    inline NOpenGLProc::EProcType getStatusEndQuery() const { return statusEndQuery; }
    inline NOpenGLProc::EProcType getStatusGenBuffers() const { return statusGenBuffers; }
    inline NOpenGLProc::EProcType getStatusGenQueries() const { return statusGenQueries; }
    inline NOpenGLProc::EProcType getStatusGetBufferParameteriv() const { return statusGetBufferParameteriv; }
    inline NOpenGLProc::EProcType getStatusGetBufferPointerv() const { return statusGetBufferPointerv; }
    inline NOpenGLProc::EProcType getStatusGetBufferSubData() const { return statusGetBufferSubData; }
    inline NOpenGLProc::EProcType getStatusGetQueryObjectiv() const { return statusGetQueryObjectiv; }
    inline NOpenGLProc::EProcType getStatusGetQueryObjectuiv() const { return statusGetQueryObjectuiv; }
    inline NOpenGLProc::EProcType getStatusGetQueryiv() const { return statusGetQueryiv; }
    inline NOpenGLProc::EProcType getStatusIsBuffer() const { return statusIsBuffer; }
    inline NOpenGLProc::EProcType getStatusIsQuery() const { return statusIsQuery; }
    inline NOpenGLProc::EProcType getStatusMapBuffer() const { return statusMapBuffer; }
    inline NOpenGLProc::EProcType getStatusUnmapBuffer() const { return statusUnmapBuffer; }

    // GL_VERSION_2_0
    inline NOpenGLProc::EProcType getStatusAttachShader() const { return statusAttachShader; }
    inline NOpenGLProc::EProcType getStatusBindAttribLocation() const { return statusBindAttribLocation; }
    inline NOpenGLProc::EProcType getStatusBlendEquationSeparate() const { return statusBlendEquationSeparate; }
    inline NOpenGLProc::EProcType getStatusCompileShader() const { return statusCompileShader; }
    inline NOpenGLProc::EProcType getStatusCreateProgram() const { return statusCreateProgram; }
    inline NOpenGLProc::EProcType getStatusCreateShader() const { return statusCreateShader; }
    inline NOpenGLProc::EProcType getStatusDeleteProgram() const { return statusDeleteProgram; }
    inline NOpenGLProc::EProcType getStatusDeleteShader() const { return statusDeleteShader; }
    inline NOpenGLProc::EProcType getStatusDetachShader() const { return statusDetachShader; }
    inline NOpenGLProc::EProcType getStatusDisableVertexAttribArray() const { return statusDisableVertexAttribArray; }
    inline NOpenGLProc::EProcType getStatusDrawBuffers() const { return statusDrawBuffers; }
    inline NOpenGLProc::EProcType getStatusEnableVertexAttribArray() const { return statusEnableVertexAttribArray; }
    inline NOpenGLProc::EProcType getStatusGetActiveAttrib() const { return statusGetActiveAttrib; }
    inline NOpenGLProc::EProcType getStatusGetActiveUniform() const { return statusGetActiveUniform; }
    inline NOpenGLProc::EProcType getStatusGetAttachedShaders() const { return statusGetAttachedShaders; }
    inline NOpenGLProc::EProcType getStatusGetAttribLocation() const { return statusGetAttribLocation; }
    inline NOpenGLProc::EProcType getStatusGetProgramInfoLog() const { return statusGetProgramInfoLog; }
    inline NOpenGLProc::EProcType getStatusGetProgramiv() const { return statusGetProgramiv; }
    inline NOpenGLProc::EProcType getStatusGetShaderInfoLog() const { return statusGetShaderInfoLog; }
    inline NOpenGLProc::EProcType getStatusGetShaderSource() const { return statusGetShaderSource; }
    inline NOpenGLProc::EProcType getStatusGetShaderiv() const { return statusGetShaderiv; }
    inline NOpenGLProc::EProcType getStatusGetUniformLocation() const { return statusGetUniformLocation; }
    inline NOpenGLProc::EProcType getStatusGetUniformfv() const { return statusGetUniformfv; }
    inline NOpenGLProc::EProcType getStatusGetUniformiv() const { return statusGetUniformiv; }
    inline NOpenGLProc::EProcType getStatusGetVertexAttribPointerv() const { return statusGetVertexAttribPointerv; }
    inline NOpenGLProc::EProcType getStatusGetVertexAttribdv() const { return statusGetVertexAttribdv; }
    inline NOpenGLProc::EProcType getStatusGetVertexAttribfv() const { return statusGetVertexAttribfv; }
    inline NOpenGLProc::EProcType getStatusGetVertexAttribiv() const { return statusGetVertexAttribiv; }
    inline NOpenGLProc::EProcType getStatusIsProgram() const { return statusIsProgram; }
    inline NOpenGLProc::EProcType getStatusIsShader() const { return statusIsShader; }
    inline NOpenGLProc::EProcType getStatusLinkProgram() const { return statusLinkProgram; }
    inline NOpenGLProc::EProcType getStatusShaderSource() const { return statusShaderSource; }
    inline NOpenGLProc::EProcType getStatusStencilFuncSeparate() const { return statusStencilFuncSeparate; }
    inline NOpenGLProc::EProcType getStatusStencilMaskSeparate() const { return statusStencilMaskSeparate; }
    inline NOpenGLProc::EProcType getStatusStencilOpSeparate() const { return statusStencilOpSeparate; }
    inline NOpenGLProc::EProcType getStatusUniform1f() const { return statusUniform1f; }
    inline NOpenGLProc::EProcType getStatusUniform1fv() const { return statusUniform1fv; }
    inline NOpenGLProc::EProcType getStatusUniform1i() const { return statusUniform1i; }
    inline NOpenGLProc::EProcType getStatusUniform1iv() const { return statusUniform1iv; }
    inline NOpenGLProc::EProcType getStatusUniform2f() const { return statusUniform2f; }
    inline NOpenGLProc::EProcType getStatusUniform2fv() const { return statusUniform2fv; }
    inline NOpenGLProc::EProcType getStatusUniform2i() const { return statusUniform2i; }
    inline NOpenGLProc::EProcType getStatusUniform2iv() const { return statusUniform2iv; }
    inline NOpenGLProc::EProcType getStatusUniform3f() const { return statusUniform3f; }
    inline NOpenGLProc::EProcType getStatusUniform3fv() const { return statusUniform3fv; }
    inline NOpenGLProc::EProcType getStatusUniform3i() const { return statusUniform3i; }
    inline NOpenGLProc::EProcType getStatusUniform3iv() const { return statusUniform3iv; }
    inline NOpenGLProc::EProcType getStatusUniform4f() const { return statusUniform4f; }
    inline NOpenGLProc::EProcType getStatusUniform4fv() const { return statusUniform4fv; }
    inline NOpenGLProc::EProcType getStatusUniform4i() const { return statusUniform4i; }
    inline NOpenGLProc::EProcType getStatusUniform4iv() const { return statusUniform4iv; }
    inline NOpenGLProc::EProcType getStatusUniformMatrix2fv() const { return statusUniformMatrix2fv; }
    inline NOpenGLProc::EProcType getStatusUniformMatrix3fv() const { return statusUniformMatrix3fv; }
    inline NOpenGLProc::EProcType getStatusUniformMatrix4fv() const { return statusUniformMatrix4fv; }
    inline NOpenGLProc::EProcType getStatusUseProgram() const { return statusUseProgram; }
    inline NOpenGLProc::EProcType getStatusValidateProgram() const { return statusValidateProgram; }
    inline NOpenGLProc::EProcType getStatusVertexAttrib1d() const { return statusVertexAttrib1d; }
    inline NOpenGLProc::EProcType getStatusVertexAttrib1dv() const { return statusVertexAttrib1dv; }
    inline NOpenGLProc::EProcType getStatusVertexAttrib1f() const { return statusVertexAttrib1f; }
    inline NOpenGLProc::EProcType getStatusVertexAttrib1fv() const { return statusVertexAttrib1fv; }
    inline NOpenGLProc::EProcType getStatusVertexAttrib1s() const { return statusVertexAttrib1s; }
    inline NOpenGLProc::EProcType getStatusVertexAttrib1sv() const { return statusVertexAttrib1sv; }
    inline NOpenGLProc::EProcType getStatusVertexAttrib2d() const { return statusVertexAttrib2d; }
    inline NOpenGLProc::EProcType getStatusVertexAttrib2dv() const { return statusVertexAttrib2dv; }
    inline NOpenGLProc::EProcType getStatusVertexAttrib2f() const { return statusVertexAttrib2f; }
    inline NOpenGLProc::EProcType getStatusVertexAttrib2fv() const { return statusVertexAttrib2fv; }
    inline NOpenGLProc::EProcType getStatusVertexAttrib2s() const { return statusVertexAttrib2s; }
    inline NOpenGLProc::EProcType getStatusVertexAttrib2sv() const { return statusVertexAttrib2sv; }
    inline NOpenGLProc::EProcType getStatusVertexAttrib3d() const { return statusVertexAttrib3d; }
    inline NOpenGLProc::EProcType getStatusVertexAttrib3dv() const { return statusVertexAttrib3dv; }
    inline NOpenGLProc::EProcType getStatusVertexAttrib3f() const { return statusVertexAttrib3f; }
    inline NOpenGLProc::EProcType getStatusVertexAttrib3fv() const { return statusVertexAttrib3fv; }
    inline NOpenGLProc::EProcType getStatusVertexAttrib3s() const { return statusVertexAttrib3s; }
    inline NOpenGLProc::EProcType getStatusVertexAttrib3sv() const { return statusVertexAttrib3sv; }
    inline NOpenGLProc::EProcType getStatusVertexAttrib4Nbv() const { return statusVertexAttrib4Nbv; }
    inline NOpenGLProc::EProcType getStatusVertexAttrib4Niv() const { return statusVertexAttrib4Niv; }
    inline NOpenGLProc::EProcType getStatusVertexAttrib4Nsv() const { return statusVertexAttrib4Nsv; }
    inline NOpenGLProc::EProcType getStatusVertexAttrib4Nub() const { return statusVertexAttrib4Nub; }
    inline NOpenGLProc::EProcType getStatusVertexAttrib4Nubv() const { return statusVertexAttrib4Nubv; }
    inline NOpenGLProc::EProcType getStatusVertexAttrib4Nuiv() const { return statusVertexAttrib4Nuiv; }
    inline NOpenGLProc::EProcType getStatusVertexAttrib4Nusv() const { return statusVertexAttrib4Nusv; }
    inline NOpenGLProc::EProcType getStatusVertexAttrib4bv() const { return statusVertexAttrib4bv; }
    inline NOpenGLProc::EProcType getStatusVertexAttrib4d() const { return statusVertexAttrib4d; }
    inline NOpenGLProc::EProcType getStatusVertexAttrib4dv() const { return statusVertexAttrib4dv; }
    inline NOpenGLProc::EProcType getStatusVertexAttrib4f() const { return statusVertexAttrib4f; }
    inline NOpenGLProc::EProcType getStatusVertexAttrib4fv() const { return statusVertexAttrib4fv; }
    inline NOpenGLProc::EProcType getStatusVertexAttrib4iv() const { return statusVertexAttrib4iv; }
    inline NOpenGLProc::EProcType getStatusVertexAttrib4s() const { return statusVertexAttrib4s; }
    inline NOpenGLProc::EProcType getStatusVertexAttrib4sv() const { return statusVertexAttrib4sv; }
    inline NOpenGLProc::EProcType getStatusVertexAttrib4ubv() const { return statusVertexAttrib4ubv; }
    inline NOpenGLProc::EProcType getStatusVertexAttrib4uiv() const { return statusVertexAttrib4uiv; }
    inline NOpenGLProc::EProcType getStatusVertexAttrib4usv() const { return statusVertexAttrib4usv; }
    inline NOpenGLProc::EProcType getStatusVertexAttribPointer() const { return statusVertexAttribPointer; }

    // GL_VERSION_2_1
    inline NOpenGLProc::EProcType getStatusUniformMatrix2x3fv() const { return statusUniformMatrix2x3fv; }
    inline NOpenGLProc::EProcType getStatusUniformMatrix2x4fv() const { return statusUniformMatrix2x4fv; }
    inline NOpenGLProc::EProcType getStatusUniformMatrix3x2fv() const { return statusUniformMatrix3x2fv; }
    inline NOpenGLProc::EProcType getStatusUniformMatrix3x4fv() const { return statusUniformMatrix3x4fv; }
    inline NOpenGLProc::EProcType getStatusUniformMatrix4x2fv() const { return statusUniformMatrix4x2fv; }
    inline NOpenGLProc::EProcType getStatusUniformMatrix4x3fv() const { return statusUniformMatrix4x3fv; }

    // GL_VERSION_3_0
    inline NOpenGLProc::EProcType getStatusBeginConditionalRender() const { return statusBeginConditionalRender; }
    inline NOpenGLProc::EProcType getStatusBeginTransformFeedback() const { return statusBeginTransformFeedback; }
    inline NOpenGLProc::EProcType getStatusBindBufferBase() const { return statusBindBufferBase; }
    inline NOpenGLProc::EProcType getStatusBindBufferRange() const { return statusBindBufferRange; }
    inline NOpenGLProc::EProcType getStatusBindFragDataLocation() const { return statusBindFragDataLocation; }
    inline NOpenGLProc::EProcType getStatusBindFramebuffer() const { return statusBindFramebuffer; }
    inline NOpenGLProc::EProcType getStatusBindRenderbuffer() const { return statusBindRenderbuffer; }
    inline NOpenGLProc::EProcType getStatusBindVertexArray() const { return statusBindVertexArray; }
    inline NOpenGLProc::EProcType getStatusBlitFramebuffer() const { return statusBlitFramebuffer; }
    inline NOpenGLProc::EProcType getStatusCheckFramebufferStatus() const { return statusCheckFramebufferStatus; }
    inline NOpenGLProc::EProcType getStatusClampColor() const { return statusClampColor; }
    inline NOpenGLProc::EProcType getStatusClearBufferfi() const { return statusClearBufferfi; }
    inline NOpenGLProc::EProcType getStatusClearBufferfv() const { return statusClearBufferfv; }
    inline NOpenGLProc::EProcType getStatusClearBufferiv() const { return statusClearBufferiv; }
    inline NOpenGLProc::EProcType getStatusClearBufferuiv() const { return statusClearBufferuiv; }
    inline NOpenGLProc::EProcType getStatusColorMaski() const { return statusColorMaski; }
    inline NOpenGLProc::EProcType getStatusDeleteFramebuffers() const { return statusDeleteFramebuffers; }
    inline NOpenGLProc::EProcType getStatusDeleteRenderbuffers() const { return statusDeleteRenderbuffers; }
    inline NOpenGLProc::EProcType getStatusDeleteVertexArrays() const { return statusDeleteVertexArrays; }
    inline NOpenGLProc::EProcType getStatusDisablei() const { return statusDisablei; }
    inline NOpenGLProc::EProcType getStatusEnablei() const { return statusEnablei; }
    inline NOpenGLProc::EProcType getStatusEndConditionalRender() const { return statusEndConditionalRender; }
    inline NOpenGLProc::EProcType getStatusEndTransformFeedback() const { return statusEndTransformFeedback; }
    inline NOpenGLProc::EProcType getStatusFlushMappedBufferRange() const { return statusFlushMappedBufferRange; }
    inline NOpenGLProc::EProcType getStatusFramebufferRenderbuffer() const { return statusFramebufferRenderbuffer; }
    inline NOpenGLProc::EProcType getStatusFramebufferTexture1D() const { return statusFramebufferTexture1D; }
    inline NOpenGLProc::EProcType getStatusFramebufferTexture2D() const { return statusFramebufferTexture2D; }
    inline NOpenGLProc::EProcType getStatusFramebufferTexture3D() const { return statusFramebufferTexture3D; }
    inline NOpenGLProc::EProcType getStatusFramebufferTextureLayer() const { return statusFramebufferTextureLayer; }
    inline NOpenGLProc::EProcType getStatusGenFramebuffers() const { return statusGenFramebuffers; }
    inline NOpenGLProc::EProcType getStatusGenRenderbuffers() const { return statusGenRenderbuffers; }
    inline NOpenGLProc::EProcType getStatusGenVertexArrays() const { return statusGenVertexArrays; }
    inline NOpenGLProc::EProcType getStatusGenerateMipmap() const { return statusGenerateMipmap; }
    inline NOpenGLProc::EProcType getStatusGetBooleani_v() const { return statusGetBooleani_v; }
    inline NOpenGLProc::EProcType getStatusGetFragDataLocation() const { return statusGetFragDataLocation; }
    inline NOpenGLProc::EProcType getStatusGetFramebufferAttachmentParameteriv() const { return statusGetFramebufferAttachmentParameteriv; }
    inline NOpenGLProc::EProcType getStatusGetIntegeri_v() const { return statusGetIntegeri_v; }
    inline NOpenGLProc::EProcType getStatusGetRenderbufferParameteriv() const { return statusGetRenderbufferParameteriv; }
    inline NOpenGLProc::EProcType getStatusGetStringi() const { return statusGetStringi; }
    inline NOpenGLProc::EProcType getStatusGetTexParameterIiv() const { return statusGetTexParameterIiv; }
    inline NOpenGLProc::EProcType getStatusGetTexParameterIuiv() const { return statusGetTexParameterIuiv; }
    inline NOpenGLProc::EProcType getStatusGetTransformFeedbackVarying() const { return statusGetTransformFeedbackVarying; }
    inline NOpenGLProc::EProcType getStatusGetUniformuiv() const { return statusGetUniformuiv; }
    inline NOpenGLProc::EProcType getStatusGetVertexAttribIiv() const { return statusGetVertexAttribIiv; }
    inline NOpenGLProc::EProcType getStatusGetVertexAttribIuiv() const { return statusGetVertexAttribIuiv; }
    inline NOpenGLProc::EProcType getStatusIsEnabledi() const { return statusIsEnabledi; }
    inline NOpenGLProc::EProcType getStatusIsFramebuffer() const { return statusIsFramebuffer; }
    inline NOpenGLProc::EProcType getStatusIsRenderbuffer() const { return statusIsRenderbuffer; }
    inline NOpenGLProc::EProcType getStatusIsVertexArray() const { return statusIsVertexArray; }
    inline NOpenGLProc::EProcType getStatusMapBufferRange() const { return statusMapBufferRange; }
    inline NOpenGLProc::EProcType getStatusRenderbufferStorage() const { return statusRenderbufferStorage; }
    inline NOpenGLProc::EProcType getStatusRenderbufferStorageMultisample() const { return statusRenderbufferStorageMultisample; }
    inline NOpenGLProc::EProcType getStatusTexParameterIiv() const { return statusTexParameterIiv; }
    inline NOpenGLProc::EProcType getStatusTexParameterIuiv() const { return statusTexParameterIuiv; }
    inline NOpenGLProc::EProcType getStatusTransformFeedbackVaryings() const { return statusTransformFeedbackVaryings; }
    inline NOpenGLProc::EProcType getStatusUniform1ui() const { return statusUniform1ui; }
    inline NOpenGLProc::EProcType getStatusUniform1uiv() const { return statusUniform1uiv; }
    inline NOpenGLProc::EProcType getStatusUniform2ui() const { return statusUniform2ui; }
    inline NOpenGLProc::EProcType getStatusUniform2uiv() const { return statusUniform2uiv; }
    inline NOpenGLProc::EProcType getStatusUniform3ui() const { return statusUniform3ui; }
    inline NOpenGLProc::EProcType getStatusUniform3uiv() const { return statusUniform3uiv; }
    inline NOpenGLProc::EProcType getStatusUniform4ui() const { return statusUniform4ui; }
    inline NOpenGLProc::EProcType getStatusUniform4uiv() const { return statusUniform4uiv; }
    inline NOpenGLProc::EProcType getStatusVertexAttribI1i() const { return statusVertexAttribI1i; }
    inline NOpenGLProc::EProcType getStatusVertexAttribI1iv() const { return statusVertexAttribI1iv; }
    inline NOpenGLProc::EProcType getStatusVertexAttribI1ui() const { return statusVertexAttribI1ui; }
    inline NOpenGLProc::EProcType getStatusVertexAttribI1uiv() const { return statusVertexAttribI1uiv; }
    inline NOpenGLProc::EProcType getStatusVertexAttribI2i() const { return statusVertexAttribI2i; }
    inline NOpenGLProc::EProcType getStatusVertexAttribI2iv() const { return statusVertexAttribI2iv; }
    inline NOpenGLProc::EProcType getStatusVertexAttribI2ui() const { return statusVertexAttribI2ui; }
    inline NOpenGLProc::EProcType getStatusVertexAttribI2uiv() const { return statusVertexAttribI2uiv; }
    inline NOpenGLProc::EProcType getStatusVertexAttribI3i() const { return statusVertexAttribI3i; }
    inline NOpenGLProc::EProcType getStatusVertexAttribI3iv() const { return statusVertexAttribI3iv; }
    inline NOpenGLProc::EProcType getStatusVertexAttribI3ui() const { return statusVertexAttribI3ui; }
    inline NOpenGLProc::EProcType getStatusVertexAttribI3uiv() const { return statusVertexAttribI3uiv; }
    inline NOpenGLProc::EProcType getStatusVertexAttribI4bv() const { return statusVertexAttribI4bv; }
    inline NOpenGLProc::EProcType getStatusVertexAttribI4i() const { return statusVertexAttribI4i; }
    inline NOpenGLProc::EProcType getStatusVertexAttribI4iv() const { return statusVertexAttribI4iv; }
    inline NOpenGLProc::EProcType getStatusVertexAttribI4sv() const { return statusVertexAttribI4sv; }
    inline NOpenGLProc::EProcType getStatusVertexAttribI4ubv() const { return statusVertexAttribI4ubv; }
    inline NOpenGLProc::EProcType getStatusVertexAttribI4ui() const { return statusVertexAttribI4ui; }
    inline NOpenGLProc::EProcType getStatusVertexAttribI4uiv() const { return statusVertexAttribI4uiv; }
    inline NOpenGLProc::EProcType getStatusVertexAttribI4usv() const { return statusVertexAttribI4usv; }
    inline NOpenGLProc::EProcType getStatusVertexAttribIPointer() const { return statusVertexAttribIPointer; }

    // GL_VERSION_3_1
    inline NOpenGLProc::EProcType getStatusCopyBufferSubData() const { return statusCopyBufferSubData; }
    inline NOpenGLProc::EProcType getStatusDrawArraysInstanced() const { return statusDrawArraysInstanced; }
    inline NOpenGLProc::EProcType getStatusDrawElementsInstanced() const { return statusDrawElementsInstanced; }
    inline NOpenGLProc::EProcType getStatusGetActiveUniformBlockName() const { return statusGetActiveUniformBlockName; }
    inline NOpenGLProc::EProcType getStatusGetActiveUniformBlockiv() const { return statusGetActiveUniformBlockiv; }
    inline NOpenGLProc::EProcType getStatusGetActiveUniformName() const { return statusGetActiveUniformName; }
    inline NOpenGLProc::EProcType getStatusGetActiveUniformsiv() const { return statusGetActiveUniformsiv; }
    inline NOpenGLProc::EProcType getStatusGetUniformBlockIndex() const { return statusGetUniformBlockIndex; }
    inline NOpenGLProc::EProcType getStatusGetUniformIndices() const { return statusGetUniformIndices; }
    inline NOpenGLProc::EProcType getStatusPrimitiveRestartIndex() const { return statusPrimitiveRestartIndex; }
    inline NOpenGLProc::EProcType getStatusTexBuffer() const { return statusTexBuffer; }
    inline NOpenGLProc::EProcType getStatusUniformBlockBinding() const { return statusUniformBlockBinding; }

    // GL_VERSION_3_2
    inline NOpenGLProc::EProcType getStatusClientWaitSync() const { return statusClientWaitSync; }
    inline NOpenGLProc::EProcType getStatusDeleteSync() const { return statusDeleteSync; }
    inline NOpenGLProc::EProcType getStatusDrawElementsBaseVertex() const { return statusDrawElementsBaseVertex; }
    inline NOpenGLProc::EProcType getStatusDrawElementsInstancedBaseVertex() const { return statusDrawElementsInstancedBaseVertex; }
    inline NOpenGLProc::EProcType getStatusDrawRangeElementsBaseVertex() const { return statusDrawRangeElementsBaseVertex; }
    inline NOpenGLProc::EProcType getStatusFenceSync() const { return statusFenceSync; }
    inline NOpenGLProc::EProcType getStatusFramebufferTexture() const { return statusFramebufferTexture; }
    inline NOpenGLProc::EProcType getStatusGetBufferParameteri64v() const { return statusGetBufferParameteri64v; }
    inline NOpenGLProc::EProcType getStatusGetInteger64i_v() const { return statusGetInteger64i_v; }
    inline NOpenGLProc::EProcType getStatusGetInteger64v() const { return statusGetInteger64v; }
    inline NOpenGLProc::EProcType getStatusGetMultisamplefv() const { return statusGetMultisamplefv; }
    inline NOpenGLProc::EProcType getStatusGetSynciv() const { return statusGetSynciv; }
    inline NOpenGLProc::EProcType getStatusIsSync() const { return statusIsSync; }
    inline NOpenGLProc::EProcType getStatusMultiDrawElementsBaseVertex() const { return statusMultiDrawElementsBaseVertex; }
    inline NOpenGLProc::EProcType getStatusProvokingVertex() const { return statusProvokingVertex; }
    inline NOpenGLProc::EProcType getStatusSampleMaski() const { return statusSampleMaski; }
    inline NOpenGLProc::EProcType getStatusTexImage2DMultisample() const { return statusTexImage2DMultisample; }
    inline NOpenGLProc::EProcType getStatusTexImage3DMultisample() const { return statusTexImage3DMultisample; }
    inline NOpenGLProc::EProcType getStatusWaitSync() const { return statusWaitSync; }

    // GL_VERSION_3_3
    inline NOpenGLProc::EProcType getStatusBindFragDataLocationIndexed() const { return statusBindFragDataLocationIndexed; }
    inline NOpenGLProc::EProcType getStatusBindSampler() const { return statusBindSampler; }
    inline NOpenGLProc::EProcType getStatusDeleteSamplers() const { return statusDeleteSamplers; }
    inline NOpenGLProc::EProcType getStatusGenSamplers() const { return statusGenSamplers; }
    inline NOpenGLProc::EProcType getStatusGetFragDataIndex() const { return statusGetFragDataIndex; }
    inline NOpenGLProc::EProcType getStatusGetQueryObjecti64v() const { return statusGetQueryObjecti64v; }
    inline NOpenGLProc::EProcType getStatusGetQueryObjectui64v() const { return statusGetQueryObjectui64v; }
    inline NOpenGLProc::EProcType getStatusGetSamplerParameterIiv() const { return statusGetSamplerParameterIiv; }
    inline NOpenGLProc::EProcType getStatusGetSamplerParameterIuiv() const { return statusGetSamplerParameterIuiv; }
    inline NOpenGLProc::EProcType getStatusGetSamplerParameterfv() const { return statusGetSamplerParameterfv; }
    inline NOpenGLProc::EProcType getStatusGetSamplerParameteriv() const { return statusGetSamplerParameteriv; }
    inline NOpenGLProc::EProcType getStatusIsSampler() const { return statusIsSampler; }
    inline NOpenGLProc::EProcType getStatusQueryCounter() const { return statusQueryCounter; }
    inline NOpenGLProc::EProcType getStatusSamplerParameterIiv() const { return statusSamplerParameterIiv; }
    inline NOpenGLProc::EProcType getStatusSamplerParameterIuiv() const { return statusSamplerParameterIuiv; }
    inline NOpenGLProc::EProcType getStatusSamplerParameterf() const { return statusSamplerParameterf; }
    inline NOpenGLProc::EProcType getStatusSamplerParameterfv() const { return statusSamplerParameterfv; }
    inline NOpenGLProc::EProcType getStatusSamplerParameteri() const { return statusSamplerParameteri; }
    inline NOpenGLProc::EProcType getStatusSamplerParameteriv() const { return statusSamplerParameteriv; }
    inline NOpenGLProc::EProcType getStatusVertexAttribDivisor() const { return statusVertexAttribDivisor; }
    inline NOpenGLProc::EProcType getStatusVertexAttribP1ui() const { return statusVertexAttribP1ui; }
    inline NOpenGLProc::EProcType getStatusVertexAttribP1uiv() const { return statusVertexAttribP1uiv; }
    inline NOpenGLProc::EProcType getStatusVertexAttribP2ui() const { return statusVertexAttribP2ui; }
    inline NOpenGLProc::EProcType getStatusVertexAttribP2uiv() const { return statusVertexAttribP2uiv; }
    inline NOpenGLProc::EProcType getStatusVertexAttribP3ui() const { return statusVertexAttribP3ui; }
    inline NOpenGLProc::EProcType getStatusVertexAttribP3uiv() const { return statusVertexAttribP3uiv; }
    inline NOpenGLProc::EProcType getStatusVertexAttribP4ui() const { return statusVertexAttribP4ui; }
    inline NOpenGLProc::EProcType getStatusVertexAttribP4uiv() const { return statusVertexAttribP4uiv; }

    // GL_VERSION_4_0
    inline NOpenGLProc::EProcType getStatusBeginQueryIndexed() const { return statusBeginQueryIndexed; }
    inline NOpenGLProc::EProcType getStatusBindTransformFeedback() const { return statusBindTransformFeedback; }
    inline NOpenGLProc::EProcType getStatusBlendEquationSeparatei() const { return statusBlendEquationSeparatei; }
    inline NOpenGLProc::EProcType getStatusBlendEquationi() const { return statusBlendEquationi; }
    inline NOpenGLProc::EProcType getStatusBlendFuncSeparatei() const { return statusBlendFuncSeparatei; }
    inline NOpenGLProc::EProcType getStatusBlendFunci() const { return statusBlendFunci; }
    inline NOpenGLProc::EProcType getStatusDeleteTransformFeedbacks() const { return statusDeleteTransformFeedbacks; }
    inline NOpenGLProc::EProcType getStatusDrawArraysIndirect() const { return statusDrawArraysIndirect; }
    inline NOpenGLProc::EProcType getStatusDrawElementsIndirect() const { return statusDrawElementsIndirect; }
    inline NOpenGLProc::EProcType getStatusDrawTransformFeedback() const { return statusDrawTransformFeedback; }
    inline NOpenGLProc::EProcType getStatusDrawTransformFeedbackStream() const { return statusDrawTransformFeedbackStream; }
    inline NOpenGLProc::EProcType getStatusEndQueryIndexed() const { return statusEndQueryIndexed; }
    inline NOpenGLProc::EProcType getStatusGenTransformFeedbacks() const { return statusGenTransformFeedbacks; }
    inline NOpenGLProc::EProcType getStatusGetActiveSubroutineName() const { return statusGetActiveSubroutineName; }
    inline NOpenGLProc::EProcType getStatusGetActiveSubroutineUniformName() const { return statusGetActiveSubroutineUniformName; }
    inline NOpenGLProc::EProcType getStatusGetActiveSubroutineUniformiv() const { return statusGetActiveSubroutineUniformiv; }
    inline NOpenGLProc::EProcType getStatusGetProgramStageiv() const { return statusGetProgramStageiv; }
    inline NOpenGLProc::EProcType getStatusGetQueryIndexediv() const { return statusGetQueryIndexediv; }
    inline NOpenGLProc::EProcType getStatusGetSubroutineIndex() const { return statusGetSubroutineIndex; }
    inline NOpenGLProc::EProcType getStatusGetSubroutineUniformLocation() const { return statusGetSubroutineUniformLocation; }
    inline NOpenGLProc::EProcType getStatusGetUniformSubroutineuiv() const { return statusGetUniformSubroutineuiv; }
    inline NOpenGLProc::EProcType getStatusGetUniformdv() const { return statusGetUniformdv; }
    inline NOpenGLProc::EProcType getStatusIsTransformFeedback() const { return statusIsTransformFeedback; }
    inline NOpenGLProc::EProcType getStatusMinSampleShading() const { return statusMinSampleShading; }
    inline NOpenGLProc::EProcType getStatusPatchParameterfv() const { return statusPatchParameterfv; }
    inline NOpenGLProc::EProcType getStatusPatchParameteri() const { return statusPatchParameteri; }
    inline NOpenGLProc::EProcType getStatusPauseTransformFeedback() const { return statusPauseTransformFeedback; }
    inline NOpenGLProc::EProcType getStatusResumeTransformFeedback() const { return statusResumeTransformFeedback; }
    inline NOpenGLProc::EProcType getStatusUniform1d() const { return statusUniform1d; }
    inline NOpenGLProc::EProcType getStatusUniform1dv() const { return statusUniform1dv; }
    inline NOpenGLProc::EProcType getStatusUniform2d() const { return statusUniform2d; }
    inline NOpenGLProc::EProcType getStatusUniform2dv() const { return statusUniform2dv; }
    inline NOpenGLProc::EProcType getStatusUniform3d() const { return statusUniform3d; }
    inline NOpenGLProc::EProcType getStatusUniform3dv() const { return statusUniform3dv; }
    inline NOpenGLProc::EProcType getStatusUniform4d() const { return statusUniform4d; }
    inline NOpenGLProc::EProcType getStatusUniform4dv() const { return statusUniform4dv; }
    inline NOpenGLProc::EProcType getStatusUniformMatrix2dv() const { return statusUniformMatrix2dv; }
    inline NOpenGLProc::EProcType getStatusUniformMatrix2x3dv() const { return statusUniformMatrix2x3dv; }
    inline NOpenGLProc::EProcType getStatusUniformMatrix2x4dv() const { return statusUniformMatrix2x4dv; }
    inline NOpenGLProc::EProcType getStatusUniformMatrix3dv() const { return statusUniformMatrix3dv; }
    inline NOpenGLProc::EProcType getStatusUniformMatrix3x2dv() const { return statusUniformMatrix3x2dv; }
    inline NOpenGLProc::EProcType getStatusUniformMatrix3x4dv() const { return statusUniformMatrix3x4dv; }
    inline NOpenGLProc::EProcType getStatusUniformMatrix4dv() const { return statusUniformMatrix4dv; }
    inline NOpenGLProc::EProcType getStatusUniformMatrix4x2dv() const { return statusUniformMatrix4x2dv; }
    inline NOpenGLProc::EProcType getStatusUniformMatrix4x3dv() const { return statusUniformMatrix4x3dv; }
    inline NOpenGLProc::EProcType getStatusUniformSubroutinesuiv() const { return statusUniformSubroutinesuiv; }

    // GL_VERSION_4_1
    inline NOpenGLProc::EProcType getStatusActiveShaderProgram() const { return statusActiveShaderProgram; }
    inline NOpenGLProc::EProcType getStatusBindProgramPipeline() const { return statusBindProgramPipeline; }
    inline NOpenGLProc::EProcType getStatusClearDepthf() const { return statusClearDepthf; }
    inline NOpenGLProc::EProcType getStatusCreateShaderProgramv() const { return statusCreateShaderProgramv; }
    inline NOpenGLProc::EProcType getStatusDeleteProgramPipelines() const { return statusDeleteProgramPipelines; }
    inline NOpenGLProc::EProcType getStatusDepthRangeArrayv() const { return statusDepthRangeArrayv; }
    inline NOpenGLProc::EProcType getStatusDepthRangeIndexed() const { return statusDepthRangeIndexed; }
    inline NOpenGLProc::EProcType getStatusDepthRangef() const { return statusDepthRangef; }
    inline NOpenGLProc::EProcType getStatusGenProgramPipelines() const { return statusGenProgramPipelines; }
    inline NOpenGLProc::EProcType getStatusGetDoublei_v() const { return statusGetDoublei_v; }
    inline NOpenGLProc::EProcType getStatusGetFloati_v() const { return statusGetFloati_v; }
    inline NOpenGLProc::EProcType getStatusGetProgramBinary() const { return statusGetProgramBinary; }
    inline NOpenGLProc::EProcType getStatusGetProgramPipelineInfoLog() const { return statusGetProgramPipelineInfoLog; }
    inline NOpenGLProc::EProcType getStatusGetProgramPipelineiv() const { return statusGetProgramPipelineiv; }
    inline NOpenGLProc::EProcType getStatusGetShaderPrecisionFormat() const { return statusGetShaderPrecisionFormat; }
    inline NOpenGLProc::EProcType getStatusGetVertexAttribLdv() const { return statusGetVertexAttribLdv; }
    inline NOpenGLProc::EProcType getStatusIsProgramPipeline() const { return statusIsProgramPipeline; }
    inline NOpenGLProc::EProcType getStatusProgramBinary() const { return statusProgramBinary; }
    inline NOpenGLProc::EProcType getStatusProgramParameteri() const { return statusProgramParameteri; }
    inline NOpenGLProc::EProcType getStatusProgramUniform1d() const { return statusProgramUniform1d; }
    inline NOpenGLProc::EProcType getStatusProgramUniform1dv() const { return statusProgramUniform1dv; }
    inline NOpenGLProc::EProcType getStatusProgramUniform1f() const { return statusProgramUniform1f; }
    inline NOpenGLProc::EProcType getStatusProgramUniform1fv() const { return statusProgramUniform1fv; }
    inline NOpenGLProc::EProcType getStatusProgramUniform1i() const { return statusProgramUniform1i; }
    inline NOpenGLProc::EProcType getStatusProgramUniform1iv() const { return statusProgramUniform1iv; }
    inline NOpenGLProc::EProcType getStatusProgramUniform1ui() const { return statusProgramUniform1ui; }
    inline NOpenGLProc::EProcType getStatusProgramUniform1uiv() const { return statusProgramUniform1uiv; }
    inline NOpenGLProc::EProcType getStatusProgramUniform2d() const { return statusProgramUniform2d; }
    inline NOpenGLProc::EProcType getStatusProgramUniform2dv() const { return statusProgramUniform2dv; }
    inline NOpenGLProc::EProcType getStatusProgramUniform2f() const { return statusProgramUniform2f; }
    inline NOpenGLProc::EProcType getStatusProgramUniform2fv() const { return statusProgramUniform2fv; }
    inline NOpenGLProc::EProcType getStatusProgramUniform2i() const { return statusProgramUniform2i; }
    inline NOpenGLProc::EProcType getStatusProgramUniform2iv() const { return statusProgramUniform2iv; }
    inline NOpenGLProc::EProcType getStatusProgramUniform2ui() const { return statusProgramUniform2ui; }
    inline NOpenGLProc::EProcType getStatusProgramUniform2uiv() const { return statusProgramUniform2uiv; }
    inline NOpenGLProc::EProcType getStatusProgramUniform3d() const { return statusProgramUniform3d; }
    inline NOpenGLProc::EProcType getStatusProgramUniform3dv() const { return statusProgramUniform3dv; }
    inline NOpenGLProc::EProcType getStatusProgramUniform3f() const { return statusProgramUniform3f; }
    inline NOpenGLProc::EProcType getStatusProgramUniform3fv() const { return statusProgramUniform3fv; }
    inline NOpenGLProc::EProcType getStatusProgramUniform3i() const { return statusProgramUniform3i; }
    inline NOpenGLProc::EProcType getStatusProgramUniform3iv() const { return statusProgramUniform3iv; }
    inline NOpenGLProc::EProcType getStatusProgramUniform3ui() const { return statusProgramUniform3ui; }
    inline NOpenGLProc::EProcType getStatusProgramUniform3uiv() const { return statusProgramUniform3uiv; }
    inline NOpenGLProc::EProcType getStatusProgramUniform4d() const { return statusProgramUniform4d; }
    inline NOpenGLProc::EProcType getStatusProgramUniform4dv() const { return statusProgramUniform4dv; }
    inline NOpenGLProc::EProcType getStatusProgramUniform4f() const { return statusProgramUniform4f; }
    inline NOpenGLProc::EProcType getStatusProgramUniform4fv() const { return statusProgramUniform4fv; }
    inline NOpenGLProc::EProcType getStatusProgramUniform4i() const { return statusProgramUniform4i; }
    inline NOpenGLProc::EProcType getStatusProgramUniform4iv() const { return statusProgramUniform4iv; }
    inline NOpenGLProc::EProcType getStatusProgramUniform4ui() const { return statusProgramUniform4ui; }
    inline NOpenGLProc::EProcType getStatusProgramUniform4uiv() const { return statusProgramUniform4uiv; }
    inline NOpenGLProc::EProcType getStatusProgramUniformMatrix2dv() const { return statusProgramUniformMatrix2dv; }
    inline NOpenGLProc::EProcType getStatusProgramUniformMatrix2fv() const { return statusProgramUniformMatrix2fv; }
    inline NOpenGLProc::EProcType getStatusProgramUniformMatrix2x3dv() const { return statusProgramUniformMatrix2x3dv; }
    inline NOpenGLProc::EProcType getStatusProgramUniformMatrix2x3fv() const { return statusProgramUniformMatrix2x3fv; }
    inline NOpenGLProc::EProcType getStatusProgramUniformMatrix2x4dv() const { return statusProgramUniformMatrix2x4dv; }
    inline NOpenGLProc::EProcType getStatusProgramUniformMatrix2x4fv() const { return statusProgramUniformMatrix2x4fv; }
    inline NOpenGLProc::EProcType getStatusProgramUniformMatrix3dv() const { return statusProgramUniformMatrix3dv; }
    inline NOpenGLProc::EProcType getStatusProgramUniformMatrix3fv() const { return statusProgramUniformMatrix3fv; }
    inline NOpenGLProc::EProcType getStatusProgramUniformMatrix3x2dv() const { return statusProgramUniformMatrix3x2dv; }
    inline NOpenGLProc::EProcType getStatusProgramUniformMatrix3x2fv() const { return statusProgramUniformMatrix3x2fv; }
    inline NOpenGLProc::EProcType getStatusProgramUniformMatrix3x4dv() const { return statusProgramUniformMatrix3x4dv; }
    inline NOpenGLProc::EProcType getStatusProgramUniformMatrix3x4fv() const { return statusProgramUniformMatrix3x4fv; }
    inline NOpenGLProc::EProcType getStatusProgramUniformMatrix4dv() const { return statusProgramUniformMatrix4dv; }
    inline NOpenGLProc::EProcType getStatusProgramUniformMatrix4fv() const { return statusProgramUniformMatrix4fv; }
    inline NOpenGLProc::EProcType getStatusProgramUniformMatrix4x2dv() const { return statusProgramUniformMatrix4x2dv; }
    inline NOpenGLProc::EProcType getStatusProgramUniformMatrix4x2fv() const { return statusProgramUniformMatrix4x2fv; }
    inline NOpenGLProc::EProcType getStatusProgramUniformMatrix4x3dv() const { return statusProgramUniformMatrix4x3dv; }
    inline NOpenGLProc::EProcType getStatusProgramUniformMatrix4x3fv() const { return statusProgramUniformMatrix4x3fv; }
    inline NOpenGLProc::EProcType getStatusReleaseShaderCompiler() const { return statusReleaseShaderCompiler; }
    inline NOpenGLProc::EProcType getStatusScissorArrayv() const { return statusScissorArrayv; }
    inline NOpenGLProc::EProcType getStatusScissorIndexed() const { return statusScissorIndexed; }
    inline NOpenGLProc::EProcType getStatusScissorIndexedv() const { return statusScissorIndexedv; }
    inline NOpenGLProc::EProcType getStatusShaderBinary() const { return statusShaderBinary; }
    inline NOpenGLProc::EProcType getStatusUseProgramStages() const { return statusUseProgramStages; }
    inline NOpenGLProc::EProcType getStatusValidateProgramPipeline() const { return statusValidateProgramPipeline; }
    inline NOpenGLProc::EProcType getStatusVertexAttribL1d() const { return statusVertexAttribL1d; }
    inline NOpenGLProc::EProcType getStatusVertexAttribL1dv() const { return statusVertexAttribL1dv; }
    inline NOpenGLProc::EProcType getStatusVertexAttribL2d() const { return statusVertexAttribL2d; }
    inline NOpenGLProc::EProcType getStatusVertexAttribL2dv() const { return statusVertexAttribL2dv; }
    inline NOpenGLProc::EProcType getStatusVertexAttribL3d() const { return statusVertexAttribL3d; }
    inline NOpenGLProc::EProcType getStatusVertexAttribL3dv() const { return statusVertexAttribL3dv; }
    inline NOpenGLProc::EProcType getStatusVertexAttribL4d() const { return statusVertexAttribL4d; }
    inline NOpenGLProc::EProcType getStatusVertexAttribL4dv() const { return statusVertexAttribL4dv; }
    inline NOpenGLProc::EProcType getStatusVertexAttribLPointer() const { return statusVertexAttribLPointer; }
    inline NOpenGLProc::EProcType getStatusViewportArrayv() const { return statusViewportArrayv; }
    inline NOpenGLProc::EProcType getStatusViewportIndexedf() const { return statusViewportIndexedf; }
    inline NOpenGLProc::EProcType getStatusViewportIndexedfv() const { return statusViewportIndexedfv; }

    // GL_VERSION_4_2
    inline NOpenGLProc::EProcType getStatusBindImageTexture() const { return statusBindImageTexture; }
    inline NOpenGLProc::EProcType getStatusDrawArraysInstancedBaseInstance() const { return statusDrawArraysInstancedBaseInstance; }
    inline NOpenGLProc::EProcType getStatusDrawElementsInstancedBaseInstance() const { return statusDrawElementsInstancedBaseInstance; }
    inline NOpenGLProc::EProcType getStatusDrawElementsInstancedBaseVertexBaseInstance() const { return statusDrawElementsInstancedBaseVertexBaseInstance; }
    inline NOpenGLProc::EProcType getStatusDrawTransformFeedbackInstanced() const { return statusDrawTransformFeedbackInstanced; }
    inline NOpenGLProc::EProcType getStatusDrawTransformFeedbackStreamInstanced() const { return statusDrawTransformFeedbackStreamInstanced; }
    inline NOpenGLProc::EProcType getStatusGetActiveAtomicCounterBufferiv() const { return statusGetActiveAtomicCounterBufferiv; }
    inline NOpenGLProc::EProcType getStatusGetInternalformativ() const { return statusGetInternalformativ; }
    inline NOpenGLProc::EProcType getStatusMemoryBarrier() const { return statusMemoryBarrier; }
    inline NOpenGLProc::EProcType getStatusTexStorage1D() const { return statusTexStorage1D; }
    inline NOpenGLProc::EProcType getStatusTexStorage2D() const { return statusTexStorage2D; }
    inline NOpenGLProc::EProcType getStatusTexStorage3D() const { return statusTexStorage3D; }

    // GL_VERSION_4_3
    inline NOpenGLProc::EProcType getStatusBindVertexBuffer() const { return statusBindVertexBuffer; }
    inline NOpenGLProc::EProcType getStatusClearBufferData() const { return statusClearBufferData; }
    inline NOpenGLProc::EProcType getStatusClearBufferSubData() const { return statusClearBufferSubData; }
    inline NOpenGLProc::EProcType getStatusCopyImageSubData() const { return statusCopyImageSubData; }
    inline NOpenGLProc::EProcType getStatusDebugMessageCallback() const { return statusDebugMessageCallback; }
    inline NOpenGLProc::EProcType getStatusDebugMessageControl() const { return statusDebugMessageControl; }
    inline NOpenGLProc::EProcType getStatusDebugMessageInsert() const { return statusDebugMessageInsert; }
    inline NOpenGLProc::EProcType getStatusDispatchCompute() const { return statusDispatchCompute; }
    inline NOpenGLProc::EProcType getStatusDispatchComputeIndirect() const { return statusDispatchComputeIndirect; }
    inline NOpenGLProc::EProcType getStatusFramebufferParameteri() const { return statusFramebufferParameteri; }
    inline NOpenGLProc::EProcType getStatusGetDebugMessageLog() const { return statusGetDebugMessageLog; }
    inline NOpenGLProc::EProcType getStatusGetFramebufferParameteriv() const { return statusGetFramebufferParameteriv; }
    inline NOpenGLProc::EProcType getStatusGetInternalformati64v() const { return statusGetInternalformati64v; }
    inline NOpenGLProc::EProcType getStatusGetObjectLabel() const { return statusGetObjectLabel; }
    inline NOpenGLProc::EProcType getStatusGetObjectPtrLabel() const { return statusGetObjectPtrLabel; }
    inline NOpenGLProc::EProcType getStatusGetProgramInterfaceiv() const { return statusGetProgramInterfaceiv; }
    inline NOpenGLProc::EProcType getStatusGetProgramResourceIndex() const { return statusGetProgramResourceIndex; }
    inline NOpenGLProc::EProcType getStatusGetProgramResourceLocation() const { return statusGetProgramResourceLocation; }
    inline NOpenGLProc::EProcType getStatusGetProgramResourceLocationIndex() const { return statusGetProgramResourceLocationIndex; }
    inline NOpenGLProc::EProcType getStatusGetProgramResourceName() const { return statusGetProgramResourceName; }
    inline NOpenGLProc::EProcType getStatusGetProgramResourceiv() const { return statusGetProgramResourceiv; }
    inline NOpenGLProc::EProcType getStatusInvalidateBufferData() const { return statusInvalidateBufferData; }
    inline NOpenGLProc::EProcType getStatusInvalidateBufferSubData() const { return statusInvalidateBufferSubData; }
    inline NOpenGLProc::EProcType getStatusInvalidateFramebuffer() const { return statusInvalidateFramebuffer; }
    inline NOpenGLProc::EProcType getStatusInvalidateSubFramebuffer() const { return statusInvalidateSubFramebuffer; }
    inline NOpenGLProc::EProcType getStatusInvalidateTexImage() const { return statusInvalidateTexImage; }
    inline NOpenGLProc::EProcType getStatusInvalidateTexSubImage() const { return statusInvalidateTexSubImage; }
    inline NOpenGLProc::EProcType getStatusMultiDrawArraysIndirect() const { return statusMultiDrawArraysIndirect; }
    inline NOpenGLProc::EProcType getStatusMultiDrawElementsIndirect() const { return statusMultiDrawElementsIndirect; }
    inline NOpenGLProc::EProcType getStatusObjectLabel() const { return statusObjectLabel; }
    inline NOpenGLProc::EProcType getStatusObjectPtrLabel() const { return statusObjectPtrLabel; }
    inline NOpenGLProc::EProcType getStatusPopDebugGroup() const { return statusPopDebugGroup; }
    inline NOpenGLProc::EProcType getStatusPushDebugGroup() const { return statusPushDebugGroup; }
    inline NOpenGLProc::EProcType getStatusShaderStorageBlockBinding() const { return statusShaderStorageBlockBinding; }
    inline NOpenGLProc::EProcType getStatusTexBufferRange() const { return statusTexBufferRange; }
    inline NOpenGLProc::EProcType getStatusTexStorage2DMultisample() const { return statusTexStorage2DMultisample; }
    inline NOpenGLProc::EProcType getStatusTexStorage3DMultisample() const { return statusTexStorage3DMultisample; }
    inline NOpenGLProc::EProcType getStatusTextureView() const { return statusTextureView; }
    inline NOpenGLProc::EProcType getStatusVertexAttribBinding() const { return statusVertexAttribBinding; }
    inline NOpenGLProc::EProcType getStatusVertexAttribFormat() const { return statusVertexAttribFormat; }
    inline NOpenGLProc::EProcType getStatusVertexAttribIFormat() const { return statusVertexAttribIFormat; }
    inline NOpenGLProc::EProcType getStatusVertexAttribLFormat() const { return statusVertexAttribLFormat; }
    inline NOpenGLProc::EProcType getStatusVertexBindingDivisor() const { return statusVertexBindingDivisor; }

    // GL_VERSION_4_4
    inline NOpenGLProc::EProcType getStatusBindBuffersBase() const { return statusBindBuffersBase; }
    inline NOpenGLProc::EProcType getStatusBindBuffersRange() const { return statusBindBuffersRange; }
    inline NOpenGLProc::EProcType getStatusBindImageTextures() const { return statusBindImageTextures; }
    inline NOpenGLProc::EProcType getStatusBindSamplers() const { return statusBindSamplers; }
    inline NOpenGLProc::EProcType getStatusBindTextures() const { return statusBindTextures; }
    inline NOpenGLProc::EProcType getStatusBindVertexBuffers() const { return statusBindVertexBuffers; }
    inline NOpenGLProc::EProcType getStatusBufferStorage() const { return statusBufferStorage; }
    inline NOpenGLProc::EProcType getStatusClearTexImage() const { return statusClearTexImage; }
    inline NOpenGLProc::EProcType getStatusClearTexSubImage() const { return statusClearTexSubImage; }

    // GL_VERSION_4_5
    inline NOpenGLProc::EProcType getStatusBindTextureUnit() const { return statusBindTextureUnit; }
    inline NOpenGLProc::EProcType getStatusBlitNamedFramebuffer() const { return statusBlitNamedFramebuffer; }
    inline NOpenGLProc::EProcType getStatusCheckNamedFramebufferStatus() const { return statusCheckNamedFramebufferStatus; }
    inline NOpenGLProc::EProcType getStatusClearNamedBufferData() const { return statusClearNamedBufferData; }
    inline NOpenGLProc::EProcType getStatusClearNamedBufferSubData() const { return statusClearNamedBufferSubData; }
    inline NOpenGLProc::EProcType getStatusClearNamedFramebufferfi() const { return statusClearNamedFramebufferfi; }
    inline NOpenGLProc::EProcType getStatusClearNamedFramebufferfv() const { return statusClearNamedFramebufferfv; }
    inline NOpenGLProc::EProcType getStatusClearNamedFramebufferiv() const { return statusClearNamedFramebufferiv; }
    inline NOpenGLProc::EProcType getStatusClearNamedFramebufferuiv() const { return statusClearNamedFramebufferuiv; }
    inline NOpenGLProc::EProcType getStatusClipControl() const { return statusClipControl; }
    inline NOpenGLProc::EProcType getStatusCompressedTextureSubImage1D() const { return statusCompressedTextureSubImage1D; }
    inline NOpenGLProc::EProcType getStatusCompressedTextureSubImage2D() const { return statusCompressedTextureSubImage2D; }
    inline NOpenGLProc::EProcType getStatusCompressedTextureSubImage3D() const { return statusCompressedTextureSubImage3D; }
    inline NOpenGLProc::EProcType getStatusCopyNamedBufferSubData() const { return statusCopyNamedBufferSubData; }
    inline NOpenGLProc::EProcType getStatusCopyTextureSubImage1D() const { return statusCopyTextureSubImage1D; }
    inline NOpenGLProc::EProcType getStatusCopyTextureSubImage2D() const { return statusCopyTextureSubImage2D; }
    inline NOpenGLProc::EProcType getStatusCopyTextureSubImage3D() const { return statusCopyTextureSubImage3D; }
    inline NOpenGLProc::EProcType getStatusCreateBuffers() const { return statusCreateBuffers; }
    inline NOpenGLProc::EProcType getStatusCreateFramebuffers() const { return statusCreateFramebuffers; }
    inline NOpenGLProc::EProcType getStatusCreateProgramPipelines() const { return statusCreateProgramPipelines; }
    inline NOpenGLProc::EProcType getStatusCreateQueries() const { return statusCreateQueries; }
    inline NOpenGLProc::EProcType getStatusCreateRenderbuffers() const { return statusCreateRenderbuffers; }
    inline NOpenGLProc::EProcType getStatusCreateSamplers() const { return statusCreateSamplers; }
    inline NOpenGLProc::EProcType getStatusCreateTextures() const { return statusCreateTextures; }
    inline NOpenGLProc::EProcType getStatusCreateTransformFeedbacks() const { return statusCreateTransformFeedbacks; }
    inline NOpenGLProc::EProcType getStatusCreateVertexArrays() const { return statusCreateVertexArrays; }
    inline NOpenGLProc::EProcType getStatusDisableVertexArrayAttrib() const { return statusDisableVertexArrayAttrib; }
    inline NOpenGLProc::EProcType getStatusEnableVertexArrayAttrib() const { return statusEnableVertexArrayAttrib; }
    inline NOpenGLProc::EProcType getStatusFlushMappedNamedBufferRange() const { return statusFlushMappedNamedBufferRange; }
    inline NOpenGLProc::EProcType getStatusGenerateTextureMipmap() const { return statusGenerateTextureMipmap; }
    inline NOpenGLProc::EProcType getStatusGetCompressedTextureImage() const { return statusGetCompressedTextureImage; }
    inline NOpenGLProc::EProcType getStatusGetCompressedTextureSubImage() const { return statusGetCompressedTextureSubImage; }
    inline NOpenGLProc::EProcType getStatusGetGraphicsResetStatus() const { return statusGetGraphicsResetStatus; }
    inline NOpenGLProc::EProcType getStatusGetNamedBufferParameteri64v() const { return statusGetNamedBufferParameteri64v; }
    inline NOpenGLProc::EProcType getStatusGetNamedBufferParameteriv() const { return statusGetNamedBufferParameteriv; }
    inline NOpenGLProc::EProcType getStatusGetNamedBufferPointerv() const { return statusGetNamedBufferPointerv; }
    inline NOpenGLProc::EProcType getStatusGetNamedBufferSubData() const { return statusGetNamedBufferSubData; }
    inline NOpenGLProc::EProcType getStatusGetNamedFramebufferAttachmentParameteriv() const { return statusGetNamedFramebufferAttachmentParameteriv; }
    inline NOpenGLProc::EProcType getStatusGetNamedFramebufferParameteriv() const { return statusGetNamedFramebufferParameteriv; }
    inline NOpenGLProc::EProcType getStatusGetNamedRenderbufferParameteriv() const { return statusGetNamedRenderbufferParameteriv; }
    inline NOpenGLProc::EProcType getStatusGetQueryBufferObjecti64v() const { return statusGetQueryBufferObjecti64v; }
    inline NOpenGLProc::EProcType getStatusGetQueryBufferObjectiv() const { return statusGetQueryBufferObjectiv; }
    inline NOpenGLProc::EProcType getStatusGetQueryBufferObjectui64v() const { return statusGetQueryBufferObjectui64v; }
    inline NOpenGLProc::EProcType getStatusGetQueryBufferObjectuiv() const { return statusGetQueryBufferObjectuiv; }
    inline NOpenGLProc::EProcType getStatusGetTextureImage() const { return statusGetTextureImage; }
    inline NOpenGLProc::EProcType getStatusGetTextureLevelParameterfv() const { return statusGetTextureLevelParameterfv; }
    inline NOpenGLProc::EProcType getStatusGetTextureLevelParameteriv() const { return statusGetTextureLevelParameteriv; }
    inline NOpenGLProc::EProcType getStatusGetTextureParameterIiv() const { return statusGetTextureParameterIiv; }
    inline NOpenGLProc::EProcType getStatusGetTextureParameterIuiv() const { return statusGetTextureParameterIuiv; }
    inline NOpenGLProc::EProcType getStatusGetTextureParameterfv() const { return statusGetTextureParameterfv; }
    inline NOpenGLProc::EProcType getStatusGetTextureParameteriv() const { return statusGetTextureParameteriv; }
    inline NOpenGLProc::EProcType getStatusGetTextureSubImage() const { return statusGetTextureSubImage; }
    inline NOpenGLProc::EProcType getStatusGetTransformFeedbacki64_v() const { return statusGetTransformFeedbacki64_v; }
    inline NOpenGLProc::EProcType getStatusGetTransformFeedbacki_v() const { return statusGetTransformFeedbacki_v; }
    inline NOpenGLProc::EProcType getStatusGetTransformFeedbackiv() const { return statusGetTransformFeedbackiv; }
    inline NOpenGLProc::EProcType getStatusGetVertexArrayIndexed64iv() const { return statusGetVertexArrayIndexed64iv; }
    inline NOpenGLProc::EProcType getStatusGetVertexArrayIndexediv() const { return statusGetVertexArrayIndexediv; }
    inline NOpenGLProc::EProcType getStatusGetVertexArrayiv() const { return statusGetVertexArrayiv; }
    inline NOpenGLProc::EProcType getStatusGetnCompressedTexImage() const { return statusGetnCompressedTexImage; }
    inline NOpenGLProc::EProcType getStatusGetnTexImage() const { return statusGetnTexImage; }
    inline NOpenGLProc::EProcType getStatusGetnUniformdv() const { return statusGetnUniformdv; }
    inline NOpenGLProc::EProcType getStatusGetnUniformfv() const { return statusGetnUniformfv; }
    inline NOpenGLProc::EProcType getStatusGetnUniformiv() const { return statusGetnUniformiv; }
    inline NOpenGLProc::EProcType getStatusGetnUniformuiv() const { return statusGetnUniformuiv; }
    inline NOpenGLProc::EProcType getStatusInvalidateNamedFramebufferData() const { return statusInvalidateNamedFramebufferData; }
    inline NOpenGLProc::EProcType getStatusInvalidateNamedFramebufferSubData() const { return statusInvalidateNamedFramebufferSubData; }
    inline NOpenGLProc::EProcType getStatusMapNamedBuffer() const { return statusMapNamedBuffer; }
    inline NOpenGLProc::EProcType getStatusMapNamedBufferRange() const { return statusMapNamedBufferRange; }
    inline NOpenGLProc::EProcType getStatusMemoryBarrierByRegion() const { return statusMemoryBarrierByRegion; }
    inline NOpenGLProc::EProcType getStatusNamedBufferData() const { return statusNamedBufferData; }
    inline NOpenGLProc::EProcType getStatusNamedBufferStorage() const { return statusNamedBufferStorage; }
    inline NOpenGLProc::EProcType getStatusNamedBufferSubData() const { return statusNamedBufferSubData; }
    inline NOpenGLProc::EProcType getStatusNamedFramebufferDrawBuffer() const { return statusNamedFramebufferDrawBuffer; }
    inline NOpenGLProc::EProcType getStatusNamedFramebufferDrawBuffers() const { return statusNamedFramebufferDrawBuffers; }
    inline NOpenGLProc::EProcType getStatusNamedFramebufferParameteri() const { return statusNamedFramebufferParameteri; }
    inline NOpenGLProc::EProcType getStatusNamedFramebufferReadBuffer() const { return statusNamedFramebufferReadBuffer; }
    inline NOpenGLProc::EProcType getStatusNamedFramebufferRenderbuffer() const { return statusNamedFramebufferRenderbuffer; }
    inline NOpenGLProc::EProcType getStatusNamedFramebufferTexture() const { return statusNamedFramebufferTexture; }
    inline NOpenGLProc::EProcType getStatusNamedFramebufferTextureLayer() const { return statusNamedFramebufferTextureLayer; }
    inline NOpenGLProc::EProcType getStatusNamedRenderbufferStorage() const { return statusNamedRenderbufferStorage; }
    inline NOpenGLProc::EProcType getStatusNamedRenderbufferStorageMultisample() const { return statusNamedRenderbufferStorageMultisample; }
    inline NOpenGLProc::EProcType getStatusReadnPixels() const { return statusReadnPixels; }
    inline NOpenGLProc::EProcType getStatusTextureBarrier() const { return statusTextureBarrier; }
    inline NOpenGLProc::EProcType getStatusTextureBuffer() const { return statusTextureBuffer; }
    inline NOpenGLProc::EProcType getStatusTextureBufferRange() const { return statusTextureBufferRange; }
    inline NOpenGLProc::EProcType getStatusTextureParameterIiv() const { return statusTextureParameterIiv; }
    inline NOpenGLProc::EProcType getStatusTextureParameterIuiv() const { return statusTextureParameterIuiv; }
    inline NOpenGLProc::EProcType getStatusTextureParameterf() const { return statusTextureParameterf; }
    inline NOpenGLProc::EProcType getStatusTextureParameterfv() const { return statusTextureParameterfv; }
    inline NOpenGLProc::EProcType getStatusTextureParameteri() const { return statusTextureParameteri; }
    inline NOpenGLProc::EProcType getStatusTextureParameteriv() const { return statusTextureParameteriv; }
    inline NOpenGLProc::EProcType getStatusTextureStorage1D() const { return statusTextureStorage1D; }
    inline NOpenGLProc::EProcType getStatusTextureStorage2D() const { return statusTextureStorage2D; }
    inline NOpenGLProc::EProcType getStatusTextureStorage2DMultisample() const { return statusTextureStorage2DMultisample; }
    inline NOpenGLProc::EProcType getStatusTextureStorage3D() const { return statusTextureStorage3D; }
    inline NOpenGLProc::EProcType getStatusTextureStorage3DMultisample() const { return statusTextureStorage3DMultisample; }
    inline NOpenGLProc::EProcType getStatusTextureSubImage1D() const { return statusTextureSubImage1D; }
    inline NOpenGLProc::EProcType getStatusTextureSubImage2D() const { return statusTextureSubImage2D; }
    inline NOpenGLProc::EProcType getStatusTextureSubImage3D() const { return statusTextureSubImage3D; }
    inline NOpenGLProc::EProcType getStatusTransformFeedbackBufferBase() const { return statusTransformFeedbackBufferBase; }
    inline NOpenGLProc::EProcType getStatusTransformFeedbackBufferRange() const { return statusTransformFeedbackBufferRange; }
    inline NOpenGLProc::EProcType getStatusUnmapNamedBuffer() const { return statusUnmapNamedBuffer; }
    inline NOpenGLProc::EProcType getStatusVertexArrayAttribBinding() const { return statusVertexArrayAttribBinding; }
    inline NOpenGLProc::EProcType getStatusVertexArrayAttribFormat() const { return statusVertexArrayAttribFormat; }
    inline NOpenGLProc::EProcType getStatusVertexArrayAttribIFormat() const { return statusVertexArrayAttribIFormat; }
    inline NOpenGLProc::EProcType getStatusVertexArrayAttribLFormat() const { return statusVertexArrayAttribLFormat; }
    inline NOpenGLProc::EProcType getStatusVertexArrayBindingDivisor() const { return statusVertexArrayBindingDivisor; }
    inline NOpenGLProc::EProcType getStatusVertexArrayElementBuffer() const { return statusVertexArrayElementBuffer; }
    inline NOpenGLProc::EProcType getStatusVertexArrayVertexBuffer() const { return statusVertexArrayVertexBuffer; }
    inline NOpenGLProc::EProcType getStatusVertexArrayVertexBuffers() const { return statusVertexArrayVertexBuffers; }
};
//------------------------------------------------------------------------------
inline COpenGL::COpenGL() : CEngineBase(),
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
inline COpenGL::COpenGL(CContext *context) : CEngineBase(context)
{
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
}
//------------------------------------------------------------------------------
inline COpenGL::~COpenGL()
{
}
//------------------------------------------------------------------------------
inline std::string COpenGL::getStatus()
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
