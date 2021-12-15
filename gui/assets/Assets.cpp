#include "Assets.h"

Assets *Assets::obj = nullptr;

void Assets::load() {
    images.floor = QSharedPointer<QImage>(new QImage(Assets::get().names.floor));
    images.wall = QSharedPointer<QImage>(new QImage(Assets::get().names.wall));
    images.entrance = QSharedPointer<QImage>(new QImage(Assets::get().names.entrance));
    images.exit = QSharedPointer<QImage>(new QImage(Assets::get().names.exit));
    images.player = QSharedPointer<QImage>(new QImage(Assets::get().names.player));
    images.light = QSharedPointer<QImage>(new QImage(Assets::get().names.light));
    images.medium = QSharedPointer<QImage>(new QImage(Assets::get().names.medium));
    images.heavy = QSharedPointer<QImage>(new QImage(Assets::get().names.heavy));
    images.heal = QSharedPointer<QImage>(new QImage(Assets::get().names.heal));
    images.armor = QSharedPointer<QImage>(new QImage(Assets::get().names.armor));
    images.weapon = QSharedPointer<QImage>(new QImage(Assets::get().names.weapon));
}
