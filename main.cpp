#define _CRT_SECURE_NO_WARNINGS

#pragma comment(lib, "OpenGL32.lib")
#pragma comment(lib, "lib-vc2017/glew32.lib")
#pragma comment(lib, "lib-vc2017/glfw3.lib")

#include "Object.h"
#include "FileManager.h"
#include "Renderer.h"

int main()
{
	FileManager* file_mgr = FileManager::instance();

	Renderer* renderer = Renderer::instance();
	renderer->init();
	renderer->setCameraPosition(glm::vec3(0.0f, 5.0f, 7.0f));

	RenderableObject* cube = new RenderableObject();
	cube->setPosition(glm::vec3(0.0f, 2.0f, 0.0f));

	file_mgr->loadObj(
		cube,
		"cube.obj",
		"uvtemplate.DDS",
		"vs.shader",
		"fs.shader"
	);

	while (true)
	{
		renderer->render(cube);
	}

	renderer->shutDown();
	cube->shutDown();

	delete cube;

	return 0;
}