cmake_minimum_required(VERSION 3.10)
project(s21_containers_project)

#set(CMAKE_CXX_COMPILER gcc)
set(CMAKE_CXX_COMPILER g++)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/build)

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

add_executable(tests tests/main_tests.cpp)

add_library(s21_containers
        containers/list/s21_list.cpp
        containers/map/s21_map.cpp
        containers/set/s21_set.cpp
        containers/stack/s21_stack.cpp
        containers/vector/s21_vector.cpp
        containers/queue/s21_queue.cpp
        s21_containers.h
)

target_include_directories(s21_containers PUBLIC containers)

target_link_libraries(tests PRIVATE s21_containers ${GTEST_LIBRARIES} pthread)
