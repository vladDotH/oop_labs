#include "CellView.h"

CellView::CellView() : ConsoleObjectView<AbstractCell>(
        {
                {typeid(Cell).hash_code(),     ' '},
                {typeid(Wall).hash_code(),     '#'},
                {typeid(Entrance).hash_code(), '@'},
                {typeid(Exit).hash_code(),     '$'}
        }
) {}

char CellView::getChar(const AbstractCell &c) {
    return chars.at(typeid(c).hash_code());
}
