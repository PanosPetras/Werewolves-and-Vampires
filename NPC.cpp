#include "NPC.h"
#include <random>

NPC::NPC(){
    //Create a random device
    std::random_device dev;
    std::mt19937 rng(dev());

    //Generate a random number between 2 and 8 for the health stat of the entity
    std::uniform_int_distribution<std::mt19937::result_type> dist(2, 8);
    health = dist(rng);

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
