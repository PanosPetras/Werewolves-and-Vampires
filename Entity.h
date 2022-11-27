#pragma once

class Entity {
protected:
	int x, y;
	int potions;

public:
	virtual void Move() = 0;
};