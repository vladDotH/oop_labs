#ifndef ITEMS_H
#define ITEMS_H

#include "Generator.h"
#include "entities/items/ItemFactory.h"

template<int n>
class Items : public Generator<n, ItemFactory> {
public:
    Items(std::shared_ptr<ItemFactory> fct) : Generator<n, ItemFactory>(fct) {}
};


#endif //ITEMS_H
