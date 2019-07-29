#pragma once
#include "Event.h"
#include "..\wlpch.h"

namespace Walnut
{
	class WALNUT_API WindowResizeEvent :public Event
	{
	private:
		float m_Height, m_Width;

	public:
		WindowResizeEvent(float height, float width) :m_Height(height), m_Width(width) {}
		virtual EventType GetEventType() const override { return GetStaticType(); }
		virtual int GetEventCategory() const override { return EventCategory::EventcategoryApplication; }
		virtual const char* GetName() const override { return "WindowResize"; }
		

		static EventType GetStaticType() { return EventType::WindowResize; }
		//EVENT_CATEGORY(EventcategoryApplication)
		//EVENT_TYPE(WindowResize)
							
							

		inline float GetHeight()const { return m_Height; }
		inline float GetWidth()const { return m_Width; }

	};

	class WALNUT_API WindowCloseEvent : public Event
	{
	public:
		WindowCloseEvent() {}
		virtual inline EventType GetEventType() const override { return  GetStaticType(); }
		virtual inline int GetEventCategory() const override { return EventCategory::EventcategoryApplication; }
		virtual inline const char* GetName() { return "WindowClose"; }
		static EventType GetStaticType() {return EventType::WindowClose;}
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
		virtual inline EventType GetEventType() const override { return GetStaticType(); }
		virtual inline int GetEventCategory() const override { return EventCategory::EventcategoryApplication; }
		virtual inline const char* GetName() { return "AppTickEvent"; }
		static EventType GetStaticType() { return EventType::AppTick; }
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

		virtual inline EventType GetEventType() const override { return GetStaticType(); }
		virtual inline int GetEventCategory() const override { return EventCategory::EventcategoryApplication; }
		virtual inline const char* GetName() { return "AppUpdateEvent"; }
		static EventType GetStaticType() { return EventType::AppUpdate; }
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

		virtual inline EventType GetEventType() const override { return GetStaticType(); }
		virtual inline int GetEventCategory() const override { return EventCategory::EventcategoryApplication; }
		virtual inline const char* GetName() { return "AppRenderEvent"; }
		static EventType GetStaticType() { return EventType::AppRender; }
		virtual inline std::string ToStringPlease()
		{
			std::stringstream ss;
			ss << "AppRenderEvent" << std::endl;
			return ss.str();
		}
	};
}




