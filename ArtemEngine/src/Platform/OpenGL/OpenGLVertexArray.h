#pragma once

#include "ArtemEngine/Renderer/VertexArray.h"

namespace ArtemEngine {

	class OpenGLVertexArray : public VertexArray
	{
	public:
		OpenGLVertexArray();
		~OpenGLVertexArray();

		void Bind() const override;
		void Unbind() const override;

		void AddVertexBuffer(const Shared<VertexBuffer>& vertexBuffer) override;
		void SetIndexBuffer(const Shared<IndexBuffer>& indexBuffer) override;

		const std::vector<Shared<VertexBuffer>>& GetVertexBuffers() const override { return vertexBuffers_; }
		const Shared<IndexBuffer>& GetIndexBuffer() const override { return indexBuffer_; }
	private:
		std::vector<Shared<VertexBuffer>> vertexBuffers_;
		Shared<IndexBuffer> indexBuffer_;
		uint32_t vertexArrayID_;
	};

}