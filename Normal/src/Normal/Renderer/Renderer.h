#pragma once

#include <Normal/Core/Core.h>
#include "RenderCommand.h"

namespace Normal {

	class NORMAL_API Renderer 
	{
	protected:
		explicit Renderer() = default;
	public:
		~Renderer() = default;

	public:
		static void BeginScene();
		static void EndScene();

		static void Submit( const std::shared_ptr<VertexArray>& vertexArray );

	public:
		inline static RendererAPI::API GetGraphicAPI() { return RendererAPI::GetCurrentAPI(); }
	};


} // namespace Normal