 #include "SandboxLayer.h"

SandboxLayer::SandboxLayer(const std::string& name)
	: Layer(name), cameraController_(1280.0f / 720.0f)
{
	//texture_ = Engine::Texture::Create("E:/Work/Artem/ArtemEngine/res/nudes/ricardo.png");

	Engine::FramebufferProperties fbprops;
	fbprops.width = 1280.0f;
	fbprops.height = 720.0f;

	framebuffer_ = Engine::Framebuffer::Create(fbprops);

	shaderLibrary_ = Engine::ShaderLibrary();
	shaderLibrary_.Load("E:/Work/Artem/ArtemEngine/res/Shaders/basic.vert", "E:/Work/Artem/ArtemEngine/res/Shaders/basic.frag");
}

SandboxLayer::~SandboxLayer()
{
}

void SandboxLayer::OnUpdate(Engine::DeltaTime dt)
{	
	cameraController_.OnUpdate(dt);
	Engine::Renderer::Init();

	Engine::RenderCommand::SetClearColor(Engine::Color::DarkGrey);
	Engine::RenderCommand::Clear();


	Engine::Shared<Engine::Shader> shd = shaderLibrary_.Get("basic");

	Engine::Renderer2D::SetCamera(cameraController_.GetCamera());
	Engine::Renderer2D::BeginBatch(shd);

	uint32_t* ind = new uint32_t[0, 1, 2, 2, 3, 0];

	Engine::Shared<Engine::VertexData> vd = Engine::MakeShared<Engine::VertexData>(shd->GetLayout(), 4);
	vd->SetData("_position", { 10.5f, -10.5f, 1.0f }, 0);
	vd->SetData("_position", { -10.5f, -10.5f, 1.0f }, 1);
	vd->SetData("_position", { -10.5f, 10.5f, 1.0f }, 2);
	vd->SetData("_position", { 10.5f, 10.5f, 1.0f }, 3);

	vd->SetData("_color", Engine::Color::Red, 0);
	vd->SetData("_color", Engine::Color::White, 1);
	vd->SetData("_color", Engine::Color::Blue, 2);
	vd->SetData("_color", Engine::Color::Green, 3);

	Engine::Renderer2D::Draw(vd, ind, 6);


	Engine::Renderer2D::EndBatch();

	delete[] ind;

	rotation1 -= 45.0f * dt;
	rotation2 += 8.0f * dt;
	rotation3 -= 11.0f * dt;
}

void SandboxLayer::OnEvent(Engine::Event& e)
{
	cameraController_.OnEvent(e);

}