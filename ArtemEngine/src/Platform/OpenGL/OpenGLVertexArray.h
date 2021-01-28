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

		void AddVertexBuffer(const std::shared_ptr<VertexBuffer>& vertexBuffer) override;
		void SetIndexBuffer(const std::shared_ptr<IndexBuffer>& indexBuffer) override;

		const std::vector<std::shared_ptr<VertexBuffer>>& GetVertexBuffers() const override { return vertexBuffers_; }
		const std::shared_ptr<IndexBuffer>& GetIndexBuffer() const override { return indexBuffer_; }
	private:
		std::vector<std::shared_ptr<VertexBuffer>> vertexBuffers_;
		std::shared_ptr<IndexBuffer> indexBuffer_;
		uint32_t vertexArrayID_;
	};

}