#include "aepch.h"
#include "Layer.h"

namespace ArtemEngine {

	Layer::Layer(const std::string& name)
		: debugName_(name)
	{

	}

	Layer::~Layer()
	{
	}

	void Layer::OnAttach()
	{
	}

	void Layer::OnDetach()
	{
	}

	void Layer::OnUpdate()
	{
	}

	void Layer::OnEvent(Event& e)
	{
		EventDispatcher dispatcher(e);
		dispatcher.Dispatch<WindowCloseEvent>(std::bind(&Layer::OnWindowClose, this, std::placeholders::_1));
		dispatcher.Dispatch<WindowResizeEvent>(std::bind(&Layer::OnWindowResize, this, std::placeholders::_1));
		dispatcher.Dispatch<KeyPressedEvent>(std::bind(&Layer::OnKeyPressed, this, std::placeholders::_1));
		dispatcher.Dispatch<KeyRepeatEvent>(std::bind(&Layer::OnKeyRepeat, this, std::placeholders::_1));
		dispatcher.Dispatch<KeyReleasedEvent>(std::bind(&Layer::OnKeyReleased, this, std::placeholders::_1));
		dispatcher.Dispatch<MouseButtonPressedEvent>(std::bind(&Layer::OnMouseButtonPressed, this, std::placeholders::_1));
		dispatcher.Dispatch<MouseButtonReleasedEvent>(std::bind(&Layer::OnMouseButtonReleased, this, std::placeholders::_1));
		dispatcher.Dispatch<MouseMovedEvent>(std::bind(&Layer::OnMouseMoved, this, std::placeholders::_1));
		dispatcher.Dispatch<MouseScrolledEvent>(std::bind(&Layer::OnMouseScrolled, this, std::placeholders::_1));
	}

	bool Layer::OnWindowClose(WindowCloseEvent& e)
	{
		return false;
	}

	bool Layer::OnWindowResize(WindowResizeEvent& e)
	{
		return false;
	}

	bool Layer::OnKeyPressed(KeyPressedEvent& e)
	{
		return false;
	}

	bool Layer::OnKeyRepeat(KeyRepeatEvent& e)
	{
		return false;
	}

	bool Layer::OnKeyReleased(KeyReleasedEvent& e)
	{
		return false;
	}

	bool Layer::OnMouseButtonPressed(MouseButtonPressedEvent& e)
	{
		return false;
	}

	bool Layer::OnMouseButtonReleased(MouseButtonReleasedEvent& e)
	{
		return false;
	}

	bool Layer::OnMouseMoved(MouseMovedEvent& e)
	{
		return false;
	}

	bool Layer::OnMouseScrolled(MouseScrolledEvent& e)
	{
		return false;
	}

}