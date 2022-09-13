#ifndef MEMDBG_PREAMBLE_HXX
#define MEMDBG_PREAMBLE_HXX

// Introduces preprocessor directives to the including scope

#ifdef _MSC_VER
#define MSVC_MEMORY_CHECK
#endif

#ifdef MSVC_MEMORY_CHECK
#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>
#endif

#endif  // MEMDBG_PREAMBLE_HXX
