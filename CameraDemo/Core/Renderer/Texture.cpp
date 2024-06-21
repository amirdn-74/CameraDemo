#include "Texture.h"

Texture::Texture(const std::string& fileName)
{
	std::stringstream path;
	path << std::filesystem::current_path().string();
	path << "\\";
	path << fileName;

	if (loadImage(path.str().c_str()))
	{
		glGenTextures(1, &m_textureId);
		glBindTexture(GL_TEXTURE_2D, m_textureId);

		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

		//glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, m_width, m_height, 0, GL_RGB, GL_UNSIGNED_INT, m_imageData);
		//glGenerateMipmap(GL_TEXTURE_2D);
	}
	else
		std::cout << "Failed to load texture: " << stbi_failure_reason() << std::endl;
	clean();
}

void Texture::bind() const
{
	glBindTexture(GL_TEXTURE_2D, m_textureId);
}

void Texture::unbind() const
{
	glBindTexture(GL_TEXTURE_2D, 0);
}

void Texture::clean() const
{
	stbi_image_free(m_imageData);
}

bool Texture::loadImage(const char* path, bool reverse)
{
	m_imageData = stbi_load(path, &m_width, &m_height, &m_channels, 0);
	stbi_set_flip_vertically_on_load(true);

	if (!m_imageData)
	{
		std::cout << "Failed to load texture: " << stbi_failure_reason() << std::endl;
		return false;
	}

	return true;
}
