#include "Game.h"

void Game::field_analysis() {
    for (int i = 0; i < fld->getSize().x; ++i) {
        for (int j = 0; j < fld->getSize().y; ++j) {
            Vec2D p(i, j);
            if (instanceof<Exit>(&fld->get(p)))
                exit = p;
            else if (instanceof<Entrance>(&fld->get(p)))
                entrance = p;
            else if (instanceof<Cell>(&fld->get(p)))
                tiles.push_back(p);
            else walls.push_back(p);
        }
    }
}

void Game::entities_analysis() {
    for (int i = 0; i < fld->getSize().x; ++i) {
        for (int j = 0; j < fld->getSize().y; ++j) {
            Vec2D p(i, j);
            if (fld->get(p).getEntity() != nullptr) {
                if (instanceof<Enemy>(fld->get(p).getEntity().get())) {
                    enemies.push_back(fld->get(p).getEntity());
                    std::shared_ptr<EnemyController> ctrl
                            = std::make_shared<EnemyController>(fld, fld->get(p).getEntity(), p, false);
                    enemyinfo.push_back(ctrl);
                    bots.push_back(
                            std::make_shared<Bot>(
                                    fld, pc,
                                    ctrl,
                                    bl
                            )
                    );
                } else if (instanceof<Item>(fld->get(p).getEntity().get())) {
                    std::shared_ptr<ItemController> ctrl
                            = std::make_shared<ItemController>(fld, fld->get(p).getEntity(), p, false);
                    items.push_back(fld->get(p).getEntity());
                    iteminfo.push_back(ctrl);
                }
            }
        }
    }
}
