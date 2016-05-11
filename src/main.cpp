//------------------------------------------------------------------------------
#include "engine.h"

#undef main
//------------------------------------------------------------------------------
int main(int argc, char *argv[])
{
#ifdef ENV_QT
  QApplication a(argc, argv);
#endif

  CEngine e(argc, argv);
#ifdef ENV_QT
  e.show();
#endif

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
