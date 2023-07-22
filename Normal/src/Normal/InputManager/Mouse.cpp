#include "Nrpch.h"
#include "Mouse.h"

#include "Normal/Core/Window.h"

#include "Normal/Events/Event.h"
#include "Normal/Events/MouseEvent.h"

namespace Normal {

	bool Mouse::IsPressed( MouseButtonPressedEvent& button ) const
	{
		NR_CORE_LINE_TRACE( "{0}", button );

		return true;
	}

	void Mouse::OnEvent( Normal::Event& event )
	{
		EventDispatcher dispatcher( event );
		dispatcher.Dispatch<MouseButtonPressedEvent>( BIND_EVENT_FN( Mouse::IsPressed ) );

	}

} // namespace Normal

