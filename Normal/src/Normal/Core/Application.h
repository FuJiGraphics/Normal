#pragma once
#include "Core.h"

#include <iostream>

namespace Normal {
	
	class Window;
	class Event;
	class WindowCloseEvent;
	class Module;

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

		// std::vector<Module&> m_Modules;
	};

	// To be defined in CLIENT
	Application* CreateApplication();

} // namespace Normal
