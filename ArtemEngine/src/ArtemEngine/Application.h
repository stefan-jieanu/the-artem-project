#pragma once

#include "Core.h"
#include "Window.h"
#include "ArtemEngine/LayerStack.h"
#include "ArtemEngine/Events/ApplicationEvent.h"

namespace ArtemEngine {

	class ARTEM_ENGINE_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();

		void PushLayer(std::shared_ptr<Layer> layer);
		void PopLayer(std::shared_ptr<Layer> layer);

		void OnEvent(Event& e);
	private:
		bool OnWindowClose(WindowCloseEvent& e);

		std::unique_ptr<Window> window_;
		bool running_ = true;
		LayerStack layerStack_;
	};

	// To be defined in CLIENT
	Application* CreateApplication();
}

