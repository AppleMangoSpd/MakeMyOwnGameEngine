#include "Player.h"
#include "Renderer.h"
#include "FileManager.h"
Player::Player()
{
	//need to fix) do loadObj in child
	FileManager::instance()->loadObj(
		this,
		"cube.obj",
		"uvtemplate.DDS",
		"vs.shader",
		"fs.shader"
	);
}

void Player::KeyDowned(int key)
{
	glm::vec3 newPosition;
	switch (key)
	{
	case GLFW_KEY_LEFT:
		newPosition = glm::vec3(Position.x - 0.01f, Position.y, Position.z);
		setPosition(newPosition);
		break;
	case GLFW_KEY_RIGHT:
		newPosition = glm::vec3(Position.x + 0.01f, Position.y, Position.z);
		setPosition(newPosition);
		break;
	default:
		break;
	}
	newPosition = glm::vec3(0.0f, 0.0f, 0.0f);
}
