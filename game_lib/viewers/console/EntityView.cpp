#include "EntityView.h"

EntityView::EntityView() : ConsoleObjectView<Entity>(
        {
                {typeid(Player).hash_code(), 'p'},
                {typeid(Light).hash_code(),  'L'},
                {typeid(Medium).hash_code(),  'M'},
                {typeid(Heavy).hash_code(),  'H'},
                {typeid(Healer).hash_code(),   'h'},
                {typeid(Weapon).hash_code(),   'w'},
                {typeid(Armor).hash_code(),   'a'}
        }
) {}

char EntityView::getChar(const Entity &c) {
    return chars.at(typeid(c).hash_code());
}
