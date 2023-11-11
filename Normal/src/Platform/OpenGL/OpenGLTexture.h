#pragma once

#include <Normal/Core/Core.h>
#include <Normal/Renderer/Texture.h>
#include <glad/glad.h>

namespace Normal {

	class OpenGLTexture2D : public Texture2D
	{
	public:
		explicit OpenGLTexture2D( const NRint& width, const NRint& height );
		explicit OpenGLTexture2D( const std::string& path );
		virtual ~OpenGLTexture2D();

		virtual void Bind() override;
		virtual void SetData( void* data, NRuint size ) override;

		inline virtual Own::Share<VertexArray>& GetVAO() override { return m_VertexArrayObject; }
		inline virtual NRuint GetWidth() const override { return m_Width; }
		inline virtual NRuint GetHeight() const override { return m_Height; }
		
	private:
		NRuint						m_RenderID;
		NRint						m_Width;
		NRint						m_Height;
		GLenum						m_StorFormat, m_SubFormat;
		Own::Share<VertexArray>		m_VertexArrayObject;
	};


} // namespace Normal