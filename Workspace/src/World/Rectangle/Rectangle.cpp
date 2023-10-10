#include "Nrpch.h"
#include "Rectangle.h"

using namespace Normal;

Rec::Rec()
	: m_Data()
	, m_Indices()
{
	m_Data = {
		-0.5f, -0.5f, 0.0f, 0.0f, 0.0f,
		+0.5f, -0.5f, 0.0f, 1.0f, 0.0f,
		+0.5f, +0.5f, 0.0f, 1.0f, 1.0f,
		-0.5f, +0.5f, 0.0f, 0.0f, 1.0f,
	};

	m_Indices = { 0, 1, 2, 0, 2, 3 };

	{
		// Create a Vertex Array
		m_VertexArray.reset( VertexArray::Create() );

		// Created a VertexBuffer
		Own::Share<Normal::VertexBuffer> vertexBuffer;
		vertexBuffer.reset( Normal::VertexBuffer::Create(m_Data.data(), sizeof(float) * m_Data.size()));

		// Created a BufferLayout;
		Normal::BufferLayout bufferLayout = {
			{ Normal::ShaderDataType::Float3, "a_Position" },
			{ Normal::ShaderDataType::Float2, "a_TexCoord"},
		};
		// Set Buffer layout in VertexBuffer
		vertexBuffer->SetLayout(bufferLayout);

		// Created a IndexBuffer
		Own::Share<Normal::IndexBuffer> indexBuffer;
		indexBuffer.reset( Normal::IndexBuffer::Create(m_Indices.data(), m_Indices.size()));

		// Set Index, Vertex buffer in the VertexArray
		m_VertexArray->AddVertexBuffer(vertexBuffer);
		m_VertexArray->SetIndexBuffer(indexBuffer);

		// Shader
		ShaderPaths paths;
		paths.VertPath = "asset/shaders/texture/Vertex.glsl";
		paths.FragPath = "asset/shaders/texture/Fragment.glsl";
		m_ShaderManager.Add( "Rectangle", Normal::Shader::Create( paths ) );
	}
}
Rec::~Rec()
{
	m_VertexArray->UnBind();
}

void Rec::Bind() const
{
	m_VertexArray->Bind();
}

void Rec::UnBind() const
{
	m_VertexArray->UnBind();
}
