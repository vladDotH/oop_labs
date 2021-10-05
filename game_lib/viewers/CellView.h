#ifndef CELLVIEW_H
#define CELLVIEW_H

#include "../field/cells/Cell.h"
#include "../field/cells/Wall.h"
#include "../field/cells/Exit.h"
#include "../field/cells/Entrance.h"
#include <map>

class CellView {
    static const char CELLS_CHAR[];
    static const std::map<size_t, char> chars;
public:
    static char getChar(AbstractCell *p);
    static char getChar(const AbstractCell& c);
};

#endif //CELLVIEW_H
