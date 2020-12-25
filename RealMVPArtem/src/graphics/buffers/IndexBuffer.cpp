#include "IndexBuffer.h"

namespace artem { namespace graphics {

    IndexBuffer::IndexBuffer(const unsigned int* data, unsigned int count)
        : count_(count)
    {
        glGenBuffers(1, &bufferID_);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, bufferID_);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, count * sizeof(unsigned int), data, GL_STATIC_DRAW);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
    }

    IndexBuffer::~IndexBuffer()
    {
        glDeleteBuffers(1, &bufferID_);
    }

    void IndexBuffer::Bind() const
    {
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, bufferID_);
    }

    void IndexBuffer::Unbind() const
    {
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
    }

} }