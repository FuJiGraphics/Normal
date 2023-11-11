#pragma once

#include <Normal/Core/Core.h>
#include <Normal/Renderer/RendererAPI.h>

namespace Normal {

	class NORMAL_API OpenGLRendererAPI : public RendererAPI
	{
	public:
		virtual void SetClearColor( const glm::vec4& clearColor ) override;
		virtual void SetBlend( bool enable ) override;
		virtual void SetViewport( NRint x, NRint y, NRuint width, NRuint height ) override;
		virtual void Clear() override;

		virtual void DrawIndexed( const Own::Share<VertexArray>& vertexArray ) override;

	private:
		glm::vec4 m_ClearColor;

		NR_SET_NAME( "OpenGLRendererAPI" );
	};

} // namespace Normal