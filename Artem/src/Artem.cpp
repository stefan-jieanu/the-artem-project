#include <ArtemEngine.h>

class Artem : public ArtemEngine::Application
{
public:
	Artem()
	{
		AR_CORE_DEBUG("hello world from artem");
	}

	~Artem()
	{

	}
};

ArtemEngine::Application* ArtemEngine::CreateApplication()
{
	return new Artem();
}