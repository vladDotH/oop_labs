#ifndef FIELDVIEW_H
#define FIELDVIEW_H

#include "field/Field.h"

class FieldView {
protected:
    Field *field = nullptr;
public:
    FieldView() = default;

    FieldView(Field *field) : field(field) {}

    const FieldView &setField(Field *field) {
        this->field = field;
        return *this;
    }

    virtual ~FieldView() = default;
};

#endif //FIELDVIEW_H
