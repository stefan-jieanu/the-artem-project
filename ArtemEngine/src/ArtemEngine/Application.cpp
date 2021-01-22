#include "aepch.h"

#include "Application.h"

namespace ArtemEngine
{
	#define BIND_EVENT_FN(x) std::bind(&x, this, std::placeholders::_1)

	Application::Application()
	{
		window_ = std::unique_ptr<Window>(Window::Create());
		window_->SetEventCallback(BIND_EVENT_FN(Application::OnEvent));
	}

	Application::~Application()
	{
	}

	void Application::Run()
	{
		while (running_)
		{
			for (std::shared_ptr<Layer> layer : layerStack_)
				layer->OnUpdate();

			window_->OnUpdate();
		}
	}

	void Application::PushLayer(std::shared_ptr<Layer> layer)
	{
		layerStack_.PushLayer(layer);
	}

	void Application::PopLayer(std::shared_ptr<Layer> layer)
	{
		layerStack_.PopLayer(layer);
	}

	void Application::OnEvent(Event& e)
	{
		EventDispatcher dispatcher(e);
		dispatcher.Dispatch<WindowCloseEvent>(BIND_EVENT_FN(Application::OnWindowClose));

		for (std::shared_ptr<Layer> layer : layerStack_)
		{
			layer->OnEvent(e);
			if (e.IsHandled())
				break;
		}
	}

	bool Application::OnWindowClose(WindowCloseEvent& e)
	{
		running_ = false;
		return true;
	}
}