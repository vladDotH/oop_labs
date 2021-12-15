#ifndef ENTITYVIEW_H
#define ENTITYVIEW_H

#include <QObject>
#include <QGraphicsItem>
#include <QPainter>

#include "entities/Entity.h"
#include "entities/items/Item.h"
#include "entities/creatures/enemies/Enemy.h"
#include "entities/creatures/Player.h"
#include "ObjectView.h"
#include "assets/Assets.h"

class EntityView : public ObjectView {
private:
    static const std::map<size_t, QSharedPointer<QImage>> objects;

public:
    EntityView(std::shared_ptr<Entity> obj, int size, QObject *parent = nullptr);
};

#endif //ENTITYVIEW_H
