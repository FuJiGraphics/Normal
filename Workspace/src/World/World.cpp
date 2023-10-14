#include "Nrpch.h"
#include "World.h"

using namespace Normal;

World::World()
	: m_CameraManager( 1280.0f / 720.0f )
{
	// Create Orthogonal Camera
	// 윈도우 화면 비에 맞게 생성한다. 16:9 == 1280:720
	m_CameraManager.ActivateRotation( true );
	m_SquareColor = glm::vec4( 1.7f, 0.7f, 0.7f, 1.0f );
}
void World::OnEvent( Event& event )
{
	m_CameraManager.OnEvent( event );
}

void World::OnUpdate( const float& dt )
{
	// Camera Manager
	m_CameraManager.OnUpdate( dt );

	// Renderering 
	Renderer2D::BeginScene( m_CameraManager );

	Renderer2D::DrawQuad( { 1.0f, 1.0f, 1.0f }, m_SquareColor );

	Renderer2D::EndScene();
}

void World::OnGuiRender()
{
	ImGui::ColorEdit4( "Color", glm::value_ptr( m_SquareColor ) );
}
