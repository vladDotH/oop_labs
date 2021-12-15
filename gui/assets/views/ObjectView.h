#ifndef OBJECTVIEW_H
#define OBJECTVIEW_H

#include <QObject>
#include <QGraphicsItem>
#include <QPainter>

class ObjectView : public QObject, public QGraphicsItem {
Q_OBJECT
protected:
    QSharedPointer<QImage> img;
    int size;

public:
    ObjectView(QSharedPointer<QImage> img, int size, QObject *parent = nullptr)
            : QObject(parent), QGraphicsItem(), img(img), size(size) {
    }

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *) override {
        painter->drawImage(boundingRect(), *img);
    }

    QRectF boundingRect() const override {
        return QRectF(-size, -size, size, size);
    }
};

#endif //OBJECTVIEW_H
