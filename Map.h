#pragma once
#include <vector>

class Entity;

class Map final {
private:
	Entity** map;

	void InitializeMap();

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
	int width, height;

public:
	int GetWidth() const;
	int GetHeight() const;
};