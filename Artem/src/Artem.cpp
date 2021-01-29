#include <ArtemEngine.h>
#include <ArtemEngine/Core/EntryPoint.h>

#include "SandboxLayer.h"

using namespace ArtemEngine;

class Artem : public ArtemEngine::Application
{
public:
	Artem()
	{
		PushLayer(std::make_shared<SandboxLayer>("Sandbox"));
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