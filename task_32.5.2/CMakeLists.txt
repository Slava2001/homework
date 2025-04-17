cmake_minimum_required(VERSION 3.10.0)
project(task_32.5.2 VERSION 0.1.0 LANGUAGES C CXX)

set(CMAKE_CXX_FLAGS "-g -Wall -Wextra -Wno-unused-parameter -Werror")

add_subdirectory("${CMAKE_CURRENT_LIST_DIR}/3rdparty/json")
include_directories("${CMAKE_CURRENT_LIST_DIR}/3rdparty/json/include")

include_directories("${CMAKE_CURRENT_LIST_DIR}/include")
set(SRC
    "src/main.cpp"
    "src/film.cpp"
    "src/database.cpp"
)

add_executable(${PROJECT_NAME} ${SRC})
