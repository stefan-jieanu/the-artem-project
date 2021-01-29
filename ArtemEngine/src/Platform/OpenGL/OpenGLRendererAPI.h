#pragma once

#include "ArtemEngine/Renderer/RendererAPI.h"

namespace ArtemEngine {

	class OpenGLRendererAPI : public RendererAPI
	{
		void SetViewport(uint32_t x, uint32_t y, uint32_t width, uint32_t height) override;
		void SetClearColor(const Color& color) override;
		void Clear() override;

		void DrawIndexed(const Shared<VertexArray>& vertexArray) override;

	};

}