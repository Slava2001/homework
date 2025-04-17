cmake_minimum_required(VERSION 3.10.0)
project(task_32.5.3 VERSION 0.1.0 LANGUAGES C CXX)

set(CMAKE_CXX_FLAGS "-g -Wall -Wextra -Wno-unused-parameter -Werror")

find_package(Protobuf REQUIRED)
protobuf_generate_cpp(PROTO_SRC PROTO_HEADER src/company.proto)
ADD_LIBRARY(proto ${PROTO_HEADER} ${PROTO_SRC})

include_directories(${CMAKE_CURRENT_BINARY_DIR})
include_directories(${Protobuf_INCLUDE_DIRS})

add_executable(task_32.5.3 src/main.cpp)
target_link_libraries(task_32.5.3 proto ${Protobuf_LIBRARIES})
