cmake_minimum_required(VERSION 2.8)
project(project2)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
        TimeLine.cpp
        TimeLine.h main.cpp Event.h Event.cpp Cashier.h Cashier.cpp Barista.h Barista.cpp)

add_executable(project2 ${SOURCE_FILES})