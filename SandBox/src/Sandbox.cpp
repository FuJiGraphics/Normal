#include <NormalEngine.h>

class SandBox : public Normal::Application
{
public:
	SandBox()
	{

	}
	~SandBox()
	{

	}
};

Normal::Application* Normal::CreateApplication()
{


	return new SandBox();
}