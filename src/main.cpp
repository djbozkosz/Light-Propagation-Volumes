//------------------------------------------------------------------------------
#include "engine.h"

#undef main
//------------------------------------------------------------------------------
int main(int argc, char *argv[])
{
#ifdef ENV_QT
  QApplication a(argc, argv);
#else
  (void)argc;
  (void)argv;
#endif

  CEngine e;

  try
  {
    return
#if defined(ENV_QT)
      a
#elif defined(ENV_SDL)
      e
#endif
      .exec();
  }
  catch(std::runtime_error &re)
  {
    e.showMessage("Critical Exception", re.what());
  }

  return 0;
}
//------------------------------------------------------------------------------