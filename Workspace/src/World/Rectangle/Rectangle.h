#pragma once

#include <Normal/Core/Core.h>

#include <Normal/Renderer/Buffer.h>
#include <Normal/Renderer/Renderer.h>
#include <Normal/Renderer/Shader.h>

namespace Normal {

	class NORMAL_API Rectangle
	{
	public:
		explicit Rectangle();
		virtual ~Rectangle();

		void Bind() const;
		void UnBind() const; 

		std::shared_ptr<VertexArray>& GetVertexArray() { return m_VertexArray; }

	private:
		std::vector<float> m_Data;
		std::vector<NRuint> m_Indices;

		std::shared_ptr<VertexArray> m_VertexArray;
		
		std::string m_VertexShader;
		std::string m_IndexShader;
		std::shared_ptr<Shader> m_Shader;

		NR_SET_NAME("Rectangle");
	};


}


