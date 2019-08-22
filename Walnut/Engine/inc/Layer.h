#pragma once
#include "..\events\Event.h"

namespace Walnut {
	class Layer
	{
	public:
		Layer(const std::string layername = "Layer" , bool isEnabled =true) { m_Layername = layername , m_IsEnabled = isEnabled; }
		virtual ~Layer() {};


		virtual void attachLayer() {}
		virtual void detachLayer() {}
		virtual void refershLayer() {}
		virtual void onLayerEvent(Event &event) {}
		
		inline const std::string& getLayerName() const { return m_Layername; }
		inline const bool islayerEnabled() { return m_IsEnabled; }
	private:
		std::string m_Layername;
		bool m_IsEnabled;
	};
}

