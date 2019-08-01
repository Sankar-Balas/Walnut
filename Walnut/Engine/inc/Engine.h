#pragma once

#include "Core.h"
#include "Window.h"

namespace Walnut{

	class WALNUT_API Engine
	{
	public:
		Engine();
		virtual ~Engine();
		void RunEngine();
		std::unique_ptr<Window>m_Window;
	};	
	Engine* CreateApplication();
}