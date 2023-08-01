#pragma once

#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"

namespace Normal {

class NORMAL_API Log
{
public:
    enum class Patterns
    {
        None = 0,
        Line, Simple
    };

public:
	static void init();
    static void setPattern( Patterns p );

	inline static std::shared_ptr<spdlog::logger>& GetCoreLoger() 
    { 
        init();
        return s_CoreLogger;
    }

	inline static std::shared_ptr<spdlog::logger>& GetClientLoger() 
    {
        init();
        return s_ClientLogger;
    }

private:
    inline static bool s_Initialized = false;
	static std::shared_ptr<spdlog::logger> s_CoreLogger;
	static std::shared_ptr<spdlog::logger> s_ClientLogger;

    static Patterns s_CurrentPattern;
};


#pragma region CoreDefines 
// Normal Engine Core log macros
#define NR_CORE_TRACE(...) \
    Log::setPattern( Log::Patterns::Simple ); \
    Normal::Log::GetCoreLoger()->trace( __VA_ARGS__ );

#define NR_CORE_DEBUG(...) \
    Log::setPattern( Log::Patterns::Simple ); \
    Normal::Log::GetCoreLoger()->debug( __VA_ARGS__ );

#define NR_CORE_INFO(...) \
    Log::setPattern( Log::Patterns::Simple ); \
    Normal::Log::GetCoreLoger()->info( __VA_ARGS__ );

#define NR_CORE_WARN(...) \
    Log::setPattern( Log::Patterns::Simple ); \
    Normal::Log::GetCoreLoger()->warn( __VA_ARGS__ );

#define NR_CORE_ERROR(...) \
    Log::setPattern( Log::Patterns::Simple ); \
    Normal::Log::GetCoreLoger()->error( __VA_ARGS__ );

#define NR_CORE_CRITICAL(...) \
    Log::setPattern( Log::Patterns::Simple ); \
    Normal::Log::GetCoreLoger()->critical( __VA_ARGS__ );

#define NR_CORE_LINE_TRACE(...) \
    Log::setPattern( Log::Patterns::Line ); \
    SPDLOG_LOGGER_CALL( Normal::Log::GetCoreLoger(), spdlog::level::trace, __VA_ARGS__);

#define NR_CORE_LINE_DEBUG(...) \
    Log::setPattern( Log::Patterns::Line ); \
    SPDLOG_LOGGER_CALL( Normal::Log::GetCoreLoger(), spdlog::level::debug, __VA_ARGS__);

#define NR_CORE_LINE_INFO(...) \
    Log::setPattern( Log::Patterns::Line ); \
    SPDLOG_LOGGER_CALL( Normal::Log::GetCoreLoger(), spdlog::level::info, __VA_ARGS__);

#define NR_CORE_LINE_WARN(...) \
    Log::setPattern( Log::Patterns::Line ); \
    SPDLOG_LOGGER_CALL( Normal::Log::GetCoreLoger(), spdlog::level::warn, __VA_ARGS__);

#define NR_CORE_LINE_ERROR(...) \
    Log::setPattern( Log::Patterns::Line ); \
    SPDLOG_LOGGER_CALL( Normal::Log::GetCoreLoger(), spdlog::level::err, __VA_ARGS__);

#define NR_CORE_LINE_CRITICAL(...) \
    Log::setPattern( Log::Patterns::Line ); \
    SPDLOG_LOGGER_CALL( Normal::Log::GetCoreLoger(), spdlog::level::critical, __VA_ARGS__);

// This macro should be defined to use NR_SET_NAME
#define NR_CORE_INFO_CTOR NR_CORE_INFO("[{0}] Successfully Allocated Memory.", NR_GET_NAME);
#define NR_CORE_INFO_DTOR NR_CORE_ERROR("[{0}] Successfully Deallocated Memory.", NR_GET_NAME);
#define NR_CORE_INFO_CTOR_N(x) NR_CORE_INFO("[{0}:{1}] Successfully Allocated Memory.", NR_GET_NAME, x);
#define NR_CORE_INFO_DTOR_N(x) NR_CORE_ERROR("[{0}:{1}] Successfully Deallocated Memory.", NR_GET_NAME, x);

#pragma endregion 

#pragma region ClientDefines 
// Normal Engine Client log macros
#define NR_CLIENT_TRACE(...) \
    Log::setPattern( Log::Patterns::Simple ); \
    Normal::Log::GetClientLoger()->trace( __VA_ARGS__ );

#define NR_CLIENT_DEBUG(...) \
    Log::setPattern( Log::Patterns::Simple ); \
    Normal::Log::GetClientLoger()->debug( __VA_ARGS__ );

#define NR_CLIENT_INFO(...) \
    Log::setPattern( Log::Patterns::Simple ); \
    Normal::Log::GetClientLoger()->info( __VA_ARGS__ );

#define NR_CLIENT_WARN(...) \
    Log::setPattern( Log::Patterns::Simple ); \
    Normal::Log::GetClientLoger()->warn( __VA_ARGS__ );

#define NR_CLIENT_ERROR(...) \
    Log::setPattern( Log::Patterns::Simple ); \
    Normal::Log::GetClientLoger()->error( __VA_ARGS__ );

#define NR_CLIENT_CRITICAL(...) \
    Log::setPattern( Log::Patterns::Simple ); \
    Normal::Log::GetClientLoger()->critical( __VA_ARGS__ );

#define NR_CLIENT_LINE_TRACE(...)    \
    Log::setPattern( Log::Patterns::Line ); \
    SPDLOG_LOGGER_CALL( Normal::Log::GetClientLoger(), spdlog::level::trace, __VA_ARGS__);

#define NR_CLIENT_LINE_DEBUG(...)    \
    Log::setPattern( Log::Patterns::Line ); \
    SPDLOG_LOGGER_CALL( Normal::Log::GetClientLoger(), spdlog::level::debug, __VA_ARGS__);

#define NR_CLIENT_LINE_INFO(...)     \
    Log::setPattern( Log::Patterns::Line ); \
    SPDLOG_LOGGER_CALL( Normal::Log::GetClientLoger(), spdlog::level::info, __VA_ARGS__);

#define NR_CLIENT_LINE_WARN(...)     \
    Log::setPattern( Log::Patterns::Line ); \
    SPDLOG_LOGGER_CALL( Normal::Log::GetClientLoger(), spdlog::level::warn, __VA_ARGS__);

#define NR_CLIENT_LINE_ERROR(...)    \
    Log::setPattern( Log::Patterns::Line ); \
    SPDLOG_LOGGER_CALL( Normal::Log::GetClientLoger(), spdlog::level::err, __VA_ARGS__);

#define NR_CLIENT_LINE_CRITICAL(...) \
    Log::setPattern( Log::Patterns::Line ); \
    SPDLOG_LOGGER_CALL( Normal::Log::GetClientLoger(), spdlog::level::critical, __VA_ARGS__);

// This macro should be defined to use NR_SET_NAME
#define NR_CLIENT_INFO_CTOR NR_CLIENT_INFO("[{0}] Successfully Allocated Memory.", NR_GET_NAME);
#define NR_CLIENT_INFO_DTOR NR_CLIENT_ERROR("[{0}] Successfully Deallocated Memory.", NR_GET_NAME);
#define NR_CLIENT_INFO_CTOR_N(x) NR_CLIENT_INFO("[{0}:{1}] Successfully Allocated Memory.", NR_GET_NAME, x);
#define NR_CLIENT_INFO_DTOR_N(x) NR_CLIENT_ERROR("[{0}:{1}] Successfully Deallocated Memory.", NR_GET_NAME, x);

#pragma endregion 

} // namespace Normal Engine
