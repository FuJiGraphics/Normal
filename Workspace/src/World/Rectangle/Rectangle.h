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

	std::shared_ptr<Normal::VertexArray>& GetVertexArray() { return m_VertexArray; }
	std::shared_ptr<Normal::Shader>& GetShader() { return m_Shader; }

private:
	std::vector<float> m_Data;
	std::vector<Normal::NRuint> m_Indices;

	std::shared_ptr<Normal::VertexArray> m_VertexArray;
		
	std::string m_VertexShader;
	std::string m_IndexShader;
	std::shared_ptr<Normal::Shader> m_Shader;

	NR_SET_NAME("Rectangle");
};



