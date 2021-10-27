#include <iostream>
#include <viewers/FieldView.h>
#include <viewers/console/ConsoleFieldView.h>
#include <field/cells/Wall.h>
#include "field/Field.h"
#include "field/FieldBuilder.h"
#include <memory>

using namespace std;

int main() {
    shared_ptr<Field> f1 = FieldBuilder().setSize(Vec2D(5, 5)).setType(FieldBuilder::Type::BOX).build();
    ConsoleFieldView fv(f1);
    fv.showInfo(cout);
    cout << fv << endl;

    shared_ptr<Field> f2 = FieldBuilder().setSize(Vec2D(2, 3)).setType(FieldBuilder::Type::DEFAULT).build();
    fv.setField(f2);
    fv.showInfo(cout);
    cout << fv << endl;

    shared_ptr<Field> f3 = FieldBuilder().setSize(Vec2D(10, 6)).setType(FieldBuilder::Type::BOX).build();
    fv.setField(f3);
    fv.showInfo(cout);
    cout << fv << endl;

    cout << CellView().getChar(f1->get({4, 4})) << endl;
}
