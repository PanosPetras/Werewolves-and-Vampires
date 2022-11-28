#pragma once
#include <random>

class Map;

class MapEntity {
protected:
	//The position of the entity on the map
	int x, y;

	Map* map;

	//Create a random device
	static inline std::random_device dev;
	static inline std::mt19937 rng = std::mt19937(dev());

public:
	MapEntity(Map* map);
	virtual ~MapEntity();

	//Every entity must have a symbol to represent itself on the map
	virtual char GetSymbol() const = 0;

	//Accessors for the entity's position
	int GetX() const;
	int GetY() const;

	friend class Map;
};