#pragma once
#include "Entity.h"

class Map;

class NPC : public Entity {
protected:
	int health;
	int attack;
	int defence;

public:
	NPC(Map* map);

	void PerformAction();

protected:
	void Attack();

	void HealAlly();
};