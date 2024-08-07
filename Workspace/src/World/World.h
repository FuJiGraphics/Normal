#pragma once
#include <NormalEngine.h>

class World : public Normal::Level
{
public:
	World();
	virtual ~World() = default;

	virtual void OnEvent( Normal::Event& event ) override;
	virtual void OnUpdate( const float& dt ) override;
	virtual void OnGuiRender() override;

private:
	Normal::Own::Share<Normal::Texture2D> m_Tex_Tile;
	
	Normal::TimeStep m_TimeStep;
	Normal::Timer m_Timer;

	glm::vec4 m_SquareColor;
};

