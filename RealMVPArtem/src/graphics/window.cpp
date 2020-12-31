#include "window.h"

namespace artem { namespace graphics {

    void window_resize(GLFWwindow *window, int width, int heigth);
    void key_callback(GLFWwindow *window, int key, int scancode, int action, int mods);
    void mouse_button_callback(GLFWwindow *window, int button, int action, int mods);
    void cursor_position_callback(GLFWwindow *window, double xpos, double ypos);

    Window::Window(const char* title, int width, int height)
        : title_(title), width_(width), height_(height)
    {
        if (!init()) 
            glfwTerminate();

        for (int i = 0; i < max_keys; i++)
            s_Keys_[i] = false;

        for (int i = 0; i < max_buttons; i++)
            s_MouseButtons_[i] = false;
    }   

    Window::~Window()
    {
        glfwTerminate();
    }

    bool Window::init()
    {
        if (!glfwInit())
        {
            std::cout << "Failed to init GLFW!\n";
            return false;
        }   

        window_ = glfwCreateWindow(width_, height_, title_, NULL, NULL);
        if (!window_) 
        {
            glfwTerminate();
            std::cout << "Failed to created glfw window\n";
            return false;
        }    
        // Make this window the current context for drawing
        glfwMakeContextCurrent(window_); 

        // Set a pointer to the window class so that we can access it in the callbacks
        glfwSetWindowUserPointer(window_, this);  
        
        // Set a callback for window resizing
        glfwSetWindowSizeCallback(window_, window_resize);

        // Set a callback for pressing a key
        glfwSetKeyCallback(window_, key_callback);

        // Set a callback for pressing a mouse button
        glfwSetMouseButtonCallback(window_, mouse_button_callback);

        // Set a callback for the cursor position
        glfwSetCursorPosCallback(window_, cursor_position_callback);

        glfwSwapInterval(0.0f);
        // Initializing GLEW
        if (glewInit() != GLEW_OK)
        {
            std::cout << "Could not initialize glew!\n";
            return false;
        }

        std::cout << "OpenGL: " << glGetString(GL_VERSION) << "\n";
        
        return true; 
    }

    void Window::update()  
    {
        // Polling events from keyboard and mouse
        glfwPollEvents();

        // Swapping the buffers
        glfwSwapBuffers(window_);
    }

    void Window::clear() const 
    {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    }

    bool Window::closed() const 
    {
        return glfwWindowShouldClose(window_);
    }


    bool Window::isKeyPressed(unsigned int keycode) const
    {
        if (keycode >= max_keys)
            return false;

        return s_Keys_[keycode];
    }

    bool Window::isButtonPressed(unsigned int button) const
    {
        if (button >= max_buttons)
            return false;

        return s_MouseButtons_[button];
    }

    const maths::Vector2& Window::getMousePosition() const
    {
        return maths::Vector2(s_MouseX, s_MouseY);
    }

    // Funcion not part of the window class, just a "helper function"
    void window_resize (GLFWwindow *window, int width, int heigth)
    {
        // Handling window resizing 
        glViewport(0, 0, width, heigth);
    }

    void key_callback(GLFWwindow *window, int key, int scancode, int action, int mods)
    {
        Window *win = (Window*) glfwGetWindowUserPointer(window);
        win->s_Keys_[key] = action != GLFW_RELEASE;
    }
    
    void mouse_button_callback(GLFWwindow *window, int button, int action, int mods)
    {
        Window *win = (Window*) glfwGetWindowUserPointer(window);
        win->s_MouseButtons_[button] = action != GLFW_RELEASE;
    }

    void cursor_position_callback(GLFWwindow *window, double xpos, double ypos)
    {
        Window *win = (Window*) glfwGetWindowUserPointer(window);
        win->s_MouseX = xpos;
        win->s_MouseY = ypos;
    }
} } 