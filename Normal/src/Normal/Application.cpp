#include "Nrpch.h"
#include "Application.h"

#include "Normal/Event/ApplicationEvent.h"
#include "Normal/Log.h"

#include "Event/Event.h"
#include "Window.h"

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

	while ( m_Running )
	{
		m_Window->OnUpdate();
	}
}


} // namespace Normal