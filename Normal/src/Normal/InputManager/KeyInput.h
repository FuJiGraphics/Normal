#pragma once

#include "Normal/Core/Core.h"
#include "InputManager.h"

namespace Normal {

#pragma region Forward
	class KeyPressedEvent;
	class KeyReleasedEvent;
	class KeyTypedEvent;
#pragma endregion

	struct KeyInputData {
		int keycode;
		int repeatCount;
	};

	/* ------------------------------------------------------------------------------------------
	* Keyboard Input class
	* If you are using the Mouse class, you need to call the GetInstance() function first.
	* You need to periodically call the 'OnEvent' function, inserting the event argument first.
	* Afterwards, you can bind each function for use with the 'AttachCallback()' function
	* via the 'BIND_EVENT_FUNC' macro. However, you must use a function that includes
	* the 'KeyboardInput' argument.
	------------------------------------------------------------------------------------------ */
	class NORMAL_API KeyInput : public InputManager <KeyInput>
	{
	public:
		enum class Type : int {
			IsPressed, IsReleased, IsTyped,
			MAX_SIZE
		};
		using KeyboardCallbackFn = std::function<void( KeyInputData )>;

	public:
		KeyInput();
		virtual ~KeyInput();

		void AttachCallback( KeyboardCallbackFn pFunc, Type type );
		void DetachCallback( Type type );

		// Polling Keycode 
		bool IsKeyPreesed( uint32 keycode ) const;
		bool IsKeyPreesed( char keycode ) const;

		virtual void OnEvent( Event& event ) override;

		inline void SetRepeatMode( bool enable ) { m_OnRepeatMode = enable; }
	protected:
		bool IsPressed( KeyPressedEvent& event ) const;
		bool IsReleased( KeyReleasedEvent& event ) const;
		bool IsTyped( KeyTypedEvent& event ) const;
		
	private:
		KeyboardCallbackFn m_Callbacks[static_cast<int>( Type::MAX_SIZE )];

		bool m_OnRepeatMode = true;

		NR_SET_NAME( "KeyInput" );
	};


} // namespace Normal

