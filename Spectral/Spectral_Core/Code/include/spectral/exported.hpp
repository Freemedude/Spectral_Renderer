#pragma once

#ifdef _WIN32
#   ifdef SPECTRAL_SHARED_LIB_EXPORT
#       define EXPORTED  __declspec( dllexport )
#   elif SPECTRAL_SHARED_LIB_IMPORT
#       define EXPORTED  __declspec( dllimport )
#   else
#		error SPECTRAL_SHARED_LIB_EXPORT or SPECTRAL_SHARED_LIB_IMPORT must be defined when using this library!
#   endif
#else
#   define EXPORTED
#endif

