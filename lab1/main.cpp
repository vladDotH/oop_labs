#include <iostream>
#include <utility>
#include "field/Field.h"

using namespace std;

int main() {
    Field f1(4, 4);
    cout << f1;

    Field f2(3, 3);
    cout << f2;
    f2 = std::move(f1);
    cout << f2;
    cout << f1;
}
