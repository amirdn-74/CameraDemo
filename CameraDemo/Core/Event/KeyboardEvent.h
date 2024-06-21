#pragma once

#include "Event.h"
#include "sstream"



class KeyDownEvent : public Event
{
private:
	int m_kyCode;

public:
	KeyDownEvent(int keyCode) 
		: m_kyCode(keyCode)
	{}

	static EventType staticType() { return EventType::KeyDown; }
	virtual EventType type() const { return staticType(); }
	virtual std::string toString() const
	{
		std::stringstream stream;
		stream << "Event: KeyDown ---" << "key id: " << m_kyCode << "\n";

		return stream.str();
	}

	int getKey() const { return m_kyCode; }
};


class KeyUpEvent : public Event
{
private:
	int m_kyCode;

public:
	KeyUpEvent(int keyCode)
		: m_kyCode(keyCode)
	{}

	static EventType staticType() { return EventType::KeyUp; }
	virtual EventType type() const { return staticType(); }
	virtual std::string toString() const
	{
		std::stringstream stream;
		stream << "Event: KeyUp ---" << "key id: " << m_kyCode << "\n";

		return stream.str();
	}

	int getKey() const { return m_kyCode; }
};


class KeyHoldEvent : public Event
{
private:
	int m_kyCode;
	int m_repeat;

public:
	KeyHoldEvent(int keyCode, int repeat)
		: m_kyCode(keyCode), m_repeat(repeat)
	{}

	static EventType staticType() { return EventType::KeyHold; }
	virtual EventType type() const { return staticType(); }
	virtual std::string toString() const
	{
		std::stringstream stream;
		stream << "Event: KeyUHold ---" << "key id: " << m_kyCode << ", repeat: " << m_repeat << "\n";

		return stream.str();
	}

	int getKey() const { return m_kyCode; }
	int getRepeat() const { return m_repeat; }
};