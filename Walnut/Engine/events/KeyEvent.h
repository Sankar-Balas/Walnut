#pragma once

#include "Event.h"
#include <sstream>
#include <string.h>

namespace Walnut
{
	class WALNUT_API KeyEvent :public Event
	{	
	protected:
		int m_KeyCode;
		KeyEvent(int Keycode) :m_KeyCode(m_KeyCode) {}
	public:
		inline int GetKeyCode() const { return m_KeyCode; }
		virtual int GetEventCategory() const override 
		{
			return EventCategory::EventCategoryInput | EventCategory::EventCategoryKeyboard;
		}
	};

	class WALNUT_API KeyPressedEvent : public KeyEvent
	{
	public:			
		KeyPressedEvent(int keyCode) :KeyEvent(keyCode) {}
		EventType GetEventType() const override{ 
			return EventType::KeyPressed;
		}
		
		const char* GetName() const override {
			return "KeyPressed";
		}		
		
		std::string ToStringPlease() const override
		{
			std::stringstream os;
			os << "KeyPressedEvent" << m_KeyCode << std::endl;
			return os.str();
		}
	};

	class WALNUT_API KeyReleasedEvent : public KeyEvent
	{
	public:
		KeyReleasedEvent(int KeyCode) :KeyEvent(KeyCode) {}
		EventType GetEventType() const override {
			return EventType::KeyReleased;
		}
		const char* GetName() const override {
			return "Key Released";
		}

		std::string ToStringPlease() const override
		{
			std::stringstream ss;
			ss << "KeyReleaseEvent" << m_KeyCode << std::endl;
			return ss.str();
		}
	};

	class WALNUT_API KeyTypedEvent : public KeyEvent
	{
	public:
		KeyTypedEvent(int keycode) :KeyEvent(keycode) {}		
		EventType GetEventType() const override {
			return EventType::KeyTyped;}
		
		const char* GetName() const override {
			return "KeyTypedEvent";}

		std::string ToStringPlease() const override
		{
			std::stringstream ss;
			ss << "KeyTypedEvent" << m_KeyCode << std::endl;
			return ss.str();
		}
	};
}