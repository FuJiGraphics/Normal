#pragma once

#include <Normal/Core/Core.h>
#include <Normal/Core/Level.h>
#include <Normal/Renderer/Camera.h>

#include "Rectangle\Rectangle.h"

namespace Normal {
	class NORMAL_API World : public Level
	{
	public:
		World();
		virtual ~World() = default;

		virtual void OnEvent( Event& event ) override;
		virtual void OnUpdate( float deltaTime ) override;

		virtual void OnKeyPressed( KeyInputData event );

	private:
		Rectangle m_Rec;


		std::shared_ptr<Camera> m_Camera;
	};

}

