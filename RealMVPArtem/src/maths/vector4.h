#pragma once

#include <iostream>

namespace artem { namespace maths {
    struct Vector4
    {
        float x, y, z, w;

        Vector4();
        Vector4(const float x,const float y, const float z, const float w);

        // Basic methods
        Vector4& add(const Vector4& other);
        Vector4& subtract(const Vector4& other);
        Vector4& multiply(const float& scalar);
        Vector4& divide(const float& scalar);

        // Operator overloading
        friend Vector4& operator+(Vector4 left, const Vector4& right);
        friend Vector4& operator-(Vector4 left, const Vector4& right);
        friend Vector4& operator*(Vector4 vec, const float& scalar);
        friend Vector4& operator/(Vector4 vec, const float& scalar);

        bool operator==(const Vector4& other);
        bool operator!=(const Vector4& other);

        Vector4& operator+=(const Vector4& other);
        Vector4& operator-=(const Vector4& other);
        Vector4& operator*=(const float& scalar);
        Vector4& operator/=(const float& scalar);

        friend std::ostream& operator<<(std::ostream& stream, const Vector4& vector4);
    };
} }