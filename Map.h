#pragma once
#include <vector>

class Entity;

typedef enum TimeOfDay { Day = 0, Night = 1 } TimeOfDay;

class Map final {
public:
	Map(int width, int height);
	~Map();

	void Render() const;

	bool IsPositionValid(int x, int y) const;

	std::vector<Entity*> GetAdjacentEntities(const Entity& entity) const;

	void MoveEntity(Entity& entity, int x, int y);

	void AddEntity(Entity* const entity);

	void RemoveEntity(const Entity* const entity);

private:
	Entity** map;
	void InitializeMap();

	int width, height;

public:
	int GetWidth() const;
	int GetHeight() const;

private:
	int ticks;
	TimeOfDay timeOfDay;

public:
	void Tick();

	TimeOfDay GetTimeOfDay() const;
};