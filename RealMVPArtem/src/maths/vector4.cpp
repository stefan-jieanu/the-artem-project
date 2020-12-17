#include "Vector4.h"

namespace artem { namespace maths {
    Vector4::Vector4()
    {
        x = 0.0f;
        y = 0.0f;
        z = 0.0f;
        w = 0.0f;
    }

    Vector4::Vector4(const float x, const float y, const float z, const float w)
    {
        this->x = x;
        this->y = y;
        this->z = z;
        this->w = w;
    }

    Vector4& Vector4::add(const Vector4& other)
    {
        x += other.x;
        y += other.y;
        z += other.z;
        w += other.w;
        return *this;
    }

    Vector4& Vector4::subtract(const Vector4& other)
    {
        x -= other.x;
        y -= other.y;
        z -= other.z;
        w -= other.w;
        return *this;
    }

    Vector4& Vector4::multiply(const float& scalar)
    {
        x *= scalar;
        y *= scalar;
        z *= scalar;
        w *= scalar;
        return *this;
    }

    Vector4& Vector4::divide(const float& scalar)
    {
        x /= scalar;
        y /= scalar;
        z /= scalar;
        w /= scalar;
        return *this;
    }

    Vector4& operator+(Vector4 left, const Vector4& right)
    {
        return left.add(right);
    }

    Vector4& operator-(Vector4 left, const Vector4& right)
    {
        return left.subtract(right);
    }

    Vector4& operator*(Vector4 left, const float& scalar)
    {
        return left.multiply(scalar);
    }

    Vector4& operator/(Vector4 left, const float& scalar)
    {
        return left.divide(scalar);
    }

    bool Vector4::operator==(const Vector4& other)
    {
        return x == other.x && y == other.y && z == other.z && w == other.w;
    }

    bool Vector4::operator!=(const Vector4& other)
    {
        return x != other.x && y != other.y && z != other.z && w!= other.w;
    }

    Vector4& Vector4::operator+=(const Vector4& other)
    {
        return add(other);
    }

    Vector4& Vector4::operator-=(const Vector4& other)
    {
        return subtract(other);
    }

    Vector4& Vector4::operator*=(const float& scalar)
    {
        return multiply(scalar);
    }

    Vector4& Vector4::operator/=(const float& scalar)
    {
        return divide(scalar);
    }
    
    std::ostream& operator<<(std::ostream& stream, const Vector4& vector4)
    {
        stream << "Vector4(" << vector4.x << ", " << vector4.y << ", " << vector4.z << ", " << vector4.w << ")";
        return stream;
    }
} }