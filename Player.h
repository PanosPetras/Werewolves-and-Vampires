#pragma once
#include "Entity.h"

class Player : public Entity {
public:
	Player(Map* map);

	void Move();

	void HealTeam();

	char GetSymbol() const;
};
