#pragma once

#include "Core.h"
#include "Window.h"
#include "ArtemEngine/LayerStack.h"
#include "ArtemEngine/Events/Event.h"
#include "ArtemEngine/Events/ApplicationEvent.h"
#include "ArtemEngine/Events/KeyEvent.h"
#include "ArtemEngine/Events/MouseEvent.h"

namespace ArtemEngine {

	class Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
		void Terminate();
		void PushLayer(std::shared_ptr<Layer> layer);
		void PopLayer(std::shared_ptr<Layer> layer);

		// Event handling callbacks
		void OnEvent(Event& e);
		virtual bool OnWindowClose(WindowCloseEvent& e);
		virtual bool OnWindowResize(WindowResizeEvent& e);
		virtual bool OnKeyPressed(KeyPressedEvent& e);
		virtual bool OnKeyRepeat(KeyRepeatEvent& e);
		virtual bool OnKeyReleased(KeyReleasedEvent& e);
		virtual bool OnMouseButtonPressed(MouseButtonPressedEvent& e);
		virtual bool OnMouseButtonReleased(MouseButtonReleasedEvent& e);
		virtual bool OnMouseMoved(MouseMovedEvent& e);
		virtual bool OnMouseScrolled(MouseScrolledEvent& e);

		Window& GetWindow() { return *window_; }
		static Application& Get() { return *sInstance_; }
	private:
		static Application* sInstance_;

		std::unique_ptr<Window> window_;
		bool running_ = true;
		LayerStack layerStack_;
	};

	// To be defined in CLIENT
	Application* CreateApplication();
}

