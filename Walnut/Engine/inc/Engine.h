#pragma once
#include <iostream>
#include "Core.h"

namespace Walnut{

	class WALNUT_API Engine
	{
	public:
		Engine();
		virtual ~Engine();
		void RunEngine();
	};	
	Engine* CreateApplication();
}