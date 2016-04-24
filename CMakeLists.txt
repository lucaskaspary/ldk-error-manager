cmake_minimum_required (VERSION 2.6)

set(PROJECT_NAME LDK-ErrorManager)
project (${PROJECT_NAME})

set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(PROJECT_SOURCES
        src/ErrorManager.cc)

include_directories( ./include)

# For include other modules
include_directories(../../host/include) 

add_library(${PROJECT_NAME} ${PROJECT_SOURCES})

# Tests
set(PROJECT_TEST_NAME ${PROJECT_NAME}_TEST)
set(PROJECT_TEST_SOURCES
        test/ErrorManagerTest.cc)

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIR})

#Create a executable
add_executable(${PROJECT_TEST_NAME} ${PROJECT_TEST_SOURCES})

# Link module library
target_link_libraries(${PROJECT_TEST_NAME} ${PROJECT_NAME} gtest gtest_main pthread)
