#pragma once
#include "Entity.h"
#include <vector>

class NPC;

class Player : public Entity {
public:
	Player(Map* map);

	void Move();

	void HealTeam(std::vector<NPC*>& vec);

	char GetSymbol() const;

private:
	char team;
};
