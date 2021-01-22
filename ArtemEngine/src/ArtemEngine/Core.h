#pragma once

#ifdef AR_PLATFORM_WINDOWS
	#ifdef AR_BUILD_DLL
		#define ARTEM_ENGINE_API __declspec(dllexport)
	#else
		#define ARTEM_ENGINE_API __declspec(dllimport)
	#endif
#else
	#error Only supports windows lol :(
#endif

#define BIT(x) (1 << x)