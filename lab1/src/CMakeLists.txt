cmake_minimum_required(VERSION 3.15)
project(game_lib)
set(CMAKE_CXX_STANDARD 17)

include_directories(entities field viewers)

set(LIB_SRC
        entities/Entity.h
        field/cells/Cell.cpp field/cells/Cell.h field/Field.cpp field/Field.h
        viewers/FieldView.h viewers/ConsoleFieldView.h viewers/ConsoleFieldView.cpp viewers/Viewers_Declarations.h field/cells/Wall.cpp field/cells/Wall.h field/cells/RegularCell.cpp field/cells/RegularCell.h field/cells/Entrance.cpp field/cells/Entrance.h field/cells/Exit.cpp field/cells/Exit.h)

add_library(game_lib STATIC ${LIB_SRC})

message("Game library built")
