#include "EntityView.h"

const std::map<size_t, QSharedPointer<QImage>> EntityView::objects = {
        {typeid(Player).hash_code(), Assets::get().images.player},
        {typeid(Light).hash_code(),  Assets::get().images.light},
        {typeid(Medium).hash_code(), Assets::get().images.medium},
        {typeid(Heavy).hash_code(),  Assets::get().images.heavy},
        {typeid(Healer).hash_code(), Assets::get().images.heal},
        {typeid(Weapon).hash_code(), Assets::get().images.weapon},
        {typeid(Armor).hash_code(),  Assets::get().images.armor}
};

EntityView::EntityView(std::shared_ptr<Entity> obj, int size, QObject *parent)
        : ObjectView(objects.at(typeid(*obj).hash_code()), size, parent) {
}
