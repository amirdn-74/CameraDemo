#include "VertexArray.h"


VertexArray::VertexArray()
{
	glGenVertexArrays(1, &m_id);
	glBindVertexArray(m_id);
}

void VertexArray::bind() const
{
	glBindVertexArray(m_id);
}

void VertexArray::unBind() const
{
	glBindVertexArray(0);
}

void VertexArray::destroy() const
{
	glDeleteVertexArrays(1, &m_id);
}
