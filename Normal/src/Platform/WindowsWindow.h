#pragma once
#include "Normal/Core/Window.h"

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

		// if you set many callback functions, maybe increase that overhead.
		virtual inline void SetEventCallback( const EventCallbackFn& callback ) override
		{ m_Data.Callbacks.push_back( callback ); }
		virtual void SetVSync( bool enabled ) override;
		virtual inline bool IsVSync() const override { return m_Data.VSync; }

	protected:
		void Init( const WindowProps& props );
		void Destroy();
		void SetCallbacks() const;

	private:
		bool m_GLFWinitialized   = false;
		GLFWwindow* m_Window     = nullptr;

	private:
		struct WindowData
		{
			std::string Title;
			uint32 Width;
			uint32 Height;
			bool VSync;

			std::vector<EventCallbackFn> Callbacks;
		};

		WindowData m_Data;
	};

} // namespace Normal

