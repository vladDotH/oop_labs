#include <iostream>
#include <field/FieldBuilder.h>
#include <viewers/console/ConsoleFieldView.h>
#include "field/Field.h"

using namespace std;

int main() {
    ConsoleFieldView fv;
    shared_ptr<Field> f1 = FieldBuilder().setSize(Vec2D(5, 5)).setType(FieldBuilder::Type::BOX).build();
    fv.setField(f1);
    fv.showInfo(cout);
    cout << fv << endl;

    shared_ptr<Field> f2 = make_shared<Field>(*f1);
    fv.setField(f2);
    fv.showInfo(cout);
    cout << fv << endl;

    shared_ptr<Field> f3 = FieldBuilder().setSize(Vec2D(2, 3)).setType(FieldBuilder::Type::DEFAULT).build();
    fv.setField(f3);
    fv.showInfo(cout);
    cout << fv << endl;

    *f3 = *f1;
    fv.showInfo(cout);
    cout << fv << endl;
}
