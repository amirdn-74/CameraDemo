#pragma once

#include <memory>
//#include <GLFW/glfw3.h>
#include <fstream>
#include <vector>

#include "Window.h"
#include "Event/Event.h"
#include "Event/WindowEvent.h"
#include "./Scene/Scene.h"
#include "../Scenes/FirstScene.h"

#define STB_IMAGE_IMPLEMENTATION



class Application
{
private:
	static Application* s_instance;
	std::unique_ptr<Window> m_window;
	bool m_isRunning = true;
	std::shared_ptr<Scene> m_scene;

public:
	Application();
	~Application();
	void run();
	void shutDown(Event& e);
	static Application& getInstance();
	const Window& getWindow() const;

private:
	void eventHandler(Event& e);
};

