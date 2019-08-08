#pragma once

#include "wlpch.h"
#include "Core.h"


namespace Walnut
{
	enum class EventType
	{
		None = 0,
		WindowClose, WindowResize, WindowFocus, WindowLostFocus, WindowMoved,
		AppTick, AppUpdate, AppRender,
		KeyPressed, KeyReleased, KeyTyped,
		MouseButtonPressed, MouseButtonReleased, MouseMoved, MouseScrolled
	};

	enum EventCategory
	{
		None = 0,
		EventcategoryApplication	= BIT(0), 
		EventCategoryInput			= BIT(1),
		EventCategoryKeyboard		= BIT(2),
		EventcategoryMouse			= BIT(3),	
		EventCatogoryMouseButton	= BIT(4)
	};

#define EVENT_CATEGORY(category) virtual int GetEventCategory() const override {return category;}
#define EVENT_TYPE(type)	virtual EventType GetEventType() const override {return EventType::##type;}\
							virtual const char* GetName() const override {return #type;}\
							static EventType GetStaticType() { return EventType::##type; }


	class WALNUT_API Event
	{
		friend class EventDispatcher;
	public:
		virtual EventType GetEventType() const = 0;
		virtual int GetEventCategory() const = 0;
		virtual const char* GetName() const = 0;
		virtual std::string ToStringPlease() const { return GetName(); }
		inline bool IsIncategory(EventCategory EvnCategory) { return GetEventCategory() & EvnCategory; }
	private:
		bool m_handled = false;
	};

	class EventDispatcher 
	{
	private:
		Event &m_event;
	public:
		template<typename T>
		using EventFunc = std::function<bool(T&)>;		
		EventDispatcher(Event& event) :m_event(event) {}

		template<typename T>
		bool dispatchtoEvent(EventFunc <T> func)
		{
			if (m_event.GetEventType() == T::GetStaticType())
			{
				m_event.m_handled = func(*(T*)&m_event);
				return true;
			}
			return false;
		}


	};

	inline std::ostream& operator <<(std::ostream& ss, const Event& e) 
	{
		return ss << e.ToStringPlease();
	}

	
}