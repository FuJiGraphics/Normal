#pragma once
#include "Core.h"

#include <iostream>

namespace Normal {
	
	class Window;

	class NORMAL_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();

	private:
		std::unique_ptr<Window> m_Window;
		bool m_Running = true;
	};

	// To be defined in CLIENT
	Application* CreateApplication();

} // namespace Normal
