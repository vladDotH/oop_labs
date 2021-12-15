#ifndef CELLVIEW_H
#define CELLVIEW_H

#include <QObject>
#include <QGraphicsItem>
#include <QPainter>

#include "ObjectView.h"
#include "field/cells/AbstractCell.h"
#include "field/cells/Cell.h"
#include "field/cells/Wall.h"
#include "field/cells/Entrance.h"
#include "field/cells/Exit.h"
#include "assets/Assets.h"

class CellView : public ObjectView {
private:
    static const std::map<size_t, QSharedPointer<QImage>> objects;

public:
    CellView(AbstractCell &cell, int size, QObject *parent = nullptr);
};


#endif // CELLVIEW_H
