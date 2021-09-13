#include <iostream>
#include "field/Field.h"

using namespace std;

int main() {
    Field f1(5, 5);
    cout << f1 << endl;

    Field f2(std::move(f1));
    cout << f1 << endl;
    cout << f2 << endl;

    Field f3(2, 2);
    f3 = std::move(f2);
    cout << f1 << endl;
    cout << f2 << endl;
    cout << f3 << endl;
}
