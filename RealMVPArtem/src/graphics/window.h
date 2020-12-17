#pragma once

#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

namespace artem { namespace graphics {
    constexpr unsigned int max_keys = 1024;
    constexpr unsigned int max_buttons = 32;

    class Window 
    {
    private:
        const char *title_;
        int width_, height_;

        GLFWwindow* window_;

        bool s_Keys_[max_keys];
        bool s_MouseButtons_[max_buttons];
        double s_MouseX, s_MouseY;

        bool init();
        static friend void key_callback(GLFWwindow *window, int key, int scancode, int action, int mods);
        static friend void mouse_button_callback(GLFWwindow *window, int button, int action, int mods);
        static friend void cursor_position_callback(GLFWwindow *window, double xpos, double ypos);
    public:
        Window(const char *title, int width, int height);
        ~Window();
        void update();
        void clear() const;
        bool closed() const;

        inline int width() const { return width_; }
        inline int height() const { return height_; }

        bool isKeyPressed(unsigned int keycode) const;
        bool isButtonPressed(unsigned int button) const;
        void getMousePosition(double &x, double &y) const;
    };
} } 