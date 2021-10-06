#ifndef FIELD_H
#define FIELD_H

#include <iostream>
#include <utility>
#include "cells/AbstractCell.h"
#include "../core/Vec2D.h"
#include "../viewers/Viewers_Declarations.h"
#include <memory>

class Field {
    friend class FieldView;

    friend class ConsoleFieldView;

    friend class FieldBuilder;

private:
    Vec2D size;
    std::unique_ptr<std::unique_ptr<std::unique_ptr<AbstractCell>[]>[]> cells;

    void clear();

    void copy(const Field &f);

    void move(Field &&f);

protected:
    Field(Vec2D size);

public:
    AbstractCell &operator[](Vec2D p);

    Field(const Field &f);

    Field &operator=(const Field &f);

    Field(Field &&f);

    Field &operator=(Field &&f);

    virtual ~Field();
};

#endif //FIELD_H
