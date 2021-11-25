#ifndef GAME_H
#define GAME_H

#include "rules/init/Generator.h"
#include "rules/end/Exterminator.h"
#include "rules/end/Collector.h"
#include "field/FieldBuilder.h"
#include <vector>
#include "bots/Bot.h"
#include "bots/logic/Predator.h"

template<class ItemsRule, class EnemiesRule, class BotsLogic>
class Game : public Loggable {
protected:
    ItemsRule rule1;
    EnemiesRule rule2;
    std::shared_ptr<Field> fld;
    std::shared_ptr<BotsLogic> bl;
    std::shared_ptr<PlayerController> pc;
    Vec2D entrance, exit;
    std::vector<std::weak_ptr<Item>> items;
    std::vector<std::weak_ptr<Enemy>> enemies;
    std::vector<std::shared_ptr<Bot<BotsLogic>>> bots;

private:
    template<class G, class ... Generators>
    void generators_unpack(G gen, Generators ... gens) {
        gen.generate(fld);
        if constexpr (sizeof...(gens))
            generators_unpack(gens...);
    }

    void field_analysis() {
        for (int i = 0; i < fld->getSize().x; ++i) {
            for (int j = 0; j < fld->getSize().y; ++j) {
                Vec2D p(i, j);
                if (typeid(fld->get(p)).hash_code() == typeid(Exit &).hash_code())
                    exit = p;
                if (typeid(fld->get(p)).hash_code() == typeid(Entrance &).hash_code())
                    entrance = p;
            }
        }
    }

    void entities_analysis() {
        for (int i = 0; i < fld->getSize().x; ++i) {
            for (int j = 0; j < fld->getSize().y; ++j) {
                Vec2D p(i, j);
                if (fld->get(p).getEntity() != nullptr) {
                    if (typeid(*fld->get(p).getEntity()).hash_code() == typeid(Enemy).hash_code()) {
                        enemies.push_back(std::dynamic_pointer_cast<Enemy>(fld->get(p).getEntity()));
                        bots.push_back(
                                std::make_shared<Bot<BotsLogic>>(
                                        fld, pc,
                                        std::make_shared<EnemyController>(fld, fld->get(p).getEntity(), p, false),
                                        bl
                                )
                        );
                    }
                    if (typeid(*fld->get(p).getEntity()).hash_code() == typeid(Item).hash_code())
                        items.push_back(std::dynamic_pointer_cast<Item>(fld->get(p).getEntity()));
                }
            }
        }
    }

public:
    template<class ... Generators>
    Game(std::shared_ptr<Field> f, std::shared_ptr<BotsLogic> bl, Generators ... gens) : fld(f), bl(bl) {
        field_analysis();
        std::shared_ptr<Player> plr = std::make_shared<Player>();
        pc = std::make_shared<PlayerController>(fld, plr, entrance);
        if constexpr (sizeof...(gens))
            generators_unpack(gens...);
        rule1.init(f, pc, exit, items);
        rule2.init(f, pc, exit, enemies);
        entities_analysis();
    }

    bool end() {
        return rule1.end() && rule2.end();
    }

    void spin() {
        for (auto b: bots)
            b->spin();
    }

    void movePlayer(Vec2D p) {
        pc->move(p);
    }

    void movePlayerAbs(Vec2D p) {
        pc->moveAbs(p);
    }

    std::shared_ptr<Field> getFld() const {
        return fld;
    }
};


#endif //GAME_H
