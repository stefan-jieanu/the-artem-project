#pragma once

#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

namespace artem { namespace graphics {
    class Window 
    {
    private:
        const char *title_;
        int width_, height_;

        GLFWwindow* window_;

        bool init();
    public:
        Window(const char *title, int width, int height);
        ~Window();
        void update();
        void clear() const;
        bool closed() const;

        inline int width() const { return width_; }
        inline int height() const { return height_; }
    };
} } 