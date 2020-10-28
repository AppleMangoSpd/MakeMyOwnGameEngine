#pragma once
#include <vector>

#include "glm/glm.hpp"
#include "include/GL/glew.h"

#include "ICleanUp.h"
#include "IUpdater.h"
#include "IRenderer.h"

class Object : public ICleanUp
{
public:
	glm::vec3 Position;
	
public:
	void setPosition(glm::vec3 _input);
public:
	virtual ~Object() {}
};

class RenderableObject : public Object, public IRenderer
{
public:
	GLuint VertexArrayID;
	GLuint programID;
	GLuint MatrixID;
	GLuint ViewMatrixID;
	GLuint ModelMatrixID;
	GLuint Texture;
	GLuint TextureID;

	std::vector<glm::vec3> vertices;
	std::vector<glm::vec2> uvs;
	std::vector<glm::vec3> normals;

	GLuint vertexbuffer;
	GLuint uvbuffer;
	GLuint normalbuffer;
	GLuint LightID;

public:
	virtual void shutDown() override;
	virtual void render() override;
};

class NonRenderableObject : public Object, public IUpdater
{
public:
	//���� ������ ������ Renderable�� ���ϱ� �ڵ��� ���뼺 ����
	virtual void shutDown() override {};
	virtual void update() override {};
};

