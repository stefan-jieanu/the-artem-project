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

		Window& GetWindow() { return *window_; }
		static Application& Get() { return *sInstance_; }
	private:
		static Application* sInstance_;

		std::unique_ptr<Window> window_;
		bool running_ = true;
		LayerStack layerStack_;

		bool OnWindowClose(WindowCloseEvent& e);
	};

	// To be defined in CLIENT
	Application* CreateApplication();
}

