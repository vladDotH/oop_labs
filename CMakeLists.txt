cmake_minimum_required(VERSION 3.15)
project(lab4_all)

add_subdirectory(game_lib)
add_subdirectory(game)
add_subdirectory(tests)
add_subdirectory(gui)

message("Project built")