#include "Nrpch.h"
#include "WindowsWindow.h"

#include <Normal/Events/Event.h>
#include <Normal/Events/KeyEvent.h>
#include <Normal/Events/MouseEvent.h>
#include <Normal/Events/ApplicationEvent.h>

#include "Normal/Renderer/RenderContext.h"

#include <GLFW/glfw3.h>

namespace Normal {
	// static function from Window.h
	Window* Window::Create( const WindowProps& props )
	{
		return new WindowsWindow( props );
	}

	WindowsWindow::WindowsWindow( const WindowProps& props )
		: m_Data{}
	{
		Initialize( props );
		NR_CORE_INFO_CTOR;
		NR_CORE_INFO( "Platform:[{0}]  Title:[{1}]  Resolution:[{2}:{3}]  VSync Mode:[{4}]",
					  "Windows", m_Data.Title, m_Data.Width, m_Data.Height, m_Data.VSync );
	}

	WindowsWindow::~WindowsWindow()
	{
		Destroy();
		NR_CORE_INFO_DTOR;
	}

	void WindowsWindow::OnUpdate()
	{
		glfwPollEvents();
		m_RenderContext->SwapBuffers();
	}

	void WindowsWindow::SetWindowSize( float width, float height )
	{
		NR_CORE_ASSERT( m_Window, "Memory Access Error : m_Window need to be initialized." );
		glfwSetWindowSize( m_Window, width, height );
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

		// Set Window
		// glfwWindowHint( GLFW_FOCUSED, GLFW_FALSE );
		m_Window = glfwCreateWindow( Width, Height, Title.c_str(), NULL, NULL );
		glfwSetWindowUserPointer( m_Window, &m_Data );

		// Set Rendering Context
		m_RenderContext = MakePtr( RenderContext::Create( m_Window ) );
		m_RenderContext->InitContext();

		SetVSync( VSync );
		SetCallbacks();
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

									   WindowResizeEvent event{ width, height };
									   data.Callback( event );
								   } );

		glfwSetWindowCloseCallback( m_Window,
									[]( GLFWwindow* window ) {
										WindowData& data = *(WindowData*)glfwGetWindowUserPointer( window );

										WindowCloseEvent event;
										data.Callback( event );
									} );
		glfwSetCursorPosCallback( m_Window,
								  []( GLFWwindow* window, double xpos, double ypos ) {
									  WindowData& data = *(WindowData*)glfwGetWindowUserPointer( window );
									  
									  MouseMovedEvent event( (float)xpos, (float)ypos );
									  data.Callback( event );
								  } );
		glfwSetMouseButtonCallback( m_Window,
									[]( GLFWwindow* window, int button, int action, int mods ) {
										WindowData& data = *(WindowData*)glfwGetWindowUserPointer( window );

										switch ( action )
										{
											case GLFW_PRESS:
											{
												MouseButtonPressedEvent event( button );
												data.Callback( event );
											} break;
											case GLFW_RELEASE:
											{
												MouseButtonReleasedEvent event( button );
												data.Callback( event );
											} break;
										}
									} );
		glfwSetScrollCallback( m_Window,
							   []( GLFWwindow* window, double xoffset, double yoffset )
							   {
								   WindowData& data = *(WindowData*)glfwGetWindowUserPointer( window );
								   
								   MouseScrolledEvent event( (float)xoffset, (float)yoffset );
								   data.Callback( event );
							   } );


		glfwSetKeyCallback( m_Window, 
							[]( GLFWwindow* window, int key, int scancode, int action, int mods )
							{
								WindowData& data = *(WindowData*)glfwGetWindowUserPointer( window );
								static NRuint64 repeatCount = 0;
						
								KeyReleasedEvent releasedEvent( key );
								KeyPressedEvent pressedEvent( key, (NRuint)repeatCount );
								switch ( action )
								{
									case GLFW_RELEASE:
									{
										// NR_CORE_TRACE( "Called a glfwSetKeyCallback Release." );
										repeatCount = 0;
										data.Callback( releasedEvent );
										return;
									} break;

									case GLFW_PRESS: [[fallthrough]];
									case GLFW_REPEAT:
									{
										// NR_CORE_TRACE( "Called a glfwSetKeyCallback Press || Repeat." );
										++repeatCount;
										data.Callback( pressedEvent );
										return;
									} break;
								}
							} );

		glfwSetCharCallback( m_Window,
							 []( GLFWwindow* window, unsigned int key )
							 {
								 // NR_CORE_TRACE( "Called a glfwSetCharCallback" );
								 WindowData& data = *(WindowData*)glfwGetWindowUserPointer( window );
								 KeyTypedEvent pressedEvent( key );
								 data.Callback( pressedEvent );
							 } );

	} // namespace SetCallbacks

} // namespace Normal