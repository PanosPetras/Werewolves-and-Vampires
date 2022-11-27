#pragma once
#include "NPC.h"

class Werewolf : public NPC {
protected:
	static int werewolfCount;

public:
	Werewolf(Map* map);

	void Move();

	char GetSymbol() const;
};