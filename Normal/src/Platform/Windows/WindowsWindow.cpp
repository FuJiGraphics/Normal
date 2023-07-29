#include "Nrpch.h"
#include "WindowsWindow.h"

#include "Normal/Events/Event.h"
#include "Normal/Events/KeyEvent.h"
#include "Normal/Events/MouseEvent.h"
#include "Normal/Events/ApplicationEvent.h"

#include <glad/glad.h>
#include <GLFW\glfw3.h>

namespace Normal {
	// static function from Window.h
	Window* Window::Create( const WindowProps& props )
	{
		return new WindowsWindow( props );
	}

	WindowsWindow::WindowsWindow( const WindowProps& props )
		: m_Data()
	{
		Initialize( props );
	}

	WindowsWindow::~WindowsWindow()
	{
		Destroy();
	}

	void WindowsWindow::OnUpdate()
	{
		glfwPollEvents();
		// testing 

		// -------
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

	void WindowsWindow::Initialize( const WindowProps& props )
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

		uint8 status = gladLoadGLLoader( GLADloadproc( glfwGetProcAddress ) );
		NR_CORE_ASSERT( status, "Failed to load Glad extenstion. " );

		SetVSync( VSync );
		SetCallbacks();

		NR_CORE_INFO( "{0} Successfully Created Window : [Resolution={1}/{2}] [VSync={3}]", NR_GET_NAME, Width, Height, VSync );
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


		// TODO : 임시적으로 여기에 선언
		// static uint64 repeatCount = 0;
		//glfwSetKeyCallback( m_Window, 
		//					[]( GLFWwindow* window, int key, int scancode, int action, int mods )
		//					{
		//						WindowData& data = *(WindowData*)glfwGetWindowUserPointer( window );
		//						KeyReleasedEvent releasedEvent( key );
		//						repeatCount = 0;
		//						for ( auto& callback : data.Callbacks )
		//						{
		//							if ( action == GLFW_RELEASE )
		//							{
		//								callback( releasedEvent );
		//							}
		//						}
		//					} );

		glfwSetCharCallback( m_Window,
							 []( GLFWwindow* window, unsigned int key )
							 {
								 WindowData& data = *(WindowData*)glfwGetWindowUserPointer( window );
								 // ++repeatCount;
								 KeyPressedEvent pressedEvent( key );
								 for ( auto& callback : data.Callbacks )
								 {
									 callback( pressedEvent );
								 }
							 } );

	} // namespace SetCallbacks

} // namespace Normal