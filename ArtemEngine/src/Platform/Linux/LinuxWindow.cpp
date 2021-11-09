#include "pch.hpp"
#include "LinuxWindow.hpp"

namespace Engine
{
    
Window* Window::Create(const WindowProps& props)
{
    return new LinuxWindow(props);
}

LinuxWindow::LinuxWindow(const WindowProps& props)
    : VulkanWindow(props)
{

}

LinuxWindow::~LinuxWindow()
{

}

} // namespace Engine

