#include "aepch.h"
#include "Renderer.h"

namespace ArtemEngine {

	Renderer::SceneData* Renderer::sSceneData_ = new Renderer::SceneData;

	void Renderer::Begin(const OrthographicCamera& camera)
	{
		sSceneData_->projectionViewMatrix_ = camera.GetProjectionViewMatrix();
	}

	void Renderer::End()
	{

	}

	void Renderer::Submit(const std::shared_ptr<Shader>& shader, const std::shared_ptr<VertexArray>& vertexArray)
	{
		shader->Bind();
		shader->SetUniformMat4f("u_ProjectionView", sSceneData_->projectionViewMatrix_);

		vertexArray->Bind();
		RenderCommand::DrawIndexed(vertexArray);
	}

}