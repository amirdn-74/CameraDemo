#pragma once

#include <fstream>
#include <sstream>
#include <string>
#include <stdio.h>
#include <iostream>
#include <glad/glad.h>

#include "../Math.h"



class Shader
{
private:
	unsigned int m_vertexShader, m_fragmentShader, m_shaderProgram;

public:
	Shader(std::string vsPath, std::string frPath);
	~Shader() 
	{
		destroy();
	}

	void bind() const;
	void unBind() const;
	void destroy() const;

	void set1i(const char* uniform, int v);
	void set1f(const char* uniform, float v);
	void set1d(const char* uniform, double v);

	void set2i(const char* uniform, int v);
	void set2i(const char* uniform, int v1, int v2);
	void set2i(const char* uniform, const glm::vec2& v);

	void set2f(const char* uniform, float v);
	void set2f(const char* uniform, float v1, float v2);
	void set2f(const char* uniform, const glm::vec2& v);

	void set2d(const char* uniform, double v);
	void set2d(const char* uniform, double v1, double v2);
	void set2d(const char* uniform, const glm::vec2& v);

	void set3i(const char* uniform, int v);
	void set3i(const char* uniform, int v1, int v2, int v3);
	void set3i(const char* uniform, const glm::vec3& v);

	void set3f(const char* uniform, float v);
	void set3f(const char* uniform, float v1, float v2, float v3);
	void set3f(const char* uniform, const glm::vec3& v);

	void set3d(const char* uniform, double v);
	void set3d(const char* uniform, double v1, double v2, double v3);
	void set3d(const char* uniform, const glm::vec3& v);

	void set4i(const char* uniform, int v);
	void set4i(const char* uniform, int v1, int v2, int v3, int v4);
	void set4i(const char* uniform, const glm::vec4& v);

	void set4f(const char* uniform, float v);
	void set4f(const char* uniform, float v1, float v2, float v3, float v4);
	void set4f(const char* uniform, const glm::vec4& v);

	void set4d(const char* uniform, double v);
	void set4d(const char* uniform, double v1, double v2, double v3, double v4);
	void set4d(const char* uniform, const glm::vec4& v);

	void setMat2(const char* uniform, const glm::mat2& mat);
	void setMat3(const char* uniform, const glm::mat3& mat);
	void setMat4(const char* uniform, const glm::mat4& mat);

private:
	std::string load(std::string sourcePath);
	void createShader(int type, std::string sourcePath);
	void createProgram();
	void clean();
	void catchErrors() const;
	uint32_t locateUniform(const char* title);
};
