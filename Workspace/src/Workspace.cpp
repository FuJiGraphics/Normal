#include <NormalEngine.h>
#include "World/World.h"

class Workspace : public Normal::Application
{
public:
	Workspace()
	{
	}
	~Workspace()
	{
	}

private:

};

Normal::Application* Normal::CreateApplication()
{
	static Workspace* s_pWorkspace = nullptr;
	if (s_pWorkspace == nullptr)
	{
		s_pWorkspace = new Workspace();
	}
	return s_pWorkspace;
}

