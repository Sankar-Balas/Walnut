#pragma once
#include "Window.h"
#include "glfw3.h"
#include "..\events\ApplicationEvent.h"
#include "..\events\MouseEvent.h"

namespace Walnut
{
	class PfmWindows :public Window
	{
	public:	
		PfmWindows(WindowProperty& wp);
		virtual ~PfmWindows();
		
		void OnUpdate() const override;
		inline unsigned int GetWindowHeight() const override { return m_WindowData.Height; }
		inline unsigned int GetWindowWidth() const override { return m_WindowData.Width; }
		
		void SetVSync(bool enabled) override;
		bool IsVSync() const override;

		inline void SetEventCallback(const EventCallbackFunc& event) override { m_WindowData.EventCallback = event; }


		struct WindowData
		{
			std::string Title;
			unsigned int Width, Height;
			bool VSync;
			EventCallbackFunc EventCallback;
		};
		WindowData m_WindowData;	

	private:
		void InitGraphicsHere(WindowProperty& props);
		void ShutdownPlease();

		GLFWwindow *m_glfWindow;
	};
}