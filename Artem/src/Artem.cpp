#include <Engine.h>

class Artem : public Engine::Application
{
public:
	Artem()
	{

	}

	~Artem()
	{

	}
};

Engine::Application* Engine::CreateApplication()
{
	return new Artem();
}