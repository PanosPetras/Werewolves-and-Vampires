#pragma once

class Map;

class Entity {
protected:
	Map* map;

public:
	Entity(Map* map);
	virtual ~Entity();

	//Every entity must move, it's up to them to make an implementation
	virtual void Move() = 0;

	//Every entity must have a symbol to represent itself on the map
	virtual char GetSymbol() const = 0;

	friend class Map;

protected:
	//The amount of magic potions that the entity has
	int potions = 0;

	//The position of the entity on the map
	int x, y;

public:
	//Accessors for the entity's potions
	int GetPotions() const;

	//Accessors for the entity's position
	int GetX() const;
	int GetY() const;
};