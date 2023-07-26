#pragma once

#include "Core.h"

#include <iostream>

namespace Normal {
	
#pragma region Forward
	// Forward Declerations
	class Window;
	class Event;
	class WindowCloseEvent;
	class Level;
	class LevelContainer;
#pragma endregion

	class NORMAL_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();

	protected:
		// TODO : �̺�Ʈ �ý��� �����ϱ�
		// TODO : �̺�Ʈ���� ���콺 ����
		void OnEvent( Event& event );
		bool OnWindowClose( WindowCloseEvent& event );

	private:
		bool m_Running = true;
		std::unique_ptr<Window> m_Window;
		LevelContainer* m_LevelContainer;

		double m_Time = 0.0;
	};

	// To be defined in CLIENT
	Application* CreateApplication();

} // namespace Normal
