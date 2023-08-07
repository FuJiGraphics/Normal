#pragma once
#include "Normal/Core/Window.h"

struct GLFWwindow;


namespace Normal {

	class RenderContext;

	class NORMAL_API WindowsWindow : public Window
	{
	public:
		WindowsWindow( const WindowProps& props );
		virtual ~WindowsWindow();

		virtual void OnUpdate() override;

		virtual inline void* GetNativeWindow() const override { return static_cast<void*>( m_Window ); }
		virtual inline uint32_t GetWidth() const override { return m_Data.Width; }
		virtual inline uint32_t GetHeight() const override { return m_Data.Height; }

		// if you set many callback functions, maybe increase that overhead.
		virtual inline void SetEventCallback( const EventCallbackFn& callback ) override
		{ m_Data.Callbacks.push_back( callback ); }
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
			std::vector<EventCallbackFn> Callbacks;
		};

		WindowData m_Data;

	private:
		bool m_GLFWinitialized = false;
		GLFWwindow* m_Window = nullptr;

	private:
		std::unique_ptr<RenderContext> m_RenderContext;

		NR_SET_NAME( "WindowsWindow" );
	};

} // namespace Normal

