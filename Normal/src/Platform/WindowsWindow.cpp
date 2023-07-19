#include "Nrpch.h"
#include "WindowsWindow.h"

#include "./Normal/Log.h"

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
	}

	void WindowsWindow::Init( const WindowProps& props )
	{
		m_Data.Title  = props.Title;
		m_Data.Width  = props.Width;
		m_Data.Height = props.Height;
		m_Data.VSync  = props.VSync;

		if ( !m_GLFWinitialized )
		{
			int success = 0;
			NR_CLIENT_ASSERT( success, "Failed to GLFW initialized." );
		}

		m_Window = glfwCreateWindow( (int)m_Data.Width,
									 (int)m_Data.Height,
									 m_Data.Title.c_str(),
									 NULL, NULL );

		m_HasWindowCreated = true;
	}

	void WindowsWindow::Destroy()
	{
		if ( m_Window != nullptr ) 
		{
			glfwDestroyWindow( m_Window );
		}
	}

} // namespace Normal