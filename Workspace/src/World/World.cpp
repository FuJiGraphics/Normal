#include "Nrpch.h"
#include "World.h"
#include <Normal/Renderer/Renderer.h>

using namespace Normal;

World::World()
{
	// Create Orthogonal Camera
	// 윈도우 화면 비에 맞게 생성한다. 16:9 == 1280:720
	m_Camera = std::make_shared<Normal::OrthogonalCamera>( -1.6f, 1.6f, -0.9f, 0.9f );
	m_SquareColor = glm::vec4( 0.7f, 0.7f, 0.7f, 1.0f );
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

	// Create Tile Object
	static glm::mat4 scale = glm::scale( glm::mat4( 1.0f ), glm::vec3( 0.1f ) );
	for ( int i = -5; i < 5; ++i )
	{
		for ( int j = -5; j < 5; ++j )
		{
			// TODO : 머티리얼 시스템을 만들어야 함.
			// 셰이더에 머티리얼 유니폼을 제출할 때, 각 모두 셰이더에 유니폼을 제출하는 것은 비용이 크다.
			// 메시가 필요로 하는 머티리얼 구성을 취사선택할 수 있도록 시스템을 따로 만드는 것이 좋다.
			// 예를 들어, Mesh -> SetMetiral(인스턴스) 이런식으로
			// 이러한 방식의 장점은 동일한 머티리얼의 종류끼리 우선 정렬을 한 다음 
			// 같은 머티리얼을 사용하는 객체들을 우선 렌더링한 후 머티리얼을 바꿔서 다시 렌더링 하는 등
			// 최적화가 원활해지기 때문이다.
			glm::mat4 transform = glm::translate( glm::mat4( 1.0f ), glm::vec3( i * 0.11f, j * 0.11f, 0.0f ) );
			Renderer::Submit( m_Rec.GetShader(), m_Rec.GetVertexArray(), transform * scale, m_SquareColor );
		}
	}

	Renderer::EndScene();
}

void World::OnGuiRender()
{
	ImGui::ColorEdit4( "Tile Color", glm::value_ptr( m_SquareColor ) );
}
