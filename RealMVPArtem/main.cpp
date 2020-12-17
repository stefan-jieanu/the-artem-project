#include "src/graphics/window.h"
#include "src/maths/maths.h"

#include <typeinfo>

using namespace artem::graphics;
using namespace artem::maths;

void printsum(Vector2 a)
{
	std::cout << a << std::endl;
}

int main()
{
	Window window("Artem", 800, 600);
	glClearColor(0.2f, 0.3f, 0.8f, 1.0f);

	Vector2 a(3, 3);
	Vector2 b(8, 1);
	printsum(a + b);
	std::cout << a + b << std::endl;

	while (!window.closed()) 
	{	
		window.clear();

		// double x, y;
		// window.getMousePosition(x, y);
		// std::cout << x << " " << y << std::endl;

		window.update();
	}

	return 0;
}
