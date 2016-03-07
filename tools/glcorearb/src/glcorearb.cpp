#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <vector>
#include <list>
#include <map>
#include <algorithm>

// g++ -std=c++11 -Wall -Wextra -pedantic -O3 src/glcorearb.cpp -o glcorearb.exe

typedef unsigned int uint;
typedef uint GLuint;
typedef uint GLenum;
typedef float GLfloat;

/*#ifdef WIN32
#include <windows.h>
#include <wingdi.h>
#else
#include <gl/glx.h>
#endif
#include <gl/gl.h>

#define GLAPI __declspec(dllimport)
#define GLAPIENTRY __stdcall

#ifdef WIN32
#define GL_GET_PROC_ADDRESS(TYPE, NAME) reinterpret_cast<TYPE>(wglGetProcAddress(NAME));
#else
#define GL_GET_PROC_ADDRESS(TYPE, NAME) reinterpret_cast<TYPE>(glXGetProcAddress(NAME));
#endif

namespace NOpenGL
{
  // GL_VERSION_1_0
  static const GLuint NUM_SAMPLE_COUNTS = 0x9380;

  // GL_VERSION_1_1
  //...
}

namespace NOpenGLDeprecated
{
  // GL_VERSION_1_0
  static const GLuint NUM_SAMPLE_COUNTS = 0x9380;

  // GL_VERSION_1_1
  //...
}

namespace NOpenGLProc
{
  // GL_VERSION_1_0
  typedef void (GLAPIENTRY *TActiveTexture)(GLenum texture);

  // GL_VERSION_1_1
  //...
}

namespace NOpenGLProcDeprecated
{
  // GL_VERSION_1_0
  typedef void (GLAPIENTRY *TActiveTexture)(GLenum texture);

  // GL_VERSION_1_1
  //...
}

class COpenGL
{
  private:
    // GL_VERSION_1_0
    NOpenGLProc::TActiveTexture glActiveTexture;

  public:
    COpenGL() : glActiveTexture(NULL)
    {
      glActiveTexture = GL_GET_PROC_ADDRESS(NOpenGLProc::TActiveTexture, "glActiveTexture");
    }
    inline void enable(GLenum cap) { ::glEnable(cap); }
    inline void activeTexture(GLenum texture) { glActiveTexture(texture); }
};*/

struct SFunc
{
  std::string ret;
  std::string name;
  std::string params;
};

struct SVerExt
{
  std::string name;
  std::map<std::string, std::string> constants;
  std::map<std::string, SFunc> functions;
};

void loadFile(const std::string &file, std::vector<std::string> &gl)
{
  std::ifstream f(file, std::ios_base::in);

  while(!f.fail())
  {
    char data[1024];
    f.getline(data, 1024);
    gl.push_back(data);
  }
  f.close();
}

void convertGl10()
{
  std::vector<std::string> gl;
  std::vector<std::string> glc;
  std::map<std::string, std::string> m;
  std::map<std::string, std::vector<std::string> > m2;
  loadFile("src/gl_.h", gl);
  loadFile("src/gl_all.txt", glc);

  for(uint i = 0; i < gl.size(); i++)
  {
    const std::string s(gl[i].substr(0, gl[i].find(" ")));
    if(s.length())
      m[gl[i].substr(0, gl[i].find(" "))] = gl[i].substr(gl[i].find(" ") + 1);
  }

  for(uint i = 0; i < glc.size(); i += 2)
    m2[glc[i + 1]].push_back(glc[i]);

  for(auto i = m2.begin(); i != m2.end(); i++)
  {
    std::cout << "#ifndef " << i->first << "\n#define " << i->first << " 1\n";
    std::sort(i->second.begin(), i->second.end());

    for(uint j = 0; j < i->second.size(); j++)
    {
      std::string s = "";
      if((42 - 8 - static_cast<int>(i->second[j].length())) > 0)
        s = std::string(42 - 8 - i->second[j].length(), ' ');
      std::cout << "#define " << i->second[j] << " " << s << m[i->second[j]] << "\n";
    }

    std::cout << "#endif /* " << i->first << " */\n\n";
  }
}

void parseVerExt(const std::vector<std::string> &g, std::map<std::string, SVerExt> &v)
{
  uint l = 0;

  for(; l < g.size(); l++)
  {
    for(; l < g.size(); l++)
    {
      if(g[l].find("#ifndef GL_") != std::string::npos)
        break;
    }

    if(l >= g.size())
      break;

    // ver / ext name
    const std::string verName = g[l].substr(g[l].find(" ") + 1);
    //std::cout << verName << "\n";
    v[verName] = SVerExt();
    SVerExt *b = &v[verName];
    b->name = verName;
    l += 2;

    for(; 1; l++)
    {
      if(g[l].find("#endif /* GL_") != std::string::npos)
        break;
      else if(g[l].find("#define GL_") != std::string::npos)
      {
        const std::string s = g[l].substr(g[l].find(" ") + 1);
        const std::string sName = s.substr(0, s.find(" "));
        const std::string sVal = s.substr(s.find_last_of(" ") + 1);
        b->constants[sName] = sVal;
        //std::cout << "\"" << sName << "\" \"" << sVal << "\"\n";
      }
      else if((g[l].find("APIENTRY") != std::string::npos) && (g[l].find("typedef") == std::string::npos))
      {
        SFunc f;
        std::string s = g[l].substr(g[l].find(" ") + 1);
        f.ret = s.substr(0, s.find("APIENTRY"));
        s = s.substr(s.find("APIENTRY") + 9);
        f.name = s.substr(0, s.find("("));
        if(f.name.find(" ") != std::string::npos)
          f.name = f.name.substr(0, s.find(" "));
        s = s.substr(s.find("(") + 1);
        f.params = s.substr(0, s.find(")"));
        b->functions[f.name] = f;
        //std::cout << "\"" << f.ret << "\" \"" << f.name << "\" \"" << f.params << "\"\n";
      }
    }
  }
}

void compareVers(const std::map<std::string, SVerExt> &v1, const std::map<std::string, SVerExt> &v2, std::map<std::string, SVerExt> &v)
{
  for(auto i = v2.cbegin(); i != v2.cend(); i++)
  {
    if((i->first.find("GL_VERSION") != std::string::npos) && (v1.find(i->first) != v1.cend()))
    {
      SVerExt bb;
      bb.name = i->first;
      const SVerExt *b = &v1.find(i->first)->second;

      for(auto j = i->second.constants.cbegin(); j != i->second.constants.cend(); j++)
      {
        if(b->constants.find(j->first) == b->constants.cend())
          bb.constants[j->first] = j->second;
      }

      for(auto j = i->second.functions.cbegin(); j != i->second.functions.cend(); j++)
      {
        if(b->functions.find(j->first) == b->functions.cend())
          bb.functions[j->first] = j->second;
      }

      if((bb.constants.size()) || (bb.functions.size()))
        v[bb.name] = bb;
    }
  }
}

void printCompatibleProfile(const std::map<std::string, SVerExt> &v)
{
  for(auto i = v.cbegin(); i != v.cend(); i++)
  {
    std::cout << i->second.name << "\n";
    for(auto j = i->second.constants.cbegin(); j != i->second.constants.cend(); j++)
      std::cout << j->first << " " << j->second << "\n";
    for(auto j = i->second.functions.cbegin(); j != i->second.functions.cend(); j++)
      std::cout << j->second.ret << " " << j->second.name << " " << j->second.params << "\n";
    std::cout << "\n";
  }
}

void printCoreHeader(const std::map<std::string, SVerExt> &v)
{
  std::cout << "#undef TRUE\n";
  std::cout << "#undef FALSE\n";
  std::cout << "#undef NO_ERROR\n";
  std::cout << "#undef RGB\n";
  std::cout << "#undef BOOL\n\n";
  std::cout << "#undef WAIT_FAILED\n\n";

  std::cout << "//------------------------------------------------------------------------------\n";
  std::cout << "namespace NOpenGL\n{\n";
  for(auto i = v.cbegin(); i != v.cend(); i++)
  {
    if((!i->second.functions.size()) || (i->second.name.find("GL_VERSION_") == std::string::npos))
      continue;

    std::cout << "  // " << i->second.name << "\n";
    for(auto j = i->second.constants.cbegin(); j != i->second.constants.cend(); j++)
    {
      std::string s = "";
      if((82 - 22 - static_cast<int>(j->first.length())) > 0)
        s = std::string(82 - 22 - j->first.length(), ' ');
      std::cout << "  static const GLuint " << j->first.substr(3) << s << " = " << j->second << ";\n";
    }
    std::cout << "\n";
  }
  std::cout << "}\n";
  std::cout << "//------------------------------------------------------------------------------\n";

  std::cout << "namespace NOpenGLProc\n{\n";
  for(auto i = v.cbegin(); i != v.cend(); i++)
  {
    if((!i->second.functions.size()) || (i->second.name.find("GL_VERSION_") == std::string::npos) || (i->second.name == "GL_VERSION_1_0") || (i->second.name == "GL_VERSION_1_1"))
      continue;

    std::cout << "  // " << i->second.name << "\n";
    for(auto j = i->second.functions.cbegin(); j != i->second.functions.cend(); j++)
    {
      std::string s = j->second.ret;
      const char c = s[s.length() - 1];
      if((c != ' ') && (c != '*'))
        s += " ";
      std::cout << "  typedef " << s << "(GLAPIENTRY *T" << j->second.name.substr(2) << ")(" << j->second.params << ");\n";
    }
    std::cout << "\n";
  }
  std::cout << "}\n";
  std::cout << "//------------------------------------------------------------------------------\n";
}

void printCoreClass(const std::map<std::string, SVerExt> &v)
{
  std::cout << "//------------------------------------------------------------------------------\n";
  std::cout << "class COpenGL : public CEngineBase\n{\n  private:\n";

  uint iic = 0;
  for(auto i = v.cbegin(); i != v.cend(); i++, iic++)
  {
    if((!i->second.functions.size()) || (i->second.name.find("GL_VERSION_") == std::string::npos) || (i->second.name == "GL_VERSION_1_0") || (i->second.name == "GL_VERSION_1_1"))
      continue;

    std::cout << "    // " << i->second.name << "\n";
    for(auto j = i->second.functions.cbegin(); j != i->second.functions.cend(); j++)
    {
      std::cout << "    NOpenGLProc::T" << j->second.name.substr(2) << " " << j->second.name << ";\n";
    }
    std::cout << "  \n";
  }
  std::cout << "  public:\n    COpenGL();\n    COpenGL(CContext *context);\n    ~COpenGL();\n\n";

  uint ii = 0;
  for(auto i = v.cbegin(); i != v.cend(); i++, ii++)
  {
    if((!i->second.functions.size()) || (i->second.name.find("GL_VERSION_") == std::string::npos))
      continue;

    std::cout << "    // " << i->second.name << "\n";
    for(auto j = i->second.functions.cbegin(); j != i->second.functions.cend(); j++)
    {
      std::string s = j->second.name.substr(2);
      std::transform(s.cbegin(), s.cend(), s.begin(), tolower);
      std::string p = j->second.params;
      if(p == "void")
        p.clear();
      else
        p += ",";

      std::vector<std::string> params;
      std::string token;
      for(uint k = 0; k < p.length(); k++)
      {
        if(p[k] != ',')
          token += p[k];
        else
        {
          token = token.substr(token.find_last_of(" ") + 1);
          if(token.find_last_of("*") != std::string::npos)
            token = token.substr(token.find_last_of("*") + 1);
          params.push_back(token);

          token.clear();
          k++;
        }         
      }

      p.clear();
      for(uint i = 0; i < params.size(); i++)
        p = p+((p.length()) ? ", " : "")+params[i];

      std::cout << "    inline " << j->second.ret << s[0] << j->second.name.substr(3) << "(" << j->second.params << ") { " << ((j->second.ret == "void ") ? "" : "return ") << j->second.name << "(" << p << "); }\n";
    }
    if(ii < (iic - 1))
      std::cout << "\n";
  }
  std::cout << "};\n";
  std::cout << "//------------------------------------------------------------------------------\n";
  std::cout << "inline COpenGL::COpenGL() : CEngineBase(),\n";

  ii = 0;
  for(auto i = v.cbegin(); i != v.cend(); i++, ii++)
  {
    if((!i->second.functions.size()) || (i->second.name.find("GL_VERSION_") == std::string::npos) || (i->second.name == "GL_VERSION_1_0") || (i->second.name == "GL_VERSION_1_1"))
      continue;

    std::cout << "  // " << i->second.name << "\n";
    uint jj = 0;
    for(auto j = i->second.functions.cbegin(); j != i->second.functions.cend(); j++, jj++)
      std::cout << "  " << j->second.name << "(NULL)" << (((ii == (iic - 1)) && (jj == (i->second.functions.size() - 1))) ? "" : ",") << "\n";
    if(ii < (iic - 1))
      std::cout << "\n";
  }
  std::cout << "{\n}\n";
  std::cout << "//------------------------------------------------------------------------------\n";
  std::cout << "inline COpenGL::COpenGL(CContext *context) : CEngineBase(context)\n{\n";

  ii = 0;
  for(auto i = v.cbegin(); i != v.cend(); i++, ii++)
  {
    if((!i->second.functions.size()) || (i->second.name.find("GL_VERSION_") == std::string::npos) || (i->second.name == "GL_VERSION_1_0") || (i->second.name == "GL_VERSION_1_1"))
      continue;

    std::cout << "  // " << i->second.name << "\n";
    for(auto j = i->second.functions.cbegin(); j != i->second.functions.cend(); j++)
      std::cout << "  " << j->second.name << " = reinterpret_cast<T" << j->second.name.substr(2) << ">(GL_GET_EXTENSION(\"" << j->second.name << "\");\n";
    if(ii < (iic - 1))
      std::cout << "\n";
  }
  std::cout << "}\n";
  std::cout << "//------------------------------------------------------------------------------\n";
  std::cout << "inline COpenGL::~COpenGL()\n{\n}\n";
  std::cout << "//------------------------------------------------------------------------------\n";
}

int main()
{
  std::vector<std::string> gl;
  std::vector<std::string> glc;
  std::vector<std::string> gle;
  std::map<std::string, SVerExt> vc;
  std::map<std::string, SVerExt> ve;
  std::map<std::string, SVerExt> vco;

  loadFile("src/gl.h", gl);
  loadFile("src/glcorearb.h", glc);
  loadFile("src/glext.h", gle);

  //convertGl10();
  parseVerExt(gl, ve);
  parseVerExt(glc, vc);
  parseVerExt(gle, ve);

  //compareVers(vc, ve, vco);

  //printCoreHeader(vc);
  printCoreClass(vc);

  return 0;
}