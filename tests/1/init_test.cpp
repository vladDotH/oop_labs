#include <iostream>
#include <viewers/FieldView.h>
#include <viewers/ConsoleFieldView.h>
#include <field/cells/Wall.h>
#include "field/Field.h"
#include "field/FieldBuilder.h"
#include <memory>

using namespace std;

int main() {
    Field f1 = FieldBuilder(Vec2D(5, 5), FieldBuilder::DEFAULT).build();
    ConsoleFieldView fv(&f1);
    cout << fv << endl;

    Field f2 = FieldBuilder(Vec2D(2, 3), FieldBuilder::DEFAULT).build();
    fv.setField(&f2);
    cout << fv << endl;

    Field f3 = FieldBuilder(Vec2D(10, 6), FieldBuilder::BOX).build();
    fv.setField(&f3);
    cout << fv << endl;

    cout << CellView::getChar(f1[{4, 4}]) << endl;
}
