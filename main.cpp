#include "src/graphics/window.h"
#include <iostream>

int main()
{
	using namespace GNgin;
	using namespace graphics;
	
	Window window("GNgin", 800, 600);
	glClearColor(0.2f, 0.3f, 0.8f, 1.0f);
	
	//std::cout << glGetString(GL_VERSION);

	while (!window.closed())
	{
		window.clear();

		glBegin(GL_TRIANGLES);
		glVertex2f(-0.5f, -0.5f);
		glVertex2f(0.0f, 0.5f);
		glVertex2f(0.5f, -0.5f);
		glEnd();

		window.update();
	}

	//std::cout << std::endl;
	//system("PAUSE");

	return 0;
}