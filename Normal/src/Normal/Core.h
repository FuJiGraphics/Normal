#pragma once

#ifdef NR_PLATFORM_WINDOWS
	#ifdef NR_BUILD_DLL
		#define NORMAL_API __declspec(dllexport)
	#else
		#define NORMAL_API __declspec(dllimport)
	#endif
#else
	#error Normal Engine only support windows!
#endif

#ifdef NR_ENABLE_ASSERTS
    #define NR_CLIENT_ASSERT(x, ...) { if(!(x)){ NR_CLIENT_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak();}}
    #define NR_CORE_ASSERT(x, ...) { if(!(x)){ NR_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak();}}
#else 
    #define NR_CLIENT_ASSERT(x, ...)
    #define NR_CORE_ASSERT(x, ...)
#endif 

#define BIT(x) ( 1 << x )


