cmake_minimum_required(VERSION 3.13)

project(LTC2943)

add_library(LTC2943 STATIC 
    LTC2943.cpp
    LTC2943.hpp
    LTC2943_registers.hpp
)

add_subdirectory(I2C)
include_directories(I2C)
target_link_libraries(LTC2943 PUBLIC I2C)

add_subdirectory(tests)
