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


// testing
#include "Renderers/OpenGL/TestRenderer.h"

namespace Normal {

	Application::Application()
		:m_LevelContainer( nullptr )
	{
		m_Window = std::unique_ptr<Window>( Window::Create() );
		m_Window->SetEventCallback( BIND_EVENT_FUNC( Application::OnEvent ) );
		
		m_LevelContainer = new LevelContainer;
		// testing
		
		TestRenderer* test = new TestRenderer();
		m_LevelContainer->PushLevel( test );
	}

	Application::~Application()
	{
		NR_CORE_DELETE( m_LevelContainer, "m_LevelContainer" );
	}

	void Application::Run()
	{
		static double frame = 0.0;
		static double contain = 0.0;
		static double limit = 0.0;
		while ( m_Running )
		{
			double time = glfwGetTime();
			time = ( m_Time > 0.001 ) ? time - m_Time : 1.0 / 60.0;
			if ( limit > 0.007 )
			{
				limit = 0.0;
				m_Window->OnUpdate();
				for ( auto& level : *m_LevelContainer )
				{
					( *level ).OnUpdate( time );
				}
				++frame;
			}
			m_Time = m_Time + time;
			contain += time;
			limit += time;
			if ( contain > 1.0 )
			{
				NR_CORE_TRACE( "Frame:{0}", frame );
				frame = 0.0;
				contain = 0.0;
			}
		}
	}

	void Application::OnEvent( Event& event )
	{
		EventDispatcher dispatcher( event );
		dispatcher.Dispatch<WindowCloseEvent>( BIND_EVENT_FUNC( Application::OnWindowClose ) );

		// NR_CORE_INFO( "{0}", event );
		
		for ( auto level = m_LevelContainer->end(); level != m_LevelContainer->begin(); )
		{
			--level;
			( *level )->OnEvent( event );
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