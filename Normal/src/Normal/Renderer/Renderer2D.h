#pragma once
#include <Normal/Core/Core.h>
#include "Camera.h"

namespace Normal {

#pragma region Forward
	class NORMAL_API CameraManager;
	class NORMAL_API ShaderManager;
	class NORMAL_API Texture2D;
#pragma endregion

	struct Render2DStorage
	{
		ShaderManager				ShaderManager;
		Own::Share<VertexArray>		ColorVAO;
		Own::Share<VertexArray>		TextureVAO;
	};

	class Renderer2D : public Renderer
	{
	public:
		static void Initialze();
		static void Finalize();

		static void BeginScene( const CameraManager& cameraManager );
		static void BeginScene( const Own::Share<CameraManager>& cameraManager );
		static void EndScene();

		static void DrawQuad( const glm::vec2& pos, const glm::vec2& scale, const glm::vec4& color );
		static void DrawQuad( const glm::vec3& pos, const glm::vec2& scale, const glm::vec4& color );
		static void DrawQuad( const glm::vec2& pos, const glm::vec2& scale, const Own::Share<Texture2D>& texture );
		static void DrawQuad( const glm::vec3& pos, const glm::vec2& scale, const Own::Share<Texture2D>& texture );
	};



} // namespace Normal