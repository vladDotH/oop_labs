#ifndef FIELDBUILDER_H
#define FIELDBUILDER_H

#include "cells/Cell.h"
#include "cells/Wall.h"
#include "cells/Entrance.h"
#include "cells/Exit.h"
#include "Field.h"

class FieldBuilder {
public:
    enum Type {
        DEFAULT,
        BOX
    };

protected:
    void default_generation(Field &f);

    void box_generation(Field &f);

    Vec2D size;
    Type type;

public:
    FieldBuilder(const Vec2D &size, Type type);

    FieldBuilder& setSize(Vec2D &size);

    FieldBuilder& setType(Type type);

    Field build();
};

#endif //FIELDBUILDER_H
