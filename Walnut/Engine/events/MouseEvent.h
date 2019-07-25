#pragma once

#include "Event.h"
#include "..\wlpch.h"


namespace Walnut
{
	class WALNUT_API MouseButtonEvent :public Event
	{	
	protected:
		inline int GetMouseButton() { return m_Button; }
		MouseButtonEvent(int button) :m_Button(button) {}
		virtual int GetEventCategory() const override { return EventCategory::EventcategoryMouse | EventCategory::EventCategoryInput; }		
	private:
		int m_Button;
	};

	class WALNUT_API MouseButtonPressed :public MouseButtonEvent
	{
	public:
		MouseButtonPressed(int button) : MouseButtonEvent(button) {}	
		virtual EventType GetEventType() const override { return EventType::MouseButtonPressed; }
		virtual const char* GetName() const override { return "MouseButtonPresses"; }		
		virtual inline std::string ToStringPlease()
		{
			std::stringstream ss;
			ss << "MouseButtonPressed" << GetMouseButton() << std::endl;
			return ss.str();
		}
	};

	class WALNUT_API MouseButtonReleased :public MouseButtonEvent
	{
	public:
		MouseButtonReleased(int button) :MouseButtonEvent(button) {}
		virtual EventType GetEventType()const override { return EventType::MouseButtonReleased; }
		virtual const char* GetName() const override { return "MouseButtonReleased"; }		
		virtual inline std::string ToStringPlease()
		{
			std::stringstream ss;
			ss << "MouseButtonReleased" << GetMouseButton() << std::endl;
			return ss.str();
		}
	};
	
	class WALNUT_API MouseScrolled :public Event
	{
	private:
		float m_xPosition;
		float m_yPosition;
	public:
		MouseScrolled(int xPos, int yPos) : m_xPosition(xPos), m_yPosition(yPos) {}		
		virtual int GetEventCategory()const override { return EventCategory::EventcategoryMouse | EventCategory::EventCategoryInput; }
		inline float getXposition() const { return m_xPosition; }
		inline float getYposition() const { return m_yPosition; }
		virtual inline std::string ToStringPlease()
		{
			std::stringstream ss;
			ss << "MouseScrolled Event Position" << getXposition() << getYposition() << std::endl;
			return ss.str();
		}
		virtual EventType GetEventType() { return EventType::MouseScrolled; }
		virtual const char* GetName() { return "MouseScroll"; }
	};
	
	class WALNUT_API MouseMoved :public Event
	{
	private:
		float m_xPosition;
		float m_yPosition;
	public:
		MouseMoved(float xPos, float yPos) : m_xPosition(xPos), m_yPosition(yPos) {}
		virtual int GetEventCategory() const override
		{
			return EventCategory::EventcategoryMouse | EventCategory::EventCategoryInput;
		}
		inline float getXposition() const { return m_xPosition; }
		inline float getYposition() const { return m_yPosition; }
		inline std::string ToStringPlease()
		{
			std::stringstream ss;
			ss << "MouseMoved Event Position" << getXposition() << getYposition() << std::endl;
			return ss.str();
		}

		virtual EventType GetEventType() { return EventType::MouseMoved; }
		virtual const char* GetName() { return "MouseMove"; }
	};
}