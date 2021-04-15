#include "aepch.h"
#include "Shader.h"

#include "Platform/OpenGL/OpenGLShader.h"
#include "Renderer.h"

namespace ArtemEngine {

    /*************************************************/
    /*  			      Shader                     */
    /*************************************************/
    Shared<Shader> Shader::Create(const std::string& vertexFilepath, const std::string& fragmentFilepath)
    {
        switch (Renderer::GetAPI())
        {
            case RendererAPI::API::None: LOG_CORE_ASSERT(false, "RendererAPI::None is not supported!"); return nullptr;
            case RendererAPI::API::OpenGL: return std::make_shared<OpenGLShader>(vertexFilepath, fragmentFilepath);
        }

        LOG_CORE_ASSERT(false, "Unknown RendererAPI!");
        return nullptr;
    }

    /*************************************************/
    /*  			  Shader Library                 */
    /*************************************************/
    void ShaderLibrary::Add(const Shared<Shader>& shader)
    {
        const std::string& name = shader->GetName();
        LOG_CORE_ASSERT(shaders_.find(name) == shaders_.end(), "Shader already exists!");
        shaders_[name] = shader;
    }

    Shared<Shader> ShaderLibrary::Load(const std::string& vertexFilepath, const std::string& fragmentFilepath)
    {
        Shared<Shader> shader = Shader::Create(vertexFilepath, fragmentFilepath);
        Add(shader);

        return shader;
    }

    Shared<Shader> ShaderLibrary::Get(const std::string& name)
    {
        LOG_CORE_ASSERT(shaders_.find(name) != shaders_.end(), "Shader not found!");
        return shaders_[name];
    }

}