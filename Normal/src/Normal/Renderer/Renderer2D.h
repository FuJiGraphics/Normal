#pragma once
#include <Normal/Core/Core.h>
#include "Camera.h"

namespace Normal {

#pragma region Forward
	class NORMAL_API CameraManager;
#pragma endregion

	class Renderer2D
	{
	public:
		static void Initialze();
		static void Finalize();

		static void BeginScene( const CameraManager& cameraManager );
		static void BeginScene( const Own::Share<CameraManager>& cameraManager );
		static void EndScene();

		static void DrawQuad( const glm::vec3& pos, const glm::vec4& color );
	};



} // namespace Normal