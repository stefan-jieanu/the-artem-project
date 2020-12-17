#include "src/graphics/window.h"
#include "src/maths/vector2.h"

#include <typeinfo>

int main()
{
	using namespace artem::graphics;
	using namespace artem::maths;

	Window window("Artem", 800, 600);

	glClearColor(0.2f, 0.3f, 0.8f, 1.0f);

	Vector2 pos1(10, 11);
	Vector2 pos2(20, 25);
	pos1 = pos2;
	pos2 = Vector2(30, 30);
	std::cout << pos1 << std::endl;

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