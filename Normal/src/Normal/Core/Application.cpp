#include "Nrpch.h"
#include "Application.h"

#include <GLFW/glfw3.h>

#include "Window.h"
#include "Level.h"
#include "LevelContainer.h"

#include "Normal/Events/ApplicationEvent.h"
#include "Normal/Events/Event.h"

#include "Normal/InputManager/Mouse.h"
#include "Normal/InputManager/Keyboard.h"

namespace Normal {

	Application::Application()
	{
		m_Window = std::unique_ptr<Window>( Window::Create() );
		m_Window->SetEventCallback( BIND_EVENT_FN( Application::OnEvent ) );

		m_LevelContainer = std::unique_ptr<LevelContainer>( LevelContainer::Create() );

		Mouse* mouse = new Mouse();
		m_LevelContainer->PushLevel( mouse );

		Keyboard* keyboard = new Keyboard();
		m_LevelContainer->PushLevel( keyboard );
	}

	Application::~Application()
	{
		// Empty
	}

	void Application::Run()
	{
		while ( m_Running )
		{
			m_Window->OnUpdate();
		}
	}

	void Application::OnEvent( Event& event )
	{
		EventDispatcher dispatcher( event );
		dispatcher.Dispatch<WindowCloseEvent>( BIND_EVENT_FN( Application::OnWindowClose ) );

		// NR_CORE_INFO( "{0}", event );

		for ( auto level = m_LevelContainer->begin(); level != m_LevelContainer->end(); level++ )
		{
			(*level)->OnEvent( event );
			if ( event.handled )
				break;
		}

	}

	bool Application::OnWindowClose( WindowCloseEvent& event )
	{
		m_Running = false;
		return true;
	}


} // namespace Normal