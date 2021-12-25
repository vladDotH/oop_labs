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
    if (!game->getPc()->expired())
        statusBar()->showMessage(QString("hp:%1 dmg:%2 armor:%3")
                                         .arg(game->getPc()->getObj().lock()->getHp())
                                         .arg(game->getPc()->getObj().lock()->getDmg())
                                         .arg(game->getPc()->getObj().lock()->getArmor()));
}


void Window::start() {
    updTimer.start();
}

void Window::stop() {
    updTimer.stop();
}

void Window::spin() {
    gameMx.lock();
    this->game->spin();
    if (game->fail()) {
        stop();
        QMessageBox::warning(this, "Информация", "Игра проиграна");
        close();
        gameMx.unlock();
        return;
    }
    print();
    gameMx.unlock();
}

void Window::init() {
    setWindowTitle("gui game");
    setCentralWidget(&gview);
    gview.setScene(&scene);
    updTimer.setInterval(Assets::get().game_freq);
    connect(&updTimer, &QTimer::timeout, this, &Window::spin);
    gview.show();

    menuBar()->addAction("Новая игра", this, &Window::newGame);
    menuBar()->addAction("Сохранить", this, &Window::save);
    menuBar()->addAction("Загрузить", this, &Window::load);
}

Window::Window() {
    init();
}


Window::Window(std::shared_ptr<Game> game) : QMainWindow(nullptr), scene(this), game(game) {
    init();
    print();
    start();
}

void Window::keyPressEvent(QKeyEvent *event) {
    gameMx.lock();
    if (!game->fail()) {
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
    }
    gameMx.unlock();
}

void Window::newGame() {
    stop();
    sgd = new StartGameDialog(this, windowFlags());
    sgd->open();
    connect(sgd, &StartGameDialog::generate, this, &Window::initNewGame);
}

void Window::load() {
    stop();
    std::shared_ptr<Game> newGame;
    QString file = QFileDialog::getOpenFileName(this, "загрузить");

    if (!file.isEmpty()) {
        try {
            QFile jsonFile(file);
            jsonFile.open(QFile::ReadOnly);
            newGame = gs.deserialize(QJsonDocument::fromJson(jsonFile.readAll()).object());

        } catch (std::exception &e) {
            QMessageBox::warning(this, "Ошибка загрузки",
                                 QString(e.what()), "OK");
            return;
        }
    }

    game = newGame;
    start();
}

void Window::save() {
    if (!game) {
        QMessageBox::warning(this, "Ошибка сохранения",
                             QString("Нет активной игры"), "OK");
        return;
    }
    stop();
    QString file = QFileDialog::getSaveFileName(this, "сохранить");
    if (!file.isEmpty()) {
        try {
            QFile jsonFile(file);
            jsonFile.open(QFile::WriteOnly);
            QJsonDocument doc(gs.serialize(game));
            jsonFile.write(doc.toJson());
        } catch (std::exception &e) {
            QMessageBox::warning(this, "Ошибка сохранения",
                                 QString(e.what()), "OK");
        }
    }
}

void Window::initNewGame(Vec2D v, int collect, int kill, int range, int heals, int armors, int weapons, int lights,
                         int mediums, int heavies) {
    std::shared_ptr<Game> newGame;
    try {
        newGame = std::make_shared<Game>(
                FieldBuilder().setSize(v).setType(FieldBuilder::Type::DEFAULT).build(),
                std::make_shared<Predator>(range), std::make_shared<ObjectsCounter>(collect),
                std::make_shared<ObjectsCounter>(kill),
                Generator(std::make_shared<LightFactory>(), lights),
                Generator(std::make_shared<MediumFactory>(), mediums),
                Generator(std::make_shared<HeavyFactory>(), heavies),
                Generator(std::make_shared<HealerFactory>(), heals),
                Generator(std::make_shared<ArmorFactory>(), armors),
                Generator(std::make_shared<WeaponFactory>(), weapons)
        );
    } catch (std::exception &e) {
        QMessageBox::warning(this, "Ошибка генерации",
                             QString(e.what()), "OK");
        sgd->reject();
        if (game != nullptr)
            start();
        return;
    }

    game = newGame;
    sgd->done(0);
    start();
}

