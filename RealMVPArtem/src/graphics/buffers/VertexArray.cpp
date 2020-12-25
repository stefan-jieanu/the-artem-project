#include "VertexArray.h"

namespace artem { namespace graphics {

    VertexArray::VertexArray()
    {    
        GLCall(glGenVertexArrays(1, &vertexArrayID_));
    }

    VertexArray::~VertexArray()
    {
        glDeleteVertexArrays(1, &vertexArrayID_);
    }

    void VertexArray::AddBuffer(const VertexBuffer& vertexBuffer, const VertexBufferLayout& layout)
    {
        Bind();
        vertexBuffer.Bind();
        const std::vector<VertexBufferElement> elements = layout.GetElements(); 
        unsigned int offset = 0;

        for (int i = 0; i < elements.size(); i++)
        {
            const VertexBufferElement element = elements[i];
            GLCall(glEnableVertexAttribArray(i));
            GLCall(glVertexAttribPointer(i, element.count, element.type, element.normalized, layout.GetStride(), (const void*)offset));
            offset += element.count * VertexBufferElement::GetSizeOfType(element.type);
        }
        vertexBuffer.Unbind();
        Unbind();
    }

    void VertexArray::Bind() const
    {
        GLCall(glBindVertexArray(vertexArrayID_));
    }

    void VertexArray::Unbind() const
    {
        GLCall(glBindVertexArray(0));
    }
    
} }
