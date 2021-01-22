#include <ArtemEngine.h>

class Artem : public ArtemEngine::Application
{
public:
	Artem()
	{
		
	}

	~Artem()
	{

	}
};

ArtemEngine::Application* ArtemEngine::CreateApplication()
{
	return new Artem();
}