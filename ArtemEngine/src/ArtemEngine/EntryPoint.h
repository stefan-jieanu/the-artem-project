#pragma once

#ifdef AR_PLATFORM_WINDOWS

extern ArtemEngine::Application* ArtemEngine::CreateApplication();

int main(int argc, char** argv)
{
	printf("Welcome to the Artem project!");
	auto app = ArtemEngine::CreateApplication();
	app->Run();
	delete app;
}

#endif