#pragma once

#include <Normal/Core/Core.h>
#include <Normal/Renderer/RendererAPI.h>

namespace Normal {

	class NORMAL_API OpenGLRendererAPI : public RendererAPI
	{
	public:
		virtual void SetClearColor( const glm::vec4& clearColor ) override;
		virtual void Clear() override;

		virtual void DrawIndexed( const NrPtr<VertexArray>& vertexArray ) override;

	private:
		glm::vec4 m_ClearColor;

		NR_SET_NAME( "OpenGLRendererAPI" );
	};

} // namespace Normal