#include "CellView.h"

const char CellView::CELLS_CHAR[] = {' ', '#', '@', '$'};
const std::map<size_t, char> CellView::chars = {
        {typeid(Cell).hash_code(),     CELLS_CHAR[0]},
        {typeid(Wall).hash_code(),     CELLS_CHAR[1]},
        {typeid(Entrance).hash_code(), CELLS_CHAR[2]},
        {typeid(Exit).hash_code(),     CELLS_CHAR[3]}
};

char CellView::getChar(AbstractCell *p) {
    return chars.at(typeid(*p).hash_code());
}

char CellView::getChar(const AbstractCell& c) {
    return chars.at(typeid(c).hash_code());
}
