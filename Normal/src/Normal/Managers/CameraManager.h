#pragma once
#include <Normal/Core/Core.h>
#include <Normal/InputManager/KeyInput.h>
#include <Normal/InputManager/MouseInput.h>
#include <Normal/InputManager/WindowInput.h>
#include "../Renderer/Camera.h"

namespace Normal {

	struct NORMAL_API CameraSpec
	{
		float		AspectRatio	= 0.0f;
		float		Width		= 0.0f;
		float		Height		= 0.0f;
		float		Angle		= 0.0f;
		float		Zoom		= 1.0f;
		float		MoveSpeed	= 3.5f;
		float 		RotSpeed	= 3.5f;
		float 		ZoomSpeed	= 1.5f;
		glm::vec3	Position	= { 0.0f, 0.0f, 0.0f };
		bool		ActivateRotation = false;
	};

	struct NORMAL_API CameraSet
	{
		CameraSpec			Spec;
		Own::Share<Camera>	spCamera;
	};

	class NORMAL_API CameraManager
	{
		using CameraPool = std::unordered_map<std::string, CameraSet>;

	//// Member Functions
	public:	
		// Constructor
		CameraManager();
		CameraManager( const CameraManager& ) = delete;

		// Event Logic
		void								OnEvent( Event& event );
		void								OnUpdate( const float& dt );

		// Interfaces
		static CameraManager&				GetInstance();
		bool								CreateCamera( const std::string& label, float w, float h, bool rotation = false );
		void								ActivateRotation( bool enabled );
		void								SetPosition( const glm::vec2& target_pos );
		bool								SetDisplayCamera( const std::string& label );
		Own::Share<Camera>&					GetDisplayCamera() const;

	protected:
		// Event Logic
		bool								OnMouseScrolled( MouseInputData event );
		void								OnMovement( const float& dt );
		void								OnRotation( const float& dt );
		void								OnScale( const float& dt );

	//// Member Variables
	private:
		static Own::Share<CameraManager>	s_spInstace;
		static Own::Share<CameraPool>		s_spCameraPool;
		static CameraSet*					s_pCurrentCamera;
		static WindowInput					s_WindowInput;
		static Own::Share<MouseInput>		s_spMouseInput;
	};

	
} // namespace Normal