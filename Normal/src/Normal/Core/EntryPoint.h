#pragma once

#ifdef NR_PLATFORM_WINDOWS

extern Normal::Application* Normal::CreateApplication();

int main( int argc, char** argv )
{
	auto app = Normal::CreateApplication();

	app->Run();
	
	delete app;

#ifdef _DEBUG
	_CrtSetDbgFlag( _CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF );
#endif
}

#endif 