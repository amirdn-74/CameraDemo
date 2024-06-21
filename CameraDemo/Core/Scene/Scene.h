#pragma once

#include <vector>

#include "Entity.h"



class Scene
{
private:
	const char* m_title;
	std::vector<const Entity*> m_meshEntities;

public:
	Scene(const char* title) : m_title(title) {}
	virtual ~Scene() {}

	const char* getTitle() const { return m_title; }
	const std::vector<const Entity*> getMeshEntities() const { return m_meshEntities; }
	void addMesh(const Entity* mesh)
	{
		m_meshEntities.emplace_back(mesh);
	}
};