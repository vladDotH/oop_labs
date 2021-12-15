#include "CellView.h"

const std::map<size_t, QSharedPointer<QImage>> CellView::objects = {
        {typeid(Cell).hash_code(),     Assets::get().images.floor},
        {typeid(Wall).hash_code(),     Assets::get().images.wall},
        {typeid(Entrance).hash_code(), Assets::get().images.entrance},
        {typeid(Exit).hash_code(),     Assets::get().images.exit}};

CellView::CellView(AbstractCell &cell, int size, QObject *parent)
        : ObjectView(objects.at(typeid(cell).hash_code()), size, parent) {
}
