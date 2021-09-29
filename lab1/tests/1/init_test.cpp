#include <iostream>
#include <viewers/FieldView.h>
#include <viewers/ConsoleFieldView.h>
#include <field/cells/Wall.h>
#include "field/Field.h"
#include "field/FieldBuilder.h"
#include <memory>

using namespace std;

int main() {
    Field f1 = FieldBuilder::default_generation(Vec2D(5, 5));
    ConsoleFieldView fv(&f1);
    cout << fv << endl;

    Field f2 = FieldBuilder::default_generation(Vec2D(2, 3));
    fv.setField(&f2);
    cout << fv << endl;

    Field f3 = FieldBuilder::box_generation(Vec2D(10, 6));
    fv.setField(&f3);
    cout << fv << endl;

    cout << f1[{4, 4}].getID() << endl;
}
