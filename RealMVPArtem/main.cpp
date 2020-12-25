#include "src/graphics/window.h"
#include "src/graphics/Camera.h"
#include "src/graphics/Shader.h"
#include "src/graphics/Renderable2d.h"
#include "src/graphics/SimpleRenderer.h"

using namespace artem::graphics;
using namespace artem::maths;

int main()
{
	Window window("Artem", 800, 600);
	Camera camera(Vector2(800, 600) / 2, 1.0f, Vector2(800, 600));
	glClearColor(0.2f, 0.3f, 0.8f, 1.0f);
		


	Shader shader("RealMVPArtem/res/shaders/basic.shader");
	shader.Bind();

	shader.SetUniformMat4f("u_Projection", camera.GetOrthographicMatrix());
	shader.SetUniformMat4f("u_View", Matrix4::Translate(Vector3(0.0f, 0.0f, -3.0f)));

	Renderable2d sprite1(Vector3(300, 400, 1), Vector3(10, 10, 1), Vector4(1.0f, 0.5f, 0.5f, 1.0f), shader);
	Renderable2d sprite2(Vector3(10, 10, 1), Vector3(50, 50, 1), Vector4(0.5f, 1.0f, 0.5f, 1.0f), shader);
	SimpleRenderer renderer;

	while (!window.closed()) 
	{	
		window.clear();

		renderer.submit(&sprite1);
		renderer.submit(&sprite2);
		renderer.flush();

		window.update();
	}

	return 0;
}
