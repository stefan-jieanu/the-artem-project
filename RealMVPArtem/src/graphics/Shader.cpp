#include "Shader.h"

namespace artem { namespace graphics {

    Shader::Shader(const std::string filepath)
        : shaderID_(0)
    {
        ShaderProgramSource source = ParseShader(filepath);
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
            std::cout << "Shader source file not found: " << filepath << std::endl; 
        
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
                ss[(int)type] << line <<  "\n";
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
            char *message = (char*)alloca(lenght * sizeof(char));
            glGetShaderInfoLog(id, lenght, &lenght, message);
            std::cout << "Failed to compile" << (type == GL_VERTEX_SHADER ? "vertex" : "fragment") << " shader: ";
            std::cout << message << std::endl;
            glDeleteShader(id);
            return 0;
        }

        return id;
    }

    unsigned int Shader::CreateShader(const std::string& vertexShader, const std::string& fragmentShader)
    {
        unsigned int program = glCreateProgram();
        unsigned int vs = CompileShader(GL_VERTEX_SHADER, vertexShader);
        unsigned int fs = CompileShader(GL_FRAGMENT_SHADER, fragmentShader);

        glAttachShader(program, vs);
        glAttachShader(program, fs);
        glLinkProgram(program);
        glValidateProgram(program);

        glDeleteShader(vs);
        glDeleteShader(fs);

        return program;
    }

    int Shader::GetUniformLocation(const std::string& name)
    {
        int location = glGetUniformLocation(shaderID_, name.c_str());
        if (location == -1)
            std::cout << "Warning: uniform '" << name << "' doesn't exist!" << std::endl;
        return location;
    }

    void Shader::SetUniform2f(const std::string& name, maths::Vector2 value)
    {
        glUniform2f(GetUniformLocation(name), value.x, value.y);
    }

    void Shader::SetUniform4f(const std::string& name, maths::Vector4 value)
    {
        glUniform4f(GetUniformLocation(name), value.x, value.y, value.z, value.w);
    }

    void Shader::SetUniformMat4f(const std::string& name, maths::Matrix4 value)
    {
        glUniformMatrix4fv(GetUniformLocation(name), 1, GL_FALSE, value.elements);
    }

    void Shader::Bind() const
    {
        glUseProgram(shaderID_);
    }

    void Shader::Unbind() const
    {
        glUseProgram(0);
    }

} }