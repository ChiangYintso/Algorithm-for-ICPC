CMAKE_MINIMUM_REQUIRED(VERSION 3.10.2)

PROJECT(string)
SET(CMAKE_C_STANDARD 11)
SET(CMAKE_CXX_STANDARD 20)

add_executable(luogup3370 hash/luogup3370.cpp)
add_executable(luogup2408 hash/luogup2408.cpp)
add_executable(poj3461 hash/poj3461.cpp)
add_executable(ac_automaton automaton/ac_automaton.cpp)
add_executable(suffix_array automaton/suffix_array.cpp)