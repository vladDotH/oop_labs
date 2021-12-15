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
#include "assets/views/EntityView.h"
#include "assets/views/CellView.h"


class Window : public QMainWindow {
protected:
    QGraphicsScene scene;
    QGraphicsView gview;
    QVector<EntityView> ev;
    QVector<CellView> cv;
    std::shared_ptr<Game> game;

    QMutex gameMx;
    QTimer updTimer;

public slots:

    void spin() {
        gameMx.lock();
        this->game->spin();
        print();
        if (game->fail()) {
            updTimer.stop();
            QMessageBox::warning(this, "Информация", "Игра проиграна");
            close();
        }
        gameMx.unlock();
    }

public:
    void print() {
        scene.clear();
        for (int i = 0; i < game->getFld()->getSize().y; ++i) {
            for (int j = 0; j < game->getFld()->getSize().x; ++j) {
                QGraphicsItem *item = new CellView(game->getFld()->get(Vec2D(j, i)), Assets::get().SPRITE_SIZE);
                item->setPos(Assets::get().SPRITE_SIZE * j, Assets::get().SPRITE_SIZE * i);
                scene.addItem(item);
                if (game->getFld()->get(Vec2D(j, i)).getEntity()) {
                    item = new EntityView(game->getFld()->get(Vec2D(j, i)).getEntity(), Assets::get().SPRITE_SIZE);
                    item->setPos(Assets::get().SPRITE_SIZE * j, Assets::get().SPRITE_SIZE * i);
                    item->setZValue(1);
                    scene.addItem(item);
                }
            }
        }
    }

    Window(std::shared_ptr<Game> game) : QMainWindow(nullptr), scene(this), game(game) {
        setWindowTitle("gui game");
        setCentralWidget(&gview);
        gview.setScene(&scene);
        print();

        updTimer.setInterval(Assets::get().GAME_FREQ);
        connect(&updTimer, &QTimer::timeout, this, &Window::spin);
        updTimer.start();

        gview.show();
    }

protected:
    void keyPressEvent(QKeyEvent *event) override {
        std::cerr << game->getPc().get()->getObj().lock()->getHp() << ' '
                  << game->getPc().get()->getObj().lock()->getArmor() << ' '
                  << game->getPc().get()->getObj().lock()->getDmg() << '\n';
        gameMx.lock();
        if (event->key() == Assets::get().keys.UP) {
            game->movePlayer(up);
        } else if (event->key() == Assets::get().keys.LEFT) {
            game->movePlayer(left);
        } else if (event->key() == Assets::get().keys.DOWN) {
            game->movePlayer(down);
        } else if (event->key() == Assets::get().keys.RIGHT) {
            game->movePlayer(right);
        }
        print();
        if (game->end()) {
            updTimer.stop();
            QMessageBox::information(this, "Информация", "Игра пройдена");
            close();
        }
        gameMx.unlock();
    }
};


#endif //WINDOW_H
