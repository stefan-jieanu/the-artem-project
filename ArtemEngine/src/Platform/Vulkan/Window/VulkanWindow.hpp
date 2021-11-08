#pragma once

#include "src/Core/Window.hpp"

// #define GLFW_INCLUDE_VULKAN
#include "GLFW/glfw3.h"

namespace Engine
{
    
class VulkanWindow : public Window
{
public:   
    VulkanWindow(const WindowProps& props);
    ~VulkanWindow();

    void OnUpdate() override;

    inline unsigned int GetWidth() const override { return data_.width; }
    inline unsigned int GetHeight() const override { return data_.height; }

    inline bool ShouldClose() const { return glfwWindowShouldClose(window_); }
    // inline VkExtent2D GetExtent()
    // { 
    //     return { static_cast<uint32_t>(data_.width), static_cast<uint32_t>(data_.height) }; 
    // }
    inline bool WasWindowResized() { return frameBufferResized_; }
    inline void ResetWindowResizedFlag() { frameBufferResized_ = false; }

    // void CreateWindowSurface(VkInstance instance, VkSurfaceKHR *surface);

    // // Window attributes
    inline void SetEventCallback(const EventCallbackFn& callback) override
    {
        data_.eventCallback = callback;
    }
    // void SetVSync(bool enabled) override;
    // bool IsVSync() const override;

private:    
    GLFWwindow* window_;

    struct WindowData
    {
        std::string title;
        unsigned int width, height;
        bool vSync;

        EventCallbackFn eventCallback;
    } data_;
    bool frameBufferResized_{false};
    
    void Init(const WindowProps& props);
    void Shutdown();
};

} // namespace Engine
