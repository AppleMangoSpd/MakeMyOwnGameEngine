#include "Object.h"
#include "Renderer.h"

void Object::setPosition(glm::vec3 _input)
{
	Position = _input;
}

void RenderableObject::shutDown()
{
	glDeleteBuffers(1, &vertexbuffer);
	glDeleteBuffers(1, &uvbuffer);
	glDeleteBuffers(1, &normalbuffer);
	glDeleteProgram(programID);
	glDeleteTextures(1, &Texture);
	glDeleteVertexArrays(1, &VertexArrayID);
}

void RenderableObject::render()
{
	Renderer::instance()->render(this);
}

