#include "aepch.h"
#include "OpenGLTexture.h"

#define STB_IMAGE_IMPLEMENTATION
#include <stb_image.h>

#include <glad/glad.h>

namespace ArtemEngine {
	
	OpenGLTexture::OpenGLTexture(const std::string& filepath)
	{
		int width, height, channels;
		stbi_set_flip_vertically_on_load(true);
		unsigned char* data = stbi_load(filepath.c_str(), &width, &height, &channels, 0);
		LOG_CORE_ASSERT(data, "Failed to laod image!");

		width_ = width;
		height_ = height;

		glCreateTextures(GL_TEXTURE_2D, 1, &textureID_);

		if (channels == 3)
			glTextureStorage2D(textureID_, 1, GL_RGB8, width_, height_);
		else if (channels == 4)
			glTextureStorage2D(textureID_, 1, GL_RGBA8, width_, height_);
		else
			LOG_CORE_ASSERT(false, "Unknown image format!");

		glTextureParameteri(textureID_, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTextureParameteri(textureID_, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

		if (channels == 3)
			glTextureSubImage2D(textureID_, 0, 0, 0, width_, height_, GL_RGB, GL_UNSIGNED_BYTE, data);
		else if (channels == 4)
			glTextureSubImage2D(textureID_, 0, 0, 0, width_, height_, GL_RGBA, GL_UNSIGNED_BYTE, data);

		stbi_image_free(data);
	}

	OpenGLTexture::OpenGLTexture(uint32_t width, uint32_t height)
		:width_(width), height_(height)
	{
		glCreateTextures(GL_TEXTURE_2D, 1, &textureID_);
		glTextureStorage2D(textureID_, 1, GL_RGBA8, width_, height_);

		glTextureParameteri(textureID_, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTextureParameteri(textureID_, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	}


	OpenGLTexture::~OpenGLTexture()
	{
		glDeleteTextures(1, &textureID_);
	}

	void OpenGLTexture::SetData(void* data, uint32_t size)
	{
		glTextureSubImage2D(textureID_, 0, 0, 0, width_, height_, GL_RGBA, GL_UNSIGNED_BYTE, data);
	}

	void OpenGLTexture::Bind(uint32_t slot) const
	{
		glBindTextureUnit(slot, textureID_);
	}

}

#undef STB_IMAGE_IMPLEMENTATION