#ifndef FIELD_H
#define FIELD_H

#include "cells/Cell.h"
#include <iostream>
#include <utility>
#include "../viewers/Viewers_Declarations.h"

class Field {
friend class FieldView;
friend class ConsoleFieldView;
private:
    int width, height;
    Cell **cells;

    void clear();

    void copy(const Field &f);

    void move(Field &&f);

    void default_generation();

public:
    Field(int width, int height);

    Field(const Field &f);

    Field &operator=(const Field &f);

    Field(Field &&f);

    Field &operator=(Field &&f);

    ~Field();
};

#endif //FIELD_H
