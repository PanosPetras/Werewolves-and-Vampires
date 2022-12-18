#include "PotionBoost.h"
#include "Map.h"
#include "Player.h"

PotionBoost::PotionBoost(Map* map) : MapEntity(map) {
}

char PotionBoost::GetSymbol() const {
	return 'B';
}

bool PotionBoost::PerformAction() {
	auto vec = map->GetAdjacentEntities(*this);

	for (auto e : vec) {
		//If the player is next to this potion, then 
		//return true and add a potion to the player's potion count
		if (e->GetSymbol() == 'P') {
			((Player*)e)->potions++;
			return true;
		}
	}
	return false;
}
