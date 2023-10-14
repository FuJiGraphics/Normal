#pragma once

#include <Normal/Core/Core.h>
#include <Normal/Core/Level.h>
#include <Normal/Renderer/Texture.h>
#include <Normal/Renderer/CameraManager.h>

class World : public Normal::Level
{
public:
	World();
	virtual ~World() = default;

	virtual void OnEvent( Normal::Event& event ) override;
	virtual void OnUpdate( const float& dt ) override;
	virtual void OnGuiRender() override;

private:
	Normal::CameraManager m_CameraManager;

	glm::vec4 m_SquareColor;
};

