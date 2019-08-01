#pragma once

//defined in Client application
#ifdef WL_PLATFORM_WINDOWS
extern Walnut::Engine* Walnut::CreateApplication();

int main(int argc, char**argv)
{
	auto app = Walnut::CreateApplication();
	app->RunEngine();
	delete app;
	return 0;
}
#endif