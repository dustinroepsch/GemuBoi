cmake_minimum_required(VERSION 3.8)

project(GemuBoi)

file(GLOB_RECURSE SOURCES src/*.cpp)

add_executable(GemuBoi ${SOURCES})

set_property(TARGET GemuBoi PROPERTY CXX_STANDARD 11)
