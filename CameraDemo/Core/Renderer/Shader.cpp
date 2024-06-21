#include "Shader.h"

Shader::Shader(std::string vsPath, std::string frPath)
{
	createShader(GL_VERTEX_SHADER, vsPath);
	createShader(GL_FRAGMENT_SHADER, frPath);
	createProgram();
	clean();
	catchErrors();
}

void Shader::bind() const
{
	glUseProgram(m_shaderProgram);
}

void Shader::unBind() const
{
	glUseProgram(0);
}

void Shader::destroy() const
{
	glDeleteProgram(m_shaderProgram);
}

void Shader::set1i(const char* uniform, int v)
{
	auto location = locateUniform(uniform);
	glUniform1i(location, v);
}

void Shader::set1f(const char* uniform, float v)
{
	auto location = locateUniform(uniform);
	glUniform1f(location, v);
}

void Shader::set1d(const char* uniform, double v)
{
	auto location = locateUniform(uniform);
	glUniform1d(location, v);
}

void Shader::set2i(const char* uniform, int v)
{
	auto location = locateUniform(uniform);
	glUniform2i(location, v, v);
}

void Shader::set2i(const char* uniform, int v1, int v2)
{
	auto location = locateUniform(uniform);
	glUniform2i(location, v1, v2);
}

void Shader::set2i(const char* uniform, const glm::vec2& v)
{
	auto location = locateUniform(uniform);
	glUniform2i(location, v.x, v.y);
}

void Shader::set2f(const char* uniform, float v)
{
	auto location = locateUniform(uniform);
	glUniform2f(location, v, v);
}

void Shader::set2f(const char* uniform, float v1, float v2)
{
	auto location = locateUniform(uniform);
	glUniform2f(location, v1, v2);
}

void Shader::set2f(const char* uniform, const glm::vec2& v)
{
	auto location = locateUniform(uniform);
	glUniform2f(location, v.x, v.y);
}


void Shader::set2d(const char* uniform, double v)
{
	auto location = locateUniform(uniform);
	glUniform2d(location, v, v);
}

void Shader::set2d(const char* uniform, double v1, double v2)
{
	auto location = locateUniform(uniform);
	glUniform2d(location, v1, v2);
}

void Shader::set2d(const char* uniform, const glm::vec2& v)
{
	auto location = locateUniform(uniform);
	glUniform2d(location, v.x, v.y);
}

void Shader::set3i(const char* uniform, int v)
{
	auto location = locateUniform(uniform);
	glUniform3i(location, v, v, v);
}

void Shader::set3i(const char* uniform, int v1, int v2, int v3)
{
	auto location = locateUniform(uniform);
	glUniform3i(location, v1, v2, v3);
}

void Shader::set3i(const char* uniform, const glm::vec3& v)
{
	auto location = locateUniform(uniform);
	glUniform3i(location, v.x, v.y, v.z);
}

void Shader::set3f(const char* uniform, float v)
{
	auto location = locateUniform(uniform);
	glUniform3f(location, v, v, v);
}

void Shader::set3f(const char* uniform, float v1, float v2, float v3)
{
	auto location = locateUniform(uniform);
	glUniform3f(location, v1, v2, v3);
}

void Shader::set3f(const char* uniform, const glm::vec3& v)
{
	auto location = locateUniform(uniform);
	glUniform3f(location, v.x, v.y, v.z);
}

void Shader::set3d(const char* uniform, double v)
{
	auto location = locateUniform(uniform);
	glUniform3d(location, v, v, v);
}

void Shader::set3d(const char* uniform, double v1, double v2, double v3)
{
	auto location = locateUniform(uniform);
	glUniform3d(location, v1, v2, v3);
}

void Shader::set3d(const char* uniform, const glm::vec3& v)
{
	auto location = locateUniform(uniform);
	glUniform3d(location, v.x, v.y, v.z);
}

void Shader::set4i(const char* uniform, int v)
{
	auto location = locateUniform(uniform);
	glUniform4i(location, v, v, v, v);
}

void Shader::set4i(const char* uniform, int v1, int v2, int v3, int v4)
{
	auto location = locateUniform(uniform);
	glUniform4f(location, v1, v2, v3, v4);
}

void Shader::set4i(const char* uniform, const glm::vec4& v)
{
	auto location = locateUniform(uniform);
	glUniform4i(location, v.x, v.y, v.z, v.w);
}

void Shader::set4f(const char* uniform, float v)
{
	auto location = locateUniform(uniform);
	glUniform4f(location, v, v, v, v);
}

void Shader::set4f(const char* uniform, float v1, float v2, float v3, float v4)
{
	auto location = locateUniform(uniform);
	glUniform4f(location, v1, v2, v3, v4);
}

void Shader::set4f(const char* uniform, const glm::vec4& v)
{
	auto location = locateUniform(uniform);
	glUniform4f(location, v.x, v.y, v.z, v.w);
}

void Shader::set4d(const char* uniform, double v)
{
	auto location = locateUniform(uniform);
	glUniform4d(location, v, v, v, v);
}

void Shader::set4d(const char* uniform, double v1, double v2, double v3, double v4)
{
	auto location = locateUniform(uniform);
	glUniform4d(location, v1, v2, v3, v4);
}

void Shader::set4d(const char* uniform, const glm::vec4& v)
{
	auto location = locateUniform(uniform);
	glUniform4d(location, v.x, v.y, v.z, v.w);
}

void Shader::setMat2(const char* uniform, const glm::mat2& mat)
{
	auto location = locateUniform(uniform);
	glUniformMatrix2fv(location, 1, GL_FALSE, glm::value_ptr(mat));
}

void Shader::setMat3(const char* uniform, const glm::mat3& mat)
{
	auto location = locateUniform(uniform);
	glUniformMatrix3fv(location, 1, GL_FALSE, glm::value_ptr(mat));
}

void Shader::setMat4(const char* uniform, const glm::mat4& mat)
{
	auto location = locateUniform(uniform);
	glUniformMatrix4fv(location, 1, GL_FALSE, glm::value_ptr(mat));
}

std::string Shader::load(std::string sourcePath)
{
	std::stringstream shaderSource;
	std::ifstream file;
	file.open(sourcePath);

	if (!file) printf("file not fount!\n");

	shaderSource << file.rdbuf();
	file.close();

	std::string result = shaderSource.str();
	//std::cout << result << std::endl;

	return result;
}

void Shader::createShader(int type, std::string sourcePath)
{
	uint32_t shader = glCreateShader(type);

	if (type == GL_VERTEX_SHADER)         m_vertexShader = shader;
	if (type == GL_FRAGMENT_SHADER)       m_fragmentShader = shader;

	std::string source = load(sourcePath);
	const char* shaderCode = source.c_str();

	glShaderSource(shader, 1, &shaderCode, NULL);
	glCompileShader(shader);
}

void Shader::createProgram()
{
	m_shaderProgram = glCreateProgram();
	glAttachShader(m_shaderProgram, m_vertexShader);
	glAttachShader(m_shaderProgram, m_fragmentShader);
	glLinkProgram(m_shaderProgram);
}

void Shader::clean()
{
	glDeleteShader(m_vertexShader);
	glDeleteShader(m_fragmentShader);
}

void Shader::catchErrors() const
{
	int psuccess;
	char pinfoLog[512];
	glGetProgramiv(m_shaderProgram, GL_LINK_STATUS, &psuccess);
	if (!psuccess)
	{
		glGetShaderInfoLog(m_shaderProgram, 512, NULL, pinfoLog);
		std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" <<
			pinfoLog << std::endl;
	}

	int vsuccess;
	char vinfoLog[512];
	glGetShaderiv(m_vertexShader, GL_COMPILE_STATUS, &vsuccess);
	if (!vsuccess)
	{
		glGetShaderInfoLog(m_vertexShader, 512, NULL, vinfoLog);
		std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" <<
			vinfoLog << std::endl;
	}

	int fsuccess;
	char finfoLog[512];
	glGetShaderiv(m_fragmentShader, GL_COMPILE_STATUS, &fsuccess);
	if (!fsuccess)
	{
		glGetShaderInfoLog(m_fragmentShader, 512, NULL, finfoLog);
		std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" <<
			finfoLog << std::endl;
	}
}

uint32_t Shader::locateUniform(const char* title)
{
	return glGetUniformLocation(m_shaderProgram, title);
}
