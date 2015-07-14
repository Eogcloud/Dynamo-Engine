#include <GLFW\glfw3.h>
#include <iostream>
#include "src/graphics/window.h"

int main()
{
	using namespace dynamo;
	using namespace graphics;

	Window window("Dynamo", 1024, 768);
	glClearColor(0.2f, 0.3f, 0.8f, 1.0f);

	while (!window.Closed()){
		
		std::cout << window.getWidth() << "x" << window.getHeight() << std::endl;
		
		window.Clear();
		glBegin(GL_TRIANGLES);
		glVertex2f(-0.5f, -0.5f);
		glVertex2f(0.0f, 0.5f);
		glVertex2f(0.5f, -0.5f);
		glEnd();
		window.Update();
	}

	system("PAUSE");
	return 0;
}


