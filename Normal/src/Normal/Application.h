#pragma once
#include "Core.h"

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
		bool m_Running;
	};

	// To be defined in CLIENT
	Application* CreateApplication();

} // namespace Normal
