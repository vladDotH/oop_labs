#ifndef FIELD_H
#define FIELD_H

#include "Cell.h"
#include <iostream>

class Field {
private:
    int width, height;
    Cell **cells;

    void clear();

    void copy(const Field &f);

    void default_generation();

public:
    Field(int width, int height);

    Field(const Field &f);

    Field &operator=(const Field &f);

    Field(Field &&f);

    Field &operator=(Field &&f);

    ~Field();

    friend std::ostream &operator<<(std::ostream &os, const Field &field);
};

#endif //FIELD_H
