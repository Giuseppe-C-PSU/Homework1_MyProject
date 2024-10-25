cmake_minimum_required(VERSION 3.23) # Specify CMake version.
project(Homework1) # A project name. This can be anything.
set(CMAKE_CXX_STANDARD 20) # C++ version
include_directories(${CMAKE_SOURCE_DIR})
add_executable(Homework1 main.cpp Plane.cpp Plane.h q1.h q1.cpp Q2.cpp Q2.h question6.h
        Q7.cpp
        Q7.h
        Q8.cpp
        Q8.h)