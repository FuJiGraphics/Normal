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

#ifdef NR_DEBUG
#define NR_ENABLE_ASSERTS
#define NR_ENABLE_DEBUG_DEFINES
#endif

#pragma region Asserts
#ifdef NR_ENABLE_ASSERTS
    #define NR_CLIENT_ASSERT(x, ...) { if(!(x)){ NR_CLIENT_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak();}}
    #define NR_CORE_ASSERT(x, ...) { if(!(x)){ NR_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak();}}
#else 
    #define NR_CLIENT_ASSERT(x, ...)
    #define NR_CORE_ASSERT(x, ...)
#endif 
#pragma endregion

#pragma region DebugDefines
#ifdef NR_ENABLE_DEBUG_DEFINES
    // One can define a unique entity in each scope area.
    #define NR_SET_NAME(x) const char* NR_DebugName = ##x;
    #define NR_GET_NAME NR_DebugName
#else
    // One can define a unique entity in each scope area.
    #define NR_SET_NAME(x)
    #define NR_GET_NAME "Release"
#endif
#pragma endregion

#pragma region DataTypes
// Built-in Data Types
namespace Normal {

#define INT8_MIN         (-127i8 - 1)
#define INT16_MIN        (-32767i16 - 1)
#define INT32_MIN        (-2147483647i32 - 1)
#define INT64_MIN        (-9223372036854775807i64 - 1)
#define INT8_MAX         127i8
#define INT16_MAX        32767i16
#define INT32_MAX        2147483647i32
#define INT64_MAX        9223372036854775807i64
#define UINT8_MAX        0xffui8
#define UINT16_MAX       0xffffui16
#define UINT32_MAX       0xffffffffui32
#define UINT64_MAX       0xffffffffffffffffui64

#ifdef NR_PLATFORM_WINDOWS
	
	// unsigned integer [1byte], range of expression [0~255]
	typedef unsigned __int8   uint8;
	// unsigned integer [2byte], range of expression [0 ~ 65535]
	typedef unsigned __int16  uint16;
	// unsigned integer [4byte], range of expression [0 ~ 4294967295]
	typedef unsigned __int32  uint32;
	// unsigned integer [8byte], range of expression [0 ~ 18446744073709551615]
	typedef unsigned __int64  uint64;
	
	// signed integer [1byte], range of expression [-128 ~ 127]
	typedef __int8    int8;
	// signed integer [2byte], range of expression [-32,768 ~ 32,767]
	typedef __int16   int16;
	// signed integer [4byte], range of expression [-2,147,483,648 ~ 2,147,483,647]
	typedef __int32   int32;
	// signed integer [8byte], range of expression [-9,223,372,036,854,775,808 ~ 9,223,372,036,854,775,807]
	typedef __int64   int64;
#else
	// unsigned integer [1byte], range of expression [0~255]
	typedef unsigned char       uint8;
	// unsigned integer [2byte], range of expression [0 ~ 65535]
	typedef unsigned short      uint16;
	// unsigned integer [4byte], range of expression [0 ~ 4294967295]
	typedef unsigned long       uint32;
	// unsigned integer [8byte], range of expression [0 ~ 18446744073709551615]
	typedef unsigned long long  uint64;

	// signed integer [8byte], range of expression [-128 ~ 127]
	typedef signed char      int8;
	// signed integer [8byte], range of expression [-32,768 ~ 32,767]
	typedef short            int16;
	// signed integer [8byte], range of expression [-2,147,483,648 ~ 2,147,483,647]
	typedef long             int32;
	// signed integer [8byte], range of expression [-9,223,372,036,854,775,808 ~ 9,223,372,036,854,775,807]
	typedef long long        int64;
#endif

} // namespace Normal
#pragma endregion
#pragma region Etc...

namespace Normal {

#define BIT(x) ( 1 << x )

#define BIND_EVENT_FUNC(x) std::bind( &x, this, std::placeholders::_1 )
#define BIND_NOARGS_FUNC(x) std::bind( &x, this )

#define NR_CORE_DELETE(x, ...) {\
            if ( x ) {\
                delete x;\
                x = nullptr;\
                NR_CORE_LINE_INFO("[{0}] Successfully deallocated memory.", __VA_ARGS__);\
            }\
        } // NR_CORE_DELETE


} // namespace Normal

#pragma endregion