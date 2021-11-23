cmake_minimum_required(VERSION 3.15)
project(tests3)
set(CMAKE_CXX_STANDARD 17)

include_directories(../../game_lib)

set(SRC_LOGGERS_TEST loggers_test.cpp)
set(SRC_LOGGABLE_TEST loggable_test.cpp)
set(SRC_CONTROLLERS_TEST controllers_test.cpp)

add_executable(loggers_test ${SRC_LOGGERS_TEST})
add_executable(loggable_test ${SRC_LOGGABLE_TEST})
add_executable(controllers_test ${SRC_CONTROLLERS_TEST})

target_link_libraries(loggers_test game_lib)
target_link_libraries(loggable_test game_lib)
target_link_libraries(controllers_test game_lib)

message("Tests 3 built")


