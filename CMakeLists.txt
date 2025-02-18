cmake_minimum_required(VERSION 3.30)
project(cs230_Project)

set(CMAKE_CXX_STANDARD 20)

add_executable(cs230_Project main.cpp
        Contestant.h
        FileIO.h
        FIleIO.cpp
        Calculations.h
        Calculations.cpp
        Sorting.h
        Sorting.cpp
        Menu.cpp
        Menu.h)
