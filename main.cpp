#include <iostream>

#include "src/graphics/window.h"

int main()
{
	using namespace GNgin;
	using namespace graphics;
	
	Window window("GNgin", 800, 600);
	glClearColor(0.2f, 0.3f, 0.8f, 1.0f);
	
	//std::cout << glGetString(GL_VERSION);

	GLuint vao;
	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);

	while (!window.closed())
	{
		window.clear();
#if 1
		glBegin(GL_TRIANGLES);
		glVertex2f(0.0f, 0.5f);
		glVertex2f(-0.5f, -0.5f);		
		glVertex2f(0.6f, -0.5f);
		glEnd();

#else

		glDrawArrays(GL_ARRAY_BUFFER, 0, 6);
#endif
		window.update();
	}

	//std::cout << std::endl;
	//system("PAUSE");

	return 0;
}