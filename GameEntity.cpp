#include "GameEntity.h"

GameEntity::GameEntity(Map* map) : MapEntity(map) {
}

int GameEntity::GetPotions() const {
    return potions;
}