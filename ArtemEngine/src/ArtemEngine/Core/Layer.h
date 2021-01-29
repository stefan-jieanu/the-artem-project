#pragma once

#include "ArtemEngine/Events/Event.h"
#include "ArtemEngine/Events/ApplicationEvent.h"
#include "ArtemEngine/Events/KeyEvent.h"
#include "ArtemEngine/Events/MouseEvent.h"
#include "ArtemEngine/Core/DeltaTime.h"

namespace ArtemEngine {

	class Layer
	{
	public:
		Layer(const std::string& name = "Layer");
		virtual ~Layer();

		virtual void OnAttach();
		virtual void OnDetach();
		virtual void OnUpdate(DeltaTime dt);

		virtual void OnEvent(Event& event);
	protected:
		virtual bool OnWindowClose(WindowCloseEvent& e);
		virtual bool OnWindowResize(WindowResizeEvent& e);
		virtual bool OnKeyPressed(KeyPressedEvent& e);
		virtual bool OnKeyRepeat(KeyRepeatEvent& e);
		virtual bool OnKeyReleased(KeyReleasedEvent& e);
		virtual bool OnMouseButtonPressed(MouseButtonPressedEvent& e);
		virtual bool OnMouseButtonReleased(MouseButtonReleasedEvent& e);
		virtual bool OnMouseMoved(MouseMovedEvent& e);
		virtual bool OnMouseScrolled(MouseScrolledEvent& e);

		inline const std::string& GetName() const { return debugName_; }
	protected:
		std::string debugName_;
	};

}

