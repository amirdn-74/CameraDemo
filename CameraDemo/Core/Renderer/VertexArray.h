#pragma once

#include <glad/glad.h>



class VertexArray
{
public:
	VertexArray();
	~VertexArray() 
	{
		destroy();
	}

	void bind() const;
	void unBind() const;
	void destroy() const;

private:
	unsigned int m_id;
};

