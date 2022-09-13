#ifndef MEMDBG_PRELUDE_HXX
#define MEMDBG_PRELUDE_HXX

// Initializes memory debug code in the including scope

#ifdef MSVC_MEMORY_CHECK
_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
_CrtSetReportMode(_CRT_WARN, _CRTDBG_MODE_FILE);
_CrtSetReportFile(_CRT_WARN, _CRTDBG_FILE_STDERR);
#endif

#endif  // MEMDBG_PRELUDE_HXX
