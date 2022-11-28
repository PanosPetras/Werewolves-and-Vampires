#include "NPC.h"
#include <random>
#include "Map.h"

std::function<void(NPC*)> NPC::deathFunc = NULL;

NPC::NPC(Map* map) : GameEntity(map) {
    //Create a random device
    std::random_device dev;
    std::mt19937 rng(dev());

    //Generate a random number between 2 and 8 for the health stat of the entity
    std::uniform_int_distribution<std::mt19937::result_type> dist(2, 8);
    maxHealth = health = dist(rng);

    //Generate a random number between 0 and 2 for the potions
    dist = std::uniform_int_distribution<std::mt19937::result_type>(0, 2);
    potions = dist(rng);

    //Generate a random number between 1 and 3 for the attack stat of the entity
    dist = std::uniform_int_distribution<std::mt19937::result_type>(1, 3);
    attack = dist(rng);

    //Generate a random number between 1 and 2 for the defence stat of the entity
    dist = std::uniform_int_distribution<std::mt19937::result_type>(1, 2);
    defence = dist(rng);
}

void NPC::PerformAction() {
    auto neighbors = map->GetAdjacentEntities(*this);

    for (auto e : neighbors) {
        if (e->GetSymbol() == 'W' || e->GetSymbol() == 'V') {

            if (e->GetSymbol() != this->GetSymbol()) {
                Attack((NPC*)e);
            } else {
                HealAlly((NPC*)e);
            }
        }
    }
}

void NPC::ChangeDeathFunc(std::function<void(NPC*)> df) {
    deathFunc = df;
}

void NPC::GetHealed() {
    if (health < maxHealth) {
        health++;
    }
}

void NPC::Attack(NPC* other) const {
    if (other->defence < this->attack) {
        //Create a random device
        std::random_device dev;
        std::mt19937 rng(dev());

        //Generate a random number that is between 0 and 1
        std::uniform_int_distribution<std::mt19937::result_type> dist(0, 1);

        //If we get a 1, we attack
        if (dist(rng) == 1) {
            other->GetAttacked(attack);
        }
    }
}

void NPC::GetAttacked(int attacker) {
    health += defence - attacker;

    if (health <= 0) {
        if (deathFunc != NULL) {
            deathFunc(this);
        }
    }
}

void NPC::HealAlly(NPC* other) {
    //Check if we have enough potions
    if (potions <= 0) return;
    //Check if the other entity is lower than max health
    if (other->health < other->maxHealth) return;

    //Create a random device
    std::random_device dev;
    std::mt19937 rng(dev());

    //Generate a random number that is between 0 and 2
    std::uniform_int_distribution<std::mt19937::result_type> dist(0, 2);

    //If we get a 1, we heal our ally
    if (dist(rng) == 1) {
        other->GetHealed();
        potions--;
    }
}
