#pragma once

#include <Normal/Core/Core.h>
#include <Normal/Core/Level.h>
#include <Normal/Renderer/Camera.h>

#include "Rectangle\Rectangle.h"

class World : public Normal::Level
{
public:
	World();
	virtual ~World() = default;

	virtual void OnEvent( Normal::Event& event ) override;
	virtual void OnUpdate( const float& dt ) override;
	virtual void OnGuiRender() override;

private:
	Rec m_Rec;

	glm::vec4 m_SquareColor;
	std::shared_ptr<Normal::Camera> m_Camera;
};

