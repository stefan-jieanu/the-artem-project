#include <ArtemEngine.h>

class ExampleLayer : public ArtemEngine::Layer
{
public:
	ExampleLayer(const std::string& name)
		: Layer(name)
	{}

	void OnUpdate() override
	{
		//AR_INFO("{0}::Updates", debugName_);
	}

	void OnEvent(ArtemEngine::Event& event) override
	{
		AR_TRACE("{0}::{1}", debugName_, event);
	}
};

class Artem : public ArtemEngine::Application
{
public:
	Artem()
	{
		std::shared_ptr<ExampleLayer> layer1 = std::make_shared<ExampleLayer>("xxx");		
		std::shared_ptr<ExampleLayer> layer2 = std::make_shared<ExampleLayer>("yyy");		

		PushLayer(layer1);
		PushLayer(layer2);
	}

	~Artem()
	{

	}
};

ArtemEngine::Application* ArtemEngine::CreateApplication()
{
	return new Artem();
}