#include "aepch.h"

#include "Application.h"

#include "ArtemEngine/Events/ApplicationEvent.h"
#include "ArtemEngine/Log.h"

namespace ArtemEngine
{

	Application::Application()
	{
		window_ = std::unique_ptr<Window>(Window::Create());
	}

	Application::~Application()
	{
	}

	void Application::Run()
	{
		while (running_)
		{
			window_->OnUpdate();
		}
	}

}