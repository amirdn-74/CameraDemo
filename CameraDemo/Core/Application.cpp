#include "Application.h"

#include "Event/Input.h"


Application* Application::s_instance = nullptr;

Application::Application()
{
	s_instance = this;

	m_window = std::make_unique<Window>("Camera Demo project.", 1920, 1080);
	m_window->setEventHandler(EVENT_BINDER(Application::eventHandler));

	m_scene = std::make_shared<FirstScene>("first scene");
}

void Application::run()
{
	while (m_isRunning)
	{
		m_window->update();

		Renderer::DrawScene(m_scene);

		m_window->swapBuffer();
	}
}

Application::~Application()
{
	m_window->terminate();
}

void Application::eventHandler(Event& e)
{
	EventDispatcher dispatcher(e);
	dispatcher.dispatch<WindowCloseEvent>(EVENT_BINDER(Application::shutDown));
}

void Application::shutDown(Event& e)
{
	m_isRunning = false;
	m_window->terminate();
}

const Window& Application::getWindow() const
{
	return *m_window.get();
}

Application& Application::getInstance()
{
	return *s_instance;
}