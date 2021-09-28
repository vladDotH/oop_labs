#include "FieldBuilder.h"

Field FieldBuilder::default_generation(Vec2D v) {
    Field f(v);
    f.cells[0][0] = new Entrance();
    f.cells[v.y - 1][v.x - 1] = new Exit();
    for (int i = 0; i < v.y; ++i) {
        for (int j = 0; j < v.x; ++j) {
            if (f.cells[i][j] == nullptr)
                f.cells[i][j] = new Cell();
        }
    }
    return Field(std::move(f));
}

Field FieldBuilder::box_generation(Vec2D v) {
    if (!(v >= one * 4))
        throw std::invalid_argument("too small field");

    Field f(v);
    f.cells[1][1] = new Entrance();
    f.cells[v.y - 2][v.x - 2] = new Exit();
    for (int i = 0; i < v.y; ++i) {
        for (int j = 0; j < v.x; ++j) {
            if (f.cells[i][j] == nullptr) {
                if (i == 0 || i == v.y - 1 || j == 0 || j == v.x - 1)
                    f.cells[i][j] = new Wall();
                else
                    f.cells[i][j] = new Cell();
            }
        }
    }
    return Field(std::move(f));
}
