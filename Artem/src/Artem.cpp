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

	bool OnKeyPressed(KeyPressedEvent& e) override 
	{
		LOG_TRACE("{}", (char)e.GetKeyCode());
		return false;
	}

};

class Artem : public ArtemEngine::Application
{
public:
	Artem()
	{
		std::shared_ptr<ExampleLayer> layer1 = std::make_shared<ExampleLayer>("xxx");		

		PushLayer(layer1);
		
		Vector2 vec2(4, 5);
		Vector3 vec3(1, 2, 3);
		Vector4 vec4(0.0f, 0.0f, 0.0f, 0.0f);
		LOG_TRACE("{0}, {1}, {2}", vec2, vec3, vec4);
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