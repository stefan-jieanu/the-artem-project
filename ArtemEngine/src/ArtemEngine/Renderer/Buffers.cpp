#include "aepch.h"
#include "Buffers.h"

#include "Renderer.h"
#include "Platform/OpenGL/OpenGLBuffers.h"

namespace ArtemEngine
{
	Shared<VertexBuffer> VertexBuffer::Create(uint32_t size)
	{
		switch (Renderer::GetAPI())
		{
			case RendererAPI::API::None: LOG_CORE_ASSERT(false, "RendererAPI::None is not supported!"); return nullptr;
			case RendererAPI::API::OpenGL: return MakeShared<OpenGLVertexBuffer>(size);
		}

		LOG_CORE_ASSERT(false, "Unknown RendererAPI!");
		return nullptr;
	}


	Shared<VertexBuffer> VertexBuffer::Create(float* vertices, uint32_t size)
	{
		switch (Renderer::GetAPI())
		{
			case RendererAPI::API::None: LOG_CORE_ASSERT(false, "RendererAPI::None is not supported!"); return nullptr;
			case RendererAPI::API::OpenGL: return MakeShared<OpenGLVertexBuffer>(vertices, size);
		}

		LOG_CORE_ASSERT(false, "Unknown RendererAPI!");
		return nullptr;
	}


	Shared<IndexBuffer> IndexBuffer::Create(uint32_t* indices, uint32_t count)
	{
		switch (Renderer::GetAPI())
		{
			case RendererAPI::API::None: LOG_CORE_ASSERT(false, "RendererAPI::None is not supported!"); return nullptr;
			case RendererAPI::API::OpenGL: return MakeShared<OpenGLIndexBuffer>(indices, count);
		}

		LOG_CORE_ASSERT(false, "Unknown RendererAPI!");
		return nullptr;
	}

}