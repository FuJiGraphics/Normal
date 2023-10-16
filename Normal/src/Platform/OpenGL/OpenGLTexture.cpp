#include <Nrpch.h>
#include <stb_image.h>
#include <glad/glad.h>
#include "OpenGLTexture.h"

// impl ref : https://heinleinsgame.tistory.com/9

namespace Normal {

	OpenGLTexture2D::OpenGLTexture2D( const std::string& path )
		: m_RenderID( 0 ), m_Width( 0 ), m_Height( 0 )
	{
		// to reverse image
		stbi_set_flip_vertically_on_load( true );

		int	width, height, channels;

		stbi_uc* data = stbi_load( path.c_str(), &width, &height, &channels, 0 );
		NR_CORE_ASSERT( data, "Failed to load image!" );

		GLenum storFormat, subFormat;
		if ( channels == 4 )
		{
			storFormat = GL_RGBA16;
			subFormat = GL_RGBA;
		}
		else if ( channels == 3 )
		{
			storFormat = GL_RGB16;
			subFormat = GL_RGB;
		}
		else
			NR_CORE_ASSERT( false, "Did not surpported a image format!" );

		m_Width = static_cast<NRuint>( width );
		m_Height = static_cast<NRuint>( height );

		// �ؽ�ó Ÿ��, ������ �ؽ�ó ����, ��� Render ID
		glCreateTextures( GL_TEXTURE_2D, 1, &m_RenderID );
		glTextureStorage2D( m_RenderID, 1, storFormat, width, height );
		glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR );
		glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR );
		// glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE );
		// glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE );
		// https://registry.khronos.org/OpenGL-Refpages/gl4/html/glTexSubImage2D.xhtml
		glTextureSubImage2D( m_RenderID, 0, 0, 0, width, height, subFormat, GL_UNSIGNED_BYTE, data );

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

} // namespace Normal