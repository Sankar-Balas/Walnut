#include "wlpch.h"
#include "LayerStack.h"

namespace Walnut
{
	LayerStack::LayerStack()
	{
		m_Layeritertor = m_Layerlist.begin();
	}

	LayerStack::~LayerStack()
	{
		for (Layer *layer : m_Layerlist)
		{
			delete layer;
		}
	}

	void Walnut::LayerStack::PushLayer(Layer *layer)
	{
		m_Layeritertor = m_Layerlist.emplace(m_Layeritertor, layer);
	}

	void Walnut::LayerStack::PushOverlayLayer(Layer *Overlay)
	{
		m_Layerlist.emplace_back(Overlay);
	}

	void Walnut::LayerStack::PopLayer(Layer *layer)
	{
		std::vector<Layer*>::iterator itr = std::find(m_Layerlist.begin(), m_Layerlist.end(), layer);

		if (itr != m_Layerlist.end())
		{
			m_Layerlist.erase(itr);
			m_Layeritertor--;
		}

	}

	void Walnut::LayerStack::PullOverlayLayer (Layer *layer)
	{
		std::vector<Layer*>::iterator itr = std::find(m_Layerlist.begin(), m_Layerlist.end(), layer);

		if (itr != m_Layerlist.end())
		{
			m_Layerlist.erase(itr);
		}

	}
}
