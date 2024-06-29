#pragma once

#include <string>

#include "Components.h"
#include "./Scene.h"




class Entity
{
private:
	std::string m_title;
	unsigned int m_id;

public:
	Entity(const std::string& title, int id) : m_title(title), m_id(id) {}
	~Entity() {};

	inline const int getId() const { return m_id; }
	inline const std::string& getTitle() const { return m_title; }
};
