#pragma once
#include "Entity.h"

class NPC : public Entity {
protected:
	int health;
	int attack;
	int defence;

public:
	NPC();
};