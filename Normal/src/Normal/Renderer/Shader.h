#pragma once

#include <Normal/Core/Core.h>

namespace Normal {

	struct ShaderPaths
	{
		std::string VertPath;
		std::string FragPath;
	};

	class NORMAL_API Shader
	{
	protected:
		explicit Shader() = default;
	public:
		virtual ~Shader() = default;

	public:
		virtual void Bind() const = 0;
		virtual void UnBind() const = 0;

		virtual void UploadUniformInt( const std::string& name, const NRint int1 ) = 0 ;
		virtual void UploadUniformFloat4( const std::string& name, const glm::vec4 float4 ) = 0;
		virtual void UploadUniformMat4( const std::string& name, const glm::mat4 mat ) = 0;

		static Shader* Create( const ShaderPaths& paths );
		static Shader* Create( const std::string& vertexSrc, const std::string& fragmentSrc );
	};

} // namespace Normal