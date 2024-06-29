#include "Window.h"
#include "Event/KeyboardEvent.h"
#include "Event/MouseEvent.h"
#include "Event/WindowEvent.h"



Window::Window(std::string title, int width, int height)
	: m_title(title), m_width(width), m_height(height)
{
	createWindow();
	setVsync(true);
	setWindowEvents();
}

void Window::createWindow()
{
	if (!glfwInit())
		printf("GLFW not initialized!\n");

	m_nativeWindow = glfwCreateWindow(m_width, m_height, m_title.c_str(), NULL, NULL);
	glfwMakeContextCurrent(m_nativeWindow);
	glfwSetWindowUserPointer(m_nativeWindow, this);

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		printf("GLAD not initialized!\n");
	}

	/*glEnable(GL_DEBUG_OUTPUT);
	glEnable(GL_DEBUG_OUTPUT_SYNCHRONOUS);

	auto glDebugCb = [](GLenum source, GLenum type, GLuint id, GLenum severity, GLsizei length, const GLchar* message, const void* userParam)
		{
			if (id == 131169 || id == 131185 || id == 131218 || id == 131204)
				return;

			std::cout << "---------------" << std::endl;
			std::cout << "Debug message (" << id << "): " << message << std::endl;

			switch (source)
			{
			case GL_DEBUG_SOURCE_API:             std::cout << "Source: API"; break;
			case GL_DEBUG_SOURCE_WINDOW_SYSTEM:   std::cout << "Source: Window System"; break;
			case GL_DEBUG_SOURCE_SHADER_COMPILER: std::cout << "Source: Shader Compiler"; break;
			case GL_DEBUG_SOURCE_THIRD_PARTY:     std::cout << "Source: Third Party"; break;
			case GL_DEBUG_SOURCE_APPLICATION:     std::cout << "Source: Application"; break;
			case GL_DEBUG_SOURCE_OTHER:           std::cout << "Source: Other"; break;
			}
			std::cout << std::endl;

			switch (type)
			{
			case GL_DEBUG_TYPE_ERROR:               std::cout << "Type: Error"; break;
			case GL_DEBUG_TYPE_DEPRECATED_BEHAVIOR: std::cout << "Type: Deprecated Behaviour"; break;
			case GL_DEBUG_TYPE_UNDEFINED_BEHAVIOR:  std::cout << "Type: Undefined Behaviour"; break;
			case GL_DEBUG_TYPE_PORTABILITY:         std::cout << "Type: Portability"; break;
			case GL_DEBUG_TYPE_PERFORMANCE:         std::cout << "Type: Performance"; break;
			case GL_DEBUG_TYPE_MARKER:              std::cout << "Type: Marker"; break;
			case GL_DEBUG_TYPE_PUSH_GROUP:          std::cout << "Type: Push Group"; break;
			case GL_DEBUG_TYPE_POP_GROUP:           std::cout << "Type: Pop Group"; break;
			case GL_DEBUG_TYPE_OTHER:               std::cout << "Type: Other"; break;
			}
			std::cout << std::endl;

			switch (severity)
			{
			case GL_DEBUG_SEVERITY_HIGH:         std::cout << "Severity: high"; break;
			case GL_DEBUG_SEVERITY_MEDIUM:       std::cout << "Severity: medium"; break;
			case GL_DEBUG_SEVERITY_LOW:          std::cout << "Severity: low"; break;
			case GL_DEBUG_SEVERITY_NOTIFICATION: std::cout << "Severity: notification"; break;
			}
			std::cout << std::endl;
			std::cout << std::endl;
		};

	glDebugMessageCallback(glDebugCb, nullptr);*/
}

void Window::setWindowEvents()
{
	glfwSetWindowCloseCallback(m_nativeWindow, [](GLFWwindow* window) {
		auto winptr = (Window*)glfwGetWindowUserPointer(window);
		WindowCloseEvent e;
		winptr->raiseEvent(e);
	});

	glfwSetWindowSizeCallback(m_nativeWindow, [](GLFWwindow* window, int width, int height) {
		auto winptr = (Window*)glfwGetWindowUserPointer(window);
		WindowResizeEvent e(width, height);
		winptr->raiseEvent(e);
	});

	glfwSetKeyCallback(m_nativeWindow, [](GLFWwindow* window, int key, int scancode, int action, int mods) {
		switch (action)
		{
			case GLFW_PRESS:
			{
				auto winptr = (Window*)glfwGetWindowUserPointer(window);
				KeyDownEvent e(key);
				winptr->raiseEvent(e);

				break;
			}
			case GLFW_RELEASE:
			{
				auto winptr = (Window*)glfwGetWindowUserPointer(window);
				KeyUpEvent e(key);
				winptr->raiseEvent(e);

				break;
			}
			case GLFW_REPEAT:
			{
				auto winptr = (Window*)glfwGetWindowUserPointer(window);
				KeyHoldEvent e(key, 1);
				winptr->raiseEvent(e);

				break;
			}
		}
	});

	glfwSetMouseButtonCallback(m_nativeWindow, [](GLFWwindow* window, int button, int action, int mods) {
		switch (action)
		{
			case GLFW_PRESS:
			{
				auto winptr = (Window*)glfwGetWindowUserPointer(window);
				MouseDownEvent e(button);
				winptr->raiseEvent(e);

				break;
			}
			case GLFW_RELEASE:
			{
				auto winptr = (Window*)glfwGetWindowUserPointer(window);
				KeyUpEvent e(button);
				winptr->raiseEvent(e);

				break;
			}
		}
	});

	glfwSetCursorPosCallback(m_nativeWindow, [](GLFWwindow* window, double xpos, double ypos) {
		auto winptr = (Window*)glfwGetWindowUserPointer(window);
		MouseMoveEvent e(xpos, ypos);
		winptr->raiseEvent(e);
	});

	glfwSetScrollCallback(m_nativeWindow, [](GLFWwindow* window, double xoffset, double yoffset) {
		auto winptr = (Window*)glfwGetWindowUserPointer(window);
		MouseScrollEvent e(xoffset, yoffset);
		winptr->raiseEvent(e);
	});
}



void Window::update()
{
	glfwPollEvents();
	glClearColor(1.f, 0.f, 0.8f, 1.f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glEnable(GL_DEPTH);
}

void Window::swapBuffer()
{
	glfwSwapBuffers(m_nativeWindow);
}

void Window::terminate()
{
	glfwTerminate();
}

void Window::setEventHandler(const EventHandlerFn& handler)
{
	m_handler = handler;
}

void Window::raiseEvent(Event& e)
{
	m_handler(e);
}

void Window::setVsync(bool vsync)
{
	if (vsync)
		glfwSwapInterval(1);
	else
		glfwSwapInterval(0);
}

const GLFWwindow* Window::getNativeWindow() const
{
	return m_nativeWindow;
}
