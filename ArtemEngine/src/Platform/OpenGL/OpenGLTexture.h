#pragma once

#include "ArtemEngine/Renderer/Texture.h"

namespace ArtemEngine {

	class OpenGLTexture : public Texture
	{
	public:
		OpenGLTexture(const std::string& filepath);
		OpenGLTexture(uint32_t width, uint32_t height);
		~OpenGLTexture();

		inline uint32_t GetWidth() const override { return width_; }
		inline uint32_t GetHeight() const override { return height_; }

		void SetData(void* data, uint32_t size);
		void Bind(uint32_t slot = 0) const override;

		bool operator==(const Texture& other) const override
		{
			return textureID_ == ((OpenGLTexture&)other).textureID_;
		}
	private:
		uint32_t width_, height_;
		uint32_t textureID_;
	};

}

