#include "aepch.h"
#include "Buffers.h"

#include "Renderer.h"
#include "Platform/OpenGL/OpenGLBuffers.h"

namespace ArtemEngine
{
	VertexBuffer* VertexBuffer::Create(float* vertices, uint32_t size)
	{
		switch (Renderer::GetAPI())
		{
			case RendererAPI::API::None: LOG_CORE_ASSERT(false, "RendererAPI::None is not supported!"); return nullptr;
			case RendererAPI::API::OpenGL: return new OpenGLVertexBuffer(vertices, size);
		}

		LOG_CORE_ASSERT(false, "Unknown RendererAPI!");
		return nullptr;
	}


	IndexBuffer* IndexBuffer::Create(uint32_t* indices, uint32_t count)
	{
		switch (Renderer::GetAPI())
		{
			case RendererAPI::API::None: LOG_CORE_ASSERT(false, "RendererAPI::None is not supported!"); return nullptr;
			case RendererAPI::API::OpenGL: return new OpenGLIndexBuffer(indices, count);
		}

		LOG_CORE_ASSERT(false, "Unknown RendererAPI!");
		return nullptr;
	}

}