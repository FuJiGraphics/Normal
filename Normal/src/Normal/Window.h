#pragma once

#include "Core.h"

#include "Event/Event.h"

namespace Normal {

	struct WindowProps
	{
		std::string Title;
		unsigned int Width;
		unsigned int Height;
		
		WindowProps( const std::string& title = "Normal Engine",
					 unsigned int width = 1280,
					 unsigned int height = 720 )
			: Title(title), Width(width), Height(height)
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
		
		virtual unsigned int GetWidth() const = 0;
		virtual unsigned int GetHeight() const = 0;

		// Window attributes
		virtual void SetEventCallBack( const EventCallbackFn& callback ) = 0;
		virtual void SetVSync( bool enabled ) = 0;
		virtual bool IsVSync() const = 0;

		// Create Function is need to define into the Platform Layer
		static Window* Create( const WindowProps& props = WindowProps() );
	};


} // namespace Normal