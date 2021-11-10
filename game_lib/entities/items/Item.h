#ifndef ITEM_H
#define ITEM_H

#include "../Entity.h"
#include <functional>

class Item : public Entity {
protected:
    std::function<bool(Creature &)> action;

    bool interact(Creature &entity) override {
        action(entity);
        notify(debug("item interacted with creature"));
        return true;
    }

    bool interact(Item &entity) override {
        notify(warn("item interacted with item"));
        return true;
    }

public:
    Item(std::function<bool(Creature &)> f) : action(f) {}

    bool interact(std::shared_ptr<Entity> entity) override {
        return entity->interact(*this);
    }

    std::shared_ptr<Entity> clone() override {
        return std::make_shared<Item>(action);
    }
};


#endif //ITEM_H
