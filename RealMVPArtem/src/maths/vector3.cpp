#include "Vector3.h"

namespace artem { namespace maths {
    Vector3::Vector3()
    {
        x = 0.0f;
        y = 0.0f;
        z = 0.0f;
    }

    Vector3::Vector3(const float x, const float y, const float z)
    {
        this->x = x;
        this->y = y;
        this->z = z;
    }

    Vector3& Vector3::add(const Vector3& other)
    {
        x += other.x;
        y += other.y;
        z += other.z;
        return *this;
    }

    Vector3& Vector3::subtract(const Vector3& other)
    {
        x -= other.x;
        y -= other.y;
        z -= other.z;
        return *this;
    }

    Vector3& Vector3::multiply(const float& scalar)
    {
        x *= scalar;
        y *= scalar;
        z *= scalar;
        return *this;
    }

    Vector3& Vector3::divide(const float& scalar)
    {
        x /= scalar;
        y /= scalar;
        z /= scalar;
        return *this;
    }

    Vector3& operator+(Vector3 left, const Vector3& right)
    {
        return left.add(right);
    }

    Vector3& operator-(Vector3 left, const Vector3& right)
    {
        return left.subtract(right);
    }

    Vector3& operator*(Vector3 left, const float& scalar)
    {
        return left.multiply(scalar);
    }

    Vector3& operator/(Vector3 left, const float& scalar)
    {
        return left.divide(scalar);
    }

    bool Vector3::operator==(const Vector3& other)
    {
        return x == other.x && y == other.y && z == other.z;
    }

    bool Vector3::operator!=(const Vector3& other)
    {
        return x != other.x && y != other.y && z != other.z;
    }

    Vector3& Vector3::operator+=(const Vector3& other)
    {
        return add(other);
    }

    Vector3& Vector3::operator-=(const Vector3& other)
    {
        return subtract(other);
    }

    Vector3& Vector3::operator*=(const float& scalar)
    {
        return multiply(scalar);
    }

    Vector3& Vector3::operator/=(const float& scalar)
    {
        return divide(scalar);
    }
    
    std::ostream& operator<<(std::ostream& stream, const Vector3& vector3)
    {
        stream << "Vector3(" << vector3.x << ", " << vector3.y << ", " << vector3.z << ")";
        return stream;
    }
} }