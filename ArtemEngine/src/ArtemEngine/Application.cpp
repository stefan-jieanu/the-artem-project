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
		LOG_ASSERT(!sInstance_, "Application already exists!");
		sInstance_ = this;
		
		window_ = std::unique_ptr<Window>(Window::Create());
		window_->SetEventCallback(BIND_EVENT_FN(Application::OnEvent));

		vao.reset(VertexArray::Create());

		float vertices[3 * 7] = {
			-0.5f, -0.5f, 0.0f, 0.8f, 0.2f, 0.8f, 1.0f,
			0.5f, -0.5f, 0.0f, 0.4f, 0.8f, 0.8f, 1.0f,
			0.0f, 0.5f, 0.0f, 0.2f, 0.8f, 0.3f, 1.0f
		};

		vb.reset(VertexBuffer::Create(vertices, sizeof(vertices)));

		BufferLayout layout{
			{ ShaderDataType::Float3, "position"},
			{ ShaderDataType::Float4, "color"}
		};
		vb->SetLayout(layout);

		vao->AddVertexBuffer(vb);

		uint32_t indices[3] = { 0, 1, 2 };
		ib.reset(IndexBuffer::Create(indices, sizeof(indices) / sizeof(uint32_t)));

		vao->SetIndexBuffer(ib);

		vao->Bind();

		shader.reset(new Shader("E:/Work/Artem/ArtemEngine/res/Shaders/basic.shader"));
		shader->Bind();
	}

	Application::~Application()
	{
	}

	void Application::Run()
	{
		while (running_)
		{
			glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
			glClear(GL_COLOR_BUFFER_BIT);

			for (std::shared_ptr<Layer> layer : layerStack_)
				layer->OnUpdate();

			glDrawElements(GL_TRIANGLES, ib->GetCount(), GL_UNSIGNED_INT, nullptr);

			window_->OnUpdate();
		}
	}

	void Application::Terminate()
	{
		running_ = false;
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
		dispatcher.Dispatch<WindowResizeEvent>(BIND_EVENT_FN(Application::OnWindowResize));
		dispatcher.Dispatch<KeyPressedEvent>(BIND_EVENT_FN(Application::OnKeyPressed));
		dispatcher.Dispatch<KeyRepeatEvent>(BIND_EVENT_FN(Application::OnKeyRepeat));
		dispatcher.Dispatch<KeyReleasedEvent>(BIND_EVENT_FN(Application::OnKeyReleased));
		dispatcher.Dispatch<MouseButtonPressedEvent>(BIND_EVENT_FN(Application::OnMouseButtonPressed));
		dispatcher.Dispatch<MouseButtonReleasedEvent>(BIND_EVENT_FN(Application::OnMouseButtonReleased));
		dispatcher.Dispatch<MouseMovedEvent>(BIND_EVENT_FN(Application::OnMouseMoved));
		dispatcher.Dispatch<MouseScrolledEvent>(BIND_EVENT_FN(Application::OnMouseScrolled));

		// If the event was not marked as handled by any of the previous callbacks
		// then send the event to the layers
		if (!e.IsHandled())
			for (std::shared_ptr<Layer> layer : layerStack_)
			{
				layer->OnEvent(e);
				if (e.IsHandled())
					break;
			}
	}

	bool Application::OnWindowClose(WindowCloseEvent& e)
	{
		return false;
	}
	
	bool Application::OnWindowResize(WindowResizeEvent& e)
	{
		return false;
	}
	
	bool Application::OnKeyPressed(KeyPressedEvent& e)
	{
		return false;
	}
	
	bool Application::OnKeyRepeat(KeyRepeatEvent& e)
	{
		return false;
	}
	
	bool Application::OnKeyReleased(KeyReleasedEvent& e)
	{
		return false;
	}
	
	bool Application::OnMouseButtonPressed(MouseButtonPressedEvent& e)
	{
		return false;
	}
	
	bool Application::OnMouseButtonReleased(MouseButtonReleasedEvent& e)
	{
		return false;
	}
	
	bool Application::OnMouseMoved(MouseMovedEvent& e)
	{
		return false;
	}
	
	bool Application::OnMouseScrolled(MouseScrolledEvent& e)
	{
		return false;
	}
}