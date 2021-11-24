cmake_minimum_required(VERSION 3.15)
project(game)
set(CMAKE_CXX_STANDARD 20)

include_directories(../game_lib bots rules)

set(LIB_SRC
        bots/Bot.h bots/logic/BotLogic.h bots/logic/Predator.h
        rules/end/Rule.h
        rules/end/Exterminator.h rules/end/Collector.h
        rules/init/Generator.h rules/init/Creautres.h rules/init/Items.h
        Game.cpp Game.h rules/end/ObjectsCounter.h rules/init/Generator.h)

add_library(game STATIC ${LIB_SRC})

message("Game built")
