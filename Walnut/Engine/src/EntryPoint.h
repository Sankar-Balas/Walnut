#pragma once
#include "Engine.h"

extern Walnut::Engine* Walnut::CreateApplication();

int main(int argc, char**argv)
{
	auto app = Walnut::CreateApplication();
	app->RunEngine();
	delete app;
	return 0;
}
