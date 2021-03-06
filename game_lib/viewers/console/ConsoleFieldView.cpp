#include "ConsoleFieldView.h"

void ConsoleFieldView::show(std::ostream &os) {
    if (!field.expired()) {
        if (field.lock()->cells != nullptr) {
            for (int i = 0; i < field.lock()->size.y; ++i) {
                for (int j = 0; j < field.lock()->size.x; ++j) {
                    if (field.lock()->get(Vec2D(j, i)).getEntity())
                        std::cout << EntityView::getChar(*field.lock()->get(Vec2D(j, i)).getEntity()) << " ";
                    else
                        std::cout << CellView::getChar(field.lock()->get(Vec2D(j, i))) << " ";
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

void ConsoleFieldView::showInfo(std::ostream &os) {
    if (!field.expired())
        os << "size:" << field.lock()->size << " cells: " << field.lock()->cells.get() << '\n';
}
