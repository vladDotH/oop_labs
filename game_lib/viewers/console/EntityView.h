#ifndef ENTITYVIEW_H
#define ENTITYVIEW_H

#include <map>
#include "ConsoleObjectView.h"
#include "../../entities/Entity.h"
#include "../../entities/creatures/Creature.h"
#include "../../entities/creatures/Player.h"
#include "../../entities/creatures/enemies/Enemy.h"
#include "../../entities/items/Item.h"

class EntityView : ConsoleObjectView<Entity> {
public:
    EntityView();

    char getChar(const Entity &c);
};


#endif //ENTITYVIEW_H
