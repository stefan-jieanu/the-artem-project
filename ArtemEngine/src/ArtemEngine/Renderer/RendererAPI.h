#pragma once

#include "Color.h"
#include "VertexArray.h"

namespace ArtemEngine {

	class RendererAPI
	{
	public:
		enum class API
		{
			None = 0, OpenGL = 1
		};

		virtual void SetClearColor(const Color& color) = 0;
		virtual void Clear() = 0;

		virtual void DrawIndexed(const Shared<VertexArray>& vertexArray) = 0;

		inline static API GetAPI() { return sAPI_; }
	private:
		static API sAPI_;
	};

}