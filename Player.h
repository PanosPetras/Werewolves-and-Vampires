#pragma once
#include "Entity.h"

class Player : public Entity {
public:
	void HealTeam();

	void Move(int x, int y);
};
