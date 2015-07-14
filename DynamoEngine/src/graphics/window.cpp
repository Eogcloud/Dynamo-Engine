#include "window.h"

namespace dynamo{
	namespace graphics{

		void windowResize(GLFWwindow *window, int width, int height);

		Window::Window(const char *name, int width, int height){
			m_Height = height;
			m_Width = width;
			m_Title = name;

			if (!Init()) {
				glfwTerminate();
			}
		}

		Window::~Window()
		{
			glfwTerminate();
		}

		void Window::Clear() const
		{
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		}

		void Window::Update() 
		{
			glfwPollEvents();
			glfwGetFramebufferSize(m_Window, &m_Width, &m_Height);
			
			glfwSwapBuffers(m_Window);
		}

		bool Window::Init()
		{
			if (!glfwInit()){
				std::cout << "Error! Failed to initialize GLFW" << std::endl;
				return false;
			}

			m_Window = glfwCreateWindow(m_Width, m_Height, m_Title, NULL, NULL);
			if (!m_Window)
			{
				std::cout << "Failed to create GLFW window!" << std::endl;
				return false;
			}

			//GLEW initialization MUST follow context creation!!
			glfwMakeContextCurrent(m_Window);
			glfwSetWindowSizeCallback(m_Window, windowResize);

			if (glewInit() != GLEW_OK){
				std::cout << "Could not initialize GLEW!" << std::endl;
				return false;
			}
			
			std::cout << "OpenGL: " << glGetString(GL_VERSION) << std::endl;
			return true;
		}

		bool Window::Closed() const
		{
			return glfwWindowShouldClose(m_Window) == 1;
		}

		void windowResize(GLFWwindow *window, int width, int height)
		{
			glViewport(0, 0, width, height);
		}

		int Window::getWidth() const
		{
			return m_Width;
		}

		int Window::getHeight() const
		{
			return m_Height;
		}
	}
}