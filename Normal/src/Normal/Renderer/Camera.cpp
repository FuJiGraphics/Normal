#include "Nrpch.h"
#include "Camera.h"

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include <Normal/Core/Application.h>
#include <Normal/Core/Window.h>

namespace Normal {

	Camera::Camera( float left, float right, float bottom, float top )
		: m_Proj( glm::ortho( left, right, bottom, top, -1.0f, 1.0f ) )
		, m_Pos( 0.0f, 0.0f, 0.0f )
	{
		RecalculateViewProj();
	}

	void Camera::AddPosition( const glm::vec3& pos )
	{
		m_Pos += pos;
		RecalculateViewProj();
	}

	void Camera::AddRotation( const float& pitch, const float& yaw, const float& roll )
	{
		// TODO : 회전 구현
	}

	void Camera::RecalculateViewProj()
	{
		this->SetView();

		// Create a VP Matrix
		m_ViewProj = m_Proj * m_View;
	}

	void Camera::SetView()
	{
		glm::mat4 translate = glm::translate( glm::mat4( 1.0f ), m_Pos );

		m_View = glm::inverse( translate );
	}

} // namespace Normal