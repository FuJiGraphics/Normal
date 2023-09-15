#pragma once

#include "Core.h"

#include <Normal/Core/NrPointer.h>
#include <Normal/InputManager/WindowInput.h>

namespace Normal {
	
#pragma region Forward
	// Forward Declerations
	class Window;
	class Level;
	class ImGuiLevel;
	class LevelContainer;
	class Event;
	class WindowInput;
	class Shader;
	class Timer;
	struct WindowInputData;

	class VertexArray;
	class VertexBuffer;
	class IndexBuffer;
#pragma endregion

	class NORMAL_API Application
	{
	protected:
		using super = Application;

	protected:
		explicit Application();
	public:
		virtual ~Application();

	public:
		void Run();
		void OnEvent( Event& event );

		void AttachLevel( Level* level );
		void DetachLevel( Level* level );
		void AttachOverlay( Level* overlay );
		void DetachOverlay( Level* overlay );

		void OnWindowClose( WindowInputData input );
		void OnWindowResize( WindowInputData input );

	public:
		inline static Application& GetInstance() { return *s_Instance; }
		inline Window& GetWindow() const { return *m_Window; }

	protected:
		void Initialize();
		void Destroy();

	private:
		inline static Application* s_Instance = nullptr;
		
		bool		m_Running	 = true;
		ImGuiLevel* m_ImGuiLevel = nullptr;

		NrPtr<Timer>				m_Timer;
		NrPtr<Window>				m_Window;
		NrPtr<LevelContainer>		m_LevelContainer;
		
		WindowInput m_WindowInput;

		NR_SET_NAME( "Application" );
	};

	// To be defined in CLIENT
	Application* CreateApplication();

} // namespace Normal
