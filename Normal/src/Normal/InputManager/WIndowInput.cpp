#include "Nrpch.h"
#include "WindowInput.h"

#include <Normal/Events/Event.h>
#include <Normal/Events/ApplicationEvent.h>

namespace Normal {

	WindowInput::WindowInput()
		: m_Callbacks{ nullptr }
	{
		NR_CORE_INFO_CTOR;
	}

	WindowInput::~WindowInput()
	{
		NR_CORE_INFO_DTOR;
	}

	void WindowInput::AttachCallback( WindowCallbackFn pFunc, Type type )
	{
		NR_CORE_ASSERT( pFunc, "Unexpected Error : Failed to called a AttachCallback Function." );
		int indices = static_cast<int>( type );
		m_Callbacks[indices] = nullptr;
		m_Callbacks[indices] = pFunc;
	}

	void WindowInput::DetachCallback( Type type )
	{
		int indices = static_cast<int>( type );
		m_Callbacks[indices] = nullptr;
	}

	void WindowInput::OnEvent( Event& event )
	{
		EventDispatcher dispatcher( event );

		// TODO : Category·Î ¹Ù²Ü Áö °í¹ÎÇØº¸±â
		switch ( event.GetEventType() )
		{
			case EventType::WindowResize:
			{
				dispatcher.Dispatch<WindowResizeEvent>( BIND_EVENT_FUNC( WindowInput::IsResizedWindow ) );
				return;
			} break;
			case EventType::WindowClose:
			{
				dispatcher.Dispatch<WindowCloseEvent>( BIND_EVENT_FUNC( WindowInput::IsClosedWindow ) );
				return;
			} break;
		}
	}

	bool WindowInput::IsResizedWindow( WindowResizeEvent& event ) const
	{
		int type = static_cast<int>( Type::IsResized );
		if ( m_Callbacks[type] != nullptr )
		{
			WindowInputData data;
			data.width = static_cast<float>( event.GetWidth() );
			data.height = static_cast<float>( event.GetHeight() );
			m_Callbacks[type]( { data.width, data.height } );
			return true;
		}
		return false;
	}

	bool WindowInput::IsClosedWindow( WindowCloseEvent& event ) const
	{
		int type = static_cast<int>( Type::IsClosed );
		if ( m_Callbacks[type] != nullptr )
		{
			m_Callbacks[type]( {} );
			return true;
		}
		return false;
	}

	bool WindowInput::IsAppTickWindow( AppTickEvent& event ) const
	{
		int type = static_cast<int>( Type::AppTick );
		if ( m_Callbacks[type] != nullptr )
		{
			m_Callbacks[type]( {} );
			return true;
		}
		return false;
	}

	bool WindowInput::IsAppUpdateWindow( AppUpdateEvent& event ) const
	{
		int type = static_cast<int>( Type::AppUpdate );
		if ( m_Callbacks[type] != nullptr )
		{
			m_Callbacks[type]( {} );
			return true;
		}
		return false;
	}

	bool WindowInput::IsAppRenderWindow( AppRenderEvent& event ) const
	{
		int type = static_cast<int>( Type::AppRender );
		if ( m_Callbacks[type] != nullptr )
		{
			m_Callbacks[type]( {} );
			return true;
		}
		return false;
	}

} // namespace Normal