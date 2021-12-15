#include "pch.hpp"
#include "VulkanWindow.hpp"

namespace Engine
{

static bool GLFWInitialized = false;

VulkanWindow::VulkanWindow(const WindowProps& props)
{
    Init(props);
}

VulkanWindow::~VulkanWindow()
{
    Shutdown();
}

void VulkanWindow::OnUpdate()
{
    glfwPollEvents();
}

void VulkanWindow::CreateWindowSurface(VkInstance instance, VkSurfaceKHR *surface)
{
    if (glfwCreateWindowSurface(instance, window_, nullptr, surface) != VK_SUCCESS) 
    {
        throw std::runtime_error("failed to create window surface");
    }
}

void VulkanWindow::Init(const WindowProps& props)
{
    data_.title = props.title;
    data_.width = props.width;
    data_.height = props.height;

    if (!GLFWInitialized)
    {
        // TODO: glfwTerminate on system shutdown
        int success = glfwInit();

        LOG_CORE_INFO("Creating window {0} ({1} {2})", props.title, props.width, props.height);

        // TODO: assert success
        // LOG_CORE_ASSERT(success, "Could not initialize GLFW!");

        GLFWInitialized = true;
    }

    window_ = glfwCreateWindow((int)props.width, (int)props.height, props.title.c_str(), nullptr, nullptr);
    glfwSetWindowUserPointer(window_, &data_);
}

void VulkanWindow::Shutdown()
{
    glfwDestroyWindow(window_);
    glfwTerminate();
}

}