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
#include <QMenuBar>
#include <QFileDialog>
#include <QJsonDocument>
#include "entities/creatures/enemies/EnemyFactory.h"
#include "entities/items/ItemFactory.h"
#include "StartGameDialog.h"
#include "serialization/GameSnapshot.h"
#include "assets/views/EntityView.h"
#include "assets/views/CellView.h"


class Window : public QMainWindow {
protected:
    QGraphicsScene scene;
    QGraphicsView gview;
    std::shared_ptr<Game> game = nullptr;
    GameSnapshot gs;
    StartGameDialog *sgd;

    QMutex gameMx;
    QTimer updTimer;

    void init();

    void start();

    void stop();

public slots:

    void spin();

    void newGame();

    void initNewGame(Vec2D v, int collect, int kill, int range,
                     int heals, int armors, int weapons, int lights, int mediums, int heavies);

    void save();

    void load();

public:
    void print();

    Window(std::shared_ptr<Game> game);

    Window();

protected:
    void keyPressEvent(QKeyEvent *event) override;
};


#endif //WINDOW_H
