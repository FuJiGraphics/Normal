#pragma once

#include <Normal/Core/Core.h>

namespace Normal {

	class NORMAL_API Shader
	{
	protected:
		explicit Shader() = default;
	public:
		virtual ~Shader() = default;

	public:
		virtual void Bind() const = 0;
		virtual void UnBind() const = 0;

		static Shader* Create( const std::string& vertexSrc, const std::string& fragmentSrc );
	};


} // namespace Normal