 #include "SandboxLayer.h"

SandboxLayer::SandboxLayer(const std::string& name)
	: Layer(name), cameraController_(1280.0f / 720.0f)
{
	texture_ = Engine::Texture::Create("E:/Work/Artem/ArtemEngine/res/nudes/ricardo.png");

	Engine::FramebufferProperties fbprops;
	fbprops.width = 1280.0f;
	fbprops.height = 720.0f;

	framebuffer_ = Engine::Framebuffer::Create(fbprops);

	shaderLibrary_ = Engine::ShaderLibrary();
	shaderLibrary_.Load("E:/Work/Artem/ArtemEngine/res/Shaders/texture.vert", "E:/Work/Artem/ArtemEngine/res/Shaders/texture.frag");

	Engine::RenderCommand::SetClearColor(Engine::Color::DarkGrey);
	Engine::RenderCommand::Clear();

	Engine::Renderer::Init();

	Engine::Renderer2D::BeginBatch(shaderLibrary_.Get("texture"));

	Engine::Renderer2D::EndBatch();
}

SandboxLayer::~SandboxLayer()
{
}

void SandboxLayer::OnUpdate(Engine::DeltaTime dt)
{	
	cameraController_.OnUpdate(dt);




	rotation1 -= 45.0f * dt;
	rotation2 += 8.0f * dt;
	rotation3 -= 11.0f * dt;
}

void SandboxLayer::OnEvent(Engine::Event& e)
{
	cameraController_.OnEvent(e);

}