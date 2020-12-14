#define _CRT_SECURE_NO_WARNINGS

#pragma comment(lib, "OpenGL32.lib")
#pragma comment(lib, "lib-vc2017/glew32.lib")
#pragma comment(lib, "lib-vc2017/glfw3.lib")

#include "Object.h"
#include "FileManager.h"
#include "Renderer.h"
#include "Sphere.h"
#include "Updater.h"
#include "BehaviorTemplate.h"
#include "GetKeyDown.h"

int main()
{
	FileManager* file_mgr = FileManager::instance();

	Renderer* renderer = Renderer::instance();
	renderer->init();
	renderer->setCameraPosition(glm::vec3(5.0f, 10.0f, 5.0f));

	Updater* updater = Updater::instance();

	GetKeyDown* key_mgr = GetKeyDown::instance();

	RenderableObject* cube = new RenderableObject();
	cube->setPosition(glm::vec3(0.0f, 2.0f, 0.0f));

	NonRenderableObject* non_render_obj = new NonRenderableObject();

	key_mgr->SetInfluencedObject(cube);

	while (true)
	{
		if (renderer->canUpdate())
		{
			//renderer->update(non_render_obj);
			updater->update();
		}
		if (renderer->canRender())
		{
			renderer->render();
		}
	}

	//non_render_obj->shutDown();
	//cube->shutDown();
	//renderer->shutDown();

	delete non_render_obj;
	delete cube;

	return 0;
}