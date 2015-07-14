#include "src/graphics/window.h"
#include <iostream>
#include <GLFW\glfw3.h>

int main()
{
	using namespace dynamo;
	using namespace graphics;

	Window window("Dynamo", 1024, 768);
	glClearColor(0.2f, 0.3f, 0.8f, 1.0f);

	GLuint vao;
	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);

	while (!window.Closed())
	{
		
		window.Clear();
		glBegin(GL_POLYGON);
		glVertex2f(-0.5f, -0.5f);
		glVertex2f(0.0f, 0.5f);
		glVertex2f(0.5f, -0.5f);
		glEnd();
		glDrawArrays(GL_ARRAY_BUFFER, 0, 0);
		window.Update();
	}

	system("PAUSE");
	return 0;
}


