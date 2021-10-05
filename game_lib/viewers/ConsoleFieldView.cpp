#include "ConsoleFieldView.h"

void ConsoleFieldView::show(std::ostream &os) const {
    if (field != nullptr) {
        os << "size:" << field->size << " cells: " << field->cells << '\n';
        if (field->cells != nullptr) {
            for (int i = 0; i < field->size.y; ++i) {
                for (int j = 0; j < field->size.x; ++j) {
                    std::cout << CellView::getChar(field->cells[i][j]) << " ";
                }
                std::cout << '\n';
            }
        }
    }
}

std::ostream &operator<<(std::ostream &os, ConsoleFieldView &fv) {
    fv.show(os);
    return os;
}
