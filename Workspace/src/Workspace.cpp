#include <NormalEngine.h>

class Workspace : public Normal::Application
{
public:
	Workspace()
	{

	}
	~Workspace()
	{

	}
};

Normal::Application* Normal::CreateApplication()
{

	return new Workspace();
}