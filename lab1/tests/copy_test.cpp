#include <iostream>
#include "field/Field.h"

using namespace std;

int main() {
    Field f1(5, 5);
    cout << f1 << endl;

    Field f2(f1);
    cout << f2 << endl;

    Field f3(2, 2);
    cout << f3 << endl;

    f3 = f1;
    cout << f3 << endl;
}
