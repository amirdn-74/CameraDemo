#pragma once

#include "../Math.h"
#include "../Renderer/VertexArray.h"
#include "../Renderer/VertexBuffer.h"
#include "../Renderer/IndexBuffer.h"




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







struct MeshComponent
{
	//std::vector<Vertex> vertices;
	std::string path;

	UINT entityId;
};

struct RenderComponent
{
	VertexArray va;
	VertexBuffer vb;
	IndexBuffer ib;
	size_t vertexCount;
	size_t indexCount;

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