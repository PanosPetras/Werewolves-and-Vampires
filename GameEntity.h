#pragma once
#include "MapEntity.h"

class Map;

class GameEntity : public MapEntity {
public:
	GameEntity(Map* map);

	//Every entity must move, it's up to them to make an implementation
	virtual void Move() = 0;

protected:
	//The amount of magic potions that the entity has
	int potions = 0;

public:
	//Accessors for the entity's potions
	int GetPotions() const;
};