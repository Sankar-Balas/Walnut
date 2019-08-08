#pragma once

#include "wlpch.h"
#include "Engine.h"
#include "ApplicationEvent.h"
#include "Log.h"
#include "glfw3.h"

namespace Walnut{

	#define Event_Callbk_Fn(x) std::bind(&Engine::x,this,std::placeholders::_1)

	bool Engine::m_isCodeRunning = true;	

	Engine::Engine()
	{
		m_Window = std::unique_ptr<Window>(Window::Create());
		m_Window->SetEventCallback(Event_Callbk_Fn(onEvent));		
	}

	Engine::~Engine()
	{

	}
	
	void Engine::RunEngine()
	{			
		while (m_isCodeRunning)
		{
			glClearColor(1, 0, 1, 1);
			glClear(GL_COLOR_BUFFER_BIT);
			m_Window->OnUpdate();
		}

	}
	void Engine::onEvent(Event &e)
	{
		EventDispatcher dispatchMe(e);
		dispatchMe.dispatchtoEvent<WindowCloseEvent>(Event_Callbk_Fn(OnWindowClose));
	}

	bool Engine::OnWindowClose(WindowCloseEvent &wce)
	{
		m_isCodeRunning = false;
		return false;
	}	
}