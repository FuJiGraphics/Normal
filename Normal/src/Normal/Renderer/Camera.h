#pragma once

#include <Normal/Core/Core.h>
#include <glm/glm.hpp>

namespace Normal {

	class NORMAL_API Camera
	{
	public:
		explicit Camera( float left, float right, float bottom, float top );
		~Camera() = default ;

	public:
		inline glm::mat4& GetVPMatrix() { return m_ViewProj; }

		void AddPosition( const glm::vec3& pos );
		void AddRotation( const float& pitch, const float& yaw, const float& roll );

	private:
		void RecalculateViewProj();
		void SetView();

	private:
		glm::vec3 m_Pos;

		glm::mat4 m_View;
		glm::mat4 m_Proj;
		glm::mat4 m_ViewProj;
	};

} // namespace Normal