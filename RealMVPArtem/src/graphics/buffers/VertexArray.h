#pragma once

#include <vector>
#include "VertexBuffer.h"
#include "VertexBufferLayout.h"

namespace artem { namespace graphics {

    class VertexArray
    {
    private:
        unsigned int vertexArrayID_;
    public:
        VertexArray();
        ~VertexArray();

        void AddBuffer(const VertexBuffer& vertexBuffer, const VertexBufferLayout& layout);

        void Bind() const;
        void Unbind() const;
    };
    
} }

