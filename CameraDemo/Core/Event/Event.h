#pragma once

#include <string>
#include <functional>
#include <iostream>


#define EVENT_BINDER(fn) std::bind(&fn, this, std::placeholders::_1)

enum class EventType
{
	None = 0,
	WindowClose, WindowResize,
	KeyDown, KeyUp, KeyHold,
	MouseDown, MouseUp, MouseMove, MouseScroll
};


class Event
{
public:
	~Event() {}

	virtual EventType type() const = 0;
	virtual std::string toString() const = 0;
};


using EventHandlerFn = std::function<void(Event&)>;


class EventDispatcher
{
private:
	Event& m_event;

public:
	EventDispatcher(Event& e) : m_event(e)
	{}

	template<class T>
	void dispatch(const EventHandlerFn& cb)
	{
		if (T::staticType() == m_event.type())
			cb(m_event);
	}
};