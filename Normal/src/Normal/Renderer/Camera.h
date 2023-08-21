#pragma once

#include <Normal/Core/Core.h>

namespace Normal {

	class NORMAL_API Camera
	{
	public:
		enum class ProjType { None = 0, Ortho, Perspec };

	public:
		explicit Camera( const glm::vec3& eye, const glm::vec3& target, const glm::vec3& up,
						 float _near, float _far, float _fov = 60.0f, ProjType type = ProjType::Perspec );
		~Camera() = default ;

	public:
		inline glm::mat4& GetVPMatrix() { m_ViewProj; }

	private:
		void SetView( const glm::vec3& eye, const glm::vec3& target, const glm::vec3& up );
		void SetOrthoProj( float _near, float _far );
		void SetPespecProj( float _near, float _far, float _fov = 60.0f );

	private:
		glm::vec3 m_EyePos;
		glm::vec3 m_Target;
		glm::vec3 m_Up;

		float m_Near;
		float m_Far;
		float m_Fov;

		glm::mat4 m_View;
		glm::mat4 m_Proj;
		glm::mat4 m_ViewProj;
		ProjType m_ProjType;
	};

} // namespace Normal