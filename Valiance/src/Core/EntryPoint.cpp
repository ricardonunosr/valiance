#include "Application.h"

int main()
{
	auto app = new Valiance::Application();

	app->Run();

	delete app;
}