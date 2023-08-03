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
	}

	void OpenGLContext::SwapBuffers()
	{
		glfwSwapBuffers( m_Window );
	}

} // namespace Normal