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

	void Window::Init()
	{
		if (!glfwInit())
			std::cout << "Couldn't Initialize GLFW" << std::endl;

		m_Window = glfwCreateWindow(800, 600, "Hello World", NULL, NULL);
		if (!m_Window)
		{
			glfwTerminate();
			std::cout << "Couldn't create window" << std::endl;
		}

		glfwMakeContextCurrent(m_Window);

		glfwSetWindowCloseCallback(m_Window, [](GLFWwindow*)
		{
			//TODO Event system
		});
	}

	void Window::OnUpdate()
	{
		glfwSwapBuffers(m_Window);
		glfwPollEvents();
	}

}