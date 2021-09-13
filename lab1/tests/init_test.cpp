#include <iostream>
#include "field/Field.h"

using namespace std;

int main() {
    Field f1(5, 5);
    cout << f1 << endl;

    Field f2(3, 10);
    cout << f2 << endl;

    Field f3(10, 3);
    cout << f3 << endl;
}
