#ifndef CELLVIEW_H
#define CELLVIEW_H

#include "../field/cells/Cell.h"
#include "../field/cells/Wall.h"
#include "../field/cells/Exit.h"
#include "../field/cells/Entrance.h"

class CellView {
    constexpr static const char CELLS_CHAR[] = {' ', '#', '@', '$'};
public:
    static CELLS_ID getCellID(AbstractCell *c) {
        if (dynamic_cast<Wall *>(c))
            return WALL;
        else if (dynamic_cast<Exit *>(c))
            return EXIT;
        else if (dynamic_cast<Entrance *>(c))
            return ENTRANCE;
        else
            return CELL;
    }

    static char getChar(CELLS_ID id) {
        return CELLS_CHAR[id];
    }
};

#endif //CELLVIEW_H
