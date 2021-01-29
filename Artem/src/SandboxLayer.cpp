#include "SandboxLayer.h"

SandboxLayer::SandboxLayer(const std::string& name)
	: Layer(name), cameraController_(1280.0f / 720.0f)
{
	vao_ = Engine::VertexArray::Create();

	float vertices[3 * 7] = {
		-0.5f, -0.5f, 0.0f, 0.8f, 0.2f, 0.8f, 1.0f,
		0.5f, -0.5f, 0.0f, 0.4f, 0.8f, 0.8f, 1.0f,
		0.0f, 0.5f, 0.0f, 0.2f, 0.8f, 0.3f, 1.0f
	};

	vb_ = Engine::VertexBuffer::Create(vertices, sizeof(vertices));

	Engine::BufferLayout layout{
		{ Engine::ShaderDataType::Float3, "position"},
		{ Engine::ShaderDataType::Float4, "color"}
	};
	vb_->SetLayout(layout);

	vao_->AddVertexBuffer(vb_);

	uint32_t indices[3] = { 0, 1, 2 };
	ib_ = Engine::IndexBuffer::Create(indices, sizeof(indices) / sizeof(uint32_t));

	vao_->SetIndexBuffer(ib_);

	vao_->Bind();

	shaderLibrary_.Load("E:/Work/Artem/ArtemEngine/res/Shaders/basic.glsl");
	shaderLibrary_.Get("basic")->Bind();
}

SandboxLayer::~SandboxLayer()
{

}

void SandboxLayer::OnUpdate(Engine::DeltaTime dt)
{
	Engine::RenderCommand::SetClearColor(Engine::Color::DarkGrey);
	Engine::RenderCommand::Clear();

	cameraController_.OnUpdate(dt);

	Engine::Renderer::Begin(cameraController_.GetCamera());
	Engine::Renderer::Submit(shaderLibrary_.Get("basic"), vao_);
	Engine::Renderer::End();
}

void SandboxLayer::OnEvent(Engine::Event& e)
{
	cameraController_.OnEvent(e);

	/*if (e.GetEventType() == EventType::WindowResize)
	{
		auto& re = (WindowResizeEvent&)e;
	}*/
}