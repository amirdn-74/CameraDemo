#pragma once

#include "../Math.h"
#include "../Renderer/VertexArray.h"




typedef unsigned int UINT;


class IComponent
{
public:
	virtual ~IComponent() {}
};

template<typename T>
class Component : public IComponent
{
private:
	T m_data;

public:
	Component(const T& data) : m_data(data) {}

	template<typename... Args>
	Component(Args... data)
	{
		m_data = T(std::forward<Args>(data)...);
	}

	const T& getData() const { return m_data; }
};





struct Vertex
{
	glm::vec3 Position;
	glm::vec3 Normal;
	glm::vec2 TextureCoordinate;

	Vertex(const glm::vec3& pos, const glm::vec3& norm, const glm::vec2& txCoord) 
		: Position(pos), Normal(norm), TextureCoordinate(txCoord)
	{}
};

struct MeshComponent
{
	std::vector<Vertex> vertices;

	UINT entityId;
};

struct RenderComponent
{
	VertexArray renderId;

	UINT entityId;
};


struct ColorComponent
{
	glm::vec4 color {1.f};

	UINT entityId;
};


struct TransformationComponent
{
	glm::vec3 Position {1.f};
	glm::vec3 Rotation {1.f};
	glm::vec3 Scale {1.f};

	UINT entityId;
};