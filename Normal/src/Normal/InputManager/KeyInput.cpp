#include "Nrpch.h"
#include "KeyInput.h"

#include <GLFW/glfw3.h>

#include <Normal/Core/Window.h>
#include <Normal/Core/Application.h>

#include <Normal/Core/Window.h>

#include <Normal/Events/Event.h>
#include <Normal/Events/KeyEvent.h>

namespace Normal {

	KeyInput::KeyInput()
	{
		NR_CORE_INFO_CTOR;
	}


	KeyInput::~KeyInput()
	{
		NR_CORE_INFO_DTOR;
	}

	void KeyInput::AttachCallback( KeyboardCallbackFn pFunc, Type type )
	{
		NR_CORE_ASSERT( pFunc, "Unexpected Error : Failed to called a AttachCallback Function." );
		int indices = static_cast<int>( type );
		m_Callbacks[indices] = nullptr;
		m_Callbacks[indices] = pFunc;
	}

	void KeyInput::DetachCallback( Type type )
	{
		int indices = static_cast<int>( type );
		m_Callbacks[indices] = nullptr;
	}

	bool KeyInput::IsKeyPreesed( NRuint keycode ) // static
	{
		auto& app = Application::GetInstance();
		auto nativeWindow = static_cast<GLFWwindow*>( app.GetWindow().GetNativeWindow() );
		auto state = glfwGetKey( nativeWindow, keycode );
		return state == GLFW_PRESS || state == GLFW_REPEAT;
	}

	bool KeyInput::IsKeyPreesed( char keycode ) // static
	{
		return IsKeyPreesed( static_cast<NRuint>( keycode ) );
	}

	void KeyInput::OnEvent( Normal::Event& event )
	{
		EventDispatcher dispatcher( event );

		// TODO : Category로 바꿀 지 고민해보기
		// TODO : KeyRelease 기능 구현
		switch ( event.GetEventType() )
		{
			case EventType::KeyPressed:
			{
				dispatcher.Dispatch<KeyPressedEvent>( BIND_EVENT_FUNC( KeyInput::IsPressed ) );
				return;
			} break;
			case EventType::KeyReleased:
			{	dispatcher.Dispatch<KeyReleasedEvent>( BIND_EVENT_FUNC( KeyInput::IsReleased ) );
				return;
			} break;
			case EventType::KeyTyped:
			{	dispatcher.Dispatch<KeyTypedEvent>( BIND_EVENT_FUNC( KeyInput::IsTyped ) );
			return;
			} break;
		}
	} // scope = void Keyboard::OnEvent( Normal::Event& event )

	bool KeyInput::IsPressed( KeyPressedEvent& event ) const
	{
		int type = static_cast<int>( Type::IsPressed );
		if ( m_Callbacks[type] != nullptr )
		{
			m_Callbacks[type]( { event.GetKeyCode(), (int)event.GetRepeatCount() } );
			return false;
		}
		return false;
	}

	bool KeyInput::IsReleased( KeyReleasedEvent& event ) const
	{
		int type = static_cast<int>( Type::IsReleased );
		if ( m_Callbacks[type] != nullptr )
		{
			m_Callbacks[type]( { event.GetKeyCode(), 0 } );
			return false;
		}
		return false;
	}

	bool KeyInput::IsTyped( KeyTypedEvent& event ) const
	{
		int type = static_cast<int>( Type::IsTyped );
		if ( m_Callbacks[type] != nullptr )
		{
			m_Callbacks[type]( { event.GetKeyCode(), 0 } );
			return false;
		}
		return false;
	}


} // namepsace Normal