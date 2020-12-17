#pragma once

#include <iostream>

namespace artem { namespace maths {
    struct Vector3
    {
        float x, y, z;

        Vector3();
        Vector3(const float x,const float y, const float z);

        // Basic methods
        Vector3& add(const Vector3& other);
        Vector3& subtract(const Vector3& other);
        Vector3& multiply(const float& scalar);
        Vector3& divide(const float& scalar);

        // Operator overloading
        friend Vector3& operator+(Vector3 left, const Vector3& right);
        friend Vector3& operator-(Vector3 left, const Vector3& right);
        friend Vector3& operator*(Vector3 vec, const float& scalar);
        friend Vector3& operator/(Vector3 vec, const float& scalar);

        bool operator==(const Vector3& other);
        bool operator!=(const Vector3& other);

        Vector3& operator+=(const Vector3& other);
        Vector3& operator-=(const Vector3& other);
        Vector3& operator*=(const float& scalar);
        Vector3& operator/=(const float& scalar);

        friend std::ostream& operator<<(std::ostream& stream, const Vector3& vector2);
    };
} }