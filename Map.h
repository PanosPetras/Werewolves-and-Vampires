#pragma once
#include <vector>

class MapEntity;
class Tree;
class Lake;

typedef enum TimeOfDay { Day = 0, Night = 1 } TimeOfDay;

class Map final {
public:
	Map(int width, int height);
	~Map();

	void Render() const;

	bool IsPositionValid(int x, int y) const;

	std::vector<MapEntity*> GetAdjacentEntities(const MapEntity& entity) const;

	void MoveEntity(MapEntity& entity, int x, int y);

	void AddEntity(MapEntity* const entity);

	void RemoveEntity(const MapEntity* const entity);

private:
	std::vector<MapEntity*> mapObstacles;
	MapEntity** map;
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