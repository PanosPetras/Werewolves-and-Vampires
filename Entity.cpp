#include "Entity.h"
#include <random>

GameEntity::GameEntity(Map* map) : MapEntity(map) {
}

int GameEntity::GetPotions() const {
    return potions;
}