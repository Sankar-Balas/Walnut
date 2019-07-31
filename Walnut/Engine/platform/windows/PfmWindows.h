#pragma once
#include "Window.h"
namespace Walnut
{
	class PfmWindows :public Window
	{
	public:		
		void OnUpdate() const override;
		inline unsigned int GetWindowHeight() const override { return m_WindowData.Height; }
		inline unsigned int GetWindowWidth() const override { return m_WindowData.Width; }
		void SetVSync(bool enabled) override;
		bool IsVSync() const override;

		inline void SetEventCallback(EventCallbackFunc& event) override { m_WindowData.EventCallback = event; }

		virtual ~PfmWindows();

		struct WindowData
		{
			std::string Title;
			unsigned int Width, Height;
			bool VSync;
			EventCallbackFunc EventCallback;
		};
		WindowData m_WindowData;	
		PfmWindows(WindowProperty& wp);
	private:
		void InitGraphicsHere(WindowProperty& props);
		void ShutdownPlease();

		GLFWwindow *m_glfWindow;
	};
}