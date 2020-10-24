cmake_minimum_required(VERSION 3.13)

set(This LTC2943Tests)

add_executable(${This} LTC2943Tests.cpp)

add_subdirectory(googletest)
include_directories(googletest/include)

target_link_libraries(LTC2943Tests PUBLIC 
    LTC2943 
    gtest_main
)

enable_testing()
add_test(
    NAME ${This}
    COMMAND ${This}
)
