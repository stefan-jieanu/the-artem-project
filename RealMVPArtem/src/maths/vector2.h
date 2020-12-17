#pragma once

#include <iostream>

namespace artem {
    namespace maths {
        struct Vector2
        {
            float x, y;

            Vector2();
            Vector2(const float x, const float y);

            // Basic methods
            Vector2& add(const Vector2& other);
            Vector2& subtract(const Vector2& other);
            Vector2& multiply(const float& scalar);
            Vector2& divide(const float& scalar);

            // Operator overloading
            friend Vector2& operator+(Vector2 left, const Vector2& right);
            friend Vector2& operator-(Vector2 left, const Vector2& right);
            friend Vector2& operator*(Vector2 vec, const float& scalar);
            friend Vector2& operator/(Vector2 vec, const float& scalar);

            bool operator==(const Vector2& other);
            bool operator!=(const Vector2& other);

            Vector2& operator+=(const Vector2& other);
            Vector2& operator-=(const Vector2& other);
            Vector2& operator*=(const float& scalar);
            Vector2& operator/=(const float& scalar);

            friend std::ostream& operator<<(std::ostream& stream, const Vector2& vector2);
        };
    }
}