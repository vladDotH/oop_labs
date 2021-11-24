#ifndef EXTERMINATOR_H
#define EXTERMINATOR_H

#include "ObjectsCounter.h"
#include "entities/creatures/enemies/Enemy.h"

template<int n>
class Exterminator : public ObjectsCounter<Enemy, n> {
public:
    void init(std::shared_ptr<Field> field, std::shared_ptr<PlayerController> pc, Vec2D exit,
              std::vector<std::weak_ptr<Enemy>> objects) {
        ObjectsCounter<Enemy, n>::init(field, pc, exit, objects);
    }
};


#endif //EXTERMINATOR_H
