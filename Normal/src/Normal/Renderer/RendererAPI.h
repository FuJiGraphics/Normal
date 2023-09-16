#pragma once

#include <Normal/Core/Core.h>
#include <glm/glm.hpp>
#include <memory>

#include "VertexArray.h"

namespace Normal {

	/*
	RendererAPI는 OpenGL과 DirectX 버전 둘 다 갖게 될 것이고 
	RenderAPI와 다르게 Renderer들을 위한 API이다. 명칭상 차이점을 분명히 인식하자.
	*/
	class NORMAL_API RendererAPI
	{
	public:
		enum class API
		{
			None = 0,
			OpenGL, Vulkan,
			DirectX11, DirectX12,
		};

	public:
		virtual void SetClearColor( const glm::vec4& clearColor ) = 0;
		virtual void Clear() = 0;

		// Index Buffer를 이용해서 Scene에 Draw 명령을 수행하기 때문에 DrawIndexed라는 이름이 된다.
		virtual void DrawIndexed( const NrPtr<VertexArray>& vertexArray ) = 0;

	public:
		inline static API GetCurrentAPI() { return m_GraphicAPI; }

	private:
		static API m_GraphicAPI;
	};


} // namespace Normal