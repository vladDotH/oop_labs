#ifndef OBJECTSCOUNTER_H
#define OBJECTSCOUNTER_H

#include <set>
#include "Rule.h"
#include "entities/Entity.h"

class ObjectsCounter : public Rule {
protected:
    std::vector<std::weak_ptr<Entity>> objects;
    int n;

public:
    ObjectsCounter(int n) : n(n) {}

    void init(std::shared_ptr<Field> field, std::shared_ptr<PlayerController> pc,
              Vec2D exit, std::vector<std::weak_ptr<Entity>> objects) {
        this->n = n;
        Rule::init(field, pc, exit);
        if (n >= 0 && objects.size() < n)
            throw std::invalid_argument("unreachable condition");
        this->objects = objects;
    }

    bool condition() override {
        int c = 0;
        for (auto i: objects) {
            c += i.expired();
        }
        return n < 0 ? c == objects.size() : c >= n;
    }
};


#endif //OBJECTSCOUNTER_H
