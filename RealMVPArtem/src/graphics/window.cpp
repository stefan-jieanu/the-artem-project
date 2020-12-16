#include "window.h"

namespace artem { namespace graphics {

    void windowResize(GLFWwindow *window, int width, int heigth);

    Window::Window(const char* title, int width, int height)
        : title_(title), width_(width), height_(height)
    {
        if (!init()) 
        {
            glfwTerminate();
        }
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
        
        // Set a callback for window resizing
        glfwSetWindowSizeCallback(window_, windowResize);


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

    // Funcion not part of the window class, just a "helper function"
    void windowResize (GLFWwindow *window, int width, int heigth)
    {
        // Handling window resizing 
        glViewport(0, 0, width, heigth);
    }
} } 