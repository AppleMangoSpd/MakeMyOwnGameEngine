#include "Updater.h"

Updater::Updater()
{
	updaterVec.clear();
}

void Updater::update()
{
	std::vector<IUpdater*>::iterator iter;
	iter = updaterVec.begin();
	while (iter != updaterVec.end())
	{
		(*iter)->update();
		iter++;
	}
}

void Updater::addObject(IUpdater* _added)
{
	updaterVec.push_back(_added);
}
