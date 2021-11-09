#pragma once

#include "Core.hpp"
#include <memory>


#include "Window.hpp"
#include "src/Platform/Linux/LinuxWindow.hpp"

namespace Engine
{

class ENGINE_API Application
{
public:
    Application();
    virtual ~Application();

    std::unique_ptr<LinuxWindow> window_;

    void Run();
};

Application* CreateApplication();

} // namespace Engine