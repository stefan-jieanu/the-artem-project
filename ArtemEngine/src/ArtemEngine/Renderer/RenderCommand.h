#pragma once

#include "RendererAPI.h"

namespace ArtemEngine {

	class RenderCommand
	{
	public:
		inline static void SetClearColor(const Color& color)
		{
			sRendererAPI_->SetClearColor(color);
		}

		inline static void Clear()
		{
			sRendererAPI_->Clear();
		}

		inline static void DrawIndexed(const Shared<VertexArray>& vertexArray)
		{
			sRendererAPI_->DrawIndexed(vertexArray);
		}
	private:
		static RendererAPI* sRendererAPI_;
	};

}