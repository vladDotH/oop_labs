#include "ConsoleFieldView.h"

void ConsoleFieldView::show(std::ostream &os) {
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

/*
std::ostream &operator<<(std::ostream &os, const ConsoleFieldView &fv) {
    os << "width: " << fv.field->width << " height: " << fv.field->height << " cells: " << fv.field->cells << '\n';
    if (fv.field->cells != nullptr) {
        for (int i = 0; i < fv.field->height; ++i) {
            for (int j = 0; j < fv.field->width; ++j) {
                std::cout << fv.field->cells[i][j].getType() << ' ';
            }
            std::cout << '\n';
        }
    }
    return os;
}
*/
