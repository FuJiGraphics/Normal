#include "Wall.h"

using namespace Normal;

Wall::Wall()
	: m_WallColor( {1.7f, 0.7f, 0.7f, 1.0f} )
	, m_Pos( 0.0f, 0.0f )
	, m_Scale( 300.0f, 0.0f )
{/*Empty*/}

void Wall::OnEvent( Event& event )
{

}

void Wall::OnUpdate( const float& dt )
{
	auto& ref_camera = CameraManager::GetInstance();
	static glm::vec2 scale( { 1.0f, 1.0f } );

	// Rendering 
	Renderer2D::BeginScene( ref_camera );
	Renderer2D::DrawQuad( m_Pos, scale, m_WallColor );
	Renderer2D::EndScene();
}

void Wall::OnGuiRender()
{

}

GENERATE_LAYER( Wall )