#pragma once

#include "RenderCommand.h"

namespace ArtemEngine {

	class Renderer
	{
	public:
		static void Begin();
		static void End();

		static void Submit(const std::shared_ptr<VertexArray>& vertexArray);

		inline static RendererAPI::API GetAPI() { return RendererAPI::GetAPI(); }
	};
}

