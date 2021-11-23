#ifndef COLLECTOR_H
#define COLLECTOR_H

#include "ObjectsCounter.h"
#include "entities/items/Item.h"

template<int n>
class Collector : public ObjectsCounter<Item, n> {
public:
    Collector(std::shared_ptr<Field> field, std::shared_ptr<PlayerController> pc, Vec2D exit,
              std::vector<std::weak_ptr<Item>> objects) : ObjectsCounter<Item, n>(field, pc, exit, objects) {}
};


#endif //COLLECTOR_H
