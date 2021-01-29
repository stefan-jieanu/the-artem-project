#include "aepch.h"
#include "Shader.h"

#include "Platform/OpenGL/OpenGLShader.h"
#include "Renderer.h"

namespace ArtemEngine {

    Shader* Shader::Create(const std::string& filepath)
    {
        switch (Renderer::GetAPI())
        {
            case RendererAPI::API::None: LOG_CORE_ASSERT(false, "RendererAPI::None is not supported!"); return nullptr;
            case RendererAPI::API::OpenGL: return new OpenGLShader(filepath);
        }

        LOG_CORE_ASSERT(false, "Unknown RendererAPI!");
        return nullptr;
    }

}