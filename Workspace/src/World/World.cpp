#include "Nrpch.h"
#include "World.h"

using namespace Normal;

World::World()
	: m_CameraManager( 1280.0f / 720.0f )
	, m_Tex_Yuyuko1( Texture2D::Create( "asset/textures/yuyuko1.png" ) )
	, m_Tex_Yuyuko2( Texture2D::Create( "asset/textures/yuyuko2.png" ) )
	, m_Tex_Tile( Texture2D::Create( "asset/textures/tile.png" ) )
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

	static glm::vec2 movement( 0.0f );
	static glm::vec2 scale( 1.5f );
	// Move Quad
	if ( KeyInput::IsKeyPreesed( NR_KEY_I ) )
		movement += dt * glm::vec2( 0.0f, +1.0f );
	if ( KeyInput::IsKeyPreesed( NR_KEY_K ) )
		movement += dt * glm::vec2( 0.0f, -1.0f );
	if ( KeyInput::IsKeyPreesed( NR_KEY_J ) )
		movement += dt * glm::vec2( -1.0f, 0.0f );
	if ( KeyInput::IsKeyPreesed( NR_KEY_L ) )
		movement += dt * glm::vec2( +1.0f, 0.0f );
	if ( KeyInput::IsKeyPreesed( NR_KEY_U ) )
		scale += dt * glm::vec2( -1.0f, -1.0f );
	if ( KeyInput::IsKeyPreesed( NR_KEY_O ) )
		scale += dt * glm::vec2( +1.0f, +1.0f );

	// Renderering 
	Renderer2D::BeginScene( m_CameraManager );
	
	Renderer2D::DrawQuad( movement - glm::vec2( 0.5f, 0.5f ), scale, m_SquareColor );
	Renderer2D::DrawQuad( movement, scale, m_Tex_Tile );
	Renderer2D::DrawQuad( movement + glm::vec2( 0.5f, 0.0f ), scale, m_Tex_Yuyuko1 );
	Renderer2D::DrawQuad( movement + glm::vec2( -0.5f, 0.0f ), scale, m_Tex_Yuyuko2 );

	Renderer2D::EndScene();
}

void World::OnGuiRender()
{
	ImGui::ColorEdit4( "Color", glm::value_ptr( m_SquareColor ) );
}
