#include "Nrpch.h"
#include "MouseInput.h"

#include "Normal/Events/Event.h"
#include "Normal/Events/MouseEvent.h"
#include "Normal/Events/ApplicationEvent.h"

namespace Normal {

	MouseInput::MouseInput()
		: m_Callbacks{ nullptr }
	{
		NR_CORE_INFO_CTOR;
	}

	MouseInput::~MouseInput()
	{
		NR_CORE_INFO_DTOR;
	}

	void MouseInput::AttachCallback( MouseCallbackFn pFunc, Type type )
	{
		NR_CORE_ASSERT( pFunc, "Unexpected Error : Failed to called a AttachCallback Function." );
		int indices = static_cast<int>( type );
		m_Callbacks[indices] = nullptr;
		m_Callbacks[indices] = pFunc;
	}

	void MouseInput::DetachCallback( Type type )
	{
		int indices = static_cast<int>( type );
		m_Callbacks[indices] = nullptr;
	}

	void MouseInput::OnEvent( Normal::Event& event )
	{
		EventDispatcher dispatcher( event );
		
		// TODO : Category·Î ¹Ù²Ü Áö °í¹ÎÇØº¸±â
		switch ( event.GetEventType() )
		{
			case EventType::MouseButtonPressed:
			{
				dispatcher.Dispatch<MouseButtonPressedEvent>( BIND_EVENT_FUNC( MouseInput::IsPressed ) );
				return;
			} break;
			case EventType::MouseButtonReleased:
			{
				dispatcher.Dispatch<MouseButtonReleasedEvent>( BIND_EVENT_FUNC( MouseInput::IsReleased ) );
				return;
			} break;
			case EventType::MouseScrolled:
			{
				dispatcher.Dispatch<MouseScrolledEvent>( BIND_EVENT_FUNC( MouseInput::IsScrolled ) );
				return;
			} break;
			case EventType::MouseMoved:
			{
				dispatcher.Dispatch<MouseMovedEvent>( BIND_EVENT_FUNC( MouseInput::IsMoved ) );
				return;
			} break;
		}
	} // scope = void Mouse::OnEvent( Normal::Event& event )

	bool MouseInput::IsPressed( MouseButtonPressedEvent& event ) const
	{
		int type = static_cast<int>( Type::IsPressed );
		if ( m_Callbacks[type] != nullptr )
		{
			m_Callbacks[type]( { event.GetMouseButton(), 0.0f, 0.0f } );
			return true;
		}
		return false;
	}

	bool MouseInput::IsReleased( MouseButtonReleasedEvent& event ) const
	{
		int type = static_cast<int>( Type::IsReleased );
		if ( m_Callbacks[type] != nullptr )
		{
			m_Callbacks[type]( { event.GetMouseButton() } );
			return true;
		}
		return false;
	}

	bool MouseInput::IsScrolled( MouseScrolledEvent& event ) const
	{
		int type = static_cast<int>( Type::IsScrolled );
		if ( m_Callbacks[type] != nullptr )
		{
			m_Callbacks[type]( { 0, event.GetXOffset(), event.GetYOffset() } );
			return true;
		}
		return false;
	}

	bool MouseInput::IsMoved( MouseMovedEvent& event ) const
	{
		int type = static_cast<int>( Type::IsMoved );
		if ( m_Callbacks[type] != nullptr )
		{
			m_Callbacks[type]( { 0, event.GetX(), event.GetY() });
			return true;
		}
		return false;
	}

} // namespace Normal

