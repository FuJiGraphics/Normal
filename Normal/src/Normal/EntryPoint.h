#pragma once

#ifdef NR_PLATFORM_WINDOWS

extern Normal::Application* Normal::CreateApplication();

int main( int argc, char** argv )
{
	Normal::Log::init();

	NR_CORE_LINE_TRACE( "core trace" ); 
	NR_CORE_LINE_DEBUG( "core debug" );
	NR_CORE_LINE_INFO( "core info" ); 
	NR_CORE_LINE_WARN( "core warning" ); 
	NR_CORE_LINE_ERROR( "core error" ); 
	NR_CORE_LINE_CRITICAL( "core critical" );

	auto app = Normal::CreateApplication();
	app->Run();
	delete app;
}

#endif 