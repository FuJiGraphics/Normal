#include "Nrpch.h"
#include "OpenGLRendererAPI.h"

#include <glad/glad.h>
#include <Normal/Renderer/Buffer.h>

namespace Normal {

	void OpenGLRendererAPI::SetClearColor( const glm::vec4& clearColor )
	{
		m_ClearColor = clearColor;
		glClearColor( static_cast<GLfloat>( clearColor.r ),
					  static_cast<GLfloat>( clearColor.g ),
					  static_cast<GLfloat>( clearColor.b ),
					  static_cast<GLfloat>( clearColor.a ) );
	}

	void OpenGLRendererAPI::SetBlend( bool enable )
	{
		if ( enable == true )
		{
			glEnable( GL_BLEND );
			glBlendFunc( GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA );
		}
		else
			glDisable( GL_BLEND );
	}

	void OpenGLRendererAPI::SetViewport( NRint x, NRint y, NRuint width, NRuint height )
	{
		glViewport( static_cast<GLint>( x ), static_cast<GLint>( y ),
					static_cast<GLsizei>( width ), static_cast<GLsizei>( height ) );
	}

	void OpenGLRendererAPI::Clear()
	{
		glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
	}

	void OpenGLRendererAPI::DrawIndexed( const Own::Share<VertexArray>& vertexArray )
	{
		const auto& indexBuffer = vertexArray->GetIndexBuffer();
		glDrawElements( GL_TRIANGLES, indexBuffer->GetIndexCount(), GL_UNSIGNED_INT, 0);
	}

}