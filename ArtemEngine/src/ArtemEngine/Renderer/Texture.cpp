#include "aepch.h"
#include "Texture.h"

#include "Renderer.h"
#include "Platform/OpenGL/OpenGLTexture.h"

namespace ArtemEngine {

	Shared<Texture> Texture::Create(const std::string& filepath)
	{
		switch (Renderer::GetAPI())
		{
			case RendererAPI::API::None: LOG_CORE_ASSERT(false, "RendererAPI::None is not supported!"); return nullptr;
			case RendererAPI::API::OpenGL: return std::make_shared<OpenGLTexture>(filepath);
		}

		LOG_CORE_ASSERT(false, "Unknown RendererAPI!");
		return nullptr;
	}

	Shared<Texture> Texture::Create(uint32_t width, uint32_t height)
	{
		switch (Renderer::GetAPI())
		{
			case RendererAPI::API::None: LOG_CORE_ASSERT(false, "RendererAPI::None is not supported!"); return nullptr;
			case RendererAPI::API::OpenGL: return std::make_shared<OpenGLTexture>(width, height);
		}

		LOG_CORE_ASSERT(false, "Unknown RendererAPI!");
		return nullptr;
	}


}