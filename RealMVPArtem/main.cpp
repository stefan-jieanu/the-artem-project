#include "src/graphics/window.h"

int main()
{
	using namespace artem::graphics;

	Window window("Artem", 800, 600);

	glClearColor(0.2f, 0.3f, 0.8f, 1.0f);

	GLuint vao; 
	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);

	while (!window.closed()) 
	{	
		window.clear();

		glDrawArrays(GL_ARRAY_BUFFER, 0, 6);
		

		window.update();
	}

	return 0;
}