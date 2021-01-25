#include <ArtemEngine.h>

using namespace ArtemEngine;

class ExampleLayer : public ArtemEngine::Layer
{
public:
	ExampleLayer(const std::string& name)
		: Layer(name)
	{
	}

	void OnUpdate() override
	{
		
	}

};

class Artem : public ArtemEngine::Application
{
public:
	Artem()
	{
		std::shared_ptr<ExampleLayer> layer1 = std::make_shared<ExampleLayer>("xxx");		

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