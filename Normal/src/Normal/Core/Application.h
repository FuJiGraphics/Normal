#pragma once

#include "Core.h"

#include <iostream>

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
	struct WindowInputData;

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

	protected:
		void Initialize();
		void Destroy();

	public:
		inline static Application& GetInstance() { return *s_Instance; };
		inline Window& GetWindow() const { return *m_Window; }

	private:
		double m_Time = 0.0;
		bool m_Running = true;
		ImGuiLevel* m_ImGuiLevel = nullptr;

		inline static Application* s_Instance = nullptr;

	private:
		static WindowInput& s_WindowInput;

		std::unique_ptr<Window> m_Window;
		std::unique_ptr<LevelContainer> m_LevelContainer;

		std::shared_ptr<VertexBuffer> m_VertexBuffer;
		std::shared_ptr<IndexBuffer> m_IndexBuffer;
		std::unique_ptr<Shader> m_Shader;

		NR_SET_NAME( "Application" );
	};

	// To be defined in CLIENT
	Application* CreateApplication();

} // namespace Normal
