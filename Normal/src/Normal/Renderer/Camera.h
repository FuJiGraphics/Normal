#pragma once

#include <Normal/Core/Core.h>

namespace Normal {

	class NORMAL_API Camera
	{
	public:
		explicit Camera( const glm::vec3& eye, 
						 const glm::vec3& center, 
						 const glm::vec3& up );
		~Camera();

	public:
		inline glm::mat4& GetViewMat() { return m_View; }
		inline glm::mat4& GetProjMat() { return m_Proj; }

	private:
		glm::vec3 m_EyePos;
		glm::vec3 m_Center;
		glm::vec3 m_Up;

		glm::mat4 m_View;
		glm::mat4 m_Proj;
	};

} // namespace Normal