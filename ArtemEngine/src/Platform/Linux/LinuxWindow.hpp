#pragma once

#include "src/Platform/Vulkan/Window/VulkanWindow.hpp"

namespace Engine
{

class LinuxWindow : public VulkanWindow
{
public:
    LinuxWindow(const WindowProps& props);
    ~LinuxWindow();
};

}