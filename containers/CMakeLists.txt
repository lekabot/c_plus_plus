#cmake_minimum_required(VERSION 3.10)
#project(s21_containers_project)
#
#set(CMAKE_CXX_COMPILER gcc)
#
#set(CMAKE_CXX_STANDARD 17)
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS_DEBUG} -g -Wall -Werror -Wextra -std=c++17")
#
#find_package(GTest REQUIRED)
#include_directories(${GTEST_INCLUDE_DIRS})
#
#include_directories(
#        ${PROJECT_SOURCE_DIR}/containers
#        ${PROJECT_SOURCE_DIR}/containers/*
#)
#
#include_directories(
#        ${PROJECT_SOURCE_DIR}/tests
#        ${PROJECT_SOURCE_DIR}/tests/*
#)
#
#file( GLOB all_SRCS
#        "${PROJECT_SOURCE_DIR}/containers/*/*.cpp"
#        "${PROJECT_SOURCE_DIR}/containers/*/*.h"
#)
#
#file( GLOB all_TESTS
#        "${PROJECT_SOURCE_DIR}/tests/*.cpp"
#        "${PROJECT_SOURCE_DIR}/tests/*.h"
#        "${PROJECT_SOURCE_DIR}/tests/*/*.cpp"
#        "${PROJECT_SOURCE_DIR}/tests/*/*.h"
#)
#
#add_library(s21_containers ${all_SRCS})
#
#add_executable(test ${all_TESTS})
#
#target_include_directories(s21_containers PUBLIC containers)
#
#target_include_directories(test PUBLIC ${all_TESTS})
#
#target_link_libraries(test s21_containers ${GTEST_LIBRARIES} pthread)
#
#add_custom_target(clean-all COMMAND ${CMAKE_COMMAND} -P ${CMAKE_SOURCE_DIR}/CleanAll.cmake)

cmake_minimum_required(VERSION 3.10)
project(s21_containers_project)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS_DEBUG} -g -Wall -Werror -Wextra -std=c++17")

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

file(GLOB all_SRCS
        "${PROJECT_SOURCE_DIR}/containers/*/*.cpp"
        "${PROJECT_SOURCE_DIR}/containers/*/*.h"
)

file(GLOB all_TESTS
        "${PROJECT_SOURCE_DIR}/tests/*.cpp"
        "${PROJECT_SOURCE_DIR}/tests/*.h"
        "${PROJECT_SOURCE_DIR}/tests/*/*.cpp"
        "${PROJECT_SOURCE_DIR}/tests/*/*.h"
)

file(GLOB all_ITERATORS
        "${PROJECT_SOURCE_DIR}/iterators/*.cpp"
        "${PROJECT_SOURCE_DIR}/iterators/*.h"
)

#target_include_directories(test PUBLIC ${PROJECT_SOURCE_DIR}/tests)
#target_include_directories(s21_containers PUBLIC ${PROJECT_SOURCE_DIR}/containers/*)
#target_include_directories(s21_containers PUBLIC ${PROJECT_SOURCE_DIR}/s21_containers.h)

add_library(s21_containers ${all_SRCS} ${all_ITERATORS})
add_executable(test ${all_TESTS})

target_link_libraries(test s21_containers ${GTEST_LIBRARIES} pthread)

add_custom_target(clean-all COMMAND ${CMAKE_COMMAND} -P ${CMAKE_SOURCE_DIR}/CleanAll.cmake)
