#pragma once
#include <iostream>
#include <GL\glew.h>
#include <GLFW\glfw3.h>

namespace dynamo{
	namespace graphics{

		class Window
		{
			//vars
			
			private:
				int m_Width;
				int m_Height;
				const char *m_Title;
				GLFWwindow *m_Window;
				bool m_Closed;
			
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

			

			private:
				bool Init();		
		};
	}
}