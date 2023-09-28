#include "Nrpch.h"
#include "Camera.h"

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/quaternion.hpp>

#include <Normal/Core/Application.h>
#include <Normal/Core/Window.h>


// TODO : 월드축, 로컬축 나누기 구현
// TODO : AddPosition에서도 월드축과 로컬축의 로직을 나눠야함 
// TODO : 설계를 다시해야함


namespace Normal {

	OrthogonalCamera::OrthogonalCamera( float left, float right, float bottom, float top )
		: m_Proj( glm::ortho( left, right, bottom, top, -1.0f, 1.0f ) )
		, m_Pos( 0.0f, 0.0f, 0.0f )
	{
		SetCalculateViewProj();
	}

	void OrthogonalCamera::SetPosition( const glm::vec3& pos )
	{
		m_Pos = pos;
		SetCalculateViewProj();
	}

	void OrthogonalCamera::SetRotation( const float& angle, const EularAngle& type )
	{
		switch ( type )
		{
			case EularAngle::Pitch: m_Pitch = glm::radians( angle ); break;
			case EularAngle::Yaw:   m_Yaw   = glm::radians( angle ); break;
			case EularAngle::Roll:  m_Roll  = glm::radians( angle ); break;
			default: NR_CORE_ASSERT( false, "Unexpected Error : Failed to binding EularAngle" );
		}

		SetCalculateViewProj();
	}

	void OrthogonalCamera::SetCalculateViewProj()
	{
		const glm::mat4& translation = glm::translate( glm::mat4( 1.0f ), m_Pos );

		// --- Roll-Pitch-Yaw 순서
		const glm::mat4& Rotation = 
			glm::rotate( glm::mat4( 1.0f ), m_Yaw,   glm::vec3( 0.0f, 1.0f, 0.0f ) ) *
			glm::rotate( glm::mat4( 1.0f ), m_Pitch, glm::vec3( 1.0f, 0.0f, 0.0f ) ) *
			glm::rotate( glm::mat4( 1.0f ), m_Roll,  glm::vec3( 0.0f, 0.0f, 1.0f ) );

		const glm::mat4& transform = translation * Rotation;

		m_View = glm::inverse( transform );

		// Create a VP Matrix
		m_ViewProj = m_Proj * m_View;
	}
} // namespace Normal