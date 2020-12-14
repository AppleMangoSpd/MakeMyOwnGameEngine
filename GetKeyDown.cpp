#include "GetKeyDown.h"
#include "Renderer.h"

GetKeyDown::GetKeyDown()
{
	InfluencedRenderableObjectList = new std::vector<RenderableObject*>();
	InfluencedNonRenderableObjectList = new std::vector<NonRenderableObject*>();
}

GetKeyDown::~GetKeyDown()
{
}

void GetKeyDown::SetInfluencedObject(RenderableObject* _renderable)
{
	InfluencedRenderableObjectList->push_back(_renderable);
}

void GetKeyDown::SetInfluencedObject(NonRenderableObject* _nonrenderable)
{
	InfluencedNonRenderableObjectList->push_back(_nonrenderable);
}

void GetKeyDown::shutDown()
{
	InfluencedRenderableObjectList->clear();
	InfluencedNonRenderableObjectList->clear();

	delete InfluencedRenderableObjectList;
	delete InfluencedNonRenderableObjectList;
}

void GetKeyDown::update()
{
//
	if (glfwGetKey(Renderer::instance()->getWindow(),GLFW_KEY_UP) == GLFW_PRESS)
	{
		std::vector<RenderableObject*>::iterator it ;
		for (it = InfluencedRenderableObjectList->begin();
			it != InfluencedRenderableObjectList->end();
			it++)
		{
			(*it)->KeyDowned(GLFW_KEY_UP);
		}
		std::vector<NonRenderableObject*>::iterator nIt;
		for (nIt = InfluencedNonRenderableObjectList->begin();
			nIt != InfluencedNonRenderableObjectList->end();
			nIt++)
		{
			(*nIt)->KeyDowned(GLFW_KEY_UP);
		}
	}
	if (glfwGetKey(Renderer::instance()->getWindow(), GLFW_KEY_DOWN) == GLFW_PRESS)
	{
		std::vector<RenderableObject*>::iterator it;
		for (it = InfluencedRenderableObjectList->begin();
			it != InfluencedRenderableObjectList->end();
			it++)
		{
			(*it)->KeyDowned(GLFW_KEY_DOWN);
		}
		std::vector<NonRenderableObject*>::iterator nIt;
		for (nIt = InfluencedNonRenderableObjectList->begin();
			nIt != InfluencedNonRenderableObjectList->end();
			nIt++)
		{
			(*nIt)->KeyDowned(GLFW_KEY_DOWN);
		}
	}
	if (glfwGetKey(Renderer::instance()->getWindow(), GLFW_KEY_LEFT) == GLFW_PRESS)
	{
		std::vector<RenderableObject*>::iterator it;
		for (it = InfluencedRenderableObjectList->begin();
			it != InfluencedRenderableObjectList->end();
			it++)
		{
			(*it)->KeyDowned(GLFW_KEY_LEFT);
		}
		std::vector<NonRenderableObject*>::iterator nIt;
		for (nIt = InfluencedNonRenderableObjectList->begin();
			nIt != InfluencedNonRenderableObjectList->end();
			nIt++)
		{
			(*nIt)->KeyDowned(GLFW_KEY_LEFT);
		}
	}
	if (glfwGetKey(Renderer::instance()->getWindow(), GLFW_KEY_RIGHT) == GLFW_PRESS)
	{
		std::vector<RenderableObject*>::iterator it;
		for (it = InfluencedRenderableObjectList->begin();
			it != InfluencedRenderableObjectList->end();
			it++)
		{
			(*it)->KeyDowned(GLFW_KEY_RIGHT);
		}
		std::vector<NonRenderableObject*>::iterator nIt;
		for (nIt = InfluencedNonRenderableObjectList->begin();
			nIt != InfluencedNonRenderableObjectList->end();
			nIt++)
		{
			(*nIt)->KeyDowned(GLFW_KEY_RIGHT);
		}
	}
}
