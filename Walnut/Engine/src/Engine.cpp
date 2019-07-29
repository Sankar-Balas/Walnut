#include "wlpch.h"
#include "Engine.h"

#include "..\events\ApplicationEvent.h"
//#include "..\Logger\inc\Log.h"

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
		if (e.IsIncategory(EventcategoryMouse))
		{
			std::cout << "Yes Iam in" << std::endl;
		}
		std::cout << "Function Run in Engine.cpp" << std::endl;
		while (true)
		{

		}

	}
}