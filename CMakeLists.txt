cmake_minimum_required(VERSION 3.27)
project(module_image)

set(CMAKE_CXX_STANDARD 14)

add_executable(module_image
        src/mainTest.cpp
        src/Pixel.h
        src/Image.h
        src/Image.cpp)
