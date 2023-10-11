#pragma once

#include <Normal/Core/Core.h>
#include <Normal/Core/Level.h>
#include <Normal/Core/NrPointer.h>
#include <Normal/Renderer/Texture.h>
#include <Normal/Renderer/CameraManager.h>

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
	Normal::CameraManager m_CameraManager;

	Own::Share<Normal::Texture> m_Texture;
	Own::Share<Normal::Texture> m_BlendTexture;

	glm::vec4 m_SquareColor;
};

