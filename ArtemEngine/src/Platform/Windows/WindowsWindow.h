#pragma once

#include "ArtemEngine/Window.h"
#include <GLFW/glfw3.h>

namespace ArtemEngine {

	class WindowsWindow : public Window
	{
	public:
		WindowsWindow(const WindowProps& props);
		virtual ~WindowsWindow();

		void OnUpdate() override;

		inline unsigned int GetWidth() const override { return data_.width; }
		inline unsigned int GetHeight() const override { return data_.height; }

		// Window attributes
		inline void SetEventCallback(const EventCallbackFn& callback) override { data_.eventCallback = callback; }
		void SetVSync(bool enabled) override;
		bool IsVSync() const override;
	private:
		struct WindowData
		{
			std::string title;
			unsigned int width, height;
			bool VSync;

			EventCallbackFn eventCallback;
		} data_;
		
		GLFWwindow* window_;

		virtual void Init(const WindowProps& props);
		virtual void Shutdown();
	};

}

