#include "Cell.h"

void Cell::putEntity(Entity *entity) {
    this->entity = entity;
}

void Cell::setType(Cell::Type type) {
    this->type = type;
}

Cell::Type Cell::getType() const {
    return type;
}
