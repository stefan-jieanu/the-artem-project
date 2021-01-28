#pragma once

#include "RenderCommand.h"
#include "OrthographicCamera.h"
#include "Shader.h"
#include "ArtemEngine/Math/math.h"

namespace ArtemEngine {

	class Renderer
	{
	public:
		static void Begin(const OrthographicCamera& camera);
		static void End();

		static void Submit(const std::shared_ptr<Shader>& shader, const std::shared_ptr<VertexArray>& vertexArray);

		inline static RendererAPI::API GetAPI() { return RendererAPI::GetAPI(); }
	private:
		struct SceneData 
		{
			Math::Matrix4 projectionViewMatrix_;
		};

		static SceneData* sSceneData_;
	};
}

