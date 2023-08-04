#include "Nrpch.h"
#include "OpenGLContext.h"

#include <GLFW/glfw3.h>
#include <glad/glad.h>

namespace Normal {


	OpenGLContext::OpenGLContext( GLFWwindow* window )
		: m_Window( window )
	{
		NR_CORE_ASSERT( window, "Window Handle is NULL." );
		NR_CORE_INFO_CTOR;
	}

	OpenGLContext::~OpenGLContext()
	{
		NR_CORE_INFO_DTOR;
	}

	void OpenGLContext::InitContext()
	{
		glfwMakeContextCurrent( m_Window );
		uint8 status = gladLoadGLLoader( GLADloadproc( glfwGetProcAddress ) );
		NR_CORE_ASSERT( status, "Failed to load Glad extenstion. " );

		ShowRendererProps();
	}

	void OpenGLContext::SwapBuffers()
	{
		glfwSwapBuffers( m_Window );
	}

	void OpenGLContext::ShowRendererProps() const
	{		
		// show driver performence
		const char* vendor = reinterpret_cast<const char*>( glGetString( GL_VENDOR ) );
		const char* renderer = reinterpret_cast<const char*>( glGetString( GL_RENDERER ) );
		const char* version = reinterpret_cast<const char*>( glGetString( GL_VERSION ) );
		NR_CORE_INFO( "-------------------------------------------------------" );
		NR_CORE_INFO( "##### OpenGL Renderer #####" );
		NR_CORE_INFO( "Vendor: {0}", vendor );
		NR_CORE_INFO( "Renderer: {0}", renderer );
		NR_CORE_INFO( "Version: {0}", version );
		NR_CORE_INFO( "-------------------------------------------------------" );
	}

} // namespace Normal