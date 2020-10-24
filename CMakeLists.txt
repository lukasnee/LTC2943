cmake_minimum_required(VERSION 3.13)

set(This LTC2943)

project(${This})

set(Sources
    i2c.cpp
    LTC2943.cpp    
)

set(Headers
    i2c.hpp
    LTC2943.hpp    
)

add_library(${This} STATIC ${Sources} ${Headers})

add_subdirectory(tests)
