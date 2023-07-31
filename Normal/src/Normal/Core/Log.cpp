#include "Nrpch.h"

#include "Log.h"
#include "spdlog\sinks\stdout_color_sinks.h"

namespace Normal {

std::shared_ptr<spdlog::logger> Log::s_CoreLogger;
std::shared_ptr<spdlog::logger> Log::s_ClientLogger;
Log::Patterns Log::s_CurrentPattern;

void Log::init()
{
	if ( s_Initialized ) return;
	s_Initialized = true;
	// spdlog::set_default_logger( s_CoreLogger );
	spdlog::set_pattern( "%^[%T] %n: %v%$" );
	s_CurrentPattern = Patterns::Simple;

	s_CoreLogger = spdlog::stdout_color_mt( "ENGINE" );
	s_CoreLogger->set_level( spdlog::level::trace );

	s_ClientLogger = spdlog::stdout_color_mt( "APP" );
	s_ClientLogger->set_level( spdlog::level::trace );
}

void Log::setPattern( Patterns p )
{
	if ( s_CurrentPattern == p ) { return; }

	s_CurrentPattern = p;
	switch ( p )
	{
		case Patterns::Simple:
			spdlog::set_pattern( "%^[%T] %n: %v%$" );
			return;
		case Patterns::Line:
			spdlog::set_pattern( "%^[%T][%s][Line:%#] %n: %v%$" );
			return;
	}
	
}

} // namepsace Normal