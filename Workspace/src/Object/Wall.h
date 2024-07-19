#pragma once
#include <NormalEngine.h>

class Wall : public Normal::Level
{
public:
	Wall();
	virtual ~Wall() = default;

	virtual void OnEvent( Normal::Event& event ) override;
	virtual void OnUpdate( const float& dt ) override;
	virtual void OnGuiRender() override;

private:
	glm::vec4				m_WallColor;
	glm::vec2				m_Pos;
	glm::vec2				m_Scale;
};

