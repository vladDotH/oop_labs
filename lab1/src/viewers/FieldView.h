#ifndef FIELDVIEW_H
#define FIELDVIEW_H

#include "../field/Field.h"

class FieldView {
protected:
	Field *field;
public:
	FieldView() = default;
	FieldView(Field *field) : field(field) {}
	void setField(Field *field) { this->field = field; }
	
	virtual void show() = 0;
};

#endif //FIELDVIEW_H
