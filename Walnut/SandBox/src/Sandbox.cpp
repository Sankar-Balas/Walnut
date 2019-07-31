#include <common.h>
#include <Log.h>

class Sandbox : public Walnut::Engine
{
public:
	Sandbox() 
	{
		WL_CORE_TRACE("Sandbox:Constructor");
	}	
	~Sandbox() {}
};

Walnut::Engine* Walnut::CreateApplication()
{
	WL_CORE_ERROR("Sandbox:CreateApplication");
	return new Sandbox();
}

