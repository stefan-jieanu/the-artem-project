#pragma once
#include "Core.h"

namespace ArtemEngine {

	class ARTEM_ENGINE_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	};

	// To be defined in CLIENT
	Application* CreateApplication();
}

