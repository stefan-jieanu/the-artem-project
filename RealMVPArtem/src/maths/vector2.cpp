#include "Vector2.h"

namespace artem { namespace maths {
    Vector2::Vector2()
    {
        value_ = glm::vec2(0, 0);
    }

    Vector2::Vector2(float x, float y)
    {
        value_ = glm::vec2(x, y);
    }

    Vector2& Vector2::add(const Vector2& other)
    {
        value_.x += other.value_.x;
        value_.y += other.value_.y;

        return *this;
    }

    Vector2& Vector2::subtract(const Vector2& other)
    {
        value_.x -= other.value_.x;
        value_.y -= other.value_.y;

        return *this;
    }

    Vector2& Vector2::multiply(const Vector2& other)
    {
        value_.x *= other.value_.x;
        value_.y *= other.value_.y;

        return *this;
    }

    Vector2& Vector2::divide(const Vector2& other)
    {
        value_.x /= other.value_.x;
        value_.y /= other.value_.y;

        return *this;
    }

    std::ostream& operator<<(std::ostream& stream, const Vector2& vector2)
    {
        stream << "Vector2(" << vector2.value_.x << ", " << vector2.value_.y << ")"; 
        return stream;
    }
} }