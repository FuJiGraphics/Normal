#pragma once

#ifdef NR_PLATFORM_WINDOWS

extern Normal::Application* Normal::CreateApplication();

int main( int argc, char** argv )
{
	Normal::Log::init();
	auto app = Normal::CreateApplication();

	app->Run();

	delete app;
}

#endif 