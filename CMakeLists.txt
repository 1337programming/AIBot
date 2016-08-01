cmake_minimum_required(VERSION 3.5)
project(bot)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES src/main.cpp src/addon.cpp src/aibot.cpp src/aibot.h src/time.cpp src/time.h src/prototype.cpp src/prototype.h)
add_executable(bot ${SOURCE_FILES})