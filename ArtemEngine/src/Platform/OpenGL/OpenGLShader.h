#pragma once

#include <glad/glad.h>
#include "ArtemEngine/Renderer/Shader.h"

namespace ArtemEngine {

	// Holds the source code of the vertex and fragment shaders
	struct ShaderProgramSource
	{
		std::string vertexSource;
		std::string fragmentSource;
	};

	class OpenGLShader : public Shader
	{
	public:
		OpenGLShader(const std::string& filepath);
		~OpenGLShader() override;

		void Bind() const override;
		void Unbind() const override;

		void SetUniformFloat(const std::string& name, float value) const override;
		void SetUniformFloat2(const std::string& name, const Math::Vector2& value) const override;
		void SetUniformFloat2(const std::string& name, float v1, float v2) const override;
		void SetUniformFloat3(const std::string& name, const Math::Vector3& value) const override;
		void SetUniformFloat3(const std::string& name, float v1, float v2, float v3) const override;
		void SetUniformFloat4(const std::string& name, const Math::Vector4& value) const override;
		void SetUniformFloat4(const std::string& name, float v1, float v2, float v3, float v4) const override;

		void SetUniformMat3() const override;
		void SetUniformMat4(const std::string& name, const Math::Matrix4& value) const override;

		void SetUnifomInt(const std::string& name, int value) const override;
		void SetUnifomInt2(const std::string& name, const Math::Vector2& value) const override;
		void SetUnifomInt2(const std::string& name, int v1, int v2) const override;
		void SetUnifomInt3(const std::string& name, const Math::Vector3& value) const override;
		void SetUnifomInt3(const std::string& name, int v1, int v2, int v3) const override;
		void SetUnifomInt4(const std::string& name, const Math::Vector4& value) const override;
		void SetUnifomInt4(const std::string& name, int v1, int v2, int v3, int v4) const override;

		void SetUniformBoll(const std::string& name, bool value) const override;
	private:
		uint32_t shaderID_;

		// Parses a source file to split it into vertex and fragment shader code strings
		ShaderProgramSource ParseShader(const std::string& filepath);

		// Compile an individual shader program (i.e. fragment, vertex)
		uint32_t CompileShader(unsigned int type, const std::string& source);

		// Link two or more compiled shader programs into a single shader 
		// (i.e. fragment and vertex get combined into a single shader)
		uint32_t CreateShader(const std::string& vertexShader, const std::string& fragmentShader);

		int32_t GetUniformLocation(const std::string& name) const;
	};

}

