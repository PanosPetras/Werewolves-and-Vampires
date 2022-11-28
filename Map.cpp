#include "Map.h"
#include "GameEntity.h"
#include "Tree.h"
#include "Lake.h"
#include "PotionBoost.h"
#include <iostream>

using namespace std;

Map::Map(int width, int height){
	this->width = width;
	this->height = height;

	ticks = 0;
	timeOfDay = Day;

	map = new MapEntity*[width * height]();
	InitializeMap();
}

Map::~Map(){
	//Free all the memory that we allocated
	for (auto me : mapObstacles) {
		delete me;
	}

	delete boost;

	delete[] map;
}

void Map::InitializeMap(){
	for (int i = 0; i < width * height; i++) {
		map[i] = NULL;
	}

	//Add obstacles
	for (int i = 0; i < width * height / 50; i++) {
		mapObstacles.push_back(new Tree(this));
	}
	for (int i = 0; i < width * height / 80; i++) {
		mapObstacles.push_back(new Lake(this));
	}

	//Add the potion boost
	boost = new PotionBoost(this);
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

std::vector<MapEntity*> Map::GetAdjacentEntities(const MapEntity& entity) const{
	std::vector<MapEntity*> vec;
	MapEntity* ptr;

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

void Map::MoveEntity(MapEntity& entity, int x, int y) {
	if (!IsPositionValid(x, y)) return;

	map[entity.GetX() + entity.GetY() * width] = NULL;
	map[x + y * width] = &entity;

	entity.x = x;
	entity.y = y;
}

void Map::AddEntity(MapEntity* const entity){
	map[entity->GetX() + entity->GetY() * width] = entity;
}

void Map::RemoveEntity(const MapEntity* const entity) {
	map[entity->GetX() + entity->GetY() * width] = NULL;
}

void Map::Tick() {
	if (boost != NULL) {
		if (boost->PerformAction()) {
			delete boost;
			boost = NULL;
		}
	}

	DayNightCycle();
}

void Map::DayNightCycle() {
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