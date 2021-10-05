#include "FieldBuilder.h"

Field FieldBuilder::default_generation() {
    Field f(size);
    f.cells[0][0] = new Entrance();
    f.cells[size.y - 1][size.x - 1] = new Exit();
    for (int i = 0; i < size.y; ++i) {
        for (int j = 0; j < size.x; ++j) {
            if (f.cells[i][j] == nullptr)
                f.cells[i][j] = new Cell();
        }
    }
    return Field(std::move(f));
}

Field FieldBuilder::box_generation() {
    if (!(size >= one * 4))
        throw std::invalid_argument("too small field");

    Field f(size);
    f.cells[1][1] = new Entrance();
    f.cells[size.y - 2][size.x - 2] = new Exit();
    for (int i = 0; i < size.y; ++i) {
        for (int j = 0; j < size.x; ++j) {
            if (f.cells[i][j] == nullptr) {
                if (i == 0 || i == size.y - 1 || j == 0 || j == size.x - 1)
                    f.cells[i][j] = new Wall();
                else
                    f.cells[i][j] = new Cell();
            }
        }
    }
    return Field(std::move(f));
}

FieldBuilder::FieldBuilder(const Vec2D &size, FieldBuilder::Type type) : size(size), type(type) {}

Field FieldBuilder::build() {
    switch (type) {
        case DEFAULT:
            return default_generation();
        case BOX:
            return box_generation();
    }
}
