#define _CRT_SECURE_NO_WARNINGS

#pragma comment(lib, "OpenGL32.lib")
#pragma comment(lib, "lib-vc2017/glew32.lib")
#pragma comment(lib, "lib-vc2017/glfw3.lib")

#include "Object.h"
#include "FileManager.h"
#include "Renderer.h"
#include "Sphere.h"

int main()
{
	FileManager* file_mgr = FileManager::instance();

	Renderer* renderer = Renderer::instance();
	renderer->init();
	renderer->setCameraPosition(glm::vec3(0.0f, 5.0f, 7.0f));

	RenderableObject* cube = new RenderableObject();
	cube->setPosition(glm::vec3(0.0f, 2.0f, 0.0f));
	renderer->addObject(cube);

	file_mgr->loadObj(
		cube,
		"cube.obj",
		"uvtemplate.DDS",
		"vs.shader",
		"fs.shader"
	);

	Sphere* mySphere = new Sphere();
	renderer->addObject(mySphere);

	NonRenderableObject* non_render_obj = new NonRenderableObject();

	while (true)
	{
		renderer->update(non_render_obj);

		renderer->render();
	}

	non_render_obj->shutDown();
	renderer->shutDown();

	delete non_render_obj;
	delete mySphere;
	delete cube;

	return 0;
}