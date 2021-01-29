#include <ArtemEngine.h>

using namespace ArtemEngine;

class ExampleLayer : public ArtemEngine::Layer
{
public:
	ExampleLayer(const std::string& name)
		: Layer(name), cameraController_(1280.0f / 720.0f)
	{
		vao_ = VertexArray::Create();

		float vertices[3 * 7] = {
			-0.5f, -0.5f, 0.0f, 0.8f, 0.2f, 0.8f, 1.0f,
			0.5f, -0.5f, 0.0f, 0.4f, 0.8f, 0.8f, 1.0f,
			0.0f, 0.5f, 0.0f, 0.2f, 0.8f, 0.3f, 1.0f
		};

		vb_ = VertexBuffer::Create(vertices, sizeof(vertices));

		BufferLayout layout{
			{ ShaderDataType::Float3, "position"},
			{ ShaderDataType::Float4, "color"}
		};
		vb_->SetLayout(layout);

		vao_->AddVertexBuffer(vb_);

		uint32_t indices[3] = { 0, 1, 2 };
		ib_ = IndexBuffer::Create(indices, sizeof(indices) / sizeof(uint32_t));

		vao_->SetIndexBuffer(ib_);

		vao_->Bind();

		shaderLibrary_.Load("E:/Work/Artem/ArtemEngine/res/Shaders/basic.glsl");
		shaderLibrary_.Get("basic")->Bind();

	}

	void OnUpdate(DeltaTime dt) override
	{
		RenderCommand::SetClearColor(Color::DarkGrey);
		RenderCommand::Clear();

		cameraController_.OnUpdate(dt);

		Renderer::Begin(cameraController_.GetCamera());
		Renderer::Submit(shaderLibrary_.Get("basic"), vao_);
		Renderer::End();
	}

	void OnEvent(Event& e) override
	{
		cameraController_.OnEvent(e);

		if (e.GetEventType() == EventType::WindowResize)
		{
			auto& re = (WindowResizeEvent&)e;
		}
	}

private:
	OrthographicCameraController cameraController_;
	ShaderLibrary shaderLibrary_;
	Shared<VertexBuffer> vb_;
	Shared<IndexBuffer> ib_;
	Shared<VertexArray> vao_;
	Math::Vector3 cameraPosition_;
	float cameraRotation_;
	float cameraSpeed_ = 1.f;;
};

class Artem : public ArtemEngine::Application
{
public:
	Artem()
	{
		std::shared_ptr<ExampleLayer> layer1 = std::make_shared<ExampleLayer>("Layer1");		
		PushLayer(layer1);
	}

	~Artem()
	{

	}

	bool OnWindowClose(WindowCloseEvent& e) override
	{
		Terminate();
		return true;
	}
};

ArtemEngine::Application* ArtemEngine::CreateApplication()
{
	return new Artem();
}