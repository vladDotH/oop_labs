#ifndef GAME_H
#define GAME_H

#include "rules/init/Generator.h"
#include "rules/end/Exterminator.h"
#include "rules/end/Collector.h"
#include "field/FieldBuilder.h"
#include <vector>

template<class ItemsRule, class EnemiesRule>
class Game {
public:
    ItemsRule rule1;
    EnemiesRule rule2;
    std::shared_ptr<Field> f;
    std::shared_ptr<PlayerController> p;
    Vec2D entrance, exit;
    std::vector<std::weak_ptr<Item>> items;
    std::vector<std::weak_ptr<Enemy>> enemies;

    template<typename Base, typename T>
    static inline bool instanceof(const T&) {
        return std::is_base_of<Base, T>::value;
    }

public:
    template<class ... Generators>
    Game(std::shared_ptr<Field> f, Generators ... gens) : f(f) {
        if constexpr (sizeof...(gens))
            generators_unpack(gens...);
        analysis();
        rule1.init(f, p, exit, items);
        rule2.init(f, p, exit, enemies);
    }

    void analysis() {
        for (int i = 0; i < f->getSize().x; ++i) {
            for (int j = 0; j < f->getSize().y; ++j) {
                Vec2D p(i, j);
                if (instanceof<Exit>(f->get(p)))
                    exit = p;
                if (instanceof<Entrance>(f->get(p)))
                    entrance = p;
                if (instanceof<Enemy>(*f->get(p).getEntity()))
                    enemies.push_back(std::dynamic_pointer_cast<Enemy>(f->get(p).getEntity()));
                if (instanceof<Item>(*f->get(p).getEntity()))
                    items.push_back(std::dynamic_pointer_cast<Item>(f->get(p).getEntity()));
            }
        }
    }

    template<class G, class ... Generators>
    void generators_unpack(G gen, Generators ... gens) {
        gen.generate(f);
        if constexpr (sizeof...(gens))
            generators_unpack(gens...);
    }
};


#endif //GAME_H
