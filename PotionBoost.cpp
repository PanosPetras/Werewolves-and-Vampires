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
		if (e->GetSymbol() == 'P') {
			((Player*)e)->potions++;
			return true;
		}
	}
	return false;
}
