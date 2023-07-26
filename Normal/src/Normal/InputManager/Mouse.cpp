#include "Nrpch.h"
#include "Mouse.h"

#include "Normal/Core/Window.h"

#include "Normal/Events/Event.h"
#include "Normal/Events/MouseEvent.h"

namespace Normal {

	Mouse::Mouse()
	{
		NR_CORE_INFO("")
	}

	Mouse::~Mouse()
	{
		NR_CORE_INFO("")
	}

	bool Mouse::IsPressed( MouseButtonPressedEvent& button ) const
	{
		NR_CORE_TRACE( "[{0}] Pressed = {1}", NR_GET_NAME, button.ToString() );

		return true;
	}

	void Mouse::OnEvent( Normal::Event& event )
	{
		EventDispatcher dispatcher( event );
		dispatcher.Dispatch<MouseButtonPressedEvent>( BIND_EVENT_FUNC( Mouse::IsPressed ) );

	}

} // namespace Normal

