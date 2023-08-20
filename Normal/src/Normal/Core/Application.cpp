#include "Nrpch.h"
#include "Application.h"

#include "Window.h"
#include "Level.h"
#include "LevelContainer.h"

#include <Normal/Events/Event.h>
#include <Normal/InputManager/WindowInput.h>

#include <Normal/ImGui/ImGuiLevel.h>

#include <Normal/Renderer/Renderer.h>
#include <Normal/Renderer/VertexArray.h>
#include <Normal/Renderer/Buffer.h>
#include <Normal/Renderer/Shader.h>

namespace Normal {

	WindowInput& Application::s_WindowInput = WindowInput::GetInstance();

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
		while ( m_Running )
		{
			{ // ------ Scene Rendering start -------
				/*RenderCommand::SetClearColor( { 0.2f, 0.2f, 0.2f, 1.0f } );
				RenderCommand::Clear();

				Renderer::Submit( m_SquareVertexArray );
				Renderer::Submit( m_VertexArray );

				Renderer::EndScene();*/
			} // ------ Scene Rendering end -------


			// Start update a Level and Overlays
			for ( auto level : *m_LevelContainer )
			{
				level->OnUpdate( 0 );
			}

			// -- ImGui Start --
			m_ImGuiLevel->BeginFrame();
			for ( auto level : *m_LevelContainer )
			{
				level->OnGuiRender();
			}
			m_ImGuiLevel->EndFrame();
			// -- ImGui End --

			// Update a Window and Renderer
			m_Window->OnUpdate();
		}
	}

	void Application::OnEvent( Event& event )
	{
		s_WindowInput.OnEvent( event );

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

	void Application::Initialize()
	{
		m_Window = std::unique_ptr<Window>( Window::Create() );
		m_Window->SetEventCallback( BIND_EVENT_FUNC( Application::OnEvent ) );

		m_LevelContainer = std::make_unique<LevelContainer>();

		m_ImGuiLevel = new ImGuiLevel;
		m_LevelContainer->InsertOverlay( m_ImGuiLevel );

		s_WindowInput.AttachCallback( BIND_EVENT_FUNC( Application::OnWindowClose ), 
									  WindowInput::Type::IsClosed );
	}

	void Application::Destroy()
	{
		// NR_CORE_DELETE( m_LevelContainer, "m_LevelContainer" );
	}

} // namespace Normal