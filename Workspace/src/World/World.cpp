#include "Nrpch.h"
#include "World.h"
#include <Normal/Renderer/Renderer.h>

using namespace Normal;

World::World()
{
	// Create Orthogonal Camera
	m_Camera = std::make_shared<Normal::OrthogonalCamera>( -1.0f, 1.0f, -1.0f, 1.0f );

}
void World::OnEvent( Event& event )
{
}

void World::OnUpdate( const float& dt )
{
	// InputKey Polling
	static glm::vec3 moveLR{0.0f, 0.0f, 0.0f};
	if ( KeyInput::IsKeyPreesed( NR_KEY_RIGHT ) )
	{
		moveLR += ( glm::vec3( 1.0f, 0.0f, 0.0f ) * dt );
		m_Camera->SetPosition( moveLR );
	}
	if ( KeyInput::IsKeyPreesed( NR_KEY_LEFT ) )
	{
		moveLR += ( glm::vec3( -1.0f, 0.0f, 0.0f ) * dt );
		m_Camera->SetPosition( moveLR );
	}
	if ( KeyInput::IsKeyPreesed( NR_KEY_UP ) )
	{
		moveLR += ( glm::vec3( 0.0f, 1.0f, 0.0f ) * dt );
		m_Camera->SetPosition( moveLR );
	}
	if ( KeyInput::IsKeyPreesed( NR_KEY_DOWN ) )
	{
		moveLR += ( glm::vec3( 0.0f, -1.0f, 0.0f ) * dt );
		m_Camera->SetPosition( moveLR );
	}

	// Renderering 
	Renderer::BeginScene( m_Camera );
	RenderCommand::Clear();
	RenderCommand::SetClearColor( { 0.2f, 0.2f, 0.2f, 1.0f } );

	Renderer::Submit( m_Rec.GetShader(), m_Rec.GetVertexArray() );
	Renderer::EndScene();
}

