#include "Nrpch.h"
#include "Keyboard.h"

#include "Normal/Core/Window.h"

#include "Normal/Events/Event.h"
#include "Normal/Events/KeyEvent.h"

namespace Normal {

	Keyboard::Keyboard()
	{
		// Empty
	}


	Keyboard::~Keyboard()
	{
		// Empty
	}

	bool Keyboard::IsPressed( KeyPressedEvent& button ) const
	{
		NR_CORE_TRACE( "[{0}] Pressed = {1}", NR_GET_NAME, button.ToString() );
		return false;
	}

	bool Keyboard::IsReleased( KeyReleasedEvent& button ) const
	{
		NR_CORE_TRACE( "[{0}] Released = {1}", NR_GET_NAME, button.ToString() );
		return false;
	}

	void Keyboard::OnEvent( Event& event )
	{
		EventDispatcher dispatcher( event );

		switch ( event.GetEventType() )
		{
			case EventType::KeyPressed:
			{
				dispatcher.Dispatch<KeyPressedEvent>( BIND_EVENT_FUNC( Keyboard::IsPressed ) );
			} break;
			case EventType::KeyReleased:
			{
				dispatcher.Dispatch<KeyReleasedEvent>( BIND_EVENT_FUNC( Keyboard::IsReleased ) );
			} 
		}

	}

} // namepsace Normal