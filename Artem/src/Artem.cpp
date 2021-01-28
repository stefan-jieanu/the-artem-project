#include <ArtemEngine.h>

using namespace ArtemEngine;

class ExampleLayer : public ArtemEngine::Layer
{
public:
	ExampleLayer(const std::string& name)
		: Layer(name), camera_(-1.6f, 1.6f, -0.9f, 0.9f)
	{
		cameraPosition_ = camera_.GetPosition();
		cameraRotation_ = camera_.GetRotation();

		vao_.reset(VertexArray::Create());

		float vertices[3 * 7] = {
			-0.5f, -0.5f, 0.0f, 0.8f, 0.2f, 0.8f, 1.0f,
			0.5f, -0.5f, 0.0f, 0.4f, 0.8f, 0.8f, 1.0f,
			0.0f, 0.5f, 0.0f, 0.2f, 0.8f, 0.3f, 1.0f
		};

		vb_.reset(VertexBuffer::Create(vertices, sizeof(vertices)));

		BufferLayout layout{
			{ ShaderDataType::Float3, "position"},
			{ ShaderDataType::Float4, "color"}
		};
		vb_->SetLayout(layout);

		vao_->AddVertexBuffer(vb_);

		uint32_t indices[3] = { 0, 1, 2 };
		ib_.reset(IndexBuffer::Create(indices, sizeof(indices) / sizeof(uint32_t)));

		vao_->SetIndexBuffer(ib_);

		vao_->Bind();

		shader_.reset(new Shader("E:/Work/Artem/ArtemEngine/res/Shaders/basic.shader"));
		shader_->Bind();

	}

	void OnUpdate(DeltaTime dt) override
	{
		LOG_TRACE("Delta time: {0}s, ({1}ms)", dt.GetSeconds(), dt.GetMilliseconds());

		if (Input::GetKey(KeyCode::W))
			cameraPosition_.y += cameraSpeed_ * dt;
		else if (Input::GetKey(KeyCode::S))
			cameraPosition_.y -= cameraSpeed_ * dt;
		if (Input::GetKey(KeyCode::A))
			cameraPosition_.x -= cameraSpeed_ * dt;
		else if (Input::GetKey(KeyCode::D))
			cameraPosition_.x += cameraSpeed_ * dt;

		if (Input::GetKey(KeyCode::Q))
			cameraRotation_ -= cameraSpeed_ * dt * 180;
		else if (Input::GetKey(KeyCode::E))
			cameraRotation_ += cameraSpeed_ * dt * 180;

		RenderCommand::SetClearColor(Color::DarkGrey);
		RenderCommand::Clear();

		camera_.SetPosition(cameraPosition_);
		camera_.SetRotation(cameraRotation_);

		Renderer::Begin(camera_);
		Renderer::Submit(shader_, vao_);
		Renderer::End();
	}

private:
	OrthographicCamera camera_;
	std::shared_ptr<Shader> shader_;
	std::shared_ptr<VertexBuffer> vb_;
	std::shared_ptr<IndexBuffer> ib_;
	std::shared_ptr<VertexArray> vao_;
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