#pragma once

#include "Core.h"

#include "Normal/Events/Event.h"

namespace Normal {

	struct WindowProps
	{
		std::string Title;
		NRuint Width;
		NRuint Height;

		bool VSync;

		WindowProps( const std::string& title = "Normal Engine",
					 NRuint width = 1280,
					 NRuint height = 720 )
			: Title(title), Width(width), Height(height), VSync(false)
		{
			// Empty
		}
	};


	class NORMAL_API Window
	{
	public:
		using EventCallbackFn = std::function<void( Event& )>;

		virtual ~Window() {}

		virtual void OnUpdate() = 0;
		
		virtual void* GetNativeWindow() const = 0;
		virtual NRuint GetWidth() const = 0;
		virtual NRuint GetHeight() const = 0;

		// Window attributes
		virtual void SetEventCallback( const EventCallbackFn& callback ) = 0;
		virtual void SetVSync( bool enabled ) = 0;
		virtual bool IsVSync() const = 0;

		// Create Function is need to define into the Platform
		static Window* Create( const WindowProps& props = WindowProps() );
	};


} // namespace Normal