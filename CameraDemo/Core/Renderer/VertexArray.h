#pragma once

#include <glad/glad.h>



class VertexArray
{
public:
	VertexArray();
	~VertexArray() 
	{
		//destroy();
	}

	void bind() const;
	unsigned int getId() const
	{
		return m_id;
	}
	void unBind() const;
	void destroy() const;

private:
	unsigned int m_id;
};

