#include "aepch.h"
#include "Renderer.h"

#include "Platform/OpenGL/OpenGLShader.h"

namespace ArtemEngine {

	Renderer::SceneData* Renderer::sSceneData_ = new Renderer::SceneData;

	void Renderer::Begin(const OrthographicCamera& camera)
	{
		sSceneData_->projectionViewMatrix_ = camera.GetProjectionViewMatrix();
	}

	void Renderer::End()
	{

	}

	void Renderer::Submit(const Shared<Shader>& shader, const Shared<VertexArray>& vertexArray)
	{
		shader->Bind();
		shader->SetUniformMat4("u_ProjectionView", sSceneData_->projectionViewMatrix_);

		vertexArray->Bind();
		RenderCommand::DrawIndexed(vertexArray);
	}

}