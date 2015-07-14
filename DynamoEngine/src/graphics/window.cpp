#include "window.h"

namespace dynamo{
	namespace graphics{

        void window_resize(GLFWwindow *window, int width, int height);
		
		Window::Window(const char *name, int width, int height){
			m_Height = height;
			m_Width = width;
			m_Title = name;

			if (!Init()) {
				glfwTerminate();
			}

			for (int i = 0; i < MAX_KEYS; i++){
				m_Keys[i] = false;
			}

			for (int i = 0; i < MAX_BUTTONS; i++){
				m_MouseButtons[i] = false;
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
			glfwSetWindowUserPointer(m_Window, this);
			glfwSetWindowSizeCallback(m_Window, window_resize);
			glfwSetKeyCallback(m_Window, key_callback);
			glfwSetMouseButtonCallback(m_Window, mouse_button_callback);
			glfwSetCursorPosCallback(m_Window, cursor_position_callback);

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

		int Window::getWidth() const
		{
			return m_Width;
		}
		
		int Window::getHeight() const
		{
			return m_Height;
		}

		bool Window::IsKeyPressed(unsigned int keyCode) const
		{

			//TODO Throw Error if invalid arg is passed, log it perhaps.
			if (keyCode >= MAX_KEYS)
			{
				return false;
			}

			return m_Keys[keyCode];
		}

		bool Window::IsMouseButtonPressed(unsigned int button) const
		{

			//TODO Throw Error if invalid arg is passed, log it perhaps.
			if (button >= MAX_BUTTONS)
			{
				return false;
			}

			return m_MouseButtons[button];
		}

		void Window::getMousePosition(double& x, double& y) const
		{
			x = m_MouseX;
			y = m_MouseY;
		}

		void window_resize(GLFWwindow *window, int width, int height)
		{
			glViewport(0, 0, width, height);
		}

		void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
		{
			Window* win =(Window*) glfwGetWindowUserPointer(window);
			if (action != GLFW_RELEASE)
			{
				win->m_Keys[key] = true;
			}
		}


		void mouse_button_callback(GLFWwindow* window, int mouseButton, int action, int mods)
		{
			Window* win = (Window*)glfwGetWindowUserPointer(window);
			if (action != GLFW_RELEASE)
			{
				win->m_MouseButtons[mouseButton] = true;
			}

		}

		void cursor_position_callback(GLFWwindow* window, double xPos, double yPos)
		{
			Window* win = (Window*)glfwGetWindowUserPointer(window);
			win->m_MouseX = xPos;
			win->m_MouseY = yPos;
		}

	}
}