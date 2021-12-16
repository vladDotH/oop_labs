#ifndef WINDOW_H
#define WINDOW_H

#include <memory>
#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QKeyEvent>
#include <Game.h>
#include <QTimer>
#include <QMutex>
#include <QMessageBox>
#include <QStatusBar>
#include "assets/views/EntityView.h"
#include "assets/views/CellView.h"


class Window : public QMainWindow {
protected:
    QGraphicsScene scene;
    QGraphicsView gview;
    std::shared_ptr<Game> game;

    QMutex gameMx;
    QTimer updTimer;

public slots:

    void spin();

public:
    void print();

    Window(std::shared_ptr<Game> game);

protected:
    void keyPressEvent(QKeyEvent *event) override;
};


#endif //WINDOW_H
