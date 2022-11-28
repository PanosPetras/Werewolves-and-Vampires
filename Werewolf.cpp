#include "Werewolf.h"
#include <random>
#include "Map.h"

int Werewolf::werewolfCount = 0;

Werewolf::Werewolf(Map* map) : NPC(map) {
    werewolfCount++;
}

Werewolf::~Werewolf() {
    werewolfCount--;
}

void Werewolf::Move() {
    //Create a random device
    std::random_device dev;
    std::mt19937 rng(dev());

    //Generate a random movement vector
    std::uniform_int_distribution<std::mt19937::result_type> dist(0, 2);
    std::uniform_int_distribution<std::mt19937::result_type> dist1(0, 1);

    int px, py;
    do {
        px = x, py = y;

        if (dist1(rng)) {
            px += dist(rng) - 1;
        } else {
            py += dist(rng) - 1;
        }

    } while (!map->IsPositionValid(px, py));

    map->MoveEntity(*this, px, py);
}

char Werewolf::GetSymbol() const {
    return 'W';
}

int Werewolf::GetWerewolfCount() {
    return werewolfCount;
}
