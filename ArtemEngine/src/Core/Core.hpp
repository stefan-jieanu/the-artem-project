#pragma once

// Declare DLL stuff for Linux based systems
#ifdef AR_PLATFORM_LINUX
    #define ENGINE_API __attribute__((visibility("default")))

// Declase DLL stuff for Windows systems
#elif AR_PLATFORM_WINDOWS
    #ifdef AR_BUILD_DLL
        #define ENGINE_API __declspec(dllexport)
    #else
        #define ENGINE_API __declspec(dllimport)
    #endif
#else
    #error No support for losers
#endif

