#pragma once
#include "GameEntity.h"
#include <vector>

class NPC;

class Player : public GameEntity {
public:
	Player(Map* map);

	void Move();

	void HealTeam(std::vector<NPC*>& vec);

	char GetSymbol() const;

private:
	char team;
};
