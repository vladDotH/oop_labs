cmake_minimum_required(VERSION 3.15)
project(tests2)
set(CMAKE_CXX_STANDARD 17)

include_directories(../../game_lib)

set(SRC_CONTROLLERS_TEST controllers_test.cpp)
set(SRC_LOGGERS_TEST loggers_test.cpp)

add_executable(controllers_test ${SRC_CONTROLLERS_TEST})
add_executable(loggers_test ${SRC_LOGGERS_TEST})

target_link_libraries(controllers_test game_lib)
target_link_libraries(loggers_test game_lib)

message("Tests 3 built")


