#include "Nrpch.h"
#include "Application.h"

#include "Event/ApplicationEvent.h"
#include "Event/Event.h"

#include "Window.h"
#include "Log.h"

namespace Normal {


Application::Application()
{
	m_Window = std::unique_ptr<Window> ( Window::Create() );
	// TODO : Create Windows Window
}

Application::~Application()
{

}

void Application::Run()
{

	while ( m_Running )
	{

	}
}


} // namespace Normal