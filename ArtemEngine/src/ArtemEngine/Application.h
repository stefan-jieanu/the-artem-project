#pragma once

#include "Core.h"
#include "Window.h"

namespace ArtemEngine {

	class ARTEM_ENGINE_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	private:
		std::unique_ptr<Window> window_;
		bool running_ = true;
	};

	// To be defined in CLIENT
	Application* CreateApplication();
}

