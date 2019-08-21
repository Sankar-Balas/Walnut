#pragma once

#include "wlpch.h"
#include "PfmWindows.h"
#include "glfw3.h"
#include "Log.h"

namespace Walnut
{
	static bool isGLFWinitiated = false;

	Window* Window::Create(WindowProperty& wp)
	{		
		return new PfmWindows(wp);
	}	
	
	PfmWindows::PfmWindows(WindowProperty& wp)
	{
		InitGraphicsHere(wp);
	}

	PfmWindows::~PfmWindows()
	{
		ShutdownPlease();
	}

	void PfmWindows::OnUpdate() const
	{
		glfwPollEvents();
		glfwSwapBuffers(m_glfWindow);
	}
	void PfmWindows::InitGraphicsHere(WindowProperty& props)
	{
		if (!isGLFWinitiated)
		{
			int success = glfwInit();
			if (success) 
				WL_CORE_TRACE("glfw initiated well");			
			else
				WL_CORE_ERROR("glfw not initiated well");
			
			isGLFWinitiated = true;
		}
		m_glfWindow = glfwCreateWindow((int)props.m_Width, (int)props.m_height,  props.m_Title.c_str(), nullptr, nullptr);
		glfwMakeContextCurrent(m_glfWindow);
		glfwSetWindowUserPointer(m_glfWindow, &m_WindowData);
		SetVSync(true);

		glfwSetWindowCloseCallback(m_glfWindow, [](GLFWwindow* window)
		{
			WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
			WindowCloseEvent event;
			data.EventCallback(event);
		});

		glfwSetMouseButtonCallback(m_glfWindow, [](GLFWwindow* window,int button,int action,int mods)
		{
			WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

			switch (action)
			{
				case GLFW_PRESS:
				{
					MouseButtonPressed mbpe(button);
					data.EventCallback(mbpe);
					break;
				}
				case GLFW_RELEASE:
				{
					MouseButtonReleased mbre(button);
					data.EventCallback(mbre);
					break;
				}			
			}
		});
		
		glfwSetKeyCallback(m_glfWindow, [](GLFWwindow* window, int keyboardKey, int scancode, int action, int mods)
		{
			WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

			switch (action)
			{
			case GLFW_PRESS: {
				KeyPressedEvent kpe(keyboardKey);
				data.EventCallback(kpe);
				break; }

			case GLFW_RELEASE: {
				KeyReleasedEvent kre(keyboardKey);
				data.EventCallback(kre);
				break; }

			case GLFW_REPEAT: {
				KeyTypedEvent kte(keyboardKey);
				data.EventCallback(kte);
				break; }
			}
		});		
		
	}

	void PfmWindows::ShutdownPlease()
	{
		glfwDestroyWindow(m_glfWindow);
	}

	void PfmWindows::SetVSync(bool enabled)
	{
		if (enabled)
			glfwSwapInterval(1);
		else
			glfwSwapInterval(0);

		m_WindowData.VSync = enabled;
	}

	bool PfmWindows::IsVSync() const
	{
		return m_WindowData.VSync;
	}
}
