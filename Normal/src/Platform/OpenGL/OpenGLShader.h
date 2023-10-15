#pragma once

#include <Normal/Core/Core.h>
#include <Normal/Renderer/Shader.h>

namespace Normal {

	class NORMAL_API OpenGLShader : public Shader
	{
	public:
		explicit OpenGLShader( const ShaderPaths& paths );
	    explicit OpenGLShader( const std::string& vertexSrc, const std::string& fragmentSrc );
		virtual ~OpenGLShader();

	public:
		virtual void Bind() const override;
		virtual void UnBind() const override;

		virtual void SetInt( const std::string& name, const NRint& int1 ) override;
		virtual void SetFloat4( const std::string& name, const glm::vec4& float4 ) override;
		virtual void SetMat4( const std::string& name, const glm::mat4& mat4 ) override;

	protected:
		void Load( const ShaderPaths& paths );
		void Complie();

	private:
		NRuint m_RenderID;

		std::string m_VertShaderSource;
		std::string m_FragShaderSource;

		NR_SET_NAME( "OpenGLShader" );
	};

} // namespace Normal

