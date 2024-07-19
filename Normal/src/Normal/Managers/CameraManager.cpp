#include <Nrpch.h>
#include "CameraManager.h"

namespace Normal {

	using namespace Own;

	Share<CameraManager>				CameraManager::s_spInstace = nullptr;
	CameraSet*							CameraManager::s_pCurrentCamera = nullptr;
	Share<CameraManager::CameraPool>	CameraManager::s_spCameraPool = nullptr;
	Share<MouseInput>					CameraManager::s_spMouseInput = nullptr;
	WindowInput							CameraManager::s_WindowInput;

	// statics
	CameraManager& CameraManager::GetInstance()
	{
		if (s_spInstace == nullptr)
		{
			s_spInstace = CreateShare<CameraManager>();
		}
		return (*s_spInstace);
	}

	// non-statics
	bool CameraManager::CreateCamera( const std::string& label, float w, float h, bool rotation )
	{
		// 이미 같은 이름의 카메라가 메모리 풀에 존재할 경우
		// false를 반환하고 종료
		if (s_spCameraPool->empty() || s_spCameraPool->find(label) == s_spCameraPool->end())
		{
			CameraSpec spec;		
			spec.Width = w;
			spec.Height = h;
			spec.AspectRatio = static_cast<float>(w / h);
			spec.Angle = 0.0f;
			spec.Zoom = 1.0f;
			spec.Position = glm::vec3{ 0.0f, 0.0f, 0.0f };
			spec.ActivateRotation = rotation;

			auto camera = CreateShare<OrthogonalCamera>( 
				-spec.AspectRatio * spec.Zoom, 
				 spec.AspectRatio * spec.Zoom, 
				-spec.Zoom, spec.Zoom );
			
			CameraSet set;
			set.Spec = spec;
			set.spCamera = camera;
			s_spCameraPool->insert( { label, set } );

			// 첫 초기화시에만 콜백, 첫번 째 카메라로 갱신
			static NRuchar bFirstInit = 't';
			if (bFirstInit == 't')
			{
				bFirstInit = 'f';
				s_spMouseInput->AttachCallback( BIND_EVENT_FUNC( CameraManager::OnMouseScrolled ), MouseInput::Type::IsScrolled );
				s_pCurrentCamera = &(*s_spCameraPool)[label];
			}
			return (true);
		}
	}

	void CameraManager::ActivateRotation( bool enabled )
	{
		if (s_pCurrentCamera != nullptr)
		{
			s_pCurrentCamera->Spec.ActivateRotation = enabled;
		}
	}

	void CameraManager::SetPosition( const glm::vec2& target_pos )
	{
		// 비율에 따른 이동량 고정
		static float weight_pos = s_pCurrentCamera->Spec.Height / s_pCurrentCamera->Spec.Width;
		auto& ref_camera = s_pCurrentCamera->spCamera;
		auto& ref_pos = s_pCurrentCamera->Spec.Position;
		ref_pos.x = target_pos.x * weight_pos;
		ref_pos.y = target_pos.y;
		ref_camera->SetPosition( ref_pos );
	}

	bool CameraManager::SetDisplayCamera( const std::string& label )
	{
		auto find = s_spCameraPool->find( label );
		if (find != s_spCameraPool->end())
		{
			s_pCurrentCamera = &find->second;
		}
		else
		{
			return (false);
		}
	}

	Own::Share<Camera>& CameraManager::GetDisplayCamera() const
	{
		return s_pCurrentCamera->spCamera;
	}

	CameraManager::CameraManager()
	{
		if (s_spCameraPool == nullptr)
		{
			s_spCameraPool = CreateShare<CameraPool>();
		}
		if (s_spMouseInput == nullptr)
		{
			s_spMouseInput = CreateShare<MouseInput>();
		}
	}

	void CameraManager::OnEvent( Event& event )
	{
		s_spMouseInput->OnEvent( event );
	}

	void CameraManager::OnUpdate( const float& dt )
	{
		// InputKey Polling
		this->OnMovement( dt );
		this->OnRotation( dt );
		this->OnScale( dt );
	}

	bool CameraManager::OnMouseScrolled( MouseInputData event )
	{
		auto& ref_camera = s_pCurrentCamera->spCamera;
		auto& ref_zoom = s_pCurrentCamera->Spec.Zoom;
		if (ref_zoom - event.yOffset > 0)
			ref_zoom -= event.yOffset;
		ref_camera->SetScale( ref_zoom );
		return true;
	}

	void CameraManager::OnMovement( const float& dt )
	{
		auto& ref_target_camera = s_pCurrentCamera->spCamera;
		auto& ref_target_pos = s_pCurrentCamera->Spec.Position;
		float target_move_speed = s_pCurrentCamera->Spec.MoveSpeed * dt;

		if (KeyInput::IsKeyPreesed( NR_KEY_D ))
		{
			ref_target_pos += (glm::vec3( 1.0f, 0.0f, 0.0f ) * target_move_speed);
			ref_target_camera->SetPosition( ref_target_pos );
		}
		if (KeyInput::IsKeyPreesed( NR_KEY_A ))
		{
			ref_target_pos += (glm::vec3( -1.0f, 0.0f, 0.0f ) * target_move_speed);
			ref_target_camera->SetPosition( ref_target_pos );
		}
		if (KeyInput::IsKeyPreesed( NR_KEY_W ))
		{
			ref_target_pos += (glm::vec3( 0.0f, 1.0f, 0.0f ) * target_move_speed);
			ref_target_camera->SetPosition( ref_target_pos );
		}
		if (KeyInput::IsKeyPreesed( NR_KEY_S ))
		{
			ref_target_pos += (glm::vec3( 0.0f, -1.0f, 0.0f ) * target_move_speed);
			ref_target_camera->SetPosition( ref_target_pos );
		}
	}

	void CameraManager::OnRotation( const float& dt )
	{
		auto& ref_target_camera = s_pCurrentCamera->spCamera;
		auto& ref_target_angle = s_pCurrentCamera->Spec.Angle;
		bool target_act_rot = s_pCurrentCamera->Spec.ActivateRotation;
		float target_rot_speed = s_pCurrentCamera->Spec.RotSpeed * dt;
		if (target_act_rot == true)
		{
			if (KeyInput::IsKeyPreesed( NR_KEY_E ))
			{
				ref_target_angle += target_rot_speed;
				ref_target_camera->SetRotation( ref_target_angle, Normal::EularAngle::Roll );
			}
			if (KeyInput::IsKeyPreesed( NR_KEY_Q ))
			{
				ref_target_angle -= target_rot_speed;
				ref_target_camera->SetRotation( ref_target_angle, Normal::EularAngle::Roll );
			}
		}
	}

	void CameraManager::OnScale( const float& dt )
	{
		auto& ref_target_camera = s_pCurrentCamera->spCamera;
		auto& ref_target_zoom = s_pCurrentCamera->Spec.Zoom;
		float target_zoom_speed = s_pCurrentCamera->Spec.ZoomSpeed * dt;
		if (KeyInput::IsKeyPreesed( NR_KEY_UP ))
		{
			if (ref_target_zoom > 0)
				ref_target_zoom -= target_zoom_speed;
			ref_target_camera->SetScale( ref_target_zoom );
		}
		if (KeyInput::IsKeyPreesed( NR_KEY_DOWN ))
		{
			ref_target_zoom += target_zoom_speed;
			ref_target_camera->SetScale( ref_target_zoom );
		}
	}

} // namespace Normal