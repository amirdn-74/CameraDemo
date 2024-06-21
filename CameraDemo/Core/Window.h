#pragma once

#include <string>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "Event/Event.h"


class Window
{
private:
	GLFWwindow* m_nativeWindow;
	std::string m_title;
	int m_width;
	int m_height;
	EventHandlerFn m_handler;

public:
	Window(std::string title, int width, int height);
	void update();
	void swapBuffer();
	void terminate();
	void setEventHandler(const EventHandlerFn& handler);
	void raiseEvent(Event& e);
	void setVsync(bool vsync);
	const GLFWwindow* getNativeWindow() const;

private:
	void createWindow();
	void setWindowEvents();
};

