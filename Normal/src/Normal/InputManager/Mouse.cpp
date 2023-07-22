#include "Nrpch.h"
#include "Mouse.h"

#include "Normal/Core/Window.h"

#include "Normal/Events/Event.h"
#include "Normal/Events/MouseEvent.h"

namespace Normal {

	bool Mouse::IsPressed( MouseButtonPressedEvent& button ) const
	{

		/*switch ( button )
		{
			case Left:
			{

			}break;
			case Right:
			{

			}break;
			case Scroll:
			{

			}break;
		}*/

		return true;
	}

	void Mouse::OnEvent( Normal::Event& event )
	{
		EventDispatcher dispatcher( event );
		dispatcher.Dispatch<MouseButtonPressedEvent>( BIND_EVENT_FN( Mouse::IsPressed ) );

	}

} // namespace Normal

