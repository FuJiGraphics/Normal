#pragma once

// Code Reference By https://github.com/TheCherno/Hazel.git

#include "Event.h"

namespace Normal {

	class NORMAL_API WindowResizeEvent : public Event
	{
	public:
		WindowResizeEvent( int width, int height )
			: m_Width( width ), m_Height( height ) {}

		inline int GetWidth() const { return m_Width; }
		inline int GetHeight() const { return m_Height; }

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "WindowResizeEvent: " << m_Width << ", " << m_Height;
			return ss.str();
		}

		EVENT_CLASS_TYPE( WindowResize )
		EVENT_CLASS_CATEGORY( EventCategoryApplication )
	private:
		int m_Width, m_Height;
	};

	class NORMAL_API WindowCloseEvent : public Event
	{
	public:
		WindowCloseEvent() {}

		EVENT_CLASS_TYPE( WindowClose )
		EVENT_CLASS_CATEGORY( EventCategoryApplication )
	};

	class NORMAL_API AppTickEvent : public Event
	{
	public:
		AppTickEvent() {}

		EVENT_CLASS_TYPE( AppTick )
		EVENT_CLASS_CATEGORY( EventCategoryApplication )
	};

	class NORMAL_API AppUpdateEvent : public Event
	{
	public:
		AppUpdateEvent() {}

		EVENT_CLASS_TYPE( AppUpdate )
		EVENT_CLASS_CATEGORY( EventCategoryApplication )
	};

	class NORMAL_API AppRenderEvent : public Event
	{
	public:
		AppRenderEvent() {}

		EVENT_CLASS_TYPE( AppRender )
		EVENT_CLASS_CATEGORY( EventCategoryApplication )
	};


} // namespace Normal