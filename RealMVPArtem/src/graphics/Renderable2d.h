#pragma once

#include "buffers/buffers.h"
#include "../maths/maths.h"
#include "../graphics/Shader.h"

namespace artem { namespace graphics {

    struct VertexData
    {
        maths::Vector3 position;
        maths::Vector2 uv;
        float tid;
        unsigned int color;
    };

    class Renderable2d
    {
    protected:
        maths::Vector3 position_;
        maths::Vector3 size_;
        maths::Vector4 color_;

        VertexArray* vertexArray_;
        IndexBuffer* indexBuffer_;
        Shader& shader_;

    public:
        Renderable2d(maths::Vector3 position, maths::Vector3 size, maths::Vector4 color, Shader& shader)
            : position_(position), size_(size), color_(color), shader_(shader)
        {
            vertexArray_ = new VertexArray();

            const int vertexDataCount = 4 * 3;
            float vertices[vertexDataCount] = {
                0, 0, 0,           //color.x, color.y, color.z, color.w,
                0, 1, 0,      //color.x, color.y, color.z, color.w,
                1, 1, 0, //color.x, color.y, color.z, color.w,
                1, 0, 0,      //color.x, color.y, color.z, color.w,
            };

            VertexBuffer vertexData(vertices, vertexDataCount * sizeof(float), true);
            VertexBufferLayout layout;
            layout.Push<float>(3, false);
            // layout.Push<float>(4, false);
            vertexArray_->AddBuffer(vertexData, layout);

            unsigned int indices[] = { 0, 1, 2, 2, 3, 0 };
            indexBuffer_ = new IndexBuffer(indices, 6);
        }

        virtual ~Renderable2d()
        {
            delete vertexArray_;
            delete indexBuffer_;
        }
    public:
        inline const VertexArray* GetVAO() const { return vertexArray_; }
        inline const IndexBuffer* GetIBO() const { return indexBuffer_; }

        inline Shader& GetShader() const { return shader_; }

        inline const maths::Vector3& GetPosition() const { return position_; }
        inline const maths::Vector3& GetSize() const { return size_; }
        inline const maths::Vector4& GetColor() const { return color_; }
    };

} }