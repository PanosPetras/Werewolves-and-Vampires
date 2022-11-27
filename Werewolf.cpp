#include "Werewolf.h"

int Werewolf::werewolfCount = 0;

Werewolf::Werewolf(Map* map) : NPC(map) {
}

void Werewolf::Move(){
}

char Werewolf::GetSymbol() const {
    return 'W';
}
