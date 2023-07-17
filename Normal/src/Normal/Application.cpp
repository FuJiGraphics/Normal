#include "Nrpch.h"
#include "Application.h"

#include "Event/ApplicationEvent.h"
#include "Log.h"

namespace Normal {


Application::Application()
{

}

Application::~Application()
{

}

void Application::Run()
{
	int width = 1280;
	int height = 720;
	WindowResizeEvent winResize( width, height );
	
	NR_CORE_INFO( "initialized WindowResizeEvent Object. Width:{} Height:{}", width, height );

	while ( true );
}


} // namespace Normal