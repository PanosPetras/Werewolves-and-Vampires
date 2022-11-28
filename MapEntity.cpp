#include "MapEntity.h"
#include "Map.h"
#include <random>

MapEntity::MapEntity(Map* map) {
    //Cache the pointer to the map
    this->map = map;

    //Create a random device
    std::random_device dev;
    std::mt19937 rng(dev());

    //Generate a random position for the entity
    std::uniform_int_distribution<std::mt19937::result_type> dist1(0, map->GetWidth() - 1);
    std::uniform_int_distribution<std::mt19937::result_type> dist2(0, map->GetHeight() - 1);
    do {
        x = dist1(rng), y = dist2(rng);
    } while (!map->IsPositionValid(x, y));

    //Add this entity to the map
    map->AddEntity(this);
}

MapEntity::~MapEntity() {
    map->RemoveEntity(this);
}

int MapEntity::GetX() const {
    return x;
}

int MapEntity::GetY() const {
    return y;
}
