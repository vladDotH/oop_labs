#ifndef GAME_H
#define GAME_H

#include "rules/init/Generator.h"
#include "rules/end/ObjectsCounter.h"
#include "field/FieldBuilder.h"
#include "entities/items/Item.h"
#include "controllers/ItemController.h"
#include <vector>
#include <core/InstanceOf.h>
#include "bots/Bot.h"
#include "bots/logic/Predator.h"

class Game : public Loggable {
protected:
    std::shared_ptr<ObjectsCounter> irule, erule;
    std::shared_ptr<Field> fld;
    std::shared_ptr<BotLogic> bl;
    std::shared_ptr<PlayerController> pc;
    std::vector<std::weak_ptr<Entity>> items;
    std::vector<std::weak_ptr<Entity>> enemies;
    std::vector<std::shared_ptr<Bot>> bots;

    //game information
    Vec2D entrance, exit;
    std::vector<Vec2D> tiles, walls;
    std::vector<std::shared_ptr<ItemController>> iteminfo;
    std::vector<std::shared_ptr<EnemyController>> enemyinfo;

private:
    template<class G, class ... Generators>
    void generators_unpack(G gen, Generators ... gens) {
        gen.generate(fld);
        if constexpr (sizeof...(gens) != 0)
            generators_unpack(gens...);
    }

    void field_analysis();

    void entities_analysis();

public:
    template<class ... Args>
    Game(std::shared_ptr<Field> f, std::shared_ptr<BotLogic> bl, std::shared_ptr<ObjectsCounter> irule,
         std::shared_ptr<ObjectsCounter> erule, Args ... generators) : fld(f), bl(bl), irule(irule), erule(erule) {
        field_analysis();
        std::shared_ptr<Player> plr = std::make_shared<Player>();
        pc = std::make_shared<PlayerController>(fld, plr, entrance);
        if constexpr (sizeof...(generators) != 0)
            generators_unpack(generators...);
        entities_analysis();
        irule->init(f, pc, exit, items);
        erule->init(f, pc, exit, enemies);
    }

    bool end() {
        return irule->end() && erule->end();
    }

    bool fail() {
        return pc->expired();
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

    const std::vector<Vec2D> &getTiles() const {
        return tiles;
    }

    const std::vector<Vec2D> &getWalls() const {
        return walls;
    }

    const std::vector<std::shared_ptr<ItemController>> &getIteminfo() const {
        return iteminfo;
    }

    const std::vector<std::shared_ptr<EnemyController>> &getEnemyinfo() const {
        return enemyinfo;
    }

    std::shared_ptr<PlayerController> getPc() {
        return pc;
    };
};


#endif //GAME_H
