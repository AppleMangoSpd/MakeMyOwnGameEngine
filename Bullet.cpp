#include "Bullet.h"
#include "Renderer.h"
#include "FileManager.h"

Bullet::Bullet()
{
	//need to fix) do loadObj in child
	FileManager::instance()->loadObj(
		this,
		"Sphere.obj",
		"uvtemplate.DDS",
		"vs.shader",
		"fs.shader"
	);
}
