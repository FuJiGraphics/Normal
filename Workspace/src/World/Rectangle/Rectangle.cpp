#include "Nrpch.h"
#include "Rectangle.h"

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
		m_VertexArray.reset( Normal::VertexArray::Create() );

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
		m_TexVertexShader = R"(
		#version 330 core
		layout (location = 0) in vec3 a_Pos;
		layout (location = 1) in vec2 a_TexCoord;

		uniform mat4 u_Transform;
		uniform mat4 u_ViewProj;

		out vec2 TexCoord;
		
		void main()
		{
			gl_Position = u_ViewProj * u_Transform * vec4( a_Pos, 1.0 );
			TexCoord = a_TexCoord;
		}		
		)";

		m_TexFragmentShader = R"(
		#version 330 core

		in vec2 TexCoord;

		uniform vec4 u_SquareColor;
		uniform sampler2D u_Texture;

		out vec4 FragColor;

		void main()
		{
			FragColor = u_SquareColor * texture( u_Texture, TexCoord );
		}
		)";

		m_Shader.reset( Normal::Shader::Create( m_TexVertexShader, m_TexFragmentShader ) );
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
