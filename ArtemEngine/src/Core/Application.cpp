#include "pch.hpp"
#include "Application.hpp"

#include "Events/ApplicationEvent.hpp"


namespace Engine
{
    
Application::Application()
{
    Log::Init();
    window_ = std::make_unique<VulkanWindow>(WindowProps());
}

Application::~Application()
{

}

void Application::Run()
{
    WindowResizeEvent e(128, 256);
    LOG_CORE_TRACE(e);

    while (true) {}
}


} // namespace Engine
