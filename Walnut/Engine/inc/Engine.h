#pragma once

#include "Core.h"
#include "Window.h"
#include "..\events\ApplicationEvent.h"

namespace Walnut{

	class WALNUT_API Engine
	{
	public:
		Engine();
		virtual ~Engine();
		void RunEngine();
		std::unique_ptr<Window>m_Window;
		void onEvent(Event &e);
		bool OnWindowClose(WindowCloseEvent &);
		static bool m_isCodeRunning;
	};	
	Engine* CreateApplication();

}