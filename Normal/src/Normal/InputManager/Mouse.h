#pragma once

#include "InputManager.h"

namespace Normal {

#pragma region Forward
	class Event; 
	class Window;
	class MouseButtonPressedEvent;
#pragma endregion

	class NORMAL_API Mouse : public InputManager <Mouse>
	{
	public:
		Mouse();
		virtual ~Mouse();

		bool IsPressed( MouseButtonPressedEvent& button ) const;
		// TODO : ���콺 ��ư ���°� �����ϱ�.
	protected:
		virtual void OnEvent( Event& event ) override;
	};

} // namespace Normal
