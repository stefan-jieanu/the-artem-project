#pragma once

#include "ArtemEngine/Math/math.h"

namespace ArtemEngine {

    class Shader
    {
    public:
        virtual ~Shader() = default;

        virtual void Bind() const = 0;
        virtual void Unbind() const = 0;

        virtual void SetUniformFloat(const std::string& name, float value) const = 0;
        virtual void SetUniformFloat2(const std::string& name, const Math::Vector2& value) const = 0;
        virtual void SetUniformFloat3(const std::string& name, const Math::Vector3& value) const = 0;
        virtual void SetUniformFloat4(const std::string& name, const Math::Vector4& value) const = 0;
        virtual void SetUniformMat3() const = 0;
        virtual void SetUniformMat4(const std::string& name, const Math::Matrix4& value) const = 0;
        virtual void SetUnifomInt(const std::string& name, int value) const = 0;
        virtual void SetUnifomInt2(const std::string& name, const Math::Vector2& value) const = 0;
        virtual void SetUnifomInt3(const std::string& name, const Math::Vector3& value) const = 0;
        virtual void SetUnifomInt4(const std::string& name, const Math::Vector4& value) const = 0;
        virtual void SetUniformBoll(const std::string& name, bool value) const = 0;

        static Shader* Create(const std::string& filepath);
    };

}


