#ifndef BASECONTROLLER_H
#define BASECONTROLLER_H

#include "../core/Vec2D.h"
#include "../field/Field.h"
#include "../entities/Entity.h"
#include "memory"

template<class T, typename std::enable_if<std::is_base_of<Entity, T>::value, void *>::type * = nullptr>
class BaseController {
protected:
    Vec2D pos;
    std::weak_ptr<Field> field;
    std::weak_ptr<T> obj;

public:
    BaseController(std::shared_ptr<Field> field, std::shared_ptr<T> obj, Vec2D pos) : field(field), obj(obj), pos(pos) {
    }

    virtual bool put() {
        if (!field.lock()->get(pos).getEntity().expired())
            throw std::logic_error("cell is already taken");
        field.lock()->get(pos).putEntity(obj.lock());
    }

    virtual bool move(Vec2D v) {
        if (!obj.expired() && pos + v >= null && v < field.lock()->getSize()) {
            if (field.lock()->get(pos).moveTo(field.lock()->get(pos + v))) {
                pos += v;
                return true;
            }
        }
        return false;
    }

    bool expired() {
        return obj.expired();
    }

    virtual ~BaseController() = default;
};


#endif //BASECONTROLLER_H
