#pragma once

#include <../logging/log_gl.h>

namespace artem { namespace graphics {

    class IndexBuffer
    {
    private:
        unsigned int bufferID_;
        unsigned int count_;
    public:
        IndexBuffer(const unsigned int* data, unsigned int count);
        ~IndexBuffer();

        void Bind() const;
        void Unbind() const;

        inline int GetCount() const { return count_; }
    };

} }

