#include "aepch.h"
#include "OpenGLBuffers.h"

namespace ArtemEngine {

	/*************************************************/
	/*					VertexBuffer			     */	
	/*************************************************/
	OpenGLVertexBuffer::OpenGLVertexBuffer(uint32_t size)
	{
		glCreateBuffers(1, &bufferID_);
		glBindBuffer(GL_ARRAY_BUFFER, bufferID_);
		glBufferData(GL_ARRAY_BUFFER, size, nullptr, GL_DYNAMIC_DRAW);
		glBindBuffer(GL_ARRAY_BUFFER, 0);
	}

	OpenGLVertexBuffer::OpenGLVertexBuffer(float* vertices, uint32_t size)
	{
		glCreateBuffers(1, &bufferID_);
		glBindBuffer(GL_ARRAY_BUFFER, bufferID_);
		glBufferData(GL_ARRAY_BUFFER, size, vertices, GL_STATIC_DRAW);
		glBindBuffer(GL_ARRAY_BUFFER, 0);
	}

	OpenGLVertexBuffer::~OpenGLVertexBuffer()
	{
		glDeleteBuffers(1, &bufferID_);
	}

	void OpenGLVertexBuffer::SetData(const void* data, uint32_t size)
	{
		glBindBuffer(GL_ARRAY_BUFFER, bufferID_);
		glBufferSubData(GL_ARRAY_BUFFER, 0, size, data);
	}

	void* OpenGLVertexBuffer::MapData() const
	{
		glBindBuffer(GL_ARRAY_BUFFER, bufferID_);
		return glMapBuffer(GL_ARRAY_BUFFER, GL_WRITE_ONLY);
	}


	void OpenGLVertexBuffer::Bind() const
	{
		glBindBuffer(GL_ARRAY_BUFFER, bufferID_);
	}

	void OpenGLVertexBuffer::Unbind() const
	{
		glBindBuffer(GL_ARRAY_BUFFER, 0);
	}

	/*************************************************/
	/*					IndexBuffer  			     */
	/*************************************************/
	OpenGLIndexBuffer::OpenGLIndexBuffer(uint32_t* indices, uint32_t count)
		: count_(count)
	{
		glCreateBuffers(1, &bufferID_);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, bufferID_);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, count * sizeof(uint32_t), indices, GL_STATIC_DRAW);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
	}

	OpenGLIndexBuffer::~OpenGLIndexBuffer()
	{
		glDeleteBuffers(1, &bufferID_);
	}

	void OpenGLIndexBuffer::Bind() const
	{
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, bufferID_);
	}

	void OpenGLIndexBuffer::Unbind() const
	{
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
	}
}

