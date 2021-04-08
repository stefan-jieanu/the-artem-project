#include "aepch.h"
#include "Framebuffer.h"

#include "ArtemEngine/Renderer/Renderer.h"
#include "Platform/OpenGL/OpenGLFramebuffer.h"

namespace ArtemEngine {

	Shared<Framebuffer> Framebuffer::Create(const FramebufferProperties& props)
	{
		switch (Renderer::GetAPI())
		{
			case RendererAPI::API::None: LOG_CORE_ASSERT(false, "RendererAPI::None is not supported!"); return nullptr;
			case RendererAPI::API::OpenGL: return std::make_shared<OpenGLFramebuffer>(props);
		}

		LOG_CORE_ASSERT(false, "Unknown RendererAPI!");
		return nullptr;
	}

}