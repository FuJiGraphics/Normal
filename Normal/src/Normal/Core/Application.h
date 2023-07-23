#pragma once

#include "Core.h"

#include <iostream>

namespace Normal {
	
#pragma region Forward
	// Forward Declerations
	class Window;
	class Event;
	class WindowCloseEvent;
	class Module;
	class ModuleContainer;
#pragma endregion

	class NORMAL_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();

	protected:
		void OnEvent( Event& event );
		bool OnWindowClose( WindowCloseEvent& event );

	private:
		bool m_Running = true;
		std::unique_ptr<Window> m_Window;
		// std::unique_ptr<LevelContainer> m_LevelContainer;
	};

	// To be defined in CLIENT
	Application* CreateApplication();

} // namespace Normal
