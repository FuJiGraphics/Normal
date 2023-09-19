#pragma once

#include <Normal/Core/Core.h>
#include <Normal/Renderer/Texture.h>


namespace Normal {

	class OpenGLTexture2D : public Texture2D
	{
	public:
		explicit OpenGLTexture2D( const std::string& path );
		virtual ~OpenGLTexture2D();

		virtual void Bind() override;

		inline virtual NRuint GetWidth() const override { return m_Width; }
		inline virtual NRuint GetHeight() const override { return m_Height; }
		
	private:
		NRuint	m_RenderID;
		NRuint	m_Width;
		NRuint	m_Height;
	};


} // namespace Normal