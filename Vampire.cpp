#include "Vampire.h"
#include <random>

int Vampire::vampireCount = 0;

Vampire::Vampire(Map* map) : NPC(map) {
}

void Vampire::Move(){
}

char Vampire::GetSymbol() const{
    return 'V';
}