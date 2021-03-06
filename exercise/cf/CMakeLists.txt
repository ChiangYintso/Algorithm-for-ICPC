CMAKE_MINIMUM_REQUIRED(VERSION 3.10.2)

PROJECT(cf)
SET(CMAKE_C_STANDARD 11)
SET(CMAKE_CXX_STANDARD 20)
SET(CMAKE_C_FLAGS -pthread)

add_executable(cf1486a cf1486a.cpp)
add_executable(cf1486b cf1486b.cpp)
add_executable(cf1485a cf1485a.cpp)