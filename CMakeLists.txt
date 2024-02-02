cmake_minimum_required(VERSION 3.25)
project(module_image)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_VERBOSE_MAKEFILE ON)

find_package(SDL2 CONFIG REQUIRED)
find_package(SDL2_image CONFIG REQUIRED)
find_package(SDL2_ttf CONFIG REQUIRED)


add_executable(test
        src/mainTest.cpp
        src/Pixel.h
        src/Image.h
        src/Image.cpp
)

get_filename_component(PROJECT_ROOT "${CMAKE_CURRENT_SOURCE_DIR}/" ABSOLUTE)
message("Chemin vers CMakeLists.txt : ${PROJECT_ROOT}")
#install(TARGETS module_image DESTINATION "${PROJECT_ROOT}/bin")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_ROOT}/bin)
