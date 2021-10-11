#include "EntityView.h"

EntityView::EntityView() : ConsoleObjectViewer<Entity>(
        {
                {typeid(Enemy).hash_code(),  'e'},
                {typeid(Player).hash_code(), 'p'},
                {typeid(Item).hash_code(),   'i'}
        }
) {}

char EntityView::getChar(const Entity &c) {
    return chars.at(typeid(c).hash_code());
}
