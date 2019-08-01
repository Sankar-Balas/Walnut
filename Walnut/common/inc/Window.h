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
		WindowProperty(const std::string& title = "Progress", unsigned int height = 1280, unsigned int width = 800) :
			m_Title(title), m_height(height), m_Width(width)
		{}
	};

	// Window - Interface

	class WALNUT_API Window
	{
	protected:
		using EventCallbackFunc = std::function<bool(Event&)>;

	public:
		virtual void OnUpdate() const = 0;
		virtual unsigned int GetWindowHeight() const = 0;
		virtual unsigned int GetWindowWidth() const = 0;
		virtual void SetVSync(bool enabled)  = 0;
		virtual bool IsVSync() const = 0;
		virtual void SetEventCallback( EventCallbackFunc& event ) = 0;		
		virtual ~Window() {}
		static Window* Create(WindowProperty& wp = WindowProperty());
	};
}