#pragma once
#include <vector>

#include "glm/glm.hpp"
#include "include/GL/glew.h"

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
public:
	virtual ~Object() {}
};

class RenderableObject : public Object, public IRenderer
{
public:
	RenderableObject();
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

private:
	virtual void doShutDown() override;
	virtual void doRender() override;
};

class NonRenderableObject : public Object, public IUpdater
{
public:
	NonRenderableObject();

	virtual void update() override;
private:
	//현재 데이터 없지만 Renderable도 쓰니까 코드의 공통성 유지
	virtual void doShutDown() override {};
	virtual void doUpdate() override;

protected:
	virtual void addSelfToUpdater() override;
};

