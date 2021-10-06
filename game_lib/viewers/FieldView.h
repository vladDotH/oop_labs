#ifndef FIELDVIEW_H
#define FIELDVIEW_H

#include "../field/Field.h"
#include <memory>

class FieldView {
protected:
    std::weak_ptr<Field> field;
public:
    FieldView() = default;

    FieldView(std::weak_ptr<Field> field) : field(field) {}

    void setField(std::shared_ptr<Field> field) {
        this->field = field;
    }

    virtual ~FieldView() = default;
};

#endif //FIELDVIEW_H
