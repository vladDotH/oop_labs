cmake_minimum_required(VERSION 3.15)
project(tests4)
set(CMAKE_CXX_STANDARD 17)

include_directories(../../game_lib)
include_directories(../../game)

set(SRC_BOT_TEST bot_test.cpp)
set(SRC_RULE_TEST rule_test.cpp)
set(SRC_GEN_TEST gen_test.cpp)
set(SRC_GAME_TEST game_test.cpp)

add_executable(bot_test ${SRC_BOT_TEST})
add_executable(rule_test ${SRC_RULE_TEST})
add_executable(gen_test ${SRC_GEN_TEST})
add_executable(game_test ${SRC_GAME_TEST})

target_link_libraries(bot_test game_lib)
target_link_libraries(rule_test game_lib)
target_link_libraries(gen_test game_lib)
target_link_libraries(game_test game_lib)

target_link_libraries(bot_test game)
target_link_libraries(rule_test game)
target_link_libraries(gen_test game)
target_link_libraries(game_test game)

message("Tests 4 built")


