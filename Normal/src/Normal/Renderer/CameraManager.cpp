#include <Nrpch.h>
#include "CameraManager.h"

namespace Normal {

	CameraManager::CameraManager( const float aspectRatio, bool rotation )
		: m_Angle( rotation ), m_Zoom( 1.0f ), m_CameraPos( 0.0f, 0.0f, 0.0f ), m_OnRotation( rotation )
		, m_Camera( new OrthogonalCamera( -aspectRatio * m_Zoom, aspectRatio * m_Zoom, -m_Zoom, m_Zoom  ) )
	{
		m_MouseInput.AttachCallback( BIND_EVENT_FUNC( CameraManager::OnMouseScrolled ), MouseInput::Type::IsScrolled );
	}

	void CameraManager::OnEvent( Event& event )
	{
		m_MouseInput.OnEvent( event );
	}

	void CameraManager::OnUpdate( const float& dt )
	{
		// InputKey Polling
		if ( KeyInput::IsKeyPreesed( NR_KEY_D ) )
		{
			m_CameraPos += ( glm::vec3( 1.0f, 0.0f, 0.0f ) * m_MoveSpeed * dt );
			m_Camera->SetPosition( m_CameraPos );
		}
		if ( KeyInput::IsKeyPreesed( NR_KEY_A ) )
		{
			m_CameraPos += ( glm::vec3( -1.0f, 0.0f, 0.0f ) * m_MoveSpeed * dt );
			m_Camera->SetPosition( m_CameraPos );
		}
		if ( KeyInput::IsKeyPreesed( NR_KEY_W ) )
		{
			m_CameraPos += ( glm::vec3( 0.0f, 1.0f, 0.0f ) * m_MoveSpeed * dt );
			m_Camera->SetPosition( m_CameraPos );
		}
		if ( KeyInput::IsKeyPreesed( NR_KEY_S ) )
		{
			m_CameraPos += ( glm::vec3( 0.0f, -1.0f, 0.0f ) * m_MoveSpeed * dt );
			m_Camera->SetPosition( m_CameraPos );
		}

		if ( m_OnRotation == true )
		{
			if ( KeyInput::IsKeyPreesed( NR_KEY_E ) )
			{
				m_Angle += m_RotSpeed * dt;
				m_Camera->SetRotation( m_Angle, Normal::EularAngle::Roll );
			}
			if ( KeyInput::IsKeyPreesed( NR_KEY_Q ) )
			{
				m_Angle -= m_RotSpeed * dt;
				m_Camera->SetRotation( m_Angle, Normal::EularAngle::Roll );
			}
		}

		if ( KeyInput::IsKeyPreesed( NR_KEY_UP ) )
		{
			if ( m_Zoom > 0 )
				m_Zoom -= m_ZoomSpeed * dt;
			m_Camera->SetScale( m_Zoom );
		}
		if ( KeyInput::IsKeyPreesed( NR_KEY_DOWN ) )
		{
			m_Zoom += m_ZoomSpeed * dt;
			m_Camera->SetScale( m_Zoom );
		}
	}

	bool CameraManager::OnMouseScrolled( MouseInputData event )
	{
		m_Zoom -= event.yOffset;
		m_Camera->SetScale( m_Zoom );
		return true;
	}

} // namespace Normal