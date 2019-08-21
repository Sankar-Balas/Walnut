#pragma once
#include".\Layer.h"
#include <vector>

namespace Walnut {
	class LayerStack:public Layer
	{
	public:
		LayerStack();
		~LayerStack();

		void PushLayer(Layer *layer);
		void PopLayer(Layer *layer);
		void PushOverlayLayer(Layer *layer);
		void PullOverlayLayer(Layer *layer);
		

		std::vector<Layer*>m_Layerlist;		
		std::vector<Layer*>::iterator m_Layeritertor;

		std::vector<Layer*>::iterator Begin() { return m_Layerlist.begin(); }
		std::vector<Layer*>::iterator End() { return m_Layerlist.end(); }
	};
}
