#pragma once

#include "InputManager.h"

// TODO : Mouse Ŭ���� �ϼ��ϱ� 
namespace Normal {
	class Event; 
	class Window;
	class MouseButtonPressedEvent;

	class NORMAL_API Mouse : public InputManager <Mouse>
	{
	public:
		Mouse( const std::string& moduleName )
			: InputManager( moduleName ) 
		{
			// Empty
		}

		bool IsPressed( MouseButtonPressedEvent& button ) const;

	protected:
		virtual void OnEvent( Event& event ) override;
	};

} // namespace Normal
