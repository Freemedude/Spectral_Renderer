// Simple main header

#include "renderer.hpp"
#include "scene.hpp"

// Define EXPORTED for any platform
#ifdef _WIN32
#   ifdef WIN_EXPORT
#       define EXPORTED  __declspec( dllexport )
#   else
#       define EXPORTED  __declspec( dllimport )
#   endif
#else
#   define EXPORTED
#endif

typedef int(__cdecl *say_something_func)();

extern "C" {

int EXPORTED say_something();

}