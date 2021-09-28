#ifndef ENTITY_H
#define ENTITY_H

class Entity {
public:
    virtual bool interact(Entity *entity) = 0;
};

#endif //ENTITY_H
