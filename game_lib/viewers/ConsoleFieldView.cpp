#include "ConsoleFieldView.h"

void ConsoleFieldView::show(std::ostream &os) const {
    if (!field.expired()) {
        os << "size:" << field.lock()->size << " cells: " << field.lock()->cells.get() << '\n';
        if (field.lock()->cells != nullptr) {
            for (int i = 0; i < field.lock()->size.y; ++i) {
                for (int j = 0; j < field.lock()->size.x; ++j) {
                    std::cout << CellView::getChar((*field.lock())[Vec2D(j, i)]) << " ";
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
