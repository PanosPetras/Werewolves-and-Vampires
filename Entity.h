#pragma once

class Map;

class Entity {
protected:
	int potions = 0;

	Map* map;

public:
	Entity(Map* map);
	~Entity();

	virtual void Move() = 0;

	virtual char GetSymbol() const = 0;

	friend class Map;

protected:
	int x, y;

public:
	int GetX() const;
	int GetY() const;
};