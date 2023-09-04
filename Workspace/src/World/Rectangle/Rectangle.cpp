#include "Nrpch.h"
#include "Rectangle.h"

Rec::Rec()
	: m_Data()
	, m_Indices()
{
	m_Data = {
		-0.5f, -0.5f, 0.0f, 1.0f, 0.5f, 0.0f, 0.0f, 1.0f,
		+0.5f, -0.5f, 0.0f, 1.0f, 0.0f, 0.5f, 0.0f, 1.0f,
		+0.5f, +0.5f, 0.0f, 1.0f, 0.0f, 0.0f, 0.5f, 1.0f,
		-0.5f, +0.5f, 0.0f, 1.0f, 0.2f, 0.3f, 0.4f, 1.0f,
	};

	m_Indices = { 0, 1, 2, 0, 2, 3 };

	{
		// Create a Vertex Array
		m_VertexArray.reset( Normal::VertexArray::Create() );

		// Created a VertexBuffer
		std::shared_ptr<Normal::VertexBuffer> vertexBuffer;
		vertexBuffer.reset( Normal::VertexBuffer::Create(m_Data.data(), sizeof(float) * m_Data.size()));

		// Created a BufferLayout;
		Normal::BufferLayout bufferLayout = {
			{ Normal::ShaderDataType::Float4, "a_Position" },
			{ Normal::ShaderDataType::Float4, "a_Color" }
		};
		// Set Buffer layout in VertexBuffer
		vertexBuffer->SetLayout(bufferLayout);

		// Created a IndexBuffer
		std::shared_ptr<Normal::IndexBuffer> indexBuffer;
		indexBuffer.reset( Normal::IndexBuffer::Create(m_Indices.data(), m_Indices.size()));

		// Set Index, Vertex buffer in the VertexArray
		m_VertexArray->AddVertexBuffer(vertexBuffer);
		m_VertexArray->SetIndexBuffer(indexBuffer);

		// Shader
		m_VertexShader = R"(
		#version 330 core
		layout (location = 0) in vec3 aPos;
		layout (location = 1) in vec4 aColor;

		uniform mat4 u_Transform;
		uniform mat4 u_ViewProj;

		out vec4 vertexColor;
		
		void main()
		{
			gl_Position = u_ViewProj * u_Transform * vec4(aPos, 1.0);
			vertexColor = aColor;
		}		
		)";

		m_IndexShader = R"(
		#version 330 core
		out vec4 FragColor;

		in vec4 vertexColor;
		void main()
		{
			FragColor = vec4(vec3(0.0f, 0.0f, 0.3f), 1.0f);
		}
		)";

		m_Shader.reset( Normal::Shader::Create( m_VertexShader, m_IndexShader ) );
	}
}
Rec::~Rec()
{
	m_Shader->UnBind();
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
