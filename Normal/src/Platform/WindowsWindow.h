#pragma once
#include "./Normal/Window.h"

#include <GLFW\glfw3.h>

namespace Normal {

	class WindowsWindow : public Window
	{
	public:
		WindowsWindow( const WindowProps& props );
		virtual ~WindowsWindow();

		virtual void OnUpdate() override;

		virtual inline uint32_t GetWidth() const override { return m_Data.Width; }
		virtual inline uint32_t GetHeight() const override { return m_Data.Height; }

		// Window attributes
		virtual inline void SetEventCallBack( const EventCallbackFn& callback ) override 
		{ m_Data.Callback = callback; }
		virtual void SetVSync( bool enabled ) override;
		virtual inline bool IsVSync() const override { return m_Data.VSync; }

	protected:
		void Init( const WindowProps& props );
		void Destroy();

	private:
		bool m_GLFWinitialized   = false;
		GLFWwindow* m_Window     = nullptr;

	private:
		struct WindowData
		{
			std::string Title;
			uint32_t Width;
			uint32_t Height;
			bool VSync;

			EventCallbackFn Callback;
		};

		WindowData m_Data;
	};

} // namespace Normal

