#pragma once

#include "Normal/Core/Core.h"
#include "InputManager.h"

namespace Normal {
	// TODO : 키보드 인풋 매니저 만들기
#pragma region Forward
	class KeyPressedEvent;
	class KeyReleasedEvent;
#pragma endregion

	class Keyboard : public InputManager <Keyboard>
	{
	public:
		Keyboard();
		virtual ~Keyboard();

		bool IsPressed( KeyPressedEvent& button ) const;
		bool IsReleased( KeyReleasedEvent& button ) const;
	protected:
		virtual void OnEvent( Event& event ) override;

	private:
		NR_SET_NAME( "Keyboard" );
	};
} // namespace Normal

