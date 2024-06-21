#pragma once

#include <GLFW/glfw3.h>
#include "../Application.h"



class Input
{
private:
	static GLFWgamepadstate state;
public:
	static bool isPressed(int keyId)
	{
		auto window = (GLFWwindow*)Application::getInstance().getWindow().getNativeWindow();
		auto res = glfwGetKey(window, keyId);
		return res == GLFW_PRESS || res == GLFW_REPEAT;
		return false;
	}
};