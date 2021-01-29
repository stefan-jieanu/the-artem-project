#pragma once

#include "Core.h"
#include "Window.h"
#include "ArtemEngine/LayerStack.h"
#include "ArtemEngine/Events/Event.h"
#include "ArtemEngine/Events/ApplicationEvent.h"
#include "ArtemEngine/Events/KeyEvent.h"
#include "ArtemEngine/Events/MouseEvent.h"
#include "ArtemEngine/Core/DeltaTime.h"

namespace ArtemEngine {

	class Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
		void Terminate();
		void PushLayer(Shared<Layer> layer);
		void PopLayer(Shared<Layer> layer);

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

		Unique<Window> window_;
		bool running_ = true;
		bool minimized_ = false;
		LayerStack layerStack_;

		float lastFrameTime_= 0.0f;
	};

	// To be defined in CLIENT
	Application* CreateApplication();
}

