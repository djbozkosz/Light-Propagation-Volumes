//-----------------------------------------------------------------------------
#ifndef OPENGLTYPES_H
#define OPENGLTYPES_H

#if defined(ENV_QT)
/*#undef __gl_h_
#undef __GL_H__
#undef _GL_H
#undef __X_GL_H
#undef __gl2_h_
#undef __gltypes_h_
#undef __REGAL_H__
#undef __glext_h_
#undef __GLEXT_H_
#undef __gl_ATI_h_*/

#include <QGLFunctions>
#elif defined(ENV_SDL)
#include <gl/glew.h>
#endif

#include "types.h"

//-----------------------------------------------------------------------------
/*#ifdef _MSC_VER
typedef unsigned int GLenum;
typedef unsigned char GLboolean;
typedef unsigned int GLbitfield;
typedef signed char GLbyte;
typedef short GLshort;
typedef int GLint;
typedef int GLsizei;
typedef unsigned char GLubyte;
typedef unsigned short GLushort;
typedef unsigned int GLuint;
typedef float GLfloat;
typedef float GLclampf;
typedef double GLdouble;
typedef double GLclampd;
typedef void GLvoid;
#endif

typedef char            GLchar;
typedef uchar           GLuchar;
#if (defined(ENV_QT) && (QT_VERSION < 0x050400)) || defined(_MSC_VER)
#ifdef QT_OPENGL_ES_2
typedef float           GLclampd;
#else
typedef int32           GLfixed;
typedef int32           GLclampx;
typedef int32           GLintptr;
typedef int32           GLsizeiptr;
#endif
#endif*/
//-----------------------------------------------------------------------------
#endif // OPENGLTYPES_H
