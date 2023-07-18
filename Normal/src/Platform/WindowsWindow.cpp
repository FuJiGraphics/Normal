#include "Nrpch.h"
#include "WindowsWindow.h"


namespace Normal {

	static Window* Create( const WindowProps& props = WindowProps() )
	{
		return new WindowsWindow( props );
	}

	WindowsWindow::WindowsWindow( const WindowProps& props )
		: m_Width( props.Width )
		, m_Height( props.Height )
		, m_Title( props.Title )
	{
		// Empty
	}

	void WindowsWindow::OnUpdate()
	{

	}

	void WindowsWindow::SetEventCallBack( const EventCallbackFn& callback )
	{


	}

	void WindowsWindow::SetVSync( bool enabled )
	{


	}

	bool WindowsWindow::IsVSync() const
	{


		return false;
	}

} // namespace Normal