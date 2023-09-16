#pragma once

#include <Normal/Core/Core.h>

#include <Normal/Renderer/Buffer.h>
#include <Normal/Renderer/Renderer.h>
#include <Normal/Renderer/Shader.h>

class Rec
{
public:
	explicit Rec();
	virtual ~Rec();

	void Bind() const;
	void UnBind() const; 

	Normal::NrPtr<Normal::VertexArray>& GetVertexArray() { return m_VertexArray; }
	Normal::NrPtr<Normal::Shader>& GetShader() { return m_Shader; }

private:
	std::vector<float> m_Data;
	std::vector<Normal::NRuint> m_Indices;

	Normal::NrPtr<Normal::VertexArray> m_VertexArray;
		
	std::string m_VertexShader;
	std::string m_IndexShader;
	Normal::NrPtr<Normal::Shader> m_Shader;

	NR_SET_NAME("Rectangle");
};



