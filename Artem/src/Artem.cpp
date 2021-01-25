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
		//LOG_INFO("{0}::Updates", debugName_);
	}

	bool OnKeyPressed(KeyPressedEvent& e) override
	{
		LOG_DEBUG("Layer: {0}", e);
		return true;
	}

};

class Artem : public ArtemEngine::Application
{
public:
	Artem()
	{
		std::shared_ptr<ExampleLayer> layer1 = std::make_shared<ExampleLayer>("xxx");		
		//std::shared_ptr<ExampleLayer> layer2 = std::make_shared<ExampleLayer>("yyy");		

		PushLayer(layer1);
		//PushLayer(layer2);

		LOG_TRACE("artem");
		LOG_DEBUG("artem");
		LOG_INFO("artem");
		LOG_WARN("artem");
		LOG_ERROR("artem");
	}

	~Artem()
	{

	}

	bool OnWindowClose(WindowCloseEvent& e) override
	{
		Terminate();
		return true;
	}

	bool OnKeyPressed(KeyPressedEvent& e) override
	{
		LOG_DEBUG("main: {0}", e);
		return false;
	}
};

ArtemEngine::Application* ArtemEngine::CreateApplication()
{
	return new Artem();
}