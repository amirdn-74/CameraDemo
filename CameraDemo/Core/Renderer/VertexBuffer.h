#pragma once

#include <vector>
#include <iostream>
#include <glad/glad.h>

#include "../Math.h"



struct Vertex
{
	glm::vec3 Position;
	glm::vec3 Normal;
	glm::vec2 TextureCoordinate;

	Vertex() {};
	Vertex(const glm::vec3& pos, const glm::vec3& norm, const glm::vec2& txCoord)
		: Position(pos), Normal(norm), TextureCoordinate(txCoord)
	{}
};


struct VertexLayoutElement
{
	const char* Title;
	int Count;
	GLenum IsNormalized;
	GLenum Type;

	VertexLayoutElement(const char* title, int count, GLenum isNorm, GLenum type) :
		Title(title), Count(count), IsNormalized(isNorm), Type(type)
	{}
};


//template <typename T>
class VertexBuffer
{
public:
	VertexBuffer(const std::vector<Vertex>& vertices)
	{
		glGenBuffers(1, &m_id);
		glBindBuffer(GL_ARRAY_BUFFER, m_id);
		glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(Vertex), &vertices[0], GL_STATIC_DRAW);
	}

	~VertexBuffer() 
	{
		//destroy();
	}

	void bind() const
	{
		glBindBuffer(GL_ARRAY_BUFFER, m_id);
	}

	unsigned int getId() const
	{
		return m_id;
	}

	void unBind() const
	{
		glBindBuffer(GL_ARRAY_BUFFER, 0);
	}

	void destroy() const
	{
		glDeleteBuffers(1, &m_id);
	}

	void addLayout(const char* title, int count, bool isNormalized = true)
	{
		m_elements.emplace_back(title, count, isNormalized ? GL_TRUE : GL_FALSE, GL_FLOAT);
	}

	void applyLayouts()
	{
		uint16_t offset = 0;

		for (int i = 0; i < m_elements.size(); i++)
		{
			auto element = m_elements[i];

			glEnableVertexAttribArray(i);
			glVertexAttribPointer(
				i, 
				element.Count, 
				element.Type, 
				element.IsNormalized, 
				sizeof(Vertex),
				((void*)offset)
			);

			offset += element.Count * sizeof(float);
		}
	}

private:
	unsigned int m_id;
	std::vector<VertexLayoutElement> m_elements;
};