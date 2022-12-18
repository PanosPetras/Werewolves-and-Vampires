#include "Vampire.h"
#include "Map.h"
#include <random>

int Vampire::vampireCount = 0;

Vampire::Vampire(Map* map) : NPC(map) {
    vampireCount++;
}

Vampire::~Vampire() {
    vampireCount--;
}

void Vampire::Move(){
    //Generate a random movement vector
    std::uniform_int_distribution<std::mt19937::result_type> dist(0, 2);

    int px = x + dist(rng) - 1, py = y + dist(rng) - 1;
        
    if (map->IsPositionValid(px, py)) {
        map->MoveEntity(*this, px, py);
    }
}

char Vampire::GetSymbol() const{
    return 'V';
}

int Vampire::GetVampireCount() {
    return vampireCount;
}
