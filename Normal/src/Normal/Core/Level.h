#pragma once

#include "Core.h"

#include <Normal/Events/Event.h>

#include <Normal/InputManager/WindowInput.h>
#include <Normal/InputManager/MouseInput.h>
#include <Normal/InputManager/KeyInput.h>

namespace Normal {

	class NORMAL_API Level
	{
	protected:
		using super = Level;

	public:
		Level() { ++s_NumOfLevels; }
		virtual ~Level() { --s_NumOfLevels; }

		virtual void OnAttach() {};
		virtual void OnDetach() {};

		virtual void OnEvent( Event& event ) {};
		virtual void OnUpdate( float deltaTime ) {};
		virtual void OnGuiRender() {};

		virtual std::string GetName() const { return std::string(); }

	protected:
		inline static WindowInput& s_WindowInput = WindowInput::GetInstance();
		inline static MouseInput& s_MouseInput = MouseInput::GetInstance();
		inline static KeyInput& s_KeyboardInput = KeyInput::GetInstance();

		inline static NRuint GetLevelCount() { return s_NumOfLevels; }

	private:
		inline static int s_NumOfLevels = 0;
	};

} // namespace Normal