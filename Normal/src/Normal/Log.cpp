#include "Nrpch.h"

#include "Log.h"
#include "spdlog\sinks\stdout_color_sinks.h"

namespace Normal {

std::shared_ptr<spdlog::logger> Log::s_CoreLogger;
std::shared_ptr<spdlog::logger> Log::s_ClientLogger;
Log::Patterns Log::m_CurrentPattern;

void Log::init()
{
	// spdlog::set_default_logger( s_CoreLogger );
	spdlog::set_pattern( "%^[%T] %n: %v%$" );
	m_CurrentPattern = Patterns::Simple;

	s_CoreLogger = spdlog::stdout_color_mt( "ENGINE" );
	s_CoreLogger->set_level( spdlog::level::trace );

	s_ClientLogger = spdlog::stdout_color_mt( "APP" );
	s_ClientLogger->set_level( spdlog::level::trace );

}

void Log::setPattern( Patterns p )
{
	if ( m_CurrentPattern == p ) { return; }

	m_CurrentPattern = p;
	switch ( p )
	{
	case Patterns::Simple:
		spdlog::set_pattern( "%^[%T] %n: %v%$" );
		return;
	case Patterns::Line:
		spdlog::set_pattern( "%^[%@][%T] %n: %v%$" );
		return;
	}
	
}

} // namepsace Normal