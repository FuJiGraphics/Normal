#pragma once

#include "Core.h"
#include "Normal/Events/Event.h"

#include "Normal/InputManager/WindowInput.h"
#include "Normal/InputManager/MouseInput.h"
#include "Normal/InputManager/KeyInput.h"

namespace Normal {

	class NORMAL_API Level
	{
	public:
		Level() { }
		virtual ~Level() { }

		virtual void OnAttach() {};
		virtual void OnDetach() {};

		virtual void OnEvent( Event& event ) {};
		virtual void OnUpdate( float deltaTime ) {};
		virtual void OnGuiRender() {};

		virtual std::string GetName() const { return NR_GET_NAME; }

	protected:
		inline static WindowInput& s_WindowInput = WindowInput::GetInstance();
		inline static MouseInput& s_MouseInput = MouseInput::GetInstance();
		inline static KeyInput& s_KeyboardInput = KeyInput::GetInstance();

	private:
		NR_SET_NAME( "Level" );
	};

} // namespace Normal