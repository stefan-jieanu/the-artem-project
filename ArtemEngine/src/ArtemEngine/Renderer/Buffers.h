#pragma once

#include "Vertex.h"
#include "Shader.h"

namespace ArtemEngine {

	/*************************************************/
	/*					BufferLayout  			     */
	/*************************************************/

	struct BufferElement
	{
		std::string name;
		ShaderDataType type;
		uint32_t offset;
		uint32_t size;
		bool normalized;

		BufferElement() {}
		BufferElement(ShaderDataType type, const std::string& name, bool normalized = false)
			: name(name), type(type), size(ShaderDataTypeSize(type)), offset(0), normalized(normalized) {}

		uint32_t GetElementCount() const
		{
			switch (type)
			{
			case ArtemEngine::ShaderDataType::Float:	return 1;
			case ArtemEngine::ShaderDataType::Float2:	return 2;
			case ArtemEngine::ShaderDataType::Float3:	return 3;
			case ArtemEngine::ShaderDataType::Float4:	return 4;
			case ArtemEngine::ShaderDataType::Mat3:		return 3 * 3;
			case ArtemEngine::ShaderDataType::Mat4:		return 4 * 4;
			case ArtemEngine::ShaderDataType::Int:		return 1;
			case ArtemEngine::ShaderDataType::Int2:		return 2;
			case ArtemEngine::ShaderDataType::Int3:		return 3;
			case ArtemEngine::ShaderDataType::Int4:		return 4;
			case ArtemEngine::ShaderDataType::Bool:		return 1;
			}
			LOG_ASSERT(false, "Invalid shader data type!");
			return 0;
		}
	};

	class BufferLayout
	{
	public:
		BufferLayout() {}
		BufferLayout(const std::initializer_list<BufferElement>& element)
			: elements_(element)
		{
			CalculateOffsetsAndStride();
		}

		inline uint32_t GetStride() const { return stride_; }
		inline const std::vector<BufferElement>& GetElements() const { return elements_; }
	private:
		std::vector<BufferElement> elements_;
		uint32_t stride_ = 0;

		void CalculateOffsetsAndStride()
		{
			uint32_t offset = 0;
			for (auto& element : elements_)
			{
				element.offset = offset;
				offset += element.size;
				stride_ += element.size;
			}
		}
	};

	/*************************************************/
	/*					VertexBuffer			     */
	/*************************************************/
	class VertexBuffer
	{
	public:
		virtual ~VertexBuffer() {}

		virtual void Bind() const = 0;
		virtual void Unbind() const = 0;

		virtual const BufferLayout& GetLayout() const = 0;
		virtual void SetLayout(const BufferLayout& layout) = 0;

		virtual void SetData(const void* data, uint32_t size) = 0;

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