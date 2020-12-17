#pragma once

#include <iostream>
#include <glm/ext/vector_float2.hpp>

namespace artem { namespace maths {
    class Vector2
    {
    private:
        glm::vec2 value_;
    public:
        Vector2();
        Vector2(float x, float y);

        // Basic methods
        Vector2& add(const Vector2& other);
        Vector2& subtract(const Vector2& other);
        Vector2& multiply(const Vector2& other);
        Vector2& divide(const Vector2& other);

        // Operator overloading
        friend std::ostream& operator<<(std::ostream& stream, const Vector2& vector2);

        // Getters
        inline float x() const { return value_.x; }
        inline float y() const { return value_.y; }
    };
} }