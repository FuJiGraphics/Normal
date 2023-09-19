#include "Nrpch.h"
#include "OpenGLVertexArray.h"

#include "OpenGLBuffer.h"
#include <glad/glad.h>


// Read a reference from https://velog.io/@parksj3205/%EB%B2%84%ED%85%8D%EC%8A%A4-%EC%96%B4%EB%A0%88%EC%9D%B4-%EB%8B%A4%EB%A3%A8%EA%B8%B0

namespace Normal {


	// 나중에 이 함수를 전역 말고 OpenGL Element를 각 API별로 추상화하고 분리 시킬 지 고민하기
	static int ShaderDataTypeToGLType( const ShaderDataType& type )
	{
		switch ( type )
		{
			case ShaderDataType::Float:   return GL_FLOAT;
			case ShaderDataType::Float2:  return GL_FLOAT;
			case ShaderDataType::Float3:  return GL_FLOAT;
			case ShaderDataType::Float4:  return GL_FLOAT;
			case ShaderDataType::Mat3:    return GL_FLOAT;
			case ShaderDataType::Mat4:    return GL_FLOAT;
			case ShaderDataType::Int:     return GL_INT;
			case ShaderDataType::Int2:    return GL_INT;
			case ShaderDataType::Int3:    return GL_INT;
			case ShaderDataType::Int4:    return GL_INT;
			case ShaderDataType::Bool:    return GL_BOOL;
		}
	}

	OpenGLVertexArray::OpenGLVertexArray()
		: m_RenderID( 0 )
	{
		glCreateVertexArrays( 1, &m_RenderID );
	}

	OpenGLVertexArray::~OpenGLVertexArray()
	{
		glDeleteVertexArrays( 1, &m_RenderID );
	}

	void OpenGLVertexArray::Bind() const
	{
		// Bind VertexArray in the context
		glBindVertexArray( m_RenderID );
	}

	void OpenGLVertexArray::UnBind() const
	{
		glBindVertexArray( 0 );
	}

	void OpenGLVertexArray::AddVertexBuffer( const Own::Share<VertexBuffer>& vertexBuffer )
	{
		glBindVertexArray( m_RenderID );
		vertexBuffer->Bind();

		const auto& BufferLayout = vertexBuffer->GetLayout();
		NR_CORE_ASSERT( BufferLayout.GetElementsSize(), "Vertex Buffer Has no layout!");

		GLuint index = 0;
		for ( const auto& element : BufferLayout )
		{
			glVertexAttribPointer( index,
								   (GLuint)element.GetCount(),
								   ShaderDataTypeToGLType(element.Type),
								   element.Normalized ? GL_TRUE : GL_FALSE,
								   (GLsizei)BufferLayout.GetStride(),
								   (void*)element.Offset );
			glEnableVertexAttribArray( index );
			++index;
		}

		m_VertexBuffers.push_back( vertexBuffer );
	}

	void OpenGLVertexArray::SetIndexBuffer( const Own::Share<IndexBuffer>& indexBuffer )
	{
		indexBuffer->Bind();
		m_IndexBuffer = indexBuffer;
	}

}  // namespace Normal