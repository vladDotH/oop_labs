#ifndef CONSOLEFIELDVIEW_H
#define CONSOLEFIELDVIEW_H

#include "FieldView.h"
#include "CellView.h"
#include <iostream>

class ConsoleFieldView : public FieldView {
public:
    using FieldView::FieldView;
    void show(std::ostream &os) const {
        if (field != nullptr) {
            os << "size:" << field->size << " cells: " << field->cells << '\n';
            if (field->cells != nullptr) {
                for (int i = 0; i < field->size.y; ++i) {
                    for (int j = 0; j < field->size.x; ++j) {
                        std::cout << CellView::getChar(CellView::getCellID(field->cells[i][j])) << " ";
                    }
                    std::cout << '\n';
                }
            }
        }
    }

    friend std::ostream &operator<<(std::ostream &os, ConsoleFieldView &fv) {
        fv.show(os);
        return os;
    }
};

#endif //CONSOLEFIELDVIEW_H
