#pragma once
#include "Object.h"

class Player : public RenderableObject
{
public:
	Player();
	virtual void KeyDowned(int key) override;
private:
};

