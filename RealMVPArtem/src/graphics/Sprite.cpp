#include "Sprite.h"

namespace artem { namespace graphics {

    Sprite::Sprite()
    {
        
    }

    Sprite::Sprite(const maths::Vector3& position, const maths::Vector3& size, const maths::Vector4& color)
        : position_(position), size_(size), color_(color)
    {
        Init();   
    }

    Sprite::Sprite(const maths::Vector3& position, const maths::Vector3& size, Texture* texture)
        : position_(position), size_(size), texture_(texture)
    {
        // If a texture is passed in make the default color a pink
        color_ = maths::Vector4(1.0f, 0.0f, 0.8f, 1.0f);

        Init();
    }   

    Sprite::~Sprite()
    {

    }

    void Sprite::Init()
    {
        // Setting the UV defaults
        uv_.push_back(maths::Vector2(0, 0));
        uv_.push_back(maths::Vector2(0, 1));
        uv_.push_back(maths::Vector2(1, 1));
        uv_.push_back(maths::Vector2(1, 0));
    }

} }