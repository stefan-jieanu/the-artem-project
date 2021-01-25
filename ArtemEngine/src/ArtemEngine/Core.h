#pragma once

#ifdef AR_PLATFORM_WINDOWS
	
#else
	#error Only supports windows lol :(
#endif

#ifdef AR_ENABLE_ASSERTS
	#define LOG_ASSERT(x, ...) { if(!(x)) { LOG_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
	#define LOG_CORE_ASSERT(x, ...) { if(!(x)) { LOG_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else
	#define LOG_ASSERT(x, ...)
	#define LOG_CORE_ASSERT(x, ...)
#endif

#define BIT(x) (1 << x)