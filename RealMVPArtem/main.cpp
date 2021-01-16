#include <time.h>

#include "src/graphics/window.h"
#include "src/graphics/Camera.h"
#include "src/graphics/Shader.h"
#include "src/graphics/layers/UILayer.h"
#include "src/graphics/layers/SceneLayer.h"
#include "src/utils/timer.h"
#include "src/settings/config.h"
#include "src/graphics/layers/Group.h"
#include "src/graphics/Texture.h"

using namespace artem::graphics;
using namespace artem::maths;

#define TEST 0

#if TEST == 1
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
	// uiLayer.Add(new Sprite(Vector3(100, 100, 0), Vector3(100, 100, 0.1f), Vector4(0.5f, 1.0f, 1, 1)));

	Group* group = new Group(Matrix4::Translate(Vector3(100, 100, 0)));
	Sprite* button = new Sprite(Vector3(0, 0, 0), Vector3(100, 100, 0.1f), Vector4(0.5f, 1.0f, 1, 1));
	Sprite* button2 = new Sprite(Vector3(10, 10, 0), Vector3(100, 10, 0.1f), Vector4(1.0f, 0.4f, 0.7f, 1));
	group->Add(button);
	group->Add(button2);
	uiLayer.Add(group);

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
#else
int main()
{
	Window window("Artem", WINDOW_WIDTH, WINDOW_HEIGHT);
	Camera* camera = new Camera(Vector2(WINDOW_WIDTH, WINDOW_HEIGHT) / 2, 1.0f, Vector2(WINDOW_WIDTH, WINDOW_HEIGHT));
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	
	// Shader stuff
	Shader sceneShader("RealMVPArtem/res/shaders/basic_light.shader");
	Shader uiShader("RealMVPArtem/res/shaders/basic_ui.shader");
	Shader texShader("RealMVPArtem/res/shaders/basic_texture.shader");

	int texIDs[] = 
	{
		0, 1, 2, 3, 4, 5, 6, 7, 8, 9
	};
	texShader.SetUniform1iv("textures", 10, texIDs);
	
	SceneLayer l1(texShader);
	l1.Add(new Sprite(Vector3(10, 10, 0), Vector3(100, 100, 0.1f), Vector4(0.5f, 0.1f, 1.0f, 1)));

	Texture* wood = new Texture("RealMVPArtem/res/images/wood1.png");
	Texture* stone = new Texture("RealMVPArtem/res/images/stone1.jpg");
	Texture* tex = new Texture("RealMVPArtem/res/images/test.png");
	l1.Add(new Sprite(Vector3(400, 300, 0), Vector3(100, 100, 0.1f), tex));
	l1.Add(new Sprite(Vector3(450, 350, 0), Vector3(100, 100, 0.1f), stone));
	l1.Add(new Sprite(Vector3(500, 400, 0), Vector3(100, 100, 0.1f), wood));
	l1.Add(new Sprite(Vector3(550, 450, 0), Vector3(100, 100, 0.1f), tex));
	// tex.Bind();


	while (!window.closed()) 
	{	
		window.clear();

		// Rendering
		l1.Render();
		

		window.update();
	}

	return 0;
}
#endif