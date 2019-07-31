
#include "wlpch.h"
#include "PfmWindows.h"

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
				std::cout << "Good" << std::endl;
			else
				std::cout << "bad" << std::endl;
			
			isGLFWinitiated = true;
		}
		m_glfWindow = glfwCreateWindow((int)props.m_Width, (int)props.m_height,  props.m_Title.c_str(), nullptr, nullptr);
		glfwMakeContextCurrent(m_glfWindow);
		glfwSetWindowUserPointer(m_glfWindow, &m_WindowData);
		SetVSync(true);
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
