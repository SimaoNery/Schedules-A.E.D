cmake_minimum_required(VERSION 3.26)
project(untitled)

set(CMAKE_CXX_STANDARD 17)

add_executable(Schedules main.cpp
        Tests/Class.cpp
        Tests/Class.h
        Tests/Student.cpp
        Tests/Student.h
        Tests/Uc_class.cpp
        Tests/Uc_class.h
)
