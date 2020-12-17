#include "src/graphics/window.h"
#include "src/maths/maths.h"

using namespace artem::graphics;
using namespace artem::maths;

int main()
{
	Window window("Artem", 800, 600);
	glClearColor(0.2f, 0.3f, 0.8f, 1.0f);

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
