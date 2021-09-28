#include <iostream>
#include <viewers/ConsoleFieldView.h>
#include <field/FieldBuilder.h>
#include "field/Field.h"

using namespace std;

int main() {
    ConsoleFieldView fv;
    Field f1 = FieldBuilder::default_generation(Vec2D(5, 5));
    fv.setField(&f1);
    cout << fv << endl;

    Field f2(std::move(f1));
    cout << fv << endl;
    fv.setField(&f2);
    cout << fv << endl;

    Field f3 = FieldBuilder::default_generation(Vec2D(3, 3));
    f3 = std::move(f2);
    fv.setField(&f1);
    cout << fv << endl;
    fv.setField(&f2);
    cout << fv << endl;
    fv.setField(&f3);
    cout << fv << endl;
}
