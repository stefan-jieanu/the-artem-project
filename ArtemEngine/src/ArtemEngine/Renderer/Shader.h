#pragma once

#include "ArtemEngine/Math/math.h"

namespace ArtemEngine {

    enum class ShaderDataType
    {
        None = 0, Float, Float2, Float3, Float4, Mat3, Mat4,
        Int, Int2, Int3, Int4, Bool
    };

    static uint32_t ShaderDataTypeSize(ShaderDataType type)
    {
        switch (type)
        {
        case ShaderDataType::Float:		return 4;
        case ShaderDataType::Float2:	return 4 * 2;
        case ShaderDataType::Float3:	return 4 * 3;
        case ShaderDataType::Float4:	return 4 * 4;
        case ShaderDataType::Mat3:		return 4 * 3 * 3;
        case ShaderDataType::Mat4:		return 4 * 4 * 4;
        case ShaderDataType::Int:		return 4;
        case ShaderDataType::Int2:		return 4 * 2;
        case ShaderDataType::Int3:		return 4 * 3;
        case ShaderDataType::Int4:		return 4 * 4;
        case ShaderDataType::Bool:		return 1;
        }

        LOG_ASSERT(false, "Invalid shader data type!");
        return 0;
    }

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
        virtual void SetUniformIntArray(const std::string& name, int* values, uint32_t count) const = 0;

        virtual void SetUniformBoll(const std::string& name, bool value) const = 0;

        virtual const std::string& GetName() const = 0;

        static Shared<Shader> Create(const std::string& vertexFilepath, const std::string& fragmentFilepath);
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

        Shared<Shader> Load(const std::string& vertexFilepath, const std::string& fragmentFilepath);

        Shared<Shader> Get(const std::string& name);
    private:
        std::unordered_map<std::string, Shared<Shader>> shaders_;
    };

}


