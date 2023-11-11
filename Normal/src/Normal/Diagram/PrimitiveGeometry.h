#pragma once
#include <Normal/Core/Core.h>
#include <Normal/Renderer/VertexArray.h>
#include <glm/glm.hpp>

namespace Normal {

	struct NORMAL_API Quad2D
	{
	public:
		explicit Quad2D( const NRint& x, const NRint& y, const NRuint& width, const NRuint& height,
						 const std::vector<NRuint>& idx = std::vector<NRuint>{ 0, 1, 2, 0, 2, 3 } );
		explicit Quad2D(	const glm::vec3& v0 = glm::vec3( -0.5f, -0.5f, 0.0f ),
							const glm::vec3& v1 = glm::vec3( +0.5f, -0.5f, 0.0f ),
							const glm::vec3& v2 = glm::vec3( +0.5f, +0.5f, 0.0f ),
							const glm::vec3& v3 = glm::vec3( -0.5f, +0.5f, 0.0f ),
							const std::vector<NRuint>& idx = std::vector<NRuint>{ 0, 1, 2, 0, 2, 3 } );
		~Quad2D();

		void Bind() const;
		void UnBind() const;

		inline Own::Share<Normal::VertexArray>&	GetVertexArray() { return m_VertexArray; }
		inline const Own::Share<Normal::VertexArray>& GetVertexArray() const { return m_VertexArray; }

	private:
		std::vector<Normal::NRuint>		m_Indices;
		std::vector<float>				m_Data;
		Own::Share<VertexArray>			m_VertexArray;

		bool m_IsBlend = false;
		NR_SET_NAME( "Quad" );
	};


}