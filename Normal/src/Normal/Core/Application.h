#pragma once

#include "Core.h"

#include <iostream>

namespace Normal {
	
#pragma region Forward
	// Forward Declerations
	class Window;
	class Level;
	class LevelContainer;
	class Event;
	class WindowInput;
	struct WindowInputData;
#pragma endregion

	class NORMAL_API Application
	{
	protected:
		typedef Application super;

	public:
		Application();
		virtual ~Application();

		void Run();

		void AttachLevel( Level* level );
		void DetachLevel( Level* level );
		void AttachOverlay( Level* overlay );
		void DetachOverlay( Level* overlay );

		void OnEvent( Event& event );
		void OnWindowClose( WindowInputData input );

	public:
		inline static Application& GetInstance() { return *s_Instance; };
		inline Window& GetWindow() const { return *m_Window; }

	private:
		inline static Application* s_Instance = nullptr;

		std::unique_ptr<Window> m_Window;
		WindowInput& m_WindowInput;

		LevelContainer* m_LevelContainer = nullptr;

		bool m_Running = true;
		double m_Time = 0.0;
	};

	// To be defined in CLIENT
	Application* CreateApplication();

} // namespace Normal
