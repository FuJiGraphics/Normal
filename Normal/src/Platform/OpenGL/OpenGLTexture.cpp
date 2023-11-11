#include <Nrpch.h>
#include <stb_image.h>
#include <Normal/Diagram/PrimitiveGeometry.h>
#include "OpenGLTexture.h"

// impl ref : https://heinleinsgame.tistory.com/9

namespace Normal {
	OpenGLTexture2D::OpenGLTexture2D( const NRint& width, const NRint& height )
		: m_RenderID( 0 ), m_Width( width ), m_Height( height )
		, m_StorFormat( GL_RGBA16 ), m_SubFormat( GL_RGBA )
	{
		GLenum storFormat, subFormat;

		// 텍스처 타입, 생성할 텍스처 개수, 대상 Render ID
		glCreateTextures( GL_TEXTURE_2D, 1, &m_RenderID );
		glTextureStorage2D( m_RenderID, 1, m_StorFormat, width, height );
		glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR );
		glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR );
	}

	OpenGLTexture2D::OpenGLTexture2D( const std::string& path )
		: m_RenderID( 0 ), m_Width( 0 ), m_Height( 0 )
		, m_StorFormat( GL_RGBA16 ), m_SubFormat( GL_RGBA )
	{
		// to reverse image
		stbi_set_flip_vertically_on_load( true );

		NRint channels;
		stbi_uc* data = stbi_load( path.c_str(), &m_Width, &m_Height, &channels, 0 );
		NR_CORE_ASSERT( data, "Failed to load image!" );

		if ( channels == 3 )
		{
			m_StorFormat = GL_RGB16;
			m_SubFormat = GL_RGB;
		}
		else if ( channels != 4 )
			NR_CORE_ASSERT( false, "Did not surpported a image format!" );

		// 텍스처 타입, 생성할 텍스처 개수, 대상 Render ID
		glCreateTextures( GL_TEXTURE_2D, 1, &m_RenderID );
		glTextureStorage2D( m_RenderID, 1, m_StorFormat, m_Width, m_Height );
		glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR );
		glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR );
		// glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE );
		// glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE );
		// https://registry.khronos.org/OpenGL-Refpages/gl4/html/glTexSubImage2D.xhtml
		glTextureSubImage2D( m_RenderID, 0, 0, 0, m_Width, m_Height, m_SubFormat, GL_UNSIGNED_BYTE, data );

		Quad2D quad( 0, 0, m_Width, m_Height );
		m_VertexArrayObject = quad.GetVertexArray();

		stbi_image_free( data );
	}

	OpenGLTexture2D::~OpenGLTexture2D()
	{
		glDeleteTextures( 1, &m_RenderID );
	}

	void OpenGLTexture2D::Bind()
	{
		glBindTextureUnit( 0, m_RenderID );
	}

	void OpenGLTexture2D::SetData( void* data, NRuint size )
	{
		glTextureSubImage2D( m_RenderID, 0, 0, 0, m_Width, m_Height, m_SubFormat, GL_UNSIGNED_BYTE, data );
	}

} // namespace Normal