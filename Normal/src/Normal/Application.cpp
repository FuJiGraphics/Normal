#include "Nrpch.h"
#include "Application.h"

#include <GLFW/glfw3.h>

namespace Normal {

// #define BIND_EVENT_FN(x) { std::bind( x, this, std::placeholders::_1  ) }

Application::Application()
{
	m_Window = std::unique_ptr<Window>( Window::Create() );
	m_Window->SetEventCallback( std::bind( &Application::OnEvent, this, std::placeholders::_1 ) );
}

Application::~Application()
{

}

void Application::Run()
{
	glClearColor( 0, 1, 0, 1 );
	while ( m_Running )
	{
		glClear( GL_COLOR_BUFFER_BIT );
		m_Window->OnUpdate();
	}
}

void Application::OnEvent( Event& event )
{
	const auto& type = event.GetEventType();

	switch ( type )
	{
		case EventType::WindowClose:
		{
			m_Running = false;
			break;
		}
	}
}


} // namespace Normal