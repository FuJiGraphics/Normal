#include "Nrpch.h"
#include "PrimitiveGeometry.h"
#include <Normal/Renderer/Buffer.h>

Normal::Quad2D::Quad2D( const bool enableTextureMode, 
						const glm::vec3& v0, const glm::vec3& v1,
						const glm::vec3& v2, const glm::vec3& v3,
						const std::vector<NRuint>& idx )
{
	const NRint size = ( enableTextureMode ) ? 20 : 12;
	std::vector<float> vertices;
	if ( enableTextureMode )
	{
		
		m_Data = {	v0.x, v0.y, v0.z, 0.0f, 0.0f,
					v1.x, v1.y, v1.z, 1.0f, 0.0f,
					v2.x, v2.y, v2.z, 1.0f, 1.0f,
					v3.x, v3.y, v3.z, 0.0f, 1.0f };
	}
	else
	{
		m_Data = {	v0.x, v0.y, v0.z,
					v1.x, v1.y, v1.z,
					v2.x, v2.y, v2.z,
					v3.x, v3.y, v3.z };
	}
	m_Indices = {	idx[0], idx[1], idx[2],
					idx[3], idx[4], idx[5] };
	
	Own::Share<VertexBuffer> vbo = VertexBuffer::Create( m_Data.data(), sizeof( float ) * m_Data.size() );
	Own::Share<IndexBuffer> ib = IndexBuffer::Create( m_Indices.data(), m_Indices.size() );

	Own::Share<BufferLayout> layout;

	if ( enableTextureMode ) 
	{
		layout.reset( new BufferLayout{
			{ShaderDataType::Float3, "a_Position"},
			{ShaderDataType::Float2, "a_TexCoord" } } );
	}
	else
	{
		layout.reset( new BufferLayout {
			{ShaderDataType::Float3, "a_Position"} } );
	}

	vbo->SetLayout( layout );

	m_VertexArray = VertexArray::Create();
	m_VertexArray->AddVertexBuffer( vbo );
	m_VertexArray->SetIndexBuffer( ib );
}

Normal::Quad2D::~Quad2D()
{
	m_VertexArray->UnBind();
}

void Normal::Quad2D::Bind() const
{
	m_VertexArray->Bind();
}

void Normal::Quad2D::UnBind() const
{
	m_VertexArray->UnBind();
}
