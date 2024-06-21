#pragma once

#include "../Math.h"





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

	MeshComponent() {}
	MeshComponent(const std::vector<Vertex>& _vertices) : vertices(_vertices) {}
};


struct ColorComponent
{
	glm::vec4 color {1.f};

	ColorComponent() {}
	ColorComponent(float scalar) : color(scalar) {}
	ColorComponent(float r, float g, float b, float a) : color({r, g, b, a}) {}
	ColorComponent(const glm::vec4& _color) : color(_color) {}
};


struct TransformationComponent
{
	glm::vec3 Position {1.f};
	glm::vec3 Rotation {1.f};
	glm::vec3 Scale {1.f};

	TransformationComponent() {}
	TransformationComponent(const glm::vec3& pos, const glm::vec3& rot, const glm::vec3& scale)
		: Position(pos), Rotation(rot), Scale(scale)
	{}
};