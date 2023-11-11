#include "Nrpch.h"
#include "Application.h"

#include "Window.h"
#include "Level.h"
#include "LevelContainer.h"
#include "Timer.h"

#include <Normal/ImGui/ImGuiLevel.h>
#include <Normal/Renderer/Renderer.h>

namespace Normal {
	Application::Application()
	{
		NR_CORE_ASSERT( !s_Instance, "Application already exists." );
		s_Instance = this;

		Initialize();
		NR_CORE_INFO_CTOR;
	}

	Application::~Application()
	{
		Destroy();
		NR_CORE_INFO_DTOR;
	}

	void Application::Run()
	{
		static Timer timer( "Delta Time" );
		while ( m_Running )
		{
			// Timer update
			timer.Update( true );

			// Start update a Level and Overlays
			if ( m_Minimized == false )
			{
				// Set a Refresh Rate
				for ( auto level : *m_LevelContainer )
				{
					level->OnUpdate( timer.ElapsedTime( Timer::Seconds ) );
				}
				// -- ImGui Start --
				m_ImGuiLevel->BeginFrame();
				for ( auto level : *m_LevelContainer )
				{
					level->OnGuiRender();
				}
				m_ImGuiLevel->EndFrame();
				// -- ImGui End --
			}
			// Update a Window and Renderer
			m_Window->OnUpdate();
		}
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

	void Application::AttachLevel( Level* level )
	{
		NR_CORE_ASSERT( level, "Failed to Attached Level." );
		m_LevelContainer->InsertLevel( level );
		level->OnAttach();
	}

	void Application::DetachLevel( Level* level )
	{
		NR_CORE_ASSERT( level, "Failed to Detached Level." );
		m_LevelContainer->RemoveLevel( level );
		level->OnDetach();
	}

	void Application::AttachOverlay( Level* overlay )
	{
		NR_CORE_ASSERT( overlay, "Failed to Attached Overlay." );
		m_LevelContainer->InsertOverlay( overlay );
		overlay->OnAttach();
	}

	void Application::DetachOverlay( Level* overlay )
	{
		NR_CORE_ASSERT( overlay, "Failed to Detached Overlay." );
		m_LevelContainer->RemoveOverlay( overlay );
		overlay->OnDetach();
	}

	void Application::OnWindowClose( WindowInputData input )
	{
		m_Running = false;
	}

	void Application::OnWindowResize( WindowInputData input )
	{
		if ( input.width <= 0.001f && input.height <= 0.001f )
			m_Minimized = true;
		else
		{
			m_Minimized = false;
			m_Window->SetWindowSize( input.width, input.height );
			// RenderCommand::SetViewport( 0, 0, input.width, input.height );
		}
	}

	void Application::Initialize()
	{
		// Create LevelContainer
		m_LevelContainer.reset( new LevelContainer() );

		// Window Initialze and Set Callback Functions
		m_Window.reset( Window::Create() );
		m_Window->SetEventCallback( BIND_EVENT_FUNC( Application::OnEvent ) );
		m_Window->SetWindowSize( 1280, 720 );
		m_Window->SetVSync( true );

		m_WindowInput.AttachCallback( BIND_EVENT_FUNC( Application::OnWindowClose ), WindowInput::Type::IsClosed );
		m_WindowInput.AttachCallback( BIND_EVENT_FUNC( Application::OnWindowResize ), WindowInput::Type::IsResized );

		// Set Blend
		RenderCommand::SetBlend( true );
		// Set Viewport
		RenderCommand::SetViewport( 0, 0, 1280, 720 );

		// Init Renderer
		Renderer::Initialize();

		// Create Imgui
		// Level Container에 메모리 관리 권한을 위임함
		m_ImGuiLevel = new ImGuiLevel;
		m_LevelContainer->InsertOverlay( m_ImGuiLevel );
	}

	void Application::Destroy()
	{
		// NR_CORE_DELETE( m_LevelContainer, "m_LevelContainer" );
		RenderCommand::DestroyRendererAPI();
		Renderer::Finalize();
	}

} // namespace Normal