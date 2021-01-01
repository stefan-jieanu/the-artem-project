#include "Sprite.h"

namespace artem { namespace graphics {

    Sprite::Sprite()
    {
        
    }

    Sprite::Sprite(const maths::Vector3& position, const maths::Vector3& size, const maths::Vector4& color)
        : position_(position), size_(size), color_(color)
    {

    }

    Sprite::~Sprite()
    {

    }

} }