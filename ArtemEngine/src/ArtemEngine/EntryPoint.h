#pragma once

#ifdef AR_PLATFORM_WINDOWS

extern ArtemEngine::Application* ArtemEngine::CreateApplication();

int main(int argc, char** argv)
{
	ArtemEngine::Log::Init();

	auto app = ArtemEngine::CreateApplication();
	app->Run();
	delete app;

	return 0;
}

#endif