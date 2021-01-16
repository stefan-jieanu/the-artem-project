#pragma once

#include "Renderable2d.h"
#include "BatchRenderer.h"
#include "Texture.h"

namespace artem { namespace graphics {

    class Sprite
    {
    private:
        maths::Vector3 position_;
        maths::Vector3 size_;
        maths::Vector4 color_;
        std::vector<maths::Vector2> uv_;

        VertexData vertexData_;

        Texture* texture_;
        void Init();
    public:
        Sprite();
        Sprite(const maths::Vector3& position, const maths::Vector3& size, const maths::Vector4& color);
        Sprite(const maths::Vector3& position, const maths::Vector3& size, Texture* texture);
        ~Sprite();
        

        virtual void Submit(BatchRenderer* renderer) const 
        {
            renderer->Submit(this);
        }

        inline const maths::Vector3& GetPosition() const { return position_; }
        inline const maths::Vector3& GetSize() const { return size_; }
        inline const maths::Vector4& GetColor() const { return color_; }
        inline const std::vector<maths::Vector2>& GetUV() const { return uv_; }
        inline const unsigned int GetTextureID() const { return texture_ == nullptr ? 0 : texture_->GetID(); }
    };

} }