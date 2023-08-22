#include "Nrpch.h"
#include "World.h"
#include <Normal/Renderer/Renderer.h>

namespace Normal {
	World::World()
	{
		// Create Orthogonal Camera
		m_Camera = std::make_shared<OrthogonalCamera>( -1.0f, 1.0f, -1.0f, 1.0f );

		// Bind a Event Callback Function
		super::s_KeyboardInput.AttachCallback( BIND_EVENT_FUNC( World::OnKeyPressed ), 
											   KeyInput::Type::IsPressed );
	}
	void World::OnEvent( Event& event )
	{
		super::s_KeyboardInput.OnEvent( event );
	}

	void World::OnUpdate( float deltaTime )
	{
		Renderer::BeginScene( m_Camera );
		RenderCommand::Clear();
		RenderCommand::SetClearColor( { 0.2f, 0.2f, 0.2f, 1.0f } );

		Renderer::Submit( m_Rec.GetShader(), m_Rec.GetVertexArray() );

		Renderer::EndScene();
	}

	void World::OnKeyPressed( KeyInputData event )
	{
		switch ( event.keycode )
		{
			case NR_KEY_UP:
				m_Camera->AddPosition( { 0.0f, -0.1f, 0.0f } );
				break;
			case NR_KEY_DOWN: 
				m_Camera->AddPosition( { 0.0f, +0.1f, 0.0f } );
				break;
			case NR_KEY_LEFT:
				m_Camera->AddPosition( { +0.1f, 0.0f, 0.0f } );
				break;
			case NR_KEY_RIGHT:
				m_Camera->AddPosition( { -0.1f, 0.0f, 0.0f } );
				break;
			case NR_KEY_A:
				m_Camera->AddRotation( -10.0f, EularAngle::Roll );
				break;
			case NR_KEY_D:
				m_Camera->AddRotation( +10.0f, EularAngle::Roll );
				break;
			case NR_KEY_W:
				m_Camera->AddRotation( -10.0f, EularAngle::Pitch );
				break;
			case NR_KEY_S:
				m_Camera->AddRotation( +10.0f, EularAngle::Pitch);
				break;
		}
	}

}
