#pragma once

//defined in Client application

extern Walnut::Engine* Walnut::CreateApplication();

int main(int argc, char**argv)
{
	auto app = Walnut::CreateApplication();
	app->RunEngine();
	delete app;
	return 0;
}
