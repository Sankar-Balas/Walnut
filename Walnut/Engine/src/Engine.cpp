#include "wlpch.h"
#include "Engine.h"
#include "ApplicationEvent.h"

namespace Walnut{

	Engine::Engine()
	{

	}

	Engine::~Engine()
	{

	}

	void Engine::RunEngine()
	{
		WindowResizeEvent e(10, 20);
		if (e.IsIncategory(EventcategoryApplication))
		{
			WL_CORE_TRACE("Inside RunEngine");			
		}		
		while (true)
		{
		}

	}
}