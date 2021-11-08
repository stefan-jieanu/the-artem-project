#pragma once

#include "Core.hpp"
#include <memory>


#include "Window.hpp"
#include "src/Platform/Vulkan/Window/VulkanWindow.hpp"
namespace Engine
{

class ENGINE_API Application
{
public:
    Application();
    virtual ~Application();

    std::unique_ptr<VulkanWindow> window_;

    void Run();
};

Application* CreateApplication();

} // namespace Engine