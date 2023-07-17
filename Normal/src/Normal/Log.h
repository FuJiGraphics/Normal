#pragma once

#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"

namespace Normal {

class NORMAL_API Log
{
public:
	static void init();

	inline static std::shared_ptr<spdlog::logger>& GetCoreLoger() { return s_CoreLogger; }
	inline static std::shared_ptr<spdlog::logger>& GetClientLoger() { return s_ClientLogger; }

private:
	static std::shared_ptr<spdlog::logger> s_CoreLogger;
	static std::shared_ptr<spdlog::logger> s_ClientLogger;

};


// Normal Engine Core log macros
#define NR_CORE_TRACE(...)         Normal::Log::GetCoreLoger()->trace( __VA_ARGS__ );
#define NR_CORE_DEBUG(...)         Normal::Log::GetCoreLoger()->debug( __VA_ARGS__ );
#define NR_CORE_INFO(...)          Normal::Log::GetCoreLoger()->info( __VA_ARGS__ );
#define NR_CORE_WARN(...)          Normal::Log::GetCoreLoger()->warn( __VA_ARGS__ );
#define NR_CORE_ERROR(...)         Normal::Log::GetCoreLoger()->error( __VA_ARGS__ );
#define NR_CORE_CRITICAL(...)      Normal::Log::GetCoreLoger()->critical( __VA_ARGS__ );

#define NR_CORE_LINE_TRACE(...)    \
    SPDLOG_LOGGER_CALL( Normal::Log::GetCoreLoger(), spdlog::level::trace, __VA_ARGS__);

#define NR_CORE_LINE_DEBUG(...)    \
    SPDLOG_LOGGER_CALL( Normal::Log::GetCoreLoger(), spdlog::level::debug, __VA_ARGS__);

#define NR_CORE_LINE_INFO(...)     \
    SPDLOG_LOGGER_CALL( Normal::Log::GetCoreLoger(), spdlog::level::info, __VA_ARGS__);

#define NR_CORE_LINE_WARN(...)     \
    SPDLOG_LOGGER_CALL( Normal::Log::GetCoreLoger(), spdlog::level::warn, __VA_ARGS__);

#define NR_CORE_LINE_ERROR(...)    \
    SPDLOG_LOGGER_CALL( Normal::Log::GetCoreLoger(), spdlog::level::err, __VA_ARGS__);

#define NR_CORE_LINE_CRITICAL(...) \
    SPDLOG_LOGGER_CALL( Normal::Log::GetCoreLoger(), spdlog::level::critical, __VA_ARGS__);


// Normal Engine Client log macros
#define NR_CLIENT_TRACE(...)       Normal::Log::GetClientLoger()->trace( __VA_ARGS__ );
#define NR_CLIENT_DEBUG( ... )     Normal::Log::GetClientLoger()->debug( __VA_ARGS__ );
#define NR_CLIENT_INFO(...)        Normal::Log::GetClientLoger()->info( __VA_ARGS__ );
#define NR_CLIENT_WARN(...)        Normal::Log::GetClientLoger()->warn( __VA_ARGS__ );
#define NR_CLIENT_ERROR(...)       Normal::Log::GetClientLoger()->error( __VA_ARGS__ );
#define NR_CLIENT_CRITICAL(...)    Normal::Log::GetClientLoger()->critical( __VA_ARGS__ );

#define NR_CLIENT_LINE_TRACE(...)    \
    SPDLOG_LOGGER_CALL( Normal::Log::GetClientLoger(), spdlog::level::trace, __VA_ARGS__);

#define NR_CLIENT_LINE_DEBUG(...)    \
    SPDLOG_LOGGER_CALL( Normal::Log::GetClientLoger(), spdlog::level::debug, __VA_ARGS__);

#define NR_CLIENT_LINE_INFO(...)     \
    SPDLOG_LOGGER_CALL( Normal::Log::GetClientLoger(), spdlog::level::info, __VA_ARGS__);

#define NR_CLIENT_LINE_WARN(...)     \
    SPDLOG_LOGGER_CALL( Normal::Log::GetClientLoger(), spdlog::level::warn, __VA_ARGS__);

#define NR_CLIENT_LINE_ERROR(...)    \
    SPDLOG_LOGGER_CALL( Normal::Log::GetClientLoger(), spdlog::level::err, __VA_ARGS__);

#define NR_CLIENT_LINE_CRITICAL(...) \
    SPDLOG_LOGGER_CALL( Normal::Log::GetClientLoger(), spdlog::level::critical, __VA_ARGS__);


} // namespace Normal Engine
