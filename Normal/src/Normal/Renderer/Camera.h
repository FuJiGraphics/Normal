#pragma once

#include <Normal/Core/Core.h>

namespace Normal {

	class NORMAL_API Camera
	{
	public:
		explicit Camera( const glm::mat4& model );
		~Camera();

	public:
		inline glm::mat4& GetViewMatrix() { return m_View; }
		inline glm::mat4& GetProjMatrix() { return m_Proj; }

	private:
		glm::mat4 m_View;
		glm::mat4 m_Proj;
	};

} // namespace Normal