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

