cmake_minimum_required(VERSION 3.15)
project(game_lib)
set(CMAKE_CXX_STANDARD 17)

include_directories(core entities field viewers viewers/console field/cells controllers ../game)

set(LIB_SRC
        core/Vec2D.h core/Vec2D.cpp
        core/Cloneable.h

        entities/Entities_Declarations.h
        entities/Entity.h
        entities/creatures/Creature.h entities/creatures/enemies/Enemy.h entities/items/Item.h entities/creatures/Player.h
        entities/EntityFactory.h entities/creatures/CreatureFactory.h entities/items/ItemFactory.h entities/creatures/enemies/EnemyFactory.h

        field/cells/AbstractCell.h
        field/cells/Wall.h field/cells/Cell.h field/cells/Entrance.h field/cells/Exit.h
        field/Field.cpp field/Field.h
        field/FieldBuilder.h field/FieldBuilder.cpp

        viewers/Viewers_Declarations.h
        viewers/FieldView.h
        viewers/console/EntityView.cpp viewers/console/EntityView.h
        viewers/console/ConsoleObjectView.h
        viewers/console/ConsoleFieldView.h viewers/console/ConsoleFieldView.cpp
        viewers/console/CellView.h viewers/console/CellView.cpp

        controllers/BaseController.h controllers/EnemyController.h controllers/PlayerController.h

        loggers/Log.h loggers/Logger.h loggers/ConsoleLogger.h loggers/FileLogger.h
        )

add_library(game_lib STATIC ${LIB_SRC})

message("Game library built")
