cmake_minimum_required(VERSION 3.10.0)
project(task_35.6.3 VERSION 0.1.0 LANGUAGES C CXX)

set(CMAKE_CXX_FLAGS "-g -Wall -Wextra -Wno-unused-parameter -Werror")

include_directories("${CMAKE_CURRENT_LIST_DIR}/include")
set(SRC
    "src/main.cpp"
)

add_executable(${PROJECT_NAME} ${SRC})
