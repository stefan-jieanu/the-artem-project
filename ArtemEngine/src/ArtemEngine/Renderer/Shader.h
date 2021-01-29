#pragma once

#include "ArtemEngine/Math/math.h"

namespace ArtemEngine {

    /*************************************************/
    /*  			      Shader                     */
    /*************************************************/
    class Shader
    {
    public:
        virtual ~Shader() = default;

        virtual void Bind() const = 0;
        virtual void Unbind() const = 0;

        virtual void SetUniformFloat(const std::string& name, float value) const = 0;
        virtual void SetUniformFloat2(const std::string& name, const Math::Vector2& value) const = 0;
        virtual void SetUniformFloat2(const std::string& name, float v1, float v2) const = 0;
        virtual void SetUniformFloat3(const std::string& name, const Math::Vector3& value) const = 0;
        virtual void SetUniformFloat3(const std::string& name, float v1, float v2, float v3) const = 0;
        virtual void SetUniformFloat4(const std::string& name, const Math::Vector4& value) const = 0;
        virtual void SetUniformFloat4(const std::string& name, float v1, float v2, float v3, float v4) const = 0;

        virtual void SetUniformMat3() const = 0;
        virtual void SetUniformMat4(const std::string& name, const Math::Matrix4& value) const = 0;

        virtual void SetUnifomInt(const std::string& name, int value) const = 0;
        virtual void SetUnifomInt2(const std::string& name, const Math::Vector2& value) const = 0;
        virtual void SetUnifomInt2(const std::string& name, int v1, int v2) const = 0;
        virtual void SetUnifomInt3(const std::string& name, const Math::Vector3& value) const = 0;
        virtual void SetUnifomInt3(const std::string& name, int v1, int v2, int v3) const = 0;
        virtual void SetUnifomInt4(const std::string& name, const Math::Vector4& value) const = 0;
        virtual void SetUnifomInt4(const std::string& name, int v1, int v2, int v3, int v4) const = 0;

        virtual void SetUniformBoll(const std::string& name, bool value) const = 0;

        virtual const std::string& GetName() const = 0;

        static Shared<Shader> Create(const std::string& filepath);
    };

    /*************************************************/
    /*  			  Shader Library                 */
    /*************************************************/
    class ShaderLibrary
    {
    public:
        // Take a const reference because the smart pointer reference counter gets incremented 
        // when added into the unordered_map; no reason to increment to when passing as a parameter
        void Add(const Shared<Shader>& shader);

        Shared<Shader> Load(const std::string& filepath);

        Shared<Shader> Get(const std::string& name);
    private:
        std::unordered_map<std::string, Shared<Shader>> shaders_;
    };

}


