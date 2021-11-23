cmake_minimum_required(VERSION 3.15)
project(game)
set(CMAKE_CXX_STANDARD 17)

include_directories(bots rules)

set(LIB_SRC
        bots/Bot.h bots/logic/BotLogic.h bots/logic/Predator.h
        rules/Rule.h
        rules/Exterminator.h rules/Collector.h
        Game.cpp Game.h rules/ObjectsCounter.h)

add_library(game STATIC ${LIB_SRC})

message("Game built")
