cmake_minimum_required(VERSION 3.15)
project(tests4)
set(CMAKE_CXX_STANDARD 17)

include_directories(../../game_lib)

set(SRC_BOT_TEST bot_test.cpp)

add_executable(bot_test ${SRC_BOT_TEST})

target_link_libraries(bot_test game_lib)

message("Tests 3 built")


