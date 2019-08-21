#pragma once

#include "Core.h"
#include "Window.h"
#include "..\events\ApplicationEvent.h"
#include "LayerStack.h"

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

		void PushLayer(Layer *layer);
		void PopLayer(Layer *layer);
		void PushOverlayLayer(Layer *layer);
		void PullOverlayLayer(Layer *layer);

		LayerStack m_Layerstack;

	};	
	Engine* CreateApplication();

}