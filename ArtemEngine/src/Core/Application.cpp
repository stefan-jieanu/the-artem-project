#include "pch.hpp"
#include "Application.hpp"

#include "Events/ApplicationEvent.hpp"


namespace Engine
{
    
Application::Application()
{
    Log::Init();
    window_ = std::make_unique<LinuxWindow>(WindowProps());
}

Application::~Application()
{

}

void Application::Run()
{
    WindowResizeEvent e(128, 256);
    LOG_CORE_TRACE(e);

    LOG_CORE_TRACE("hello now");

    while (!window_->ShouldClose()) {}
    LOG_CORE_INFO("closed window");
}


} // namespace Engine
