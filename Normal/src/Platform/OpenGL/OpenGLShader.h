#pragma once

#include <Normal/Core/Core.h>
#include <Normal/Renderer/Shader.h>

namespace Normal {

	class NORMAL_API OpenGLShader : public Shader
	{
	public:
	    explicit OpenGLShader( const std::string& vertexSrc, const std::string& fragmentSrc );
		virtual ~OpenGLShader();

	public:
		virtual void Bind() const override;
		virtual void UnBind() const override;

		virtual void UploadUniformFloat4( const std::string& name, const glm::vec4 float4 ) override;
		virtual void UploadUniformMat4( const std::string& name, const glm::mat4 mat ) override;

	private:
		NRuint m_RenderID;

		NR_SET_NAME( "OpenGLShader" );
	};

} // namespace Normal

