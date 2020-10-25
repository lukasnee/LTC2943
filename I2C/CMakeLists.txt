cmake_minimum_required(VERSION 3.13)

project(I2C)

add_library(I2C STATIC 
    i2c.cpp 
    i2c.hpp
)

include_directories(${CMAKE_SOURCE_DIR})
