cmake_minimum_required(VERSION 3.15)
project(tests1)
set(CMAKE_CXX_STANDARD 17)

include_directories(../../game_lib)

set(SRC_INIT_TEST init_test.cpp)
set(SRC_COPY_TEST copy_test.cpp)
set(SRC_MOVE_TEST move_test.cpp)

add_executable(init_test ${SRC_INIT_TEST})
add_executable(copy_test ${SRC_COPY_TEST})
add_executable(move_test ${SRC_MOVE_TEST})

target_link_libraries(init_test game_lib)
target_link_libraries(copy_test game_lib)
target_link_libraries(move_test game_lib)

message("Tests 1 built")


