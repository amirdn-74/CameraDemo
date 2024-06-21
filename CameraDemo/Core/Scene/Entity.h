#pragma once

#include <unordered_map>
#include <typeindex>
#include <memory>

#include "Components.h"





enum class EntityType
{
	None = 0, Mesh, Light, Camera, Force
};


class Entity
{
protected:
	const char* m_title;
	std::unordered_map<std::type_index, std::vector<std::shared_ptr<IComponent>>> m_components;

public:
	Entity(const char* title) : m_title(title) {}
	virtual ~Entity() {}

	const char* getTitle() const { return m_title; }

	template<typename T>
	void addComponent(const T& data)
	{
		m_components[typeid(T)].push_back(std::make_shared<Component<T>>(data));
	}

	template<typename T, typename... Args>
	void addComponent(Args&&... data)
	{
		m_components[typeid(T)].push_back(std::make_shared<Component<T>>(std::forward<Args>(data)...));
	}

	template<typename T>
	bool hasComponent() const
	{
		return m_components.find(typeid(T)) != m_components.end();
	}

	template<typename T>
	std::vector<const T*> getComponent() const
	{
		auto componentVector = m_components.find(typeid(T));

		std::vector<const T*> result;

		if (componentVector != m_components.end())
		{
			for (auto component : componentVector->second)
			{
				const T& data = static_cast<Component<T>*>(component.get())->getData();
				result.emplace_back(&data);
			}

			return result;
		}
		else
			std::runtime_error("Component not found!");
	}
};