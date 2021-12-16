#include "Window.h"

void Window::print() {
    scene.clear();
    for (int i = 0; i < game->getFld()->getSize().y; ++i) {
        for (int j = 0; j < game->getFld()->getSize().x; ++j) {
            QGraphicsItem *item = new CellView(game->getFld()->get(Vec2D(j, i)), Assets::get().sprite_size);
            item->setPos(Assets::get().sprite_size * j, Assets::get().sprite_size * i);
            scene.addItem(item);
            if (game->getFld()->get(Vec2D(j, i)).getEntity()) {
                item = new EntityView(game->getFld()->get(Vec2D(j, i)).getEntity(), Assets::get().sprite_size);
                item->setPos(Assets::get().sprite_size * j, Assets::get().sprite_size * i);
                item->setZValue(1);
                scene.addItem(item);
            }
        }
    }
    statusBar()->showMessage(QString("hp:%1 dmg:%2 armor:%3")
                                     .arg(game->getPc()->getObj().lock()->getHp())
                                     .arg(game->getPc()->getObj().lock()->getDmg())
                                     .arg(game->getPc()->getObj().lock()->getArmor()));
}

void Window::spin() {
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

Window::Window(std::shared_ptr<Game> game) : QMainWindow(nullptr), scene(this), game(game) {
    setWindowTitle("gui game");
    setCentralWidget(&gview);
    gview.setScene(&scene);
    print();

    updTimer.setInterval(Assets::get().game_freq);
    connect(&updTimer, &QTimer::timeout, this, &Window::spin);
    updTimer.start();

    gview.show();
}

void Window::keyPressEvent(QKeyEvent *event) {
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
