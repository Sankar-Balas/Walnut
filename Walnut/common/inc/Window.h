#pragma once

#include "wlpch.h"
#include "Core.h"
#include "..\events\Event.h"

namespace Walnut
{
	struct WindowProperty
	{
		unsigned int m_height;
		unsigned int m_Width;
		std::string m_Title;
		WindowProperty(const std::string& title = "Progress", unsigned int height = 800, unsigned int width = 400) :
			m_Title(title), m_height(height), m_Width(width)
		{}
	};

	// Window - Interface

	class WALNUT_API Window
	{
	protected:
		using EventCallbackFunc = std::function<void(Event&)>;

	public:
		virtual void OnUpdate() const = 0;
		virtual unsigned int GetWindowHeight() const = 0;
		virtual unsigned int GetWindowWidth() const = 0;
		virtual void SetVSync(bool enabled)  = 0;
		virtual bool IsVSync() const = 0;
		virtual void SetEventCallback(const EventCallbackFunc& event ) = 0;		
		virtual ~Window() {}
		static Window* Create(WindowProperty& wp = WindowProperty());
	};
}