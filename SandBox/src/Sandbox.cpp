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
	
	NR_CLIENT_LINE_TRACE( "client trace" );
	NR_CLIENT_LINE_INFO( "client info" );
	NR_CLIENT_LINE_WARN( "client warn" );
	NR_CLIENT_LINE_ERROR( "client error" );
	NR_CLIENT_LINE_CRITICAL( "client critical" );

	return new SandBox();
}