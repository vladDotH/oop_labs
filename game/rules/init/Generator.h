#ifndef GENERATOR_H
#define GENERATOR_H

#include <memory>
#include "entities/Entity.h"
#include "entities/EntityFactory.h"
#include "field/Field.h"

class Generator {
    static const int MAX_ATTEMPT = 65536;
    std::shared_ptr<EntityFactory> fct;
    int size;

public:
    Generator(std::shared_ptr<EntityFactory> fct, int size) : size(size), fct(fct) {}

    int generate(std::shared_ptr<Field> field) {
        int put = 0;
        for (int i = 0; i < size; ++i) {
            int attempt = 0;
            Vec2D p;
            do {
                p = Vec2D::rand({0, field->getSize().x - 1}, {0, field->getSize().y - 1});
                attempt++;
            } while (!(!field->get(p).getEntity() && field->get(p).putEntity(fct->build()))
                     && attempt < MAX_ATTEMPT);
            put += (attempt < MAX_ATTEMPT);
        }
        return put;
    }
};


#endif //GENERATOR_H
