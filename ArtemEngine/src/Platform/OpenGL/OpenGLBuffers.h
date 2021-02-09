#pragma once

#include "ArtemEngine/Renderer/Buffers.h"
#include "glad/glad.h"

namespace ArtemEngine {

	/*************************************************/
	/*					VertexBuffer			     */
	/*************************************************/
	class OpenGLVertexBuffer : public VertexBuffer
	{
	public:
		OpenGLVertexBuffer(float* vertices, uint32_t size);
		~OpenGLVertexBuffer();

		void Bind() const override;
		void Unbind() const override;

		inline void SetLayout(const BufferLayout& layout) override { layout_ = layout; }
		inline const BufferLayout& GetLayout() const override { return layout_; }
	private:
		uint32_t bufferID_;
		BufferLayout layout_;
	};

	/*************************************************/
	/*					IndexBuffer  			     */
	/*************************************************/
	class OpenGLIndexBuffer : public IndexBuffer
	{
	public:
		OpenGLIndexBuffer(uint32_t* indices, uint32_t count);
		~OpenGLIndexBuffer();

		void Bind() const override;
		void Unbind() const override;

		uint32_t GetCount() const override { return count_; }

	private:
		uint32_t bufferID_;
		uint32_t count_;
	};

}