CMAKE_MINIMUM_REQUIRED(VERSION 3.10.2)

PROJECT(vj)
SET(CMAKE_C_STANDARD 11)
SET(CMAKE_CXX_STANDARD 17)

add_executable(a a.cpp)
add_executable(d d.cpp)
add_executable(c c.cpp)
add_executable(b b.c)
add_executable(l l.cpp)
add_executable(h h.cpp)