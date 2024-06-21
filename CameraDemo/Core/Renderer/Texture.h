#pragma once

#include <string>
#include <iostream>
#include <filesystem>
#include <glad/glad.h>

#include "../Vendor/StbImage/StbImage.h"




class Texture
{
private:
	unsigned int m_textureId;
	unsigned char* m_imageData;
	int m_width, m_height, m_channels;

public:
	Texture(const std::string& path);

	void bind() const;
	void unbind() const;
	void clean() const;

private:
	bool loadImage(const char* path, bool reverse = true);
};