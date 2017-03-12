#include "window.h"
#include <iostream>

namespace GNgin { namespace graphics {

	void windowResize(GLFWwindow *window, int width, int height);

	Window::Window(const char *title, int width, int height)
	{
		m_Title = title;
		m_Height = height;
		m_Width = width;

		if (!init())
			glfwTerminate();
	}

	Window::~Window()
	{

	}

	bool Window::init()
	{
		if (!glfwInit())
		{
			std::cout << "failed to initialize";
			return false;
		}

		m_Window = glfwCreateWindow(m_Width, m_Height, m_Title, NULL, NULL);

		if (!m_Window)
		{
			glfwTerminate();
			std::cout << "window creation failed!" << std::endl;
			return false;
		}

		glfwMakeContextCurrent(m_Window);

		return true;
	}

	bool Window::closed() const
	{
		return glfwWindowShouldClose(m_Window);
	}

	void Window::clear() const
	{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	}

	void Window::update() 
	{
		glfwPollEvents();		
		glfwSetWindowSizeCallback(m_Window, windowResize);
		glfwSwapBuffers(m_Window);
	}

	void windowResize(GLFWwindow *window, int width, int height)
	{
		glViewport(0, 0, width, height);
	}

	
}}