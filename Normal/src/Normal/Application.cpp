#include "Nrpch.h"
#include "Application.h"

#include <GLFW/glfw3.h>

namespace Normal {


Application::Application()
{
	m_Window = std::unique_ptr<Window>( Window::Create() );
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


} // namespace Normal