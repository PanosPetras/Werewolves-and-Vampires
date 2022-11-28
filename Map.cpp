#include "Map.h"
#include "Entity.h"
#include <iostream>

using namespace std;

Map::Map(int width, int height){
	this->width = width;
	this->height = height;

	ticks = 0;
	timeOfDay = Day;

	map = new Entity*[width * height]();
	InitializeMap();
}

Map::~Map(){
	//Free all the memory that we allocated
	delete[] map;
}

void Map::InitializeMap(){
	for (int i = 0; i < width * height; i++) {
		map[i] = NULL;
	}
}

void Map::Render() const{
	if (timeOfDay == Day) {
		cout << "Day" << endl;
	} else {
		cout << "Night" << endl;
	}

	cout << endl << "  ";

	for (int i = 0; i < width; i++) {
		cout << (char)('A' + i);
	}

	cout << endl;

	for (int i = height - 1; i >= 0; i--) {
		printf("%2d", i + 1);
		for (int j = 0; j < width; j++) {
			if (map[j + i * width] != NULL) {
				cout << map[j + i * width]->GetSymbol();
			} else {
				cout << " ";
			}
		}
		cout << endl;
	}
}

bool Map::IsPositionValid(int x, int y) const {
	//Check if the position is within the x axis bounds
	if (x < 0 || x >= width) {
		return false;
	}

	//Check if the position is within the y axis bounds
	if (y < 0 || y >= height) {
		return false;
	}

	//Check if the position is not already occupied
	if (map[x + y * width] != NULL) {
		return false;
	}

	return true;
}

std::vector<Entity*> Map::GetAdjacentEntities(const Entity& entity) const{
	std::vector<Entity*> vec;
	Entity* ptr;

	int x = entity.GetX(), y = entity.GetY();

	for (int i = -1; i <= 1; i += 2) {
		if (x + i >= 0 && x + i < width) {
			ptr = map[x + i + y * width];
			if (ptr != NULL) {
				vec.push_back(ptr);
			}
		}

		if (y + i >= 0 && y + i < height) {
			ptr = map[x + (y + i) * width];
			if (ptr != NULL) {
				vec.push_back(ptr);
			}
		}
	}

	return vec;
}

void Map::MoveEntity(Entity& entity, int x, int y) {
	if (!IsPositionValid(x, y)) return;

	map[entity.GetX() + entity.GetY() * width] = NULL;
	map[x + y * width] = &entity;

	entity.x = x;
	entity.y = y;
}

void Map::AddEntity(Entity* const entity){
	map[entity->GetX() + entity->GetY() * width] = entity;
}

void Map::RemoveEntity(const Entity* const entity) {
	map[entity->GetX() + entity->GetY() * width] = NULL;
}

void Map::Tick() {
	ticks++;

	if (ticks > 12) {
		ticks = 0;
		timeOfDay = (TimeOfDay)(!timeOfDay);
	}
}

int Map::GetWidth() const {
	return width;
}

int Map::GetHeight() const {
	return height;
}

TimeOfDay Map::GetTimeOfDay() const {
	return timeOfDay;
}