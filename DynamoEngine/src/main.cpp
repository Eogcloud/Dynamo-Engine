#include "graphics/window.h"
#include "math/math.h"
#include <iostream>
#include <GLFW\glfw3.h>


int main()
{
	using namespace dynamo;
	using namespace graphics;
	using namespace math;

	Window window("Dynamo", 1024, 768);
	glClearColor(0.2f, 0.3f, 0.8f, 1.0f);

	GLuint vao;
	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);

	vec2 vector(1.0f, 2.0f);

	while (!window.Closed())
	{
		
		window.Clear();
		std::cout << window.IsKeyPressed(GLFW_KEY_A) << std::endl;
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


