#include "FieldBuilder.h"

void FieldBuilder::default_generation(Field &f) {
    f.cells[0][0] = std::make_unique<Entrance>();
    f.cells[size.y - 1][size.x - 1] = std::make_unique<Exit>();
    for (int i = 0; i < size.y; ++i) {
        for (int j = 0; j < size.x; ++j) {
            if (f.cells[i][j] == nullptr)
                f.cells[i][j] = std::make_unique<Cell>();
        }
    }
}

void FieldBuilder::box_generation(Field &f) {
    if (!(size >= one * 4)) {
        notify(error("too small size for box generation"));
        throw std::invalid_argument("too small size");
    }

    f.cells[1][1] = std::make_unique<Entrance>();
    f.cells[size.y - 2][size.x - 2] = std::make_unique<Exit>();
    for (int i = 0; i < size.y; ++i) {
        for (int j = 0; j < size.x; ++j) {
            if (f.cells[i][j] == nullptr) {
                if (i == 0 || i == size.y - 1 || j == 0 || j == size.x - 1)
                    f.cells[i][j] = std::make_unique<Wall>();
                else
                    f.cells[i][j] = std::make_unique<Cell>();
            }
        }
    }
}

std::shared_ptr<Field> FieldBuilder::build() {
    auto f = std::make_shared<Field>(size);
    switch (type) {
        case Type::DEFAULT:
            default_generation(*f);
            break;
        case Type::BOX:
            box_generation(*f);
            break;
    }
    notify(debug("field has been built"));
    return f;
}

FieldBuilder &FieldBuilder::setSize(Vec2D size) {
    this->size = size;
    return *this;
}

FieldBuilder &FieldBuilder::setType(FieldBuilder::Type type) {
    this->type = type;
    return *this;
}


