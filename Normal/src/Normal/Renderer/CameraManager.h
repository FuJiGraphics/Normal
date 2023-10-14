#pragma once
#include <Normal/Core/Core.h>
#include <Normal/InputManager/KeyInput.h>
#include <Normal/InputManager/MouseInput.h>
#include <Normal/InputManager/WindowInput.h>
#include "Camera.h"

namespace Normal {

	class NORMAL_API CameraManager
	{
	public:
		CameraManager( const float aspectRatio, bool rotation = false );
		~CameraManager() = default;

		void OnEvent( Event& event );
		void OnUpdate( const float& dt );
		
		inline void ActivateRotation( bool enable ) { m_OnRotation = enable; }

		inline Own::Share<Normal::Camera>& GetCamera() { return m_Camera; }
		inline const Own::Share<Normal::Camera>& GetCamera() const { return m_Camera; }

	protected:
		bool OnMouseScrolled( MouseInputData event );

	private:
		float	m_Angle;
		float	m_Zoom;
		bool	m_OnRotation;
		glm::vec3 m_CameraPos;

		float	m_MoveSpeed = 1.0f;
		float	m_RotSpeed = 1.0f;
		float	m_ZoomSpeed = 1.0f;

		Own::Share<Normal::Camera> m_Camera;

	private:
		WindowInput m_WindowInput;
		MouseInput m_MouseInput;
	};

	
} // namespace Normal