#include "World.h"

using namespace Normal;

World::World()
	: m_Tex_Tile( Texture2D::Create( "asset/textures/checkerboard.png" ) )
	, m_Timer( "Rendering" )
{
	m_SquareColor = glm::vec4( 1.7f, 0.7f, 0.7f, 1.0f );
	m_Timer.SetTimeStep( &m_TimeStep );
}

void World::OnEvent( Event& event )
{
}

void World::OnUpdate( const float& dt )
{
	static glm::vec2 movement( 0.0f ); 
	static glm::vec2 scale( { 300.0f, 1.0f } );

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


	// Camera Manager
	auto& camera = CameraManager::GetInstance();
	static glm::vec2 prevMovement;
	if (prevMovement != movement)
	{
		prevMovement = movement;
		camera.SetPosition( movement );
	}

	// Rendering 
	m_Timer.Start();
 	Renderer2D::BeginScene( camera );

	Renderer2D::DrawQuad( {0.0f, 0.0f, 0.0f}, {10.0f, 10.0f}, m_Tex_Tile);

	m_Timer.End();
	Renderer2D::EndScene();
}

void World::OnGuiRender()
{
	std::string text( m_TimeStep.Name );
	text += " DeltaTime = %.3f, Frame = %.3f";
	ImGui::ColorEdit4( "Color", glm::value_ptr( m_SquareColor ) );
	ImGui::Text( text.c_str(), m_TimeStep.DeltaTime, m_TimeStep.Frame );
}

GENERATE_OVERLAY(World)