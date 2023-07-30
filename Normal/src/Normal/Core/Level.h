#pragma once

#include "Core.h"
#include "Normal/Events/Event.h"

#include "Normal/InputManager/WindowInput.h"
#include "Normal/InputManager/MouseInput.h"
#include "Normal/InputManager/KeyInput.h"

namespace Normal {

	class NORMAL_API Level
	{
	protected:
		inline static WindowInput& s_WindowInput = WindowInput::GetInstance();
		inline static MouseInput& s_MouseInput = MouseInput::GetInstance();
		inline static KeyInput& s_KeyboardInput = KeyInput::GetInstance();
	
	public:
		Level() { }
		virtual ~Level() { }

		virtual void OnAttach() {};
		virtual void OnDetach() {};

		virtual void OnEvent( Event& event ) {};
		virtual void OnUpdate( float deltaTime ) {};
		virtual void OnRender() {};

		virtual std::string GetName() const { return NR_GET_NAME; }
	private:
		NR_SET_NAME( "Level" );
	};

} // namespace Normal