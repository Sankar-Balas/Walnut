#pragma once

#include "Core.h"
#include "..\wlpch.h"


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
							virtual const char* GetName() const override {return #type;}


	class WALNUT_API Event
	{
	public:
		virtual EventType GetEventType() const = 0;
		virtual int GetEventCategory() const = 0;
		virtual const char* GetName() const = 0;
		virtual std::string ToStringPlease() const { return GetName(); }
		inline bool IsIncategory(EventCategory EvnCategory) { return GetEventCategory() & EvnCategory; }
	};

	inline std::ostream& operator <<(std::ostream& ss, const Event& e) 
	{
		return ss << e.ToStringPlease();
	}
}