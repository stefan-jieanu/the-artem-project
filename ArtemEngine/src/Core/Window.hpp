#pragma once 

#include <functional>

#include "src/Events/Event.hpp"

namespace Engine
{
    
struct WindowProps
{
    std::string title;
    unsigned int width;
    unsigned int height;

    WindowProps(
        const std::string& t = "Artem Engine",
        unsigned int w = 1280,
        unsigned int h = 720)
        : title{t}, width{w}, height{h} {}
};

class ENGINE_API Window
{
public:
    using EventCallbackFn = std::function<void(Event&)>;

    virtual ~Window() {}

    virtual void OnUpdate() = 0;

    virtual inline unsigned int GetWidth() const = 0;
    virtual inline unsigned int GetHeight() const = 0;

    // Window attributes
    virtual inline void SetEventCallback(const EventCallbackFn& callback) = 0;
    // virtual void SetVSync(bool enabled) = 0;
    // virtual bool IsVSync() const = 0;

    static Window* Create(const WindowProps& props = WindowProps());
};

} // namespace Engine
