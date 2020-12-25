#pragma once

#include <../logging/log_gl.h>

namespace artem { namespace graphics {

    class VertexBuffer
    {
    private:
        unsigned int bufferID_;
    public:
        VertexBuffer(const void* data, unsigned int size);
        ~VertexBuffer();

        void Bind() const;
        void Unbind() const;
    };

} }

