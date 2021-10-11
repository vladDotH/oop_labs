#ifndef FIELDBUILDER_H
#define FIELDBUILDER_H

#include <memory>
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
    FieldBuilder() = default;

    FieldBuilder &setSize(Vec2D size);

    FieldBuilder &setType(Type type);

    std::shared_ptr<Field> build();
};

#endif //FIELDBUILDER_H
