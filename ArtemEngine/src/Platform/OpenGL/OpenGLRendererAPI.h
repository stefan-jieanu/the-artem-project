#pragma once

#include "ArtemEngine/Renderer/RendererAPI.h"

namespace ArtemEngine {

	class OpenGLRendererAPI : public RendererAPI
	{
		virtual void SetClearColor(const Color& color) override;
		virtual void Clear() override;

		virtual void DrawIndexed(const Shared<VertexArray>& vertexArray) override;

	};

}