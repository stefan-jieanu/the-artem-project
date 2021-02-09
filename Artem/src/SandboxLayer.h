#pragma once

#include <ArtemEngine.h>

namespace Engine = ArtemEngine;

class SandboxLayer : public ArtemEngine::Layer
{
public:
	SandboxLayer(const std::string& name);
	~SandboxLayer();

	void OnUpdate(Engine::DeltaTime dt) override;
	void OnEvent(Engine::Event& e) override;
private:
	Engine::OrthographicCameraController cameraController_;
	Engine::ShaderLibrary shaderLibrary_;
	Engine::Shared<ArtemEngine::VertexBuffer> vb_;
	Engine::Shared<ArtemEngine::IndexBuffer> ib_;
	Engine::Shared<ArtemEngine::VertexArray> vao_;
	Engine::Math::Vector3 cameraPosition_;
	float cameraRotation_;
	float cameraSpeed_ = 1.f;

	Engine::Shared<Engine::Texture> texture_;

	float rotation1 = 14.0f;
	float rotation2 = 78.0f;
	float rotation3 = 41.0f;
};

