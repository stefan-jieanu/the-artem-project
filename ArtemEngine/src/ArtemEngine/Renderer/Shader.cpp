#include "aepch.h"
#include "Shader.h"

#include "glad/glad.h"

namespace ArtemEngine {

    Shader::Shader(const std::string filepath)
        : shaderID_(0)
    {
        // Get the source code for each shader program
        ShaderProgramSource source = ParseShader(filepath);

        // Create a shader using the source code previously loaded
        shaderID_ = CreateShader(source.vertexSource, source.fragmentSource);
    }

    Shader::~Shader()
    {
        glDeleteProgram(shaderID_);
    }

    ShaderProgramSource Shader::ParseShader(const std::string& filepath)
    {
        std::ifstream stream(filepath);
        if (!stream.good())
            LOG_ERROR("Shader source file not found: {}", filepath);

        std::string line;

        enum class ShaderType
        {
            NONE = -1, VERTEX = 0, FRAGMENT = 1
        };

        std::stringstream ss[2];
        ShaderType type = ShaderType::NONE;

        while (std::getline(stream, line))
        {
            if (line.find("#shader") != std::string::npos)
            {
                if (line.find("vertex") != std::string::npos)
                    type = ShaderType::VERTEX;
                else if (line.find("fragment") != std::string::npos)
                    type = ShaderType::FRAGMENT;
            }
            else
            {
                ss[(int)type] << line << "\n";
            }
        }

        return { ss[0].str(), ss[1].str() };
    }

    unsigned int Shader::CompileShader(unsigned int type, const std::string& source)
    {
        unsigned int id = glCreateShader(type);
        const char* src = source.c_str();
        glShaderSource(id, 1, &src, nullptr);
        glCompileShader(id);

        // Error handling
        int result;
        glGetShaderiv(id, GL_COMPILE_STATUS, &result);
        if (result == GL_FALSE)
        {
            int lenght;
            glGetShaderiv(id, GL_INFO_LOG_LENGTH, &lenght);
            char* message = (char*)alloca(lenght * sizeof(char));
            glGetShaderInfoLog(id, lenght, &lenght, message);
            LOG_ERROR("Failed to compile {} shader", (type == GL_VERTEX_SHADER ? "vertex" : "fragment"));
            LOG_ERROR("{}", message);
            glDeleteShader(id);
            return 0;
        }

        return id;
    }

    unsigned int Shader::CreateShader(const std::string& vertexShader, const std::string& fragmentShader)
    {
        // The shader program containing fragment and vertex
        unsigned int program = glCreateProgram();

        // The vertex shader by itself
        unsigned int vs = CompileShader(GL_VERTEX_SHADER, vertexShader);

        // The fragment shader by itself
        unsigned int fs = CompileShader(GL_FRAGMENT_SHADER, fragmentShader);

        // Linking vertex and fragment into a single shader program
        glAttachShader(program, vs);
        glAttachShader(program, fs);
        glLinkProgram(program);
        glValidateProgram(program);

        // Deleting the now unused vertex and fragment shader because they are now stored 
        // in a unified(linked) shader program
        glDeleteShader(vs);
        glDeleteShader(fs);
        
        return program;
    }

    int Shader::GetUniformLocation(const std::string& name)
    {
        int location = glGetUniformLocation(shaderID_, name.c_str());
        if (location == -1)
            LOG_WARN("Uniform \"{}\" doesn't exist", name); 
        return location;
    }

    void Shader::SetUniform2f(const std::string& name, Math::Vector2 value)
    {
        glUniform2f(GetUniformLocation(name), value.x, value.y);
    }

    void Shader::SetUniform1fv(const std::string& name, int count, const float* value)
    {
        glUniform1fv(GetUniformLocation(name), count, value);
    }

    void Shader::SetUniform1iv(const std::string& name, int count, const int* value)
    {
        glUniform1iv(GetUniformLocation(name), count, value);
    }

    void Shader::SetUniform1i(const std::string& name, const int value)
    {
        glUniform1i(GetUniformLocation(name), value);
    }

    void Shader::SetUniform4f(const std::string& name, Math::Vector4 value)
    {
        glUniform4f(GetUniformLocation(name), value.x, value.y, value.z, value.w);
    }

    void Shader::SetUniformMat4f(const std::string& name, Math::Matrix4 value)
    {
        //glUniformMatrix4fv(GetUniformLocation(name), 1, GL_FALSE, value.elements);
    }

    void Shader::Bind() const
    {
        glUseProgram(shaderID_);
    }

    void Shader::Unbind() const
    {
        glUseProgram(0);
    }

}