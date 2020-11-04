#pragma once
#include "Object.h"
class GetKeyDown : public NonRenderableObject
{
public:
	void influencedObject(RenderableObject _renderable);
	void influencedObject(NonRenderableObject _nonrenderable);
	virtual void shutDown() override;
	virtual void update() override;
};

