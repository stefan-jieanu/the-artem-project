#include "aepch.h"
#include "Renderer.h"

namespace ArtemEngine {

	RendererAPI::API RendererAPI::sAPI_ = RendererAPI::API::OpenGL;

	void Renderer::Begin()
	{

	}

	void Renderer::End()
	{

	}

	void Renderer::Submit(const std::shared_ptr<VertexArray>& vertexArray)
	{
		vertexArray->Bind();
		RenderCommand::DrawIndexed(vertexArray);
	}

}