#pragma once

#include "OrthographicCamera.h"
#include "Color.h"
#include "Texture.h"
#include "Vertex.h"
#include "Shader.h"

namespace ArtemEngine {

	class Renderer2D
	{
	public:
		static void Init();
		static void Terminate();

		static void SetCamera(const OrthographicCamera& camera);

		template<typename T>
		static void BeginBatch(T vertexType, Shared<Shader> shader);

		static void Submit();
		static void EndBatch();
		static void Flush();
		static void FlushAndReset();
	};

}

