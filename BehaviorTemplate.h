#pragma once
#include "glm/glm.hpp"
#include "include/GL/glew.h"

class BehaviorTemplate
{
public:
	void init() { doInit(); }
	void render() { doRender(); }
	void update() { doUpdate(); }
	void shutDown() { doShutDown(); }
	void setPosition(glm::vec3 _input) { doSetPosition(_input); }
protected:
	virtual void doInit() {};
	virtual void doRender() {};
	virtual void doUpdate() {};
	virtual void doShutDown() {};
	virtual void doSetPosition(glm::vec3 _input) {};
};

