#pragma once

#include <Normal/Core/Core.h>

#include "RenderCommand.h"
#include "Shader.h"
#include "Camera.h"
#include "Texture.h"

namespace Normal {

	class NORMAL_API Renderer 
	{
	public:
		static void Initialize();
		static void Finalize();
		static void BeginScene( const Own::Share<Camera>& camera );
		static void EndScene();

		static void Submit( const Own::Share<Shader>& shader,
							const Own::Share<VertexArray>& vertexArray );


	public:
		inline static RendererAPI::API GetGraphicAPI() { return RendererAPI::GetCurrentAPI(); }

	private:
		struct SceneData { 
			 Own::Share<Camera> Camera;
		};

		inline static SceneData m_SceneData{};
	};


} // namespace Normal