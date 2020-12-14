#pragma once
#include "Object.h"

#include <vector>

//class ComponentObject : public Object
//{
//public:
//	virtual ~ComponentObject() {}
//};
//
//class CompositeObject : public ComponentObject
//{
//public:
//	virtual ~CompositeObject() 
//	{
//		for (std::vector<ComponentObject*>::const_iterator it = _componentObject_table->begin();
//			it != _componentObject_table->end();
//			++it
//			)
//		{
//			delete (*it);
//		}
//
//		_componentObject_table->clear();
//
//		delete _componentObject_table;
//
//	}
//
//	CompositeObject() 
//	{
//		_componentObject_table = new std::vector<ComponentObject*>();
//	}
//
//	void addObject(ComponentObject* obj)
//	{
//		_componentObject_table->push_back(obj);
//	}
//private:
//	std::vector<ComponentObject*>* _componentObject_table;
//};