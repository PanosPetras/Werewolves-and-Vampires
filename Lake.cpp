#include "Lake.h"

Lake::Lake(Map* map) : MapEntity(map) {
}

char Lake::GetSymbol() const {
    return 'L';
}
