#pragma once

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
		virtual void OnUpdate( const float& dt ) {};
		virtual void OnGuiRender() {};

		virtual std::string GetName() const { return std::string(); }

	protected:
		inline static NRuint GetLevelCount() { return s_NumOfLevels; }

	private:
		inline static int s_NumOfLevels = 0;
	};

} // namespace Normal