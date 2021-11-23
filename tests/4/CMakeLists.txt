cmake_minimum_required(VERSION 3.15)
project(tests4)
set(CMAKE_CXX_STANDARD 17)

include_directories(../../game_lib)
include_directories(../../game)

set(SRC_BOT_TEST bot_test.cpp)
set(SRC_RULE_TEST rule_test.cpp)

add_executable(bot_test ${SRC_BOT_TEST})
add_executable(rule_test ${SRC_RULE_TEST})

target_link_libraries(bot_test game_lib)
target_link_libraries(rule_test game_lib)

target_link_libraries(bot_test game)
target_link_libraries(rule_test game)

message("Tests 3 built")


