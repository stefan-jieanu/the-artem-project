#include "VertexBuffer.h"

namespace artem { namespace graphics {

    VertexBuffer::VertexBuffer(const void* data, unsigned int size, bool staticDraw)
    {
        GLCall(glGenBuffers(1, &bufferID_));
        GLCall(glBindBuffer(GL_ARRAY_BUFFER, bufferID_));
        GLCall(
            if (staticDraw)
                glBufferData(GL_ARRAY_BUFFER, size, data, GL_STATIC_DRAW);
            else
                glBufferData(GL_ARRAY_BUFFER, size, data, GL_DYNAMIC_DRAW)
            );
        GLCall(glBindBuffer(GL_ARRAY_BUFFER, 0));
    }

    VertexBuffer::~VertexBuffer()
    {
        glDeleteBuffers(1, &bufferID_);
    }

    void VertexBuffer::Bind() const
    {
        GLCall(glBindBuffer(GL_ARRAY_BUFFER, bufferID_));
    }

    void VertexBuffer::Unbind() const
    {
        glBindBuffer(GL_ARRAY_BUFFER, 0);
    }

} }