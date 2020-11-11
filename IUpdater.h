#pragma once
class IUpdater
{
public:
	virtual void update() = 0;
	virtual void addSelfToUpdater() = 0;
};