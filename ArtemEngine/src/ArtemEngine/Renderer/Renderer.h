#pragma once

#include "RenderCommand.h"
#include "OrthographicCamera.h"
#include "Shader.h"
#include "ArtemEngine/Math/math.h"

namespace ArtemEngine {

	class Renderer
	{
	public:
		static void OnWindowResize(uint32_t width, uint32_t heigth);

		static void Begin(const OrthographicCamera& camera);
		static void End();

		static void Submit(const Shared<Shader>& shader, const Shared<VertexArray>& vertexArray);

		inline static RendererAPI::API GetAPI() { return RendererAPI::GetAPI(); }
	private:
		struct SceneData 
		{
			Math::Matrix4 projectionViewMatrix_;
		};

		static SceneData* sSceneData_;
	};
}

