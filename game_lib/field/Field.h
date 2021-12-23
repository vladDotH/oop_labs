#ifndef FIELD_H
#define FIELD_H

#include <iostream>
#include <utility>
#include "cells/AbstractCell.h"
#include "../core/Vec2D.h"
#include "../viewers/viewers_declarations.h"
#include <memory>
#include "../logging//Loggable.h"
#include "../../game/serialization/Snapshots_declaration.h"

class Field : public Loggable {
    friend class FieldView;

    friend class ConsoleFieldView;

    friend class FieldBuilder;

    friend class FieldSnapshot;

private:
    Vec2D size;
    std::unique_ptr<std::unique_ptr<std::unique_ptr<AbstractCell>[]>[]> cells;

    void clear();

    void copy(const Field &f);

    void move(Field &&f);

public:
    Vec2D getSize();

    Field(Vec2D size);

    AbstractCell &get(Vec2D p);

    AbstractCell &operator[](Vec2D p);

    Field(const Field &f);

    Field &operator=(const Field &f);

    Field(Field &&f);

    Field &operator=(Field &&f);

    virtual ~Field();

    bool addLogger(std::shared_ptr<Logger> logger) override;

    bool removeLogger(std::shared_ptr<Logger> logger) override;

};


#endif //FIELD_H
