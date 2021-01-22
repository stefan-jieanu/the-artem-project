#include "aepch.h"
#include "WindowsWindow.h"

namespace ArtemEngine {

	static bool sGLFWInitialized = false;

	Window* Window::Create(const WindowProps& props)
	{
		return new WindowsWindow(props);
	}

	WindowsWindow::WindowsWindow(const WindowProps& props)
	{
		Init(props);
	}

	WindowsWindow::~WindowsWindow()
	{
		Shutdown();
	}

	void WindowsWindow::Init(const WindowProps& props)
	{
		data_.title = props.title;
		data_.width = props.width;
		data_.height = props.height;

		AR_CORE_INFO("Creating window {0} ({1}, {2})", data_.title, data_.width, data_.height);

		if (!sGLFWInitialized)
		{
			// TODO: glfwTerminate on system shutdown
			int success = glfwInit();
			AR_CORE_ASSERT(success, "Could not initialize GLFW!");

			sGLFWInitialized = true;
		}

		window_ = glfwCreateWindow((int)data_.width, (int)data_.height, data_.title.c_str(), nullptr, nullptr);
		glfwMakeContextCurrent(window_);
		glfwSetWindowUserPointer(window_, &data_);
		SetVSync(true);
	}

	void WindowsWindow::Shutdown()
	{
		glfwDestroyWindow(window_);
	}

	void WindowsWindow::OnUpdate()
	{
		glfwPollEvents();
		glfwSwapBuffers(window_);
	}

	void WindowsWindow::SetVSync(bool enabled)
	{
		if (enabled)
			glfwSwapInterval(1);
		else
			glfwSwapInterval(0);

		data_.VSync = enabled;
	}

	bool WindowsWindow::IsVSync() const
	{
		return data_.VSync;
	}

}