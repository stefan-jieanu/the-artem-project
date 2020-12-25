#pragma once

#include <vector>
#include "../logging/log_gl.h"

namespace artem { namespace graphics {

    struct VertexBufferElement
    {
        unsigned int type;
        unsigned int count;
        int normalized;

        static unsigned int GetSizeOfType(unsigned int type)
        {
            switch (type)
            {
                case GL_FLOAT:        return sizeof(GLfloat);
                case GL_UNSIGNED_INT: return sizeof(GLuint);
                case GL_BYTE:         return sizeof(GLbyte);
            }
            ASSERT(false);
            return 0;
        }
    };

    class VertexBufferLayout
    {
    private:
        std::vector<VertexBufferElement> elements_;
        unsigned int stride_;
    public:
        VertexBufferLayout()
            : stride_(0) {}

        template<typename T>
        void Push(unsigned int count, bool normalized)
        {
            static_assert(false);
        }

        template<>
        void Push<float>(unsigned int count, bool normalized)
        {
            elements_.push_back({GL_FLOAT, count, normalized ? GL_TRUE : GL_FALSE});
            stride_ += count * VertexBufferElement::GetSizeOfType(GL_FLOAT);
        }

        template<>
        void Push<unsigned int>(unsigned int count, bool normalized)
        {
            elements_.push_back({GL_UNSIGNED_INT, count, normalized ? GL_TRUE : GL_FALSE});
            stride_ += count * VertexBufferElement::GetSizeOfType(GL_UNSIGNED_INT);
        }

        template<>
        void Push<unsigned char>(unsigned int count, bool normalized)
        {
            elements_.push_back({GL_UNSIGNED_BYTE, count, normalized ? GL_TRUE : GL_FALSE});
            stride_ += count * VertexBufferElement::GetSizeOfType(GL_BYTE);
        }

        inline const std::vector<VertexBufferElement>& GetElements() const { return elements_; }
        inline unsigned int GetStride() const { return stride_; }
    };

}}