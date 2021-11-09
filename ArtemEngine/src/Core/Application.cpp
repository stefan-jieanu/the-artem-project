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

    while (!window_->ShouldClose()) {
        window_->OnUpdate();
    }

}


} // namespace Engine
