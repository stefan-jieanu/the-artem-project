#pragma once

#include "Renderable2d.h"

namespace artem { namespace graphics {

    class Sprite
    {
    private:
        maths::Vector3 position_;
        maths::Vector3 size_;
        maths::Vector4 color_;

        VertexData vertexData_;
    public:
        Sprite();
        Sprite(const maths::Vector3& position, const maths::Vector3& size, const maths::Vector4& color);
        ~Sprite();

        inline const maths::Vector3& GetPosition() const { return position_; }
        inline const maths::Vector3& GetSize() const { return size_; }
        inline const maths::Vector4& GetColor() const { return color_; }
    };

} }