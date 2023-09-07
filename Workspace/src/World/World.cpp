#include "Nrpch.h"
#include "World.h"
#include <Normal/Renderer/Renderer.h>

using namespace Normal;

World::World()
{
	// Create Orthogonal Camera
	// ������ ȭ�� �� �°� �����Ѵ�. 16:9 == 1280:720
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
			// TODO : ��Ƽ���� �ý����� ������ ��.
			// ���̴��� ��Ƽ���� �������� ������ ��, �� ��� ���̴��� �������� �����ϴ� ���� ����� ũ��.
			// �޽ð� �ʿ�� �ϴ� ��Ƽ���� ������ ��缱���� �� �ֵ��� �ý����� ���� ����� ���� ����.
			// ���� ���, Mesh -> SetMetiral(�ν��Ͻ�) �̷�������
			// �̷��� ����� ������ ������ ��Ƽ������ �������� �켱 ������ �� ���� 
			// ���� ��Ƽ������ ����ϴ� ��ü���� �켱 �������� �� ��Ƽ������ �ٲ㼭 �ٽ� ������ �ϴ� ��
			// ����ȭ�� ��Ȱ������ �����̴�.
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
