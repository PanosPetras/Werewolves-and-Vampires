#include "Tree.h"

Tree::Tree(Map* map) : MapEntity(map) {
}

char Tree::GetSymbol() const {
    return 'T';
}
