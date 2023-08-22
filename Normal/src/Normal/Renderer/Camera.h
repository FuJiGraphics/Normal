#pragma once

#include <Normal/Core/Core.h>
#include <glm/glm.hpp>

namespace Normal {

	enum class EularAngle { 
		None = 0,
		Pitch, Yaw, Roll 
	};

	// Camera Interface
	class NORMAL_API Camera
	{
	public:
		explicit Camera() = default;
		~Camera() = default;

	public:
		inline virtual glm::mat4& GetVPMatrix() = 0;

		virtual void AddPosition( const glm::vec3& dir ) = 0;
		virtual void SetPosition( const glm::vec3& pos ) = 0;
		virtual void AddRotation( const float& angle, const EularAngle type ) = 0;
	};

	// Orthogonal Projection Camera
	class NORMAL_API OrthogonalCamera : public Camera
	{
	public:
		explicit OrthogonalCamera( float left, float right, float bottom, float top );
		~OrthogonalCamera() = default ;

	public:
		inline virtual glm::mat4& GetVPMatrix() override { return m_ViewProj; }

		virtual void AddPosition( const glm::vec3& dir ) override;
		virtual void AddRotation( const float& angle, const EularAngle type ) override;

	private:
		void RecalculateViewProj();
		void SetView();

	private:
		glm::vec3 m_Pos;

		float m_Pitch = 0.0f;
		float m_Yaw   = 0.0f;
		float m_Roll  = 0.0f;

		glm::mat4 m_View;
		glm::mat4 m_Proj;
		glm::mat4 m_ViewProj;
	};

} // namespace Normal