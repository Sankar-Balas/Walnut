#include "Sandbox.h"

class Sandbox : public Walnut::Engine
{
public:
	Sandbox(){}
	~Sandbox(){}
};

Walnut::Engine* Walnut::CreateApplication()
{
	return new Sandbox();
}
