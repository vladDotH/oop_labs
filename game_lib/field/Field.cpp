#include "Field.h"

AbstractCell &Field::operator[](Vec2D p) {
    if (!(p < size && p >= null))
        throw std::out_of_range("cell index error");
    if (cells[p.y][p.x] == nullptr)
        throw std::bad_alloc();
    return *cells[p.y][p.x];
}

Field::Field(Vec2D size) : size(size) {
    cells = new AbstractCell **[size.y];
    for (int i = 0; i < size.y; ++i) {
        cells[i] = new AbstractCell *[size.x];
        for (int j = 0; j < size.x; ++j) {
            cells[i][j] = nullptr;
        }
    }
}

void Field::copy(const Field &f) {
    size = f.size;
    cells = new AbstractCell **[size.y];
    for (int i = 0; i < size.y; ++i) {
        cells[i] = new AbstractCell *[size.x];
        for (int j = 0; j < size.x; ++j) {
            cells[i][j] = f.cells[i][j]->copy();
        }
    }
}

Field::Field(const Field &f) {
    copy(f);
}

Field &Field::operator=(const Field &f) {
    if (this != &f) {
        clear();
        copy(f);
    }
    return *this;
}

void Field::move(Field &&f) {
    size = std::exchange(f.size, null);
    cells = std::exchange(f.cells, nullptr);
}

Field::Field(Field &&f) {
    move(std::move(f));
}

Field &Field::operator=(Field &&f) {
    if (this != &f) {
        clear();
        move(std::move(f));
    }
    return *this;
}

void Field::clear() {
    for (int i = 0; i < size.y; ++i) {
        for (int j = 0; j < size.x; ++j) {
            delete cells[i][j];
        }
        delete[] cells[i];
    }
    delete[] cells;
}

Field::~Field() {
    clear();
}

