#pragma once

#include "Event.h"
#include <sstream>



class WindowCloseEvent : public Event
{
public:
	~WindowCloseEvent() {}

	static EventType staticType() { return EventType::WindowClose; }
	virtual EventType type() const { return staticType(); }
	virtual std::string toString() const { return std::string("Event: WindowClose\n"); }
};


class WindowResizeEvent : public Event
{
private:
	int m_width;
	int m_height;

public:
	WindowResizeEvent(int width, int height)
		: m_width(width), m_height(height)
	{}
	~WindowResizeEvent() {}

	static EventType staticType() { return EventType::WindowResize; }
	virtual EventType type() const { return staticType(); }
	virtual std::string toString() const 
	{ 
		std::stringstream stream;
		stream << "Event: WindowResize, " << "width: " << m_width << ", height: " << m_height << "\n";
		return stream.str();
	}

	int getWidth() const { return m_width; }
	int getHeigth() const { return m_height; }
};