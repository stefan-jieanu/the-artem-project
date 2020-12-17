#include "Vector2.h"

namespace artem {
    namespace maths {
        Vector2::Vector2()
        {
            x = 0.0f;
            y = 0.0f;
        }

        Vector2::Vector2(const float x, const float y)
        {
            this->x = x;
            this->y = y;
        }

        Vector2& Vector2::add(const Vector2& other)
        {
            x += other.x;
            y += other.y;
            return *this;
        }

        Vector2& Vector2::subtract(const Vector2& other)
        {
            x -= other.x;
            y -= other.y;
            return *this;
        }

        Vector2& Vector2::multiply(const float& scalar)
        {
            x *= scalar;
            y *= scalar;
            return *this;
        }

        Vector2& Vector2::divide(const float& scalar)
        {
            x /= scalar;
            y /= scalar;
            return *this;
        }

        Vector2& operator+(Vector2 left, const Vector2& right)
        {
            return left.add(right);
        }

        Vector2& operator-(Vector2 left, const Vector2& right)
        {
            return left.subtract(right);
        }

        Vector2& operator*(Vector2 left, const float& scalar)
        {
            return left.multiply(scalar);
        }

        Vector2& operator/(Vector2 left, const float& scalar)
        {
            return left.divide(scalar);
        }

        bool Vector2::operator==(const Vector2& other)
        {
            return x == other.x && y == other.y;
        }

        bool Vector2::operator!=(const Vector2& other)
        {
            return x != other.x && y != other.y;
        }

        Vector2& Vector2::operator+=(const Vector2& other)
        {
            return add(other);
        }

        Vector2& Vector2::operator-=(const Vector2& other)
        {
            return subtract(other);
        }

        Vector2& Vector2::operator*=(const float& scalar)
        {
            return multiply(scalar);
        }

        Vector2& Vector2::operator/=(const float& scalar)
        {
            return divide(scalar);
        }

        std::ostream& operator<<(std::ostream& stream, const Vector2& vector2)
        {
            stream << "Vector2(" << vector2.x << ", " << vector2.y << ")";
            return stream;
        }
    }
}