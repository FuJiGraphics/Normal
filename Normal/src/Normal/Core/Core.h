#pragma once

#ifdef NR_PLATFORM_WINDOWS
	#ifdef NR_SHARED_DLL
		#ifdef NR_BUILD_DLL
			#define NORMAL_API __declspec(dllexport)
		#else
			#define NORMAL_API __declspec(dllimport)
		#endif
	#else
		#define NORMAL_API
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
    #define NR_CLIENT_ASSERT(x, ...)	{ if(!(x)){ NR_CLIENT_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak();}}
    #define NR_CORE_ASSERT(x, ...)		{ if(!(x)){ NR_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak();}}
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

	enum NR_TYPES { NR_FLOAT, NR_DOUBLE, NR_UINT, NR_INT };

#ifdef NR_PLATFORM_WINDOWS
	using NRsizet  = unsigned long long;
	using NRbool   = bool;
	using NRenum   = unsigned int;
	using NRfloat  = float;
	using NRdouble = double;
	using NRuchar  = unsigned char;
	using NRchar   = char;

	// unsigned integer [4byte], range of expression [0 ~ 4294967295]
	using NRuint   = unsigned __int32;
	// unsigned integer [1byte], range of expression [0~255]
	using NRuint8  = unsigned __int8;
	// unsigned integer [2byte], range of expression [0 ~ 65535]
	using NRuint16 = unsigned __int16;
	// unsigned integer [4byte], range of expression [0 ~ 4294967295]
	using NRuint32 = unsigned __int32;
	// unsigned integer [8byte], range of expression [0 ~ 18446744073709551615]
	using NRuint64 = unsigned __int64;

	// signed integer [4byte], range of expression [-2,147,483,648 ~ 2,147,483,647]
	using NRint   = __int32;
	// signed integer [1byte], range of expression [-128 ~ 127]
	using NRint8  = __int8;
	// signed integer [2byte], range of expression [-32,768 ~ 32,767]
	using NRint16 = __int16;
	// signed integer [4byte], range of expression [-2,147,483,648 ~ 2,147,483,647]
	using NRint32 = __int32;
	// signed integer [8byte], range of expression [-9,223,372,036,854,775,808 ~ 9,223,372,036,854,775,807]
	using NRint64 = __int64;
#else
	using NRsizet  = unsigned long long;
	using NRbool   = bool;
	using NRenum   = unsigned int;
	using NRfloat  = float;
	using NRdouble = double;
	using NRuchar  = unsigned char;
	using NRchar   = char;

	// unsigned integer [4byte], range of expression [0 ~ 4294967295]
	using NRuint   = unsigned int;
	// unsigned integer [1byte], range of expression [0~255]
	using NRuint8  = unsigned char;
	// unsigned integer [2byte], range of expression [0 ~ 65535]
	using NRuint16 = unsigned short;
	// unsigned integer [4byte], range of expression [0 ~ 4294967295]
	using NRuint32 = unsigned int;
	// unsigned integer [8byte], range of expression [0 ~ 18446744073709551615]
	using NRuint64 = unsigned long long;

	// signed integer [1byte], range of expression [-128 ~ 127]
	using NRint8  = signed char;    
	// signed integer [2byte], range of expression [-32,768 ~ 32,767]
	using NRint16 = short;         
	// signed integer [4byte], range of expression [-2,147,483,648 ~ 2,147,483,647]
	using NRint32 = int;           
	// signed integer [8byte], range of expression [-9,223,372,036,854,775,808 ~ 9,223,372,036,854,775,807]
	using NRint64 = long long;    
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


#include <memory>
#include <utility>
namespace Normal {
	namespace Own
	{
		template <typename T>
		using Share = std::shared_ptr<T>;
		template <typename T, typename ... Args>
		constexpr Share<T> CreateShare( Args&& ... args )
		{
			return std::make_shared<T>( std::forward<Args>( args )... );
		}

		template <typename T>
		using Unit = std::unique_ptr<T>;
		template <typename T, typename ... Args>
		constexpr Unit<T> CreateUnit( Args&& ... args )
		{
			return std::make_unique<T>( std::forward<Args>( args )... );
		}
	}
}

#pragma endregion