#pragma once

#include "Normal/Core/Core.h"
#include "InputManager.h"

namespace Normal {

#pragma region Forward
	class Event;
	class WindowResizeEvent;
	class WindowCloseEvent;
	class AppTickEvent;
	class AppUpdateEvent;
	class AppRenderEvent;
#pragma endregion

	/* ------------------------------------------------------------------------------------------
	* MouseInput class
	* If you are using the Mouse class, you need to call the GetInstance() function first.
	* You need to periodically call the 'OnEvent' function, inserting the event argument first.
	* Afterwards, you can bind each function for use with the 'AttachCallback()' function
	* via the 'BIND_EVENT_FUNC' macro. 
	* ------------------------------------------------------------------------------------------ */
	class NORMAL_API WindowInput : public InputManager <WindowInput>
	{
	public:
		enum class Type : int {
			IsResized, IsClosed, AppTick, AppUpdate, AppRender,
			MAX_SIZE
		};
		using WindowCallbackFn = std::function<void( void )>;

	public:
		WindowInput();
		virtual ~WindowInput();

		void AttachCallback( WindowCallbackFn pFunc, Type type );
		void DetachCallback( Type type );

		virtual void OnEvent( Event& event ) override;

	protected:
		bool IsResizedWindow( WindowResizeEvent& event ) const;
		bool IsClosedWindow( WindowCloseEvent& event ) const;
		bool IsAppTickWindow( AppTickEvent& event ) const;
		bool IsAppUpdateWindow( AppUpdateEvent& event ) const;
		bool IsAppRenderWindow( AppRenderEvent& event ) const;

	private:
		WindowCallbackFn m_Callbacks[static_cast<int>( Type::MAX_SIZE )];

		NR_SET_NAME( "WindowInput" );
	};

} // namespace Normal
