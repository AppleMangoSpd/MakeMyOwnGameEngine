#pragma once
#include <vector>

#include "glm/glm.hpp"
#include "include/GL/glew.h"
#include "include/GLFW/glfw3.h"

#include "ComponentObject.h"
#include "BehaviorTemplate.h"
#include "ICleanUp.h"
#include "IUpdater.h"
#include "IRenderer.h"

class Object : public ICleanUp, public BehaviorTemplate
{
public:
	glm::vec3 Position;
	
public:
	void doSetPosition(glm::vec3 _input) override;
	void shutDown() override {};

	virtual void KeyDowned(int key) {};
public:
	Object() {}
	virtual ~Object() {}
};

class RenderableObject : public Object, public IRenderer
{
public:
	RenderableObject();
	~RenderableObject()
	{
		this->doShutDown();
	}
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
	virtual void shutDown();
	virtual void render();
	virtual void KeyDowned(int key) override;
private:
	virtual void doShutDown();
	virtual void doRender();
};

class NonRenderableObject : public Object, public IUpdater
{
public:
	NonRenderableObject();
	~NonRenderableObject()
	{
		this->doShutDown();
	}
	virtual void update() override;
	virtual void KeyDowned(int key) override;

private:
	//���� ������ ������ Renderable�� ���ϱ� �ڵ��� ���뼺 ����
	virtual void doShutDown()  {};
	virtual void doUpdate();

protected:
	virtual void addSelfToUpdater() override;
};

