#include "Nrpch.h"
#include "Application.h"

#include <GLFW/glfw3.h>

#include "Window.h"
#include "Level.h"
#include "LevelContainer.h"

#include "Normal/Events/Event.h"
#include "Normal/InputManager/WindowInput.h"

namespace Normal {

	Application::Application()
		: m_WindowInput( WindowInput::GetInstance() )
	{
		NR_CORE_ASSERT( !s_Instance, "Application already exists." );
		s_Instance = this;

		m_Window = std::unique_ptr<Window>( Window::Create() );
		m_Window->SetEventCallback( BIND_EVENT_FUNC( Application::OnEvent ) );

		m_WindowInput.AttachCallback( BIND_NOARGS_FUNC(Application::OnWindowClose), WindowInput::Type::IsClosed);
		
		m_LevelContainer = new LevelContainer;
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
					level->OnUpdate( time );
					level->OnRender();
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

	void Application::AttachLevel( Level* level )
	{
		NR_CORE_ASSERT( level, "Failed to Attached Level." );
		m_LevelContainer->PushLevel( level );
		level->OnAttach();
	}

	void Application::DetachLevel( Level* level )
	{
		NR_CORE_ASSERT( level, "Failed to Detached Level." );
		m_LevelContainer->PopOverlay( level );
		level->OnDetach();
	}

	void Application::AttachOverlay( Level* overlay )
	{
		NR_CORE_ASSERT( overlay, "Failed to Attached Overlay." );
		m_LevelContainer->PushOverlay( overlay );
		overlay->OnAttach();
	}

	void Application::DetachOverlay( Level* overlay )
	{
		NR_CORE_ASSERT( overlay, "Failed to Detached Overlay." );
		m_LevelContainer->PopOverlay( overlay );
		overlay->OnDetach();
	}

	void Application::OnEvent( Event& event )
	{
		m_WindowInput.OnEvent( event );

		for ( auto level = m_LevelContainer->end(); level != m_LevelContainer->begin(); )
		{
			--level;
			( *level )->OnEvent( event );
			if ( event.handled )
				break;
		}
	}

	void Application::OnWindowClose()
	{
		m_Running = false;
	}

} // namespace Normal