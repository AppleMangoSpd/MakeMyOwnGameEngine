#pragma once
#include "Object.h"
#include <vector>

class GetKeyDown : public NonRenderableObject
{
public:
	static GetKeyDown* instance()
	{
		static GetKeyDown instance;
		return &instance;
	}

	GetKeyDown();
	~GetKeyDown();

private:
	std::vector<RenderableObject*>* InfluencedRenderableObjectList;
	std::vector<NonRenderableObject*>* InfluencedNonRenderableObjectList;
public:
	void SetInfluencedObject(RenderableObject* _renderable);
	void SetInfluencedObject(NonRenderableObject* _nonrenderable);
	virtual void shutDown() override;
	virtual void update() override;
};

