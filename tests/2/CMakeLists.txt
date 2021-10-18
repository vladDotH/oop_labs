cmake_minimum_required(VERSION 3.15)
project(tests2)
set(CMAKE_CXX_STANDARD 17)

include_directories(../../game_lib)

set(SRC_INTERACTION_TEST interaction_test.cpp)
set(SRC_ENTITIES_TEST entities_test.cpp)

add_executable(interaction_test ${SRC_INTERACTION_TEST})
add_executable(entities_test ${SRC_ENTITIES_TEST})

target_link_libraries(interaction_test game_lib)
target_link_libraries(entities_test game_lib)

message("Tests 2 built")


