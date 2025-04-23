# Qt5_DIR="path_to_qt" cmake . -B build

cmake_minimum_required(VERSION 3.10.0)
project(task_34.5.1 VERSION 0.1.0 LANGUAGES C CXX)

find_package(Qt5 COMPONENTS
    Core
    Gui
    Widgets
    REQUIRED)

add_executable(task_34.5.1 main.cpp)

target_link_libraries(task_34.5.1
    Qt5::Core
    Qt5::Gui
    Qt5::Widgets)

