#include "common.h"

class Sandbox : public Walnut::Engine
{
public:
	Sandbox() {

		WL_CORE_TRACE("I m from Sandbox");
	}
	~Sandbox() {}
};

Walnut::Engine* Walnut::CreateApplication()
{
	WL_CORE_ERROR("I m from CreateApplication");
	return new Sandbox();
}

