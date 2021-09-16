#include "Field.h"

Field::Field(int width, int height) : width(width), height(height) {
    cells = new Cell *[height];
    for (int i = 0; i < height; ++i) {
        cells[i] = new Cell[width];
    }
    default_generation();
}

void Field::default_generation() {
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            cells[i][j].setType(Cell::Type::REGULAR);
        }
    }
    cells[0][0].setType(Cell::Type::ENTRANCE);
    cells[height - 1][width - 1].setType(Cell::Type::EXIT);
}

void Field::copy(const Field &f) {
    width = f.width;
    height = f.height;
    cells = new Cell *[height];
    for (int i = 0; i < height; ++i) {
        cells[i] = new Cell[width];
        std::copy(f.cells[i], f.cells[i] + width, cells[i]);
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
    width = std::exchange(f.width, 0);
    height = std::exchange(f.height, 0);
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
    for (int i = 0; i < height; ++i) {
        delete[] cells[i];
    }
    delete[] cells;
}

Field::~Field() {
    clear();
}

