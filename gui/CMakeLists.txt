cmake_minimum_required(VERSION 3.15)
project(gui)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
#set(CMAKE_PREFIX_PATH "<qt path>")

find_package(Qt5 COMPONENTS Core Widgets Gui REQUIRED)

set(CMAKE_AUTOMOC ON)
#set(CMAKE_AUTOUIC ON)
#set(CMAKE_AUTORCC ON)

include_directories(../game_lib ../game)

set(SRC
        Window.h Window.cpp main.cpp
        assets/Assets.cpp assets/Assets.h
        assets/views/ObjectView.h assets/views/EntityView.h assets/views/CellView.h
        assets/views/CellView.cpp assets/views/EntityView.cpp
        StartGameDialog.cpp StartGameDialog.h)

add_executable(gui ${SRC})

target_link_libraries(gui game_lib game Qt5::Core Qt5::Widgets Qt5::Gui)

message("Gui built")
