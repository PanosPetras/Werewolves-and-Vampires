#pragma once
#include "NPC.h"

class Vampire : public NPC {
protected:
	static int vampireCount;

public:
	Vampire(Map* map);
	~Vampire();

	void Move();

	char GetSymbol() const;

	static int GetVampireCount();
};