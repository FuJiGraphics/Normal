#include "Nrpch.h"
#include "OpenGLShader.h"

#include <glad/glad.h>
#include <glm/gtc/type_ptr.hpp>

#include <fstream>

namespace Normal {
	OpenGLShader::OpenGLShader( const ShaderPaths& paths )
		: m_RenderID( 0 ) 
	{
		Load( paths );
		Complie();
	}

	OpenGLShader::OpenGLShader( const std::string& vertexSrc, const std::string& fragmentSrc )
		: m_RenderID( 0 )
	{
		m_VertShaderSource = vertexSrc;
		m_FragShaderSource = fragmentSrc;
		Complie();
	}

	OpenGLShader::~OpenGLShader()
	{
		glDeleteShader( m_RenderID );
	}

	void OpenGLShader::Bind() const
	{
		glUseProgram( m_RenderID );
	}

	void OpenGLShader::UnBind() const
	{
		glUseProgram( 0 );
	}

	void OpenGLShader::UploadUniformInt( const std::string& name, const NRint int1 )
	{
		NRuint location = glGetUniformLocation( m_RenderID, name.c_str() );
		glUniform1i( location, int1 );
	}

	void OpenGLShader::UploadUniformFloat4( const std::string& name, const glm::vec4 float4 )
	{
		NRuint location = glGetUniformLocation( m_RenderID, name.c_str() );
		glUniform4f( location, float4.x, float4.y, float4.z, float4.w );
	}

	void OpenGLShader::UploadUniformMat4( const std::string& name, const glm::mat4 mat )
	{
		NRuint location = glGetUniformLocation( m_RenderID, name.c_str() );
		glUniformMatrix4fv( location, 1, GL_FALSE, glm::value_ptr( mat ) );
	}

	void OpenGLShader::Load( const ShaderPaths& paths )
	{
		if ( paths.VertPath.empty() == false )
		{
			std::ifstream ifs( paths.VertPath.c_str(), std::ios::binary );
			NR_CORE_ASSERT( ifs.is_open(), "Could not open shader file! \"{0}\"", paths.VertPath );
			std::stringstream ss;
			ss << ifs.rdbuf();
			m_VertShaderSource = ss.str();
			ifs.close();
		}
		if ( paths.FragPath.empty() == false )
		{
			std::ifstream ifs( paths.FragPath.c_str(), std::ios::binary );
			NR_CORE_ASSERT( ifs.is_open(), "Could not open shader file! \"{0}\"", paths.FragPath );
			std::stringstream ss;
			ss << ifs.rdbuf();
			m_FragShaderSource = ss.str();
			ifs.close();
		}
	}

	void OpenGLShader::Complie()
	{
		// Create an empty vertex shader handle
		NRuint vertexShader = glCreateShader( GL_VERTEX_SHADER );

		// Send the vertex shader source code to GL
		// Note that std::string's .c_str is NULL character terminated.
		const NRchar* source = (const NRchar*)m_VertShaderSource.c_str();
		glShaderSource( vertexShader, 1, &source, 0 );

		// Compile the vertex shader
		glCompileShader( vertexShader );

		NRint isCompiled = 0;
		glGetShaderiv( vertexShader, GL_COMPILE_STATUS, &isCompiled );
		if ( isCompiled == GL_FALSE )
		{
			NRint maxLength = 0;
			glGetShaderiv( vertexShader, GL_INFO_LOG_LENGTH, &maxLength );

			// The maxLength includes the NULL character
			std::vector<NRchar> infoLog( maxLength );
			glGetShaderInfoLog( vertexShader, maxLength, &maxLength, &infoLog[0] );

			// We don't need the shader anymore.
			glDeleteShader( vertexShader );

			// Use the infoLog as you see fit.
			NR_CORE_ERROR( "Vertex Shader Error: {0}", infoLog.data() );
			NR_CORE_ASSERT( NULL, "Failed to Load a Vertex Shader." );

			// In this simple program, we'll just leave
			return;
		}

		// Create an empty fragment shader handle
		NRuint fragmentShader = glCreateShader( GL_FRAGMENT_SHADER );

		// Send the fragment shader source code to GL
		// Note that std::string's .c_str is NULL character terminated.
		source = (const NRchar*)m_FragShaderSource.c_str();
		glShaderSource( fragmentShader, 1, &source, 0 );

		// Compile the fragment shader
		glCompileShader( fragmentShader );

		glGetShaderiv( fragmentShader, GL_COMPILE_STATUS, &isCompiled );
		if ( isCompiled == GL_FALSE )
		{
			NRint maxLength = 0;
			glGetShaderiv( fragmentShader, GL_INFO_LOG_LENGTH, &maxLength );

			// The maxLength includes the NULL character
			std::vector<NRchar> infoLog( maxLength );
			glGetShaderInfoLog( fragmentShader, maxLength, &maxLength, &infoLog[0] );

			// We don't need the shader anymore.
			glDeleteShader( fragmentShader );
			// Either of them. Don't leak shaders.
			glDeleteShader( vertexShader );

			// Use the infoLog as you see fit.
			NR_CORE_ERROR( "Fragment Shader Error: {0}", infoLog.data() );
			NR_CORE_ASSERT( NULL, "Failed to Load a Fragment Shader." );

			// In this simple program, we'll just leave
			return;
		}

		// Vertex and fragment shaders are successfully compiled.
		// Now time to link them together into a program.
		// Get a program object.
		m_RenderID = glCreateProgram();
		NRuint program = m_RenderID;

		// Attach our shaders to our program
		glAttachShader( program, vertexShader );
		glAttachShader( program, fragmentShader );

		// Link our program
		glLinkProgram( program );

		// Note the different functions here: glGetProgram* instead of glGetShader*.
		NRint isLinked = 0;
		glGetProgramiv( program, GL_LINK_STATUS, (int*)&isLinked );
		if ( isLinked == GL_FALSE )
		{
			NRint maxLength = 0;
			glGetProgramiv( program, GL_INFO_LOG_LENGTH, &maxLength );

			// The maxLength includes the NULL character
			std::vector<NRchar> infoLog( maxLength );
			glGetProgramInfoLog( program, maxLength, &maxLength, &infoLog[0] );

			// We don't need the program anymore.
			glDeleteProgram( program );
			// Don't leak shaders either.
			glDeleteShader( vertexShader );
			glDeleteShader( fragmentShader );

			// Use the infoLog as you see fit.
			NR_CORE_ERROR( "Shader Program Error: {0}", infoLog.data() );
			NR_CORE_ASSERT( NULL, "Failed to Create a Shader Program." );

			// In this simple program, we'll just leave
			return;
		}

		// Always detach shaders after a successful link.
		glDetachShader( program, vertexShader );
		glDetachShader( program, fragmentShader );
	}

} // namespace Normal