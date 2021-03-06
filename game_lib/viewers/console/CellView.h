#ifndef CELLVIEW_H
#define CELLVIEW_H

#include "../../field/cells/Cell.h"
#include "../../field/cells/Wall.h"
#include "../../field/cells/Exit.h"
#include "../../field/cells/Entrance.h"
#include "ConsoleObjectView.h"
#include <map>
#include <memory>

class CellView : public ConsoleObjectView<AbstractCell> {
public:
    CellView();

    char getChar(const AbstractCell &c) override;
};


#endif //CELLVIEW_H
