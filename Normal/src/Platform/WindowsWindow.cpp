#include "Nrpch.h"
#include "WindowsWindow.h"

#include "Normal/Events/Event.h"
#include "Normal/Events/KeyEvent.h"
#include "Normal/Events/MouseEvent.h"
#include "Normal/Events/ApplicationEvent.h"

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

		if ( !m_GLFWinitialized )
		{
			m_GLFWinitialized = true;
			int success = glfwInit();
			NR_CLIENT_ASSERT( success, "Failed to GLFW initialized." );
		}

		m_Window = glfwCreateWindow( Width, Height, Title.c_str(), NULL, NULL );
		glfwMakeContextCurrent( m_Window );
		glfwSetWindowUserPointer( m_Window, &m_Data );
		SetVSync( VSync );
		SetCallbacks();

		NR_CORE_INFO( "Successfully Created Window : [Resolution={0}/{1}] [VSync={2}]", Width, Height, VSync );
	}

	void WindowsWindow::Destroy()
	{
		if ( m_Window != nullptr ) 
		{
			glfwDestroyWindow( m_Window );
			glfwTerminate();
		}
	}

	void WindowsWindow::SetCallbacks() const
	{
		glfwSetWindowSizeCallback( m_Window,
								   []( GLFWwindow* window, int width, int height )
								   {
									   WindowData& data = *(WindowData*)glfwGetWindowUserPointer( window );
									   data.Width = width;
									   data.Height = height;

									   WindowResizeEvent event{ width, width };
									   for ( auto& callback : data.Callbacks )
									   {
										   callback( event );
									   }
								   } );

		glfwSetWindowCloseCallback( m_Window,
									[]( GLFWwindow* window ) {
										WindowData& data = *(WindowData*)glfwGetWindowUserPointer( window );

										WindowCloseEvent event;
										for ( auto& callback : data.Callbacks )
										{
											callback( event );
										}
									} );
		glfwSetCursorPosCallback( m_Window,
								  []( GLFWwindow* window, double xpos, double ypos ) {
									  WindowData& data = *(WindowData*)glfwGetWindowUserPointer( window );
									  
									  MouseMovedEvent event( xpos, ypos );
									  for ( auto& callback : data.Callbacks )
									  {
										  callback( event );
									  }
								  } );
		glfwSetMouseButtonCallback( m_Window,
									[]( GLFWwindow* window, int button, int action, int mods ) {
										WindowData& data = *(WindowData*)glfwGetWindowUserPointer( window );

										switch ( action )
										{
											case GLFW_PRESS:
											{
												MouseButtonPressedEvent event( button );
												for ( auto& callback : data.Callbacks )
												{
													callback( event );
												}
											} break;
											case GLFW_RELEASE:
											{
												MouseButtonReleasedEvent event( button );
												for ( auto& callback : data.Callbacks )
												{
													callback( event );
												}
											} break;
										}
									} );
		glfwSetScrollCallback( m_Window,
							   []( GLFWwindow* window, double xoffset, double yoffset )
							   {
								   WindowData& data = *(WindowData*)glfwGetWindowUserPointer( window );
								   
								   MouseScrolledEvent event( xoffset, yoffset );
								   for ( auto& callback : data.Callbacks )
								   {
									   callback( event );
								   }
							   } );



	} // namespace SetCallbacks

} // namespace Normal