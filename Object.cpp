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

	//need to fix) do loadObj in child
	FileManager::instance()->loadObj(
		this,
		"cube.obj",
		"uvtemplate.DDS",
		"vs.shader",
		"fs.shader"
	);
}

void RenderableObject::shutDown()
{
	this->doShutDown();
}

void RenderableObject::render()
{
	this->doRender();
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

void NonRenderableObject::doUpdate()
{
	std::cout << "NonRenderObj Updated!" << std::endl;
}

void NonRenderableObject::addSelfToUpdater()
{
	Updater::instance()->addObject(this);
}
