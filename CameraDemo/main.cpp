#include "Core/Application.h"


int main(int argc, char** argv)
{
	auto* app = new Application();
	app->run();
	delete app;
}