#include "aepch.h"

#include "Application.h"
#include "glad/glad.h"
#include "Input.h"

namespace ArtemEngine
{
	#define BIND_EVENT_FN(x) std::bind(&x, this, std::placeholders::_1)

	Application* Application::sInstance_ = nullptr;

	Application::Application()
	{
		window_ = std::unique_ptr<Window>(Window::Create());
		window_->SetEventCallback(BIND_EVENT_FN(Application::OnEvent));

		sInstance_ = this;

		LOG_CORE_TRACE("engine");
		LOG_CORE_DEBUG("engine");
		LOG_CORE_INFO("engine");
		LOG_CORE_WARN("engine");
		LOG_CORE_ERROR("engine");
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

			bool pressed = Input::IsKeyPressed(87);
			//LOG_CORE_DEBUG("{0}", pressed);

			window_->OnUpdate();
		}
	}

	void Application::PushLayer(std::shared_ptr<Layer> layer)
	{
		layerStack_.PushLayer(layer);
		layer->OnAttach();
	}

	void Application::PopLayer(std::shared_ptr<Layer> layer)
	{
		layerStack_.PopLayer(layer);
		layer->OnDetach();
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