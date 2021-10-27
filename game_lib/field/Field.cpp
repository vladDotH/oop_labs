#include "Field.h"

Vec2D Field::getSize() {
    return size;
}

AbstractCell &Field::get(Vec2D p) {
    if (!(p < size && p >= null)) {
        notify(error("cell index error"));
        throw std::out_of_range("cell index error");
    }
    if (cells[p.y][p.x] == nullptr) {
        notify(error("field was not built : nullptr error"));
        throw std::bad_alloc();
    }
    return *cells[p.y][p.x];
}

AbstractCell &Field::operator[](Vec2D p) {
    return get(p);
}

Field::Field(Vec2D size) : size(size) {
    if (size <= null) {
        notify(error("bad field size error"));
        throw std::invalid_argument("bad field size");
    }
    cells = std::make_unique<std::unique_ptr<std::unique_ptr<AbstractCell>[]>[]>(size.y);
    for (int i = 0; i < size.y; ++i) {
        cells[i] = std::make_unique<std::unique_ptr<AbstractCell>[]>(size.x);
        for (int j = 0; j < size.x; ++j) {
            cells[i][j] = nullptr;
        }
    }
}

void Field::copy(const Field &f) {
    size = f.size;
    cells = std::make_unique<std::unique_ptr<std::unique_ptr<AbstractCell>[]>[]>(size.y);
    for (int i = 0; i < size.y; ++i) {
        cells[i] = std::make_unique<std::unique_ptr<AbstractCell>[]>(size.x);
        for (int j = 0; j < size.x; ++j) {
            cells[i][j] = f.cells[i][j]->clone();
        }
    }
    notify(debug("field has been copied"));
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
    cells = std::move(f.cells);
    notify(debug("field has been moved"));
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
            cells[i][j].release();
        }
        cells[i].release();
    }
    cells.release();
    notify(debug("field has been cleared"));
}

Field::~Field() {
    clear();
}

bool Field::addLogger(std::shared_ptr<Logger> logger) {
    for (int i = 0; i < size.y; ++i) {
        for (int j = 0; j < size.x; ++j) {
            cells[i][j]->addLogger(logger);
        }
    }
    return Loggable::addLogger(logger);
}

bool Field::removeLogger(std::shared_ptr<Logger> logger) {
    for (int i = 0; i < size.y; ++i) {
        for (int j = 0; j < size.x; ++j) {
            cells[i][j]->removeLogger(logger);
        }
    }
    return Loggable::removeLogger(logger);
}

