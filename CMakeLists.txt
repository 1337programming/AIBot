cmake_minimum_required(VERSION 3.5)
project(bot)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp addon.cpp aibot.cpp aibot.h helper.cpp helper.h src/time.cpp src/time.h)
add_executable(bot ${SOURCE_FILES})