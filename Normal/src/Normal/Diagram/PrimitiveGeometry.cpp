#include "Nrpch.h"
#include "PrimitiveGeometry.h"
#include <Normal/Renderer/Buffer.h>

Normal::Quad::Quad( const glm::vec3& v0, const glm::vec3& v1,
					const glm::vec3& v2, const glm::vec3& v3,
					const std::vector<NRuint>& idx )
{
	std::array<NRfloat, 12> vertices{	v0.x, v0.y, v0.z, 
										v1.x, v1.y, v1.z, 
										v2.x, v2.y, v2.z, 
										v3.x, v3.y, v3.z };
	std::array<NRuint, 6> indices{	idx[0], idx[1], idx[2],
									idx[3], idx[4], idx[5] };
	
	Own::Share<VertexBuffer> vbo = VertexBuffer::Create( vertices.data(), sizeof( float ) * vertices.size() );
	Own::Share<IndexBuffer> ib = IndexBuffer::Create( indices.data(), indices.size() );

	BufferLayout layout{
		{ShaderDataType::Float3, "a_Position"}
	};

	vbo->SetLayout( layout );

	m_VertexArray = VertexArray::Create();
	m_VertexArray->AddVertexBuffer( vbo );
	m_VertexArray->SetIndexBuffer( ib );

	ShaderPaths paths;
	paths.VertPath = "asset/shaders/color/Vertex.glsl";
	paths.FragPath = "asset/shaders/color/Fragment.glsl";
	m_ShaderManager.Add( "Quad", Normal::Shader::Create( paths ) );

}

Normal::Quad::~Quad()
{
	m_VertexArray->UnBind();
}

void Normal::Quad::Bind() const
{
	m_VertexArray->Bind();
}

void Normal::Quad::UnBind() const
{
	m_VertexArray->UnBind();
}
