#pragma once
#include "MapEntity.h"

class Lake : public MapEntity {
public:
	Lake(Map* map);
	char GetSymbol() const;
};