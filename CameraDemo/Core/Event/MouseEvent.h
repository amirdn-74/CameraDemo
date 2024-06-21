#pragma once

#include "Event.h"
#include <sstream>



class MouseDownEvent : public Event
{
private:
	int m_buttonCode;

public:
	MouseDownEvent(int buttonCode)
		: m_buttonCode(buttonCode)
	{}

	static EventType staticType() { return EventType::MouseDown; }
	virtual EventType type() const { return staticType(); }
	virtual std::string toString() const
	{
		std::stringstream stream;
		stream << "Event: MouseDown, " << "button code: " << m_buttonCode << "\n";

		return stream.str();
	}

	int getButtonCode() const { return m_buttonCode; }
};


class MouseUpEvent : public Event
{
private:
	int m_buttonCode;

public:
	MouseUpEvent(int buttonCode)
		: m_buttonCode(buttonCode)
	{}

	static EventType staticType() { return EventType::MouseUp; }
	virtual EventType type() const { return staticType(); }
	virtual std::string toString() const
	{
		std::stringstream stream;
		stream << "Event: MouseUp, " << "button code: " << m_buttonCode << "\n";

		return stream.str();
	}

	int getButtonCode() const { return m_buttonCode; }
};


class MouseMoveEvent : public Event
{
private:
	int m_x;
	int m_y;

public:
	MouseMoveEvent(int x, int y)
		: m_x(x), m_y(y)
	{}

	static EventType staticType() { return EventType::MouseMove; }
	virtual EventType type() const { return staticType(); }
	virtual std::string toString() const
	{
		std::stringstream stream;
		stream << "Event: MouseMove, " << "position: " << m_x << ", " << m_y << "\n";

		return stream.str();
	}

	int getPositionX() const { return m_x; }
	int getPositionY() const { return m_y; }
};


class MouseScrollEvent : public Event
{
private:
	int m_x;
	int m_y;

public:
	MouseScrollEvent(int x, int y)
		: m_x(x), m_y(y)
	{}

	static EventType staticType() { return EventType::MouseScroll; }
	virtual EventType type() const { return staticType(); }
	virtual std::string toString() const
	{
		std::stringstream stream;
		stream << "Event: MouseScroll, " << "offset: " << m_x << ", " << m_y << "\n";

		return stream.str();
	}

	int getOffsetX() const { return m_x; }
	int getOffsetY() const { return m_y; }
};