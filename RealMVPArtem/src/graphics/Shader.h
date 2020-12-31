#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <../logging/log_gl.h>
#include "../maths/maths.h"

namespace artem { namespace graphics {

    struct ShaderProgramSource
    {
        std::string vertexSource;
        std::string fragmentSource;
    };

    class Shader
    {
    private:
        unsigned int shaderID_;

        ShaderProgramSource ParseShader(const std::string& filepath);
        unsigned int CompileShader(unsigned int type, const std::string& source);
        unsigned int CreateShader(const std::string& vertexShader, const std::string& fragmentShader);

        int GetUniformLocation(const std::string& name);
    public:
        Shader(const std::string filepath);
        ~Shader();

        void SetUniform4f(const std::string& name, maths::Vector4 value);
        void SetUniform2f(const std::string& name, maths::Vector2 value);
        void SetUniformMat4f(const std::string& name, maths::Matrix4 value);

        void Bind() const;
        void Unbind() const;
    };

} }