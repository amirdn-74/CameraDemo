#pragma once

#include <vector>
#include <sstream>

#include "Entity.h"





class Scene
{
private:
	const char* m_title;

	std::vector<Entity> m_entities;

	std::unordered_map<UINT, std::vector<MeshComponent>> m_meshComponents;
	std::unordered_map<UINT, std::vector<ColorComponent>> m_colorComponents;
	std::unordered_map<UINT, std::vector<TransformationComponent>> m_transformationComponents;
	std::unordered_map<UINT, std::vector<RenderComponent>> m_renderComponents;

public:

	Scene(const char* title) : m_title(title) {}
	virtual ~Scene() {}

	const char* getTitle() const { return m_title; }
	const std::vector<Entity>& getEntities() const { return m_entities; }

	const Entity& createEntity()
	{
		auto index = m_entities.size();
		std::stringstream stream;
		stream << "Entity " << index;

		auto title = stream.str();

		m_entities.emplace_back(title, index);

		return m_entities[index];
	}

	template<typename T>
	void attachComponent(const Entity& ent, const T& data)
	{
		printf("invalid component type!\n");
	}

	template<>
	void attachComponent(const Entity& ent, const MeshComponent& data)
	{
		m_meshComponents[ent.getId()].emplace_back(data);
	}

	template<>
	void attachComponent(const Entity& ent, const RenderComponent& data)
	{
		m_renderComponents[ent.getId()].emplace_back(data);
	}

	template<typename T>
	const std::unordered_map<UINT, std::vector<T>>& getComponents()
	{
		printf("invalid component type!\n");
	}

	template<>
	const std::unordered_map<UINT, std::vector<MeshComponent>>& getComponents()
	{
		return m_meshComponents;
	}

	template<>
	const std::unordered_map<UINT, std::vector<RenderComponent>>& getComponents()
	{
		return m_renderComponents;
	}

	template<typename T>
	std::vector<T> getComponents(const Entity& ent)
	{
		auto components = getComponents<T>();
		return components[ent.getId()];
	}

	template<typename T>
	bool hasComponent(const Entity& ent)
	{
		if (typeid(T) == typeid(MeshComponent) && m_meshComponents.find(ent.getId()) != m_meshComponents.end())
			return true;
		if (typeid(T) == typeid(RenderComponent) && m_renderComponents.find(ent.getId()) != m_renderComponents.end())
			return true;

		return false;
	}
};