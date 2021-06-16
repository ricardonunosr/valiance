#include "Window.h"
#include <iostream>

namespace Valiance
{
    Window::Window()
    {
        Init();
    }

    Window::~Window()
    {
        glfwTerminate();
    }

    bool m_WindowClosed = false;
    void OnWindowCloseCallback(GLFWwindow *window)
    {
        m_WindowClosed = true;
    }

    void Window::Init()
    {
        if (!glfwInit())
            std::cout << "Couldn't Initialize GLFW" << std::endl;

        glfwSetErrorCallback([](int error_code, const char *description) {
            std::cout << "Error Code: " << error_code << ", Error: " << description << '\n';
        });

        m_Window = glfwCreateWindow(800, 600, "Hello World", NULL, NULL);
        if (!m_Window)
        {
            glfwTerminate();
            std::cout << "Couldn't create window" << std::endl;
        }

        glfwMakeContextCurrent(m_Window);

        glfwSetWindowCloseCallback(m_Window, OnWindowCloseCallback);

        m_IsActive = true;
    }

    void Window::OnUpdate()
    {
        glfwSwapBuffers(m_Window);
        glfwPollEvents();

        if (m_WindowClosed)
        {
            m_IsActive = false;
            m_WindowClosed = false;
        }
    }


} // namespace Valiance