#pragma once

#include <Normal/Core/Core.h>

#include "RenderCommand.h"
#include "Shader.h"
#include "Camera.h"

namespace Normal {

	class NORMAL_API Renderer 
	{
	protected:
		explicit Renderer() = default;
	public:
		~Renderer() = default;

	public:
		static void BeginScene( const std::shared_ptr<Camera>& camera );
		static void EndScene();

		static void Submit( const std::shared_ptr<Shader>& shader, 
							const std::shared_ptr<VertexArray>& vertexArray );

	public:
		inline static RendererAPI::API GetGraphicAPI() { return RendererAPI::GetCurrentAPI(); }

	private:
		struct SceneData { 
			std::shared_ptr<Camera> Camera;
		};

		inline static SceneData m_SceneData{};
	};


} // namespace Normal