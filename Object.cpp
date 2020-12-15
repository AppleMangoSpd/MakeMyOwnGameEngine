#include <iostream>

#include "Object.h"
#include "Renderer.h"
#include "Updater.h"
#include "FileManager.h"

void Object::doSetPosition(glm::vec3 _input)
{
	Position = _input;
}

RenderableObject::RenderableObject()
{
	Renderer::instance()->addObject(this);
}

void RenderableObject::shutDown()
{
	this->doShutDown();
}

void RenderableObject::render()
{
	this->doRender();
}

void RenderableObject::KeyDowned(int key)
{
	glm::vec3 newPosition;
	switch (key)
	{
	case GLFW_KEY_UP:
		newPosition = glm::vec3(Position.x, Position.y + 0.01f, Position.z);
		setPosition(newPosition);
		break;
	case GLFW_KEY_DOWN:
		newPosition = glm::vec3(Position.x, Position.y - 0.01f, Position.z);
		setPosition(newPosition);
		break;
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

void RenderableObject::doShutDown()
{
	glDeleteBuffers(1, &vertexbuffer);
	glDeleteBuffers(1, &uvbuffer);
	glDeleteBuffers(1, &normalbuffer);
	glDeleteProgram(programID);
	glDeleteTextures(1, &Texture);
	glDeleteVertexArrays(1, &VertexArrayID);
}

void RenderableObject::doRender()
{
	Renderer::instance()->render(this);
}

NonRenderableObject::NonRenderableObject()
{
	addSelfToUpdater();
}

void NonRenderableObject::update()
{
	this->doUpdate();
}

void NonRenderableObject::KeyDowned(int key)
{
}

void NonRenderableObject::doUpdate()
{
	
}

void NonRenderableObject::addSelfToUpdater()
{
	Updater::instance()->addObject(this);
}
