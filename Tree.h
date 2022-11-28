#pragma once
#include "MapEntity.h"

class Tree : public MapEntity {
public:
	Tree(Map* map);
	char GetSymbol() const;
};