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
    std::shared_ptr<Field> field;
    std::weak_ptr<T> obj;

public:
    BaseController(std::shared_ptr<Field> field, std::shared_ptr<T> obj, Vec2D pos = -one, bool put = true)
            : field(field), obj(obj) {
        if (put) {
            if (pos != -one)
                this->put(pos);
        } else this->pos = pos;
    }

    BaseController(std::shared_ptr<Field> field, std::shared_ptr<Entity> obj, Vec2D pos = -one, bool put = true) :
            BaseController(field, std::dynamic_pointer_cast<T>(obj), pos, put) {}

    bool put(Vec2D v) {
        if (pos == -one) {
            if (v >= null && v < field->getSize()) {
                if (!field->get(v).getEntity()) {
                    if (field->get(v).putEntity(obj.lock())) {
                        pos = v;
                        notify(logInfo("entity has been put on: " + pos.toString()));
                        return true;
                    } else notify(logInfo("entity has not been put on: " + pos.toString()));
                } else notify(logWarn("try to put on claimed cell"));
            } else notify(logWarn("try to put no outside of field"));
        }
        return false;
    }

    virtual bool move(Vec2D v) {
        if (!expired()) {
            if (pos + v >= null && pos + v < field->getSize()) {
                if (field->get(pos).moveTo(field->get(pos + v))) {
                    Log log = logInfo("entity has been moved from: " + pos.toString());
                    pos += v;
                    if (field->get(pos).getEntity() == obj.lock())
                        log.msg += " to: " + pos.toString();
                    notify(log);
                    return true;
                } else
                    notify(logInfo("entity has not been move from: " + pos.toString() + " to: " + (pos + v).toString()));
            } else notify(logWarn("try to move to outside of field"));
        } else notify(logWarn("try to move the deleted entity"));

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

    std::weak_ptr<T> getObj() const {
        return obj;
    }

    virtual ~BaseController() = default;
};


#endif //BASECONTROLLER_H
