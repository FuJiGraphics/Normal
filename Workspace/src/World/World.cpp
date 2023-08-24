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

void World::OnUpdate( float deltaTime )
{
	// InputKey Polling


	// Renderering 
	Renderer::BeginScene( m_Camera );
	RenderCommand::Clear();
	RenderCommand::SetClearColor( { 0.2f, 0.2f, 0.2f, 1.0f } );

	Renderer::Submit( m_Rec.GetShader(), m_Rec.GetVertexArray() );
	Renderer::EndScene();
}

