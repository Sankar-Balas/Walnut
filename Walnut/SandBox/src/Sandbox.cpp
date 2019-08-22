#pragma once
#include <common.h>
#include <Log.h>
#include "Layer.h"


class TestLayerOne : public Walnut::Layer
{
public:
	TestLayerOne()
	{
		WL_CORE_TRACE("Test layer Const");
	}

	~TestLayerOne()	
	{
		WL_CORE_TRACE("Test layer Dest");
	}

	void attachLayer() override {
		WL_CORE_TRACE("Test layer got attcahed");
	}

	void detachLayer() override {
		WL_CORE_TRACE("Test layer got detached");
	}

	void onLayerEvent(Walnut::Event &event) override {
		WL_CORE_TRACE("Test layer onLayerEvent");
		//event.m_handled = true;
	}
};


class Sandbox : public Walnut::Engine
{
public:
	Sandbox() 
	{
		WL_CORE_TRACE("Sandbox:Constructor");
		PushLayer(new TestLayerOne());
	}	
	~Sandbox() {}
};

Walnut::Engine* Walnut::CreateApplication()
{
	WL_CORE_ERROR("Sandbox:CreateApplication");
	return new Sandbox();
}

