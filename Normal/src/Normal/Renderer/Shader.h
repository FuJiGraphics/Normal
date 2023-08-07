#pragma once

#include <Normal/Core/Core.h>

namespace Normal {

	class NORMAL_API Shader
	{
	public:
		Shader( const std::string& vertexSrc, const std::string& fragmentSrc );
		virtual ~Shader();

		void Bind();
		void UnBind();

	private:
		NRuint m_RenderID;
	};


} // Normal