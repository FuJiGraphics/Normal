#pragma once

#include <Normal/Core/Core.h>

#include <Normal/Renderer/Buffer.h>
#include <Normal/Renderer/Renderer.h>
#include <Normal/Renderer/Shader.h>

using namespace Normal;

class Rec
{
public:
	explicit Rec();
	virtual ~Rec();

	void Bind() const;
	void UnBind() const; 

	Own::Share<Normal::VertexArray>& GetVertexArray() { return m_VertexArray; }
	Own::Share<Normal::Shader>& GetShader() { return m_Shader; }

private:
	std::vector<float> m_Data;
	std::vector<Normal::NRuint> m_Indices;

	Own::Share<Normal::VertexArray> m_VertexArray;
		
	std::string m_TexVertexShader;
	std::string m_TexFragmentShader;

	Own::Share<Normal::Shader> m_Shader;

	bool m_IsBlend = false;
	NR_SET_NAME("Rectangle");
};



