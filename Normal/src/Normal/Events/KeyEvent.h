#pragma once

// Code Reference By https://github.com/TheCherno/Hazel.git

#include "Event.h"

#include <sstream>

namespace Normal {

class NORMAL_API KeyEvent : public Event
{
public:
	inline int GetKeyCode() const { return m_KeyCode; }

	EVENT_CLASS_CATEGORY( EventCategoryKeyboard | EventCategoryInput )
protected:
	KeyEvent( int keycode )
		: m_KeyCode( keycode ) {}

	int m_KeyCode;
};

class NORMAL_API KeyPressedEvent : public KeyEvent
{
public:
	KeyPressedEvent( int keycode, NRuint64 repeatCount = 0 )
		: KeyEvent( keycode ), m_RepeatCount( repeatCount ) {}

	inline NRuint64 GetRepeatCount() const { return m_RepeatCount; }

	std::string ToString() const override
	{
		std::stringstream ss;
		ss << "KeyPressedEvent: " << m_KeyCode << " (" << m_RepeatCount << " repeats)";
		return ss.str();
	}

	EVENT_CLASS_TYPE( KeyPressed )
private:
	NRuint64 m_RepeatCount;
};

class NORMAL_API KeyReleasedEvent : public KeyEvent
{
public:
	KeyReleasedEvent( int keycode )
		: KeyEvent( keycode ) {}

	std::string ToString() const override
	{
		std::stringstream ss;
		ss << "KeyReleasedEvent: " << m_KeyCode;
		return ss.str();
	}

	EVENT_CLASS_TYPE( KeyReleased )
};


class NORMAL_API KeyTypedEvent : public KeyEvent
{
public:
	KeyTypedEvent( int keycode )
		: KeyEvent( keycode ) {}

	std::string ToString() const override
	{
		std::stringstream ss;
		ss << "KeyTypedEvent: " << m_KeyCode;
		return ss.str();
	}

	EVENT_CLASS_TYPE( KeyTyped )
};
} // namepsace Normal