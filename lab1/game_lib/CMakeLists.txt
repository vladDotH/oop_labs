cmake_minimum_required(VERSION 3.15)
project(game_lib)
set(CMAKE_CXX_STANDARD 17)

include_directories(core entities field viewers field/cells)

set(LIB_SRC
        core/Vec2D.h core/Vec2D.cpp
        entities/Entity.h
        field/cells/AbstractCell.h
        field/cells/Wall.h field/cells/Cell.h field/cells/Entrance.h field/cells/Exit.h
        field/Field.cpp field/Field.h
        field/FieldBuilder.h field/FieldBuilder.cpp
        viewers/FieldView.h viewers/ConsoleFieldView.h viewers/Viewers_Declarations.h
        viewers/CellView.h
        )

add_library(game_lib STATIC ${LIB_SRC})

message("Game library built")
