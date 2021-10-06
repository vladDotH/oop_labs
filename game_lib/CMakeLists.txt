cmake_minimum_required(VERSION 3.15)
project(game_lib)
set(CMAKE_CXX_STANDARD 17)

include_directories(core entities field viewers field/cells game)

set(LIB_SRC
        core/Vec2D.h core/Vec2D.cpp

        entities/Entities_Declarations.h
        entities/Entity.h
        entities/Creature.h entities/enemies/Enemy.h entities/items/Item.h entities/Player.h
        entities/EntityAbstractFactory.h entities/CreatureFactory.h entities/items/ItemFactory.h
        entities/items/HealerFactory.h entities/items/ArmorFactory.h entities/items/WeaponFactory.h
        entities/enemies/LightFactory.h entities/enemies/MediumFactory.h entities/enemies/HeavyFactory.h

        field/cells/AbstractCell.h
        field/cells/Wall.h field/cells/Cell.h field/cells/Entrance.h field/cells/Exit.h
        field/Field.cpp field/Field.h
        field/FieldBuilder.h field/FieldBuilder.cpp

        viewers/Viewers_Declarations.h
        viewers/FieldView.h
        viewers/ConsoleFieldView.h viewers/ConsoleFieldView.cpp
        viewers/CellView.h viewers/CellView.cpp

        game/Game.h game/Game.cpp
        )

add_library(game_lib STATIC ${LIB_SRC})

message("Game library built")
