#pragma once

#include "Normal\Window.h"

namespace Normal
{
	class WindowsWindow : public Window
	{
	public:
		WindowsWindow( const WindowProps& props );
		virtual ~WindowsWindow() {};

		virtual void OnUpdate() override;

		virtual inline unsigned int GetWidth() const override { return m_Width; }
		virtual inline unsigned int GetHeight() const override { return m_Height; }

		// Window attributes
		virtual void SetEventCallBack( const EventCallbackFn& callback ) override;
		virtual void SetVSync( bool enabled ) override;
		virtual bool IsVSync() const override;

	private:
		unsigned int m_Width;
		unsigned int m_Height;
		std::string m_Title;

	};



} // namespace Normal

