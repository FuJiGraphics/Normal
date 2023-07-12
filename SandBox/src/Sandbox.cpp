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
	
	NR_LINE_TRACE( "client trace" );
	NR_LINE_INFO( "client info" );
	NR_LINE_WARN( "client warn" );
	NR_LINE_ERROR( "client error" );
	NR_LINE_CRITICAL( "client critical" );

	return new SandBox();
}