#include "Nrpch.h"

#include "Log.h"
#include "spdlog\sinks\stdout_color_sinks.h"

namespace Normal {

std::shared_ptr<spdlog::logger> Log::s_CoreLogger;
std::shared_ptr<spdlog::logger> Log::s_ClientLogger;

void Log::init()
{
	// spdlog::set_default_logger( s_CoreLogger );
	spdlog::set_pattern( "%^[%@][%T] %n: %v%$" );

	s_CoreLogger = spdlog::stdout_color_mt( "ENGINE" );
	s_CoreLogger->set_level( spdlog::level::trace );

	s_ClientLogger = spdlog::stdout_color_mt( "APP" );
	s_ClientLogger->set_level( spdlog::level::trace );

}

}