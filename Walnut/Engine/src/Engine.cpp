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

			for (Layer* layer : m_Layerstack.m_Layerlist) {
				layer->refershLayer();
			}

			m_Window->OnUpdate();
		}

	}
	void Engine::onEvent(Event &e)
	{
		EventDispatcher dispatchMe(e);

		for (auto it = m_Layerstack.m_Layerlist.end(); it != m_Layerstack.m_Layerlist.begin();it--)
		{
			(**it).onLayerEvent(e);

			if (e.m_handled == true)
				break;
		}
		switch (e.GetEventType())
		{
		case EventType::WindowClose:
			dispatchMe.dispatchtoEvent<WindowCloseEvent>(Event_Callbk_Fn(OnWindowClose));
			break;
		case EventType::MouseButtonPressed:
			std::cout << e.ToStringPlease() << std::endl;
			break;
		case EventType::MouseButtonReleased:
			std::cout << e.ToStringPlease() << std::endl;
			break;
		case EventType::KeyPressed:
			std::cout << e.ToStringPlease() << std::endl;
			break;
		case EventType::KeyReleased:
			std::cout << e.ToStringPlease() << std::endl;
			break;
		case EventType::KeyTyped:
			std::cout << e.ToStringPlease() << std::endl;
			break;
		}
		
	}

	bool Engine::OnWindowClose(WindowCloseEvent &wce)
	{
		m_isCodeRunning = false;
		return true;
	}	

	void  Engine::PushLayer(Layer *layer)
	{
		m_Layerstack.PushLayer(layer);
	}
	void  Engine::PopLayer(Layer *layer)
	{
		m_Layerstack.PopLayer(layer);
	}
	void  Engine::PushOverlayLayer(Layer *layer)
	{
		m_Layerstack.PushOverlayLayer(layer);
	}
	void  Engine::PullOverlayLayer(Layer *layer)
	{
		m_Layerstack.PullOverlayLayer(layer);
	}
}