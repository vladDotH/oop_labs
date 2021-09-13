cmake_minimum_required(VERSION 3.15)
project(game_lib)
set(CMAKE_CXX_STANDARD 17)

set(LIB_SRC field/Cell.cpp field/Cell.h field/Field.cpp field/Field.h entities/Entity.h)
add_library(game_lib STATIC ${LIB_SRC})

message("Game library is builded")
