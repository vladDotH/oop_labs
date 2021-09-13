#ifndef ENTITY_H
#define ENTITY_H

class Entity {
    virtual void interact(const Entity &entity) = 0;
};

#endif //ENTITY_H
