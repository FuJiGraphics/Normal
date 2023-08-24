#include <NormalEngine.h>
#include "World/World.h"

class Workspace : public Normal::Application
{
public:
	Workspace()
	{
		super::AttachLevel( new World );
	}
	~Workspace()
	{
	}

private:

};

Normal::Application* Normal::CreateApplication()
{
	return new Workspace();
}

