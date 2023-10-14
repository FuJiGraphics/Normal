#pragma once
#include <Normal/Core/Core.h>
#include <Normal/Renderer/Shader.h>
#include <Normal/Renderer/VertexArray.h>
#include <array>
#include <glm/glm.hpp>

namespace Normal {

	struct NORMAL_API Quad
	{
	public:
		explicit Quad( const glm::vec3& v0 = glm::vec3( -0.5f, -0.5f, 0.0f ),
					   const glm::vec3& v1 = glm::vec3( +0.5f, -0.5f, 0.0f ),
					   const glm::vec3& v2 = glm::vec3( +0.5f, +0.5f, 0.0f ),
					   const glm::vec3& v3 = glm::vec3( -0.5f, +0.5f, 0.0f ),
					   const std::vector<NRuint>& idx = std::vector<NRuint>{ 0, 1, 2, 0, 2, 3 } );
		~Quad();

		void Bind() const;
		void UnBind() const;

		Own::Share<Normal::VertexArray>& GetVertexArray() { return m_VertexArray; }
		Own::Share<Normal::Shader>& GetShader() { return m_ShaderManager.Get( "Quad" ); }

	private:
		std::vector<Normal::NRuint> m_Indices;
		std::vector<float> m_Data;
		ShaderManager m_ShaderManager;
		Own::Share<VertexArray>	m_VertexArray;

		bool m_IsBlend = false;
		NR_SET_NAME( "Quad" );
	};


}