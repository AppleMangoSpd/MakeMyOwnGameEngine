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
#include "Player.h"
#include "Bullet.h"

int main()
{
	FileManager* file_mgr = FileManager::instance();

	Renderer* renderer = Renderer::instance();
	renderer->init();
	renderer->setCameraPosition(glm::vec3(0.0f, -3.0f, 10.0f));

	Updater* updater = Updater::instance();

	GetKeyDown* key_mgr = GetKeyDown::instance();

	RenderableObject* playerCube = new Player();
	playerCube->setPosition(glm::vec3(0.0f, -3.0f, 0.0f));

	RenderableObject* bulletCube_1 = new RenderableObject();
	bulletCube_1->setPosition(glm::vec3(0.0f, 6.0f, 0.0f));

	NonRenderableObject* WindowControl = new NonRenderableObject();

	key_mgr->SetInfluencedObject(playerCube);

	while (!renderer->isEnd())
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
	
	delete playerCube;

	return 0;
}