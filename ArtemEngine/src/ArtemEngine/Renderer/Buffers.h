#pragma once

#include "Vertex.h"
#include "Shader.h"

namespace ArtemEngine {

	/*************************************************/
	/*					VertexBuffer			     */
	/*************************************************/
	class VertexBuffer
	{
	public:
		virtual ~VertexBuffer() {}

		virtual void Bind() const = 0;
		virtual void Unbind() const = 0;

		virtual const ShaderLayout& GetLayout() const = 0;
		virtual void SetLayout(const ShaderLayout& layout) = 0;

		virtual void SetData(const void* data, uint32_t size) = 0;
		virtual void* MapData() const = 0;

		static Shared<VertexBuffer> Create(uint32_t size);
		static Shared<VertexBuffer> Create(float* vertices, uint32_t size);
	};

	/*************************************************/
	/*					IndexBuffer  			     */
	/*************************************************/

	// Currently only supporting 32-bit index buffers
	class IndexBuffer
	{
	public:
		virtual ~IndexBuffer() {}

		virtual void Bind() const = 0;
		virtual void Unbind() const = 0;

		virtual uint32_t GetCount() const = 0;

		static Shared<IndexBuffer> Create(uint32_t* indices, uint32_t count);
	};

}