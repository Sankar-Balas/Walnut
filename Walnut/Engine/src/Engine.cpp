#pragma once

#include "wlpch.h"
#include "Engine.h"
#include "ApplicationEvent.h"
#include "Log.h"
#include "glfw3.h"

namespace Walnut{

	Engine::Engine()
	{
		m_Window = std::unique_ptr<Window>(Window::Create());
	}

	Engine::~Engine()
	{

	}

	void Engine::RunEngine()
	{			
		while (true)
		{
			glClearColor(1, 0, 1, 1);
			glClear(GL_COLOR_BUFFER_BIT);
			m_Window->OnUpdate();
		}

	}
}