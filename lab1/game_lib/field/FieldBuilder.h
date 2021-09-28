#ifndef FIELDBUILDER_H
#define FIELDBUILDER_H

#include "cells/Cell.h"
#include "cells/Wall.h"
#include "cells/Entrance.h"
#include "cells/Exit.h"
#include "Field.h"

class FieldBuilder {
public:
    FieldBuilder() = delete;

    static Field default_generation(Vec2D v);

    static Field box_generation(Vec2D v);
};

#endif //FIELDBUILDER_H
