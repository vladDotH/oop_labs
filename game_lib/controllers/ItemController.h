#ifndef ITEMCONTROLLER_H
#define ITEMCONTROLLER_H

#include "BaseController.h"
#include "../entities/items/Item.h"

class ItemController : public BaseController<Item> {
public:
    ItemController(std::shared_ptr<Field> field, std::shared_ptr<Item> obj, Vec2D pos = -one, bool put = true)
            : BaseController(field, obj, pos, put) {}

    ItemController(std::shared_ptr<Field> field, std::shared_ptr<Entity> obj, Vec2D pos = -one, bool put = true)
            : BaseController(field, obj, pos, put) {}

    bool move(Vec2D v) override {
        return false;
    };
};


#endif //ITEMCONTROLLER_H
