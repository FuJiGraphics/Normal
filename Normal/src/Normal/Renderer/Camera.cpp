#include "Nrpch.h"
#include "Camera.h"

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include <Normal/Core/Application.h>
#include <Normal/Core/Window.h>

namespace Normal {

	Camera::Camera( const glm::vec3& eye, const glm::vec3& target, const glm::vec3& up,
					float _near, float _far, float _fov = 60.0f, ProjType type = ProjType::Perspec )
		: m_EyePos( eye ) , m_Target( glm::normalize( eye - target ) ), m_Up( up )
		, m_Near( _near ) , m_Far( _far ) , m_Fov( _fov )
		, m_View( 0.0f ) , m_Proj( 0.0f ), m_ViewProj( 0.0f ), m_ProjType( type )
	{
		this->SetView( m_EyePos, m_Target, m_Up );
		switch ( m_ProjType )
		{
			case ProjType::Ortho: 
				this->SetOrthoProj( m_Near, m_Far );
				break;
			case ProjType::Perspec:
				this->SetPespecProj( m_Near, m_Far, m_Fov );
				break;
			case ProjType::None:
				NR_CORE_ASSERT( false, "Unexpected Error : ProjType is undefined.")
		}

		// Create a VP Matrix
		m_ViewProj = m_Proj * m_View;
	}

	void Camera::SetView( const glm::vec3& eye, const glm::vec3& target, const glm::vec3& up )
	{
		m_View = glm::lookAt( eye, target, up );
	}

	void Camera::SetOrthoProj( float _near, float _far )
	{
		auto& win = Application::GetInstance().GetWindow();
		m_Proj = glm::ortho( 0.0f, (float)win.GetWidth(), (float)win.GetHeight(), 0.0f, _near, _far );
		m_Near = _near;
		m_Far = _far;
		m_ProjType = ProjType::Ortho;
	}

	void Camera::SetPespecProj( float _near, float _far, float _fov = 60.0f )
	{
		auto& win = Application::GetInstance().GetWindow();
		float aspect = static_cast<float>( win.GetWidth() ) / win.GetHeight();
		m_Proj = glm::perspective( _fov, aspect, _near, _far );		
		m_Near = _near;
		m_Far = _far;
		m_Fov = _fov;
		m_ProjType = ProjType::Perspec;
	}

	

} // namespace Normal