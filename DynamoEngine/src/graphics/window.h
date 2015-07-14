#pragma once
#include <iostream>
#include <GL\glew.h>
#include <GLFW\glfw3.h>

namespace dynamo{
	namespace graphics{

#define MAX_KEYS 1024
#define MAX_BUTTONS 32
		
		class Window
		{
			//vars			
			private:
				int m_Width;
				int m_Height;
				const char *m_Title;
				GLFWwindow *m_Window;
				bool m_Closed;
				bool m_Keys[MAX_KEYS];
				bool m_MouseButtons[MAX_BUTTONS];
				double m_MouseX, m_MouseY;
			
			public:

			//methods
			public:
				Window(const char *name, int width, int height);
				~Window();
				void Update();
				bool Closed() const;
				void Clear() const;
				inline int getWidth() const;
				inline int getHeight() const;
				bool IsKeyPressed(unsigned int keyCode) const;
				bool IsMouseButtonPressed(unsigned int keyCode) const;
				void getMousePosition(double& x, double& y) const;

			private:
				bool Init();
				friend static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
				friend static void mouse_button_callback(GLFWwindow* window, int mouseButton, int action, int mods);
				friend static void cursor_position_callback(GLFWwindow* window, double xPos, double yPos);
		};
	}
}