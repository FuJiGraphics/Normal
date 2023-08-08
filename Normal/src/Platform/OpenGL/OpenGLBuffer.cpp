#include "Nrpch.h"
#include "OpenGLBuffer.h"

#include <glad/glad.h>

namespace Normal {
	
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