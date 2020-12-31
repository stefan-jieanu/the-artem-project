#include <time.h>

#include "src/graphics/window.h"
#include "src/graphics/Camera.h"
#include "src/graphics/Shader.h"
#include "src/graphics/layers/UILayer.h"
#include "src/graphics/layers/SceneLayer.h"
#include "src/utils/timer.h"
#include "src/settings/config.h"

using namespace artem::graphics;
using namespace artem::maths;

int main()
{
	Window window("Artem", WINDOW_WIDTH, WINDOW_HEIGHT);
	Camera* camera = new Camera(Vector2(WINDOW_WIDTH, WINDOW_HEIGHT) / 2, 1.0f, Vector2(WINDOW_WIDTH, WINDOW_HEIGHT));
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	
	// Shader stuff
	Shader sceneShader("RealMVPArtem/res/shaders/basic_light.shader");
	Shader uiShader("RealMVPArtem/res/shaders/basic_ui.shader");

	srand(time(NULL));

	// Creating layers and adding sprites to them
	UILayer uiLayer(uiShader);
	uiLayer.Add(new Sprite(Vector3(100, 100, 0), Vector3(100, 100, 0.1f), Vector4(0.5f, 1.0f, 1, 1)));

	SceneLayer sceneLayer(sceneShader);

	for (float y = 0; y < WINDOW_HEIGHT; y += 4) {
		for (float x = 0; x < WINDOW_WIDTH; x += 4) {
			sceneLayer.Add(new Sprite(Vector3(x, y, 0), Vector3(2.8f, 2.8f, 0.1f), Vector4(rand() % 1000 / 1000.0f, 0, 1, 1)));
		}
	}

	// FPS count setup
	artem::Timer time;
	float t = 0;
	unsigned int frames = 0;


	while (!window.closed()) 
	{	
		window.clear();

		// Vector2 mousePos = window.getMousePosition();
		// Vector2 onScrenMousePos = Vector2((float)(mousePos.x / WINDOW_WIDTH * 2 - 1.f), (float)(-mousePos.y / WINDOW_HEIGHT * 2 + 1.f));
		// shader.SetUniform2f("light_pos", onScrenMousePos);

		// Rendering
		sceneLayer.Render();
		uiLayer.Render();

		window.update();

		// Counting the FPS
		frames++;
		if (time.Elapsed() - t > 1.0f)
		{
			t += 1.0f;
			printf("FPS: %d\n", frames);
			frames = 0;
		}
	}

	return 0;
}
