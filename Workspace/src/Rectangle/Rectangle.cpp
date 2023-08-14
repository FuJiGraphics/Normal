#include "Nrpch.h"
#include "Rectangle.h"

namespace Normal {
	// TODO: 완성하기
	Rectangle::Rectangle()
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

		{ // Create a Vertex Array
			// Created a VertexBuffer
			std::shared_ptr<VertexBuffer> vertexBuffer;
			vertexBuffer.reset(VertexBuffer::Create(m_Data.data(), sizeof(float) * m_Data.size()));

			// Created a BufferLayout;
			BufferLayout bufferLayout = {
				{ ShaderDataType::Float4, "a_Position" },
				{ ShaderDataType::Float4, "a_Color" }
			};
			// Set Buffer layout in VertexBuffer
			vertexBuffer->SetLayout(bufferLayout);

			// Created a IndexBuffer
			std::shared_ptr<IndexBuffer> indexBuffer;
			indexBuffer.reset(IndexBuffer::Create(m_Indices.data(), m_Indices.size()));
			m_VertexArray->SetIndexBuffer(indexBuffer);

			// Set Index, Vertex buffer in the VertexArray
			m_VertexArray->AddVertexBuffer(vertexBuffer);
			m_VertexArray->SetIndexBuffer(indexBuffer);
		}
	}
	Rectangle::~Rectangle()
	{


	}
	
	void Rectangle::OnUpdate(float deltaTime)
	{
		m_VertexArray->Bind();
	}

} // namespace Normal 