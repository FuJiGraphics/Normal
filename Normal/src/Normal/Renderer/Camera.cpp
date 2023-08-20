#include "Nrpch.h"
#include "Normal/Renderer/Camera.h"

#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"

namespace Normal {

	Camera::Camera( const glm::vec3& eye, 
					const glm::vec3& center, 
					const glm::vec3& up )
		: m_EyePos( eye )
		, m_Center( center )
		, m_Up( up )
		, m_View( 0.0f )
		, m_Proj( 0.0f )
	{

	}

	Camera::~Camera()
	{

	}

} // namespace Normal