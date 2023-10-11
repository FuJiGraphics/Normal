#include "Nrpch.h"
#include "World.h"
#include <Normal/Renderer/Renderer.h>

using namespace Normal;

World::World()
	: m_CameraManager( 1280.0f / 720.0f )
{
	// Create Orthogonal Camera
	// ������ ȭ�� �� �°� �����Ѵ�. 16:9 == 1280:720
	m_SquareColor = glm::vec4( 0.7f, 0.7f, 0.7f, 1.0f );

	m_Rec.GetShader()->Bind();
	m_Rec.GetShader()->UploadUniformInt( "u_Texture", 0 );

	m_Texture.reset( Texture2D::Create( "asset/textures/tiles.png" ) );
	m_BlendTexture.reset( Texture2D::Create( "asset/textures/yuyuko2.png" ) );
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
	Renderer::BeginScene( m_CameraManager.GetCamera() );
	RenderCommand::Clear();
	RenderCommand::SetClearColor( { 0.2f, 0.2f, 0.2f, 1.0f } );

	// Create Tile Object
	//static glm::mat4 scale = glm::scale( glm::mat4( 1.0f ), glm::vec3( 0.1f ) );
	//for ( int i = -5; i < 5; ++i )
	//{
	//	for ( int j = -5; j < 5; ++j )
	//	{
	//		// TODO : ��Ƽ���� �ý����� ������ ��.
	//		// ���̴��� ��Ƽ���� �������� ������ ��, �� ��� ���̴��� �������� �����ϴ� ���� ����� ũ��.
	//		// �޽ð� �ʿ�� �ϴ� ��Ƽ���� ������ ��缱���� �� �ֵ��� �ý����� ���� ����� ���� ����.
	//		// ���� ���, Mesh -> SetMetiral(�ν��Ͻ�) �̷�������
	//		// �̷��� ����� ������ ������ ��Ƽ������ �������� �켱 ������ �� ���� 
	//		// ���� ��Ƽ������ ����ϴ� ��ü���� �켱 �������� �� ��Ƽ������ �ٲ㼭 �ٽ� ������ �ϴ� ��
	//		// ����ȭ�� ��Ȱ������ �����̴�.
	//		glm::mat4 transform = glm::translate( glm::mat4( 1.0f ), glm::vec3( i * 0.11f, j * 0.11f, 0.0f ) );
	//		Renderer::Submit( m_Rec.GetShader(), m_Rec.GetVertexArray(), transform * scale, m_SquareColor );
	//	}
	//}

	glm::mat4 transform2 = glm::translate( glm::mat4( 1.0f ), glm::vec3( 0.0f, -0.3f, 0.0f ) );

	m_Texture->Bind();
	Renderer::Submit( m_Rec.GetShader(), m_Rec.GetVertexArray(), 
					  glm::scale( glm::mat4( 1.0f ), glm::vec3( 1.5f ) ), 
					  m_SquareColor );

	m_BlendTexture->Bind();
	Renderer::Submit( m_Rec.GetShader(), m_Rec.GetVertexArray(),
					  glm::scale( glm::mat4( 1.0f ), glm::vec3( 1.0f ) ), 
					  m_SquareColor );

	Renderer::EndScene();
}

void World::OnGuiRender()
{
	ImGui::ColorEdit4( "Tile Color", glm::value_ptr( m_SquareColor ) );
}
