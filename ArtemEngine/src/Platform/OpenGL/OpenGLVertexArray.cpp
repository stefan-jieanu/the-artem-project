#include "aepch.h"
#include "OpenGLVertexArray.h"

#include "glad/glad.h"

namespace ArtemEngine {

	static GLenum ShaderDataTypeToOpenGLBaseType(ShaderDataType type)
	{
		switch (type)
		{
			case ShaderDataType::Float:		return GL_FLOAT;
			case ShaderDataType::Float2:	return GL_FLOAT;
			case ShaderDataType::Float3:	return GL_FLOAT;
			case ShaderDataType::Float4:	return GL_FLOAT;
			case ShaderDataType::Mat3:		return GL_FLOAT;
			case ShaderDataType::Mat4:		return GL_FLOAT;
			case ShaderDataType::Int:		return GL_INT;
			case ShaderDataType::Int2:		return GL_INT;
			case ShaderDataType::Int3:		return GL_INT;
			case ShaderDataType::Int4:		return GL_INT;
			case ShaderDataType::Bool:		return GL_BOOL;
		}

		LOG_ASSERT(false, "Invalid shader data type!");
		return 0;
	}

	OpenGLVertexArray::OpenGLVertexArray()
	{
		glCreateVertexArrays(1, &vertexArrayID_);
	}

	OpenGLVertexArray::~OpenGLVertexArray()
	{
		glDeleteVertexArrays(1, &vertexArrayID_);
	}

	void OpenGLVertexArray::Bind() const
	{
		glBindVertexArray(vertexArrayID_);
	}

	void OpenGLVertexArray::Unbind() const
	{
		glBindVertexArray(0);
	}

	void OpenGLVertexArray::AddVertexBuffer(const std::shared_ptr<VertexBuffer>& vertexBuffer)
	{
		glBindVertexArray(vertexArrayID_);
		vertexBuffer->Bind();

		const auto& layout = vertexBuffer->GetLayout();
		const auto& elements = layout.GetElements();

		LOG_CORE_ASSERT(elements.size(), "VertexBuffer has no layout!");

		for (int i = 0; i < layout.GetElements().size(); i++)
		{
			glEnableVertexAttribArray(i),
				glVertexAttribPointer(i, elements[i].GetElementCount(),
				ShaderDataTypeToOpenGLBaseType(elements[i].type),
				elements[i].normalized ? GL_TRUE : GL_FALSE,
				layout.GetStride(),
				(const void*)elements[i].offset);
		}

		vertexBuffers_.push_back(vertexBuffer);
		glBindVertexArray(0);
		vertexBuffer->Unbind();
	}

	void OpenGLVertexArray::SetIndexBuffer(const std::shared_ptr<IndexBuffer>& indexBuffer)
	{
		glBindVertexArray(vertexArrayID_);
		indexBuffer->Bind();

		indexBuffer_ = indexBuffer;

		glBindVertexArray(0);
		indexBuffer->Unbind();
	}

}