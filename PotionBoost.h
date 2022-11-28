#pragma once
#include "MapEntity.h"

class PotionBoost : public MapEntity {
public:
	PotionBoost(Map* map);

	char GetSymbol() const;

	bool PerformAction();
};