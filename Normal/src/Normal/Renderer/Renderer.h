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
		static void BeginScene( const NrPtr<Camera>& camera );
		static void EndScene();

		static void Submit( const NrPtr<Shader>& shader,
							const NrPtr<VertexArray>& vertexArray,
							const glm::mat4& transform = glm::mat4( 1.0f ),
							const glm::vec4& vec = glm::vec4( 0.5f, 0.5f, 0.5f, 1.0f ) );

	public:
		inline static RendererAPI::API GetGraphicAPI() { return RendererAPI::GetCurrentAPI(); }

	private:
		struct SceneData { 
			NrPtr<Camera> Camera;
		};

		inline static SceneData m_SceneData{};
	};


} // namespace Normal