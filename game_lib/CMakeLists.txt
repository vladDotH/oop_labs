cmake_minimum_required(VERSION 3.15)
project(game_lib)
set(CMAKE_CXX_STANDARD 17)

include_directories(core entities field viewers viewers/console field/cells controllers logging logging/loggers ../game)

set(LIB_SRC
        core/Vec2D.h core/Vec2D.cpp
        core/Cloneable.h

        entities/entities_declarations.h
        entities/Entity.h
        entities/creatures/Creature.h entities/creatures/enemies/Enemy.h entities/items/Item.h entities/creatures/Player.h
        entities/EntityFactory.h entities/creatures/CreatureFactory.h entities/items/ItemFactory.h entities/creatures/enemies/EnemyFactory.h

        field/cells/AbstractCell.h
        field/cells/Wall.h field/cells/Cell.h field/cells/Entrance.h field/cells/Exit.h
        field/Field.cpp field/Field.h
        field/FieldBuilder.h field/FieldBuilder.cpp

        viewers/viewers_declarations.h
        viewers/FieldView.h
        viewers/console/EntityView.cpp viewers/console/EntityView.h
        viewers/console/ConsoleObjectView.h
        viewers/console/ConsoleFieldView.h viewers/console/ConsoleFieldView.cpp
        viewers/console/CellView.h viewers/console/CellView.cpp

        controllers/BaseController.h controllers/EnemyController.h controllers/PlayerController.h

        logging/Level.cpp logging/Level.h
        logging/Log.h logging/loggers/Logger.h logging/loggers/ConsoleLogger.h logging/loggers/FileLogger.h
        logging/Loggable.h logging/LogTimer.h logging/LogTimer.cpp
        logging/formats/Format.h logging/formats/TagFormat.h logging/formats/TimeFormat.h logging/formats/EmptyFormat.h)

add_library(game_lib STATIC ${LIB_SRC})

message("Game library built")
