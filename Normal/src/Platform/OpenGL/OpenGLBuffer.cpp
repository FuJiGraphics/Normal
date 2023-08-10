#include "Nrpch.h"
#include "OpenGLBuffer.h"

#include <glad/glad.h>

namespace Normal {

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

	// OpenGL Vertex Buffer Implements
	OpenGLVertexBuffer::OpenGLVertexBuffer( float* vertices, NRuint size )
		: m_RenderID( 0 )
	{
		glCreateBuffers( 1, &m_RenderID );
		glBindBuffer( GL_ARRAY_BUFFER, m_RenderID );
		glBufferData( GL_ARRAY_BUFFER, size, vertices, GL_STATIC_DRAW );
	}

	OpenGLVertexBuffer::~OpenGLVertexBuffer()
	{
		glDeleteBuffers( 1, &m_RenderID );
	}

	void OpenGLVertexBuffer::Bind() const
	{
		glBindBuffer( GL_ARRAY_BUFFER, m_RenderID );
	}

	void OpenGLVertexBuffer::UnBind() const
	{
		glBindBuffer( GL_ARRAY_BUFFER, 0 );
	}

	void OpenGLVertexBuffer::SetLayout( BufferLayout& layout )
	{
		NRuint indices = 0;
		for ( const auto& element : layout )
		{
			glVertexAttribPointer( indices,
								   (GLuint)element.Count,
								   ShaderDataTypeToGLType( element.Type ),
								   (GLboolean)element.Normalized,
								   (GLsizei)layout.GetStride(),
								   (void*)element.Offset );
			glEnableVertexAttribArray( indices );
			++indices;
		}

	}


	// OpenGL Index Buffer Implements
	OpenGLIndexBuffer::OpenGLIndexBuffer( NRuint* indices, NRuint count )
		: m_RenderID( 0 )
		, m_IndexCount( count )
	{
		glCreateBuffers( 1, &m_RenderID );
		glBindBuffer( GL_ELEMENT_ARRAY_BUFFER, m_RenderID );
		glBufferData( GL_ELEMENT_ARRAY_BUFFER, sizeof( NRuint ) * count, indices, GL_STATIC_DRAW );
	}

	OpenGLIndexBuffer::~OpenGLIndexBuffer()
	{
		glDeleteBuffers( 1, &m_RenderID );
	}

	void OpenGLIndexBuffer::Bind() const
	{
		glBindBuffer( GL_ELEMENT_ARRAY_BUFFER, m_RenderID );
	}

	void OpenGLIndexBuffer::UnBind() const
	{
		glBindBuffer( GL_ELEMENT_ARRAY_BUFFER, 0 );
	}

}