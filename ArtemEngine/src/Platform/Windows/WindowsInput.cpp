#include "aepch.h"
#include "WindowsInput.h"

#include "ArtemEngine/Core/Application.h"
#include "GLFW/glfw3.h"

namespace ArtemEngine {

	Input* Input::sInstance_ = new WindowsInput();

	bool WindowsInput::GetKeyImpl(KeyCode keycode)
	{
		auto window = static_cast<GLFWwindow*>(Application::Get().GetWindow().GetNativeWindow());
		auto state = glfwGetKey(window, (int)keycode);
		return state == GLFW_PRESS || state == GLFW_REPEAT;
	}

	bool WindowsInput::GetMouseButtonImpl(int button)
	{
		auto window = static_cast<GLFWwindow*>(Application::Get().GetWindow().GetNativeWindow());
		auto state = glfwGetMouseButton(window, button);
		return state == GLFW_PRESS;
	}

}