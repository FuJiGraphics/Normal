#include "Nrpch.h"
#include "Camera.h"

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include <Normal/Core/Application.h>
#include <Normal/Core/Window.h>

namespace Normal {

	OrthogonalCamera::OrthogonalCamera( float left, float right, float bottom, float top )
		: m_Proj( glm::ortho( left, right, bottom, top, -1.0f, 1.0f ) )
		, m_Pos( 0.0f, 0.0f, 0.0f )
	{
		RecalculateViewProj();
	}

	void OrthogonalCamera::AddPosition( const glm::vec3& move )
	{
		m_Pos += move;
		RecalculateViewProj();
	}

	void OrthogonalCamera::SetPosition( const glm::vec3& pos )
	{
		m_Pos = pos;
		RecalculateViewProj();
	}

	void OrthogonalCamera::AddRotation( const float& angle, const EularAngle type )
	{
		switch ( type )
		{
			case EularAngle::Pitch: m_Pitch += glm::radians( angle ); break;
			case EularAngle::Yaw:   m_Yaw   += glm::radians( angle ); break;
			case EularAngle::Roll:  m_Roll  += glm::radians( angle ); break;
			Default: NR_CORE_ASSERT( false, "Unexpected Error : Failed to binding EularAngle" );
		}

		RecalculateViewProj();
	}

	void OrthogonalCamera::SetRotation( const float& angle, const EularAngle type )
	{
		switch ( type )
		{
			case EularAngle::Pitch: m_Pitch = glm::radians( angle ); break;
			case EularAngle::Yaw:   m_Yaw   = glm::radians( angle ); break;
			case EularAngle::Roll:  m_Roll  = glm::radians( angle ); break;
			Default: NR_CORE_ASSERT( false, "Unexpected Error : Failed to binding EularAngle" );
		}

		RecalculateViewProj();
	}

	void OrthogonalCamera::RecalculateViewProj()
	{
		this->SetView();

		// Create a VP Matrix
		m_ViewProj = m_Proj * m_View;
	}

	void OrthogonalCamera::SetView()
	{
		const glm::mat4& translation = glm::translate( glm::mat4( 1.0f ), m_Pos );

		// Roll-Pitch-Yaw ¼ø¼­
		const glm::mat4& rotation = glm::rotate( glm::mat4( 1.0f ), m_Yaw,   glm::vec3( 0.0f, 1.0f, 0.0f ) ) *
									glm::rotate( glm::mat4( 1.0f ), m_Pitch, glm::vec3( 1.0f, 0.0f, 0.0f ) ) *
								    glm::rotate( glm::mat4( 1.0f ), m_Roll,  glm::vec3( 0.0f, 0.0f, 1.0f ) ) ;

		const glm::mat4& transform = rotation * translation;

		m_View = glm::inverse( transform );
	}

} // namespace Normal