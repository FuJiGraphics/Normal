#include "Nrpch.h"
#include "Normal/Renderer/Camera.h"

#include "glm/glm.hpp"

namespace Normal {

	Camera::Camera()
		: m_View( 0.0f )
		, m_Proj( 0.0f )
	{

	}

	Camera::~Camera()
	{

	}

} // namespace Normal