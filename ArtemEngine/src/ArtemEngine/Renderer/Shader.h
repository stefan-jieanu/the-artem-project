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
    /*					BufferLayout  			     */
    /*************************************************/

    struct ShaderInElement
    {
        std::string name;
        ShaderDataType type;
        uint32_t offset;
        uint32_t size;
        bool normalized;

        ShaderInElement() {}
        ShaderInElement(ShaderDataType type, const std::string& name, bool normalized = false)
            : name(name), type(type), size(ShaderDataTypeSize(type)), offset(0), normalized(normalized) {}

        uint32_t GetElementCount() const
        {
            switch (type)
            {
            case ArtemEngine::ShaderDataType::Float:	return 1;
            case ArtemEngine::ShaderDataType::Float2:	return 2;
            case ArtemEngine::ShaderDataType::Float3:	return 3;
            case ArtemEngine::ShaderDataType::Float4:	return 4;
            case ArtemEngine::ShaderDataType::Mat3:		return 3 * 3;
            case ArtemEngine::ShaderDataType::Mat4:		return 4 * 4;
            case ArtemEngine::ShaderDataType::Int:		return 1;
            case ArtemEngine::ShaderDataType::Int2:		return 2;
            case ArtemEngine::ShaderDataType::Int3:		return 3;
            case ArtemEngine::ShaderDataType::Int4:		return 4;
            case ArtemEngine::ShaderDataType::Bool:		return 1;
            }
            LOG_ASSERT(false, "Invalid shader data type!");
            return 0;
        }
    };

    class ShaderLayout
    {
    public:
        ShaderLayout() {}
        ShaderLayout(const std::initializer_list<ShaderInElement>& element)
            : elements_(element)
        {
            
        }

        inline uint32_t GetStride() const { return stride_; }
        inline uint32_t GetSize() const { return size_; }
        inline const std::vector<ShaderInElement>& GetElements() const { return elements_; }
        inline void AddElement(const ShaderInElement element) { elements_.push_back(element); };

        void CalculateOffsetsAndStride()
        {
            uint32_t offset = 0;
            for (auto& element : elements_)
            {
                element.offset = offset;
                offset += element.size;
                stride_ += element.size;
                size_ += element.size;
            }
        }

        int GetElementLocation(const std::string& name) const
        {
            for (auto& element : elements_)
            {
                if (element.name.compare(name))
                {
                    return element.offset;
                }
            }
        }

    private:
        std::vector<ShaderInElement> elements_;
        uint32_t stride_ = 0;
        uint32_t size_ = 0;
    };

    /*************************************************/
    /*  			      Shader                     */
    /*************************************************/
    class Shader
    {
    public:
        static float decl_float;
        static Math::Vector2 decl_float2;
        static Math::Vector3 decl_float3;
        static Math::Vector4 decl_float4;

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

        const ShaderLayout& GetLayout() const { return layout_; }
        const uint32_t GetLayoutSize() const { return layout_.GetSize(); }

        static Shared<Shader> Create(const std::string& vertexFilepath, const std::string& fragmentFilepath);

    protected:
        ShaderLayout layout_;
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


