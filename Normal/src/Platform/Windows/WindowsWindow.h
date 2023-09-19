#pragma once
#include "Normal/Core/Window.h"

struct GLFWwindow;

namespace Normal {

	class RenderContext;

	class NORMAL_API WindowsWindow : public Window
	{
	public:
		explicit WindowsWindow( const WindowProps& props );
		virtual ~WindowsWindow();

	public:
		virtual void OnUpdate() override;

		virtual inline void* GetNativeWindow() const override { return static_cast<void*>( m_Window ); }
		virtual inline uint32_t GetWidth() const override { return m_Data.Width; }
		virtual inline uint32_t GetHeight() const override { return m_Data.Height; }
		virtual void SetWindowSize( float width, float height ) override;

		// if you set many callback functions, maybe increase that overhead.
		virtual inline void SetEventCallback( const EventCallbackFn& callback ) override
		{ m_Data.Callback = callback; }
		virtual void SetVSync( bool enabled ) override;
		virtual inline bool IsVSync() const override { return m_Data.VSync; }

	protected:
		void Initialize( const WindowProps& props );
		void Destroy();
		void SetCallbacks() const;

	private:
		struct WindowData {
			std::string Title;
			NRuint Width;
			NRuint Height;
			bool VSync;
			EventCallbackFn Callback;
		};

		WindowData m_Data;

	private:
		bool m_GLFWinitialized = false;
		GLFWwindow* m_Window = nullptr;

	private:
		Own::Share<RenderContext> m_RenderContext;

		NR_SET_NAME( "WindowsWindow" );
	};

} // namespace Normal

