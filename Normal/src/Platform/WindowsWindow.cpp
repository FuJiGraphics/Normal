#include "Nrpch.h"
#include "WindowsWindow.h"

namespace Normal {
	// static function from Window.h
	Window* Window::Create( const WindowProps& props )
	{
		return new WindowsWindow( props );
	}

	WindowsWindow::WindowsWindow( const WindowProps& props )
	{
		Init( props );
	}

	WindowsWindow::~WindowsWindow()
	{
		Destroy();
	}

	void WindowsWindow::OnUpdate()
	{
		glfwPollEvents();
		glfwSwapBuffers( m_Window );
	}

	void WindowsWindow::SetVSync( bool enabled )
	{
		m_Data.VSync = enabled;
		switch ( enabled )
		{
		case true:
			glfwSwapInterval( 1 );
			break;
		case false:
			glfwSwapInterval( 0 );
			break;
		}

	}

	void WindowsWindow::Init( const WindowProps& props )
	{
		auto& [ Title, Width, Height, VSync, Callback ] = m_Data;
		Title  = props.Title;
		Width  = props.Width;
		Height = props.Height;
		VSync  = props.VSync;

		NR_CORE_INFO( "Created the Windows Window. Resolution:{0},{1} VSync{2}", Width, Height, VSync );

		if ( !m_GLFWinitialized )
		{
			m_GLFWinitialized = true;
			int success = glfwInit();
			NR_CLIENT_ASSERT( success, "Failed to GLFW initialized." );
		}

		m_Window = glfwCreateWindow( (int)Width, (int)Height, Title.c_str(), NULL, NULL );
		glfwMakeContextCurrent( m_Window );
		glfwSetWindowUserPointer( m_Window, &m_Data );
		SetVSync( VSync );

	}

	void WindowsWindow::Destroy()
	{
		if ( m_Window != nullptr ) 
		{
			glfwDestroyWindow( m_Window );
			glfwTerminate();
		}
	}

} // namespace Normal