#include "Nrpch.h"
#include "Shader.h"

#include <glad/glad.h>

namespace Normal {

	Shader::Shader( const std::string& vertexSrc, const std::string& fragmentSrc )
	{
		// Create an empty vertex shader handle
		NRuint vertexShader = glCreateShader( GL_VERTEX_SHADER );

		// Send the vertex shader source code to GL
		// Note that std::string's .c_str is NULL character terminated.
		const NRchar* source = (const NRchar*)vertexSrc.c_str();
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
		source = (const NRchar*)fragmentSrc.c_str();
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

	Shader::~Shader()
	{
		glDeleteProgram( m_RenderID );
	}

	void Shader::Bind()
	{
		glUseProgram( m_RenderID );
	}

	void Shader::UnBind()
	{
		glUseProgram( 0 );
	}


}