#include <iostream>
#include <field/FieldBuilder.h>
#include <viewers/ConsoleFieldView.h>
#include "field/Field.h"

using namespace std;

int main() {
    ConsoleFieldView fv;
    Field f1 = FieldBuilder(Vec2D(5, 5), FieldBuilder::BOX).build();
    fv.setField(&f1);
    cout << fv << endl;

    Field f2(f1);
    fv.setField(&f2);
    cout << fv << endl;

    Field f3 = FieldBuilder(Vec2D(2, 3), FieldBuilder::DEFAULT).build();
    fv.setField(&f3);
    cout << fv << endl;

    f3 = f1;
    cout << fv << endl;
}
