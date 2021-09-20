#include "ConsoleFieldView.h"

void ConsoleFieldView::show(std::ostream &os) const {
    if (field != nullptr) {
        os << "width: " << field->width << " height: " << field->height << " cells: " << field->cells << '\n';
        if (field->cells != nullptr) {
            for (int i = 0; i < field->height; ++i) {
                for (int j = 0; j < field->width; ++j) {
                    std::cout << field->cells[i][j].getType() << ' ';
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

