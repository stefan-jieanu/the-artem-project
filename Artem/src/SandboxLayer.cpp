 #include "SandboxLayer.h"

SandboxLayer::SandboxLayer(const std::string& name)
	: Layer(name), cameraController_(1280.0f / 720.0f)
{
	texture_ = Engine::Texture::Create("E:/Work/Artem/ArtemEngine/res/nudes/ricardo.png");

	Engine::FramebufferProperties fbprops;
	fbprops.width = 1280.0f;
	fbprops.height = 720.0f;

	framebuffer_ = Engine::Framebuffer::Create(fbprops);
}

SandboxLayer::~SandboxLayer()
{
}

void SandboxLayer::OnUpdate(Engine::DeltaTime dt)
{	
	cameraController_.OnUpdate(dt);

	//framebuffer_->Bind();

	Engine::RenderCommand::SetClearColor(Engine::Color::DarkGrey);
	Engine::RenderCommand::Clear();

	/*Engine::Renderer2D::BeginScene(cameraController_.GetCamera());
	for (float y = -5.0f; y < 5.0f; y += 0.5f)
	{
		for (float x = -5.0f; x < 5.0f; x += 0.5f)
		{
			Engine::Color color = { (x + 5.0f) / 10.f, (y + 5.0f) / 10.f , 0.3f, 1.0f};
			Engine::Renderer2D::DrawQuad({ x, y }, { 0.45f, 0.45f }, color, rotation1);
		}
	}
	Engine::Renderer2D::EndScene();*/

	Engine::Renderer2D::BeginScene(cameraController_.GetCamera());

	//Engine::Renderer2D::DrawQuad({ 0.0f, 0.0f, 1.0f }, { 0.6f, 0.6f }, { 0.2f, 0.8f, 0.2f, 1.0f }, rotation2);
	//Engine::Renderer2D::DrawQuad({ 1.0f, 0.0f, 1.0f }, { 0.6f, 0.6f }, { 0.2f, 0.2f, 0.8f, 1.0f }, rotation3);

	Engine::Renderer2D::DrawQuad({ -1.0f, 0.0f, 1.0f }, { 0.6f, 0.6f }, { 0.8f, 0.8f, 0.2f, 1.0f });
	//Engine::Renderer2D::DrawQuad({ -1.0f, 1.0f, 1.0f }, { 0.6f, 0.6f }, { 0.8f, 0.2f, 0.2f, 0.5f });
	//Engine::Renderer2D::DrawQuad({ -1.4f, 0.0f, 0.2f }, { 0.6f, 0.6f }, texture_, rotation1);
	//Engine::Renderer2D::DrawQuad({ 1.4f, 0.0f, 0.2f }, { 0.6f, 0.6f }, texture_, rotation1);
	Engine::Renderer2D::EndScene();
	
	//framebuffer_->Unbind();

	rotation1 -= 45.0f * dt;
	rotation2 += 8.0f * dt;
	rotation3 -= 11.0f * dt;
}

void SandboxLayer::OnEvent(Engine::Event& e)
{
	cameraController_.OnEvent(e);

}