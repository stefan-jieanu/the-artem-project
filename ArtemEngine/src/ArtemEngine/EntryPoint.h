#pragma once

#ifdef AR_PLATFORM_WINDOWS

extern ArtemEngine::Application* ArtemEngine::CreateApplication();

int main(int argc, char** argv)
{
	ArtemEngine::Log::Init();
	AR_CORE_INFO("this is info");
	int a = 5;
	AR_DEBUG("fatal var:{0}", a);

	auto app = ArtemEngine::CreateApplication();
	app->Run();
	delete app;

	return 0;
}

#endif