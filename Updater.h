#pragma once
#include <vector>

#include "IUpdater.h"
class Updater :
    public IUpdater
{
public:
    Updater();

    static Updater* instance()
    {
        static Updater instance;
        return &instance;
    }

    void update() override;
    void addObject(IUpdater* _added);
    void addSelfToUpdater() override {};
private:
    std::vector<IUpdater*> updaterVec;

};

