#pragma once
#include "NPC.h"

class Werewolf : public NPC {
protected:
	static int werewolfCount;

public:
	Werewolf(Map* map);
	~Werewolf();

	void Move();

	char GetSymbol() const;

	static int GetWerewolfCount();
};