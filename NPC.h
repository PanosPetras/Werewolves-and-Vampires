#pragma once
#include "Entity.h"
#include <functional>

class Map;

class NPC : public Entity {
protected:
	int maxHealth;
	int health;
	int attack;
	int defence;

	static std::function<void(NPC*)> deathFunc;

public:
	NPC(Map* map);

	void PerformAction();

	static void ChangeDeathFunc(std::function<void(NPC*)> df);

	void GetHealed();

protected:
	void Attack(NPC* other) const;

	void GetAttacked(int attacker);

	void HealAlly(NPC* other);
};