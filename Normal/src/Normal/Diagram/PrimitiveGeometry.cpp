#include "Nrpch.h"
#include "PrimitiveGeometry.h"
#include <Normal/Renderer/Buffer.h>

Normal::Quad2D::Quad2D( const NRint& x, const NRint& y, 
						const NRuint& width, const NRuint& height, 
						const std::vector<NRuint>& idx )
{
	float aspect = ( static_cast<float>( width ) / height ) - 0.5f;

	m_Data = {  -0.5f,	-0.5f,	0.0f, 0.0f, 0.0f,
				aspect,	-0.5f,	0.0f, 1.0f, 0.0f,
				aspect,	aspect, 0.0f, 1.0f, 1.0f,
				-0.5f,  aspect,	0.0f, 0.0f, 1.0f};
	m_Indices = {	idx[0], idx[1], idx[2],
					idx[3], idx[4], idx[5] };

	Own::Share<VertexBuffer> VertexBuffer = VertexBuffer::Create( m_Data.data(), sizeof( float ) * m_Data.size() );
	Own::Share<IndexBuffer> indexBuffer = IndexBuffer::Create( m_Indices.data(), m_Indices.size() );

	Own::Share<BufferLayout> layout;
	layout.reset( new BufferLayout{
		{ShaderDataType::Float3, "a_Position"},
		{ShaderDataType::Float2, "a_TexCoord" } } );

	VertexBuffer->SetLayout( layout );

	m_VertexArray = VertexArray::Create();
	m_VertexArray->AddVertexBuffer( VertexBuffer );
	m_VertexArray->SetIndexBuffer( indexBuffer );
}

Normal::Quad2D::Quad2D( const glm::vec3& v0, const glm::vec3& v1,
						const glm::vec3& v2, const glm::vec3& v3,
						const std::vector<NRuint>& idx )
{
	m_Data = {	v0.x, v0.y, v0.z, 0.0f, 0.0f,
				v1.x, v1.y, v1.z, 1.0f, 0.0f,
				v2.x, v2.y, v2.z, 1.0f, 1.0f,
				v3.x, v3.y, v3.z, 0.0f, 1.0f };
	m_Indices = {	idx[0], idx[1], idx[2],
					idx[3], idx[4], idx[5] };
	
	Own::Share<VertexBuffer> VertexBuffer = VertexBuffer::Create( m_Data.data(), sizeof( float ) * m_Data.size() );
	Own::Share<IndexBuffer> indexBuffer = IndexBuffer::Create( m_Indices.data(), m_Indices.size() );

	Own::Share<BufferLayout> layout;
	layout.reset( new BufferLayout{
		{ShaderDataType::Float3, "a_Position"},
		{ShaderDataType::Float2, "a_TexCoord" } } );

	VertexBuffer->SetLayout( layout );

	m_VertexArray = VertexArray::Create();
	m_VertexArray->AddVertexBuffer( VertexBuffer );
	m_VertexArray->SetIndexBuffer( indexBuffer );
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
