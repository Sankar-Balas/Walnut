#pragma once
#include "Event.h"
#include <string>
#include <sstream>

namespace Walnut
{
	class WALNUT_API WindowResize :public Event
	{
	private:
		float m_Height, m_Width;

	public:
		WindowResize(float height, float width) :m_Height(height), m_Width(width) {}
		virtual inline EventType GetEventType() const override { return EventType::WindowResize ; }
		virtual inline int GetEventCategory() const override { return EventCategory::EventcategoryApplication; }
		virtual inline const char* GetName() { return "WindowResize"; }
		virtual inline std::string ToStringPlease()
		{
			std::stringstream ss;
			ss << "Window Resize" << m_Height << m_Width << std::endl;
			return ss.str();
		}

		inline float GetHeight()const { return m_Height; }
		inline float GetWidth()const { return m_Width; }

	};

	class WALNUT_API WindowCloseEvent : public Event
	{
	public:
		WindowCloseEvent() {}
		virtual inline EventType GetEventType() const override { return EventType::WindowClose; }
		virtual inline int GetEventCategory() const override { return EventCategory::EventcategoryApplication; }
		virtual inline const char* GetName() { return "WindowClose"; }
		virtual inline std::string ToStringPlease() 
		{
			std::stringstream ss;
			ss << "Window Close" << std::endl;
			return ss.str();	
		}
	};

	class WALNUT_API AppTickEvent : public Event
	{
	public:
		AppTickEvent() {}
		virtual inline EventType GetEventType() const override { return EventType::AppTick ; }
		virtual inline int GetEventCategory() const override { return EventCategory::EventcategoryApplication; }
		virtual inline const char* GetName() { return "AppTickEvent"; }
		virtual inline std::string ToStringPlease()
		{
			std::stringstream ss;
			ss << "AppTickEvent" << std::endl;
			return ss.str();
		}
	};

	class WALNUT_API AppUpdateEvent : public Event
	{
	public:
		AppUpdateEvent() {}

		virtual inline EventType GetEventType() const override { return EventType::AppUpdate; }
		virtual inline int GetEventCategory() const override { return EventCategory::EventcategoryApplication; }
		virtual inline const char* GetName() { return "AppUpdateEvent"; }
		virtual inline std::string ToStringPlease()
		{
			std::stringstream ss;
			ss << "AppUpdateEvent" << std::endl;
			return ss.str();
		}
	};

	class WALNUT_API AppRenderEvent : public Event
	{
	public:
		AppRenderEvent() {}

		virtual inline EventType GetEventType() const override { return EventType::AppRender ; }
		virtual inline int GetEventCategory() const override { return EventCategory::EventcategoryApplication; }
		virtual inline const char* GetName() { return "AppRenderEvent"; }
		virtual inline std::string ToStringPlease()
		{
			std::stringstream ss;
			ss << "AppRenderEvent" << std::endl;
			return ss.str();
		}
	};
}




