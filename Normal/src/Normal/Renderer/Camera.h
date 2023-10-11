#pragma once

#include <Normal/Core/Core.h>
#include <glm/glm.hpp>

namespace Normal {

	enum class EularAngle { 
		None = 0,
		Pitch, Yaw, Roll 
	};

	enum class RotSpace
	{
		None = 0,
		Local, World
	};

	// Camera Interface
	class NORMAL_API Camera
	{
	public:
		explicit Camera() = default;
		~Camera() = default;

	public:
		inline virtual glm::mat4& GetVPMatrix() = 0;

		virtual void SetPosition( const glm::vec3& pos ) = 0;
		virtual void SetRotation( const float& angle, const EularAngle& type ) = 0;
		virtual void SetScale( const float scale ) = 0;
	};

	// Orthogonal Projection Camera
	class NORMAL_API OrthogonalCamera : public Camera
	{
	public:
		OrthogonalCamera( float left, float right, float bottom, float top );
		~OrthogonalCamera() = default ;

	public:
		inline virtual glm::mat4& GetVPMatrix() override { return m_ViewProj; }

		virtual void SetPosition( const glm::vec3& pos ) override;
		virtual void SetRotation( const float& angle, const EularAngle& type ) override;
		virtual void SetScale( const float scale ) override;


	private:
		void SetCalculateViewProj();

	private:
		glm::vec3 m_Pos;

		float m_Pitch = 0.0f;
		float m_Yaw   = 0.0f;
		float m_Roll  = 0.0f;

		float m_Scale = 1.0f;
		glm::mat4 m_View;
		glm::mat4 m_Proj;
		glm::mat4 m_ViewProj;
	};

} // namespace Normal