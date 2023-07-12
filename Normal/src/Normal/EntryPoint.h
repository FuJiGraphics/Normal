#pragma once

#ifdef NR_PLATFORM_WINDOWS

extern Normal::Application* Normal::CreateApplication();

int main( int argc, char** argv )
{
	Normal::Log::init();

	auto logger = Normal::Log::GetCoreLoger();

	SPDLOG_LOGGER_INFO( logger, "log with source info" ); // Use console.

	auto app = Normal::CreateApplication();
	app->Run();
	delete app;
}

#endif 