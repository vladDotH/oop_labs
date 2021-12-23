cmake_minimum_required(VERSION 3.15)
project(game)
set(CMAKE_CXX_STANDARD 20)

include_directories(../game_lib ../game)

set(LIB_SRC
        bots/Bot.h bots/logic/BotLogic.h bots/logic/Predator.h
        rules/end/Rule.h rules/end/ObjectsCounter.h
        rules/init/Generator.h
        Game.cpp Game.h serialization/FieldSnapshot.h serialization/CellSnapshot.h serialization/EntitySnapshot.h serialization/SerializeException.h serialization/GameSnapshot.h serialization/Snapshot.h)

find_package(Qt5 COMPONENTS Core REQUIRED)

add_library(game STATIC ${LIB_SRC})
target_link_libraries(game Qt5::Core)

message("Game built")
