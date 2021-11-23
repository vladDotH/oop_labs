#ifndef BASECONTROLLER_H
#define BASECONTROLLER_H

#include "../core/Vec2D.h"
#include "../field/Field.h"
#include "../entities/Entity.h"
#include "../logging/Loggable.h"
#include <memory>

template<class T, typename std::enable_if<std::is_base_of<Entity, T>::value, void *>::type * = nullptr>
class BaseController : public Loggable {
protected:
    Vec2D pos = -one;
    std::weak_ptr<Field> field;
    std::weak_ptr<T> obj;

public:
    BaseController(std::shared_ptr<Field> field, std::shared_ptr<T> obj, Vec2D pos = -one) : field(field), obj(obj) {
        if (pos != -one)
            put(pos);
    }

    BaseController(std::shared_ptr<Field> field, std::shared_ptr<Entity> obj, Vec2D pos = -one) :
            BaseController(field, std::dynamic_pointer_cast<T>(obj), pos) {}

    bool put(Vec2D v) {
        if (pos == -one) {
            if (v >= null && v < field.lock()->getSize()) {
                if (field.lock()->get(pos).getEntity().expired()) {
                    if (field.lock()->get(pos).putEntity(obj.lock())) {
                        pos = v;
                        notify(info("entity has been put on: " + pos.toString()));
                        return true;
                    } else notify(info("entity has not been put on: " + pos.toString()));
                } else notify(warn("try to put on claimed cell"));
            } else notify(warn("try to put no outside of field"));
        }
        return false;
    }

    virtual bool move(Vec2D v) {
        if (!expired()) {
            if (pos + v >= null && pos + v < field.lock()->getSize()) {
                if (field.lock()->get(pos).moveTo(field.lock()->get(pos + v))) {
                    notify(info("entity has been moved from: " + pos.toString() + " to:" + (pos + v).toString()));
                    pos += v;
                    return true;
                } else notify(info("entity has not been move from: " + pos.toString() + " to:" + (pos + v).toString()));
            } else notify(warn("try to move to outside of field"));
        } else notify(warn("try to move the deleted entity"));

        return false;
    }

    bool moveAbs(Vec2D v) {
        return move(v - pos);
    }

    bool expired() {
        return obj.expired();
    }

    Vec2D getPos() const {
        return pos;
    }

    virtual ~BaseController() = default;
};


#endif //BASECONTROLLER_H
