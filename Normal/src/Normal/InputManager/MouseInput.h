#pragma once

#include "Normal/Core/Core.h"
#include "InputManager.h"

namespace Normal {

#pragma region Forward
	class Event; 
	class MouseButtonPressedEvent;
	class MouseButtonReleasedEvent;
	class MouseScrolledEvent;
	class MouseMovedEvent;
#pragma endregion

	struct MouseInputData {
		int keycode;
		float xOffset;
		float yOffset;
	};
	
	/* ------------------------------------------------------------------------------------------
	* MouseInput class
	* If you are using the Mouse class, you need to call the GetInstance() function first.
	* You need to periodically call the 'OnEvent' function, inserting the event argument first.
	* Afterwards, you can bind each function for use with the 'AttachCallback()' function 
	* via the 'BIND_EVENT_FUNC' macro. However, you must use a function that includes 
	* the 'MouseInputData' argument.
	* ------------------------------------------------------------------------------------------ */
	class NORMAL_API MouseInput : public InputManager <MouseInput>
	{
	public:
		enum class Type : int {
			IsPressed, IsReleased, IsScrolled, IsMoved,
			MAX_SIZE
		};
		using MouseCallbackFn = std::function<void( MouseInputData )>;

	public:
		MouseInput();
		virtual ~MouseInput();

		void AttachCallback( MouseCallbackFn pFunc, Type type );
		void DetachCallback( Type type );

		virtual void OnEvent( Event& event ) override;

	protected:
		bool IsPressed( MouseButtonPressedEvent& event ) const;
		bool IsReleased( MouseButtonReleasedEvent& event ) const;
		bool IsScrolled( MouseScrolledEvent& event ) const;
		bool IsMoved( MouseMovedEvent& event ) const;

	private:
		MouseCallbackFn m_Callbacks[static_cast<int>( Type::MAX_SIZE )];

		NR_SET_NAME( "MouseInput" );
	};

} // namespace Normal
