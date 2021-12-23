cmake_minimum_required(VERSION 3.15)
project(tests6)
set(CMAKE_CXX_STANDARD 17)

include_directories(../../game_lib)
include_directories(../../game)

find_package(Qt5 COMPONENTS Core REQUIRED)

set(SRC_FIELD_TEST field_test.cpp)

add_executable(field_test ${SRC_FIELD_TEST})

target_link_libraries(field_test game_lib game Qt5::Core)

message("Tests 6 built")


