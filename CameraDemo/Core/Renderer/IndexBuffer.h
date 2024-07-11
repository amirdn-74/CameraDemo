#pragma once

#include <glad/glad.h>
#include <vector>



class IndexBuffer
{
private:
	unsigned int m_id;

public:
	IndexBuffer(const std::vector<unsigned int>& data)
	{
		glGenBuffers(1, &m_id);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_id);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, data.size() * sizeof(unsigned int), &data[0], GL_STATIC_DRAW);
	}

	~IndexBuffer() {  }

	inline void bind() const { glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_id); }
	inline void unbind() const { glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0); }
	inline void destroy() const { glDeleteBuffers(1, &m_id); }
	inline unsigned int getId() const { return m_id; }
};