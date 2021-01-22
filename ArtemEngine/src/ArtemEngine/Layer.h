#pragma once

#include "ArtemEngine/Core.h"
#include "ArtemEngine/Events/Event.h"

namespace ArtemEngine {

	class ARTEM_ENGINE_API Layer
	{
	public:
		Layer(const std::string& name = "Layer")
			: debugName_(name) {}
		virtual ~Layer() {}

		virtual void OnAttach() {}
		virtual void OnDetach() {}
		virtual void OnUpdate() {}
		virtual void OnEvent(Event& event) {}

		inline const std::string& GetName() const { return debugName_; }
	protected:
		std::string debugName_;
	};

}

