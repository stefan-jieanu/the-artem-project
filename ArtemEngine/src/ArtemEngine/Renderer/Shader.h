#pragma once

#include <fstream>
#include "ArtemEngine/Math/math.h"

namespace ArtemEngine {

    // Holds the source code of the vertex and fragment shaders
    struct ShaderProgramSource
    {
        std::string vertexSource;
        std::string fragmentSource;
    };

    class Shader
    {
    private:
        unsigned int shaderID_;

        // Parses a source file to split it into vertex and fragment shader code strings
        ShaderProgramSource ParseShader(const std::string& filepath);
        // Compile an individual shader program (i.e. fragment, vertex)
        unsigned int CompileShader(unsigned int type, const std::string& source);
        // Link two or more compiled shader programs into a single shader 
        // (i.e. fragment and vertex get combined into a single shader)
        unsigned int CreateShader(const std::string& vertexShader, const std::string& fragmentShader);

        int GetUniformLocation(const std::string& name);
    public:
        Shader(const std::string filepath);
        ~Shader();

        void SetUniform1i(const std::string& name, const int value);
        void SetUniform2f(const std::string& name, const Math::Vector2& value);
        void SetUniform4f(const std::string& name, const Math::Vector4& value);
        void SetUniform1fv(const std::string& name, int count, const float* value);
        void SetUniform1iv(const std::string& name, int count, const int* value);
        void SetUniformMat4f(const std::string& name, const Math::Matrix4& value);

        void Bind() const;
        void Unbind() const;
    };

}


