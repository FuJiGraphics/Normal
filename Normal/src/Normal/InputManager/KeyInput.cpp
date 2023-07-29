#include "Nrpch.h"
#include "KeyInput.h"

#include "Normal/Core/Window.h"

#include "Normal/Events/Event.h"
#include "Normal/Events/KeyEvent.h"

namespace Normal {

	KeyInput::KeyInput()
	{
		// Empty
	}


	KeyInput::~KeyInput()
	{
		// Empty
	}

	void KeyInput::AttachCallback( KeyboardCallbackFn pFunc, Type type )
	{
		NR_CORE_ASSERT( pFunc, "Unexpected Error : Failed to called a AttachCallback Function." );
		int indices = static_cast<int>( type );
		m_Callbacks[indices] = nullptr;
		m_Callbacks[indices] = pFunc;
	}

	void KeyInput::DetachCallback( Type type )
	{
		int indices = static_cast<int>( type );
		m_Callbacks[indices] = nullptr;
	}

	void KeyInput::OnEvent( Normal::Event& event )
	{
		EventDispatcher dispatcher( event );

		// TODO : Category로 바꿀 지 고민해보기
		// TODO : KeyRelease 기능 구현
		switch ( event.GetEventType() )
		{
			case EventType::KeyPressed:
			{
				dispatcher.Dispatch<KeyPressedEvent>( BIND_EVENT_FUNC( KeyInput::IsPressed ) );
				return;
			} break;
			/*case EventType::KeyReleased:
			{	dispatcher.Dispatch<KeyReleasedEvent>( BIND_EVENT_FUNC( Keyboard::IsReleased ) );
				return;
			} break;*/
		}
	} // scope = void Keyboard::OnEvent( Normal::Event& event )

	bool KeyInput::IsPressed( KeyPressedEvent& event ) const
	{
		int type = static_cast<int>( Type::IsPressed );
		if ( m_Callbacks[type] != nullptr )
		{
			m_Callbacks[type]( { event.GetKeyCode(), event.GetRepeatCount() } );
			return true;
		}
		return false;
	}

	//bool Keyboard::IsReleased( KeyReleasedEvent& event ) const
	//{
	//	int type = static_cast<int>( Type::IsReleased );
	//	if ( m_Callbacks[type] != nullptr )
	//	{
	//		m_Callbacks[type]( { event.GetKeyCode(), 0 } );
	//		return true;
	//	}
	//	return false;
	//}


} // namepsace Normal