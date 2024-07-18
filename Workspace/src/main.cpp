#include <NormalEngine.h>
#include "Workspace.h"

extern Normal::Application* Normal::CreateApplication()
{
	static Workspace* pApp = nullptr;

	if (pApp == nullptr)
		pApp = new Workspace();

	return (pApp);
}

int main( int argc, char** argv )
{
	Normal::Application* app = Normal::CreateApplication();

	app->Run();

	delete app;
#ifdef _DEBUG
	_CrtSetDbgFlag( _CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF );
#endif
}