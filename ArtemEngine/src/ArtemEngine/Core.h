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

#ifdef AR_ENABLE_ASSERTS
	#define AR_ASSERT(x, ...) { if(!(x)) { AR_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
	#define AR_CORE_ASSERT(x, ...) { if(!(x)) { AR_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else
	#define AR_ASSERT(x, ...)
	#define AR_CORE_ASSERT(x, ...)
#endif

#define BIT(x) (1 << x)